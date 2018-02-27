#ifndef ASOCKET_H_
#define ASOCKET_H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>

class ASocket
{
public:
	ASocket(const char *hostname, const char *port);
	virtual ~ASocket() {}

	virtual int		initConnect() = 0;
	virtual int		responseServer() = 0;
	virtual void	sendSocket(void* data) = 0;

protected:
	const char *_hostname;
	const char *_port;
	bool		_isConnected;
};

#endif // !ASOCKET_H_