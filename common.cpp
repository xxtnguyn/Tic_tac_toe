#include "common.h"

HWND common::consoleWindow = GetConsoleWindow();
HANDLE common::consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void common::setUpConsole()
{
	setFontInfo();
	setAndCenterWindow();
	disableMaximize();
	setConsoleTitle();
	hideScrollBars();
	showCursor(false);
	disableMouseInput();
}

void common::gotoXY(int pX, int pY)
{
	SetConsoleCursorPosition(consoleOutput, COORD{ (short)pX, (short)pY });
}

void common::setAndCenterWindow()
{
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int width = 1216;
	int height = 784;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);
}

void common::setConsoleTitle()
{
	SetConsoleTitle(L"\u0043\u0041\u0052\u00D4");
}

void common::hideScrollBars()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void common::setConsoleColor(int background, int text)
{
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}

void common::clearConsole()
{
	system("cls");
}

void common::disableMaximize()
{
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void common::showCursor(bool show)
{
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}

void common::setFontInfo()
{
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;
	info.dwFontSize.Y = 24;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}

void common::disableMouseInput()
{
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

int common::getConsoleInput()
{
	int c = _getch();
	if (c == 27)                  //ESC
		return 1;
	else if (c == 87 || c == 119) //W, w
		return 2;
	else if (c == 65 || c == 97)  //A, a
		return 3;
	else if (c == 68 || c == 100) //D, d
		return 4;
	else if (c == 83 || c == 115) //S, s
		return 5;
	else if (c == 13)             //Enter
		return 6;
	else if (c == 80 || c == 112) //P, p
		return 7;
	else
		return 0;                 //nút khác

}


void common::playSound(int i)
{
	static vector<const wchar_t*> soundFile{ L"moveO.wav", L"moveX.wav",
		L"move.wav", L"PacmanDeath.wav", L"error.wav", L"placed.wav", L"win.wav", L"lose.wav",  L"background.wav", L"effect.wav" };
	PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
}


int getRandomInt(int begin, int end)
{
	static random_device rd;
	static mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, end);
	return dist(mt);
}

void common::setColor(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}
