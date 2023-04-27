#include "gameplay.h"


gameplay::gameplay()
{
	_mode = -1;
	_x = LEFT, _y = TOP;
	_b = new board(SIZE, LEFT, TOP);
	_loop = _turn = _changeTurn = true;
	_finish = false;
	_showCursor = false;
	_p1Name = _p2Name = "";
	_countP1Wins = _countP2Wins = 0;
	_loadSymbols = false;
}

gameplay::~gameplay()
{
	delete _b;
	_b = nullptr;
}

void gameplay::startGame()
{
	common::clearConsole();
	while (_loop)
	{
		bool pause = false;
		_finish = false;
		printInterface();
		_x = _b->getXAt(5, 6);
		_y = _b->getYAt(5, 6);
		common::gotoXY(_x, _y);
		moveDown();
		while (!_finish && !pause)
		{
			if (_mode == 0 || (_turn == 1 && _countRounds % 2 == 0) || (_turn == 0 && _countRounds % 2 == 1))
			{
				switch (common::getConsoleInput())
				{
				case 0:
					//common::playSound(4);
					break;
				case 1:
					pause = 1;
					_loadSymbols = 1;
					exitGameScreen();
					_showCursor = false;
					break;
				case 2:
					moveUp();
					break;
				case 3:
					moveLeft();
					break;
				case 4:
					moveRight();
					break;
				case 5:
					moveDown();
					break;
				case 6:
					processCheckBoard();
					break;
				case 7:
					pause = 1;
					_loadSymbols = 1;
					saveBoxScreen();
					_showCursor = false;
					break;
				}
			}
			else
			{
				gpoint p = (_mode == 1) ? _b->PVC_easy() : _b->PVC_hard();
				moveToDirection(p.getX(), p.getY());
				processCheckBoard();
			}
		}
		if (pause)
			continue;
		_countRounds++;
		askContinue();
		if (_loop)
		{
			swap(_p1Name, _p2Name);
			swap(_countP1Wins, _countP2Wins);
		}
	}
	saveData();
}

void gameplay::processCheckBoard()
{
	int c = _b->checkBoard(_x, _y, _turn);
	if (c == -1 || c == 1)
	{
		//ommon::playSound(3);
		common::gotoXY(_x, _y);
		if (c == 1)
		{
			common::setConsoleColor(BRIGHT_WHITE, BLUE);
			putchar(88);
			common::gotoXY(86, 8);
			cout << _b->getCountX();
		}
		else
		{
			common::setConsoleColor(BRIGHT_WHITE, RED);
			putchar(79);
			common::gotoXY(86, 21);
			cout << _b->getCountO();
		}
		int result = processFinish();
		if (result == 2)
		{
			int color[] = { RED, BLUE }, pos[] = { 22,9 };
			if (_turn)
			{
				menu::printBoard(69, 1, 34, 10, LIGHT_BLUE);
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				menu::printRectangle(69, 14, 33, 10);
				menu::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
				common::gotoXY(86 - _p1Name.length() / 2, 4);
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
				cout << _p1Name;
				common::gotoXY(80, 5);
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				cout << "Winning Ratio:";
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
				string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
				common::gotoXY(86 - score1.find('/'), 6);
				cout << score1;
				common::gotoXY(84, 7);
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				cout << "Moves:";
				common::gotoXY(86, 8);
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
				cout << _b->getCountX();
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				common::gotoXY(82, 16);
				menu::printBigO(66, 15, GRAY, BRIGHT_WHITE);
				common::gotoXY(86 - _p2Name.length() / 2, 17);
				cout << _p2Name;
				common::gotoXY(80, 18);
				cout << "Winning Ratio:";
				string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
				common::gotoXY(86 - score2.find('/'), 19);
				cout << score2;
				common::gotoXY(84, 20);
				cout << "Moves:";
				common::gotoXY(86, 21);
				cout << _b->getCountO();
			}
			else
			{
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				menu::printRectangle(69, 1, 33, 10);
				menu::printBoard(69, 14, 34, 10, LIGHT_RED);
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				menu::printBigX(66, 2, GRAY, BRIGHT_WHITE);
				common::gotoXY(86 - _p1Name.length() / 2, 4);
				cout << _p1Name;
				common::gotoXY(80, 5);
				cout << "Winning Ratio:";
				string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
				common::gotoXY(86 - score1.find('/'), 6);
				cout << score1;
				common::gotoXY(84, 7);
				cout << "Moves:";
				common::gotoXY(86, 8);
				cout << _b->getCountX();
				common::gotoXY(82, 16);
				menu::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
				common::gotoXY(86 - _p2Name.length() / 2, 17);
				cout << _p2Name;
				common::gotoXY(80, 18);
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				cout << "Winning Ratio:";
				string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
				common::gotoXY(86 - score2.find('/'), 19);
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
				cout << score2;
				common::gotoXY(84, 20);
				common::setConsoleColor(BRIGHT_WHITE, BLACK);
				cout << "Moves:";
				common::gotoXY(86, 21);
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
				cout << _b->getCountO();
			}
			common::gotoXY(_x, _y);
			_showCursor = true;
			common::showCursor(_showCursor);
		}
	}
	else
	{
		//if (_mode == 0)
			//common::playSound(5);
	}
}

int gameplay::processFinish()
{
	common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int pWhoWin = _b->testBoard(_x, _y);
	if (_mode != 0)
	{
		switch (pWhoWin)
		{
		case -1:
			_finish = 1;
			_countP2Wins++;
			printWinPos();
			if (_p2Name != "Computer")
				printYouWin();
			else
				printYouLose();
			break;
		case 1:
			_finish = 1;
			_countP1Wins++;
			printWinPos();
			if (_p1Name != "Computer")
				printYouWin();
			else
				printYouLose();
			break;
		case 0:
			_finish = 1;
			printDraw();
			break;
		case 2:
			_turn = !_turn; // change turn if nothing happen
			_changeTurn = 1;
		}
	}
	else
	{
		switch (pWhoWin)
		{
		case -1:
			_finish = 1;
			_countP2Wins++;
			printWinPos();
			printPlayerWin(-1);
			break;
		case 1:
			_finish = 1;
			_countP1Wins++;
			printWinPos();
			printPlayerWin(1);
			break;
		case 0:
			_finish = 1;
			printDraw();
			break;
		case 2:
			_turn = !_turn; // change turn if nothing happen
			_changeTurn = 1;
		}
	}
	return pWhoWin;
}

void gameplay::moveRight()
{
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		//common::playSound(_turn);
		if (_b->getCheckAtXY(_x, _y) == 0)
		{
			common::gotoXY(_x, _y);
			putchar(32);
		}
		_x += 4;
		common::gotoXY(_x, _y);
		printTurnSymbol();
	}
	else
	{
		//common::playSound(4);
	}
}

void gameplay::moveLeft()
{
	if (_x > _b->getXAt(0, 0))
	{
		//common::playSound(_turn);
		if (_b->getCheckAtXY(_x, _y) == 0)
		{
			common::gotoXY(_x, _y);
			putchar(32);
		}
		_x -= 4;
		common::gotoXY(_x, _y);
		printTurnSymbol();
	}
	else
	{
		//common::playSound(4);
	}
}

void gameplay::moveDown()
{
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		//common::playSound(_turn);
		if (_b->getCheckAtXY(_x, _y) == 0)
		{
			common::gotoXY(_x, _y);
			putchar(32);
		}
		_y += 2;
		common::gotoXY(_x, _y);
		printTurnSymbol();
	}
	else
	{
		//common::playSound(4);
	}
}

void gameplay::moveUp()
{
	if (_y > _b->getYAt(0, 0))
	{
		//common::playSound(_turn);
		if (_b->getCheckAtXY(_x, _y) == 0)
		{
			common::gotoXY(_x, _y);
			putchar(32);
		}
		_y -= 2;
		common::gotoXY(_x, _y);
		printTurnSymbol();
	}
	else
	{
		//common::playSound(4);
	}
}

void gameplay::printTurnSymbol()
{
	if (_b->getCheckAtXY(_x, _y))
	{
		if (_showCursor == false)
		{
			_showCursor = true;
			common::showCursor(_showCursor);
		}
	}
	else
	{
		if (_showCursor == true)
		{
			_showCursor = false;
			common::showCursor(_showCursor);
		}
		if (_changeTurn == 1)
		{
			if (_turn == 1)
			{
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			}
			else
			{
				common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			}
			_changeTurn = 0;
		}
		if (_turn == 1)
			putchar(120);
		else
			putchar(111);
		common::gotoXY(_x, _y);
	}
}


void gameplay::printInterface()
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	_b->drawBoard();
	if (_loadSymbols)
	{
		printLoadedSymbols();
		_loadSymbols = 0;
	}
	if (_turn)
	{
		menu::printBoard(69, 1, 34, 10, LIGHT_BLUE);
		common::setConsoleColor(BRIGHT_WHITE, GRAY);
		menu::printRectangle(69, 14, 33, 10);
		menu::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
		common::gotoXY(86 - _p1Name.length() / 2, 4);
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
		cout << _p1Name;
		common::gotoXY(80, 5);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		cout << "Winning Ratio:";
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
		string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
		common::gotoXY(86 - score1.find('/'), 6);
		cout << score1;
		common::gotoXY(84, 7);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		cout << "Moves:";
		common::gotoXY(86, 8);
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
		cout << _b->getCountX();
		common::setConsoleColor(BRIGHT_WHITE, GRAY);
		common::gotoXY(82, 16);
		menu::printBigO(66, 15, GRAY, BRIGHT_WHITE);
		common::gotoXY(86 - _p2Name.length() / 2, 17);
		cout << _p2Name;
		common::gotoXY(80, 18);
		cout << "Winning Ratio:";
		string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
		common::gotoXY(86 - score2.find('/'), 19);
		cout << score2;
		common::gotoXY(84, 20);
		cout << "Moves:";
		common::gotoXY(86, 21);
		cout << _b->getCountO();
	}
	else
	{
		common::setConsoleColor(BRIGHT_WHITE, GRAY);
		menu::printRectangle(69, 1, 33, 10);
		menu::printBoard(69, 14, 34, 10, LIGHT_RED);
		common::setConsoleColor(BRIGHT_WHITE, GRAY);
		menu::printBigX(66, 2, GRAY, BRIGHT_WHITE);
		common::gotoXY(86 - _p1Name.length() / 2, 4);
		cout << _p1Name;
		common::gotoXY(80, 5);
		cout << "Winning Ratio:";
		string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
		common::gotoXY(86 - score1.find('/'), 6);
		cout << score1;
		common::gotoXY(84, 7);
		cout << "Moves:";
		common::gotoXY(86, 8);
		cout << _b->getCountX();
		common::gotoXY(82, 16);
		menu::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
		common::gotoXY(86 - _p2Name.length() / 2, 17);
		cout << _p2Name;
		common::gotoXY(80, 18);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		cout << "Winning Ratio:";
		string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
		common::gotoXY(86 - score2.find('/'), 19);
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		cout << score2;
		common::gotoXY(84, 20);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		cout << "Moves:";
		common::gotoXY(86, 21);
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		cout << _b->getCountO();
	}
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	menu::printRectangle(69, 27, 14, 2);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	menu::printRectangle(88, 27, 14, 2);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(73, 28);
	cout << "SAVE (P)";
	common::gotoXY(91, 28);
	cout << "BACK (ESC)";
	if(!_turn) common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
	else common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
}

void gameplay::moveToDirection(int x, int y)
{
	while (_x < x)
	{
		Sleep(300);
		moveRight();
	}
	while (_x > x)
	{
		Sleep(300);
		moveLeft();
	}
	while (_y < y)
	{
		Sleep(300);
		moveDown();
	}
	while (_y > y)
	{
		Sleep(300);
		moveUp();
	}
}

void gameplay::setUpGame(int mode, string fileName)
{
	if (mode == 3)
	{
		string fullPath = "load\\" + fileName + ".txt";
		ifstream inFile(fullPath);
		getline(inFile, _dt);
		getline(inFile, _p1Name);
		getline(inFile, _p2Name);
		inFile >> _mode;
		inFile >> _countRounds;
		inFile >> _countP1Wins;
		inFile >> _countP2Wins;
		inFile >> _finish;
		if (!_finish)
		{
			_loadSymbols = true;
			_b->loadBoard(inFile);
		}
		else
		{
			_b->resetData();
		}
		inFile.close();
	}
	else
	{
		common::setConsoleColor(BRIGHT_WHITE, GRAY);
		common::clearConsole();
		menu::printLogo();
		menu::printBigO(5, 11, LIGHT_BLUE, BRIGHT_WHITE);
		menu::printBigX(93, 2, LIGHT_RED, BRIGHT_WHITE);
		_mode = mode;
		menu::printBoard(22, 19, 68, 6, BLACK);
		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(37, 19);
		cout << "  ENTER NAME (UNDER 15 CHARACTERS)  ";
		if (_mode == 0)
		{
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			common::gotoXY(27, 21);
			cout << "X player's:  ";
			common::gotoXY(28, 23);
			common::showCursor(true);
			getline(cin, _p1Name);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			common::gotoXY(74, 21);
			cout << "O player's:  ";
			common::gotoXY(75, 23);
			getline(cin, _p2Name);
			common::showCursor(false);
		}
		else
		{
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			common::gotoXY(27, 21);
			cout << "X player's:  ";
			common::gotoXY(28, 23);
			common::showCursor(true);
			getline(cin, _p1Name);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			common::gotoXY(74, 21);
			cout << "O player's:  ";
			common::gotoXY(75, 23);
			common::showCursor(false);
			cout << "Computer";
			Sleep(500);
			common::gotoXY(75, 23);
			cout << "        ";
			Sleep(500);
			common::gotoXY(75, 23);
			cout << "Computer";
			Sleep(500);
			common::gotoXY(75, 23);
			cout << "        ";
			Sleep(500);
			common::gotoXY(75, 23);
			cout << "Computer";
			Sleep(1000);
			_p2Name = "Computer";
		}
		common::showCursor(false);
		_b->resetData();
	}
}

void gameplay::printWinPos()
{
	common::playSound(9);
	gpoint* win = _b->getWinPos();
	int pWhoWin = _b->testBoard(_x, _y);
	int symbol = (_turn) ? 88 : 79;
	for (int i = 1;i <= 2;i++)
	{
		int loop = 7;
		while (loop > -1)
		{
			for (int i = 0; i < 5; i++)
			{
				common::gotoXY(win[i].getX(), win[i].getY());
				common::setConsoleColor(BRIGHT_WHITE, loop);
				putchar(symbol);
				Sleep(50);
			}
			Sleep(100);
			loop--;
		}
	}
	delete[] win;
}

void gameplay::saveData()
{
	auto start = std::chrono::system_clock::now();
	auto legacyStart = std::chrono::system_clock::to_time_t(start);
	char tmBuff[30];
	ctime_s(tmBuff, sizeof(tmBuff), &legacyStart);
	string path;
	if (_countRounds % 2 == 1 && (!_finish || _loop))
	{
		path = "load\\" + _p2Name + "-" + _p1Name + ".txt";
	}
	else
	{
		path = "load\\" + _p1Name + "-" + _p2Name + ".txt";
	}
	ofstream outFile(path);
	outFile << tmBuff;
	outFile << _p1Name << endl;
	outFile << _p2Name << endl;
	outFile << _mode << endl;
	outFile << _countRounds << endl;
	outFile << _countP1Wins << endl;
	outFile << _countP2Wins << endl;
	outFile << _finish << endl;
	if (!_finish)
	{
		_b->saveBoard(outFile);
	}
	outFile.close();
}

void gameplay::printLoadedSymbols()
{
	for (int i = 0; i < _b->getSize(); i++)
	{
		for (int j = 0; j < _b->getSize(); j++)
		{
			_x = _b->getXAt(i, j);
			_y = _b->getYAt(i, j);
			common::gotoXY(_x, _y);
			int c = _b->getCheckAtXY(_x, _y);
			if (c == 1)
			{
				common::setConsoleColor(BRIGHT_WHITE, BLUE);
				putchar(88);
			}
			else if (c == -1)
			{
				common::setConsoleColor(BRIGHT_WHITE, RED);
				putchar(79);
			}
		}
	}
	if (_b->getCountX() > _b->getCountO())
	{
		common::setConsoleColor(BRIGHT_WHITE, RED);
		_turn = 0;
	}
	else
	{
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		_turn = 1;
	}
}

void gameplay::askContinue()
{
	/*common::gotoXY(38, 21);
	common::setConsoleColor(BRIGHT_WHITE, GREEN);
	cout << "Do you want to play another round?";
	string str[2] = { "Yes", "No" };
	int left[] = { 38,42,48,61,65,70 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 24;*/
	common::showCursor(false);
	common::clearConsole();
	continueBackground();
	menu::printBoard(32, 8, 44, 9, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(47, 11);
	cout << " DO YOU WANT TO ";
	common::gotoXY(45, 12);
	cout << " PLAY ANOTHER ROUND? ";
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
	while (true)
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
				_b->resetData();
				_loop = 1;
				_changeTurn = 1;
			}
			else
			{
				common::clearConsole();
				_loop = 0;
			}
			return;
		}
		else
		{
			common::playSound(4);
		}
	}
}

void gameplay::printPlayerWin(int pWhoWin)
{
	string playerName;
	if (pWhoWin == -1)
	{
		playerName = _p2Name;
	}
	else playerName = _p1Name;
	common::playSound(6);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	unsigned char win[] = {
		32 , 32 , 32 ,176, 219, 219, 187, 176, 176, 176, 176, 176, 176, 176, 219, 219, 187, 219, 219, 187, 219, 219, 219, 187, 176, 176, 219, 219, 187, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 219, 219, 186, 176, 176, 219, 219, 187, 176, 176, 219, 219, 186, 219, 219, 186, 219, 219, 219, 219, 187, 176, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 200, 219, 219, 187, 219, 219, 219, 219, 187, 219, 219, 201, 188, 219, 219, 186, 219, 219, 201, 219, 219, 187, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 176, 219, 219, 219, 219, 201, 205, 219, 219, 219, 219, 186, 176, 219, 219, 186, 219, 219, 186, 200, 219, 219, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 176, 200, 219, 219, 201, 188, 176, 200, 219, 219, 201, 188, 176, 219, 219, 186, 219, 219, 186, 176, 200, 219, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 188, 176, 176, 200, 205, 188, 200, 205, 188, 176, 176, 200, 205, 205, 188, 32 , 32 , 32 , 32 ,
	};
	int top = 6, num_char = 33, count = 0;
	int color[] = { RED, YELLOW, GREEN, AQUA, BLUE, PURPLE };
	common::gotoXY(53 - playerName.size() / 2, 10);
	cout << playerName;
	Sleep(500);
	for (int i = 1;i <= 3;i++)
	{
		count = 0;
		while (count++ < 5)
		{

			common::setConsoleColor(BRIGHT_WHITE, color[count]);
			for (int i = 0; i < 6; i++)
			{
				common::gotoXY(37, i + top + 7);
				for (int j = 0; j < num_char; j++)
				{
					putchar(win[i * num_char + j]);
				}
			}
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				common::gotoXY(37, i + top + 7);
				for (int j = 0; j < num_char; j++)
				{
					putchar(32);
				}
			}
			Sleep(50);
		}
	}
}

void gameplay::printBotWin()
{
	common::playSound(7);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	unsigned char Bot_1[] = {
		176, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 219, 219, 219, 187, 176, 219, 219, 219, 187, 176, 176, 176, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 176, 219, 219, 187, 176, 176, 176, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 176,
		219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 219, 219, 187, 176, 219, 219, 219, 219, 186, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 186, 176, 176, 176, 219, 219, 186, 200, 205, 205, 219, 219, 201, 205, 205, 188, 219, 219, 201, 205, 205, 205, 205, 188, 219, 219, 201, 205, 205, 219, 219, 187,
		219, 219, 186, 176, 176, 200, 205, 188, 219, 219, 186, 176, 176, 219, 219, 186, 219, 219, 201, 219, 219, 219, 219, 201, 219, 219, 186, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 219, 219, 219, 219, 201, 188,
		219, 219, 186, 176, 176, 219, 219, 187, 219, 219, 186, 176, 176, 219, 219, 186, 219, 219, 186, 200, 219, 219, 201, 188, 219, 219, 186, 219, 219, 201, 205, 205, 205, 188, 176, 219, 219, 186, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 201, 205, 205, 188, 176, 176, 219, 219, 201, 205, 205, 219, 219, 187,
		200, 219, 219, 219, 219, 219, 201, 188, 200, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 176, 200, 205, 188, 176, 219, 219, 186, 219, 219, 186, 176, 176, 176, 176, 176, 200, 219, 219, 219, 219, 219, 219, 201, 188, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 186, 176, 176, 219, 219, 186,
		176, 200, 205, 205, 205, 205, 188, 176, 176, 200, 205, 205, 205, 205, 188, 176, 200, 205, 188, 176, 176, 176, 176, 176, 200, 205, 188, 200, 205, 188, 176, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 188, 176, 176, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 188, 176, 176, 200, 205, 188,

	};
	unsigned char Bot_2[] = {
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 219, 219, 187, 176, 176, 176, 176, 176, 176, 176, 219, 219, 187, 219, 219, 187, 219, 219, 219, 187, 176, 176, 219, 219, 187, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 219, 219, 186, 176, 176, 219, 219, 187, 176, 176, 219, 219, 186, 219, 219, 186, 219, 219, 219, 219, 187, 176, 219, 219, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 200, 219, 219, 187, 219, 219, 219, 219, 187, 219, 219, 201, 188, 219, 219, 186, 219, 219, 201, 219, 219, 187, 219, 219, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 219, 219, 219, 219, 201, 205, 219, 219, 219, 219, 186, 176, 219, 219, 186, 219, 219, 186, 200, 219, 219, 219, 219, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 200, 219, 219, 201, 188, 176, 200, 219, 219, 201, 188, 176, 219, 219, 186, 219, 219, 186, 176, 200, 219, 219, 219, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 176, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 188, 176, 176, 200, 205, 188, 200, 205, 188, 176, 176, 200, 205, 205, 188, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32
	};
	int top = 6, num_char = 69, count = 0;
	int color[] = { BRIGHT_WHITE, BLACK, BRIGHT_WHITE, BLUE, BRIGHT_WHITE, GREEN, BRIGHT_WHITE, PURPLE };
	while (count++ < 7)
	{
		common::setConsoleColor(BRIGHT_WHITE, color[count]);
		for (int i = 0; i < 6; i++)
		{
			common::gotoXY(20, i + top);
			for (int j = 0; j < num_char; j++)
			{
				putchar(Bot_1[i * num_char + j]);
			}
			common::gotoXY(20, i + top + 7);
			for (int j = 0; j < num_char; j++)
			{
				putchar(Bot_2[i * num_char + j]);
			}
			Sleep(100);
		}
		Sleep(900);
	}
}

void gameplay::printDraw()
{
	common::playSound(6);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	unsigned char Draw_1[] = {
		219, 219, 219, 219, 219, 219, 187, 176, 32, 32, 219, 219, 219, 219, 219, 219, 187, 176, 219, 219, 187, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 187, 176, 219, 219, 187, 176, 176, 176, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 187, 176,
		200, 205, 205, 205, 205, 219, 219, 187, 32, 32, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 186, 176, 176, 176, 176, 176, 219, 219, 201, 205, 205, 219, 219, 187, 200, 219, 219, 187, 176, 219, 219, 201, 188, 219, 219, 201, 205, 205, 205, 205, 188, 219, 219, 201, 205, 205, 219, 219, 187,
		176, 176, 219, 219, 219, 201, 205, 188, 32, 32, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 186, 176, 200, 219, 219, 219, 219, 201, 188, 176, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 219, 219, 219, 219, 201, 188,
		219, 219, 201, 205, 205, 188, 176, 176, 32, 32, 219, 219, 201, 205, 205, 205, 188, 176, 219, 219, 186, 176, 176, 176, 176, 176, 219, 219, 201, 205, 205, 219, 219, 186, 176, 176, 200, 219, 219, 201, 188, 176, 176, 219, 219, 201, 205, 205, 188, 176, 176, 219, 219, 201, 205, 205, 219, 219, 187,
		219, 219, 219, 219, 219, 219, 219, 187, 32, 32, 219, 219, 186, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 186, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 186, 176, 176, 219, 219, 186,
		200, 205, 205, 205, 205, 205, 205, 188, 32, 32, 200, 205, 188, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 188, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 188, 176, 176, 200, 205, 188,
	};
	unsigned char Draw_2[] = {
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 187, 176, 219, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 187, 176, 176, 176, 176, 176, 176, 176, 219, 219, 187, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 187, 176, 219, 219, 186, 176, 176, 219, 219, 187, 176, 176, 219, 219, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 186, 176, 176, 219, 219, 186, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 219, 219, 219, 219, 219, 186, 176, 200, 219, 219, 187, 219, 219, 219, 219, 187, 219, 219, 201, 188, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 186, 176, 176, 219, 219, 186, 219, 219, 201, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 219, 219, 186, 176, 176, 219, 219, 219, 219, 201, 205, 219, 219, 219, 219, 186, 176, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 186, 176, 176, 219, 219, 186, 219, 219, 186, 176, 176, 219, 219, 186, 176, 176, 200, 219, 219, 201, 188, 176, 200, 219, 219, 201, 188, 176, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 200, 205, 205, 205, 205, 205, 188, 176, 200, 205, 188, 176, 176, 200, 205, 188, 200, 205, 188, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 188, 176, 176, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32
	};
	int top = 6, num_char = 59, count = 0;
	int color[] = { BRIGHT_WHITE, BLACK, BRIGHT_WHITE, BLUE, BRIGHT_WHITE, GREEN, BRIGHT_WHITE, PURPLE };
	while (count++ < 7)
	{
		common::setConsoleColor(BRIGHT_WHITE, color[count]);
		for (int i = 0; i < 6; i++)
		{
			common::gotoXY(24, i + top);
			for (int j = 0; j < num_char; j++)
			{
				putchar(Draw_1[i * num_char + j]);
			}
			common::gotoXY(24, i + top + 7);
			for (int j = 0; j < num_char; j++)
			{
				putchar(Draw_2[i * num_char + j]);
			}
			Sleep(100);
		}
		Sleep(300);
	}
}

void gameplay::saveBoxScreen()
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
	menu::printBoard(32, 8, 44, 9, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(44, 11);
	cout << " DO YOU WANT TO SAVE? ";
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
				saveData();
				common::clearConsole();
				return;
			}
			else 
			{
				common::clearConsole();
				menu::loadingBar();
				common::clearConsole();
				return;
			}
		}
		else
		{
			//common::playSound(4);
		}
	}

}

void gameplay::exitGameScreen() {
	common::showCursor(false);
	common::clearConsole();
	menu::printScene();
	menu::printBoard(32, 8, 44, 9, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(44, 11);
	cout << " DO YOU WANT TO EXIT ";
	common::gotoXY(45, 12);
	cout <<  " YOUR CURRENT GAME? ";
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
				menu::mainScreen();
			}
			else 
			{
				common::clearConsole();
				menu::loadingBar();
				common::clearConsole();
				return;
			}
		}
		else
		{
			//common::playSound(4);
		}
	}
}

void gameplay::printYouWin()
{
	common::playSound(6);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	unsigned char you[] = {
		176, 219, 219, 187, 176, 176, 176, 176, 176, 219, 219, 187, 176, 219, 219, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 187, 176, 176, 176, 176, 219, 219, 187,
		176, 200, 219, 219, 187, 176, 176, 176, 219, 219, 201, 188, 219, 219, 201, 205, 205, 205, 205, 219, 219, 187, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186,
		176, 176, 200, 219, 219, 219, 219, 219, 219, 201, 188, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186,
		176, 176, 176, 176, 200, 219, 219, 201, 205, 188, 176, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186,
		176, 176, 176, 176, 176, 219, 219, 186, 176, 176, 176, 176, 200, 219, 219, 219, 219, 219, 219, 219, 201, 188, 176, 200, 219, 219, 219, 219, 219, 219, 219, 201, 188,
		176, 176, 176, 176, 176, 200, 205, 188, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 32
	};
	unsigned char win[] = {
		32 , 32 , 32 ,176, 219, 219, 187, 176, 176, 176, 176, 176, 176, 176, 219, 219, 187, 219, 219, 187, 219, 219, 219, 187, 176, 176, 219, 219, 187, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 219, 219, 186, 176, 176, 219, 219, 187, 176, 176, 219, 219, 186, 219, 219, 186, 219, 219, 219, 219, 187, 176, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 200, 219, 219, 187, 219, 219, 219, 219, 187, 219, 219, 201, 188, 219, 219, 186, 219, 219, 201, 219, 219, 187, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 176, 219, 219, 219, 219, 201, 205, 219, 219, 219, 219, 186, 176, 219, 219, 186, 219, 219, 186, 200, 219, 219, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 176, 200, 219, 219, 201, 188, 176, 200, 219, 219, 201, 188, 176, 219, 219, 186, 219, 219, 186, 176, 200, 219, 219, 219, 186, 32 , 32 , 32 , 32 ,
		32 , 32 , 32 ,176, 176, 176, 200, 205, 188, 176, 176, 176, 200, 205, 188, 176, 176, 200, 205, 188, 200, 205, 188, 176, 176, 200, 205, 205, 188, 32 , 32 , 32 , 32 ,
	};
	int top = 6, num_char = 33, count = 0;
	int color[] = { RED, YELLOW, GREEN, AQUA, BLUE, PURPLE};
	for (int i = 0; i < 6; i++)
	{
		common::gotoXY(37, i + top);
		for (int j = 0; j < num_char; j++)
		{
			putchar(you[i * num_char + j]);
		}
	}
	Sleep(500);
	for(int i=1;i<=3;i++)
	{
		count = 0;
		while (count++ < 5)
		{

			common::setConsoleColor(BRIGHT_WHITE, color[count]);
			for (int i = 0; i < 6; i++)
			{
				common::gotoXY(37, i + top + 7);
				for (int j = 0; j < num_char; j++)
				{
					putchar(win[i * num_char + j]);
				}
			}
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				common::gotoXY(37, i + top + 7);
				for (int j = 0; j < num_char; j++)
				{
					putchar(32);
				}
			}
			Sleep(50);
		}
	}
}

void gameplay::printYouLose()
{
	common::playSound(6);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	unsigned char you[] = {
		176, 219, 219, 187, 176, 176, 176, 176, 176, 219, 219, 187, 176, 219, 219, 219, 219, 219, 219, 219, 187, 176, 176, 219, 219, 187, 176, 176, 176, 176, 219, 219, 187, 32 ,
		176, 200, 219, 219, 187, 176, 176, 176, 219, 219, 201, 188, 219, 219, 201, 205, 205, 205, 205, 219, 219, 187, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 32 ,
		176, 176, 200, 219, 219, 219, 219, 219, 219, 201, 188, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 32 ,
		176, 176, 176, 176, 200, 219, 219, 201, 205, 188, 176, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 176, 219, 219, 186, 176, 176, 176, 176, 219, 219, 186, 32 ,
		176, 176, 176, 176, 176, 219, 219, 186, 176, 176, 176, 176, 200, 219, 219, 219, 219, 219, 219, 219, 201, 188, 176, 200, 219, 219, 219, 219, 219, 219, 219, 201, 188, 32 ,
		176, 176, 176, 176, 176, 200, 205, 188, 176, 176, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 176, 176, 176, 200, 205, 205, 205, 205, 205, 205, 188, 32 , 32 ,
	};
	unsigned char lose[] = {
		176, 219, 219, 187, 176, 176, 176, 176, 176, 176, 219, 219, 219, 219, 219, 219, 187, 176, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 219, 219, 187,
		176, 219, 219, 187, 176, 176, 176, 176, 176, 219, 219, 201, 205, 205, 205, 219, 219, 187, 219, 219, 201, 205, 205, 205, 205, 188, 219, 219, 201, 205, 205, 205, 205, 188,
		176, 219, 219, 187, 176, 176, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 186, 219, 219, 219, 219, 219, 219, 219, 187, 219, 219, 219, 219, 219, 187, 176, 176,
	    176, 219, 219, 187, 176, 176, 176, 176, 176, 219, 219, 186, 176, 176, 176, 219, 219, 186, 200, 205, 205, 205, 205, 219, 219, 186, 219, 219, 201, 205, 205, 199, 176, 176,
		176, 219, 219, 219, 219, 219, 219, 219, 187, 200, 219, 219, 219, 219, 219, 219, 201, 188, 219, 219, 219, 219, 219, 219, 219, 186, 219, 219, 219, 219, 219, 219, 219, 187,
		176, 200, 205, 205, 205, 205, 205, 205, 188, 176, 200, 205, 205, 205, 205, 205, 188, 176, 200, 205, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 205, 188,
	};
	int top = 6, num_char = 34, count = 0;
	int color[] = { RED, YELLOW, GREEN, AQUA, BLUE, PURPLE };
	for (int i = 0; i < 6; i++)
	{
		common::gotoXY(37, i + top);
		for (int j = 0; j < num_char; j++)
		{
			putchar(you[i * num_char + j]);
		}
	}
	Sleep(500);
	for (int i = 1;i <= 3;i++)
	{
		count = 0;
		while (count++ < 5)
		{

			common::setConsoleColor(BRIGHT_WHITE, color[count]);
			for (int i = 0; i < 6; i++)
			{
				common::gotoXY(37, i + top + 7);
				for (int j = 0; j < num_char; j++)
				{
					putchar(lose[i * num_char + j]);
				}
			}
			Sleep(300);
			for (int i = 0; i < 6; i++)
			{
				common::gotoXY(37, i + top + 7);
				for (int j = 0; j < num_char; j++)
				{
					putchar(32);
				}
			}
			Sleep(50);
		}
	}
}


void gameplay::continueBackground()
{
	common::setConsoleColor(RED, BLACK);
	for (int i = 0; i < 105; i++) {
		common::gotoXY(i, 13);
		putchar(223);
	}

	common::setColor(1);
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 105; j++) {
			common::gotoXY(j, i);
			putchar(219);
		}
	}

	common::setColor(4);
	for (int i = 14; i < 28; i++) {
		for (int j = 0; j < 105; j++) {
			common::gotoXY(j, i);
			putchar(219);
		}
	}

	menu::printBigX(84, 23, BLACK, RED);
	menu::printBigO(16, 23, BLACK, RED);

	common::setColor(0);
	for (int i = 28; i < 31; i++) {
		for (int j = 0; j < 105; j++) {
			common::gotoXY(j, i);
			putchar(219);
		}
	}

	// Vẽ sân boxing
	for (int i = 23; i < 29; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(j, i);
			putchar(219);
		}
	}
	for (int i = 23; i < 29; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(j + 102, i);
			putchar(219);
		}
	}
	for (int i = 3; i < 102; i++) {
		common::gotoXY(i, 24);
		putchar(223);
	}
	for (int i = 3; i < 102; i++) {
		common::gotoXY(i, 26);
		putchar(223);
	}

	// Vẽ đèn chiếu của sân
	for(int k=1;k<=3;k++)
	{
		for (int i = 0; i < 7; i++) {
			common::setColor(i + 9);
			common::gotoXY(0, 22);
			putchar(219);
			common::gotoXY(1, 22);
			putchar(219);
			common::gotoXY(103, 22);
			putchar(219);
			common::gotoXY(104, 22);
			putchar(219);
			Sleep(200);
		}
	}

	common::setColor(15);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 44; j++) {
			common::gotoXY(32 + j, 8 + i);
			putchar(219);
		}
	}
}
