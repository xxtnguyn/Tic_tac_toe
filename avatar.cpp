#include "avatar.h"
#include "common.h"

void avatar::rightAmongUs(int x, int y, int color, int color_1, int color_2, int color_3)
{
	// TÃ´ mÃ u
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

	// TÃ´ bÃ³ng
	common::setColor(7);
	common::gotoXY(x + 3, y + 9); putchar(219);
	common::gotoXY(x + 11, y + 9); putchar(219);

	// TÃ´ mÃ u kÃ­nh
	for (int i = 0; i < 9; i++) {
		common::setConsoleColor(WHITE, GRAY);
		common::gotoXY(x + 8 + i, y + 3); putchar(220);
		common::setConsoleColor(GRAY, WHITE);
		common::gotoXY(x + 8 + i, y + 2); putchar(219);
	}

	common::setColor(0);
	// Váº½ viá»n kÃ­nh vÅ© trá»¥
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
	common::setConsoleColor(color_3, BLACK);
	common::gotoXY(x + 15, y + 1); putchar(220);
	common::gotoXY(x + 16, y + 1); putchar(220);
	common::gotoXY(x + 16, y + 4); putchar(223);

	// Váº½ viá»n
	common::setConsoleColor(color_2, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 1 + i, y + 3); putchar(220);
		common::gotoXY(x + 1 + i, y + 7); putchar(223);
	}
	for (int i = 0; i < 9; i++) {
		common::gotoXY(x + 5 + i, y); putchar(220);
	}

	common::setConsoleColor(WHITE, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x, y + 4 + i); putchar(219);
	}
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x + 3, y + 2 + i); putchar(219);
	}
	common::gotoXY(x + 4, y + 1); putchar(219);
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

void avatar::leftAmongUsHead(int x, int y, int color)
{
	// Tồ màu
	common::setColor(color);
	for (int i = 0; i < 3; i++) {
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

void avatar::leftAmongUs(int x, int y, int color, int color_1, int color_2, int color_3)
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
	common::setColor(color_3);
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
	common::setConsoleColor(color_2, BLACK);
	common::gotoXY(x + 2, y + 1); putchar(220);
	common::gotoXY(x + 3, y + 1); putchar(220);
	common::gotoXY(x + 2, y + 4); putchar(223);

	// Vẽ viền
	common::setConsoleColor(color_3, BLACK);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 4 + i, y + 9); putchar(223);
	}
	for (int i = 0; i < 3; i++) {
		common::gotoXY(x + 12 + i, y + 9); putchar(223);
	}

	common::setConsoleColor(color_2, BLACK);
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
	common::gotoXY(x + 7, y + 8); putchar(219);
	common::gotoXY(x + 11, y + 8); putchar(219);
	for (int i = 0; i < 7; i++) {
		common::gotoXY(x + 15, y + 8 - i); putchar(219);
	}
}

void avatar::BotHead(int left, int top, int color, int color_1)
{
	// Tô màu
	common::setColor(color);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(left + i + 12, top);
		putchar(219);
	}
	for (int i = 0; i < 14; i++) {
		common::gotoXY(left + i + 8, top + 1);
		putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 15; j++) {
			common::gotoXY(left + 7 + j, top + 2 + i);
			putchar(219);
		}
	}

	//Vẽ viền
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(left + i + 12, top - 1);
		putchar(220);
	}
	common::gotoXY(left + 11, top);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(left + i + 8, top);
		putchar(220);
	}
	common::gotoXY(left + 7, top + 1);
	putchar(219);
	common::gotoXY(left + 6, top + 2);
	putchar(219);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(left + 22, top + 4 - i);
		putchar(219);
		common::gotoXY(left + 6, top + 4 - i);
		putchar(219);
	}
	common::gotoXY(left + 22, top + 2);
	putchar(219);
	common::gotoXY(left + 21, top + 1);
	putchar(219);
	for (int i = 0; i < 4; i++) {
		common::gotoXY(left + 17 + i, top);
		putchar(220);
	}
	common::gotoXY(left + 17, top);
	putchar(219);

	//Tô mặt
	common::setConsoleColor(color, BLACK);
	for (int i = 0; i < 7; i++) {
		common::gotoXY(left + 11 + i, top + 1);
		putchar(220);
	}
	for (int i = 0; i < 11; i++) {
		common::gotoXY(left + 9 + i, top + 2);
		putchar(219);
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 13; j++) {
			common::gotoXY(left + 8 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 11; i++) {
		common::gotoXY(left + 9 + i, top + 4);
		putchar(223);
	}

	//Vẽ mặt
	common::setColor(color_1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(left + 11 + i * 5 + j, top + 3);
			putchar(219);
		}
	}
}

void avatar::Bot(int left, int top, int color1, int color2, int color3, int color4)
{
	//Vẽ mình
	/*unsigned char avatarbot[] = {
		 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,219,219,219,219,219,219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
		 32, 32, 32, 32, 32, 32, 32,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 32, 32, 32, 32, 32, 32, 32,
		 32, 32, 32, 32, 32, 32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 32, 32, 32, 32, 32, 32,
		 32, 32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 32,
		 32, 32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 32,
		 32, 32, 32, 32, 32, 32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 32, 32, 32, 32, 32,
		 32, 32, 32, 32, 32, 32, 32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 32, 32, 32, 32, 32, 32,
		 32, 32, 32, 32, 32, 32, 32, 32, 32,219,219,219,219,219,219,219,219,219,219,219, 32, 32, 32, 32, 32, 32, 32, 32,
		 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,219,219,219,219,219, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,

	};
	int num_char = 28, num_lines = 9;
	for (int i = 0; i < num_lines; i++) {
		common::gotoXY(left, top + i);
		common::setConsoleColor(BRIGHT_WHITE, color1);
		for (int j = 0; j < num_char; j++)
		{
			putchar(avatarbot[i * num_char + j]);
		}
	}*/

	// Tô màu
	common::setColor(color1);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(left + 3 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			common::gotoXY(left + 23 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 5; i++) {
		common::gotoXY(left + i + 12, top);
		putchar(219);
	}
	for (int i = 0; i < 14; i++) {
		common::gotoXY(left + i + 8, top + 1);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 15; j++) {
			common::gotoXY(left + 7 + j, top + 2 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 14; i++) {
		common::gotoXY(left + i + 8, top + 6);
		putchar(219);
	}
	for (int i = 0; i < 12; i++) {
		common::gotoXY(left + i + 8, top + 7);
		putchar(219);
	}
	for (int i = 0; i < 5; i++) {
		common::gotoXY(left + i + 12, top + 8);
		putchar(219);
	}

	//Vẽ viền
	common::setConsoleColor(color4, BLACK);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(left + i + 12, top - 1);
		putchar(220);
	}
	common::gotoXY(left + 11, top);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(left + i + 8, top);
		putchar(220);
	}
	common::gotoXY(left + 7, top + 1);
	putchar(219);
	common::gotoXY(left + 6, top + 2);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(left + 3 + i, top + 2);
		putchar(220);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(left + 2, top + 3 + i);
		putchar(219);
		common::gotoXY(left + 6, top + 3 + i);
		putchar(219);
	}
	for (int i = 0; i < 3; i++) {
		common::gotoXY(left + 3 + i, top + 5);
		putchar(223);
	}
	common::gotoXY(left + 6, top + 5);
	putchar(219);
	common::gotoXY(left + 7, top + 6);
	putchar(219);
	common::gotoXY(left + 8, top + 7);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(left + 9 + i, top + 8);
		putchar(223);
	}
	common::gotoXY(left + 11, top + 8);
	putchar(219);
	for (int i = 0; i < 5; i++) {
		common::gotoXY(left + 12 + i, top + 9);
		putchar(223);
	}
	common::gotoXY(left + 17, top + 8);
	putchar(219);
	for (int i = 0; i < 2; i++) {
		common::gotoXY(left + 18 + i, top + 8);
		putchar(223);
	}
	common::gotoXY(left + 20, top + 7);
	putchar(219);
	common::gotoXY(left + 21, top + 6);
	putchar(219);
	common::gotoXY(left + 22, top + 5);
	putchar(219);
	for (int i = 0; i < 3; i++) {
		common::gotoXY(left + 23 + i, top + 5);
		putchar(223);
	}
	for (int i = 0; i < 2; i++) {
		common::gotoXY(left + 26, top + 4 - i);
		putchar(219);
		common::gotoXY(left + 22, top + 4 - i);
		putchar(219);
	}
	for (int i = 0; i < 4; i++) {
		common::gotoXY(left + 22 + i, top + 2);
		putchar(220);
	}
	common::gotoXY(left + 22, top + 2);
	putchar(219);
	common::gotoXY(left + 21, top + 1);
	putchar(219);
	for (int i = 0; i < 4; i++) {
		common::gotoXY(left + 17 + i, top);
		putchar(220);
	}
	common::gotoXY(left + 17, top);
	putchar(219);

	//Tô mặt
	common::setConsoleColor(color1, BLACK);
	for (int i = 0; i < 7; i++) {
		common::gotoXY(left + 11 + i, top + 1);
		putchar(220);
	}
	for (int i = 0; i < 11; i++) {
		common::gotoXY(left + 9 + i, top + 2);
		putchar(219);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 13; j++) {
			common::gotoXY(left + 8 + j, top + 3 + i);
			putchar(219);
		}
	}
	for (int i = 0; i < 11; i++) {
		common::gotoXY(left + 9 + i, top + 5);
		putchar(223);
	}

	//Vẽ mặt
	common::setColor(color2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			common::gotoXY(left + 11 + i * 5 + j, top + 3);
			putchar(219);
		}
	}

	// In tên con bot
	common::setColor(color3);
	string bot_name = "FIT@HCMUS";
	for (int i = 0; i < bot_name.size(); i++) {
		common::gotoXY(left + 10 + i, top + 6);
		cout << bot_name[i];
	}
}
