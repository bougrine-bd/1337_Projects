#include "../Include/Webserv.hpp"

namespace ft
{
	Client::Client(std::map<int, const std::string> &statusCM, std::map<std::string, const std::string> &mimeType):
		_response(_request, statusCM, mimeType), _port(0), _address(0), _sizeSended(0) {}
	Client::~Client(){}

	void Client::setPort(uint16_t port)
	{
		_port = port;
	}

	void Client::setAddress(uint32_t address)
	{
		_address = address;
	}

	std::string	Client::getResponse()
	{
		return (_response.getResponse());
	}

	int			Client::getResponseSize()
	{
		return (_response.getResponse().length());
	}

	int			Client::getSizeSended()
	{
		return (_sizeSended);
	}

	void		Client::setSizeSended(int ret)
	{
		_sizeSended += ret;
	}

	void Client::processRequst(const char *buff, int size, std::list<Server> &servers)
	{
		
		_parsingResult = _request.parse(buff, size);
		_response.handler( _parsingResult, servers, _port, _address);
	}

	int		Client::reset()
	{
		if (!_request.isKeepAlive())
			return (0);
		_sizeSended = 0;
		_response.setResponse("");
		_request.reset();
		return (1);
	}
}