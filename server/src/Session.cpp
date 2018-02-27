//
// SessionManager.cpp for sessionManager in /home/lezard/rendu/C++/tek3/cpp_spider/server
//
// Made by Lezard
// Login   <lucas.onillon@epitech.eu>
//
// Started on  Mon Oct  2 16:14:57 2017 Lezard
// Last update Mon Nov  6 17:40:22 2017 Lezard
//
#include <iostream>
#include <Data.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/asio.hpp>
#include <boost/asio/read.hpp>
#include "Session.h"
#include "CommandInput.h"
#include "Data.h"
#include "Server.h"
#include <vector>
#include <list>
#include "CommandOutput.hpp"

void Session::do_read()
{
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
							[this](boost::system::error_code ec, std::size_t length) {
								if (!ec)
								{
									std::cout << "****************************NEW READ*****************************" << std::endl;
									std::cout << "Readed size => " << length << " ||| waited size => " << max_length << std::endl;
									data_[length] = 0;
									char *tmp = data_;
									packetManager.pushPacket(tmp, length);
									(void)length;
									do_read();
								}
								else if (ec == boost::asio::error::eof)
								{
									std::cout << "EOF\n";
									this->sessionManager_->removeSessionById(this->id_);
								}
							});
}

int Session::getId() const
{
	return this->id_;
}

void Session::start()
{
	do_read();
}

Session::Session(int id, boost::asio::ip::tcp::socket socket, std::weak_ptr<SessionManager> sessions)
	: id_(id), socket_(std::move(socket)), sessionManager_(sessions)
{
	this->ip_ = socket_.remote_endpoint().address().to_string();
	std::cout << "new session : " << this->id_ << ":" << this->ip_ << "\n";
	size_t i = 0;
	while (i < sizeof(t_packet))
	{
		data_[i] = 0;
		i++;
	}
}

Session::~Session()
{
	std::cout << "session destroy\n";
}
