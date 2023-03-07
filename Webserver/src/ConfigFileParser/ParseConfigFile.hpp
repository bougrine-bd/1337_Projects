#pragma once

#include "../Include/Webserv.hpp"

class ParseConfigFile
{
	int					start;
	int					current;
	std::string			buffer;
	std::list<Server> 	&servers;

    void readFile(const std::string &filename);
    void parse();
    std::list<std::string> nextTokenList();
    std::string nextToken();
	bool isTerminatorToken(std::string str);
    bool isTerminatorToken(char c);
    bool isWhiteSpace(char c);
    void skipWhiteSpaces();

    void server();
    void listen(Server &server, std::list<std::string> &token_list);
	void server_names(Server &server, std::list<std::string> &token_list);
	void error_page(Server &server, std::list<std::string> &token_list);
	void clientMaxBodySize(Server &server, std::list<std::string> &token_list);

	void location(Server &server, std::string name);
	void root(Location &location, std::list<std::string> &token_list);
	void autoindex(Location &location, std::list<std::string> &token_list);
	void allow_methods(Location &location, std::list<std::string> &token_list);
	void redirection(Location &location, std::list<std::string> &token_list);
	void index(Location &location, std::list<std::string> &token_list);
	void cgi(Location &location, std::list<std::string> &token_list);
	void upload(Location &location, std::list<std::string> &token_list);
	
	size_t strToInt(const std::string &str);
	int strToPortNumber(const std::string &str);
	int strToRedirectionStatusCode(const std::string &str);
	int strToErrorStatusCode(const std::string &str);
	public:
		ParseConfigFile(const std::string &filename, std::list<Server> &servers);


};