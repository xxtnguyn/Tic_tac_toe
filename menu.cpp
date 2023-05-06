#include "menu.h"
#include "gameplay.h"
#include "avatar.h"
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
	/*common::clearConsole();
	draw::printIntro();
	common::clearConsole();
	draw::loadingBar();
	common::clearConsole();*/
	// draw::printAnimatedBigXandBigO(96, 10, 1, 10);
	common::clearConsole();
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
		draw::printColoredRectangle(48, top + current_option % 5 * 2, 12, 1, BRIGHT_WHITE);
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
		draw::printColoredRectangle(48, top + current_option % 5 * 2, 12, 1, BLACK);
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


void menu::mainMenu()
{
	draw::printBigX(96, 19, LIGHT_RED, BRIGHT_WHITE);
	draw::printBigO(1, 16, LIGHT_BLUE, BRIGHT_WHITE);
	Sleep(100);
	draw::printBigX(22, 22, LIGHT_RED, BRIGHT_WHITE);
	Sleep(100);
	draw::printBigO(78, 24, LIGHT_BLUE, BRIGHT_WHITE);
	draw::printLogo();
	Sleep(100);
	//printOptionsBoard();
	current_option = 4;
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 0);
	changeOption(0, 1);
}

void menu::backMenu()
{
	common::clearConsole();
	draw::loadingBar();
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

	draw::printBoard(10, 1, 86, 5, BLACK);

	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(48, 1);
	cout << "  CONTROL  ";

	draw::printBoard(10, 7, 86, 19, BLACK);

	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(49, 7);
	cout << "  RULES  ";

	common::setConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE);
	common::gotoXY(13, 10);
	putchar(06); cout << " Two players play against each other on 14x14 grid using the   and   symbol.";
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

	draw::printColoredRectangle(48, 28, 12, 1, BLACK);
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
	draw::loadingBar();
	common::clearConsole();
}

void menu::aboutUS()
{
	common::clearConsole();
	common::setConsoleColor(BRIGHT_WHITE, AQUA);
	common::gotoXY(1, 1);
	putchar(201); putchar(205);
	draw::printTTN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, GREEN);
	common::gotoXY(102, 1);
	putchar(205); putchar(187);
	draw::printDNTN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, YELLOW);
	common::gotoXY(1, 26);
	putchar(200); putchar(205);
	draw::printTHKN();
	Sleep(500);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(102, 26);
	putchar(205); putchar(188);
	draw::printLTN();
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
	draw::printInstructor();
	Sleep(500);
	draw::printColoredRectangle(48, 28, 12, 1, BLACK);
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
	draw::loadingBar();
	common::clearConsole();
}


void menu::exitScreen()
{
	common::showCursor(false);
	common::clearConsole();
	draw::printScene();
	/*avatar::leftAmongUsHead(10, 0, LIGHT_BLUE, BLUE);*/
	/*avatar::Cat(10, 0);*/
	//common::setConsoleColor(BRIGHT_WHITE, BLACK);
	//printRectangle(36, 18, 35, 8);
	//printRectangle(39, 23, 7, 2);
	//printRectangle(62, 23, 6, 2);
	//common::setConsoleColor(BRIGHT_WHITE, RED);
	//printLogo();
	draw::printBoard(32, 8, 44, 9, BLACK);
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
			draw::loadingBar();
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
	draw::printLoadText();
	draw::printLoadBoard(BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(12, 10); cout << " No. ";
	common::gotoXY(20, 10); cout << " X player's name ";
	common::gotoXY(42, 10); cout << " O player's name ";
	common::gotoXY(71, 10); cout << " Date & Time ";
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	draw::printRectangle(7, 28, 14, 2);
	draw::printRectangle(46, 28, 14, 2);
	draw::printRectangle(85, 28, 14, 2);
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

void menu::chooseAvatar() 
{
	// Tiêu đề
	draw::printTitleChoose(20, 1);

	// Hàng trên
	common::setColor(0);
	common::gotoXY(14, 4); cout << "No.1";
	draw::printBoard(7, 5, 16, 10, BLACK);
	draw::printColoredRectangle(8, 6, 15, 9, WHITE);
	avatar::rightAmongUs(9, 7, LIGHT_RED, RED);
	string red = "RED";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	for (int i = 0; i < red.size(); i++) {
		common::gotoXY(5, 8 + 2 * i);
		cout << red[i];
	}

	common::setColor(0);
	common::gotoXY(44, 4); cout << "No.2";
	draw::printBoard(37, 5, 16, 10, BLACK);
	draw::printColoredRectangle(38, 6, 15, 9, WHITE);
	avatar::rightAmongUs(39, 7, LIGHT_BLUE, BLUE);
	string blue = "BLUE";
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	for (int i = 0; i < blue.size(); i++) {
		common::gotoXY(35, 7 + 2 * i);
		cout << blue[i];
	}

	common::setColor(0);
	common::gotoXY(74, 4); cout << "No.3";
	draw::printBoard(67, 5, 16, 10, BLACK);
	draw::printColoredRectangle(68, 6, 15, 9, WHITE);
	avatar::rightAmongUs(69, 7, LIGHT_GREEN, GREEN);
	string green = "GREEN";
	common::setConsoleColor(BRIGHT_WHITE, GREEN);
	for (int i = 0; i < green.size(); i++) {
		common::gotoXY(65, 6 + 2 * i);
		cout << green[i];
	}

	// Hang dưới
	common::setColor(0);
	common::gotoXY(27, 18); cout << "No.4";
	draw::printBoard(20, 19, 16, 10, BLACK);
	draw::printColoredRectangle(21, 20, 15, 9, WHITE);
	avatar::rightAmongUs(22, 21, LIGHT_PURPLE, PURPLE);
	string purple = "PURPLE";
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	for (int i = 0; i < purple.size(); i++) {
		common::gotoXY(18, 19 + 2 * i);
		cout << purple[i];
	}

	common::setColor(0);
	common::gotoXY(57, 18); cout << "No.5";
	draw::printBoard(50, 19, 16, 10, BLACK);
	draw::printColoredRectangle(51, 20, 15, 9, WHITE);
	avatar::rightAmongUs(52, 21, BRIGHT_WHITE, WHITE);
	string white = "WHITE";
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < white.size(); i++) {
		common::gotoXY(48, 20 + 2 * i);
		cout << white[i];
	}

	common::setColor(0);
	common::gotoXY(87, 18); cout << "No.6";
	draw::printBoard(80, 19, 16, 10, BLACK);
	draw::printColoredRectangle(81, 20, 15, 9, WHITE);
	avatar::rightAmongUs(82, 21, LIGHT_YELLOW, LIGHT_YELLOW);
	string yellow = "YELLOW";
	common::setConsoleColor(BRIGHT_WHITE, YELLOW);
	for (int i = 0; i < yellow.size(); i++) {
		common::gotoXY(78, 19 + 2 * i);
		cout << yellow[i];
	}

	// Hộp Start (vào game)
	common::setColor(2);
	draw::printRectangle(91, 9, 9, 2);
	common::gotoXY(94, 10); cout << "START";

	// Hộp back menu
	draw::printRectangle(3, 23, 8, 2);
	common::gotoXY(6, 24); cout << "BACK";
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


