//
// ServerManager.cpp for serverManager in /home/lezard/rendu/C++/tek3/cpp_spider/server
//
// Made by Lezard
// Login   <lucas.onillon@epitech.eu>
//
// Started on  Mon Oct  2 16:54:34 2017 Lezard
// Last update Sat Oct  7 19:43:42 2017 Lezard
//

#include <iostream>
#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio.hpp>
#include "Server.h"

int main(int ac, char **av)
{
  try
  {
    if (ac != 2)
    {
      std::cerr << "Usage: async_tcp_echo_server <port>\n";
      return (1);
    }
    Server *server = new Server(std::atoi(av[1]));
    server->runServer();
    (void)server;
  }
  catch (std::exception &err)
  {
    std::cerr << "Exception: " << err.what() << "\n";
  }
  return (0);
}
