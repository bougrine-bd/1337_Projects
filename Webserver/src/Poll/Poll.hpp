#ifndef POLL_HPP
#define POLL_HPP

#include "../Include/Webserv.hpp"

namespace ft
{
	class Poll
	{
		private:
			std::vector<pollfd>	_vPollFd;
			std::vector<std::pair<time_t, time_t> > _vTimer;
			int _numSockFd;
		public:
			Poll();
			~Poll();

			short int	&getRevent(int i);
			int			&getFd(int i);
			int			size();
			void		checkTime(std::map<int, ft::Client* > &clients);
			void		enventObserver (std::map<int, ft::Client* > &clients);
			void		addConnectionFd(int fd);
			void		addSocketFds(std::vector<Socket > &vSocket);
			int			checkSocketFd(int i, std::vector<Socket > &vSocket);
			void		removeConnectionFd(int index);
	};
}

#endif