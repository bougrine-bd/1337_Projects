#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "../Include/Webserv.hpp"

enum enumUriStatus {URI_EXISTENCE, URI_EXIST, URI_NOT_EXIST, 
					URI_TYPE, IS_FILE, IS_DIR, 
					FILE_SIZE,
					RU_OK, WU_OK, XU_OK};
namespace ft
{
	class Response
	{
		private:
			std::string									_response;
			Request										&_request;
			Result 										_parsingResult;

			std::map<int, const std::string>			_statusCM;
			std::map<std::string, const std::string>	_mimeType;

			std::string									_uploadPath;
			std::string									_rootPath;
			Server										_server;
			std::pair<std::string, Location>			_location;
			std::map<int, std::string>					_errorPages;
			bool 										_hasIndexpage;
			std::string									_host;

			uint16_t 									_port;
			uint32_t 									_address;

		public:
			Response(Request &req, std::map<int, const std::string> &statusCM, std::map<std::string, const std::string> &mimeType);
			~Response();
			
			std::string getResponse();
			size_t getSizeResponse();
			void setResponse(std::string newstr);

			void	initializeData(Result &pRes, uint16_t &port, uint32_t &address);
			void	readFile(std::string path, std::string	&body);
			void	setStatusLine(int statusCode);
			void	okResponse(int statusCode);
			void	defaultErrorPages(int statusCode);
			void	makeErrorResponse(int statusCode);
			void	redirectToDir(int statusCode); 
			void	redirectResponse(int statusCode);
			void	makeStatusCode(int statusCode);
			int		uriChecks(int type, std::string path);
			void	choseServer(std::list<Server> &servers, uint16_t &port);
			void	choseLocation();
			int		autoIndex();
			void	choseIndexPage();
			int		uploadData(int statusCode);
			int		upload();
			void	findExtension(std::string &extension);
			int		deleteUri(std::string path);
			int		checkCgiResult(Result &cgiResult, Cgi &cgi);
			int		handleGet();
			int		handlePost();
			int		handleDelete();
			void	handler(Result &pRes, std::list<Server> &servers, uint16_t &port, uint32_t &address);
	};
}

#endif