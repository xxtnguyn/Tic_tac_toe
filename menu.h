#pragma once
#include "header.h"
#include "common.h"
#include "gameplay.h"
#include "draw.h"
#include "time.h"


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
	static void newGameMenu();								//Menu New Game
	static void loadScreen();								//Màn hình load file
	static void helpScreen();								//Màn hình hướng dẫn
	static void aboutUS();									//Màn hình giới thiệu
	static void exitScreen();								//Màn hình thoát
	static void playPvP();									//Chế độ người-người
	static void playPvEe();									//Chế độ người-máy(dễ)
	static void playPvEh();									//Chế độ người-máy(khó)
	static void backMenu();									//Trở về Menu chính
	static void changeOption(bool, bool);					//Thay đổi lựa chọn
	//static void onlyOption();								//Lựa chọn duy nhất
	static void changeFile(int, vector<string>&, int&);		//Thay đổi file
	//Hàm sử dụng trong màn hình chọn avatar:
	static void Tutorial();									//Hướng dẫn chơi game
};
