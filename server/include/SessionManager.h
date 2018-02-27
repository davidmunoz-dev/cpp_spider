#ifndef SESSIONMANAGER_H_
#define SESSIONMANAGER_H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <map>

class Session;
class SessionManager
{

  public:
    SessionManager();
    ~SessionManager();
    bool                                  removeSessionById(int const id);
    bool                                  pushSession(std::shared_ptr<Session> const &session);
    int                                   getNbSessions() const;
  private:
    std::vector<std::shared_ptr<Session>> sessions_;
};

#endif /*!SESSIONMANAGER_H_ */
