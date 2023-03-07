#pragma once

#include "../Include/Webserv.hpp"
#include <sys/_types/_size_t.h>

class Server
{
    private:
    t_listen_port		        listen_ports;
    std::set<std::string>	    server_names;
    std::map<int, std::string>  error_pages;
    int							client_max_body_size;
    t_locations				    locations;

	public:
        Server();
        bool                	isServerName(std::string name);
        std::string         	getErrorPage(int status_code);
        const t_locations&  	getLocations();
        int                 	getClientMaxBodySize();
        const t_listen_port&	getListenPorts();
		void					addListenPort(const std::pair<std::string, int> &listen_addr);
		void					addServerName(const std::string &str);
		void					addErrorPage(int n, const std::string &path);
        void					setClientMaxBodySize(size_t n);
        void					addLocation(const std::string &name, Location &location);
        void					setTodefault();



};