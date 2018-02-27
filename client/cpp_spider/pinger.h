#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <istream>
#include <iostream>
#include <ostream>

namespace posix_time = boost::posix_time;

class pinger
{
public:
	pinger(boost::asio::io_service& io_service, const char* destination);
	bool	getConnected() const;

private:
	int		counter;
	void	start_send();
	void	handle_timeout();
	void	start_receive();
	void	handle_receive(std::size_t length);
	static unsigned short get_identifier();

	boost::asio::ip::icmp::resolver	resolver_;
	boost::asio::ip::icmp::endpoint	destination_;
	boost::asio::ip::icmp::socket	socket_;
	boost::asio::deadline_timer		timer_;
	unsigned short	sequence_number_;
	posix_time::ptime	time_sent_;
	boost::asio::streambuf	reply_buffer_;
	std::size_t	num_replies_;
	bool	_isConnected;
};
