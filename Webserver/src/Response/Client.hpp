#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../Include/Webserv.hpp"

namespace ft
{
	class Client
	{
		private:
			Request			_request;
			Response		_response;
			Result			_parsingResult;
			uint16_t		_port;
			uint32_t		_address;
			int				_sizeSended;

		public:
			Client(std::map<int, const std::string> &statusCM, std::map<std::string, const std::string> &mimeType);
			~Client();

			void setPort(uint16_t port);
			void setAddress(uint32_t address);

			std::string	getResponse();
			int			getResponseSize();
			int			getSizeSended();
			void		setSizeSended(int ret);


			void processRequst(const char *buff, int size, std::list<Server> &servers);

			int		reset();	
	};
}

#endif