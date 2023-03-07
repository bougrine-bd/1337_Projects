#include "../Include/Webserv.hpp"
#include <sys/_types/_size_t.h>

Server::Server() : client_max_body_size(-1)
{
}

bool Server::isServerName(std::string name)
{
	if ( server_names.find(name) != server_names.end() )
		return (true);
	return (false);        
}

std::string Server::getErrorPage(int status_code)
{
	std::string def;
	
	def = "src/Html/";
	def += itos(status_code);
	def += ".html";
	if ( error_pages.find(status_code) != error_pages.end() )
		return (error_pages.find(status_code)->second);
	return (def);
}

const t_locations& Server::getLocations()
{
	return (locations);
} 

int Server::getClientMaxBodySize()
{
	return (client_max_body_size);
}

const t_listen_port& Server::getListenPorts()
{
	return (listen_ports);
}

void Server::addListenPort(const std::pair<std::string, int> &listen_addr)
{
	if (listen_ports.find(listen_addr) != listen_ports.end())
		throw (ConfigFile_ParseError);
	listen_ports.insert(listen_addr);
}

void Server::addServerName(const std::string &str)
{
	server_names.insert(str);
}

void Server::addErrorPage(int n, const std::string &path)
{
	if (error_pages.find(n) != error_pages.end())
		throw (ConfigFile_ParseError);
	error_pages.insert( make_pair(n, path) );
}

void Server::setClientMaxBodySize(size_t n)
{
	if (client_max_body_size != -1)
		throw (ConfigFile_ParseError);
	client_max_body_size = n;
}

void Server::addLocation(const std::string &name, Location &location)
{
	if (locations.find(name) != locations.end())
		throw (ConfigFile_ParseError);
	locations.insert( make_pair(name, location) );
}

void Server::setTodefault()
{
	if (listen_ports.size() == 0)
		listen_ports.insert( std::make_pair("0.0.0.0", 80) );
	if (locations.size() == 0 || locations.find("/") == locations.end())
	{
		Location location;
		location.setToDefault();
		locations.insert( std::make_pair("/", location) );
	}
	if (client_max_body_size == -1)
		client_max_body_size = 1000000;
}