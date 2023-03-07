#pragma once

#include "../Include/Webserv.hpp"

class Location
{
	int					autoindex;
	std::string			root;
	std::set<Method>	allowed_methods;
	t_redirection		redirection;
	t_index				index_pages;
	t_cgi				cgi;
	std::string			upload_path;
	
	public:
		Location() : autoindex(-1)
		{}
		std::string		getRoot();
		bool			isAutoIndexOn();
		bool			isMethodAllowed(Method method);
		t_redirection	getRedirection();
		const t_index&	getIndexPages();
		bool			isCgiScript(std::string file_ext);
		std::string		getCgiPath(std::string file_ext);
		std::string		getUploadPath();
		void			setRoot(const std::string &str);
		void			setAutoindex(const std::string &str);
		void			AllowMethod(const std::string &str);
		void			setRedirection(const std::pair<int, std::string> &val);
		void			addIndexPage(const std::string &str);
		void			addCgiFile(const std::string &file_ext, const std::string &path = "Def");
		void			setUploadPath(const std::string &str);
		void			setToDefault();
};