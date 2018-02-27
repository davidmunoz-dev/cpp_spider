#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include "socketManager.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/asio.hpp>

namespace Serializer {

	template <typename T>
	void	deserialize(T &packet, boost::asio::streambuf *buf)
	{
		std::istream is(buf);
		(void)packet;
		boost::archive::text_iarchive ar(is);
		ar & packet;
	}

	template <typename T>
	void	serialize(T &p, boost::asio::streambuf &buf)
	{
		std::ostream os(&buf);
		boost::archive::text_oarchive ar(os);
		ar & p;
	}

}

#endif // !SERIALIZER_H_