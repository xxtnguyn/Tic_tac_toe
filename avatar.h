#pragma once
#include "header.h"
#include "data.h"
#include "common.h"
#include "menu.h"

class avatar
{
public:
	static void rightAmongUs(int, int, int, int, int);	// Vẽ nhân vật among us phải
	static void leftAmongUs(int, int, int, int, int, int);	// Vẽ nhân vật among us trái
	static void leftAmongUsHead(int, int, int);		// Vẽ đầu among us
	static void Bot(int, int);				// Vẽ con bot fithcmus
	static void BotHead(int, int, int, int);		// Vẽ phần đầu con bot
};
