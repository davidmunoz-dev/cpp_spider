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

//#include "../include/Serializer.h"

using boost::asio::ip::tcp;

enum { max_length = 1024 };



int add_node(t_mouseData *l)
{
  // t_mouseData *tmp;

  // tmp = l;
  while (l->next != NULL)
    l = l->next;

  l->next = new t_mouseData;
  l->next->timestamp=6666698;
  l->next->key_code = 43;
  l->next->x = 1;
  l->next->y = 9;
  l->next->status = 1;
  l->next->next = NULL;
  return (0);
}
int main(int argc, char* argv[])
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
	      








	      t_paquet p;
	      p.id = "toto"; 
	      p.opcode = 0x05;
	      p.kbdata = NULL;
	      p.msdata = NULL;
	      // t_kb_data *kb = new t_kb_data;
	      
	      // t_kb_data *kb2 = new t_kb_data;
	      // kb2->next = NULL;
	      // kb2->timestamp = 8888;
	      // kb2->key_code = 54;
	      
	      // kb->timestamp = 9999;
	      // kb->key_code = 53;
	      // kb->next = kb2;

	      
	      // p.kbdata = kb;
	      // p.msdata = NULL;



	      t_mouseData *ms = new t_mouseData;

	      	      t_mouseData *ms2 = new t_mouseData;

	      ms2->timestamp=66666;
	      ms2->key_code = 43;
	      ms2->x = 1;
	      ms2->y = 9;
	      ms2->status = 1;
	      ms2->next = NULL;

	      ms->timestamp=555566;
	      ms->key_code = 43;
	      ms->x = 1;
	      ms->y = 9;
	      ms->status = 1;
	      ms->next = ms2;

	      p.kbdata = NULL;
	      p.msdata = ms;
	      

	      // ms2->next = new t_mouseData;

	      // ms2->next->timestamp=6666698;
	      // ms2->next->key_code = 43;
	      // ms2->next->x = 1;
	      // ms2->next->y = 9;
	      // ms2->next->status = 1;
	      // ms2->next->next = NULL;

	      //	      t_mouseData *tmp = ms2->next;
	      int i = 0;
	      while (i < 10){
		add_node(ms);
		i++;
	      }
	      // t_mouseData *tmp = new t_mouseData;
	      // t_mouseData *tmp1 = tmp;
	      
	      // int	i = 0;
	      // while (i < 100)
	      // 	{
		  
	      // 	  tmp->timestamp=555566;
	      // 	  tmp->key_code = 43;
	      // 	  tmp->x = 1;
	      // 	  tmp->y = 9;
	      // 	  tmp->status = 1;
	      // 	  tmp->next = NULL;
	      // 	  tmp = tmp->next;
	      // 	  tmp = new t_mouseData;
		  
	      // 	  i++;
	      // 	}

	      // ms2->next = tmp1;


	      boost::asio::streambuf buf;
	      std::ostream os( &buf );
	      boost::archive::text_oarchive ar( os );
	      ar & p;


	      // boost::asio::streambuf buf;
	      // // std::ostream os( &buf );
	      // // boost::archive::text_oarchive ar( os );
	      // // ar & p;

	      // Serializer::serialize(p, buf);

	      // const size_t header = buf.size();
	      // std::cout << "buffer size " << header << " bytes" << std::endl;

	      // // send header and buffer using scatter
	      // std::vector<boost::asio::const_buffer> buffers;
	      // //	      buffers.push_back( boost::asio::buffer(&header, sizeof(header)) );
	      // buffers.push_back( buf.data() );
	      const size_t rc = boost::asio::write(s, buf);
	      std::cout << "wrote " << rc << " bytes" << std::endl;;
	    


      }
    catch (std::exception& e)
      {
	std::cerr << "Exception: " << e.what() << "\n";
      }

    return 0;
}
