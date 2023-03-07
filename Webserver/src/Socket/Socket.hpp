#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "../Include/Webserv.hpp"

namespace ft
{
	class Socket
	{
		private:
			int					_socketFD;
			sockaddr_in 		_address;

		public:
			Socket();
			~Socket();

			int			getSocketFd();
			sockaddr_in	getSocketAddr();

			int		handler(int &port, unsigned int &host);
			int		creatSocket();
			void	setAdress(unsigned int host, int port);
			int		bindSocket();
			int		listenSocket();
			int		acceptSocket();
	};
}

#endif