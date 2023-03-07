#include "../Include/Webserv.hpp"

extern std::list<Server> servers;

ParseConfigFile::ParseConfigFile(const std::string &filename, std::list<Server> &servers) : start(0), current(0), servers(servers)
{
    readFile(filename);
    parse();
}

void ParseConfigFile::readFile(const std::string &filename)
{
    std::ifstream in(filename, std::ifstream::in);
    std::stringstream ss;

    ss << in.rdbuf();
    buffer = ss.str();
}

void ParseConfigFile::parse()
{
    std::list<std::string> token_list;

	do
	{
		token_list = nextTokenList();
		if (token_list.front() == "server" && token_list.back() == "{" && token_list.size() == 2)
			server();
		else
			throw (ConfigFile_ParseError);
		skipWhiteSpaces();
	} while (buffer[current]);
}

std::list<std::string> ParseConfigFile::nextTokenList()
{
    std::string				token;
    std::list<std::string>	token_list;

    do
    {
        token = nextToken();
        token_list.push_back(token);
    }
    while (isTerminatorToken(token) == false);
    return (token_list);
}

std::string ParseConfigFile::nextToken()
{
    std::string token;

    skipWhiteSpaces();
    if ( isTerminatorToken(buffer[current]) )
    {
        token = std::string(1, buffer[current]);
        ++current;
        return(token);
    }
    while (buffer[current] && isTerminatorToken(buffer[current]) == false && isWhiteSpace(buffer[current]) == false)
	{
		if (buffer[current] == '\\')
			++current;
		if (!buffer[current])
			break;
		++current;
	}
	if (!buffer[current])
        throw (ConfigFile_ParseError);
    token = buffer.substr(start, current - start);
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (token[i] == '\\')
			token.erase(token.begin() + i);
	}
    start = current;
    return (token);
}

bool ParseConfigFile::isTerminatorToken(std::string str)
{
	if (str == "{" || str == "}" || str == ";")
		return (true);
	return (false);
}

bool ParseConfigFile::isTerminatorToken(char c)
{
	if (c == '{' || c == '}' || c == ';')
		return (true);
	return (false);
}

bool ParseConfigFile::isWhiteSpace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13) )
		return (true);
	return (false);
}

void ParseConfigFile::skipWhiteSpaces()
{
	while (buffer[current] == 32 || ( buffer[current] >= 9 && buffer[current] <= 13 ) )
		++current;
	start = current;
}

void ParseConfigFile::server()
{
    Server                  server;
    std::list<std::string>  token_list;
    std::string             directive;

    token_list = nextTokenList();
    while (token_list.front() != "}")
    {
        directive = token_list.front();
        token_list.pop_front();
        if (directive == "listen")
            listen(server, token_list);
        else if (directive == "server_names")
            server_names(server, token_list);
        else if (directive == "error_page")
            error_page(server, token_list);
		else if (directive == "client_max_body_size")
            clientMaxBodySize(server, token_list);
        else if (directive == "location" && token_list.back() == "{" && token_list.size() == 2)
			location(server, token_list.front());
		else if (directive == "#")
			NULL;
        else
            throw (ConfigFile_ParseError);
        token_list = nextTokenList();
    }
	server.setTodefault();
	servers.push_back(server);
}

void ParseConfigFile::listen(Server &server, std::list<std::string> &token_list)
{
	unsigned long int 	pos;
	int 				port;
	std::string			address;
	std::string			terminator;

	if (token_list.size() != 2)
		throw (ConfigFile_ParseError);
	address = token_list.front();
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	if ( (pos = address.find(':')) != std::string::npos)
	{
		std::string host = address.substr(0, pos);
		port = strToPortNumber( address.substr(pos + 1) );
		server.addListenPort( make_pair(host, port) );
	}
	else if ( address.find('.') == std::string::npos)
	{
		port = strToPortNumber(address);
		server.addListenPort( make_pair(std::string("0.0.0.0"), port) );
	}
	else
		server.addListenPort( make_pair(address, 80));
}

void ParseConfigFile::server_names(Server &server, std::list<std::string> &token_list)
{
	std::string							terminator;
	std::list<std::string>::iterator	it;

	if (token_list.size() < 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	token_list.pop_back();
	if (terminator != ";")
		throw(ConfigFile_ParseError);
	for (it = token_list.begin(); it != token_list.end(); ++it)
		server.addServerName(*it);
}

void ParseConfigFile::error_page(Server &server, std::list<std::string> &token_list)
{
	int									error_status_code;
	std::string							terminator;
	std::string 						path;
	std::list<std::string>::iterator	it;
	
	if (token_list.size() < 3)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	token_list.pop_back();
	path = token_list.back();
	token_list.pop_back();
	for (it = token_list.begin(); it != token_list.end(); ++it)
	{
		error_status_code = strToErrorStatusCode(*it);
		server.addErrorPage(error_status_code, path);
	}
}

void ParseConfigFile::clientMaxBodySize(Server &server, std::list<std::string> &token_list)
{
	size_t 		size;
	std::string	str;
	std::string	terminator;

	if (token_list.size() != 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	str = token_list.front();
	size = strToInt(str);
	size *= 1000000; 
	server.setClientMaxBodySize(size);
}

void ParseConfigFile::location(Server &server, std::string name)
{
	Location				location;
	std::string				directive;
	std::list<std::string>	token_list;

	token_list = nextTokenList();
	while (token_list.front() != "}")
	{
		directive = token_list.front(); token_list.pop_front();
		if (directive == "root")
		{
			root(location, token_list);
		}
		else if (directive == "autoindex")
		{
			autoindex(location, token_list);
		}
		else if (directive == "allow_methods")
		{
			allow_methods(location, token_list);
		}
		else if (directive == "return")
		{
			redirection(location, token_list);
		}
		else if (directive == "index")
		{
			index(location, token_list);
		}
		else if (directive == "upload")
		{
			upload(location, token_list);
		}
		else if (directive == "cgi")
		{
			cgi(location, token_list);
		}
		else if (directive == "#")
		{
			NULL;
		}
		else
		{
			throw (ConfigFile_ParseError);
		}
		token_list = nextTokenList();
	}
	location.setToDefault();
	server.addLocation(name, location);
}

void ParseConfigFile::upload(Location &location, std::list<std::string> &token_list)
{
	std::string path;
	std::string	terminator;
	
	if (token_list.size() != 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	path = token_list.front();
	location.setUploadPath(path);
}

void cgi(Location &location, std::list<std::string> &token_list)
{
	std::string							terminator;
	std::list<std::string>::iterator 	it;

	if (token_list.size() < 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	token_list.pop_back();
	for (it = token_list.begin(); it != token_list.end(); ++it)
		location.addCgiFile(*it);
}

void ParseConfigFile::root(Location &location, std::list<std::string> &token_list)
{
	std::string path;
	std::string	terminator;
	
	if (token_list.size() != 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	path = token_list.front();
	location.setRoot(path);
}

void ParseConfigFile::autoindex(Location &location, std::list<std::string> &token_list)
{
	std::string	value;
	std::string terminator;
	
	if (token_list.size() != 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	value = token_list.front();
	location.setAutoindex(value);
}

void ParseConfigFile::allow_methods(Location &location, std::list<std::string> &token_list)
{
	std::string							terminator;
	std::list<std::string>::iterator	it;

	if (token_list.size() < 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	token_list.pop_back();
	for (it = token_list.begin(); it != token_list.end() ; ++it)
		location.AllowMethod(*it);
}

void ParseConfigFile::redirection(Location &location, std::list<std::string> &token_list)
{
	int	status_code;
	std::string	terminator;
	std::string destination;
	std::string str;

	if (token_list.size() != 3)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	token_list.pop_back();
	destination = token_list.back();
	str = token_list.front();
	token_list.pop_back();
	token_list.pop_front();
	status_code = strToRedirectionStatusCode(str);
	location.setRedirection( make_pair(status_code, destination) );
}

void ParseConfigFile::index(Location &location, std::list<std::string> &token_list)
{
	std::string							terminator;
	std::list<std::string>::iterator 	it;

	if (token_list.size() < 2)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	token_list.pop_back();
	for (it = token_list.begin(); it != token_list.end(); ++it)
		location.addIndexPage(*it);
}

void ParseConfigFile::cgi(Location &location, std::list<std::string> &token_list)
{
	std::string terminator;
	std::string	cgi_path;
	std::list<std::string>::iterator it;

	if (token_list.size() != 3)
		throw (ConfigFile_ParseError);
	terminator = token_list.back();
	if (terminator != ";")
		throw (ConfigFile_ParseError);
	token_list.pop_back();
	cgi_path = token_list.back();
	token_list.pop_back();
	for (it = token_list.begin(); it != token_list.end(); ++it)
		location.addCgiFile(*it, cgi_path);
}

size_t ParseConfigFile::strToInt(const std::string &str)
{
	size_t n = 0;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] < 48 || str[i] > 57)
			throw (ConfigFile_ParseError);
		n *= 10;
		n += str[i] - 48;
	}
	return (n);
}

int ParseConfigFile::strToPortNumber(const std::string &str)
{
	int n = 0;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] < 48 || str[i] > 57)
			throw (ConfigFile_ParseError);
		n *= 10;
		n += str[i] - 48;
	}
	return (n);
}

int ParseConfigFile::strToRedirectionStatusCode(const std::string &str)
{
	int n;
	int redirection_status_codes[] = { 301, 302, 303, 307 };

	n = 0;
	if (str.length() != 3)
		throw (ConfigFile_ParseError);
	for (int i = 0; i < 3; ++i)
	{
		if (str[i] < 48 || str[i] > 57)
			throw (ConfigFile_ParseError);
		n *= 10;
		n += str[i] - 48;
	}
	if ( std::find(redirection_status_codes, redirection_status_codes + 7, n) == (redirection_status_codes + 7))
		throw (ConfigFile_ParseError);
	return (n);
}

int ParseConfigFile::strToErrorStatusCode(const std::string &str)
{
	int n = 0;
	int error_status_codes[] = {400, 402, 403, 404, 405, 406, 408,
								409, 410, 411, 413, 414, 415, 417,
								426, 500, 501, 502, 503, 504, 505 };

	if (str.length() != 3)
		throw (ConfigFile_ParseError);
	for (int i = 0; i < 3; ++i)
	{
		if (str[i] < 48 || str[i] > 57)
			throw (ConfigFile_ParseError);
		n *= 10;
		n += str[i] - 48;
	}
	if ( std::find(error_status_codes, error_status_codes + 21, n) == (error_status_codes + 21))
		throw (ConfigFile_ParseError);
	return (n);
}