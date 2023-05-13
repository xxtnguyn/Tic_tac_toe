#include "tutorial.h"
#include "board.h"

void tutorial::Intro()
{
	// Vẽ đường ray
	// đường ngang
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 105; i++) {
		common::gotoXY(i, 19); putchar(205);
		common::gotoXY(i, 22); putchar(254);
		common::gotoXY(i, 25); putchar(205);
		Sleep(10);
	}
	// đường dọc
	for (int i = 0; i < 31; i++) {
		common::gotoXY(23, i); putchar(186);
		common::gotoXY(30, i); putchar(219);
		common::gotoXY(37, i); putchar(186);
		Sleep(10);
	}

	draw::printColoredRectangle(9, 16, 44, 12, BLACK);
	draw::printCaroTutorial(20, 17, BRIGHT_WHITE, BLACK);
	draw::printBigX(80, 3, BLACK, BRIGHT_WHITE);
	draw::printBigO(90, 3, BLACK, BRIGHT_WHITE);

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::stepOne()
{
	// Hướng dẫn chơi game
	// In chữ "HOW TO START A GAME"
	unsigned char how_to_start[] = { 219, 32 , 219, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 32 , 32 , 32 , 223, 219, 223, 32 , 219, 223, 219, 32 , 32 , 32 , 219, 223, 32 , 223, 219, 223, 32 , 219, 223, 219, 32 , 219, 223, 219, 32 , 223, 219, 223, 32 , 32 , 32 , 219, 223, 219, 32 , 32 , 32 , 219, 223, 223, 32 , 219, 223, 219, 32 , 219, 220, 32 , 220, 219, 32 , 219, 223, 223,
									 219, 223, 219, 32 , 219, 220, 219, 32 , 223, 254, 223, 254, 223, 32 , 32 , 32 , 32 , 219, 32 , 32 , 219, 220, 219, 32 , 32 , 32 , 220, 219, 32 , 32 , 219, 32 , 32 , 219, 223, 219, 32 , 219, 223, 220, 32 , 32 , 219, 32 , 32 , 32 , 32 , 219, 223, 219, 32 , 32 , 32 , 219, 220, 219, 32 , 219, 223, 219, 32 , 219, 32 , 223, 32 , 219, 32 , 219, 219, 220 };
	int num_chars = 70;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(20 + j, 2 + i);
			putchar(how_to_start[i * num_chars + j]);
		}
	}

	// hiển thị menu cần chọn: NEW GAME
	draw::printBoard(45, 5, 15, 2, BLACK);
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(47, 6); cout << "  NEW GAME  ";
		common::setColor(15);
		common::gotoXY(39, 6); cout << "    ";
		common::gotoXY(63, 6); cout << "    ";
		Sleep(500);

		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(47, 6); cout << "  NEW GAME  ";
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		common::gotoXY(39, 6); cout << ">>>>";
		common::setColor(RED);
		common::gotoXY(63, 6); cout << "<<<<";
		Sleep(500);
	}

	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(26, 9); cout << "After that, you can choose one of three modes below to play.";

	// hiển thị 3 mode bằng bảng
	draw::printBoard(6, 18, 15, 2, BLACK);
	common::gotoXY(8, 19); cout << "     PVP    ";
	draw::printBoard(45, 18, 15, 2, BLACK);
	common::gotoXY(47, 19); cout << " PVE (easy) ";
	draw::printBoard(85, 18, 15, 2, BLACK);
	common::gotoXY(87, 19); cout << " PVE (hard) ";
	Sleep(1000);

	// hiển thị mode game PVP
	draw::printColoredRectangle(45, 18, 59, 3, BRIGHT_WHITE);
	draw::printBoard(6, 18, 15, 2, BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(8, 19); cout << "     PVP    ";
	Sleep(500);
	draw::printColoredRectangle(6, 18, 20, 3, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(7, 12); cout << "This one is for playing with friends";
	common::gotoXY(12, 13); cout << "or your game opponent";
	avatar::rightAmongUs(3, 16, LIGHT_BLUE, BLUE, WHITE);
	draw::printVS(24, 20);
	avatar::leftAmongUs(28, 16, LIGHT_RED, RED, WHITE, WHITE);
	Sleep(1500);
	draw::printColoredRectangle(7, 12, 40, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(3, 16, 50, 10, BRIGHT_WHITE);
	draw::printBoard(6, 18, 15, 2, BLACK);
	common::gotoXY(8, 19); cout << "     PVP    ";
	draw::printBoard(45, 18, 15, 2, BLACK);
	common::gotoXY(47, 19); cout << " PVE (easy) ";
	draw::printBoard(85, 18, 15, 2, BLACK);
	common::gotoXY(87, 19); cout << " PVE (hard) ";
	Sleep(500);

	// hiển thị mode game PVE easy
	draw::printColoredRectangle(6, 18, 20, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(85, 18, 20, 3, BRIGHT_WHITE);
	draw::printBoard(45, 18, 15, 2, BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(47, 19); cout << " PVE (easy) ";
	Sleep(500);
	draw::printColoredRectangle(45, 18, 20, 3, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(36, 12); cout << "This one is for single player";
	common::gotoXY(38, 13); cout << "playing with friendly bot";
	avatar::rightAmongUs(26, 16, LIGHT_BLUE, BLUE, WHITE);
	draw::printVS(47, 20);
	avatar::Bot(51, 16, BRIGHT_WHITE, LIGHT_BLUE, BLUE);
	Sleep(1500);
	draw::printColoredRectangle(36, 12, 40, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(26, 15, 55, 11, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	draw::printBoard(6, 18, 15, 2, BLACK);
	common::gotoXY(8, 19); cout << "     PVP    ";
	draw::printBoard(45, 18, 15, 2, BLACK);
	common::gotoXY(47, 19); cout << " PVE (easy) ";
	draw::printBoard(85, 18, 15, 2, BLACK);
	common::gotoXY(87, 19); cout << " PVE (hard) ";
	Sleep(500);

	// hiển thị mode game PVE hard
	draw::printColoredRectangle(6, 18, 20, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(45, 18, 20, 3, BRIGHT_WHITE);
	draw::printBoard(85, 18, 15, 2, BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(87, 19); cout << " PVE (hard) ";
	Sleep(500);
	draw::printColoredRectangle(85, 18, 20, 3, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(66, 12); cout << "This one is for single player";
	common::gotoXY(65, 13); cout << "playing with extremely angry bot";
	avatar::rightAmongUs(53, 16, LIGHT_BLUE, BLUE, WHITE);
	draw::printVS(74, 20);
	avatar::Bot(78, 16, LIGHT_RED, RED, BLACK);
	Sleep(1500);
	draw::printColoredRectangle(63, 12, 40, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(53, 15, 53, 11, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	draw::printBoard(6, 18, 15, 2, BLACK);
	common::gotoXY(8, 19); cout << "     PVP    ";
	draw::printBoard(45, 18, 15, 2, BLACK);
	common::gotoXY(47, 19); cout << " PVE (easy) ";
	draw::printBoard(85, 18, 15, 2, BLACK);
	common::gotoXY(87, 19); cout << " PVE (hard) ";
	Sleep(500);

	// hiển thị di chuyển
	common::setColor(2);
	draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::stepTwo()
{
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();

	draw::drawBoard();

	draw::boxChatRight(70, 10, 4, 30);

	avatar::leftAmongUs(80, 20, BRIGHT_WHITE, WHITE, BRIGHT_WHITE, WHITE);

	draw::printRule(77, 6);

	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(79, 13); cout << "The game starts";
	common::gotoXY(72, 14); cout << "as soon as the board appears";
	Sleep(1500);
	draw::printColoredRectangle(72, 13, 29, 4, BRIGHT_WHITE);

	// Hướng dẫn di chuyển
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(76, 13); cout << "Use A,W,S,D to move";
	common::gotoXY(72, 14); cout << "and Enter to place your move";
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	common::gotoXY(30, 14); cout << "X";
	common::setConsoleColor(BRIGHT_WHITE, GRAY);
	common::gotoXY(30, 12); cout << "W";
	common::gotoXY(30, 16); cout << "S";
	common::gotoXY(34, 14); cout << "D";
	common::gotoXY(26, 14); cout << "A";
	Sleep(1500);
	draw::printColoredRectangle(68, 10, 35, 10, BRIGHT_WHITE);

	// Hướng dẫn di chuyển W
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(30, 12); cout << "O";
	common::gotoXY(77, 14); cout << "Use W to move up";
	draw::boxChatRight(74, 11, 3, 20);
	Sleep(1500);
	draw::printColoredRectangle(77, 14, 18, 2, BRIGHT_WHITE);

	// Hướng dẫn di chuyển D
	common::setConsoleColor(BRIGHT_WHITE, GRAY);
	common::gotoXY(30, 12); cout << "W";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(34, 14); cout << "O";
	common::gotoXY(75, 14); cout << "Use D to move right";
	Sleep(1500);
	draw::printColoredRectangle(75, 14, 19, 2, BRIGHT_WHITE);

	// Hướng dẫn di chuyển S
	common::setConsoleColor(BRIGHT_WHITE, GRAY);
	common::gotoXY(30, 12); cout << "W";
	common::gotoXY(34, 14); cout << "D";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(30, 16); cout << "O";
	common::gotoXY(76, 14); cout << "Use S to move down";
	Sleep(1500);
	draw::printColoredRectangle(75, 14, 18, 2, BRIGHT_WHITE);

	// Hướng dẫn di chuyển A
	common::setConsoleColor(BRIGHT_WHITE, GRAY);
	common::gotoXY(30, 12); cout << "W";
	common::gotoXY(34, 14); cout << "D";
	common::gotoXY(30, 16); cout << "S";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(26, 14); cout << "O";
	common::gotoXY(76, 14); cout << "Use A to move left";
	Sleep(1500);
	draw::printColoredRectangle(72, 11, 30, 9, BRIGHT_WHITE);

	// Lời dẫn
	draw::boxChatRight(67, 10, 4, 34);
	common::setColor(15);
	common::gotoXY(30, 12); putchar(219);
	common::gotoXY(30, 16); putchar(219);
	common::gotoXY(34, 14); putchar(219);
	common::gotoXY(26, 14); putchar(219);
	common::gotoXY(30, 14); putchar(219);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(67, 13); cout << "To win the game, you have to create";
	common::gotoXY(68, 14); cout << "an unbroken row of five symbols";
	Sleep(1500);
	draw::printColoredRectangle(65, 10, 39, 10, BRIGHT_WHITE);

	// Hướng dẫn thắng hàng dọc
	draw::boxChatRight(67, 11, 3, 35);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(78, 13); cout << "The row can be";
	common::gotoXY(69, 14); cout << "VERTICAL, horizontal, or diagonal";
	common::gotoXY(73, 15); cout << "as long as it is unbroken";
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	common::gotoXY(30, 14); cout << "X";
	common::gotoXY(30, 12); cout << "X";
	common::gotoXY(30, 16); cout << "X";
	common::gotoXY(30, 10); cout << "X";
	common::gotoXY(30, 18); cout << "X";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(30, 20); cout << "O";
	common::gotoXY(34, 14); cout << "O";
	common::gotoXY(30, 6); cout << "O";
	common::gotoXY(26, 12); cout << "O";
	Sleep(2500);

	// Hướng dẫn thắng hàng ngang
	common::setColor(15);
	common::gotoXY(30, 14); putchar(219);
	common::gotoXY(30, 12); putchar(219);
	common::gotoXY(30, 16); putchar(219);
	common::gotoXY(30, 10); putchar(219);
	common::gotoXY(30, 18); putchar(219);
	common::gotoXY(30, 20); putchar(219);
	common::gotoXY(34, 14); putchar(219);
	common::gotoXY(30, 6); putchar(219);
	common::gotoXY(26, 12); putchar(219);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(78, 13); cout << "The row can be";
	common::gotoXY(69, 14); cout << "vertical, HORIZONTAL, or diagonal";
	common::gotoXY(73, 15); cout << "as long as it is unbroken";
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	common::gotoXY(30, 14); cout << "X";
	common::gotoXY(34, 14); cout << "X";
	common::gotoXY(38, 14); cout << "X";
	common::gotoXY(26, 14); cout << "X";
	common::gotoXY(22, 14); cout << "X";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(30, 20); cout << "O";
	common::gotoXY(34, 16); cout << "O";
	common::gotoXY(30, 10); cout << "O";
	common::gotoXY(26, 12); cout << "O";
	Sleep(2500);

	// Hướng dẫn thắng hàng chéo
	common::setColor(15);
	common::gotoXY(30, 14); putchar(219);
	common::gotoXY(34, 14); putchar(219);
	common::gotoXY(38, 14); putchar(219);
	common::gotoXY(26, 14); putchar(219);
	common::gotoXY(22, 14); putchar(219);
	common::gotoXY(30, 20); putchar(219);
	common::gotoXY(34, 16); putchar(219);
	common::gotoXY(30, 10); putchar(219);
	common::gotoXY(26, 12); putchar(219);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(78, 13); cout << "The row can be";
	common::gotoXY(69, 14); cout << "vertical, horizontal, or DIAGONAL";
	common::gotoXY(73, 15); cout << "as long as it is unbroken";
	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	common::gotoXY(30, 14); cout << "X";
	common::gotoXY(34, 12); cout << "X";
	common::gotoXY(38, 10); cout << "X";
	common::gotoXY(26, 16); cout << "X";
	common::gotoXY(22, 18); cout << "X";
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(30, 18); cout << "O";
	common::gotoXY(34, 10); cout << "O";
	common::gotoXY(30, 12); cout << "O";
	common::gotoXY(26, 18); cout << "O";
	Sleep(2500);

	// Lời dẫn "Let's continue"
	common::clearConsole();
	draw::boxChatRight(35, 8, 1, 25);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(40, 10); cout << "Let's continue...";
	avatar::leftAmongUs(48, 15, BRIGHT_WHITE, WHITE, BRIGHT_WHITE, WHITE);


	// hiển thị di chuyển
	common::setColor(2);
	draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::stepThree()
{
	// Hướng dẫn cách save game
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	unsigned char how_to_save[] = { 219, 32 , 219, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 32 , 32 , 32 , 223, 219, 223, 32 , 219, 223, 219, 32 , 32 , 32 , 219, 223, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 223, 223, 32 , 32 , 32 , 219, 223, 219, 32 , 32 , 32 , 219, 223, 223, 32 , 219, 223, 219, 32 , 219, 220, 32 , 220, 219, 32 , 219, 223, 223,
									219, 223, 219, 32 , 219, 220, 219, 32 , 223, 254, 223, 254, 223, 32 , 32 , 32 , 32 , 219, 32 , 32 , 219, 220, 219, 32 , 32 , 32 , 220, 219, 32 , 219, 223, 219, 32 , 223, 254, 223, 32 , 219, 219, 220, 32 , 32 , 32 , 219, 223, 219, 32 , 32 , 32 , 219, 220, 219, 32 , 219, 223, 219, 32 , 219, 32 , 223, 32 , 219, 32 , 219, 219, 220 };
	int num_chars = 66;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(20 + j, 16 + i); putchar(how_to_save[i * num_chars + j]);
		}
	}

	avatar::BotHead(35, 10, BRIGHT_WHITE, BLUE);
	draw::boxChatLeft(58, 5, 1, 8);
	common::gotoXY(61, 7); cout << "How?";
	Sleep(1500);

	common::clearConsole();

	draw::drawBoard();

	string _p1Name = "Thao Nguyen", _p2Name = "Trong Nghia";
	int _countP1Wins = 2, _countP2Wins = 1;
	int _countRounds = 3;
	board* _b = new board(SIZE, LEFT, TOP);
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
	avatar::leftAmongUsHead(89, 8, LIGHT_BLUE);

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

	common::setConsoleColor(BRIGHT_WHITE, BLUE);
	draw::printRectangle(75, 27, 12, 2);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	draw::printRectangle(90, 27, 12, 2);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(78, 28);
	cout << "SAVE (P)";
	common::gotoXY(92, 28);
	cout << "BACK (ESC)";
	draw::musicIconOff(67, 27);
	Sleep(500);

	// Lời dẫn nhấn P
	avatar::rightAmongUs(2, 20, LIGHT_RED, RED, BRIGHT_WHITE);
	draw::printColoredRectangle(11, 11, 33, 7, BRIGHT_WHITE);
	draw::boxChatLeft(12, 11, 4, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(15, 14); cout << "To save your current game,";
	common::gotoXY(16, 15); cout << "press P and confirm YES";
	Sleep(2000);

	// Hiển thị thao tác nhấn P
	for (int i = 0; i < 2; i++) {
		draw::printBoard(75, 27, 13, 2, BLUE);
		draw::printColoredRectangle(76, 28, 12, 1, BLUE);
		common::setConsoleColor(BLUE, BRIGHT_WHITE);
		common::gotoXY(78, 28);
		cout << "SAVE (P)";
		Sleep(500);
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		draw::printColoredRectangle(76, 28, 12, 1, BRIGHT_WHITE);
		common::setColor(BLUE);
		draw::printRectangle(75, 27, 12, 2);
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(78, 28);
		cout << "SAVE (P)";
		Sleep(500);
	}

	// Lời dẫn sang mục Load
	common::clearConsole();
	draw::boxChatRight(30, 8, 1, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(33, 10); cout << "Now we move to Load board";
	avatar::leftAmongUs(48, 15, LIGHT_RED, RED, BRIGHT_WHITE, WHITE);
	Sleep(2000);
	common::clearConsole();
	unsigned char load[] = { 219, 32 , 32 , 32 , 219, 223, 219, 32 , 219, 223, 219, 32 , 219, 223, 220,
							 219, 220, 220, 32 , 219, 220, 219, 32 , 219, 223, 219, 32 , 219, 220, 223, };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 15; j++) {
			common::gotoXY(45 + j, 13 + i); putchar(load[i * 15 + j]);
		}
	}
	draw::printBoard(45, 16, 15, 2, BLACK);
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(47, 17); cout << "    LOAD    ";
		common::setColor(15);
		common::gotoXY(39, 17); cout << "    ";
		common::gotoXY(63, 17); cout << "    ";
		Sleep(500);

		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(47, 17); cout << "    LOAD    ";
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		common::gotoXY(39, 17); cout << ">>>>";
		common::setColor(RED);
		common::gotoXY(63, 17); cout << "<<<<";
		Sleep(500);
	}

	// Hiển thị mục load game
	common::clearConsole();
	draw::printLoadText();
	draw::printLoadBoard(BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(12, 10); cout << " No. ";
	common::gotoXY(20, 10); cout << " X player's name ";
	common::gotoXY(42, 10); cout << " O player's name ";
	common::gotoXY(71, 10); cout << " Date & Time ";
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(14, 12); cout << "1";
	common::setColor(BLUE);
	common::gotoXY(20, 12); cout << "Kim Ngan";
	common::setColor(RED);
	common::gotoXY(42, 12); cout << "Thao Nguyen";
	common::setColor(PURPLE);
	common::gotoXY(66, 12); cout << "Thu Apr 20 01:57::43 2023";
	Sleep(500);
	
	// Lời dẫn mục load
	avatar::leftAmongUs(85, 21, LIGHT_RED, RED, BRIGHT_WHITE, BRIGHT_WHITE);
	draw::printColoredRectangle(63, 16, 34, 4, BRIGHT_WHITE);
	draw::boxChatRight(65, 15, 2, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(74, 17); cout << "This is where";
	common::gotoXY(69, 18); cout << "your game will be saved";
	Sleep(2000);
	draw::printColoredRectangle(61, 15, 40, 7, BRIGHT_WHITE);
	draw::printLoadBoard(BLACK);
	common::setConsoleColor(BLACK, BRIGHT_WHITE);
	common::gotoXY(12, 10); cout << " No. ";
	common::gotoXY(20, 10); cout << " X player's name ";
	common::gotoXY(42, 10); cout << " O player's name ";
	common::gotoXY(71, 10); cout << " Date & Time ";
	avatar::leftAmongUs(85, 21, LIGHT_RED, RED, BRIGHT_WHITE, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(20, 14); cout << "Kim Ngan";
	common::gotoXY(42, 14); cout << "Thao Nguyen";
	common::gotoXY(66, 14); cout << "Thu Apr 20 01:57::43 2023";
	common::gotoXY(14, 12); cout << "1";
	common::gotoXY(14, 14); cout << "2";
	common::setColor(BLUE);
	common::gotoXY(20, 12); cout << "Thao Nguyen";
	common::setColor(RED);
	common::gotoXY(42, 12); cout << "Trong Nghia";
	common::setColor(PURPLE);
	common::gotoXY(66, 12); cout << "Thu Apr 20 01:33::43 2023";
	draw::printColoredRectangle(63, 17, 34, 3, BRIGHT_WHITE);
	draw::boxChatRight(65, 16, 1, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(68, 18); cout << "as well as your next game";
	Sleep(2000);

	// Lời dẫn "Keep going"
	common::clearConsole();
	draw::boxChatRight(35, 8, 1, 25);
	avatar::leftAmongUs(48, 15, LIGHT_RED, RED, BRIGHT_WHITE, WHITE);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(38, 10); cout << "That was easy, right?";
	Sleep(1000);
	draw::printColoredRectangle(40, 10, 19, 1, BRIGHT_WHITE);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(38, 10); cout << "Keep moving, friend!";
	Sleep(1000);

	// hiển thị di chuyển
	common::setColor(2);
	draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::stepFour()
{
	// Giới thiệu 3 mục: HELP, ABOUT US, EXIT
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	unsigned char items[] = { 219, 223, 219, 32 , 223, 219, 223, 32 , 219, 32 , 219, 32 , 219, 223, 223, 32 , 219, 223, 219, 32 , 32 , 32 , 219, 32 , 223, 219, 223, 32 , 219, 223, 223, 32 , 219, 220, 32 , 220, 219, 32 , 219, 223,
							  219, 220, 219, 32 , 32 , 219, 32 , 32 , 219, 223, 219, 32 , 219, 219, 220, 32 , 219, 223, 220, 32 , 32 , 32 , 219, 32 , 32 , 219, 32 , 32 , 219, 219, 220, 32 , 219, 32 , 223, 32 , 219, 32 , 220, 219, };
	int num_chars = 40;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(10 + j, 4 + i); putchar(items[i * num_chars + j]);
		}
	}

	draw::printBoard(22, 7, 15, 2, BLACK);
	draw::printBoard(22, 10, 15, 2, BLACK);
	draw::printBoard(22, 13, 15, 2, BLACK);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(24, 8); cout << "    HELP    ";
	common::gotoXY(24, 11); cout << "  ABOUT US  ";
	common::gotoXY(24, 14); cout << "    EXIT    ";
	Sleep(1000);

	// hiển thị menu cần chọn: HELP
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(24, 8); cout << "    HELP    ";
		common::setColor(15);
		common::gotoXY(16, 8); cout << "    ";
		common::gotoXY(40, 8); cout << "    ";
		Sleep(500);

		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(24, 8); cout << "    HELP    ";
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		common::gotoXY(16, 8); cout << ">>>>";
		common::setColor(RED);
		common::gotoXY(40, 8); cout << "<<<<";
		Sleep(500);
	}
	avatar::leftAmongUsHead(85, 25, LIGHT_GREEN);
	draw::boxChatRight(60, 15, 4, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(65, 18); cout << "This item offers you";
	common::gotoXY(63, 19); cout << "information about the rule";
	Sleep(1500);
	draw::printColoredRectangle(57, 15, 36, 10, BRIGHT_WHITE);
	draw::boxChatRight(48, 15, 4, 54);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(60, 18); cout << "Whether you forgot the rule,";
	common::gotoXY(50, 19); cout << "it would be useful to recall the missing information";
	Sleep(2000);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(24, 8); cout << "    HELP    ";
	common::setColor(15);
	common::gotoXY(16, 8); cout << "    ";
	common::gotoXY(40, 8); cout << "    ";
	draw::printColoredRectangle(45, 15, 60, 15, BRIGHT_WHITE);

	// hiển thị menu cần chọn: ABOUT US
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(24, 11); cout << "  ABOUT US  ";
		common::setColor(15);
		common::gotoXY(16, 11); cout << "    ";
		common::gotoXY(40, 11); cout << "    ";
		Sleep(500);

		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(24, 11); cout << "  ABOUT US  ";
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		common::gotoXY(16, 11); cout << ">>>>";
		common::setColor(RED);
		common::gotoXY(40, 11); cout << "<<<<";
		Sleep(500);
	}
	avatar::leftAmongUsHead(85, 25, LIGHT_PURPLE);
	draw::boxChatRight(60, 15, 4, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(65, 18); cout << "This item offers you";
	common::gotoXY(63, 19); cout << "information about our group";
	Sleep(1500);
	draw::printColoredRectangle(57, 15, 36, 10, BRIGHT_WHITE);
	draw::boxChatRight(60, 15, 4, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(64, 18); cout << "Including members' names";
	common::gotoXY(64, 19); cout << "and our instructor's name";
	Sleep(1500);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(24, 11); cout << "  ABOUT US  ";
	common::setColor(15);
	common::gotoXY(16, 11); cout << "    ";
	common::gotoXY(40, 11); cout << "    ";
	draw::printColoredRectangle(45, 15, 60, 15, BRIGHT_WHITE);

	// hiển thị menu cần chọn: EXIT
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(24, 14); cout << "    EXIT    ";
		common::setColor(15);
		common::gotoXY(16, 14); cout << "    ";
		common::gotoXY(40, 14); cout << "    ";
		Sleep(500);

		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(24, 14); cout << "    EXIT    ";
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		common::gotoXY(16, 14); cout << ">>>>";
		common::setColor(RED);
		common::gotoXY(40, 14); cout << "<<<<";
		Sleep(500);
	}
	avatar::leftAmongUsHead(85, 25, LIGHT_YELLOW);
	draw::boxChatRight(60, 15, 4, 38);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(71, 18); cout << "If you want to exit,";
	common::gotoXY(65, 19); cout << "this item will show you the way";
	Sleep(1500);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(24, 14); cout << "    EXIT    ";
	common::setColor(15);
	common::gotoXY(16, 14); cout << "    ";
	common::gotoXY(40, 14); cout << "    ";
	draw::printColoredRectangle(45, 15, 60, 15, BRIGHT_WHITE);

	// hiển thị di chuyển
	common::setColor(2);
	draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::stepFive()
{
	// Hiển thị mục phụ: SOUND
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	unsigned char additional[] = { 219, 223, 219, 32 , 219, 223, 220, 32 , 219, 223, 220, 32 , 219, 32 , 223, 219, 223, 32 , 219, 32 , 219, 223, 219, 32 , 219, 220, 32 , 219, 32 , 219, 223, 219, 32 , 219, 32 , 32 ,
								   219, 223, 219, 32 , 219, 220, 223, 32 , 219, 220, 223, 32 , 219, 32 , 32 , 219, 32 , 32 , 219, 32 , 219, 220, 219, 32 , 219, 32 , 223, 219, 32 , 219, 223, 219, 32 , 219, 220, 220, };
	unsigned char item[] = { 219, 32 , 223, 219, 223, 32 , 219, 223, 223, 32 , 219, 220, 32 , 220, 219,
							 219, 32 , 32 , 219, 32 , 32 , 219, 219, 220, 32 , 219, 32 , 223, 32 , 219, };
	unsigned char sound[] = { 219, 223, 32 , 219, 223, 219, 32 , 219, 32 , 219, 32 , 219, 220, 32 , 219, 32 , 219, 223, 220, 
							  220, 219, 32 , 219, 220, 219, 32 , 219, 220, 219, 32 , 219, 32 , 223, 219, 32 , 219, 220, 223, };
	int num_chars = 36, num_chars_1 = 15, num_chars_2 = 19;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(10 + j, 4 + i); putchar(additional[i * num_chars + j]);
		}
		for (int k = 0; k < num_chars_1; k++) {
			common::gotoXY(49 + k, 4 + i); putchar(item[i * num_chars_1 + k]);
		}
		for (int t = 0; t < num_chars_2; t++) {
			common::gotoXY(10 + t, 7 + i); putchar(sound[i * num_chars_2 + t]);
		}
	}
	common::gotoXY(65, 4); putchar(254);
	common::gotoXY(65, 5); putchar(254);

	// Hiển thị bật nhạc
	avatar::leftAmongUs(45, 18, LIGHT_RED, RED, BRIGHT_WHITE, WHITE);
	draw::boxChatRight(25, 11, 1, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(28, 13); cout << "Use N to turn on the sound";
	draw::musicIconOn(25, 21);
	Sleep(2000);
	draw::printColoredRectangle(22, 11, 38, 9, BRIGHT_WHITE);
	draw::printColoredRectangle(45, 18, 19, 10, BRIGHT_WHITE);

	// Hiển thị tắt nhạc
	avatar::rightAmongUs(45, 18, BRIGHT_WHITE, WHITE, BRIGHT_WHITE);
	draw::boxChatLeft(60, 11, 1, 30);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(62, 13); cout << "Use M to turn off the sound";
	draw::musicIconOff(75, 21);
	Sleep(2000);
	draw::printColoredRectangle(58, 11, 40, 9, BRIGHT_WHITE);
	draw::printColoredRectangle(45, 18, 19, 10, BRIGHT_WHITE);

	// hiển thị di chuyển
	common::setColor(2);
	draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::lastStep()
{
	avatar::leftAmongUs(48, 15, LIGHT_RED, RED, BRIGHT_WHITE, WHITE);
	draw::boxChatRight(30, 8, 1, 36);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(32, 10); cout << "That is everything about tutorial";
	Sleep(2000);
	draw::printColoredRectangle(27, 8, 45, 7, BRIGHT_WHITE);
	draw::boxChatRight(37, 8, 1, 25);
	common::setConsoleColor(BRIGHT_WHITE, RED);
	common::gotoXY(44, 10); cout << "See ya later!";
	Sleep(2000);

	common::clearConsole();
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	unsigned char end[] = { 223, 219, 223, 32 , 219, 32 , 219, 32 , 219, 223, 223, 32 , 32 , 32 , 219, 223, 223, 32 , 219, 220, 32 , 219, 32 , 219, 223, 220, 
							32 , 219, 219, 32 , 219, 223, 219, 32 , 219, 219, 220, 32 , 32 , 32 , 219, 219, 220, 32 , 219, 32 , 223, 219, 32 , 219, 220, 223, };
	int num_chars = 26;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < num_chars; j++) {
			common::gotoXY(40 + j, 15 + i); putchar(end[i * num_chars + j]);
		}
	}

	// hiển thị di chuyển
	common::setColor(2);
	draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}
