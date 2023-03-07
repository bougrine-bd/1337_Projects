#include "../Include/Webserv.hpp"
#include "Socket.hpp"
#include <sys/_types/_size_t.h>
#include <sys/_types/_socklen_t.h>
#include <sys/socket.h>

namespace ft
{
	Socket::Socket(){}

	Socket::~Socket()
	{
		close(_socketFD);
	}

	int Socket::handler(int &port, unsigned int &host)
	{
		if (creatSocket() == -1)
			return (-1);
		setAdress(host, port);
		if (bindSocket() == -1)
			return (-1);
		if(listenSocket() == -1)
			return (-1);
		return (0);
	}

	int Socket::creatSocket()
	{
		_socketFD = socket(AF_INET, SOCK_STREAM, 0);
		if (_socketFD == -1)
			std::cout << "Socket() error\n";
		else
			fcntl(_socketFD, F_SETFL, O_NONBLOCK);
		return (_socketFD);
	}

	int Socket::getSocketFd()
	{
		return (_socketFD);
	}
	sockaddr_in Socket::getSocketAddr()
	{
		return (_address);
	}

	void Socket::setAdress(uint32_t host, int port) 
	{
		bzero(&_address, sizeof(_address));
		_address.sin_len = sizeof(_address);
		_address.sin_family = AF_INET;
		_address.sin_addr.s_addr = host;
		_address.sin_port = htons(port);
	}

	int Socket::bindSocket()
	{
		int enable = 1;
		setsockopt(_socketFD, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
		int ret = bind(_socketFD, (sockaddr*)(&_address), _address.sin_len);
		if (ret == -1)
			std::cout << "Bind() error\n";
		return (ret);
	}

	int Socket::listenSocket()
	{
		int ret = listen(_socketFD, MAX_CLIENT);
		if (ret == -1)
			std::cout << "Bind() error\n";
		return (ret);
	}

	int Socket::acceptSocket()
	{
		sockaddr clinet;
		socklen_t addLen = sizeof(clinet);
		int newfd = accept(_socketFD, &clinet, &addLen);
		if (newfd == -1)
			std::cout << "Accept() error\n";
		return (newfd);
	}

}//Namespace End