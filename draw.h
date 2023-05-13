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
	static void Cat(int, int, int);								// Vẽ mèo
	static void printTitleChoose(int, int);						// Vẽ dòng chữ "CHOOSE YOUR AVATAR"
	static void smallLostAmongUs(int, int, int);				// Vẽ among us khóc
	static void Aura(int, int);									// Vẽ hào quang
	static void biggerAura(int, int);							// Vẽ hào quang lớn
	static void titleEffect(int, int);							// Tiêu đề
	static void winnerSignature(int, int);						// Vẽ dòng chữ "WINNER"
	static void musicIconOn(int, int);							// icon bật nhạc
	static void musicIconOff(int, int);							// icon tắt nhạc
	static void printCaroTutorial(int, int, int, int);			// Vẽ dòng chữ "CARO TUTORIAL"						
	static void printVS(int, int);								// In "VS
	static void boxChatRight(int, int, int, int);				// In hộp chat
	static void boxChatLeft(int, int, int, int);
	static void drawBoard();
	static void printRule(int x, int y);						// In dòng chữ "RULE"
	static void Coin(int, int);									// Vẽ đồng xu
	static void PacmanCloseMouth(int, int);						// Vẽ pacman
	static void PacmanOpenHalfMouth(int, int);
	static void PacmanOpenMouth(int, int);
	static void thankPlaying(int, int);							// Kết thúc game
};
