#include "header.h"
#include "common.h"
#include "menu.h"

int main()
{
	common::setUpConsole();
	_getch();
	system("color F0");
	menu::Tutorial();
	Sleep(1000);
	common::clearConsole();
	draw::printIntro();
	draw::printAnimatedBigXandBigO(96, 10, 1, 10);
	menu::mainScreen();
}
