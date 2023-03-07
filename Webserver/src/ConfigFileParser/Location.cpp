#include "../Include/Webserv.hpp"

std::string	Location::getRoot()
{
	return (root);
}

bool Location::isAutoIndexOn()
{
	return (autoindex);
}

bool Location::isMethodAllowed(Method method)
{
	if (allowed_methods.find(method) != allowed_methods.end())
		return (true);
	return (false);
}

t_redirection Location::getRedirection()
{
	return (redirection);
}

const t_index&	Location::getIndexPages()
{
	return (index_pages);
}

bool Location::isCgiScript(std::string file_ext)
{
	if (cgi.find(file_ext) != cgi.end())
		return (true);
	return (false);
}

std::string Location::getCgiPath(std::string file_ext)
{
	if (cgi.find(file_ext) != cgi.end())
		return ( cgi.find(file_ext)->second );
	return ("");
}

std::string Location::getUploadPath()
{
	return (upload_path);
}

void Location::setRoot(const std::string &str) 
{ 
	if (root.empty() == false)
		throw (-1);
	root = str; 
}

void Location::setAutoindex(const std::string &str) 
{
	if (str == "on")
		autoindex = true;
	else if (str == "off")
		autoindex = false;
	else
		throw (-1);
}

void Location::AllowMethod(const std::string &str)
{
	if (str == "GET")
		allowed_methods.insert(GET);
	else if (str == "POST")
		allowed_methods.insert(POST);
	else if (str == "DELETE")
		allowed_methods.insert(DELETE);
	else
		throw (ConfigFile_MethodNotAllowed);
}

void Location::setRedirection(const std::pair<int, std::string> &val)
{
	redirection = val;
}

void Location::addIndexPage(const std::string &str)
{
	index_pages.insert(str);
}

void Location::addCgiFile(const std::string &file_ext, const std::string &path)
{
	if (cgi.find(file_ext) != cgi.end())
		throw (ConfigFile_Duplicate);
	cgi.insert(make_pair(file_ext, path));
}

void Location::setUploadPath(const std::string &str)
{
	if (upload_path.empty() == false)
		throw (ConfigFile_Duplicate);
	upload_path = str;
}

void Location::setToDefault()
{
	if (autoindex == -1)
		autoindex = 0;
	if (root.empty() == true)
		root = "src/Html";
	if (index_pages.size() == 0)
		index_pages.insert("index.html");
	if (allowed_methods.empty())
		allowed_methods.insert(GET);
}