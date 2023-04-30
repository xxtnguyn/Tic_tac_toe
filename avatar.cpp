#include "avatar.h"
#include "common.h"

void avatar::Cat(int x, int y)
{
	// Vẽ viền
	common::setColor(0);
	common::gotoXY(x + 1, y); putchar(220);
	common::gotoXY(x + 2, y); putchar(220);
	common::gotoXY(x + 3, y + 1); putchar(219);
	common::gotoXY(x + 4, y + 2); putchar(219);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x, y + 1 + i); putchar(219);
		common::gotoXY(x - 1, y + 3 + i); putchar(219);
		common::gotoXY(x + 11, y + 1 + i); putchar(219);
		common::gotoXY(x + 12, y + 3 + i); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 5 + i, y + 3); putchar(223);
	}
	common::gotoXY(x + 7, y + 2); putchar(219);
	common::gotoXY(x + 8, y + 1); putchar(219);
	common::gotoXY(x + 9, y); putchar(220);
	common::gotoXY(x + 10, y); putchar(220);

	common::gotoXY(x, y + 5); putchar(219);
	common::gotoXY(x + 1, y + 6); putchar(219);
	for (int i = 0; i < 8; i++) {
		common::gotoXY(x + 2 + i, y + 7); putchar(223);
	}
	common::gotoXY(x + 11, y + 5); putchar(219);
	common::gotoXY(x + 10, y + 6); putchar(219);

	// Tô màu
	common::setColor(8);
	for (int i = 0; i < 12; i++) {
		common::gotoXY(x + i, y + 3); putchar(219);
		common::gotoXY(x + i, y + 4); putchar(219);
	}
	for (int i = 0; i < 10; i++) {
		common::gotoXY(x + 1 + i, y + 5); putchar(219);
	}
	for (int i = 0; i < 8; i++) {
		common::gotoXY(x + 2 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(GRAY, BLACK);
		common::gotoXY(x + 5 + i, y + 3); putchar(223);
	}
	common::setColor(8);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(x + 1 + 7 * i + j, y + 2); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 1 + 8 * i + j, y + 1); putchar(219);
		}
	}
	common::setColor(7);
	common::gotoXY(x + 2, y + 2); putchar(219);
	common::gotoXY(x + 9, y + 2); putchar(219);

	// Vẽ mắt và miệng, má

	// Vẽ má
	common::setColor(13);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 1 + j + i * 8, y + 5);
			putchar(219);
		}
	}

	// Vẽ mắt
	for (int i = 0; i < 2; i++) {
		common::setConsoleColor(BRIGHT_WHITE, BLACK);
		common::gotoXY(x + 3 + i * 4, y + 4); putchar(220);
		common::setColor(0);
		common::gotoXY(x + 4 + i * 4, y + 4); putchar(219);
	}

	// Vẽ miệng
	common::setConsoleColor(GRAY, BLACK);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 5 + i, y + 6); putchar(223);
	}
}

void avatar::rightAmongUs(int x, int y, int color, int color_1)
{
	// Tô màu
	common::setColor(color);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 1 + j, y + 4 + i); putchar(219);
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			common::gotoXY(x + 4 + j, y + 2 + i); putchar(219);
		}
	}
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 5 + i, y + 1); putchar(219);
	}
	common::setConsoleColor(color, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 8 + i, y + 7); putchar(220);
	}

	common::setColor(color_1);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 1 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
			common::gotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 4 + j + 10 * i, y + 7); putchar(219);
			common::gotoXY(x + 4 + 11 * i, y + 6); putchar(219);
		}
	}

	// Tô bóng
	common::setColor(7);
	common::gotoXY(x + 3, y + 9); putchar(219);
	common::gotoXY(x + 11, y + 9); putchar(219);

	// Tô màu kính
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(WHITE, GRAY);
		common::gotoXY(x + 8 + i, y + 3); putchar(220);
		common::setConsoleColor(GRAY, WHITE);
		common::gotoXY(x + 8 + i, y + 2); putchar(219);
	}

	common::setColor(0);
	// Vẽ viền kính vũ trụ
	common::gotoXY(x + 7, y + 2); putchar(219);
	common::gotoXY(x + 7, y + 3); putchar(219);
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(color, BLACK);
		common::gotoXY(x + 8 + i, y + 1); putchar(220);
		common::setConsoleColor(color, BLACK);
		common::gotoXY(x + 8 + i, y + 4); putchar(223);
	}
	common::setColor(0);
	common::gotoXY(x + 17, y + 2); putchar(219);
	common::gotoXY(x + 17, y + 3); putchar(219);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(x + 15, y + 1); putchar(220);
	common::gotoXY(x + 16, y + 1); putchar(220);
	common::gotoXY(x + 16, y + 4); putchar(223);

	// Vẽ viền
	common::setConsoleColor(WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x, y + 4 + i); putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 1 + i, y + 3); putchar(220);
		common::gotoXY(x + 1 + i, y + 7); putchar(223);
	}
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x + 3, y + 2 + i); putchar(219);
	}
	common::gotoXY(x + 4, y + 1); putchar(219);
	for (int i = 0; i < 9; i++) {
		common::gotoXY(x + 5 + i, y); putchar(220);
	}
	common::gotoXY(x + 14, y + 1); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 4 + i, y + 9); putchar(223);
	}
	common::gotoXY(x + 7, y + 8); putchar(219);
	common::gotoXY(x + 11, y + 8); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 12 + i, y + 9); putchar(223);
	}
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + 15, y + 8 - i); putchar(219);
	}
}

void avatar::leftAmongUsHead(int x, int y, int color, int color_1)
{
	// Tồ màu
	common::setColor(color);
	for(int i = 0; i < 3; i++) {
		common::gotoXY(x + 11 + i, y + 1); putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			common::gotoXY(x + 11 + j, y + 2 + i); putchar(219);
		}
	}

	// Tô màu kính
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(WHITE, GRAY);
		common::gotoXY(x + 2 + i, y + 3); putchar(220);
		common::setConsoleColor(GRAY, WHITE);
		common::gotoXY(x + 2 + i, y + 2); putchar(219);
	}

	common::setColor(0);
	// Vẽ viền kính vũ trụ
	common::gotoXY(x + 1, y + 2); putchar(219);
	common::gotoXY(x + 1, y + 3); putchar(219);
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(color, BLACK);
		common::gotoXY(x + 2 + i, y + 1); putchar(220);
		common::setConsoleColor(color, BLACK);
		common::gotoXY(x + 2 + i, y + 4); putchar(223);
	}
	common::setColor(0);
	common::gotoXY(x + 11, y + 2); putchar(219);
	common::gotoXY(x + 11, y + 3); putchar(219);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(x + 2, y + 1); putchar(220);
	common::gotoXY(x + 3, y + 1); putchar(220);
	common::gotoXY(x + 2, y + 4); putchar(223);

	// Vẽ viền
	common::gotoXY(x + 4, y + 1); putchar(219);
	for (int i = 0; i < 9; i++) {
		common::gotoXY(x + 5 + i, y); putchar(220);
	}
	common::gotoXY(x + 14, y + 1); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 15, y + 2 + i); putchar(219);
	}
	common::gotoXY(x + 3, y + 4); putchar(219);
}

void avatar::leftAmongUs(int x, int y, int color, int color_1)
{
	// Tô màu
	common::setColor(color);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 16 + j, y + 4 + i); putchar(219);
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			common::gotoXY(x + 4 + j, y + 2 + i); putchar(219);
		}
	}
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 11 + i, y + 1); putchar(219);
	}
	common::setConsoleColor(color, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 8 + i, y + 7); putchar(220);
	}

	common::setColor(color_1);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(x + 16 + i, y + 6); putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
			common::gotoXY(x + 4 + j + 8 * i, y + 8); putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(x + 3 + j + 10 * i, y + 7); putchar(219);
			common::gotoXY(x + 3 + 11 * i, y + 6); putchar(219);
		}
	}
	common::setConsoleColor(color, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 8 + i, y + 7); putchar(220);
	}

	// Tô bóng
	common::setColor(7);
	common::gotoXY(x + 7, y + 9); putchar(219);
	common::gotoXY(x + 15, y + 9); putchar(219);

	// Tô màu kính
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(WHITE, GRAY);
		common::gotoXY(x + 2 + i, y + 3); putchar(220);
		common::setConsoleColor(GRAY, WHITE);
		common::gotoXY(x + 2 + i, y + 2); putchar(219);
	}

	common::setColor(0);
	// Vẽ viền kính vũ trụ
	common::gotoXY(x + 1, y + 2); putchar(219);
	common::gotoXY(x + 1, y + 3); putchar(219);
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(color, BLACK);
		common::gotoXY(x + 2 + i, y + 1); putchar(220);
		common::setConsoleColor(color, BLACK);
		common::gotoXY(x + 2 + i, y + 4); putchar(223);
	}
	common::setColor(0);
	common::gotoXY(x + 11, y + 2); putchar(219);
	common::gotoXY(x + 11, y + 3); putchar(219);
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::gotoXY(x + 2, y + 1); putchar(220);
	common::gotoXY(x + 3, y + 1); putchar(220);
	common::gotoXY(x + 2, y + 4); putchar(223);

	// Vẽ viền
	common::setConsoleColor(WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 18, y + 4 + i); putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 15 + i, y + 3); putchar(220);
		common::gotoXY(x + 15 + i, y + 7); putchar(223);
	}
	for (int i = 0; i < 5; i++) {
		common::gotoXY(x + 3, y + 4 + i); putchar(219);
	}
	common::gotoXY(x + 4, y + 1); putchar(219);
	for (int i = 0; i < 9; i++) {
		common::gotoXY(x + 5 + i, y); putchar(220);
	}
	common::gotoXY(x + 14, y + 1); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 4 + i, y + 9); putchar(223);
	}
	common::gotoXY(x + 7, y + 8); putchar(219);
	common::gotoXY(x + 11, y + 8); putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 12 + i, y + 9); putchar(223);
	}
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x + 15, y + 8 - i); putchar(219);
	}
}
