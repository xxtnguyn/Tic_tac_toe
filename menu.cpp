#include "menu.h"
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

int menu::current_option;
const string menu::options[9] = { "NEW GAME", "LOAD", "HELP", "ABOUT US", "EXIT", " PvP ", "PvE(easy)", "PvE(hard)", "BACK" };


void menu::mainScreen()
{
	_getch();
	unordered_map<string, void(*)()> function_map = {
		{options[0], newGameMenu},
		{options[1], loadScreen},
		{options[2], helpScreen},
		{options[3], aboutUS},
		{options[4], exitScreen},
		{options[5], playPvP},
		{options[6], playPvEe},
		{options[7], playPvEh},
		{options[8], backMenu} };
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::clearConsole();
	printIntro();
	printAnimatedBigXandBigO(96, 10, 1, 10);
	loadingBar();
	bool loadMenu = 1;
	while (true)
	{
		if (loadMenu)
			mainMenu();
		switch (common::getConsoleInput())
		{
		case 2:
			changeOption(0, 1);
			loadMenu = 0;
			break;
		case 5:
			changeOption(1, 1);
			loadMenu = 0;
			break;
		case 6:
			if (current_option == 0)
				loadMenu = 0;
			else
				loadMenu = 1;
			function_map[options[current_option]]();
			break;
		default:
			//common::playSound(4);
			loadMenu = 0;
		}
	}

	common::clearConsole();

}

void menu::changeOption(bool direction, bool flag) //0: lên, 1: xuống
{
	int top = 19;
	if ((direction == 0 && (current_option == 5 || current_option == 0))
		|| (direction == 1 && (current_option == 4 || current_option == 8)))
	{
		//common::playSound(4);
		return;
	}
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(54 - (int)options[current_option].length(), top + current_option % 5 * 2);
	cout << "                     ";
	common::gotoXY(54 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
	cout << options[current_option];
	if (flag)
	{
		/*common::gotoXY(44, top + current_option % 5 * 2);
		putchar(32);
		common::gotoXY(64, top + current_option % 5 * 2);
		putchar(32);*/
		printColoredRectangle(48, top + current_option % 5 * 2, 12, 1, BRIGHT_WHITE);
		common::gotoXY(54 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		cout << options[current_option];
		common::gotoXY(41, top + current_option % 5 * 2);
		putchar(32); putchar(32); putchar(32); putchar(32);
		common::gotoXY(63, top + current_option % 5 * 2);
		putchar(32); putchar(32); putchar(32); putchar(32);
	}
	(direction == 1) ? current_option++ : current_option--;
	if (flag)
	{
		//common::playSound(2);
		/*common::setConsoleColor(BRIGHT_WHITE, RED);
		common::gotoXY(44, top + current_option % 5 * 2);
		putchar(175);
		common::gotoXY(54 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
		cout << options[current_option];
		common::gotoXY(64, top + current_option % 5 * 2);
		putchar(174);*/
		printColoredRectangle(48, top + current_option % 5 * 2, 12, 1, BLACK);
		common::gotoXY(54 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		cout << options[current_option];
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
		common::gotoXY(41, top + current_option % 5 * 2);
		putchar(62); putchar(62); putchar(62); putchar(62);
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		common::gotoXY(63, top + current_option % 5 * 2);
		putchar(60); putchar(60); putchar(60); putchar(60);
	}
}

//void menu::onlyOption()
//{
//	int top = 19;
//	printColoredRectangle(48, top + current_option % 5 * 2, 12, 1, BLACK);
//	common::gotoXY(54 - (int)options[current_option].length() / 2, top + current_option % 5 * 2);
//	common::setConsoleColor(BLACK, BRIGHT_WHITE);
//	cout << options[current_option];
//	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
//	common::gotoXY(41, top + current_option % 5 * 2);
//	putchar(62);putchar(62);putchar(62);putchar(62);
//	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
//	common::gotoXY(63, top + current_option % 5 * 2);
//	putchar(60);putchar(60);putchar(60);putchar(60);
//}

void menu::printLogo()
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

void menu::mainMenu()
{
	printBigX(96, 19, LIGHT_RED, BRIGHT_WHITE);
	printBigO(1, 16, LIGHT_BLUE, BRIGHT_WHITE);
	Sleep(100);
	printBigX(22, 22, LIGHT_RED, BRIGHT_WHITE);
	Sleep(100);
	printBigO(78, 24, LIGHT_BLUE, BRIGHT_WHITE);
	printLogo();
	Sleep(100);
	//printOptionsBoard();
	current_option = 4;
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 1);
}

void menu::printRectangle(int left, int top, int width, int height)
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

void menu::printColoredRectangle(int left, int top, int width, int height, int color)
{
	common::gotoXY(left, top);
	common::setConsoleColor(BRIGHT_WHITE, color);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) putchar(219);
		common::gotoXY(left, top + i + 1);
	}
}

void menu::printX(int left, int top)
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

void menu::printO(int left, int top)
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

void menu::printBigX(int left, int top, int color1, int color2)
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

void menu::printAnimatedBigXandBigO(int leftX, int topX, int leftO, int topO)
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

void menu::printBigO(int left, int top, int color1, int color2)
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

void menu::printBoard(int left, int top, int width, int height, int color)
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

void menu::printTTN()
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

void menu::printDNTN() {
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

void menu::printLTN()
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

void menu::printTHKN()
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

void menu::printInstructor()
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

void menu::backMenu()
{
	common::clearConsole();
	menu::loadingBar();
	common::clearConsole();
}

void menu::newGameMenu()
{
	current_option = 8;
	common::gotoXY(50 - (int)options[8].length(), 27);
	cout << "                     ";
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 1);
}

void menu::playPvP()
{
	gameplay g;
	g.setUpGame(0);
	g.startGame();
}

void menu::helpScreen()
{
	common::showCursor(false);
	common::clearConsole();

	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	common::gotoXY(18, 4);
	cout << "USE                     TO MOVE";
	common::gotoXY(30, 3);
	common::setConsoleColor(LIGHT_RED, BRIGHT_WHITE);
	cout << " W ";
	common::gotoXY(26, 5); cout << " A ";
	common::gotoXY(30, 5); cout << " S ";
	common::gotoXY(34, 5);	cout << " D ";

	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	common::gotoXY(58, 4);
	cout << "USE                  TO PLACE";
	common::gotoXY(68, 3);
	putchar(220); putchar(220); putchar(220); putchar(220); putchar(220);
	common::gotoXY(68, 4);
	common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	putchar(32); putchar(17); putchar(196); putchar(217); putchar(32);

	printBoard(10, 1, 86, 5, BLACK);

	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(48, 1);
	cout << "  CONTROL  ";

	printBoard(10, 7, 86, 19, BLACK);

	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(49, 7);
	cout << "  RULES  ";

	common::setConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE);
	common::gotoXY(13, 10);
	putchar(06); cout << " Two players play against each other on 10x10 grid using the   and   symbol.";
	common::gotoXY(13, 13);
	putchar(06); cout << " The player representing   gets to take the first turn followed by the player ";
	common::gotoXY(15, 14);
	cout << "representing  . Players take turn placing their symbol on an open intersection ";
	common::gotoXY(15, 15);
	cout << "on the board.";
	common::gotoXY(13, 18);
	putchar(06); cout << " You have to race to create an unbroken row of five symbols while blocking ";
	common::gotoXY(15, 19);
	cout << "your opponent to prevent them from creating five in a row. The one managing to ";
	common::gotoXY(15, 20);
	cout << "create five in a row first wins the round. ";
	common::gotoXY(13, 23);
	putchar(06); cout << " The row can be horizontal, vertical, or diagonal as long as it is unbroken. ";

	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	common::gotoXY(75, 10); cout << "X";
	common::gotoXY(39, 13); cout << "X";
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	common::gotoXY(81, 10); cout << "O";
	common::gotoXY(28, 14); cout << "O";

	printColoredRectangle(48, 28, 12, 1, BLACK);
	common::gotoXY(54 - (int)options[8].length() / 2, 28);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	cout << options[8];
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	common::gotoXY(41, 28);
	putchar(62); putchar(62); putchar(62); putchar(62);
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	common::gotoXY(63, 28);
	putchar(60); putchar(60); putchar(60); putchar(60);

	while (common::getConsoleInput() != 6) {}
	common::clearConsole();
	menu::loadingBar();
	common::clearConsole();
}

void menu::aboutUS()
{
	common::clearConsole();
	common::setConsoleColor(BRIGHT_WHITE, AQUA);
	common::gotoXY(1, 1);
	putchar(201); putchar(205);
	printTTN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, GREEN);
	common::gotoXY(102, 1);
	putchar(205); putchar(187);
	printDNTN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, YELLOW);
	common::gotoXY(1, 26);
	putchar(200); putchar(205);
	printTHKN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(102, 26);
	putchar(205); putchar(188);
	printLTN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, GRAY);
	common::gotoXY(4, 1);
	for (int i = 1; i <= 96; i++) putchar(196);
	common::gotoXY(4, 26);
	for (int i = 1; i <= 96; i++) putchar(196);
	for (int i = 2; i <= 23; i++)
	{
		common::gotoXY(1, 1 + i);
		putchar(179);
	}
	for (int i = 2; i <= 23; i++)
	{
		common::gotoXY(103, 1 + i);
		putchar(179);
	}
	printInstructor();
	Sleep(500);
	printColoredRectangle(48, 28, 12, 1, BLACK);
	common::gotoXY(54 - (int)options[8].length() / 2, 28);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	cout << options[8];
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	common::gotoXY(41, 28);
	putchar(62); putchar(62); putchar(62); putchar(62);
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	common::gotoXY(63, 28);
	putchar(60); putchar(60); putchar(60); putchar(60);
	while (common::getConsoleInput() != 6) {}
	common::clearConsole();
	menu::loadingBar();
	common::clearConsole();
}


void menu::exitScreen()
{
	common::showCursor(false);
	common::clearConsole();
	menu::printScene();
	//common::setConsoleColor(BRIGHT_WHITE, BLACK);
	//printRectangle(36, 18, 35, 8);
	//printRectangle(39, 23, 7, 2);
	//printRectangle(62, 23, 6, 2);
	//common::setConsoleColor(BRIGHT_WHITE, RED);
	////printLogo();
	printBoard(32, 8, 44, 9, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(44, 11);
	cout << " DO YOU WANT TO EXIT? ";
	string str[2] = { "YES", "NO" };
	int left[] = { 35,41,48,58,64,70 }, word[] = { 32,32,62,60 }, top = 15;
	bool choice = 0;
	bool loop = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			//common::playSound(2);
			if (i == 1)
			{
				common::setConsoleColor(BLACK, BRIGHT_WHITE);
				common::gotoXY(left[choice * 3 + 1], top);    cout << " " << str[choice] << " ";
			}
			else
			{
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				common::gotoXY(left[choice * 3 + 1], top);    cout << " " << str[choice] << " ";
			}
			common::gotoXY(left[choice * 3], top);  common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);      putchar(word[i * 2]);putchar(word[i * 2]);putchar(word[i * 2]);putchar(word[i * 2]);
			common::gotoXY(left[choice * 3 + 2], top);  common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);  putchar(word[i * 2 + 1]); putchar(word[i * 2 + 1]); putchar(word[i * 2 + 1]); putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (loop)
	{
		int key = common::getConsoleInput();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
		{
			print1();
		}
		else if (key == 6)
		{
			if (!choice)
			{
				common::clearConsole();
				exit(0);
			}
			common::clearConsole();
			menu::loadingBar();
			common::clearConsole();
			return;
		}
		else
		{
			//common::playSound(4);
		}
	}
}

void menu::playPvEe()
{
	gameplay g;
	g.setUpGame(1);
	g.startGame();
}

void menu::playPvEh()
{
	gameplay g;
	g.setUpGame(2);
	g.startGame();
}

void menu::loadScreen()
{
	common::clearConsole();
	printLoadText();
	printLoadBoard(BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(12, 10); cout << " No. ";
	common::gotoXY(20, 10); cout << " X player's name ";
	common::gotoXY(42, 10); cout << " O player's name ";
	common::gotoXY(71, 10); cout << " Date & Time ";
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	printRectangle(7, 28, 14, 2);
	printRectangle(46, 28, 14, 2);
	printRectangle(85, 28, 14, 2);
	common::gotoXY(11, 29);
	cout << "PREV (A)";
	common::gotoXY(49, 29);
	cout << "BACK (ESC)";
	common::gotoXY(89, 29);
	cout << "NEXT (D)";
	vector<string> fileName;
	for (auto& p : fs::recursive_directory_iterator("load"))
	{
		if (p.path().extension() == ".txt")
		{
			string temp = p.path().filename().string();
			temp.erase(temp.find_last_of('.'));
			fileName.push_back(temp);
		}
	}
	if (!fileName.size())
	{
		common::gotoXY(42, 15);
		cout << "No game files were found!";
		Sleep(3000);
		return;
	}
	int file = 8;
	changeFile(3, fileName, file);
	bool chosen = 0;
	while (!chosen)
	{
		int key = common::getConsoleInput();
		if (key == 6)
		{
			gameplay g;
			g.setUpGame(3, fileName[file]);
			g.startGame();
			chosen = 1;
		}
		else if (key > 1 && key < 6)
		{
			changeFile(key, fileName, file);
		}
		else if (key == 1)
		{
			chosen = 1;
			common::clearConsole();
		}
		else
		{
			//common::playSound(4);
		}
	}
}


void menu::changeFile(int key, vector<string>& fileName, int& file)
{
	vector<string> dt;
	vector<string> p1Name;
	vector<string> p2Name;
	for (int i=0; i<fileName.size();i++)
	{
		string temp1, temp2, temp3;
		string fullPath = "load\\" + fileName[i] + ".txt";
		ifstream inFile(fullPath);
		getline(inFile, temp1);
		getline(inFile, temp2);
		getline(inFile, temp3);
		dt.push_back(temp1);
		p1Name.push_back(temp2);
		p2Name.push_back(temp3);
		inFile.close();
	}
	if (key == 3 || key == 4)
	{
		if (key == 3 && file > 7)
		{
			//common::playSound(2);
			file = (file / 8 - 1) * 8;
		}
		else if (key == 4 && file / 8 < fileName.size() / 8)
		{
			file = (file / 8 + 1) * 8;
		}
		else
		{
			//common::playSound(4);
			return;
		}
		//common::playSound(2);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		int i = 0;
		for (i = file + 1; i < file + 8; i++)
		{
			common::gotoXY(12, 12 + i % 8 * 2);
			for (int j = 0; j < 5;j++)
			{
				putchar(32);
			}
			common::gotoXY(20, 12 + i % 8 * 2);
			for (int j = 0; j < 19;j++)
			{
					putchar(32);
			}
			common::gotoXY(40, 12 + i % 8 * 2);
			for (int j = 0; j < 20;j++)
			{
				putchar(32);
			}
			common::gotoXY(62, 12 + i % 8 * 2);
			for (int j = 0; j < 32;j++)
			{
				putchar(32);
			}
			if (i < fileName.size())
			{
				common::gotoXY(14, 12 + i % 8 * 2);
				cout << i + 1;
				common::gotoXY(23, 12 + i % 8 * 2);
				cout << p1Name[i];
				common::gotoXY(43, 12 + i % 8 * 2);
				cout << p2Name[i];
				common::gotoXY(66, 12 + i % 8 * 2);
				cout << dt[i];
			}
		}
		common::gotoXY(5, 16);
		if (file - 8 < 0) cout << "   ";
		else cout << "<<<";
		common::gotoXY(98, 16);
		if (file + 8 >= fileName.size()) cout << "   ";
		else cout << ">>>";
		common::setConsoleColor(BRIGHT_WHITE, RED);
		common::gotoXY(12, 12);
		for (int j = 0; j < 5;j++)
		{
			putchar(32);
		}
		common::gotoXY(20, 12);
		for (int j = 0; j < 19;j++)
		{
			putchar(32);
		}
		common::gotoXY(40, 12);
		for (int j = 0; j < 20;j++)
		{
			putchar(32);
		}
		common::gotoXY(62, 12);
		for (int j = 0; j < 32;j++)
		{
			putchar(32);
		}
		common::gotoXY(14, 12);
		common::setConsoleColor(BRIGHT_WHITE, PURPLE);
		cout << file + 1;
		common::gotoXY(23, 12);
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		cout << p1Name[file];
		common::gotoXY(43, 12);
		common::setConsoleColor(BRIGHT_WHITE, RED);
		cout << p2Name[file];
		common::gotoXY(66, 12);
		common::setConsoleColor(BRIGHT_WHITE, PURPLE);
		cout << dt[file];
	}
	else if (key == 2 || key == 5)
	{
			if (key == 2 && file % 8 > 0)
			{
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				common::gotoXY(14, 12 + file % 8 * 2);
				cout << file + 1;
				common::gotoXY(23, 12 + file % 8 * 2);
				cout << p1Name[file];
				common::gotoXY(43, 12 + file % 8 * 2);
				cout << p2Name[file];
				common::gotoXY(66, 12 + file % 8 * 2);
				cout << dt[file];
				file--;
			}
			else if (key == 5 && file % 8 < 7 && file < fileName.size() - 1)
			{
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				common::gotoXY(14, 12 + file % 8 * 2);
				cout << file + 1;
				common::gotoXY(23, 12 + file % 8 * 2);
				cout << p1Name[file];
				common::gotoXY(43, 12 + file % 8 * 2);
				cout << p2Name[file];
				common::gotoXY(66, 12 + file % 8 * 2);
				cout << dt[file];
				file++;
			}
			else
			{
				//common::playSound(4);
				return;
			}
			common::gotoXY(14, 12 + file % 8 * 2);
			common::setConsoleColor(BRIGHT_WHITE, PURPLE);
			cout << file + 1;
			common::gotoXY(23, 12 + file % 8 * 2);
			common::setConsoleColor(BRIGHT_WHITE, BLUE);
			cout << p1Name[file];
			common::gotoXY(43, 12 + file % 8 * 2);
			common::setConsoleColor(BRIGHT_WHITE, RED);
			cout << p2Name[file];
			common::gotoXY(66, 12 + file % 8 * 2);
			common::setConsoleColor(BRIGHT_WHITE, PURPLE);
			cout << dt[file];
	}
}

//void menu::changeFile(int key, vector<string>& fileName, int& file)
//{
//	if (key == 3 || key == 4)
//	{
//		if (key == 3 && file > 7)
//		{
//			common::playSound(2);
//			file = (file / 8 - 1) * 8;
//		}
//		else if (key == 4 && file / 8 < fileName.size() / 8)
//		{
//			file = (file / 8 + 1) * 8;
//		}
//		else
//		{
//			common::playSound(4);
//			return;
//		}
//		common::playSound(2);
//		common::setConsoleColor(BRIGHT_WHITE, BLACK);
//		int i = 0;
//		for (i = file + 1; i < file + 8; i++)
//		{
//			common::gotoXY(0, 9 + i % 8 * 2);
//			for (int j = 0; j < 107; j++)
//				putchar(32);
//			if (i < fileName.size())
//			{
//				common::gotoXY(54 - fileName[i].find('-'), 9 + i % 8 * 2);
//				cout << fileName[i];
//			}
//		}
//		common::gotoXY(15, 16);
//		(file - 8 < 0) ? putchar(32) : putchar(60);
//		common::gotoXY(93, 16);
//		(file + 8 >= fileName.size()) ? putchar(32) : putchar(62);
//		common::setConsoleColor(BRIGHT_WHITE, RED);
//		common::gotoXY(0, 9);
//		for (int j = 0; j < 107; j++)
//			putchar(32);
//		common::gotoXY(54 - fileName[file].find('-'), 9);
//		cout << fileName[file];
//	}
//	else if (key == 2 || key == 5)
//	{
//		if (key == 2 && file % 8 > 0)
//		{
//			common::setConsoleColor(BRIGHT_WHITE, BLACK);
//			common::gotoXY(54 - fileName[file].find('-'), 9 + file % 8 * 2);
//			cout << fileName[file];
//			file--;
//		}
//		else if (key == 5 && file % 8 < 7 && file < fileName.size() - 1)
//		{
//			common::setConsoleColor(BRIGHT_WHITE, BLACK);
//			common::gotoXY(54 - fileName[file].find('-'), 9 + file % 8 * 2);
//			cout << fileName[file];
//			file++;
//		}
//		else
//		{
//			common::playSound(4);
//			return;
//		}
//		common::setConsoleColor(BRIGHT_WHITE, RED);
//		common::gotoXY(54 - fileName[file].find('-'), 9 + file % 8 * 2);
//		cout << fileName[file];
//	}
//}

void menu::printLoadText() 
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
			if (j < num_chars / 2-1) common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			else common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			putchar(logo[i * num_chars + j]);
		}
	}
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	printX(28, 5);
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	printO(77, 0);
}

void menu::loadingBar()
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

void menu::printScene() {
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
}

void menu::rainbowBackground()
{
	int color[] = { 12, 14, 10 , 9, 13 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 105; j++) {
			for (int k = 0; k < 6; k++) {
				common::setColor(color[i]);
				common::gotoXY(j, i * 6 + k);
				putchar(219);
			}
		}
	}
	for (int i = 0; i < 105; i++) {
		common::setColor(color[4]);
		common::gotoXY(i, 30);
		putchar(219);
	}

	common::setColor(15);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 44; j++) {
			common::gotoXY(32 + j, 8 + i);
			putchar(219);
		}
	}
}

void menu::printIntro()
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

	menu::printBoard(x - 3, y - 2, 49, 8, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 44; j++) {
			common::gotoXY(x + j, y + i);
			putchar(intro_Welcome[i * 44 + j]);

		}
	}

	menu::printBoard(x + 1, y + 6, 41, 5, BLACK);
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

void menu::rainbowColumn() {
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

void menu::printLoadBoard(int color)
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
	for (int i = top + 2;i < top + height;i += 2)
	{
		common::gotoXY(12, i);
		for (int j = 0;j < width - 1;j++)
		{
			if (j != 5 && j != 27 && j != 49)
				putchar(196);
			else putchar(197);
		}
	}
	for (int i = top + 1;i < top + height;i += 2)
	{
		common::gotoXY(17, i); putchar(179);
		common::gotoXY(39, i); putchar(179);
		common::gotoXY(61, i); putchar(179);
	}
}

