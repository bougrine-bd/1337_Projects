// #include "Poll.hpp"
#include "../Include/Webserv.hpp"

namespace ft
{
	Poll::Poll()
	{
		_vPollFd.reserve(MAX_CLIENT);
		_vTimer.reserve(MAX_CLIENT);
	}
	Poll::~Poll() {}

	short int	&Poll::getRevent(int i)
	{
		return (_vPollFd[i].revents);
	}

	int	&Poll::getFd(int i)
	{
		return (_vPollFd[i].fd);
	}

	void Poll::checkTime(std::map<int, ft::Client* > &clients)
	{
		for (size_t i = _numSockFd; i < _vPollFd.size(); ++i)
		{
			time(&_vTimer[i].second);
			if ((_vTimer[i].second - _vTimer[i].first) >= 10 && clients[_vPollFd[i].fd]->getResponse().empty())
			{
				std::cout << YELLOW << "Time out, Connection closed!" << RESETCOLOR << "\n";
				delete clients[_vPollFd[i].fd];
				clients.erase(_vPollFd[i].fd);
				removeConnectionFd(i);
			}
			else if (_vPollFd[i].revents & POLLIN)
				time(&_vTimer[i].first);
		}
	}

	void	Poll::enventObserver (std::map<int, ft::Client* > &clients)
	{
		int pollRet = 0;
		pollRet = poll(&_vPollFd[0], _vPollFd.size(), 2000);
		if (pollRet == -1)
			std::cout << "Poll() error\n";
		checkTime(clients);
	}

	void	Poll::addConnectionFd(int fd)
	{
		pollfd newPollfd;

		bzero(&newPollfd, sizeof(newPollfd));
		newPollfd.fd = fd;
		newPollfd.events = POLLIN | POLLOUT;
		_vPollFd.push_back(newPollfd);

		_vTimer.push_back(std::make_pair(0, 0));
		time(&_vTimer.back().first);
	}

	void	Poll::addSocketFds(std::vector<Socket > &vSocket)
	{
		for (size_t i = 0; i < vSocket.size(); ++i)
			addConnectionFd(vSocket[i].getSocketFd());
		_numSockFd = vSocket.size();
	}

	int		Poll::checkSocketFd(int i, std::vector<Socket > &vSocket)
	{
		for (size_t j = 0; j < vSocket.size(); ++j)
		{
			if (_vPollFd[i].fd == vSocket[j].getSocketFd())
				return (j);
		}
		return (-1);
	}

	void	Poll::removeConnectionFd(int index)
	{
		close(_vPollFd[index].fd);
		_vPollFd.erase(_vPollFd.begin() + index);
		_vTimer.erase(_vTimer.begin() + index);
	}

	int Poll::size()
	{
		return (_vPollFd.size());
	}

}//EON-amespase