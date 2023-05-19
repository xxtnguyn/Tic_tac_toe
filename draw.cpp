#include "draw.h"
#include "gameplay.h"
#ifdef __cpp_lib_filesystem
#include <filesystem>
namespace fs = std::filesystem;
#elif __cpp_lib_experimental_filesystem
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#error "no filesystem support ='("
#endif

void draw::rainbowBackground()
{
	int color[] = { 12, 14 , 9, 13 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 105; j++) {
			for (int k = 0; k < 8; k++) {
				common::setColor(color[i]);
				common::gotoXY(j, i * 8 + k);
				putchar(219);
			}
		}
	}
	
	common::setColor(color[3]);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 105; j++) {
			common::gotoXY(j, 24 + i);
			putchar(219);
		}
	}

	common::setColor(15);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 44; j++) {
			common::gotoXY(32 + j, 8 + i);
			putchar(219);
		}
	}
	Cat(10, 0, LIGHT_RED, LIGHT_RED);
	Cat(10, 16, LIGHT_BLUE, LIGHT_BLUE);
	Cat(85, 8, LIGHT_YELLOW, LIGHT_YELLOW);
	Cat(85, 23, LIGHT_PURPLE, LIGHT_BLUE);
}

void draw::rainbowColumn() {
	int color[] = { 12, 14, 10, 9, 13 };
	int x = 23, y = 0;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 12; k++) {
			for (int j = 0; j < 31; j++) {
				common::setColor(color[i]);
				common::gotoXY(x + i * 12 + k, j);
				putchar(219);
			}
		}
	}
}

void draw::printBoard(int left, int top, int width, int height, int color)
{
	common::setConsoleColor(BRIGHT_WHITE, color);
	common::gotoXY(left, top);
	putchar(201);
	for (int i = 1; i < width; i++)
	{
		putchar(205);
	}
	putchar(187);


	for (int i = 1; i < height; i++)
	{
		common::gotoXY(left, top + i);
		putchar(186);
		common::gotoXY(left + width, top + i);
		putchar(186);
	}
	common::gotoXY(left, top + height);
	putchar(200);
	for (int i = 1; i < width; i++)
	{
		putchar(205);
	}
	putchar(188);
}

void draw::printLogo()
{
	printColoredRectangle(27, 2, 35, 11, RED);
	printColoredRectangle(25, 1, 35, 11, LIGHT_RED);
	Sleep(500);
	printColoredRectangle(52, 6, 35, 11, BLUE);
	printColoredRectangle(50, 5, 35, 11, LIGHT_BLUE);
	Sleep(500);
	unsigned char logo[] = {
		32 ,219,219,219,219,219,219,187,32 ,219,219,219,219,219,187,32 ,32 ,32 ,32 ,219,219,219,219,219,219,187,32 ,32 ,219,219,219,219,219,219,187,32 ,
		219,219,201,205,205,205,205,188,219,219,201,205,205,219,219,187,32 ,32 ,32 ,219,219,201,205,205,219,219,187,219,219,201,205,205,205,219,219,187,
		219,219,186,32 ,32 ,32 ,32 ,32 ,219,219,219,219,219,219,219,186,32 ,32 ,32 ,219,219,219,219,219,219,201,188,219,219,186,32 ,32 ,32 ,219,219,186,
		219,219,186,32 ,32 ,32 ,32 ,32 ,219,219,201,205,205,219,219,186,32 ,32 ,32 ,219,219,201,205,205,219,219,187,219,219,186,32 ,32 ,32 ,219,219,186,
		200,219,219,219,219,219,219,187,219,219,186,32 ,32 ,219,219,186,32 ,32 ,32 ,219,219,186,32 ,32 ,219,219,186,200,219,219,219,219,219,219,201,188,
		32 ,200,205,205,205,205,205,188,200,205,188,32 ,32 ,200,205,188,32 ,32 ,32 ,200,205,188,32 ,32 ,200,205,188,32 ,200,205,205,205,205,205,188,32 };
	int top = 6, left = 33;
	int num_lines = 6, num_chars = 36;
	int k = -17;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{
			if (j == 17) k = 0;
			if (k % 36 == 0) common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
			else if (j % 36 == 0) common::setConsoleColor(LIGHT_RED, BRIGHT_WHITE);
			putchar(logo[i * num_chars + j]);
			k++;
		}
		Sleep(75);
	}
	Sleep(100);
	common::setConsoleColor(LIGHT_RED, BRIGHT_WHITE);
	printX(26, 1);
	Sleep(100);
	common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	printO(81, 13);
	common::gotoXY(25, 25);
}

void draw::printIntro()
{
	int x = 31;
	int y = 5;
	rainbowColumn();
	unsigned char intro_Welcome[] = { 205, 203, 205, 32 , 32 , 32 , 205, 203, 205, 32 , 203, 205, 205, 187, 32 , 205, 203, 205, 32 , 32 , 32 , 32 , 203, 205, 205, 187, 32 , 203, 205, 205, 203, 32 , 32 , 203, 205, 203, 205, 203, 32 , 32 , 203, 205, 205, 187,
									 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 186, 32 , 186, 32 , 32 , 186, 32 , 32 , 32 ,
									 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 204, 205, 185, 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 186, 32 , 186, 32 , 32 , 204, 205, 185, 32 ,
									 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 ,
									 32 , 202, 205, 205, 202, 205, 205, 202, 32 , 32 , 202, 205, 205, 188, 32 , 205, 202, 205, 205, 205, 188, 32 , 202, 205, 205, 188, 32 , 202, 205, 205, 202, 32 , 205, 202, 205, 32 , 205, 202, 205, 32 , 202, 205, 205, 188,

	};
	unsigned char intro_Player[] = { 205, 203, 205, 205, 187, 32 , 205, 203, 205, 32 , 32 , 32 , 32 , 201, 205, 205, 187, 32 , 205, 203, 205, 32 , 205, 203, 205, 32 , 203, 205, 205, 187, 32 , 205, 203, 205, 205, 187,
									32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 186,
									205, 206, 205, 205, 188, 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 206, 205, 205, 206, 32 , 32 , 200, 205, 203, 205, 188, 32 , 32 , 204, 205, 185, 32 , 32 , 205, 206, 205, 203, 188,
									32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 32 , 186, 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 186, 32 , 32 , 32 , 32 , 32 , 186, 32 , 186, 32 ,
									205, 202, 205, 32 , 32 , 32 , 205, 202, 205, 205, 205, 188, 32 , 202, 32 , 32 , 202, 32 , 32 , 32 , 205, 202, 205, 32 , 32 , 32 , 202, 205, 205, 188, 32 , 205, 202, 32 , 200, 205,
	};

	common::setColor(15);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 49; j++) {
			common::gotoXY(x - 2 + j, y - 1 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 41; j++) {
			common::gotoXY(x + 1 + j, y + 7 + i);
			putchar(219);
		}
	}

	printBoard(x - 3, y - 2, 49, 8, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 44; j++) {
			common::gotoXY(x + j, y + i);
			putchar(intro_Welcome[i * 44 + j]);

		}
	}

	printBoard(x + 1, y + 6, 41, 5, BLACK);
	common::setColor(15);
	for (int i = 0; i < 42; i++) {
		common::gotoXY(x + i + 1, 11);
		putchar(219);
	}
	common::setColor(0);
	common::gotoXY(x + 1, 11); putchar(187);
	common::gotoXY(x + 42, 11); putchar(201);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 36; j++) {
			common::gotoXY(x + 4 + j, y + 5 + i);
			putchar(intro_Player[i * 36 + j]);
		}
	}
}

void draw::printRectangle(int left, int top, int width, int height)
{
	common::gotoXY(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		common::gotoXY(left, top + i + 1);
		putchar(179);
		common::gotoXY(left + width + 1, top + i + 1);
		putchar(179);
	}

	common::gotoXY(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}

void draw::printColoredRectangle(int left, int top, int width, int height, int color)
{
	common::gotoXY(left, top);
	common::setConsoleColor(BRIGHT_WHITE, color);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) putchar(219);
		common::gotoXY(left, top + i + 1);
	}
}

void draw::printX(int left, int top)
{
	common::gotoXY(left, top);
	putchar(220);
	common::gotoXY(left + 2, top);
	putchar(220);
	common::gotoXY(left + 1, top + 1);
	putchar(219);
	common::gotoXY(left, top + 2);
	putchar(223);
	common::gotoXY(left + 2, top + 2);
	putchar(223);
}

void draw::printO(int left, int top)
{
	common::gotoXY(left + 1, top);
	putchar(220);
	common::gotoXY(left, top + 1);
	putchar(219);
	common::gotoXY(left + 2, top + 1);
	putchar(219);
	common::gotoXY(left + 1, top + 2);
	putchar(223);
}

void draw::printBigX(int left, int top, int color1, int color2)
{
	common::setConsoleColor(color2, color1);
	unsigned char bigX[] = {
		219,219,187,32 ,32 ,219,219,187,
		200,219,219,187,219,219,201,188,
		32 ,200,219,219,219,201,188,32 ,
		32 ,219,219,201,219,219,187,32 ,
		219,219,201,188,32 ,219,219,187,
		200,205,188,32 ,32 ,200,205,188 };
	int t = top, l = left;
	int num_lines = 6, num_chars = 8;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(bigX[i * num_chars + j]);
	}
}

void draw::printBigO(int left, int top, int color1, int color2)
{
	common::setConsoleColor(color2, color1);
	unsigned char bigX[] = {
		32 ,219,219,219,219,219,219,187,32 ,
		219,219,201,205,205,205,219,219,187,
		219,219,186,32 ,32 ,32 ,219,219,186,
		219,219,186,32 ,32 ,32 ,219,219,186,
		200,219,219,219,219,219,219,201,188,
		32 ,200,205,205,205,205,205,188,32 };
	int t = top, l = left;
	int num_lines = 6, num_chars = 9;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
			putchar(bigX[i * num_chars + j]);
	}
}

void draw::printAnimatedBigXandBigO(int leftX, int topX, int leftO, int topO)
{
	int time = 0;
	int k = 1;
	int i = 1;
	while (i > 0)
	{
		printBigX(leftX, topX + i, i, BRIGHT_WHITE);
		printBigO(leftO, topO + 15 - i, 15 - i, BRIGHT_WHITE);
		time++;
		Sleep(100);
		if (i == 14) k = -1;
		if (i == 1) k = 1;
		i += k;
		if (time == 34)
		{
			common::clearConsole();
			break;
		}
	}
}

void draw::printTTN()
{

	unsigned char name[] = { 32 ,201,203,187,203,205,187,201,205,187,201,187,201,32 ,32 ,201,203,187,203,205,187,201,205,187,201,187,201,201,205,187,32 ,32 ,201,187,201,201,205,187,203,32 ,203,203,201,205,187,32 ,
							32 ,32 ,186,32 ,204,203,188,204,205,185,186,186,186,32 ,32 ,32 ,186,32 ,204,203,188,186,32 ,186,186,186,186,186,32 ,203,32 ,32 ,186,186,186,186,32 ,203,204,205,185,186,204,205,185,32 ,
							32 ,32 ,202,32 ,202,200,205,202,32 ,202,188,200,188,32 ,32 ,32 ,202,32 ,202,200,205,200,205,188,188,200,188,200,205,188,32 ,32 ,188,200,188,200,205,188,202,32 ,202,202,202,32 ,202,32 };
	int top = 2, left = 5;
	int num_lines = 3, num_chars = 46;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{

			common::setConsoleColor(AQUA, BRIGHT_WHITE);
			putchar(name[i * num_chars + j]);
		}
	}
	common::gotoXY(55, 3);
	common::setConsoleColor(BRIGHT_WHITE, AQUA);
	cout << "22120231";
}

void draw::printDNTN() {
	unsigned char name[] = { 32 ,201,203,187,201,205,187,201,205,187,32 ,32 ,201,187,201,201,205,187,201,205,187,201,205,187,32 ,32 ,201,203,187,203,32 ,203,201,205,187,201,205,187,32 ,32 ,201,187,201,201,205,187,203,32 ,203,203,32 ,203,201,205,187,201,187,201,32 ,
							 32 ,32 ,186,186,204,205,185,186,32 ,186,32 ,32 ,186,186,186,186,32 ,203,186,32 ,186,186,32 ,32 ,32 ,32 ,32 ,186,32 ,204,205,185,204,205,185,186,32 ,186,32 ,32 ,186,186,186,186,32 ,203,186,32 ,186,200,203,188,204,185,32 ,186,186,186,32 ,
							 32 ,205,202,188,202,32 ,202,200,205,188,32 ,32 ,188,200,188,200,205,188,200,205,188,200,205,188,32 ,32 ,32 ,202,32 ,202,32 ,202,202,32 ,202,200,205,188,32 ,32 ,188,200,188,200,205,188,200,205,188,32 ,202,32 ,200,205,188,188,200,188,32 };
	int top = 7, left = 42;
	int num_lines = 3, num_chars = 59;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{

			common::setConsoleColor(GREEN, BRIGHT_WHITE);
			putchar(name[i * num_chars + j]);
		}
	}
	common::gotoXY(30, 8);
	common::setConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "22120234";
}

void draw::printLTN()
{

	unsigned char name[] = { 32 ,203,32 ,32 ,201,205,187,32 ,32 ,201,203,187,203,205,187,201,205,187,201,187,201,201,205,187,32 ,32 ,201,187,201,201,205,187,203,32 ,203,203,201,205,187,32 ,
							32 ,186,32 ,32 ,204,185,32 ,32 ,32 ,32 ,186,32 ,204,203,188,186,32 ,186,186,186,186,186,32 ,203,32 ,32 ,186,186,186,186,32 ,203,204,205,185,186,204,205,185,32 ,
							32 ,202,205,188,200,205,188,32 ,32 ,32 ,202,32 ,202,200,205,200,205,188,188,200,188,200,205,188,32 ,32 ,188,200,188,200,205,188,202,32 ,202,202,202,32 ,202,32 };
	int top = 17, left = 60;
	int num_lines = 3, num_chars = 40;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{

			common::setConsoleColor(PURPLE, BRIGHT_WHITE);
			putchar(name[i * num_chars + j]);
		}
	}
	common::gotoXY(47, 18);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	cout << "22120226";
}

void draw::printTHKN()
{

	unsigned char name[] = { 32 ,201,203,187,203,205,187,201,205,187,201,187,201,32 ,32 ,203,32 ,203,201,205,187,201,205,187,201,187,201,201,205,187,32 ,32 ,203,201,205,203,201,203,187,32 ,32 ,201,187,201,201,205,187,201,205,187,201,187,201,32 ,
							32 ,32 ,186,32 ,204,203,188,204,205,185,186,186,186,32 ,32 ,204,205,185,186,32 ,186,204,205,185,186,186,186,186,32 ,203,32 ,32 ,204,202,187,186,186,186,186,32 ,32 ,186,186,186,186,32 ,203,204,205,185,186,186,186,32 ,
							32 ,32 ,202,32 ,202,200,205,202,32 ,202,188,200,188,32 ,32 ,202,32 ,202,200,205,188,202,32 ,202,188,200,188,200,205,188,32 ,32 ,202,32 ,202,202,202,32 ,202,32 ,32 ,188,200,188,200,205,188,202,32 ,202,188,200,188,32 };
	int top = 12, left = 6;
	int num_lines = 3, num_chars = 54;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{

			common::setConsoleColor(YELLOW, BRIGHT_WHITE);
			putchar(name[i * num_chars + j]);
		}
	}
	common::gotoXY(64, 13);
	common::setConsoleColor(BRIGHT_WHITE, YELLOW);
	cout << "22120224";
}

void draw::printInstructor()
{
	common::gotoXY(49, 22);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	cout << "INSTRUCTOR";
	unsigned char name[] = { 201,203,187,203,205,187,203,32 ,203,201,205,187,201,187,201,201,205,187,32 ,32 ,201,203,187,201,205,187,201,205,187,201,187,201,32 ,32 ,201,203,187,203,32 ,203,203,201,187,201,203,32 ,203,
							32 ,186,32 ,204,203,188,186,32 ,186,186,32 ,186,186,186,186,186,32 ,203,32 ,32 ,32 ,186,32 ,186,32 ,186,204,205,185,186,186,186,32 ,32 ,32 ,186,32 ,204,205,185,186,186,186,186,204,205,185,
							32 ,202,32 ,202,200,205,200,205,188,200,205,188,188,200,188,200,205,188,32 ,32 ,32 ,202,32 ,200,205,188,202,32 ,202,188,200,188,32 ,32 ,32 ,202,32 ,202,32 ,202,202,188,200,188,202,32 ,202 };
	int top = 23, left = 30;
	int num_lines = 3, num_chars = 47;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{

			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			putchar(name[i * num_chars + j]);
		}
	}
}

void draw::printLoadText()
{
	unsigned char logo[] = {
		32 ,220,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,220,219,219,219,219,219,219,220,32 ,32 ,32 ,32 ,32 ,220,219,219,219,219,219,219,219,219,32 ,219,219,219,219,219,219,219,219,220,32 ,32 ,
		219,219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,219,219,219,32 ,32 ,32 ,223,219,219,219,32 ,
		219,219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,
		219,219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,
		219,219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,223,219,219,219,219,219,219,219,219,219,219,219,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,
		219,219,219,32 ,32 ,32 ,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,
		219,219,219,219,32 ,32 ,32 ,32 ,220,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,219,219,32 ,219,219,219,32 ,32 ,32 ,220,219,219,219,32 ,
		219,219,219,219,219,220,220,219,219,32 ,32 ,223,219,219,219,219,219,219,223,32 ,32 ,32 ,32 ,219,219,219,32 ,32 ,32 ,32 ,219,223,32 ,32 ,219,219,219,219,219,219,219,219,223,32 ,32 ,
		223,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 ,32 , };
	int top = 0, left = 32;
	int num_lines = 9, num_chars = 45;
	for (int i = 0; i < num_lines; i++)
	{
		common::gotoXY(left, i + top);
		for (int j = 0; j < num_chars; j++)
		{
			if (j < num_chars / 2 - 1) common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			else common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			putchar(logo[i * num_chars + j]);
		}
	}
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	draw::printX(28, 5);
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	draw::printO(77, 0);
}

void draw::printLoadBoard(int color)
{
	int left = 11;
	int top = 9;
	int width = 83;
	int height = 18;
	common::setConsoleColor(BRIGHT_WHITE, color);
	common::gotoXY(left, top);
	putchar(201);
	for (int i = 1; i < width; i++)
	{
		putchar(205);
	}
	putchar(187);


	for (int i = 1; i < height; i++)
	{
		common::gotoXY(left, top + i);
		putchar(186);
		common::gotoXY(left + width, top + i);
		putchar(186);
	}
	common::gotoXY(left, top + height);
	putchar(200);
	for (int i = 1; i < width; i++)
	{
		putchar(205);
	}
	putchar(188);
	for (int i = top + 2; i < top + height; i += 2)
	{
		common::gotoXY(12, i);
		for (int j = 0; j < width - 1; j++)
		{
			if (j != 5 && j != 27 && j != 49)
				putchar(196);
			else putchar(197);
		}
	}
	for (int i = top + 1; i < top + height; i += 2)
	{
		common::gotoXY(17, i); putchar(179);
		common::gotoXY(39, i); putchar(179);
		common::gotoXY(61, i); putchar(179);
	}
}

void draw::loadingBar()
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(37, 13); cout << "LOADING...";
	printBoard(37, 14, 34, 2, BLACK);
	common::setColor(4);
	for (int i = 0; i < 30; i++) {
		common::gotoXY(39 + i, 15);
		putchar(178);
		putchar(219);
		Sleep(1);
	}
	Sleep(200);
}

void draw::Cat(int x, int y, int color, int color_1)
{
	// Vẽ viền
	common::setConsoleColor(color_1, BLACK);
	common::gotoXY(x + 9, y); putchar(220);
	common::gotoXY(x + 10, y); putchar(220);
	common::gotoXY(x + 1, y); putchar(220);
	common::gotoXY(x + 2, y); putchar(220);
	common::setConsoleColor(color, BLACK);
	common::gotoXY(x + 3, y + 1); putchar(219);
	common::gotoXY(x + 4, y + 2); putchar(219);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x, y + 1 + i); putchar(219);
		common::gotoXY(x - 1, y + 3 + i); putchar(219);
		common::gotoXY(x + 11, y + 1 + i); putchar(219);
		common::gotoXY(x + 12, y + 3 + i); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 5 + i, y + 3); putchar(223);
	}
	common::gotoXY(x + 7, y + 2); putchar(219);
	common::gotoXY(x + 8, y + 1); putchar(219);

	common::gotoXY(x - 1, y + 5); putchar(219);
	common::gotoXY(x, y + 6); putchar(219);
	for (int i = 0; i < 10; i++) {
		common::gotoXY(x + 1 + i, y + 7); putchar(223);
	}
	common::gotoXY(x + 12, y + 5); putchar(219);
	common::gotoXY(x + 11, y + 6); putchar(219);

	// Tô màu
	common::setColor(8);
	for (int i = 0; i < 12; i++) {
		common::gotoXY(x + i, y + 3); putchar(219);
		common::gotoXY(x + i, y + 4); putchar(219);
	}
	for (int i = 0; i < 12; i++) {
		common::gotoXY(x + i, y + 5); putchar(219);
	}
	for (int i = 0; i < 10; i++) {
		common::gotoXY(x + 1 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(GRAY, BLACK);
		common::gotoXY(x + 5 + i, y + 3); putchar(223);
	}
	common::setColor(8);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(x + 1 + 7 * i + j, y + 2); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 1 + 8 * i + j, y + 1); putchar(219);
		}
	}
	common::setColor(7);
	common::gotoXY(x + 2, y + 2); putchar(219);
	common::gotoXY(x + 9, y + 2); putchar(219);

	// Vẽ mắt và miệng, má

	// Vẽ má
	common::setColor(13);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 1 + j + i * 8, y + 5);
			putchar(219);
		}
	}

	// Vẽ mắt
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(x + 3 + i * 4, y + 4); putchar(220);
		common::setColor(0);
		common::gotoXY(x + 4 + i * 4, y + 4); putchar(219);
	}

	// Vẽ miệng
	common::setConsoleColor(GRAY, BLACK);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 5 + i, y + 6); putchar(223);
	}
}

void draw::printTitleChoose(int x, int y)
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	unsigned char title[] = { 219, 223, 223, 32 , 219, 32 , 219, 32 , 219, 223, 219, 32 , 219, 223, 219, 32 , 219, 223, 223, 32 , 219, 223, 223, 32 , 32 , 32 , 219, 32 , 219, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 223, 219, 32 , 32 , 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 223, 219, 32 , 223, 219, 223, 32 , 219, 223, 219, 32 , 219, 223, 219,
							  219, 220, 220, 32 , 219, 223, 219, 32 , 219, 220, 219, 32 , 219, 220, 219, 32 , 220, 220, 219, 32 , 219, 219, 220, 32 , 32 , 32 , 32 , 219, 32 , 32 , 219, 220, 219, 32 , 219, 220, 219, 32 , 219, 223, 220, 32 , 32 , 32 , 219, 223, 219, 32 , 223, 254, 223, 32 , 219, 223, 219, 32 , 32 , 219, 32 , 32 , 219, 223, 219, 32 , 219, 223, 220};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 67; j++) {
			common::gotoXY(x + j, y + i); putchar(title[j + i * 67]);
		}
	}
}

void draw::smallLostAmongUs(int x, int y, int color) 
{
	// Tô màu
	common::setColor(color);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + 2 + i, y); putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			common::gotoXY(x + 1 + j, y + 1 + i); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 1 + i, y + 4); putchar(219);
		common::gotoXY(x + 6 + i, y + 4); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 9, y + 2 + i); putchar(219);
	}

	// Vẽ viền
	common::setConsoleColor(color, BLACK);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x - 1 + i, y); putchar(220);
		common::gotoXY(x - 1 + i, y + 2); putchar(223);
	}
	common::gotoXY(x - 2, y + 1); putchar(219);
	common::gotoXY(x + 4, y + 1); putchar(219);
	common::gotoXY(x + 4, y + 3); putchar(220);

	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x, y + 2 + i);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 1 + i, y + 5); putchar(223);
	}
	common::gotoXY(x + 3, y + 4); putchar(219);
	common::gotoXY(x + 5, y + 4); putchar(219);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 6 + i, y + 5); putchar(223);
	}
	for (int i = 0; i < 4; i++) {
		common::gotoXY(x + 8, y + 1 + i);
		putchar(219);
	}
	common::gotoXY(x + 9, y + 1); putchar(220);
	common::gotoXY(x + 9, y + 4); putchar(223);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 10, y + 2 + i); putchar(219);
	}
	common::gotoXY(x + 7, y); putchar(219);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + 2 + i, y - 1); putchar(220);
	}
	common::gotoXY(x + 1, y); putchar(219);

	// Tô màu kính
	common::setColor(7);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x - 1 + i, y + 1); putchar(219);
	}
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(x - 1, y + 2); putchar(223);
	common::gotoXY(x - 1, y); putchar(220);
	common::gotoXY(x, y); putchar(220);

	// Vẽ nước mắt
	common::setColor(9);
	common::gotoXY(x - 2, y + 2); putchar(219);
	common::gotoXY(x + 3, y + 2); putchar(219);
}

void draw::Aura(int x, int y)
{
	common::setColor(LIGHT_YELLOW);
	for (int i = 0; i < 10; i++) {
		common::gotoXY(x + 13 + i, y); putchar(219);
		common::gotoXY(x + 13 + i, y + 18); putchar(219);
	}
	for (int i = 0; i < 18; i++) {
		common::gotoXY(x + 9 + i, y + 1); putchar(219);
		common::gotoXY(x + 9 + i, y + 17); putchar(219);
	}
	for (int i = 0; i < 22; i++) {
		common::gotoXY(x + 7 + i, y + 2); putchar(219);
		common::gotoXY(x + 7 + i, y + 16); putchar(219);
	}
	for (int i = 0; i < 26; i++) {
		common::gotoXY(x + 5 + i, y + 3); putchar(219);
		common::gotoXY(x + 5 + i, y + 15); putchar(219);
	}
	for (int i = 0; i < 28; i++) {
		common::gotoXY(x + 4 + i, y + 4); putchar(219);
		common::gotoXY(x + 4 + i, y + 14); putchar(219);
	}
	for (int i = 0; i < 30; i++) {
		common::gotoXY(x + 3 + i, y + 5); putchar(219);
		common::gotoXY(x + 3 + i, y + 13); putchar(219);
	}
	for (int i = 0; i < 32; i++) {
		common::gotoXY(x + 2 + i, y + 6); putchar(219);
		common::gotoXY(x + 2 + i, y + 12); putchar(219);
	}
	for (int i = 0; i < 34; i++) {
		common::gotoXY(x + 1 + i, y + 6); putchar(219);
		common::gotoXY(x + 1 + i, y + 12); putchar(219);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 36; j++) {
			common::gotoXY(x + j, y + 7 + i); putchar(219);
		}
	}
}

void draw::biggerAura(int x, int y, int color_1)
{
	unsigned int color[] = { LIGHT_RED, LIGHT_YELLOW, LIGHT_GREEN, LIGHT_BLUE, LIGHT_RED, color_1 };
	for (int count = 0; count < 6; count++) {
		common::setColor(color[count]);
		for (int i = 0; i < 16; i++) {
			common::gotoXY(x + 17 + i, y); putchar(219);
			common::gotoXY(x + 17 + i, y + 22); putchar(219);
		}
		for (int i = 0; i < 24; i++) {
			common::gotoXY(x + 13 + i, y + 1); putchar(219);
			common::gotoXY(x + 13 + i, y + 21); putchar(219);
		}
		for (int i = 0; i < 30; i++) {
			common::gotoXY(x + 10 + i, y + 2); putchar(219);
			common::gotoXY(x + 10 + i, y + 20); putchar(219);
		}
		for (int i = 0; i < 34; i++) {
			common::gotoXY(x + 8 + i, y + 3); putchar(219);
			common::gotoXY(x + 8 + i, y + 19); putchar(219);
		}
		for (int i = 0; i < 38; i++) {
			common::gotoXY(x + 6 + i, y + 4); putchar(219);
			common::gotoXY(x + 6 + i, y + 18); putchar(219);
		}
		for (int i = 0; i < 40; i++) {
			common::gotoXY(x + 5 + i, y + 5); putchar(219);
			common::gotoXY(x + 5 + i, y + 17); putchar(219);
		}
		for (int i = 0; i < 42; i++) {
			common::gotoXY(x + 4 + i, y + 6); putchar(219);
			common::gotoXY(x + 4 + i, y + 16); putchar(219);
		}
		for (int i = 0; i < 44; i++) {
			common::gotoXY(x + 3 + i, y + 7); putchar(219);
			common::gotoXY(x + 3 + i, y + 15); putchar(219);
		}
		for (int i = 0; i < 46; i++) {
			common::gotoXY(x + 2 + i, y + 8); putchar(219);
			common::gotoXY(x + 2 + i, y + 14); putchar(219);
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 48; j++) {
				common::gotoXY(x + 1 + j, y + 9 + i); putchar(219);
			}
		}
		Sleep(50);
	}
	
}

void draw::titleEffect(int x, int y, int amongus_color, int smallamong_color, int box_color, int status)
{
	// Hiẻn thị ảnh người chơi
	draw::biggerAura(49, 4, box_color);
	draw::Aura(56, 9);
	switch (amongus_color)
	{
	case LIGHT_RED:  avatar::leftAmongUs(65, 15, LIGHT_RED, RED, LIGHT_YELLOW, LIGHT_YELLOW); break;
	case LIGHT_BLUE:  avatar::leftAmongUs(65, 15, LIGHT_BLUE, BLUE, LIGHT_YELLOW, LIGHT_YELLOW); break;
	case LIGHT_YELLOW:  avatar::leftAmongUs(65, 15, LIGHT_YELLOW, LIGHT_YELLOW, LIGHT_YELLOW, LIGHT_YELLOW); break;
	case LIGHT_PURPLE:  avatar::leftAmongUs(65, 15, LIGHT_PURPLE, PURPLE, LIGHT_YELLOW, LIGHT_YELLOW); break;
	case BRIGHT_WHITE:  avatar::leftAmongUs(65, 15, BRIGHT_WHITE, WHITE, LIGHT_YELLOW, LIGHT_YELLOW); break;
	case LIGHT_GREEN:  avatar::leftAmongUs(65, 15, LIGHT_GREEN, GREEN, LIGHT_YELLOW, LIGHT_YELLOW); break;
	}
	if (status == 1) {
		draw::smallLostAmongUs(94, 23, smallamong_color);
		draw::winnerSignature(62, 11, LIGHT_YELLOW); // status = 1: thắng, status = 0: thua
	}
	else draw::loserSignature(66, 11, LIGHT_YELLOW);

	// Bảng thông tin
	// in thời gian còn lại
	printBoard(x + 10, y + 11, 35, 3, LIGHT_BLUE);
	unsigned char timeleft[] = { 223, 219, 223, 32 , 219, 32 , 219, 220, 32 , 220, 219, 32 , 219, 223, 223, 32 , 32 , 32 , 219, 32 , 32 , 32 , 219, 223, 223, 32 , 219, 223, 223, 32 , 223, 219, 223,
								 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 223, 32 , 219, 32 , 219, 219, 220, 32 , 32 , 32 , 219, 220, 220, 32 , 219, 219, 220, 32 , 219, 223, 223, 32 , 32 , 219, 32 , };
	draw::printColoredRectangle(x + 8, y + 10, 36, 4, LIGHT_BLUE);
	common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	int num_chars_2 = 33;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars_2; j++) {
			common::gotoXY(x + 10 + j, y + 11 + i); putchar(timeleft[i * num_chars_2 + j]);
		}
	}
	numberTransfer(x + 11, y + 15, 25000000);

	// in tỉ lệ thắng
	printBoard(x, y + 1, 53, 3, LIGHT_BLUE);
	unsigned char winningMove[] = { 219, 32 , 219, 32 , 219, 32 , 219, 32 , 219, 220, 32 , 219, 32 , 219, 220, 32 , 219, 32 , 219, 32 , 219, 220, 32 , 219, 32 , 219, 223, 223, 32 , 32 , 32 , 219, 223, 219, 32 , 219, 223, 219, 32 , 223, 219, 223, 32 , 219, 32 , 219, 223, 219, 
									223, 254, 223, 254, 223, 32 , 219, 32 , 219, 32 , 223, 219, 32 , 219, 32 , 223, 219, 32 , 219, 32 , 219, 32 , 223, 219, 32 , 219, 220, 219, 32 , 32 , 32 , 219, 223, 220, 32 , 219, 223, 219, 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 220, 219, };
	draw::printColoredRectangle(x - 1, y, 53, 4, LIGHT_BLUE);
	common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	int num_chars = 48;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(x + j + 1, y + 1 + i); putchar(winningMove[i * num_chars + j]);
		}
	}
	numberTransfer(x + 3, y + 5, 250);
	
	// in số lượt đi
	printBoard(x + 27, y + 21, 25, 3, LIGHT_BLUE);
	unsigned char moves[] = { 219, 220, 32 , 220, 219, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 223, 223, 32 , 219, 223,
							  219, 32 , 223, 32 , 219, 32 , 219, 220, 219, 32 , 223, 254, 223, 32 , 219, 219, 220, 32 , 220, 219, };
	draw::printColoredRectangle(x + 26, y + 20, 25, 4, LIGHT_BLUE);
	common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	int num_chars_1 = 20;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars_1; j++) {
			common::gotoXY(x + j + 28, y + i + 21); putchar(moves[i * num_chars_1 + j]);
		}
	}
	numberTransfer(x + 30, y + 25, 25);

}

void draw::winnerSignature(int x, int y, int color)
{
	common::setConsoleColor(color, BLACK);
	unsigned char winner[] = { 219, 32 , 219, 32 , 219, 32 , 219, 32 , 219, 220, 32 , 219, 32 , 219, 220, 32 , 219, 32 , 219, 223, 223, 32 , 219, 223, 219,
							   223, 254, 223, 254, 223, 32 , 219, 32 , 219, 32 , 223, 219, 32 , 219, 32 , 223, 219, 32 , 219, 219, 220, 32 , 219, 223, 220};
	int num_chars = 25;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(x + j, y + i);
			putchar(winner[i * 25 + j]);
		}
	}
}

void draw::musicIconOff(int x, int y)
{
	draw::printColoredRectangle(x, y, 7, 3, GRAY);
	common::setConsoleColor(BRIGHT_WHITE, WHITE);
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x - 1 + i, y - 1); putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x - 1 + i, y + 2); putchar(223);
	}
	common::setConsoleColor(GRAY, WHITE);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + 1 + i, y + 2); putchar(223);
	}
	draw::printColoredRectangle(x - 1, y, 7, 2, WHITE);
	common::setConsoleColor(WHITE, BLACK);
	common::gotoXY(x + 2, y); putchar(219);
	common::gotoXY(x + 3, y); putchar(223);
	common::gotoXY(x + 4, y); putchar(254);
	common::gotoXY(x + 2, y + 1); putchar(219);
	common::gotoXY(x + 1, y + 1); putchar(219);
	common::gotoXY(x, y + 1); putchar(254);
}

void draw::musicIconOn(int x, int y)
{
	draw::printColoredRectangle(x, y, 7, 3, RED);
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x - 1 + i, y - 1); putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x - 1 + i, y + 2); putchar(223);
	}
	common::setConsoleColor(RED, LIGHT_RED);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + 1 + i, y + 2); putchar(223);
	}
	draw::printColoredRectangle(x - 1, y, 7, 2, LIGHT_RED);
	common::setConsoleColor(LIGHT_RED, BLACK);
	common::gotoXY(x + 2, y); putchar(219);
	common::gotoXY(x + 3, y); putchar(223);
	common::gotoXY(x + 4, y); putchar(254);
	common::gotoXY(x + 2, y + 1); putchar(219);
	common::gotoXY(x + 1, y + 1); putchar(219);
	common::gotoXY(x, y + 1); putchar(254);
}

void draw::printCaroTutorial(int x, int y, int color, int color_1)
{
	common::setConsoleColor(color_1, color);
	unsigned char caro[] = { 220, 220, 220, 220, 32 , 220, 220, 220, 220, 32 , 220, 220, 220, 220, 32 , 220, 220, 220, 220,
							 219, 32 , 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 219,
							 219, 32 , 32 , 32 , 32 , 219, 223, 223, 219, 32 , 219, 254, 254, 32 , 32 , 219, 32 , 32 , 219,
							 219, 220, 220, 220, 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 220, 220, 219 };
	int num_chars_caro = 19;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < num_chars_caro; j++) {
			common::gotoXY(x + j, y + i);
			putchar(caro[i * num_chars_caro + j]);
		}
	}

	unsigned char tutorial[] = { 220, 220, 220, 220, 220, 32 , 220, 32 , 32 , 220, 32 , 220, 220, 220, 220, 220, 32 , 220, 220, 220, 220, 32 , 220, 220, 220, 220, 32 , 220, 32 , 220, 220, 220, 220, 32 , 220, 32 , 32 , 32 ,
								 32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 32 ,
								 32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 254, 254, 32 , 32 , 219, 32 , 219, 223, 223, 219, 32 , 219, 32 , 32 , 32 ,
								 32 , 32 , 219, 32 , 32 , 32 , 219, 220, 220, 219, 32 , 32 , 32 , 219, 32 , 32 , 32 , 219, 220, 220, 219, 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 220, 220, 220 };
	int num_chars_tutorial = 38;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < num_chars_tutorial; j++) {
			common::gotoXY(x - 8 + j, y + 5 + i);
			putchar(tutorial[i * num_chars_tutorial + j]);
		}
	}
}

void draw::printVS(int x, int y)
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	unsigned char VS[] = { 219, 32 , 219,
						   223, 254, 223,
						   32 , 219, 223,
						   254, 220, 219,};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(x + j, y + i); putchar(VS[i * 3 + j]);
		}
	}
}

void draw::boxChatRight(int x, int y, int height, int width)
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < width + 1; i++) {
		common::gotoXY(x + i, y); putchar(220);
		common::gotoXY(x + i, y + height + 3); putchar(223);
	}
	for (int i = 0; i < height; i++) {
		common::gotoXY(x - 2, y + 2 + i); putchar(219);
		common::gotoXY(x + width + 2, y + 2 + i); putchar(219);
	}
	common::gotoXY(x - 1, y + 1); putchar(254);
	common::gotoXY(x - 1, y + 2 + height); putchar(254);
	common::gotoXY(x + width + 1, y + 1); putchar(254);
	common::gotoXY(x + width + 1, y + 2 + height); putchar(254);
	common::gotoXY(x + width - width / 2, y + 4 + height); putchar(219);
	common::gotoXY(x + width - width / 2 + 1, y + 4 + height); putchar(219);
	common::gotoXY(x + width - width / 2 + 2, y + 5 + height); putchar(254);
}

void draw::boxChatLeft(int x, int y, int height, int width)
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < width + 1; i++) {
		common::gotoXY(x + i, y); putchar(220);
		common::gotoXY(x + i, y + height + 3); putchar(223);
	}
	for (int i = 0; i < height; i++) {
		common::gotoXY(x - 2, y + 2 + i); putchar(219);
		common::gotoXY(x + width + 2, y + 2 + i); putchar(219);
	}
	common::gotoXY(x - 1, y + 1); putchar(254);
	common::gotoXY(x - 1, y + 2 + height); putchar(254);
	common::gotoXY(x + width + 1, y + 1); putchar(254);
	common::gotoXY(x + width + 1, y + 2 + height); putchar(254);
	common::gotoXY(x + width - width / 2, y + 4 + height); putchar(219);
	common::gotoXY(x + width - width / 2 - 1, y + 4 + height); putchar(219);
	common::gotoXY(x + width - width / 2 - 2, y + 5 + height); putchar(254);
}

void draw::printRule(int x, int y)
{
	unsigned char rule[] = { 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 32 , 32 , 32 , 219, 223, 223,
							 219, 223, 220, 32 , 219, 220, 219, 32 , 219, 220, 220, 32 , 219, 219, 220, };
	int num_chars = 15;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(x + j, y + i); putchar(rule[i * num_chars + j]);
		}
	}
}

void draw::PacmanCloseMouth(int x, int y)
{
	common::setColor(YELLOW);
	for (int i = 0; i < 10; i++) {
		common::gotoXY(x + 4 + i, y); putchar(219);
		common::gotoXY(x + 4 + i, y + 7); putchar(219);
	}
	for (int i = 0; i < 14; i++) {
		common::gotoXY(x + 2 + i, y + 1); putchar(219);
		common::gotoXY(x + 2 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 16; i++) {
		common::gotoXY(x + 1 + i, y + 2); putchar(219);
		common::gotoXY(x + 1 + i, y + 5); putchar(219);
	}
	for (int i = 0; i < 18; i++) {
		common::gotoXY(x + i, y + 3); putchar(219);
		common::gotoXY(x + i, y + 4); putchar(219);
	}
	common::setConsoleColor(YELLOW, BLACK);
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x + 11 + i, y + 4); putchar(223);
	}
	common::setColor(0);
	common::gotoXY(x + 9, y + 2); putchar(219);
}

void draw::PacmanOpenMouth(int x, int y)
{
	PacmanCloseMouth(x, y);
	common::setConsoleColor(YELLOW, BLACK);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 11 + i, y + 3); putchar(220);
		common::gotoXY(x + 11 + i, y + 4); putchar(223);
	}
	for (int i = 0; i < 5; i++)
	{
		common::gotoXY(x + 13 + i, y + 3); putchar(219);
		common::gotoXY(x + 13 + i, y + 4); putchar(219);
	}
	common::gotoXY(x + 14, y + 2); putchar(220);
	common::gotoXY(x + 15, y + 2); putchar(219);
	common::gotoXY(x + 16, y + 2); putchar(219);
	common::gotoXY(x + 16, y + 5); putchar(219);
	common::gotoXY(x + 15, y + 5); putchar(219);
	common::gotoXY(x + 14, y + 5); putchar(223);
}

void draw::PacmanOpenHalfMouth(int x, int y)
{
	PacmanCloseMouth(x, y);
	common::setConsoleColor(YELLOW, BLACK);
	for (int i = 0; i < 4; i++) {
		common::gotoXY(x + 11 + i, y + 3); putchar(220);
		common::gotoXY(x + 11 + i, y + 4); putchar(223);
	}
	for (int i = 0; i < 4; i++) {
		common::gotoXY(x + 15 + i, y + 3); putchar(219);
		common::gotoXY(x + 15 + i, y + 4); putchar(219);
	}
}

void draw::Coin(int x, int y)
{
	// Vẽ viền coin
	common::setConsoleColor(BLACK, YELLOW);
	common::gotoXY(x, y); putchar(219);
	common::gotoXY(x + 3, y); putchar(219);
	for (int i = 0; i < 4; i++) {
		common::gotoXY(x + i, y - 1); putchar(220);
		common::gotoXY(x + i, y + 1); putchar(223);
	}

	// Tô màu
	common::setColor(LIGHT_YELLOW);
	common::gotoXY(x + 1, y); putchar(219);
	common::gotoXY(x + 2, y); putchar(219);
}

void draw::thankPlaying(int x, int y)
{
	system("color 07");

	// Hiển thị Pacman ăn coin
	common::setConsoleColor(BLACK, LIGHT_PURPLE);
	for (int i = 0; i < 105; i++) {
		common::gotoXY(i, 9); putchar(205);
		common::gotoXY(i, 10); putchar(205);
		common::gotoXY(i, 21); putchar(205);
		common::gotoXY(i, 22); putchar(205);
	}
	Coin(30, 16);
	Coin(47, 16);
	Coin(64, 16);

	for (int i = 0; i < 5; i++) {
		PacmanOpenMouth(i * 17, 12);
		Sleep(100);
		printColoredRectangle(i * 17, 12, 18 + i, 8, BLACK);
		PacmanOpenHalfMouth(i * 17, 12);
		Sleep(100); 
		printColoredRectangle(i * 17, 12, 18 + i, 8, BLACK);
		PacmanCloseMouth(i * 17, 12);
		Sleep(100);
		printColoredRectangle(i * 17, 12, 18 + i, 8, BLACK);
	}
	PacmanCloseMouth(84, 12);

	Sleep(1000);
	common::clearConsole();

	// Hiển thị màn hình Thanks for playing
	system("color 07");
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	unsigned char thank[] = { 223, 223, 219, 223, 223, 32 , 219, 32 , 32 , 219, 32 , 219, 223, 223, 219, 32 , 219, 220, 32 , 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 223, 223, 223, 32 , 32 , 32 , 219, 223, 223, 223, 32 , 219, 223, 223, 219, 32 , 219, 223, 223, 219, 32 , 32 , 32 , 
							  32 , 32 , 219, 32 , 32 , 32 , 219, 254, 254, 219, 32 , 219, 223, 223, 219, 32 , 219, 32 , 219, 32 , 219, 32 , 219, 254, 219, 32 , 32 , 223, 254, 254, 220, 32 , 32 , 32 , 219, 223, 223, 223, 32 , 219, 32 , 32 , 219, 32 , 219, 254, 254, 32 , 32 , 32 , 32 , 
							  32 , 32 , 219, 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 223, 219, 32 , 219, 32 , 32 , 219, 32 , 220, 220, 220, 219, 32 , 32 , 32 , 219, 32 , 32 , 32 , 32 , 219, 220, 220, 219, 32 , 219, 32 , 32 , 219, 32 , 32 , 32 , };
	unsigned char playing[] = { 219, 223, 223, 219, 32 , 219, 32 , 32 , 32 , 32 , 219, 223, 223, 219, 32 , 219, 32 , 219, 32 , 219, 32 , 219, 220, 32 , 32 , 219, 32 , 219, 223, 223, 223,
								219, 223, 223, 223, 32 , 219, 32 , 32 , 32 , 32 , 219, 223, 223, 219, 32 , 254, 220, 254, 32 , 219, 32 , 219, 32 , 219, 32 , 219, 32 , 219, 32 , 220, 220,
								219, 32 , 32 , 32 , 32 , 219, 220, 220, 220, 32 , 219, 32 , 32 , 219, 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 32 , 223, 219, 32 , 219, 220, 220, 219, };
	int num_chars = 51, num_chars_1 = 31;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(x + j + 20, y + i + 2); putchar(thank[i * num_chars + j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < num_chars_1; j++) {
			common::gotoXY(x + j + 29, y + i + 6); putchar(playing[i * num_chars_1 + j]);
		}
	}
	cout << "\n\n\n\n\n\n\n";
	Sleep(5000);
}

void draw::drawBoard()
{
	// Hiển thị bàn cờ
	int _size = 14, _left = 3, _top = 1;
	//Ve duong duoi
	for (int i = 1; i < _size * 4; i++)
	{
		common::gotoXY(_size * 4 + _left - i + 1, _size * 2 + _top);
		if (i % 4 == 0)
			putchar(202);
		else
			putchar(205);
	}
	common::gotoXY(_left + 1, _size * 2 + _top);
	putchar(200);

	//Ve duong ben trai
	for (int i = 1; i < _size * 2; i++)
	{
		common::gotoXY(_left + 1, _size * 2 + _top - i);
		if (i % 2 != 0)
			putchar(186);
		else
			putchar(204);
	}
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	//Ve duong tren
	common::gotoXY(_left + 1, _top);
	putchar(201);
	for (int i = 1; i < _size * 4; i++)
	{
		if (i % 4 == 0)
			putchar(203);
		else
			putchar(205);
	}
	putchar(187);


	//Ve duong ben phai
	for (int i = 1; i < _size * 2; i++)
	{
		common::gotoXY(_size * 4 + _left + 1, i + _top);
		if (i % 2 != 0)
			putchar(186);
		else
			putchar(185);
	}
	common::gotoXY(_size * 4 + _left + 1, _size * 2 + _top);
	putchar(188);


	//Ve cac duong doc
	for (int j = 1; j < _size * 4; j++)
	{
		for (int i = 1; i < _size * 2; i++)
		{
			if (j % 4 != 0)
			{
				if (i % 2 == 0)
				{
					common::gotoXY(j + _left + 1, i + _top);
					putchar(196);
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					common::gotoXY(j + _left + 1, i + _top);
					putchar(197);
				}
				else
				{
					common::gotoXY(j + _left + 1, i + _top);
					putchar(179);
				}
			}
		}
	}
}

void draw::exitBackground()
{
	system("color 07");

	// nền đất
	common::setColor(GRAY);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 105; j++) {
			common::gotoXY(j, i + 27); putchar(219);
		}
	}
	common::setConsoleColor(GRAY, WHITE);
	for (int i = 0; i < 105; i+=5) {
		if (i % 10 == 0) {
			for (int j = 0; j < 3; j++) {
				common::gotoXY(i + j, 29); putchar(223);
				if (j == 1) {
					common::gotoXY(i + j, 28); putchar(220);
				}
			}
		}
		else {
			for (int j = 0; j < 3; j++) {
				common::gotoXY(i + j, 30); putchar(223);
				if (j == 1) {
					common::gotoXY(i + j, 29); putchar(220);
				}
			}
		}
	}

	// nền cỏ
	for (int i = 0; i < 105; i++) {
		common::setColor(LIGHT_GREEN);
		common::gotoXY(i, 27); putchar(219);
		if (i % 10 == 0) {
			common::setConsoleColor(LIGHT_GREEN, GREEN);
			common::gotoXY(i, 27); putchar(223);
			common::gotoXY(i + 1, 27); putchar(223);
			common::gotoXY(i + 2, 27); putchar(223);
			i += 2;
		}
	}
	common::setConsoleColor(GRAY, LIGHT_GREEN);
	for (int i = 3; i < 100; i += 10) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(i + j, 28); putchar(223);
			if (j == 1) {
				common::gotoXY(i + j, 28); putchar(219);
			}
		}
	}
	common::setConsoleColor(BLACK, GREEN);
	for (int i = 0; i < 105; i++) {
		common::gotoXY(i, 26); putchar(220);
	}

	// cột lửa
	fireStatus(6, 11);
	fireStatus(83, 11);
	
	// lửa
	Fire(11, 2);
	Fire(88, 2);

	// chữ Exit
	exitTitle(30, 0);
	common::setConsoleColor(BLACK, GRAY);
	common::gotoXY(28, 1); putchar(254);
	common::gotoXY(29, 1); putchar(219);
	common::gotoXY(30, 1); putchar(254);
	common::gotoXY(29, 0); putchar(220);
	common::gotoXY(29, 2); putchar(223);

	common::gotoXY(76, 6); putchar(254);
	common::gotoXY(77, 6); putchar(219);
	common::gotoXY(78, 6); putchar(254);
	common::gotoXY(77, 5); putchar(220);
	common::gotoXY(77, 7); putchar(223);

	// in khung cho exit
	common::setColor(15);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 44; j++) {
			common::gotoXY(32 + j, 8 + i);
			putchar(219);
		}
	}

	// vẽ đom đóm
	common::setConsoleColor(BLACK, LIGHT_YELLOW);
	common::gotoXY(10, 5); putchar(254);
	common::gotoXY(21, 5); putchar(254);
	common::gotoXY(87, 4); putchar(254);
	common::gotoXY(25, 17); putchar(254);
	common::gotoXY(97, 5); putchar(254);
	common::gotoXY(80, 15); putchar(254);
	common::gotoXY(2, 13); putchar(254);
	common::gotoXY(100, 20); putchar(254);

	// Lời dẫn goodbye
	common::setColor(LIGHT_YELLOW);
	common::gotoXY(33, 20); cout << "There is no greater thing you can do with";
	common::gotoXY(30, 21); cout << "your life and your work than follow your passions";
	common::gotoXY(33, 22); cout << "- in a way that serves the world and you.";
	common::gotoXY(55, 24); cout << "- Richard Branson -";
}

void draw::Fire(int x, int y) {
	common::setColor(BRIGHT_WHITE);
	common::gotoXY(x + 3, y + 7); putchar(219);
	common::gotoXY(x + 4, y + 7); putchar(219);

	common::setConsoleColor(BRIGHT_WHITE, LIGHT_YELLOW); //
	common::gotoXY(x + 3, y + 6); putchar(219);
	common::gotoXY(x + 4, y + 6); putchar(223);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 3 + i, y + 5); putchar(219);
	}

	common::setConsoleColor(RED, LIGHT_RED);
	common::gotoXY(x + 3, y + 4); putchar(220);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(x + 4 + j, y + 3 + i); putchar(219);
		}
	}
	common::gotoXY(x + 4, y + 2); putchar(219);
	common::gotoXY(x + 3, y + 3); putchar(223);
	common::gotoXY(x + 2, y + 5); putchar(219);
	common::gotoXY(x + 1, y + 6); putchar(219);
	common::gotoXY(x + 3, y + 3); putchar(220);
	common::gotoXY(x + 3, y + 4); putchar(219);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 6, y + 5 + i); putchar(219);
	}

	common::setColor(RED);
	common::gotoXY(x + 3, y + 2); putchar(219);
	common::gotoXY(x + 7, y + 3); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 7, y + 4 + i); putchar(219);
	}
	common::gotoXY(x + 1, y + 7); putchar(219);

	common::setConsoleColor(BLACK, RED);
	common::gotoXY(x + 4, y + 1); putchar(220);
	common::gotoXY(x + 2, y); putchar(220);
	common::gotoXY(x + 7, y + 1); putchar(220);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 5 + i, y + 2); putchar(220);
	}
	common::gotoXY(x + 6, y + 3); putchar(219);
	common::gotoXY(x + 6, y + 7); putchar(223);
	common::gotoXY(x, y + 7); putchar(223);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x, y + 5 + i); putchar(219);
	}
	common::gotoXY(x + 1, y + 5); putchar(219);
	common::gotoXY(x + 1, y + 4); putchar(220);
	common::gotoXY(x + 2, y + 4); putchar(219);
	common::gotoXY(x + 2, y + 3); putchar(220);

	common::setConsoleColor(RED, LIGHT_YELLOW);
	common::gotoXY(x + 5, y + 7); putchar(223);
	common::gotoXY(x + 2, y + 7); putchar(223);

	common::setConsoleColor(LIGHT_RED, LIGHT_YELLOW);
	common::gotoXY(x + 2, y + 6); putchar(220);

	common::setConsoleColor(LIGHT_RED, LIGHT_YELLOW); //1
	common::gotoXY(x + 5, y + 5); putchar(220);
	common::gotoXY(x + 5, y + 6); putchar(219);
}

void draw::exitTitle(int x, int y)
{
	unsigned char exit[] = { 32 , 32 , 32 , 220, 219, 219, 219, 219, 219, 219, 219, 219, 32 , 223, 219, 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 223, 32 , 32 , 32 , 220, 219, 32 , 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 ,
							 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 219, 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 223, 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 223, 219, 219, 219, 219, 219, 219, 219, 219, 219, 220, 
							 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 219, 223, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 219, 32 , 32 , 32 , 219, 219, 219, 223, 32 , 32 , 32 , 32 , 219, 219, 219, 219, 32 , 32 , 32 , 32 , 223, 219, 219, 219, 223, 223, 219, 219, 
							 32 , 220, 219, 219, 219, 220, 220, 220, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 223, 219, 219, 219, 220, 219, 219, 219, 223, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 223,
							 223, 223, 219, 219, 219, 223, 223, 223, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 220, 219, 219, 219, 223, 219, 219, 219, 220, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 
							 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 219, 220, 32 , 32 , 32 , 32 , 32 , 220, 219, 219, 219, 32 , 32 , 32 , 219, 219, 219, 219, 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 
						     32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 220, 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 220, 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 32 , 32 , 32 , 32 ,
							 32 , 32 , 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 32 , 32 , 220, 219, 219, 219, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 219, 219, 219, 220, 32 , 32 , 219, 223, 32 , 32 , 32 , 32 , 32 , 32 , 220, 219, 219, 219, 219, 223, 32 , 32 , };
	int num_chars = 47;
	common::setConsoleColor(BLACK, GRAY);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(x + j, y + i);
			putchar(exit[i * num_chars + j]);
		}
	}
	common::setColor(WHITE);
}

void draw::fireStatus(int x, int y)
{
	common::setColor(GRAY);
	for (int i = 0; i < 13; i++) { // 13
		for (int j = 0; j < 8; j++) {
			if (i != 12) {
				common::gotoXY(x + 5 + j, y + 1 + i); putchar(219);
			}
			else {
				common::setConsoleColor(GRAY, WHITE);
				common::gotoXY(x + 5 + j, y + 13); putchar(220);
			}
		}
	}
	common::setConsoleColor(BLACK, WHITE);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + i, y + 13); putchar(220);
		common::gotoXY(x + 13 + i, y + 13); putchar(220);
	}
	common::setColor(GRAY);
	for (int i = 0; i < 16; i++) {
		common::gotoXY(x + 1 + i, y + 14); putchar(219);
	}
	common::setConsoleColor(GREEN, WHITE);
	for (int i = 0; i < 18; i++) {
		common::gotoXY(x + i, y + 15); putchar(223);
	}
	common::setColor(WHITE);
	common::gotoXY(x, y + 14); putchar(219);
	common::gotoXY(x + 17, y + 14); putchar(219);

	common::setConsoleColor(GRAY, WHITE);
	for (int i = 0; i < 18; i++) {
		common::gotoXY(x + i, y); putchar(220);
	}
	common::gotoXY(x, y); putchar(219);
	common::gotoXY(x + 17, y); putchar(219);
	for (int i = 0; i < 18; i++) {
		common::gotoXY(x + i, y - 1); putchar(223);
	}
	common::gotoXY(x, y - 1); putchar(219);
	common::gotoXY(x + 17, y - 1); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 7, i + y + 3); putchar(219);
		common::gotoXY(x + 10, i + y + 8); putchar(219);
	}

	common::setConsoleColor(GREEN, WHITE);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 5 + j * 9 - 1, y + 1 + i); putchar(219);
		}
	}
}

void draw::numberTransfer(int x, int y, int number)
{
	int k = number;
	int count = 0;
	while (k > 0) { count++; k /= 10; }
	if (number >= 0 && number <= 9) {
		unsigned char zero[] = { 219, 223, 223, 219, 219, 32 , 32 , 219, 219, 220, 220, 219, };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(zero[i * 4 + j]);
			}
		}
		singleNumberTransfer(x + 5, y, number);
	}
	else {
		while (count > 0) {
			// chữ số đầu tiên
			int divide = pow(10, count - 1);
			int firstSingleNum = number / divide;
			singleNumberTransfer(x, y, firstSingleNum);
			x += 5;
			number %= divide;
			count--;
		}
	}
}

void draw::singleNumberTransfer(int x, int y, int number)
{
	if (number < 0 || number > 9) return;
	if (number == 0) {
		unsigned char num[] = {  219, 223, 223, 219,
								 219, 32 , 32 , 219,
								 219, 220, 220, 219, };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 1) {
		unsigned char num[] = { 32 , 32 , 219, 32 , 
								32 , 223, 219, 32 ,
								32 , 220, 219, 220,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 2) {
		unsigned char num[] = { 223, 223, 223, 219,
								219, 223, 223, 223,
								219, 220, 220, 220,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 3) {
		unsigned char num[] = { 223, 223, 223, 219,
								223, 223, 223, 219,
								220, 220, 220, 219, };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 4) {
		unsigned char num[] = { 219, 32 , 32 , 219,
								219, 220, 220, 219,
								32 , 32 , 32 , 219,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 5) {
		unsigned char num[] = { 219, 223, 223, 223,
						        223, 223, 223, 219,
								220, 220, 220, 219,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 6) {
		unsigned char num[] = { 219, 223, 223, 223,
								219, 223, 223, 219,
								219, 220, 220, 219,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 7) {
		unsigned char num[] = { 219, 223, 223, 219,
								32 , 32 , 32 , 219,
								32 , 32 , 32 , 219,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else if (number == 8) {
		unsigned char num[] = { 219, 223, 223, 219,
							    219, 223, 223, 219,
								219, 220, 220, 219, };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}
	}
	else {
		unsigned char num[] = { 219, 223, 223, 219,
								223, 223, 223, 219,
						        220, 220, 220, 219,};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				common::gotoXY(x + j, y + i); putchar(num[i * 4 + j]);
			}
		}	
	}
}

void draw::loserSignature(int x, int y, int color)
{
	common::setConsoleColor(color, BLACK);
	unsigned char loser[] = { 219, 32 , 32 , 32 , 219, 223, 219, 32 , 219, 223, 32 , 219, 223, 223, 32 , 219, 223, 219, 
							  219, 220, 220, 32 , 219, 220, 219, 32 , 220, 219, 32 , 219, 219, 220, 32 , 219, 223, 220, };
	int num_chars = 18;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(x + j, y + i); putchar(loser[i * num_chars + j]);
		}
	}
}
void draw::setTimer(int hour, int minute, int second)
{
	// tiêu đề "SET YOUR TIMER"
	unsigned char time[] = { 219, 223, 32 , 219, 223, 223, 32 , 223, 219, 223, 32 , 32 , 32 , 219, 32 , 219, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 223, 219, 32 , 32 , 32 , 223, 219, 223, 32 , 219, 32 , 219, 220, 32 , 220, 219, 32 , 219, 223, 223, 32 , 219, 223, 219,
							 220, 219, 32 , 219, 219, 220, 32 , 32 , 219, 32 , 32 , 32 , 32 , 32 , 219, 32 , 32 , 219, 220, 219, 32 , 219, 220, 219, 32 , 219, 223, 220, 32 , 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 32 , 223, 32 , 219, 32 , 219, 219, 220, 32 , 219, 223, 220, };
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	int num_chars = 50;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(30 + j, 2 + i); putchar(time[i * num_chars + j]);
		}
	}
	common::gotoXY(34, 29); cout << "W: add time" << "\t" << "S: minus time" << "\t" << "Enter: confirm";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(34, 20); cout << "The limit of the timer is from 0 to 24 hours";

	printColoredRectangle(31, 9, 50, 9, BLACK);
	printColoredRectangle(33, 10, 46, 7, BRIGHT_WHITE);
	printBoard(29, 8, 53, 10, BLACK);

	common::setConsoleColor(BRIGHT_WHITE, GREEN);
	numberTransfer(40, 12, hour);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(50, 12); putchar(254);
	common::gotoXY(50, 13); putchar(254);
	numberTransfer(52, 12, minute);
	common::gotoXY(62, 12); putchar(254);
	common::gotoXY(62, 13); putchar(254);
	numberTransfer(64, 12, minute);

	int pos = 0;
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	while (1) {
		if (pos == 1) {
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			numberTransfer(40, 12, hour);
			common::setConsoleColor(BRIGHT_WHITE, GREEN);
			numberTransfer(52, 12, minute);
		}
		else if (pos == 2) {
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			numberTransfer(52, 12, minute);
			common::setConsoleColor(BRIGHT_WHITE, GREEN);
			numberTransfer(64, 12, second);
		}
		common::setConsoleColor(BRIGHT_WHITE, GREEN);
		int input = common::getConsoleInput();
		switch (input) {
		case 2: 
			if (pos == 0) {
				++hour; if (hour == 25) hour = 24; numberTransfer(40, 12, hour); break;
			}
			else if (pos == 1) {
				++minute; if (minute == 60) minute = 0; numberTransfer(52, 12, minute); break;
			}
			else {
				++second; if (second == 60) second = 0; numberTransfer(64, 12, second); break;
			}
		case 5: 
			if (pos == 0) {
				--hour; if (hour == -1) hour = 0; numberTransfer(40, 12, hour); break;
			}
			else if (pos == 1) {
				--minute; if (minute == -1) minute = 59; numberTransfer(52, 12, minute); break;
			}
			else {
				--second; if (second == -1) second = 59; numberTransfer(64, 12, second); break;
			}
		case 6: pos++; break;
		}
		if (pos == 3) break;
	}

	int t = 3;
	while (t > 0) {
		common::setColor(0);
		numberTransfer(40, 12, hour);
		common::gotoXY(50, 12); putchar(254);
		common::gotoXY(50, 13); putchar(254);
		numberTransfer(52, 12, minute);
		common::gotoXY(62, 12); putchar(254);
		common::gotoXY(62, 13); putchar(254);
		numberTransfer(64, 12, second);
		Sleep(500);

		common::setColor(4);
		numberTransfer(40, 12, hour);
		common::gotoXY(50, 12); putchar(254);
		common::gotoXY(50, 13); putchar(254);
		numberTransfer(52, 12, minute);
		common::gotoXY(62, 12); putchar(254);
		common::gotoXY(62, 13); putchar(254);
		numberTransfer(64, 12, second);
		Sleep(500);
		t--;
	}
}
