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
		int input = 0, _P1hour = 0, _P1minute = 1, _P1second = 30, _P1ms = 0, _P2hour = 0, _P2minute = 1, _P2second = 30, _P2ms = 0, _Bothour = 0, _Botminute = 1, _Botsecond = 20, _Botms = 0;
		while (!_finish && !pause)
		{
			if (_mode == 0 || (_turn == 1 && _countRounds % 2 == 0) || (_turn == 0 && _countRounds % 2 == 1))
			{
				if (_turn == 1) {
					if (_mode == 0) time::printData(89, 20, _P2hour, _P2minute, _P2second, GRAY);
					else time::printData(89, 20, _Bothour, _Botminute, _Botsecond, GRAY);
					// time::stayTime(80, 9, _P1hour, _P1minute, _P1second, _P1ms, LIGHT_BLUE);
					time::counter(89, 7, _P1hour, _P1minute, _P1second, _P1ms, input, LIGHT_BLUE);
					input = common::getConsoleInput();
					switch (input)
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
				else if (_turn == 0 && _mode == 0) {
					time::printData(89, 7, _P1hour, _P1minute, _P1second, GRAY);
					// time::stayTime(80, 16, _P2hour, _P2minute, _P2second, _P1ms, LIGHT_RED);
					time::counter(89, 20, _P2hour, _P2minute, _P2second, _P2ms, input, LIGHT_RED);
					input = common::getConsoleInput();
					switch (input)
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
			}
			else
			{
				time::printData(89, 7, _P1hour, _P1minute, _P1second, GRAY);
				gpoint p = (_mode == 1) ? _b->PVC_easy() : _b->PVC_hard();
				moveToDirection(p.getX(), p.getY(), _Bothour, _Botminute, _Botsecond, _Botms);
				processCheckBoard();
			}
		}
		if (pause)
			continue;
		_countRounds++;
		askContinue();
		if (_loop)
		{
			swap(_p1pos, _p2pos);
			swap(_p1Name, _p2Name);
			swap(_countP1Wins, _countP2Wins);
		}
	}
	saveData();
}

void gameplay::processCheckBoard()
{
	int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
	int c = _b->checkBoard(_x, _y, _turn);
	if (c == -1 || c == 1)
	{
		//common::playSound(3);
		common::gotoXY(_x, _y);
		if (c == 1)
		{
			common::setConsoleColor(BRIGHT_WHITE, BLUE);
			putchar(88);
			common::gotoXY(86, 6); 
			cout << _b->getCountX();
		}
		else
		{
			common::setConsoleColor(BRIGHT_WHITE, RED);
			putchar(79);
			common::gotoXY(86, 19); 
			cout << _b->getCountO();
		}
		int result = processFinish();
		if (result == 2)
		{
			if (_mode == 0)
			{
				int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
				if (_turn)
				{
					draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printRectangle(69, 14, 33, 10);
					draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
					common::gotoXY(86 - _p1Name.length() / 2, 3);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					cout << _p1Name;
					common::gotoXY(78, 5);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Winning Ratio:";
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score1.find('/'), 5);
					cout << score1;
					common::gotoXY(78, 6);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Moves:";
					common::gotoXY(78, 7);
					cout << "Time left:";
					common::gotoXY(86, 6);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					cout << _b->getCountX();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
					else
						avatar::leftAmongUsHead(89, _p1pos, WHITE);

					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					common::gotoXY(82, 16);
					draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
					common::gotoXY(86 - _p2Name.length() / 2, 16);
					cout << _p2Name;
					common::gotoXY(78, 18);
					cout << "Winning Ratio:";
					string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score2.find('/'), 18);
					cout << score2;
					common::gotoXY(78, 19);
					cout << "Moves:";
					common::gotoXY(78, 20);
					cout << "Time left:";
					common::gotoXY(86, 19);
					cout << _b->getCountO();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p2pos, WHITE);
					else
						avatar::leftAmongUsHead(89, _p2pos, col[_cp2]);
				}
				else
				{
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printRectangle(69, 1, 33, 10);
					draw::printBoard(69, 14, 34, 10, LIGHT_RED);
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
					common::gotoXY(86 - _p1Name.length() / 2, 3);
					cout << _p1Name;
					common::gotoXY(78, 5);
					cout << "Winning Ratio:";
					string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score1.find('/'), 5);
					cout << score1;
					common::gotoXY(78, 6);
					cout << "Moves:";
					common::gotoXY(78, 7);
					cout << "Time left:";
					common::gotoXY(86, 6);
					cout << _b->getCountX();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p1pos, WHITE);
					else
						avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);

					common::gotoXY(82, 16);
					draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
					common::gotoXY(86 - _p2Name.length() / 2, 16);
					cout << _p2Name;
					common::gotoXY(78, 18);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Winning Ratio:";
					string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score2.find('/'), 18);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
					cout << score2;
					common::gotoXY(78, 19);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Moves:";
					common::gotoXY(78, 20);
					cout << "Time left:";
					common::gotoXY(86, 19);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
					cout << _b->getCountO();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p2pos, col[_cp2]);
					else
						avatar::leftAmongUsHead(89, _p2pos, WHITE);
				}
			}
			else if (_mode == 1)
			{
				int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
				if (_turn)
				{
					draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printRectangle(69, 14, 33, 10);
					draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
					common::gotoXY(86 - _p1Name.length() / 2, 3);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					cout << _p1Name;
					common::gotoXY(78, 5);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Winning Ratio:";
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score1.find('/'), 5);
					cout << score1;
					common::gotoXY(78, 6);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Moves:";
					common::gotoXY(78, 7);
					cout << "Time left:";
					common::gotoXY(86, 6);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					cout << _b->getCountX();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
					else
						avatar::leftAmongUsHead(89, _p1pos, WHITE);


					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					common::gotoXY(82, 16);
					draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
					common::gotoXY(86 - _p2Name.length() / 2, 16);
					cout << _p2Name;
					common::gotoXY(78, 18);
					cout << "Winning Ratio:";
					string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score2.find('/'), 18);
					cout << score2;
					common::gotoXY(78, 19);
					cout << "Moves:";
					common::gotoXY(78, 20);
					cout << "Time left:";
					common::gotoXY(86, 19);
					cout << _b->getCountO();
					if (_p1pos == 8)
						avatar::BotHead(82, _p2pos, WHITE, GRAY);
					else
						avatar::BotHead(82, _p2pos, BRIGHT_WHITE, LIGHT_BLUE);
				}
				else
				{
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printRectangle(69, 1, 33, 10);
					draw::printBoard(69, 14, 34, 10, LIGHT_RED);
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
					common::gotoXY(86 - _p1Name.length() / 2, 3);
					cout << _p1Name;
					common::gotoXY(78, 5);
					cout << "Winning Ratio:";
					string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score1.find('/'), 5);
					cout << score1;
					common::gotoXY(78, 6);
					cout << "Moves:";
					common::gotoXY(78, 7);
					cout << "Time left:";
					common::gotoXY(86, 6);
					cout << _b->getCountX();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p1pos, WHITE);
					else
						avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
					
					common::gotoXY(82, 16);
					draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
					common::gotoXY(86 - _p2Name.length() / 2, 16);
					cout << _p2Name;
					common::gotoXY(78, 18);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Winning Ratio:";
					string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score2.find('/'), 18);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
					cout << score2;
					common::gotoXY(78, 19);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Moves:";
					common::gotoXY(78, 20);
					cout << "Time left:";
					common::gotoXY(86, 19);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
					cout << _b->getCountO();
					if (_p1pos == 8)
						avatar::BotHead(82, _p2pos, BRIGHT_WHITE, LIGHT_BLUE);
					else
						avatar::BotHead(82, _p2pos, WHITE, GRAY);
				}
			}
			else
			{
				int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
				if (_turn)
				{
					draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printRectangle(69, 14, 33, 10);
					draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
					common::gotoXY(86 - _p1Name.length() / 2, 3);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					cout << _p1Name;
					common::gotoXY(78, 5);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Winning Ratio:";
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score1.find('/'), 5);
					cout << score1;
					common::gotoXY(78, 6);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Moves:";
					common::gotoXY(78, 7);
					cout << "Time left:";
					common::gotoXY(86, 6);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
					cout << _b->getCountX();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
					else
						avatar::leftAmongUsHead(89, _p1pos, WHITE);

					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					common::gotoXY(82, 16);
					draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
					common::gotoXY(86 - _p2Name.length() / 2, 16);
					cout << _p2Name;
					common::gotoXY(78, 18);
					cout << "Winning Ratio:";
					string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score2.find('/'), 18);
					cout << score2;
					common::gotoXY(78, 19);
					cout << "Moves:";
					common::gotoXY(78, 20);
					cout << "Time left:";
					common::gotoXY(86, 19);
					cout << _b->getCountO();
					if (_p1pos == 8)
						avatar::BotHead(82, _p2pos, GRAY, BRIGHT_WHITE);
					else
						avatar::BotHead(82, _p2pos, RED, LIGHT_RED);
				}
				else
				{
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printRectangle(69, 1, 33, 10);
					draw::printBoard(69, 14, 34, 10, LIGHT_RED);
					common::setConsoleColor(BRIGHT_WHITE, GRAY);
					draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
					common::gotoXY(86 - _p1Name.length() / 2, 3);
					cout << _p1Name;
					common::gotoXY(78, 5);
					cout << "Winning Ratio:";
					string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score1.find('/'), 5);
					cout << score1;
					common::gotoXY(78, 6);
					cout << "Moves:";
					common::gotoXY(78, 7);
					cout << "Time left:";
					common::gotoXY(86, 6);
					cout << _b->getCountX();
					if (_p1pos == 8)
						avatar::leftAmongUsHead(89, _p1pos, WHITE);
					else
						avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);

					common::gotoXY(82, 16);
					draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
					common::gotoXY(86 - _p2Name.length() / 2, 16);
					cout << _p2Name;
					common::gotoXY(78, 18);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Winning Ratio:";
					string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
					common::gotoXY(94 - score2.find('/'), 18);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
					cout << score2;
					common::gotoXY(78, 19);
					common::setConsoleColor(BRIGHT_WHITE, BLACK);
					cout << "Moves:";
					common::gotoXY(78, 20);
					cout << "Time left:";
					common::gotoXY(86, 19);
					common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
					cout << _b->getCountO();
					if (_p1pos == 8)
						avatar::BotHead(82, _p2pos, RED, LIGHT_RED);
					else
						avatar::BotHead(82, _p2pos, GRAY, BRIGHT_WHITE);
		
				}
			}
			/*int color[] = { RED, BLUE }, pos[] = { 22,9 };
			if (_turn)
			{
				draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				draw::printRectangle(69, 14, 33, 10);
				draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
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
				avatar::leftAmongUsHead(89, 8, col[_cp1]);

				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				common::gotoXY(82, 16);
				draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
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
				avatar::leftAmongUsHead(89, 21, WHITE);
			}
			else
			{
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				draw::printRectangle(69, 1, 33, 10);
				draw::printBoard(69, 14, 34, 10, LIGHT_RED);
				common::setConsoleColor(BRIGHT_WHITE, GRAY);
				draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
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
				avatar::leftAmongUsHead(89, 8, WHITE);

				common::gotoXY(82, 16);
				draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
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
				avatar::leftAmongUsHead(89, 21, col[_cp2]);
			}
			common::gotoXY(_x, _y);
			_showCursor = true;
			common::showCursor(_showCursor);*/
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
				printBotWin();
				// printYouLose();
			break;
		case 1:
			_finish = 1;
			_countP1Wins++;
			printWinPos();
			if (_p1Name != "Computer")
				printYouWin();
			else
				printBotWin();
				// printYouLose();
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
	if (_mode == 0)
	{
		int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		_b->drawBoard();
		if (_loadSymbols)
		{
			printLoadedSymbols();
			_loadSymbols = 0;
		}
		if (_turn)
		{
			draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printRectangle(69, 14, 33, 10);
			draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
			common::gotoXY(86 - _p1Name.length() / 2, 3);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			cout << _p1Name;
			common::gotoXY(78, 5);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Winning Ratio:";
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score1.find('/'), 5);
			cout << score1;
			common::gotoXY(78, 6);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Moves:";
			common::gotoXY(78, 7);
			cout << "Time left:";
			common::gotoXY(86, 6);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			cout << _b->getCountX();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
			else
				avatar::leftAmongUsHead(89, _p1pos, WHITE);

			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			common::gotoXY(82, 16);
			draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
			common::gotoXY(86 - _p2Name.length() / 2, 16);
			cout << _p2Name;
			common::gotoXY(78, 18);
			cout << "Winning Ratio:";
			string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score2.find('/'), 18);
			cout << score2;
			common::gotoXY(78, 19);
			cout << "Moves:";
			common::gotoXY(78, 20);
			cout << "Time left:";
			common::gotoXY(86, 19);
			cout << _b->getCountO();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p2pos, WHITE);
			else
				avatar::leftAmongUsHead(89, _p2pos, col[_cp2]);
		}
		else
		{
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printRectangle(69, 1, 33, 10);
			draw::printBoard(69, 14, 34, 10, LIGHT_RED);
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
			common::gotoXY(86 - _p1Name.length() / 2, 3);
			cout << _p1Name;
			common::gotoXY(78, 5);
			cout << "Winning Ratio:";
			string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score1.find('/'), 5);
			cout << score1;
			common::gotoXY(78, 6);
			cout << "Moves:";
			common::gotoXY(78, 7);
			common::gotoXY(86, 6);
			cout << _b->getCountX();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p1pos, WHITE);
			else
				avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);	

			common::gotoXY(82, 16);
			draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
			common::gotoXY(86 - _p2Name.length() / 2, 16);
			cout << _p2Name;
			common::gotoXY(78, 18);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Winning Ratio:";
			string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score2.find('/'), 18);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			cout << score2;
			common::gotoXY(78, 19);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Moves:";
			common::gotoXY(78, 20);
			cout << "Time left:";
			common::gotoXY(86, 19);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			cout << _b->getCountO();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p2pos, col[_cp2]);
			else
				avatar::leftAmongUsHead(89, _p2pos, WHITE);
		}
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		draw::printRectangle(69, 27, 14, 2);
		common::setConsoleColor(BRIGHT_WHITE, RED);
		draw::printRectangle(88, 27, 14, 2);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(73, 28);
		cout << "SAVE (P)";
		common::gotoXY(91, 28);
		cout << "BACK (ESC)";
		if (!_turn) common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		else common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	}
	else if (_mode == 1)
	{
		int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		_b->drawBoard();
		if (_loadSymbols)
		{
			printLoadedSymbols();
			_loadSymbols = 0;
		}
		if (_turn)
		{
			draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printRectangle(69, 14, 33, 10);
			draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
			common::gotoXY(86 - _p1Name.length() / 2, 3);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			cout << _p1Name;
			common::gotoXY(78, 5);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Winning Ratio:";
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score1.find('/'), 5);
			cout << score1;
			common::gotoXY(78, 6);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Moves:";
			common::gotoXY(78, 7);
			cout << "Time left:";
			common::gotoXY(86, 6);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			cout << _b->getCountX();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
			else
				avatar::leftAmongUsHead(89, _p1pos, WHITE);

			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			common::gotoXY(82, 16);
			draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
			common::gotoXY(86 - _p2Name.length() / 2, 16);
			cout << _p2Name;
			common::gotoXY(78, 18);
			cout << "Winning Ratio:";
			string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score2.find('/'), 18);
			cout << score2;
			common::gotoXY(78, 19);
			cout << "Moves:";
			common::gotoXY(78, 20);
			cout << "Time left:";
			common::gotoXY(86, 19);
			cout << _b->getCountO();
			if (_p1pos == 8)
				avatar::BotHead(82, _p2pos, WHITE, GRAY);
			else
				avatar::BotHead(82, _p2pos, BRIGHT_WHITE, LIGHT_BLUE);
		}
		else
		{
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printRectangle(69, 1, 33, 10);
			draw::printBoard(69, 14, 34, 10, LIGHT_RED);
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
			common::gotoXY(86 - _p1Name.length() / 2, 3);
			cout << _p1Name;
			common::gotoXY(78, 5);
			cout << "Winning Ratio:";
			string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score1.find('/'), 5);
			cout << score1;
			common::gotoXY(78, 6);
			cout << "Moves:";
			common::gotoXY(78, 7);
			cout << "Time left:";
			common::gotoXY(86, 6);
			cout << _b->getCountX();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p1pos, WHITE);
			else
				avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);

			common::gotoXY(82, 16);
			draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
			common::gotoXY(86 - _p2Name.length() / 2, 16);
			cout << _p2Name;
			common::gotoXY(78, 18);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Winning Ratio:";
			string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score2.find('/'), 18);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			cout << score2;
			common::gotoXY(78, 19);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Moves:";
			common::gotoXY(78, 20);
			common::gotoXY(86, 19);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			cout << _b->getCountO();
			if (_p1pos == 8)
				avatar::BotHead(82, _p2pos, BRIGHT_WHITE, LIGHT_BLUE);
			else
				avatar::BotHead(82, _p2pos, WHITE, GRAY);
		}
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		draw::printRectangle(69, 27, 14, 2);
		common::setConsoleColor(BRIGHT_WHITE, RED);
		draw::printRectangle(88, 27, 14, 2);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(73, 28);
		cout << "SAVE (P)";
		common::gotoXY(91, 28);
		cout << "BACK (ESC)";
		if (!_turn) common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		else common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
	}
	else
	{
		int col[7] = { 0, LIGHT_RED, LIGHT_BLUE, LIGHT_GREEN, LIGHT_PURPLE, BRIGHT_WHITE, LIGHT_YELLOW };
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		_b->drawBoard();
		if (_loadSymbols)
		{
			printLoadedSymbols();
			_loadSymbols = 0;
		}
		if (_turn)
		{
			draw::printBoard(69, 1, 34, 10, LIGHT_BLUE);
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printRectangle(69, 14, 33, 10);
			draw::printBigX(66, 2, LIGHT_BLUE, BRIGHT_WHITE);
			common::gotoXY(86 - _p1Name.length() / 2, 3);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			cout << _p1Name;
			common::gotoXY(78, 5);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Winning Ratio:";
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score1.find('/'), 5);
			cout << score1;
			common::gotoXY(78, 6);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Moves:";
			common::gotoXY(78, 7);
			cout << "Time left:";
			common::gotoXY(86, 6);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
			cout << _b->getCountX();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);
			else
				avatar::leftAmongUsHead(89, _p1pos, WHITE);

			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			common::gotoXY(82, 16);
			draw::printBigO(66, 15, GRAY, BRIGHT_WHITE);
			common::gotoXY(86 - _p2Name.length() / 2, 16);
			cout << _p2Name;
			common::gotoXY(78, 18);
			cout << "Winning Ratio:";
			string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score2.find('/'), 18);
			cout << score2;
			common::gotoXY(78, 19);
			cout << "Moves:";
			common::gotoXY(78, 20);
			cout << "Time left:";
			common::gotoXY(86, 19);
			cout << _b->getCountO();
			if (_p1pos == 8)
				avatar::BotHead(82, _p2pos, GRAY, BRIGHT_WHITE);
			else
				avatar::BotHead(82, _p2pos, RED, LIGHT_RED);
		}
		else
		{
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printRectangle(69, 1, 33, 10);
			draw::printBoard(69, 14, 34, 10, LIGHT_RED);
			common::setConsoleColor(BRIGHT_WHITE, GRAY);
			draw::printBigX(66, 2, GRAY, BRIGHT_WHITE);
			common::gotoXY(86 - _p1Name.length() / 2, 3);
			cout << _p1Name;
			common::gotoXY(78, 5);
			cout << "Winning Ratio:";
			string score1 = to_string(_countP1Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score1.find('/'), 5);
			cout << score1;
			common::gotoXY(78, 6);
			cout << "Moves:";
			common::gotoXY(78, 7);
			cout << "Time left:";
			common::gotoXY(86, 6);
			cout << _b->getCountX();
			if (_p1pos == 8)
				avatar::leftAmongUsHead(89, _p1pos, WHITE);
			else
				avatar::leftAmongUsHead(89, _p1pos, col[_cp1]);

			common::gotoXY(82, 16);
			draw::printBigO(66, 15, LIGHT_RED, BRIGHT_WHITE);
			common::gotoXY(86 - _p2Name.length() / 2, 16);
			cout << _p2Name;
			common::gotoXY(78, 18);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Winning Ratio:";
			string score2 = to_string(_countP2Wins) + "/" + to_string(_countRounds);
			common::gotoXY(94 - score2.find('/'), 18);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			cout << score2;
			common::gotoXY(78, 19);
			common::setConsoleColor(BRIGHT_WHITE, BLACK);
			cout << "Moves:";
			common::gotoXY(78, 20);
			cout << "Time left:";
			common::gotoXY(86, 19);
			common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
			cout << _b->getCountO();
			if (_p1pos == 8)
				avatar::BotHead(82, _p2pos, RED, LIGHT_RED);
			else
				avatar::BotHead(82, _p2pos, GRAY, BRIGHT_WHITE);
		}
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		draw::printRectangle(69, 27, 14, 2);
		common::setConsoleColor(BRIGHT_WHITE, RED);
		draw::printRectangle(88, 27, 14, 2);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(73, 28);
		cout << "SAVE (P)";
		common::gotoXY(91, 28);
		cout << "BACK (ESC)";
		if (!_turn) common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		else common::setConsoleColor(BRIGHT_WHITE, LIGHT_BLUE);
    }
}

void gameplay::moveToDirection(int x, int y, int& hour, int& minute, int& second, int& ms)
{
	int countTime = 0;

	while (_x < x)
	{
		Sleep(250);
		countTime = 1;
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		time::timerForBot(89, 20, hour, minute, second, ms, LIGHT_RED, countTime);
		countTime = 0;
		moveRight();
	}
	while (_x > x)
	{
		Sleep(250);
		countTime = 1;
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		time::timerForBot(89, 20, hour, minute, second, ms, LIGHT_RED, countTime);
		countTime = 0;
		moveLeft();
	}
	while (_y < y)
	{
		Sleep(250);
		countTime = 1;
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		time::timerForBot(89, 20, hour, minute, second, ms, LIGHT_RED, countTime);
		countTime = 0;
		moveDown();
	}
	while (_y > y)
	{
		Sleep(250);
		countTime = 1;
		common::setConsoleColor(BRIGHT_WHITE, LIGHT_RED);
		time::timerForBot(89, 20, hour, minute, second, ms, LIGHT_RED, countTime);
		countTime = 0;
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
		inFile >> _cp1;
		inFile >> _cp2;
		inFile >> _p1pos;
		inFile >> _p2pos;
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
		_p1pos = 8;
		_p2pos = 22;
		common::setConsoleColor(BRIGHT_WHITE, GRAY);
		common::clearConsole();
		draw::printLogo();
		draw::printBigO(5, 11, LIGHT_BLUE, BRIGHT_WHITE);
		draw::printBigX(93, 2, LIGHT_RED, BRIGHT_WHITE);
		_mode = mode;
		draw::printBoard(22, 19, 68, 6, BLACK);
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
		else if (_mode == 1)
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
			_cp2 = 1;
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
			_cp2 = 2;
		}
		common::showCursor(false);
		_b->resetData();
		Sleep(1000);
		chooseAvatarScreen(mode);
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
	outFile << _cp1 << endl;
	outFile << _cp2 << endl;
	outFile << _p1pos << endl;
	outFile << _p2pos << endl;
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
	draw::printBoard(32, 8, 44, 9, BLACK);
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
	common::clearConsole();
	if (pWhoWin == 1) { // player 1 thắng
		draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_BLUE, 1, 0, 0); 
		Sleep(3000);
		draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_RED, 0, 0, 0);
		Sleep(3000);
	}
	else {
		draw::titleEffect(2, 2, _cp2, _cp1, LIGHT_RED, 1, 0, 0);
		Sleep(3000);
		draw::titleEffect(2, 2, _cp2, _cp1, LIGHT_BLUE, 0, 0, 0);
		Sleep(3000);
	}
	common::clearConsole();
}

void gameplay::printBotWin()
{
	common::playSound(7);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	
	draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_RED, 1, 1, _mode);
	Sleep(3000);
	draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_BLUE, 0, 0, _mode);
	Sleep(3000);

	common::clearConsole();
}

void gameplay::printDraw()
{
	common::playSound(6);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();

	int t = 3;
	while (t > 0) {
		draw::printColoredRectangle(3, 0, 24, 30, BRIGHT_WHITE);
		draw::printColoredRectangle(79, 0, 25, 30, BRIGHT_WHITE);
		Sleep(300);

		draw::printColoredRectangle(3, 0, 24, 30, WHITE);
		draw::printColoredRectangle(79, 0, 25, 30, WHITE);
		Sleep(300);

		t--;
	}
	avatar::rightAmongUs(5, 16, LIGHT_RED, RED, WHITE, WHITE);
	avatar::leftAmongUs(82, 16, LIGHT_BLUE, BLUE, WHITE, WHITE);
	// avatar::Bot(77, 16, BRIGHT_WHITE, LIGHT_BLUE, BLUE, WHITE);
	Sleep(100);

	draw::printBoard(28, 9, 49, 19, BLACK);
	draw::printColoredRectangle(25, 1, 56, 8, BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	draw::drawTitle(28, 2);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	draw::resultTitle(42, 10);
	common::setConsoleColor(WHITE, RED);
	common::gotoXY(39, 12); cout << " THE GAME ENDED IN A DRAW ";
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(31, 14); cout << "Player 1's name: ";
	common::gotoXY(31, 16); cout << "Player 2's name: ";
	common::gotoXY(31, 18); cout << "Ratio: ";
	common::gotoXY(31, 20); cout << "Moves: ";
	common::gotoXY(31, 22); cout << "Time left: ";
	common::gotoXY(31, 24); cout << "Mode: ";
	common::gotoXY(31, 26); cout << "Status: "; // hoà
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(45, 29); cout << "To be continued...";

	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(61, 18); putchar(179);
	common::gotoXY(61, 20); putchar(179);
	common::gotoXY(61, 22); putchar(179);
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	common::gotoXY(57, 14); cout << _p1Name;
	common::gotoXY(55, 18); cout << _countP1Wins;
	common::gotoXY(55, 20); cout << "5";
	common::gotoXY(50, 22); cout << "00:00:00";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(57, 16); cout << "NguyenThao";
	common::gotoXY(67, 18); cout << "3";
	common::gotoXY(67, 20); cout << "4";
	common::gotoXY(65, 22); cout << "00:00:00";
	common::setConsoleColor(BRIGHT_WHITE, LIGHT_PURPLE);
	common::gotoXY(60, 24); cout << "PVP";
	common::gotoXY(59, 26); cout << "draw";
}
void gameplay::saveBoxScreen()
{
	common::showCursor(false);
	common::clearConsole();
	draw::rainbowBackground();
	//common::setConsoleColor(BRIGHT_WHITE, BLACK);
	//printRectangle(36, 18, 35, 8);
	//printRectangle(39, 23, 7, 2);
	//printRectangle(62, 23, 6, 2);
	//common::setConsoleColor(BRIGHT_WHITE, RED);
	////printLogo();
	draw::printBoard(32, 8, 44, 9, BLACK);
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
	draw::rainbowBackground();
	draw::printBoard(32, 8, 44, 9, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, PURPLE);
	common::gotoXY(44, 11);
	cout << " DO YOU WANT TO EXIT ";
	common::gotoXY(45, 12);
	cout << " YOUR CURRENT GAME? ";
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

	draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_BLUE, 1, 0, 1);
	Sleep(3000);
	draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_RED, 0, 1, 1);
	Sleep(3000);

	common::clearConsole();
}


void gameplay::printYouLose()
{
	common::playSound(6);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();

	draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_RED, 0, 1, _mode);
	Sleep(3000);
	draw::titleEffect(2, 2, _cp1, _cp2, LIGHT_BLUE, 0, 0, _mode);
	Sleep(3000);

	common::clearConsole();
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

	draw::printBigX(84, 23, BLACK, RED);
	draw::printBigO(16, 23, BLACK, RED);

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
	for (int k = 1;k <= 3;k++)
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

void gameplay::chooseAvatarScreen(int mode)
{
	common::showCursor(false);
	common::clearConsole();

	// Tiêu đề
	draw::printTitleChoose(20, 1);

	// Hàng trên
	common::setColor(0);
	common::gotoXY(14, 4); cout << "No.1";
	draw::printBoard(7, 5, 16, 10, LIGHT_BLUE);
	draw::printColoredRectangle(8, 6, 15, 9, LIGHT_BLUE);
	avatar::rightAmongUs(9, 7, LIGHT_RED, RED, WHITE, BRIGHT_WHITE);
	common::gotoXY(7, 4);
	common::setConsoleColor(LIGHT_BLUE, BRIGHT_WHITE);
	cout << " P1 ";
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
	avatar::rightAmongUs(39, 7, LIGHT_BLUE, BLUE, WHITE, BRIGHT_WHITE);
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
	avatar::rightAmongUs(69, 7, LIGHT_GREEN, GREEN, WHITE, BRIGHT_WHITE);
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
	avatar::rightAmongUs(22, 21, LIGHT_PURPLE, PURPLE, WHITE, BRIGHT_WHITE);
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
	avatar::rightAmongUs(52, 21, BRIGHT_WHITE, WHITE, WHITE, BRIGHT_WHITE);
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
	avatar::rightAmongUs(82, 21, LIGHT_YELLOW, LIGHT_YELLOW, WHITE, BRIGHT_WHITE);
	string yellow = "YELLOW";
	common::setConsoleColor(BRIGHT_WHITE, YELLOW);
	for (int i = 0; i < yellow.size(); i++) {
		common::gotoXY(78, 19 + 2 * i);
		cout << yellow[i];
	}

	if (_mode == 0) {
		// Player 1
		draw::printBoard(91, 10, 11, 1, LIGHT_BLUE);
		common::setColor(0);
		common::gotoXY(93, 10); cout << "PLAYER 1";

		// Player 2
		draw::printBoard(3, 24, 11, 1, LIGHT_RED);
		common::setColor(0);
		common::gotoXY(5, 24); cout << "PLAYER 2";
	}
	else {
		// Hộp Player 
		draw::printBoard(91, 10, 11, 1, LIGHT_BLUE);
		common::setColor(0);
		common::gotoXY(94, 10); cout << "PLAYER";

		// Hộp bot
		draw::printBoard(3, 24, 11, 1, LIGHT_RED);
		common::setColor(0);
		common::gotoXY(8, 24); cout << "BOT";
	}
	//Biến số lựa chọn
	int count = 0;
	//Biến vị trí trỏ ban đầu
	int pos = 1;
	bool chosen[7];
	int wall;
	if (mode == 0) wall = 2;
	else wall = 1;
	memset(chosen, false, sizeof(chosen));
	while (count < wall)
	{
		switch (common::getConsoleInput())
		{
		case 2:
			if (pos > 3)
			{
				if (chosen[pos - 3] == false)
				{
					addFrame(pos - 3, count + 1);
					removeFrame(pos);
					pos -= 3;
				}
			}
			break;
		case 3:
			if (pos != 1)
			{
				if (chosen[pos - 1] == false)
				{
					addFrame(pos - 1, count + 1);
					removeFrame(pos);
					pos -= 1;
				}
			}
			break;
		case 4:
			if (pos != 6)
			{
				if (chosen[pos + 1] == false)
				{
					addFrame(pos + 1, count + 1);
					removeFrame(pos);
					pos += 1;
				}
			}
			break;
		case 5:
			if (pos < 4)
			{
				if (chosen[pos + 3] == false)
				{
					addFrame(pos + 3, count + 1);
					removeFrame(pos);
					pos += 3;
				}
			}
			break;
		case 6:
			if (mode == 0)
			{
				if (count == 0) _cp1 = pos;
				if (count == 1) _cp2 = pos;
			}
			else
			{
				if (count == 0) _cp1 = pos;
			}
			chosen[pos] = true;
			count++;
			if (count == wall)
			{
				Sleep(1500);
			}
			else
			{
				if (pos != 1)
				{
					addFrame(1, count + 1);
					pos = 1;
				}
				else
				{
					addFrame(2, count + 1);
					pos = 2;
				}
			}
			break;
		case 1:
			common::clearConsole();
			return;
			break;
		}
	}
}

void gameplay::addFrame(int no, int p)
{
	int mau[3] = { 0, LIGHT_BLUE, LIGHT_RED };
	int left[7] = { 0, 7, 37, 67, 20, 50, 80 };
	int top[7] = { 0, 5, 5, 5, 19, 19, 19 };
	int col[7] = { 0, RED, BLUE, GREEN, PURPLE, WHITE, YELLOW };
	draw::printBoard(left[no], top[no], 16, 10, mau[p]);
	draw::printColoredRectangle(left[no] + 1, top[no] + 1, 15, 9, mau[p]);
	avatar::rightAmongUs(left[no] + 2, top[no] + 2, col[no] + 8, col[no], mau[p], BRIGHT_WHITE);
	common::gotoXY(left[no], top[no] - 1);
	common::setConsoleColor(mau[p], BRIGHT_WHITE);
	cout << " P" << p << " ";
}

void gameplay::removeFrame(int no)
{
	int left[7] = { 0, 7, 37, 67, 20, 50, 80 };
	int top[7] = { 0, 5, 5, 5, 19, 19, 19 };
	int col[7] = { 0, RED, BLUE, GREEN, PURPLE, WHITE, YELLOW };
	draw::printBoard(left[no], top[no], 16, 10, BLACK);
	draw::printColoredRectangle(left[no] + 1, top[no] + 1, 15, 9, WHITE);
	avatar::rightAmongUs(left[no] + 2, top[no] + 2, col[no] + 8, col[no], WHITE, BRIGHT_WHITE);
	common::gotoXY(left[no], top[no] - 1);
	common::setConsoleColor(BRIGHT_WHITE, BRIGHT_WHITE);
	cout << "     ";
}
