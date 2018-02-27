/*
** SessionManager.h for SManager in /home/lezard/rendu/C++/tek3/cpp_spider/server
** 
** Made by Lezard
** Login   <lucas.onillon@epitech.eu>
** 
** Started on  Mon Oct  2 16:08:17 2017 Lezard
** Last update Mon Nov  6 17:44:59 2017 Lezard
*/

#ifndef SESSION_H_
#define SESSION_H_

/*
** Standard header inclusions
*/
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <vector>

/*
** Personnal header inclusion.
*/
#include "CommandInput.h"
#include "Data.h"
#include "SessionManager.h"
#include "PacketManager.h"
//using boost::asio::ip::tcp;

/*
** Session class definition, handle the client session from the server.
*/
class SessionManager;
class CBoost;
class Session : public std::enable_shared_from_this<Session>
{
public:
  Session(int id, boost::asio::ip::tcp::socket socket, std::weak_ptr<SessionManager> sessionManager);
  ~Session();
  void                                  start();
  boost::asio::ip::tcp::socket const    &getSocket();
  bool                                  isMySocket(boost::asio::ip::tcp::socket const &socket) const;
  int                                   getId() const;
 

private:
  void                                  do_read();
  void                                  do_write(std::size_t length);
  void                                  handle_read_content(const boost::system::error_code &err);
  void                                  deleteMe();
  std::shared_ptr<Session>              getSharedPtr();


  int                                   id_;
  boost::asio::ip::tcp::socket          socket_;
  enum
  {
    max_length = sizeof(t_packet)
  };
  char                                  data_[max_length];
  std::vector<std::shared_ptr<Session>> sessions_;
  std::shared_ptr<SessionManager>       sessionManager_;
  std::string                           ip_;
  PacketManager                         packetManager;
};

#endif /* !SESSION_H_ */
