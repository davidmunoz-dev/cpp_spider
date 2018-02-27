#ifndef CORE_H_
#define	CORE_H_

#include <iostream>

class core
{
private:
	std::string		port;
	std::string		address;

public:
	core();
	~core();

	int		init();
	int		invisibleSpider();
	int		infoConnection();
	void	connectServer();
};

#endif // !CORE_H_
