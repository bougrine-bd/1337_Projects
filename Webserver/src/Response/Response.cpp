#include "../Include/Webserv.hpp"
#include "Response.hpp"

namespace ft
{
	Response::Response(Request &req, std::map<int, const std::string> &statusCM, std::map<std::string, const std::string> &mimeType):
		_request(req), _statusCM(statusCM), _mimeType(mimeType){}

	Response::~Response(){}

	std::string Response::getResponse()
	{
		return (_response);
	}

	size_t Response::getSizeResponse(){return (_response.length());}
	void Response::setResponse(std::string newstr){_response = newstr;}

	void Response::initializeData(Result &pRes, uint16_t &port, uint32_t &address)
	{
		_rootPath = _request.getUri();
		_parsingResult = pRes;
		_address = address;
		_port = port;
	}

	void Response::readFile(std::string path, std::string &body)
	{
		std::ifstream	file;
		
		file.open(path.c_str());
		if (file.is_open())
		{
			while (file)
			{
				std::string buff;
				std::getline (file, buff);
				body += buff;
				if (!file.eof())
					body += "\n";
			}
			file.close();
		}
	}

	void Response::setStatusLine(int statusCode)
	{
		_response += "HTTP/1.1 " + itos(statusCode) + " " + _statusCM[statusCode] + "\r\n";
	}

	void Response::okResponse(int statusCode)
	{
		setStatusLine(statusCode);
		if (statusCode == 200)
		{
			std::string extension = _rootPath;
			findExtension(extension);
			if (!extension.empty())
			{
				std::map<std::string, const std::string>::iterator iter = _mimeType.find(extension);
				if (iter != _mimeType.end()) 
					_response += "Content-Type: " +  iter->second + "; charset=UTF-8\n";
				else
				{
					std::string fileName = strrchr(_rootPath.c_str(), '/') + 1;
					_response += "Content-Type: text/plain; charset=UTF-8\n";
					_response += "Content-Disposition: attachment; filename=\"" + fileName + "\"\r\n";
				}
			}
			else
			{
				std::string fileName = strrchr(_rootPath.c_str(), '/') + 1;
				_response += "Content-Type: text/plain; charset=UTF-8\n";
				_response += "Content-Disposition: attachment; filename=\"" + fileName + "\"\r\n";
			}
			_response += "Content-Length: " + itos(uriChecks(FILE_SIZE, _rootPath)) + "\r\n";
		}
		else {
			_response += "Content-Length: 0\r\n";
		}
		_response += "Server: mouk.bd\r\n";
		_response += "\r\n";
		if (_request.getMethod() == GET)
			readFile(_rootPath, _response);
	}

	void Response::defaultErrorPages(int statusCode)
	{
		switch (statusCode)
		{
			case 400:
				_response += "Content-Length: 101\r\n\r\n";
				_response += "<title>Bad Request</title>\n<style>h1 {text-align: center;}</style>\n<h1>400</h1>\n<h1> Bad Request</h1>";
				break;
			case 403:
				_response += "Content-Length: 97\r\n\r\n";
				_response += "<title>Forbidden</title>\n<style>h1 {text-align: center;}</style>\n<h1>403</h1>\n<h1> Forbidden</h1>";
				break;
			case 404:
				_response += "Content-Length: 107\r\n\r\n";
				_response += "<title>Page Not Found</title>\n<style>h1 {text-align: center;}</style>\n<h1>404</h1>\n<h1> Page Not Found</h1>";
				break;
			case 405:
				_response += "Content-Length: 116\r\n\r\n";
				_response += "<title>Method Not Allowed </title>\n<style>h1 {text-align: center;}</style>\n<h1>405</h1>\n<h1> Method Not Allowed</h1>";
				break;
			case 409:
				_response += "Content-Length: 95\r\n\r\n";
				_response += "<title>Conflict</title>\n<style>h1 {text-align: center;}</style>\n<h1>409</h1>\n<h1> Conflict</h1>";
				break;
			case 413:
				_response += "Content-Length: 127\r\n\r\n";
				_response += "<title>Request Entity Too Large</title>\n<style>h1 {text-align: center;}</style>\n<h1>413</h1>\n<h1> Request Entity Too Large</h1>";
				break;
			case 500:
				_response += "Content-Length: 121\r\n\r\n";
				_response += "<title>Internal Server Error</title>\n<style>h1 {text-align: center;}</style>\n<h1>500</h1>\n<h1> Internal Server Error</h1>";
				break;
			case 501:
				_response += "Content-Length: 109\r\n\r\n";
				_response += "<title>Not Implemented</title>\n<style>h1 {text-align: center;}</style>\n<h1>501</h1>\n<h1> Not Implemented</h1>";
				break;
			case 502:
				_response += "Content-Length: 101\r\n\r\n";
				_response += "<title>Bad Gateway</title>\n<style>h1 {text-align: center;}</style>\n<h1>502</h1>\n<h1> Bad Gateway</h1>";
				break;
			default:
				_response += "Content-Length: 131\r\n\r\n";
				_response += "<title>HTTP Version Not Supported</title>\n<style>h1 {text-align: center;}</style>\n<h1>505</h1>\n<h1> HTTP Version Not Supported</h1>";
				break;
		}
	}

	void Response::makeErrorResponse(int statusCode)
	{
		std::string path = _server.getErrorPage(statusCode);

		setStatusLine(statusCode);
		_response += "Content-Type: text/html; charset=UTF-8\r\n";
		_response += "Server: mouk.bd\r\n";
		if (uriChecks(URI_EXISTENCE, path) == URI_EXIST)
		{
			_response += "Content-Length: " + itos(uriChecks(FILE_SIZE, path)) + "\r\n";
			_response += "\r\n";
			readFile(path, _response);
		}
		else
			defaultErrorPages(statusCode);
	}

	void Response::redirectToDir(int statusCode)
	{
		setStatusLine(statusCode);
		_response += "Location: http://" + _host + ":" + itos(_port) + _request.getUri()  + "/\r\n";
		_response += "Server: mouk.bd\r\n";
		_response += "\r\n";
	}

	void Response::redirectResponse(int statusCode)
	{
		setStatusLine(statusCode);
		_response += "Location: " + _location.second.getRedirection().second + "\r\n";
		_response += "Server: mouk.bd\r\n";
		_response += "\r\n";
	}

	void Response::makeStatusCode(int statusCode)
	{
		if (statusCode == 300 || statusCode == 301 || statusCode == 302 || statusCode == 303 || statusCode == 304 || statusCode == 305 || statusCode == 307)
			redirectResponse(statusCode);
		else if (statusCode == 200 || statusCode == 201 || statusCode == 204)
			okResponse(statusCode);
		else
			makeErrorResponse(statusCode);
	}

	int Response::uriChecks(int type, std::string path)
	{
		struct stat fileProps;

		int statRet = stat(path.c_str(), &fileProps);
		int result;
		switch (type)
		{
			case URI_EXISTENCE:
				if (statRet == -1)
					return (URI_NOT_EXIST);
				else
					return (URI_EXIST);
			case URI_TYPE:
				if (fileProps.st_mode & S_IFDIR)
					return (IS_DIR);
				else
					return (IS_FILE);
			case FILE_SIZE:
				return (fileProps.st_size);
			case RU_OK:
				result = fileProps.st_mode & UREAD_ONLY;
				if (result == 256)
					return (1);
				return (0);
			case WU_OK:
				result = fileProps.st_mode & UWRITE_ONLY;
				if (result == 128)
					return (1);
				return (0);
			case XU_OK:
				result = fileProps.st_mode & UEXECUTE_ONLY;
				if (result == 64)
					return (1);
				return (0);
			default:
				break;
		}
		return (-1);
	}

	void	Response::choseServer(std::list<Server> &servers, uint16_t &port)
	{
		std::map<std::string, std::list<std::string> >::const_iterator hostHeader = _request.getHeaders().find("host"); // iterator on request Headers
		_host = hostHeader->second.front();

		std::list<Server>::iterator server = servers.begin();
		std::vector<Server> validServers;
		for (; server != servers.end() ; ++server)
		{
			std::set<std::pair<std::string, int> >::iterator iter;
			for (iter = server->getListenPorts().begin(); iter != server->getListenPorts().end(); ++iter)
			{ 
				if (iter->second == port)
				{
					validServers.push_back(*server);
					break;
				}
			}
		}

		for (size_t i = 0; i < validServers.size(); ++i)
		{
			if (validServers[i].isServerName(_host))
			{
				_server =  validServers[i];
				return;
			}
		}
		_server = validServers[0];
	}

	void Response::choseLocation()
	{
		std::vector<std::string > validLoctionName;
		std::map<std::string, Location> locations = _server.getLocations();
		std::map<std::string, Location>::const_iterator iterLocation = locations.begin();
		std::map<std::string, Location>::const_iterator iterLocationEnd = locations.end();

		for (; iterLocation != iterLocationEnd; ++iterLocation)
		{
			std::string locPath = iterLocation->first;
			int locPathSize =  locPath.size();
			if (locPathSize == 1 && locPath[0] == '/')
				validLoctionName.push_back(locPath);
			else if (strncmp(_rootPath.c_str(), locPath.c_str(), locPathSize) == 0)
			{
				if (locPath[locPathSize - 1] == '/' || _rootPath[locPathSize] == '/' || !_rootPath[locPathSize])
					validLoctionName.push_back(locPath);
			}
		}
		if (validLoctionName.size() == 1)
		{
			_location.first = locations.find(validLoctionName[0])->first;
			_location.second = locations.find(validLoctionName[0])->second;
		}
		else if (validLoctionName.size() > 1)
		{
			std::sort(validLoctionName.begin(), validLoctionName.end(), sortBylenth);
			_location.first = locations.find(validLoctionName[0])->first;
			_location.second = locations.find(validLoctionName[0])->second;
		}
		//replace Uri
		_rootPath = _rootPath.substr(_location.first.size());
		if (_rootPath[0] == '/' && *(_location.second.getRoot().end() - 1) == '/')
			_rootPath = _location.second.getRoot() + &_rootPath[1];
		else if (_rootPath[0] != '/' && *(_location.second.getRoot().end() - 1) != '/')
			_rootPath = _location.second.getRoot() + "/" + _rootPath;
		else
			_rootPath = _location.second.getRoot() + _rootPath;
		if (!_location.second.getUploadPath().empty())
			_uploadPath = _location.second.getUploadPath() + _request.getUri().substr(_location.first.size());
	}

	int Response::autoIndex()
	{
		std::string body;
		DIR *dir = opendir(_rootPath.c_str());
		if (dir)
		{
			body = "<html>\n<head>\n<title>Index of " + _request.getUri() + "</title>\n</head>\n";
			body += "<body>\n<h1>Index of " + _request.getUri() + "</h1>\n<hr style=\"border-top: 1px solid rgba(0, 0, 0, 0.35);\">\n";
			std::string uri = _request.getUri();
			if (_request.getUri().length() == 1 && uri[uri.size() - 1] == '/')
				body += "<div style=\"padding: .5rem 2rem;\">\n<a href=\"/\" style=\"display: block; text-decoration: none;\">[parent directory]</a>\n<table>\n<th>Name</th>\n<th>Size</th>\n";
			else
			{
				std::string tempUri;
				int i = uri.length() - 2;
				for (; uri[i] != '/' ; --i);
				for (int j = 0; j <= i ; j++)
					tempUri += uri[j];
				body += "<div style=\"padding: .5rem 2rem;\">\n<a href=\"" + tempUri + "\" style=\"display: block; text-decoration: none;\">[parent directory]</a>\n<table>\n<th>Name</th>\n<th>Size</th>\n";
			};
			dirent *entity;
			while((entity = readdir(dir)))
			{
				if (strcmp(entity->d_name, ".") && strcmp(entity->d_name, ".."))
				{
					std::string uri = _request.getUri();
					if (entity->d_type == DT_DIR)
					{
						if (uri[uri.size() -1] != '/')
							body += "<tr><td><a href=\"" + uri + "/" + entity->d_name + "/\" style=\"display: block; text-decoration: none;\">" + entity->d_name + "/</a></td>\
									\n<td style=\"padding-left: 2rem;\">-</td>\n</tr>\n";
						else
							body += "<tr><td><a href=\"" + uri + entity->d_name + "/\" style=\"display: block; text-decoration: none;\">" + entity->d_name + "/</a></td>\
									\n<td style=\"padding-left: 2rem;\">-</td>\n</tr>\n";
					}
					else
					{
						body += "<tr><td><a href=\"" + uri + entity->d_name + "\" style=\"display: block; text-decoration: none;\">" + entity->d_name + "</a>\n</td>\n";
						body += "<td style=\"padding-left: 2rem;\">" + itos(uriChecks(FILE_SIZE,_rootPath + "/" + entity->d_name)) + " B</td>\n</tr>\n";
					}
				}
			}
			body +=	"</table>\n</div></body>\n</html>";
			_response += "HTTP/1.1 200 OK\r\n";
			_response += "Content-Type: text/html; charset=UTF-8\r\n";
			_response += "Content-Length: " + itos(body.length()) + "\r\n";
			_response += "Server: mouk.bd\r\n";
			_response += "\r\n";
			_response += body;
			closedir(dir);
		}
		else
			return (403);
		return (0);
	}

	void Response::choseIndexPage()
	{
		std::set<std::string>::iterator iterIndexPage = _location.second.getIndexPages().begin();
		_hasIndexpage = false;

		for(; iterIndexPage != _location.second.getIndexPages().end(); ++iterIndexPage)
		{
			std::string tempUri = _rootPath;
			if (tempUri[tempUri.size() - 1] != '/')
				tempUri += "/" + *iterIndexPage;
			else
				tempUri += *iterIndexPage;
			if (uriChecks(URI_EXISTENCE, tempUri) == URI_EXIST)
			{
				_rootPath = tempUri;
				_hasIndexpage = true;
				break;
			}
		}
	}

	int Response::uploadData(int statusCode)
	{
		std::ofstream file;
		std::string body;
		file.open(_uploadPath.c_str());
		if (file.is_open())
		{
			readFile(_request.getBodyFileName(), body);
			file << body;
			file.close();
			return (statusCode);
		}
		return (500);
	}

	int Response::upload()
	{
		std::string uri = _request.getUri();
		if (uri[uri.size() - 1] == '/')
			return (409);
		if (uriChecks(URI_EXISTENCE, _uploadPath) == URI_NOT_EXIST)
			return (uploadData(201));
		else if (uriChecks(URI_TYPE, _uploadPath) == IS_FILE)
			return (uploadData(204));
		return (409);
	}

	void Response::findExtension(std::string &extension)
	{
		int foundIndex = extension.rfind('/');
		extension = extension.substr(foundIndex + 1);

		foundIndex = extension.rfind('.');
		if (foundIndex == -1)
			extension = "";
		else
			extension = extension.substr(foundIndex + 1);
	}

	int Response::deleteUri(std::string path)
	{
		if (uriChecks(URI_TYPE, path) == IS_DIR)
		{
			DIR *dir = opendir(path.c_str());
			if (dir)
			{
				dirent *entity;
				while((entity = readdir(dir)))
				{
					if (strcmp(entity->d_name, ".") && strcmp(entity->d_name, ".."))
					{
						if (entity->d_type != DT_DIR)
						{
							std::string tempPath = path + "/" + entity->d_name;
							if (remove(tempPath.c_str()) != 0)
								return (-1);
						}
						else
							deleteUri(path + "/" + entity->d_name);
					}
				}
			}
			else
				return (-1);
		}
		if (remove(path.c_str()) != 0)
			return (-1);
		return (0);
	}

	int Response::checkCgiResult(Result &cgiResult, Cgi &cgi)
	{
		switch (cgiResult)
		{
			case Server_Error:
				return 500;
			case Bad_Gateway:
				return 502;
			case Response_Ready:
				readFile(cgi.getResponseFilename(), _response);
				break;
			default:
				break;
		}
		return 0;
	}

	int Response::handleGet()
	{
		if (uriChecks(URI_EXISTENCE, _rootPath) == URI_NOT_EXIST)
			return (404);
		if (!uriChecks(RU_OK, _rootPath))
			return (403);
		if (uriChecks(URI_TYPE, _rootPath) == IS_DIR)
		{
			std::string uri = _request.getUri();

			if (uri[uri.size() - 1] != '/')
			{
				redirectToDir(301);
				return (0);
			}

			choseIndexPage();

			if (!_hasIndexpage)
			{
				if (!_location.second.isAutoIndexOn())
					return (403);

				int ret = autoIndex();
				uri.clear();
				return (ret);
			}
		}
		if (!uriChecks(RU_OK, _rootPath))
			return (403);
		if (uriChecks(URI_TYPE, _rootPath) == IS_FILE)
		{
			std::string extension = _rootPath;
			findExtension(extension);
			if (_location.second.isCgiScript(extension))
			{
				Cgi cgi(_request, _location.second.getCgiPath(extension), "", _rootPath, itos(_port));
				Result cgiResult = cgi.generateResponse();
				return (checkCgiResult(cgiResult, cgi));
			}
			else
				return (200);
		}
		return (0);
	}

	int Response::handlePost()
	{
		if (_request.getBodySize() > _server.getClientMaxBodySize())
			return (413);
		if (!_location.second.getUploadPath().empty())
			return (upload());
		if (uriChecks(URI_EXISTENCE, _rootPath) == URI_NOT_EXIST)
			return (404);
		if (!uriChecks(XU_OK, _rootPath))
			return (403);
		if (uriChecks(URI_TYPE, _rootPath) == IS_DIR)
		{
			choseIndexPage();
			if (!_hasIndexpage)
				return (405);
		}
		if (!uriChecks(XU_OK, _rootPath))
			return (403);
		if (uriChecks(URI_TYPE, _rootPath) == IS_FILE)
		{
			std::string extension =  _rootPath;
			findExtension(extension);
			if (_location.second.isCgiScript(extension))
			{
				Cgi cgi(_request, _location.second.getCgiPath(extension), "", _rootPath, itos(_port));
				Result cgiResult = cgi.generateResponse();
				return (checkCgiResult(cgiResult, cgi));
			}
			else
				return (405);
		}
		return (0);
	}

	int Response::handleDelete()
	{
		if (uriChecks(URI_EXISTENCE, _rootPath) == URI_NOT_EXIST)
			return (404);
		else
		{
			if (!uriChecks(XU_OK, _rootPath))
				return (403);
			if (deleteUri(_rootPath) == 0)
				return (204);
			else
				return (500);
		}
		return (0);
	}

	void Response::handler(Result &pRes, std::list<Server> &servers, uint16_t &port, uint32_t &address)
	{
		initializeData(pRes, port, address);
		int responseResult = 0;

		if (_parsingResult == Bad_Request)
			responseResult = 400;
		else if (_parsingResult == Not_Implemented)
			responseResult = 501;
		else if (_parsingResult == HTTP_Version_Not_Supported)
			responseResult = 505;
		else if (_parsingResult == Server_Error)
			responseResult = 500;
		else if (_parsingResult == Request_Ready)
		{
			choseServer(servers, port);
			choseLocation();
			if (_location.second.getRedirection().first != 0)
			{
				makeStatusCode(_location.second.getRedirection().first);
			}
			else
			{
				if (!_location.second.isMethodAllowed(_request.getMethod()))
					responseResult = 405;
				else
				{
					if (_request.getMethod() == GET)
						responseResult = handleGet();
					else if (_request.getMethod() == POST)
						responseResult = handlePost();
					else if (_request.getMethod() == DELETE)
						responseResult = handleDelete();
				}
			}
		}
		if (responseResult != 0)
			makeStatusCode(responseResult);
	}
}