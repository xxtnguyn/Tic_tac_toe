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
	avatar::Cat(10, 0, LIGHT_RED);
	avatar::Cat(10, 16, LIGHT_BLUE);
	avatar::Cat(85, 8, LIGHT_YELLOW);
	avatar::Cat(85, 24, LIGHT_PURPLE);
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


void draw::printScene() {
	common::setColor(0);
	char sun[] = { char(219), char(254), char(223),char(220) };
	for (int i = 0; i < 3; i++)
	{
		// Tia lửa ngang trái
		common::gotoXY(90 - 6 + 2 * i, 5);
		cout << sun[3];
		common::gotoXY(90 - 6 + 2 * i, 5 + 1);
		cout << sun[2];

		// Vẽ hình tròn mặt trời
		common::gotoXY(90 + i, 5 - i);
		cout << sun[0];
		common::gotoXY(90 + i, 5 + 1 + i);
		cout << sun[0];
		if (i == 2) {
			common::gotoXY(90 + 3, 5 - 2);
			cout << sun[0] << sun[0];
			common::gotoXY(90 + 3, 5 + 3);
			cout << sun[0] << sun[0];
		}

		common::gotoXY(90 + 4 + i, 5 - 2 + i);
		cout << sun[0];
		common::gotoXY(90 + 4 + i, 5 + 3 - i);
		cout << sun[0];

		// Vẽ tia lửa ngang phải
		common::gotoXY(90 + 8 + 2 * i, 5);
		cout << sun[3];
		common::gotoXY(90 + 8 + 2 * i, 5 + 1);
		cout << sun[2];

		// Vẽ tia lửa ngang phía trên
		common::gotoXY(90 + 3, 5 - 3 - i);
		if (i == 0) cout << sun[2];
		else if (i == 1) cout << sun[1];
		else cout << sun[3];

		// Vẽ tia lửa ngang phía dưới
		common::gotoXY(90 + 3, 5 + 4 + i);
		if (i == 0) cout << sun[3];
		else if (i == 1) cout << sun[1];
		else cout << sun[2];

		// Vẽ tia lửa chéo trái
		common::gotoXY(90 - 3 + i, 5 - 4 + i);
		cout << sun[1];
		common::gotoXY(90 + 7 + i, 5 + 3 + i);
		cout << sun[1];

		// Vẽ tia lửa chéo phải
		common::gotoXY(90 + 7 + i, 5 - 2 - i);
		cout << sun[1];
		common::gotoXY(90 - 3 + i, 5 + 5 - i);
		cout << sun[1];
	}

	// Vẽ tâm mặt trời
	common::setColor(14);
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			common::gotoXY(90 + 1, 5);
			cout << sun[0];
			common::gotoXY(90 + 1, 5 + 1);
			cout << sun[0];
		}
		if (i == 2) {
			common::gotoXY(90 + 5, 5);
			cout << sun[0];
			common::gotoXY(90 + 5, 5 + 1);
			cout << sun[0];
		}

		common::gotoXY(90 + 2 + i, 5 - 1);
		cout << sun[0];
		common::gotoXY(90 + 2 + i, 5);
		cout << sun[0];
		common::gotoXY(90 + 2 + i, 5 + 1);
		cout << sun[0];
		common::gotoXY(90 + 2 + i, 5 + 2);
		cout << sun[0];
	}

	// Vẽ hải âu 1
	common::setColor(0);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(60 + i, 4 - i);
		cout << sun[0];
		if (i == 2) {
			common::gotoXY(60 + 3, 4 - i);
			cout << sun[0];
		}
		common::gotoXY(60 + 2 + i + 1, 4 - 2 + i);
		cout << sun[0];

		common::gotoXY(60 + 4 + i + 1, 4 - i);
		cout << sun[0];
		if (i == 2) {
			common::gotoXY(60 + 8, 4 - i);
			cout << sun[0];
		}
		common::gotoXY(60 + 8 + i, 4 - 2 + i);
		cout << sun[0];
	}

	// Vẽ hải âu 2
	for (int i = 0; i < 3; i++) {
		common::gotoXY(83 + i, 17 - i);
		cout << sun[0];
		if (i == 2) {
			common::gotoXY(83 + 3, 17 - i);
			cout << sun[0];
		}
		common::gotoXY(83 + 2 + i + 1, 17 - 2 + i);
		cout << sun[0];

		common::gotoXY(83 + 4 + i + 1, 17 - i);
		cout << sun[0];
		if (i == 2) {
			common::gotoXY(683 + 8, 17 - i);
			cout << sun[0];
		}
		common::gotoXY(83 + 8 + i, 17 - 2 + i);
		cout << sun[0];
	}

	// Vẽ biển
	common::setColor(9);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 105; j++) {
			common::gotoXY(j, 25 + i + 1);
			cout << sun[0];
		}
	}

	common::setColor(0);
	for (int i = 0; i < 105; i++) {
		common::gotoXY(i, 25);
		cout << sun[3];
	}

	common::setConsoleColor(LIGHT_BLUE, BLUE);
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					common::gotoXY(8 + 25 * j + k, 25 + 1 + i);
					cout << sun[3];
				}
			}
		}
		else {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 2; k++) {
					common::gotoXY(20 + 25 * j + k, 25 + 1 + i);
					cout << sun[3];
				}
			}
		}
	}

	// Vẽ đảo

	// Vẽ cây trên đảo

	// Vẽ phần trên của cây
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 15 + 4 * i; j++) {
			if (i == 0) {
				common::gotoXY(j, 0);
				cout << sun[3];
			}
			if (j == 14 + 4 * i) {
				/*common::gotoXY(x + j + 1, y - 1 + i);
				cout << sun[0];*/
				for (int t = 0; t < 4; t++) {
					common::gotoXY(j + 1 + t, 2 - 1 + i);
					cout << sun[3];
				}
			}
		}
		for (int k = 0; k < 33 - 3 * i; k++) {
			if (i != 5 && i != 4 && i != 0) {
				if (k == 32 - 3 * i) {
					/*common::gotoXY(x + k + 1, y + i + 7);
					cout << sun[0];*/
					for (int t = 0; t < 3; t++) {
						common::gotoXY(k + 1 + t, 2 + i + 7);
						cout << sun[2];
					}
				}
				if (i == 3) {
					common::gotoXY(k, 13);
					cout << sun[2];
				}
			}
		}
	}

	common::setColor(2);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 15 + 4 * i; j++) {
			if (i == 0) {
				common::gotoXY(j, 1);
				cout << sun[0];
			}
			if (j == 14 + 4 * i) {
				for (int t = 0; t < 4; t++) {
					common::gotoXY(j + 1 + t, 2 + i);
					cout << sun[0];
				}
			}
		}
		for (int k = 0; k < 33 - 3 * i; k++) {
			if (i != 5 && i != 4) {
				if (k == 32 - 3 * i) {
					for (int t = 0; t < 3; t++) {
						common::gotoXY(k + 1 + t, 2 + i + 6);
						cout << sun[0];
					}
				}
				if (i == 3) {
					common::gotoXY(k, 12);
					cout << sun[0];
				}
			}
		}
	}

	common::setColor(10);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 15 + 4 * i; j++) {
			common::gotoXY(j, 2 + i);
			cout << sun[0];
		}
		for (int k = 0; k < 33 - 3 * i; k++) {
			if (i != 4 && i != 5) {
				common::gotoXY(k, 2 + i + 6);
				cout << sun[0];
			}
		}
	}

	// Vẽ thân cây
	common::setColor(0);
	for (int i = 0; i < 13; i++) {
		common::gotoXY(7, 12 + i);
		cout << sun[0];
	}

	common::setColor(6);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 7; j++) {
			common::gotoXY(j, 2 + 10 + i);
			cout << sun[0];
		}
	}

	// Vẽ táo
	common::setColor(4);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(2 + j, 5 + i); cout << sun[0];
			common::gotoXY(8 + j, 8 + i); cout << sun[0];
			common::gotoXY(16 + j, 5 + i); cout << sun[0];
			common::gotoXY(21 + j, 9 + i); cout << sun[0];
		}
	}
	common::setColor(2);
	common::gotoXY(3, 4); cout << sun[0];
	common::gotoXY(9, 7); cout << sun[0];
	common::gotoXY(17, 4); cout << sun[0];
	common::gotoXY(22, 8); cout << sun[0];

	// Vẽ nền đất của đảo
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 15; i++) {
		common::gotoXY(8 + i, 2 + 12 + 9);
		cout << sun[3];
	}
	for (int i = 0; i < 4; i++) {
		common::gotoXY(9 + 14 + i, 2 + 13 + 9 + i);
		cout << sun[0];
	}

	common::setColor(8);
	for (int i = 8; i < 23; i++) {
		common::gotoXY(i, 2 + 12 + 10);
		cout << sun[0];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 24 + i; j++) {
			common::gotoXY(j, 2 + 13 + 9 + 1 + i);
			cout << sun[0];
		}
	}

	avatar::rightAmongUs(10, 15, LIGHT_RED, RED);
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
