#ifndef SENDDATA_H_
#define SENDDATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <mutex>

#define		KEYBOARD_DATA	1
#define		MOUSE_DATA		2

typedef struct		s_paquet 
{
		char				opcode;
		unsigned int	timestamp;
		char			key_code;
		int			status;
		int			x;
		int			y;
		char			k[30];
		char		name[50];
}					t_paquet;

class sendData
{
private:
	t_paquet			*keyboard;
	t_paquet			*mouse;
	std::mutex			myMutex;

public:
	sendData();
	~sendData();

	virtual int		sendMouse();
	virtual int		sendKey();
	virtual int		fillStruct(std::string);
	virtual void	printData(int type);
	t_paquet		*getMouseData() const;
	t_paquet		*getKeyData() const;
};

#endif // !SENDDATA_H_

