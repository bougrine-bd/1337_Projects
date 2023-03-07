# pragma once

#include "../Include/Webserv.hpp"
class Request; 
class Cgi
{
    Request			&_request;
    std::string     _cgi_path;
    t_cgi_headers   _headers;
    std::ifstream   _cgi_response;
    std::string     _cgi_response_filename;
    std::ofstream   _response;
    std::string     _response_filename;
    std::string		_client_addr;
    std::string		_script_name;
    std::string		_server_port;

    void        setMetaVariables();
	void		invokeCgiScript();
	void        parseCgiResponse();
	void		makeResponse();
    void        extractHeaderFields();
    std::string extractFieldName();
    std::string extractContentTypeValue();
    std::string extractStatusValue();
    std::string extractFieldValue();
    std::string extractMediaType();
    std::string extractParameter();
    std::string	extractStatusCode();
    std::string extractReasonPhrase();
	void		putStatusLine();
    void		putHeaders();
    void		putResponseBody();
    std::string extractToken();
    std::string extractQuotedString();
    bool		istchar(char c);
    bool		isSeparetor(char c);
	void        setContentLength();
    void        setContentType(std::string value);
    void        setGatewayInterface();
    void        setQueryString();
    void        setRemoteAddr();
    void        setRequestMethod();
    void        setScriptName();
    void        setServerName(std::string value);
    void        setServerPort();
    void        setServerProtocol();
    void        setServerSoftware();
    void        setOther(std::string name, std::string value);

	public:
		Cgi(Request &request, std::string cgi_path, std::string client_addr, std::string script_name, std::string server_port);
		~Cgi();
        Result      generateResponse();
        std::string getResponseFilename();
    



};