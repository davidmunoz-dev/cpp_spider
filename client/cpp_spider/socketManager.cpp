#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "socketManager.h"
#include "sendData.h"
#include "spider.h"

enum { max_length = 1024 };

socketManager::socketManager(const char *hostname, const char *port) : ASocket(hostname, port), sock(io_service), resolver(io_service)
{
	this->_hostname = hostname;
	this->_port = port;
	this->_isConnected = false;
}

socketManager::~socketManager()
{}

int		socketManager::initConnect()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	boost::system::error_code error;
	boost::asio::ip::tcp::resolver::iterator	it;
	std::cout << "Connecting to " << _hostname << " : " << _port << std::endl;
	it = boost::asio::connect(sock, resolver.resolve({ _hostname, _port }), error);
	while (error != 0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[ERROR] Can't reach " << _hostname << "..." << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Connecting to " << _hostname << " : " << _port << std::endl;
		it = boost::asio::connect(sock, resolver.resolve({ _hostname, _port }), error);
	}
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "Connected to " << it->endpoint() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	_isConnected = true;
	return (SPIDER_OK);
}

void	socketManager::sendSocket(void* data)
{
//	char* my_s_bytes = static_cast<char*>(static_cast<void*>(&my_s));
	boost::asio::write(sock, boost::asio::buffer(data, sizeof(t_paquet)));
}

bool	socketManager::isConnected() const
{
	return (_isConnected);
}

void	socketManager::setIsConnected(bool value)
{
	this->_isConnected = value;
}

int		socketManager::responseServer()
{
	char reply[max_length];
	size_t reply_length = boost::asio::read(sock, boost::asio::buffer(reply, request_length));
	std::cout << "Reply is: ";
	std::cout.write(reply, reply_length);
	std::cout << "\n";
	return (SPIDER_OK);
}