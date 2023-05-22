#pragma once
#include <cstdio>
#include <stdlib.h>   //for exit(0), system("cls")
#include <conio.h>    //For kbhit, getch()
#include <time.h>     //For clock(),clock_t
#include "header.h"
#include "common.h"
#pragma warning (disable: 4996)

class time
{
public:
	static void delay(int);
	static void counter(int, int, int&, int&, int&, int&, int, int);
	static void printData(int, int, int, int, int, int);
	static int selection(int, int, int&, int&, int&, int&, int);
	static void timer(int, int, int&, int&, int&, int&, int, int);
	static int recallHour(int);
	static int recallMin(int);
	static int recallSec(int);
	static void stayTime(int, int, int&, int&, int&, int&, int);
	static void timerForBot(int, int, int&, int&, int&, int&, int, int);
};
