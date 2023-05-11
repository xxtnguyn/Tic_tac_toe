#include "tutorial.h"

void tutorial::tutorialIntro()
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
		common::gotoXY(36, i); putchar(186);
		Sleep(10);
	}

	draw::printColoredRectangle(10, 16, 43, 12, BLACK);
	draw::printCaroTutorial(20, 17, BRIGHT_WHITE, BLACK);
	draw::printBigX(80, 3, BLACK, BRIGHT_WHITE);
	draw::printBigO(90, 3, BLACK, BRIGHT_WHITE);

	// common::setColor(2);
	/*draw::printRectangle(70, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(72, 29); cout << "BACK (A)";*/

	common::setColor(2);
	draw::printRectangle(82, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(84, 29); cout << "NEXT (D)";

	common::setColor(2);
	draw::printRectangle(94, 28, 9, 2);
	common::setColor(0);
	common::gotoXY(96, 29); cout << "SKIP (S)";
}

void tutorial::tutorialStepOne()
{
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
	draw::printBoard(42, 5, 15, 2, BLACK);
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(43, 6); cout << "   NEW GAME   ";
		common::setColor(15);
		common::gotoXY(36, 6); cout << "    ";
		common::gotoXY(60, 6); cout << "    ";
		Sleep(1000);

		common::setConsoleColor(BLACK, BRIGHT_WHITE);
		common::gotoXY(43, 6); cout << "   NEW GAME   ";
		common::setConsoleColor(BRIGHT_WHITE, BLUE);
		common::gotoXY(36, 6); cout << ">>>>";
		common::setColor(RED);
		common::gotoXY(60, 6); cout << "<<<<";
		Sleep(1000);
	}

	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(23, 9); cout << "After that, you can choose one of three modes below to play.";

	// hiển thị mode game PVP
	common::gotoXY(7, 12); cout << "This one is for playing with friends";
	common::gotoXY(12, 13); cout << "or your game opponent.";
	avatar::rightAmongUs(3, 16, LIGHT_BLUE, BLUE, WHITE);
	draw::printVS(24, 20);
	avatar::leftAmongUs(28, 16, LIGHT_RED, RED, WHITE, WHITE);
	Sleep(3000);
	draw::printColoredRectangle(7, 12, 40, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(3, 16, 50, 10, BRIGHT_WHITE);

	// hiển thị mode game PVE easy
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(36, 12); cout << "This one is for single player";
	common::gotoXY(38, 13); cout << "playing with friendly bot.";
	avatar::rightAmongUs(26, 16, LIGHT_BLUE, BLUE, WHITE);
	draw::printVS(47, 20);
	avatar::Bot(51, 16, BRIGHT_WHITE, LIGHT_BLUE, BLUE);
	Sleep(3000);
	draw::printColoredRectangle(36, 12, 40, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(26, 15, 55, 11, BRIGHT_WHITE);

	// hiển thị mode game PVE hard
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(66, 12); cout << "This one is for single player";
	common::gotoXY(63, 13); cout << "playing with extremely angry bot.";
	avatar::rightAmongUs(53, 16, LIGHT_BLUE, BLUE, WHITE);
	draw::printVS(74, 20);
	avatar::Bot(78, 16, LIGHT_RED, RED, BLACK);
	Sleep(3000);
	draw::printColoredRectangle(63, 12, 40, 3, BRIGHT_WHITE);
	draw::printColoredRectangle(53, 15, 53, 11, BRIGHT_WHITE);
}

void tutorial::tutorialStepTwo()
{

}

void tutorial::tutorialStepThree()
{

}

void tutorial::tutorialStepFour()
{

}

void tutorial::tutorialStepFive()
{

}
