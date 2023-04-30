#pragma once
#include "header.h"
#include "common.h"
#include "gameplay.h"
#include "avatar.h"


#include <unordered_map>
#include <filesystem>

//#include "gameplay.h"

class draw
{
public:
	static void rainbowBackground();						//Background cầu vồng
	static void rainbowColumn();							//In cột hình cầu vồng
	static void printBoard(int, int, int, int, int);		//In khung
	static void printLoadBoard(int);						//In khung Load Game
	static void printLogo();								//In ra logo
	static void printIntro();								//In intro mở đầu
	static void printRectangle(int, int, int, int);			//Vẽ hình chữ nhật
	static void printColoredRectangle(int, int, int, int, int);   //Vẽ hình chữ nhật màu
	static void printX(int, int);                               //Vẽ X
	static void printO(int, int);                                //Vẽ O
	static void printBigX(int, int, int, int);                        //Vẽ X siêu to khổng lồ
	static void printBigO(int, int, int, int);						//Vẽ O siêu to khổng lồ
	static void printAnimatedBigXandBigO(int, int, int, int);				//Vẽ X và O siêu to nhấp nháy
	static void printTTN();										//
	static void printDNTN();									//	
	static void printLTN();										//In tên các thành viên
	static void printTHKN();									//
	static void printInstructor();								//In tên giảng viên
	static void printLoadText();								//In logo màn hình load game
	static void printScene();									//In cảnh
	static void loadingBar();									//Màn hình chờ
};
