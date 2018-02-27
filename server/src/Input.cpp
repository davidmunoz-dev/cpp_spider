//
// Input.cpp for  in /home/beche/rendu/cpp_spider/server/src
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Fri Oct  6 21:20:47 2017 beche
// Last update Sat Oct  7 13:56:01 2017 beche
//

#include <iostream>
#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "Input.hpp"
#include "CommandOutput.hpp"

using namespace boost::asio;
using namespace std;

Input::Input(boost::asio::io_service& io): input(io, STDIN_FILENO)
{
  this->read();
}

Input::~Input()
{}

void	Input::read_handler(const boost::system::error_code& error){
  (void)error;

  std::istream is(&inStream);
  std::string line;
  std::getline(is, line);
  std::cout << line << std::endl;
  this->command.exec(line);
  this->read();
}

void Input::read(){
  boost::asio::async_read_until(input,inStream, "\n",
  				bind(&Input::read_handler,this, boost::asio::placeholders::error));
}


