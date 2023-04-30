#pragma once
#include "header.h"
#include "data.h"
#include "common.h"
#include "menu.h"

class avatar
{
public:
	static void Cat(int, int);						// Vẽ mèo
	static void rightAmongUs(int, int, int, int);					// Vẽ nhân vật among us phải
	static void leftAmongUs(int, int, int, int);	// Vẽ nhân vật among us trái
	static void leftAmongUsHead(int, int, int, int);	// Vẽ đầu among us
};
