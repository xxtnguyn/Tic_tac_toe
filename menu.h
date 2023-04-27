#pragma once
#include "header.h"
#include "common.h"
#include "gameplay.h"


#include <unordered_map>
#include <filesystem>

//#include "gameplay.h"

class menu
{
private:
	static bool exitGame;				//Cờ thoát game
	static int current_option;			//Lựa chọn hiện tại
	const static string options[9];		//Tên các lựa chọn
public:
	static void mainScreen();								//Màn hình chính
	static void mainMenu();									//Menu
	static void newGameMenu();									//Menu New Game
	static void loadScreen();								//Màn hình load file
	static void helpScreen();								//Màn hình hướng dẫn
	static void aboutUS();									//Màn hình giới thiệu
	static void exitScreen();								//Màn hình thoát
	static void playPvP();									//Chế độ người-người
	static void playPvEe();									//Chế độ người-máy(dễ)
	static void playPvEh();									//Chế độ người-máy(khó)
	static void backMenu();									//Trở về Menu chính
	static void rainbowBackground();						//Background cầu vồng
	static void rainbowColumn();							//In cột hình cầu vồng
	static void printBoard(int, int, int, int, int);		//In khung
	static void printLoadBoard(int);						//In khung Load Game
	//static void printAnimation();							//In hiệu ứng mở đầu
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
	static void changeOption(bool, bool);					//Thay đổi lựa chọn
	//static void onlyOption();								//Lựa chọn duy nhất
	static void changeFile(int, vector<string>&, int&);		//Thay đổi file
};
