#include "../Include/Webserv.hpp"

void eventLoop(std::vector<ft::Socket > &vSocket, std::list<Server> &servers)
{
	int eventFd;
	short int rEvent;

	int			nReaded;
	std::map<int, ft::Client* > clients;
	std::map<int, const std::string>			statusCM;
	std::map<std::string, const std::string>	mimeType;

	initStatusCM(statusCM);
	initMimeType(mimeType);
	ft::Poll pollFds;
	pollFds.addSocketFds(vSocket);

	while (1998)
	{
		pollFds.enventObserver(clients);
		for (int i = 0; i < pollFds.size(); ++i)
		{
			eventFd = pollFds.getFd(i);
			rEvent = pollFds.getRevent(i);

			if (rEvent & POLLHUP || rEvent & POLLERR)
			{
				std::cout << YELLOW << "Connection closed!" << RESETCOLOR << "\n";
				delete clients[eventFd];
				clients.erase(eventFd);
				pollFds.removeConnectionFd(i);
			}
			else if (rEvent & POLLIN)
			{
				int index = pollFds.checkSocketFd(i, vSocket);
				if (index != -1)
				{
					int newClientFd = vSocket[index].acceptSocket();
					if (newClientFd != -1)
					{
						fcntl(newClientFd, F_SETFL, O_NONBLOCK);
						clients[newClientFd] = new ft::Client(statusCM, mimeType);
						clients[newClientFd]->setPort(ntohs(vSocket[index].getSocketAddr().sin_port));
						clients[newClientFd]->setAddress(ntohl(vSocket[index].getSocketAddr().sin_addr.s_addr));
						pollFds.addConnectionFd(newClientFd);
					}
				}
				else
				{
					char buffer[TCP_MAX_BUFF] = {0};
					nReaded = recv(eventFd , buffer, TCP_MAX_BUFF, 0);
					if (nReaded <= 0)
					{
						if (nReaded < 0)
							std::cout << RED << "Error " << WHITE << ": read()." << RESETCOLOR << "\n";
						
						std::cout << YELLOW << "Connection closed!" << RESETCOLOR << "\n";
						delete clients[eventFd];
						clients.erase(eventFd);
						pollFds.removeConnectionFd(i);
					}
					else if (nReaded > 0)
						clients[eventFd]->processRequst(buffer, nReaded, servers);
				}
			}
			else if (rEvent & POLLOUT)
			{
				if (!clients[eventFd]->getResponse().empty())
				{
					int sizeSended = clients[eventFd]->getSizeSended();
					int ret  = send(eventFd,
						clients[eventFd]->getResponse().c_str() + sizeSended,
						clients[eventFd]->getResponseSize() - sizeSended, 0);

					clients[eventFd]->setSizeSended(ret);
					if (clients[eventFd]->getSizeSended() == clients[eventFd]->getResponseSize())
					{
						int result = clients[eventFd]->reset();
						if (!result)
						{
							std::cout << YELLOW << "Connection closed!" << RESETCOLOR << "\n";
							delete clients[eventFd];
							clients.erase(eventFd);
							pollFds.removeConnectionFd(i);
						}
					}
				}
			}
		}

	}//Eventloop End
}

void runWebserv(std::list<Server> &servers)
{
	std::list<Server>::iterator serverIt = servers.begin();
	std::list<Server>::iterator serverEnd = servers.end();
	std::set<std::pair<std::string, int> > uniquePort;
	for (; serverIt != serverEnd; ++serverIt)
	{
		std::set<std::pair<std::string, int> >::iterator portIt = serverIt->getListenPorts().begin();
		std::set<std::pair<std::string, int> >::iterator portend = serverIt->getListenPorts().end();
		for (; portIt != portend; ++portIt)
			uniquePort.insert(std::make_pair(portIt->first, portIt->second));
	}

	std::vector<ft::Socket > vSockets;
	vSockets.reserve(uniquePort.size());
	std::set<std::pair<std::string, int> >::iterator portIt = uniquePort.begin();
	std::set<std::pair<std::string, int> >::iterator portEnd = uniquePort.end();
	for (; portIt != portEnd; ++portIt)
	{
		int port = portIt->second;
		unsigned int host = inet_addr(portIt->first.c_str());

		vSockets.push_back(ft::Socket());
		ft::Socket &sock = vSockets.back();
		if (sock.handler(port, host) == -1)
		{
			vSockets.pop_back();
			continue;
		}
	}
	if (vSockets.size() == 0)
	{
		std::cout << RED << "Error " << WHITE << ": There's no Socket" << RESETCOLOR << "\n";
		exit(-1);
	}
	eventLoop(vSockets, servers);
}

bool sortBylenth(std::string s1, std::string s2)
{
	return (s1.length() > s2.length());
}

std::string itos(int num)
{
	int nbr = num;
	std::string str;
	if (nbr == 0)
		str = "0";
	while (nbr > 0)
	{
		str += nbr % 10 + 48;
		nbr /= 10;
	}
	std::reverse(str.begin(), str.end());
	return (str);
}

void initStatusCM(std::map<int, const std::string> &statusCM)
{
	statusCM.insert(std::make_pair(200, "OK"));
	statusCM.insert(std::make_pair(201, "Created"));
	statusCM.insert(std::make_pair(204, "No Content"));

	statusCM.insert(std::make_pair(301, "Moved Permanently"));
	statusCM.insert(std::make_pair(302, "Found"));
	statusCM.insert(std::make_pair(303, "See Other"));
	statusCM.insert(std::make_pair(307, "Temporary Redirect"));

	statusCM.insert(std::make_pair(400, "Bad Request"));
	statusCM.insert(std::make_pair(403, "Forbidden"));
	statusCM.insert(std::make_pair(404, "Not Found"));
	statusCM.insert(std::make_pair(405, "Method Not Allowed"));
	statusCM.insert(std::make_pair(409, "Conflict"));
	statusCM.insert(std::make_pair(413, "Request Entity Too Large"));

	statusCM.insert(std::make_pair(500, "Internal Server Error"));
	statusCM.insert(std::make_pair(501, "Not Implemented"));
	statusCM.insert(std::make_pair(502, "Bad Gateway"));
	statusCM.insert(std::make_pair(505, "HTTP Version Not Supported"));
}

void initMimeType(std::map<std::string, const std::string> &mimeType)
{
	std::string line, extension, type , del = "::";
	std::ifstream file;
	file.open("src/mimeType.types");
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::getline(file, line);
			extension = line.substr(0, line.find(del));
			type = line.substr(line.find(del)+2);
			mimeType.insert(std::make_pair(type, extension)); 
		}
	}
	else
	{
		std::cout << RED << "Error " << WHITE << ": MimeType file not found." << RESETCOLOR << "\n";
	}
}