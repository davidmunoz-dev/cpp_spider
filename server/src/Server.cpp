//
// command.cpp for  in /home/beche/rendu/test
//
// Made by beche
// Login   <francois.beche@epitech.eu>
//
// Started on  Tue Oct  3 13:15:33 2017 beche
// Last update Sat Oct  7 15:58:58 2017 beche
//

#include "Server.h"

Server::Server(unsigned short port) : ANetwork(port), acceptor_(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
                                      socket_(io)
{
    this->sessionManager_ = std::make_shared<SessionManager>();
    this->accept();
}

Server::~Server() {}

void Server::runServer()
{
    while (true)
    {
        this->io.run();
    }
}

boost::asio::ip::tcp::acceptor &Server::accept()
{
    acceptor_.async_accept(this->socket_,
                           [this](boost::system::error_code ec) {
                               if (!ec)
                               {
                                   std::cout << "Accepted\n";
                                   try
                                   {
                                       std::shared_ptr<Session> tmp = std::make_shared<Session>(ids, std::move(this->socket_), sessionManager_);
                                       this->sessionManager_->pushSession(tmp);
                                       tmp->start();
                                       ids++;
                                   }
                                   catch (std::bad_alloc const &e)
                                   {
                                       std::cerr << "exception caught: " << e.what() << '\n';
                                   }
                               }
                               accept();
                           });
    return acceptor_;
}