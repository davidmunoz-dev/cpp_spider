#include <cstddef>
#include "SessionManager.h"
#include <vector>
#include <memory>
#include "Session.h"

#include <iostream>
#include <map>

SessionManager::SessionManager()
{
}

SessionManager::~SessionManager()
{
}

bool SessionManager::removeSessionById(int const id)
{
    (void)id;
 
    std::vector<std::shared_ptr<Session>>::iterator i;
	for (i = this->sessions_.begin(); i != this->sessions_.end(); ++i)
	{
		if (i->get()->getId() == id)
		{
			try
			{
				i->reset();
			}
			catch (std::bad_alloc const &e)
			{
				std::cerr << "exception caught: " << e.what() << '\n';
			}

			this->sessions_.erase(i);
			return true;
		}
	}
    return false;
}

bool SessionManager::pushSession(std::shared_ptr<Session> const &session)
{
    this->sessions_.push_back(session);
    return false;
}

int SessionManager::getNbSessions() const{
    return this->sessions_.size();
}