#ifndef SOCKET_MANAGER_H_
#define	SOCKET_MANAGER_H_

#include "ASocket.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class socketManager : public ASocket
{
private:
	const char			*_hostname;
	const char			*_port;

	bool				_isConnected;

	size_t				request_length;

	boost::asio::io_service			io_service;
	boost::asio::ip::tcp::socket	sock;
	boost::asio::ip::tcp::resolver	resolver;

public:
	socketManager(const char *hostname, const char *_port);
	~socketManager();

	virtual int		initConnect();
	virtual int		responseServer();
	virtual void	sendSocket(void* data);
	virtual bool	isConnected() const;
	void			setIsConnected(bool value);
};


#endif // !SOCKET_MANAGER_H_