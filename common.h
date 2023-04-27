#pragma once
#include "header.h"
#include "data.h"


#include <Windows.h>
#include <vector>
#include <Random>

class common
{
private:
	static HWND consoleWindow;    //Con trỏ xử lí cửa sổ console
	static HANDLE consoleOutput;  //Con trỏ xử lí output console
public:
	common() {}
	~common() {}
	static void setUpConsole();               //Thiết lập cửa sổ console
	static void gotoXY(int, int);			  //Di chuyển con trỏ đến vị trí x,y
	static void setAndCenterWindow();         //Căn giữa và thiết lập độ phân giải màn hình console
	static void setConsoleColor(int, int);    //Thiết lập màu chữ và và màu nền
	static void hideScrollBars();             //Ẩn thanh cuộn
	static void setFontInfo();
	static void setConsoleTitle();            //Cài đặt tiêu đề console
	static void setColor(int);					  //Cài đặt màu nền
	static void disableMaximize();            //Vô hiệu hóa phóng to màn hình
	static void showCursor(bool);             //Ẩn hoặc hiện con trỏ
	//static void setFontInfo();                //Cài đặt font chữ
	static void clearConsole();               //Xóa màn hình console
	static void disableMouseInput();          //Vô hiệu hóa chuột trong console
	static int  getConsoleInput();             //Lấy lệnh từ bàn phím
	static void playSound(int);               //Phát âm thanh
};

int getRandomInt(int begin, int end);         //Hàm lấy số nguyên ngẫu nhiên
