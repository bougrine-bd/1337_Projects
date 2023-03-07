#include "../Include/Webserv.hpp"

Cgi::Cgi(Request &request, std::string cgi_path, std::string client_addr, std::string script_name, std::string server_port) : 
_request(request), _cgi_path(cgi_path), _client_addr(client_addr), _script_name(script_name), _server_port(server_port)
{

}

Cgi::~Cgi()
{
    _cgi_response.close();
    _response.close();
    remove(_cgi_response_filename.c_str());
    remove(_response_filename.c_str());
}

Result Cgi::generateResponse()
{
    try
    {
        setMetaVariables();
        invokeCgiScript();
        parseCgiResponse();
    }
    catch(const Result& result)
    {
        _cgi_response.close();
        _response.close();
        return (result);
    }
    _cgi_response.close();
    _response.close();
    return (Response_Ready);
}

std::string Cgi::getResponseFilename()
{
    return(_response_filename);
}

void Cgi::setMetaVariables()
{
    t_request_headers::const_iterator begin = _request.getHeaders().begin();
    t_request_headers::const_iterator end = _request.getHeaders().end();

    for (; begin != end; ++begin)
    {
        if (begin->first == "host")
            setServerName(begin->second.front());
        else if (begin->first == "content-type")
            setContentType(begin->second.front());
        else if (begin->first == "content-length" || begin->first == "transfer-encoding" || begin->first == "connection")
            NULL;
        else
            setOther(begin->first, begin->second.front());
    }
    setContentLength();
    setGatewayInterface();
    setQueryString();
    setRemoteAddr();
    setRequestMethod();
    setServerPort();
    setServerProtocol();
    setServerSoftware();
    setScriptName();
    setenv("REMOTE_HOST", "127.0.0.1", 1);
}

void Cgi::invokeCgiScript() 
{
    char        *argv[3];
    pid_t       pid;
    int         body_fd;
    int         response_fd;
    std::string body_filename;

    body_filename = _request.getBodyFileName();
    _cgi_response_filename = generateFileName("/tmp/.cgi_response_");
    pid = fork();
    if (pid == -1)
        throw Server_Error;
    if (pid == 0)
    {
        argv[0] = strdup(_cgi_path.c_str());
        argv[1] = strdup(_script_name.c_str());
        argv[2] = NULL;
        if ( !body_filename.empty() )
        {
            body_fd = open(body_filename.c_str(), O_RDONLY);
            if (body_fd == -1)
                exit(1);
            dup2(body_fd, 0);
        }
        response_fd = open(_cgi_response_filename.c_str(), O_CREAT | O_RDWR, S_IRWXU);
        if (response_fd == -1)
            exit(1);
        dup2(response_fd, 1);
        execve(argv[0], argv, environ);
        remove(_cgi_response_filename.c_str());
        exit(1);
    }
    wait(NULL);
}

void Cgi::parseCgiResponse()
{
    _cgi_response.open(_cgi_response_filename);
    if (!_cgi_response.is_open())
        throw (Server_Error);
    extractHeaderFields();
    makeResponse();
}

void Cgi::makeResponse()
{
    _response_filename = generateFileName("/tmp/.response_");
    _response.open(_response_filename);
    if (! _response.is_open())
        throw (Server_Error);
    putStatusLine();
    putHeaders();
    putResponseBody();
}

void Cgi::extractHeaderFields()
{
    char                    input;
    std::string             field_name;
    std::string             field_value;

    field_name = extractFieldName();
    while ( !field_name.empty() )
    {
        if ( (input = _cgi_response.get()) != ':' )
            throw Bad_Gateway;
        if (field_name == "content-type")
            field_value = extractContentTypeValue();
        else if (field_name == "status")
            field_value = extractStatusValue();
        else
            field_value = extractFieldValue();
        if ( !field_value.empty() )
        {
            _headers.insert( make_pair(field_name, field_value) );
        }
        field_name = extractFieldName();
    }
    input = _cgi_response.get();
    if (input == '\r')
        input = _cgi_response.get();
    if ( input != '\n')
        throw Bad_Gateway;
    if ( _headers.find("content-type") == _headers.end() )
        throw Bad_Gateway;
}

std::string Cgi::extractFieldName()
{
	std::string field_name;

	field_name = extractToken();
	field_name = strToLower(field_name);
	return (field_name);
}

std::string Cgi::extractContentTypeValue()
{
    char        input;
    std::string media_type;

    if ( _headers.find("content-type") != _headers.end() )
        throw Bad_Gateway;
    if ( (input = _cgi_response.peek()) == ' ' )
        _cgi_response.get();
    media_type = extractMediaType();
    input = _cgi_response.get();
    if (input == '\r')
        input = _cgi_response.get();
    if ( input != '\n')
        throw Bad_Gateway;
    return (media_type);
}

std::string Cgi::extractStatusValue()
{
    char            input;
    std::string     status_code;
    std::string     reason_phrase;
    std::string     status;

    if ( _headers.find("status") != _headers.end() )
        throw Bad_Gateway;
    if ( (input = _cgi_response.peek()) == ' ' )
        _cgi_response.get();
    status_code = extractStatusCode();
    if ( (input = _cgi_response.get()) != ' ')
        throw Bad_Gateway;
    reason_phrase = extractReasonPhrase();
    input = _cgi_response.get();
    if (input == '\r')
        input = _cgi_response.get();
    if ( input != '\n')
        throw Bad_Gateway;
    status = status_code + ' ' + reason_phrase;
    return (status);
}

std::string Cgi::extractFieldValue()
{
    char        input;
    std::string field_value;

    if ( (input = _cgi_response.peek()) == ' ' )
        _cgi_response.get();
    input = _cgi_response.peek();
    while (input != '\r' && input != '\n')
    {
        if ( isSeparetor(input) )
            field_value += _cgi_response.get();
        else if ( istchar(input) )
            field_value = extractToken(); 
        else if (input == '"')
            field_value = extractQuotedString();
        else
            throw (Bad_Gateway);
        input = _cgi_response.peek();
    }
    input = _cgi_response.get();
    if (input == '\r')
        input = _cgi_response.get();
    if (input != '\n')
        throw (Bad_Request);
    return (field_value);
}

std::string Cgi::extractMediaType()
{
    char        input;
    std::string type;
    std::string subtype;
    std::string parameter;
    std::string media_type;

    type = extractToken();
    if ( (input = _cgi_response.get()) != '/' )
        throw Bad_Gateway;
    subtype = extractToken();
    media_type = type + "/" + subtype;
    while ( (input = _cgi_response.peek()) == ';' )
    {
        _cgi_response.get();
        parameter = extractParameter();
        media_type += ";" + parameter;
    }
    return (media_type);
}

std::string Cgi::extractParameter()
{
    char        input;
    std::string attribute;
    std::string value;
    std::string parameter;

    while (_cgi_response.peek() == ' ')
        _cgi_response.get();
    attribute = extractToken();
    if ( (input = _cgi_response.get()) != '=' )
        throw Bad_Gateway;
    if ( (input = _cgi_response.peek()) != '"')
        value = extractToken();
    else
        value = extractQuotedString();
    parameter = attribute + "=" + value;
    return (parameter);
}

std::string Cgi::extractStatusCode()
{
    char        input;
    std::string status_code;

    input = _cgi_response.peek();
    while ( isdigit(input) )
    {
        status_code += _cgi_response.get();
        input = _cgi_response.peek();
    }
    if (status_code.length() != 3)
        throw Bad_Gateway;
    return (status_code);
}

std::string Cgi::extractReasonPhrase()
{
    char        input;
    std::string reason_phrase;

    input = _cgi_response.peek();
    while ( input >= 32  && input <= 127)
    {
        reason_phrase += _cgi_response.get();
        input = _cgi_response.peek();
    }
    return (reason_phrase);
}

void Cgi::putStatusLine()
{
    std::string             status_line;
    t_cgi_headers::iterator status_header;

    status_header = _headers.find("status");
    if (status_header != _headers.end())
        status_line = "HTTP/1.1 " + status_header->second + "\r\n";
    else
        status_line = "HTTP/1.1 200 OK\r\n";
    _response << status_line;
    _headers.erase("status");
}

void Cgi::putHeaders()
{
    std::string             header;
    t_cgi_headers::iterator begin;
    t_cgi_headers::iterator end;

    begin = _headers.begin();
    end = _headers.end();
    for (; begin != end; ++begin)
    {
        header = begin->first + ": " + begin->second + "\r\n";
        _response << header;
    }
    _response << "Transfer-Encoding: chunked\r\n";
    _response << "\r\n";
}

void Cgi::putResponseBody()
{
    int         n_read;
    char        buff[8000];
    char        chunk_header[6];

    do
    {
        _cgi_response.read(buff, 8000);
        if ( (n_read = _cgi_response.gcount()) != 0)
        {
            sprintf(chunk_header, "%x\r\n", n_read);
            _response << chunk_header;
            _response.write(buff, n_read);
            _response << "\r\n";
        }
    } while ( !_cgi_response.eof() );
    sprintf(chunk_header, "%x\r\n", 0);
    _response << chunk_header;
    _response << "\r\n";
}

std::string Cgi::extractToken()
{
    char        input;
    std::string token;
    
    input = _cgi_response.peek();
    while ( istchar(input) )
    {
        token += _cgi_response.get();;
        input = _cgi_response.peek();
    }
    return (token);
}

std::string Cgi::extractQuotedString()
{
    char        input;
    std::string quoted_string;

    input = _cgi_response.get();
    if ( (input = _cgi_response.get()) )
        throw Bad_Gateway;
    quoted_string += input;
    do
    {
        input = _cgi_response.get();
        if (istchar(input) || isSeparetor(input) || input == '\n')
            quoted_string += input;
        else
            throw Bad_Gateway;
    }
    while (input != '"');
    if (input != '"')
        throw Bad_Gateway;
    return (quoted_string);
}

bool Cgi::istchar(char c)
{
    if (isalpha(c) || isdigit(c)
        || c == '#' || c == '$' || c == '%' || c == '&' || c == '\''
        || c == '!' || c == '*' || c == '+' || c == '-' || c == '.'
        || c == '^' || c == '_' || c == '`' || c == '|' || c == '~') 
        return (true);
    return (false);
}

bool Cgi::isSeparetor(char c)
{
    if (c == '(' || c == ')' || c == '<' || c == '>'  || c == '@'
        || c == ',' || c == ';' || c == ':' || c == '"' || c== '\\'
        || c == '/' || c == '[' || c == ']' || c == '?' || c == '=' 
        || c == '{' || c == '}' || c == ' ' || c == '\t') 
        return (true);
    return (false);
}

void Cgi::setContentLength()
{
    int body_size;

    body_size = _request.getBodySize();
    if (body_size == 0)
        return;
    setenv("CONTENT_LENGTH", itos(body_size).c_str(), 1);
}

void Cgi::setContentType(std::string value)
{
    setenv("CONTENT_TYPE", value.c_str(), 1);
}

void Cgi::setGatewayInterface()
{
    setenv("GATEWAY_INTERFACE", "CGI/1.1", 1);
    setenv("REDIRECT_STATUS", "CGI", 1);
}

void Cgi::setQueryString()
{
    setenv("QUERY_STRING", _request.getQuery().c_str(), 1);
}

void Cgi::setRemoteAddr()
{
    setenv("REMOTE_ADDR", "127.0.0.1", 1);
}

void Cgi::setRequestMethod()
{
    switch (_request.getMethod())
    {
        case GET:
            setenv("REQUEST_METHOD", "GET", 1);
            break;
        case POST:
            setenv("REQUEST_METHOD", "POST", 1);
            break;
        case DELETE:
            setenv("REQUEST_METHOD", "DELETE", 1);
            break;
    }
}

void Cgi::setScriptName()
{
    setenv("SCRIPT_NAME", _script_name.c_str(), 1);
    setenv("SCRIPT_FILENAME", _script_name.c_str(), 1);
}

void Cgi::setServerName(std::string value)
{
    setenv("SERVER_NAME", value.c_str(), 1);
}

void Cgi::setServerPort()
{
    setenv("SERVER_PORT", _server_port.c_str(), 1);
}

void Cgi::setServerProtocol()
{
    setenv("SERVER_PROTOCOL", "HTTP/1.1", 1);
}

void Cgi::setServerSoftware()
{
    setenv("SERVER_SOFTWARE", "mouk.bd", 1);
}

void Cgi::setOther(std::string name, std::string value)
{
    name = "HTTP_" + strToUpper(name);
    setenv(name.c_str(), value.c_str(), 1);
}
