#ifndef ANetwork_H_
#define ANetwork_H_

/*
** Standard header inclusions.
*/
#include <iostream>
#include <cstdlib>
#include <utility>
#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <list>

/*
** Personnal header inclusion.
*/

/**
 * Abstraction de boost::asio
 * */
class ANetwork
{

  public:
    ANetwork(unsigned short port) { this->port = port; }
    virtual ~ANetwork() {}
    /**
    * RunSession() permet de lancer le service via io_service
    **/
    virtual void                            runServer() = 0;
    /**
    * Accept() est la fonction receptrice d'une nouvelle connexion
    **/
    virtual boost::asio::ip::tcp::acceptor  &accept() = 0;

  protected:
    unsigned short                          port;
};

#endif /* !ANetwork_H_ */