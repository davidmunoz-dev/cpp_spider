#ifndef Server_H_
# define Server_H_


/*
** Standard header inclusions.
*/
# include <iostream>
# include <cstdlib>
# include <utility>
# include <memory>
# include <boost/asio.hpp>
# include <boost/bind.hpp>
# include <list>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
/*
** Personnal header inclusion.
*/
#include "ANetwork.h"
# include "Session.h"
#include "SessionManager.h"

class Server : public ANetwork{
public:
    Server(unsigned short port);
    ~Server();

    boost::asio::ip::tcp::acceptor&         accept() override;
    void                                    runServer() override ;

    int                                     ids = 0;
    std::vector<std::shared_ptr<Session>>   sessions;
    boost::asio::io_service                 io;
    boost::asio::ip::tcp::acceptor	        acceptor_;
    boost::asio::ip::tcp::socket		    socket_;
    std::shared_ptr<SessionManager>         sessionManager_;
};
#endif /* !Server_H_ */