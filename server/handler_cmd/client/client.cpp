//
// blocking_tcp_echo_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "../../include/Data.h"
#include "../include/Serializer.h"
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
#include <boost/asio.hpp>

#include <fstream>

#include <boost/asio.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/tuple/tuple.hpp>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <cstddef>
//#include "../include/Serializer.h"

using boost::asio::ip::tcp;

enum
{
	max_length = 1024
};

int main(int argc, char *argv[])
{

	try
	{
		if (argc != 3)
		{
			std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
			return 1;
		}

		boost::asio::io_service io_service;

		tcp::resolver resolver(io_service);
		tcp::resolver::query query(tcp::v4(), argv[1], argv[2]);
		tcp::resolver::iterator iterator = resolver.resolve(query);

		tcp::socket s(io_service);
		boost::asio::connect(s, iterator);

		using namespace std; // For strlen.

		char request[max_length];
		std::cout << "Enter message: ";
		std::cin.getline(request, max_length);

		int i = 0;
		t_packet p;
		//		while (i < 100000)
		//{
			p.opcode = i % 255;
			p.timestamp = i;
			p.type = i % 2;
			p.key_code = i;
			p.status = i;
			p.x = i;
			p.y = i;
			char *tmp = reinterpret_cast<char *>(&p);
			//i++;

			const size_t rc = boost::asio::write(s, boost::asio::buffer(tmp, sizeof(p)));
			//const size_t rc = boost::asio::write(s, buf);
			std::cout << "wrote " << rc << " bytes" << std::endl;
			;
			//}
			//	while (true);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
