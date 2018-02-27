#include "ASocket.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include "spider.h"

enum { max_length = 1024 };

ASocket::ASocket(const char *hostname, const char *port)
{
	this->_hostname = hostname;
	this->_port = port;
	this->_isConnected = false;
}