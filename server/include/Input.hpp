//
// Input.hpp for  in /home/beche/rendu/cpp_spider/server
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Fri Oct  6 21:20:58 2017 beche
// Last update Sat Oct  7 13:55:53 2017 beche
//

#ifndef INPUT_HPP_
# define INPUT_HPP_
#include <iostream>

#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "CommandOutput.hpp"

class Input
{
public:
  Input(boost::asio::io_service& io_service);
  ~Input();

  void					                        read();
  void					                        read_handler(const boost::system::error_code& error);


  boost::asio::io_service		            io_service;
  boost::asio::posix::stream_descriptor input;
  boost::asio::streambuf		            inStream;
  boost::system::error_code		          ec;
  char				                        	data_[1024];
  CommandOutput			                  	command;
};
#endif /* INPUT_HPP_ */
