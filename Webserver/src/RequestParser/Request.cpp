#include "../Include/Webserv.hpp"

Request::Request()
{
	_request_state = Parse_Request_Line;
	_ptr = NULL;
	_begin = NULL;
	_end = NULL;
	_begin_save = NULL;
	_remainder = NULL;
	_remainder_size = 0;
	_body_size = 0;
	_keep_alive = true;
}

Request::~Request()
{
	delete [] _remainder;
	_body_.close();
	remove(_body_filename.c_str());
}

void Request::reset()
{
	_ptr = NULL;
	_begin = NULL;
	_end = NULL;
	_begin_save = NULL;
	_request_target.clear();
	_http_version.clear();
	_query.clear();
	_headers.clear();
	_body_.close();
	remove(_body_filename.c_str());
	_body_filename.clear();
	_body_size = 0;
	_request_state = Parse_Request_Line;
	_keep_alive = true;
}

Method	Request::getMethod()
{
	return (_method);
}

std::string	Request::getUri()
{
	return (_request_target);
}

std::string	Request::getQuery()
{
	return (_query);
}

const t_request_headers&	Request::getHeaders()
{
	return (_headers);
}

std::string	Request::getBodyFileName()
{
	return (_body_filename);
}

int	Request::getBodySize()
{
	return (_body_size);
}

bool Request::isKeepAlive()
{
	return (_keep_alive);
}

Result Request::parse(const char *buff, int buff_size)
{
	int total_size = buff_size + _remainder_size;
	
	_ptr = NULL;
	_begin = new char[buff_size + _remainder_size];
	_end = _begin + total_size;
	_begin_save = _begin;
	if (_remainder != NULL)
		memcpy(_begin, _remainder, _remainder_size);
	memcpy(&_begin[_remainder_size], buff, buff_size);
	
	delete [] _remainder;
	_remainder = NULL;
	_remainder_size = 0;

	try
	{
		startParsing();
		if (_ptr)
		{
			
			_remainder_size = _end - _ptr;
			_remainder = new char[_remainder_size];
			memcpy(_remainder, _ptr, _remainder_size);
		}
		delete [] _begin_save;
	}
	catch(Result& result)
	{
		delete [] _begin_save;
		_request_state = Error;
		return (result);
	}
	if (_request_state == Ready)
	{
		_body_.close();
		return (Request_Ready);
	}
	return (Request_Unready);
}

void Request::startParsing()
{
	while (_begin != _end)
	{
		switch (_request_state)
		{
			case Parse_Request_Line:
				parseRequestLine();
				break;
			case Parse_Header_Fields:
				parseHeaderFields();
				break;
			case Parse_Body:
				readRequestBody();
				break;
			case Parse_Chunked_Body:
				parseChunkedBody();
				break;
			case Parse_Trailer_Part:
				parseTrailerPart();
				break;
			case Error:
				throw (Request_Unready);
				break;
			default:
				return;
				break;
		}
	}
}

std::string Request::urlEncoding(std::string url)
{
	std::string new_url;

	for (size_t i = 0; i < url.length(); ++i)
	{
		if (url[i] == '%')
		{
			new_url += hexToAscii( url.substr(i + 1, 2) );
			i += 2;
		}
		else
			new_url += url[i];
	}
	return (new_url);
}

void Request::parseRequestLine()
{
	_ptr = _begin;
	_method = extractMethod();
	skipStr(" ");
	_request_target = extractRequestTarget();
	_request_target = urlEncoding(_request_target);
	if (_begin != _end && *_begin == '?')
	{
		++_begin;
		_query = extractQuery();
	}
	skipStr(" ");
	_http_version = extractHttpVersion();
	skipStr("\r\n");
	if (_begin == _end)
		return ;
	stateTransition();
	
	_ptr = NULL;
}

Method	Request::extractMethod()
{
	std::string	token;
	Method		method;

	method = GET;
	token = extractToken();
	if (token == "GET")
		method = GET;
	else if (token == "POST")
		method = POST;
	else if (token == "DELETE")
		method = DELETE;
	else if (_begin != _end)
		throw (Not_Implemented);
	return (method);
}

std::string Request::extractRequestTarget()
{
	std::string request_target;

	while (_begin != _end && *_begin == '/')
	{
		++_begin;
		request_target += '/';
		request_target += extractSegment();
	}
	if (_begin != _end && request_target.empty())
		throw (Bad_Request);
	return (request_target);
}

std::string Request::extractHttpVersion()
{
	size_t 		i;
	std::string	http_version;
	
	i = 0;
	http_version = "HTTP/1.1";
	for (; _begin != _end && i < http_version.size(); ++i)
	{
		if ( (i == 5 || i == 7) && !isdigit(*_begin) )
			throw (Bad_Request);
		else if (*_begin != http_version[i])
			throw (Bad_Request);
		if ( (i == 5 || i == 7) && *_begin != http_version[i])
			throw (HTTP_Version_Not_Supported);
		++_begin;
	}
	return (http_version);
}

std::string Request::extractQuery()
{
	std::string query;
	
	while (_begin != _end)
	{
		if (*_begin == '/' || *_begin == '?' || *_begin == ':' || *_begin == '@'
			|| isunreserved(*_begin) || isSubDelims(*_begin))
			query += *(_begin++);
		else if (isPctEncoded())
		{
			query += _begin[0];
			query += _begin[1];
			query += _begin[2];
			_begin += 3;
		}
		else
			break;
	}
	return (query);
}

void		Request::parseHeaderFields()
{
	std::string 			field_name;
	std::list<std::string>	field_value;


	while (_begin != _end && istchar(*_begin))
	{
		_ptr = _begin;
		field_name = extractFieldName();
		skipStr(":");
		omitCharset(" \t");
		field_value = extractFieldValue(field_name);
		omitCharset(" \t");
		skipStr("\r\n");
		if (_begin == _end)
			return;
		_headers.insert(make_pair(field_name, field_value));
	}
	_ptr = _begin;
	skipStr("\r\n");
	if ( *(_begin - 1) != '\n' )
		return;
	stateTransition();
	_ptr = NULL;
}

void		Request::parseTrailerPart()
{
	std::string 			field_name;
	std::list<std::string>	field_value;

	while (_begin != _end && istchar(*_begin))
	{
		_ptr = _begin;
		field_name = extractFieldName();
		if (_begin != _end && _headers.find(field_name) == _headers.end())
			throw (Bad_Request);
		skipStr(":");
		omitCharset(" \t");
		field_value = extractFieldValue(field_name);
		omitCharset(" \t");
		_headers.insert(make_pair(field_name, field_value));
		skipStr("\r\n");
		if (_begin == _end)
			return;
		_headers.insert(make_pair(field_name, field_value));
	}
	_ptr = _begin;
	if (_begin + 2 > _end)
		return;
	skipStr("\r\n");
	stateTransition();
	_ptr = NULL;
}

std::string Request::extractFieldName()
{
	std::string field_name;

	field_name = extractToken();
	field_name = strToLower(field_name);
	return (field_name);
}

std::list<std::string> Request::extractFieldValue(const std::string &field_name)
{
	std::list<std::string> field_value;

	if (field_name == "host")
		field_value = extractHostValue();
	else if (field_name == "content-length")
		field_value = extractContentLengthValue();
	else if (field_name == "transfer-encoding")
		field_value = extractTransferEncodingValue();
	else if (field_name == "trailer")
		field_value = extractTrailerValue();
	else if (field_name == "connection")
		field_value = extractConnectionValue();
	else
		field_value = extractHeaderValue();
	return (field_value);
}

std::list<std::string> Request::extractHostValue()
{	
	std::string				host;
	std::list<std::string>	value;

	if (_headers.find("host") != _headers.end())
		throw (Bad_Request);
	host = extractRegName();
	if (_begin != _end && *_begin == ':')
		extractPort();
	if (_begin != _end && host.empty())
		throw (Bad_Request);
	value.push_back(host);
	return (value);
}

std::list<std::string> Request::extractContentLengthValue()
{
	std::string				length;
	std::list<std::string>	value;

	while (_begin != _end && isdigit(*_begin))
	{
		length += *_begin;
		++_begin;
	}
	if (_begin != _end && 
		(length.empty() || (_headers.find("content-length") != _headers.end() && 
		_headers.find("content-length")->second.front() != length ) ) )
		throw(Bad_Request);
	value.push_back(length);
	return (value);
}

std::list<std::string> Request::extractTransferEncodingValue()
{
	std::string				transfer_coding;
	std::list<std::string>	value;

	transfer_coding = extractTransferCoding();
	value.push_back(transfer_coding);
	omitCharset(" \t");
	while (_begin != _end && *_begin == ',')
	{
		omitCharset(" \t");
		transfer_coding = extractTransferCoding();
		value.push_back(transfer_coding);
		omitCharset(" \t");
	}
	return (value);
}

std::list<std::string>	Request::extractConnectionValue()
{
	std::list<std::string> value;

	omitCharset(", \t");
	while ( _begin != _end && istchar(*_begin) )
	{
		value.push_back(extractToken());
		if (value.back() == "close")
			_keep_alive = false;
		omitCharset(", \t");
	}
	return (value);
}

std::list<std::string>	Request::extractTrailerValue()
{
	std::string				field_name;
	std::list<std::string>	value;

	omitCharset(", \t");
	while (_begin != _end && istchar(*_begin) )
	{
		field_name = extractFieldName();
		if (_begin != _end && isForbiddenTrailerValue(field_name))
			throw (Bad_Request);
		value.push_back(field_name);
		omitCharset(", \t");
	}
	return (value);
}

std::list<std::string>	Request::extractHeaderValue()
{
	std::string				field_content;
	std::list<std::string>	value;
	
	field_content = extractFieldContent();
	if (field_content.empty() == false)
		value.push_back(field_content);
	return (value);
}

std::string	Request::extractTransferCoding()
{
	std::string transfer_coding;

	transfer_coding = extractToken();
	omitCharset(" \t");
	if ( _begin != _end && *_begin == ';')
	{
		omitCharset(" \t");
		transfer_coding += extractTransferParameter();
		omitCharset(" \t");
	}
	transfer_coding = strToLower(transfer_coding);
	return (transfer_coding);
}

std::string	Request::extractTransferParameter()
{
	std::string value;

	value = extractToken() + '=';
	omitCharset(" \t");
	skipStr("=");
	omitCharset(" \t");
	if (_begin != _end && *_begin == '"')
		value += extractQuotedString();
	else
		value += extractToken();
	return (value);
}

std::string Request::extractFieldContent()
{
	std::string field_content;
	while ( _begin != _end  && (isVchar(*_begin) || isObsText(*_begin)) )
	{
		field_content += *_begin;
		++_begin;
	}	
	return (field_content);
};

void Request::readRequestBody()
{
	static size_t	i = 0;

	for (; i < _body_size && _begin != _end; ++i)
	{
		_body_ << *_begin;
		++_begin;
	}
	if (i == _body_size)
	{
		i = 0;
		stateTransition();
	}
}

void Request::parseChunkedBody()
{
	static int	chunk_size;
	int			tmp;

	tmp = 0;
	while (_begin != _end)
	{
		if (chunk_size != 0)
		{
			chunk_size -= readChunkData(chunk_size);
			if (chunk_size == 0)
			{
				skipStr("\r\n");
				if (_begin == _end && *(_begin - 1) != '\n')
				{
					chunk_size = 1;
					_ptr = _begin - 1;
					return;
				}
			}
		}
		else
		{
			_ptr = _begin;
			tmp = chunkHeader();
			if (tmp == -1)
				return ;
			if (tmp == 0)
				stateTransition();
			chunk_size = tmp;
			_ptr = NULL;
		}	
	}
}

int Request::chunkHeader()
{
	int chunk_size;

	chunk_size = extractChunkSize();
	while (_begin != _end && *_begin == ';')
		extractChunkExtension();
	skipStr("\r\n");
	if (_begin == _end)
		return (-1);
	return (chunk_size);
}

int Request::extractChunkSize()
{
	int size = 0;

	while (_begin != _end && ishexdigit(*_begin))
	{
		if (*_begin >= 'a')
			size = size * 16 + (*_begin - 87);
		else if (*_begin >= 'A')
			size = size * 16 + (*_begin - 55);
		else
			size = size * 16 + (*_begin - 48);
		++_begin;
	}
	return (size);
}

std::string Request::extractChunkExtension()
{
	std::string chunk_ext;

	if (_begin == _end)
		return (chunk_ext);
	if (*_begin != ';')
		throw (Bad_Request);
	++_begin;
	chunk_ext = extractToken();
	if (_begin != _end && *_begin == '=')
	{
		++_begin;
		chunk_ext += '=';
		if (*_begin == '"')
			chunk_ext += extractQuotedString();
		else
			chunk_ext += extractToken();
	}
	return (chunk_ext);
}

int Request::readChunkData(int chunk_size)
{
	int	i;

	for (i = 0; i < chunk_size && _begin != _end; ++i)
	{
		_body_ << *_begin;
		++_begin;
	}
	_body_size += i;
	return (i);
}

std::string Request::extractQuotedString()
{
	std::string	quoted_string;

	if (_begin == _end)
		return (quoted_string);
	if (*_begin == '"')
	{
		while (_begin != _end && *_begin != '"')
		{
			if ( _begin != _end && isqdtext(*_begin) )
			{
				quoted_string += *_begin;
				++_begin;
			}
			else
				quoted_string += extractQuotedPair();
		}
	}
	else
		throw (Bad_Request);
	return (quoted_string); 
}

std::string Request::extractQuotedPair()
{
	std::string quoted_pair;

	if (_begin == _end)
		return (quoted_pair);
	if (*_begin != '\\')
		throw (Bad_Request);
	++_begin;
	if ( _begin != _end && (isqdtext(*_begin) || *_begin == '"' || *_begin == '\\') )
	{
		quoted_pair += '\\';
		quoted_pair += *_begin; 
		++_begin;
	}
	else if (_begin != _end)
		throw (Bad_Request);
	return (quoted_pair);
}


std::string Request::extractToken()
{
	std::string	token;

	while ( _begin != _end && istchar(*_begin))
	{
		token += *_begin;
		++_begin;
	}
	if (_begin != _end && token.empty())
		throw (Bad_Request);
	return (token);
}

std::string Request::extractSegment()
{
	std::string	segment;

	while (_begin != _end)
	{
		if ( isunreserved(*_begin) || isSubDelims(*_begin) 
			|| *_begin == ':' || *_begin == '@')
			
		{
			segment += *_begin;
			++_begin;
		}
		else if ( isPctEncoded() )
		{
			segment += *_begin;
			segment += *(_begin + 1);
			segment += *(_begin + 2);
			_begin += 3;
		}
		else
			break;
	}
	return (segment);
}

std::string Request::extractRegName()
{
	std::string reg_name;

	while (_begin != _end)
	{
		if ( isunreserved(*_begin) || isSubDelims(*_begin) )
		{
			reg_name += *_begin;
			++_begin;
		}
		else if (isPctEncoded())
		{
			reg_name += *(_begin++);
			reg_name += *(_begin++);
			reg_name += *(_begin++);
		}
		else
			break;
	}
	return (reg_name);
}

std::string	Request::extractPort()
{
	std::string port;

	if (_begin == _end || *_begin != ':')
		return (port);
	++_begin;
	while ( _begin != _end && isdigit(*_begin) )
	{
		port += *_begin;
		++_begin;
	}
	return (port);
}

bool Request::isalpha(char c)
{
	if ( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) )
		return (true);
	return (false);
}

bool Request::isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}

bool Request::ishexdigit(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102))
		return (true);
	return (false);
}

bool Request::istchar(char c)
{
	if (isalpha(c) || isdigit(c)
		|| c == '#' || c == '$' || c == '%' || c == '&' || c == '\''
		|| c == '!' || c == '*' || c == '+' || c == '-' || c == '.'
		|| c == '^' || c == '_' || c == '`' || c == '|' || c == '~') 
		return (true);
	return (false);
}

bool Request::isunreserved(char c)
{
	if (isalpha(c) || isdigit(c) || c == '-' || c == '.' || c == '_' || c == '~')
		return (true);
	return (false);
}

bool Request::isSubDelims(char c)
{
	if (c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' 
		|| c == '*' || c == '+' || c == ',' || c == ';' || c == '=')
		return (true);
	return (false);
}

bool Request::isPctEncoded()
{
	if ( _begin + 2 < _end && *_begin == '%' && ishexdigit(_begin[1]) && ishexdigit(_begin[2]) )
		return (true);
	return (false);
}

bool Request::isqdtext(unsigned char c)
{
	if (c == '\t' || c == ' ' || c == '!' ||
		(c >= '#' && c <= '[') || (c >= ']' && c <= '~') ||
		(c >= 128 && c <= 255))
		return (true);
	return(false);
}

bool Request::isForbiddenTrailerValue(std::string field_name)
{
	if (field_name == "transfer-encoding" || field_name == "content-length" ||
		field_name == "host" || field_name == "trailer")
		return (true);
	return (false);
}

void	Request::skipStr(std::string str)
{
	for (size_t i = 0; _begin != _end && i < str.size(); ++i)
	{
		if (*_begin != str[i])
			throw (Bad_Request);
		++_begin;
	}
}

void Request::omitCharset(std::string char_set)
{
	while (_begin != _end && char_set.find(*_begin) != std::string::npos)
		++_begin;
}

void Request::stateTransition()
{
	switch(_request_state)
	{
		case Parse_Request_Line:
			_request_state = Parse_Header_Fields;
			break;
		case Parse_Header_Fields:
			shiftFromParseHeaderFields();
			break;
		case Parse_Body:
			_request_state = Ready;
			break;
		case Parse_Chunked_Body:
			shiftFromParseChunkedBody();
			break;
		case Parse_Trailer_Part:
			_request_state = Ready;
			break;
		default:
			break;
	}
}

void Request::shiftFromParseHeaderFields()
{
	if (_headers.find("transfer-encoding") != _headers.end()
		|| _headers.find("content-length") != _headers.end())
	{
		_body_filename = generateFileName("/tmp/.requestBody_");
		_body_.open(_body_filename);
		if (!_body_.is_open())
			throw (Server_Error);
	}
	if (_headers.find("transfer-encoding") != _headers.end())
		_request_state = Parse_Chunked_Body;
	else if (_headers.find("content-length") != _headers.end())
	{
		_body_size = strToSize_t(_headers.find("content-length")->second.front());
		_request_state = Parse_Body;
	}
	else
		_request_state = Ready;
}

void Request::shiftFromParseChunkedBody()
{
	if (_headers.find("trailer") != _headers.end())
		_request_state = Parse_Trailer_Part;
	else
	{
		_request_state = Ready;
		skipStr("\r\n");
	}	
}

bool Request::isVchar(char c)
{
	if (c > 31 && c < 127)
		return (true);
	return (false);
}

bool Request::isObsText(unsigned char c)
{
	if (c > 127)
		return (true);
	return (false);
}
