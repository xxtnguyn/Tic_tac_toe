#include "board.h"

board::board(int p_size, int pX, int pY) :
	_size(p_size), _left(pX), _top(pY)
{
	_pArr = new gpoint * [p_size];
	for (int i = 0; i < p_size; i++)
		_pArr[i] = new gpoint[p_size];
	_countX = _countO = 0;
	_winPos = nullptr;
}

board::~board()
{
	for (int i = 0; i < _size; i++)
		delete[] _pArr[i];
	delete[] _pArr,
		_pArr = nullptr;
	delete[] _winPos;
	_winPos = nullptr;
}


int board::getSize()
{
	return _size;
}

int board::getLeft()
{
	return _left;
}

int board::getTop()
{
	return _top;
}

int board::getCountX()
{
	return _countX;
}

int board::getCountO()
{
	return _countO;
}

int board::getXAt(int i, int j)
{
	return _pArr[i][j].getX();
}

int board::getYAt(int i, int j)
{
	return _pArr[i][j].getY();
}

void board::resetData()
{
	if (_size == 0)
		return; // Firstly calling constructor before calling resetData
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			_pArr[i][j].setX(4 * j + _left + 3); // x-value of boardgame
			_pArr[i][j].setY(2 * i + _top + 1); // y-value of boardgame
			_pArr[i][j].setCheck(0);
		}
	}
	_countX = _countO = 0;
}

void board::drawBoard()
{
	if (_pArr == NULL)
		return;
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	common::clearConsole();
	
	//Ve duong duoi
	for (int i = 1; i < _size * 4; i++)
	{
		common::gotoXY(_size * 4 + _left - i + 1, _size * 2 + _top);
		if (i % 4 == 0)
			putchar(202);
		else
			putchar(205);
	}
	common::gotoXY(_left + 1, _size * 2 + _top);
	putchar(200);

	//Ve duong ben trai
	for (int i = 1; i < _size * 2; i++)
	{
		common::gotoXY(_left + 1, _size * 2 + _top - i);
		if (i % 2 != 0)
			putchar(186);
		else
			putchar(204);
	}
	common::setConsoleColor(BRIGHT_WHITE, BLACK);
	//Ve duong tren
	common::gotoXY(_left + 1, _top);
	putchar(201);
	for (int i = 1; i < _size * 4; i++)
	{
		if (i % 4 == 0)
			putchar(203);
		else
			putchar(205);
	}
	putchar(187);


	//Ve duong ben phai
	for (int i = 1; i < _size * 2; i++)
	{
		common::gotoXY(_size * 4 + _left + 1, i + _top);
		if (i % 2 != 0)
			putchar(186);
		else
			putchar(185);
	}
	common::gotoXY(_size * 4 + _left + 1, _size * 2 + _top);
	putchar(188);


	//Ve cac duong doc
	for (int j = 1; j < _size * 4; j++)
	{
		for (int i = 1; i < _size * 2; i++)
		{
			if (j % 4 != 0)
			{
				if (i % 2 == 0)
				{
					common::gotoXY(j + _left + 1, i + _top);
					putchar(196);
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					common::gotoXY(j + _left + 1, i + _top);
					putchar(197);
				}
				else
				{
					common::gotoXY(j + _left + 1, i + _top);
					putchar(179);
				}
			}
		}
		Sleep(2);
	}

	//Ve cac duong ngang
	/*for (int i = 1; i < _size * 4; i++)
	{
		for (int j = 2; j < _size * 2; j += 2)
		{
			common::gotoXY(i + _left + 1, j + _top);
			if (i % 4 == 0)
				putchar(197);
			else
				putchar(196);
		}
		Sleep(1);
	}*/
}


int board::checkBoard(int pX, int pY, bool pTurn)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
			{
				if (_pArr[i][j].getCheck() == 0)
				{
					if (pTurn)
					{
						_countX++;
						_pArr[i][j].setCheck(1);
					}
					else
					{
						_countO++;
						_pArr[i][j].setCheck(-1);
					}
					return _pArr[i][j].getCheck();
				}
				else
					return 0;
			}
		}
	}
	throw "Problem with cursor";
}

int board::testBoard(int pX, int pY) //i,j la row,col cua bang
{
	if (_countX + _countO == _size * _size)
		return 0; // draw
	int i, j;
	[&] {
		for (i = 0; i < _size; i++)
		{
			for (j = 0; j < _size; j++)
			{
				if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
					return;
			}
		}
	}();
	int turn = _pArr[i][j].getCheck();
	if (checkRow(i, j, turn) || checkCol(i, j, turn) || checkDiag1(i, j, turn) || checkDiag2(i, j, turn))
		return (turn == 1) ? 1 : -1;
	return 2; // continue
}

int board::getCheckAtXY(int pX, int pY)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY)
				return _pArr[i][j].getCheck();
		}
	}
	throw "Problem with cursor position";
}

bool board::checkRow(int i, int j, int turn)
{
	int up = 0, down = 0;
	int count = 0, col = i;
	// kiểm tra hàng
	while (col <= _size - 1 && _pArr[col][j].getCheck() == _pArr[i][j].getCheck() && _pArr[i][j].getCheck() == turn)
	{
		if (col == _size - 1)
		{
			count++;
			down = col;
			break;
		}
		else
		{
			count++;
			col++;
			down = col;
		}
	}
	count--;
	col = i;
	while (col >= 0 && _pArr[col][j].getCheck() == _pArr[i][j].getCheck() && _pArr[i][j].getCheck() == turn)
	{
		if (col == 0)
		{
			count++;
			up = col;
			break;
		}
		else
		{
			count++;
			col--;
			up = col;
		}
	}
	if (count > 4)
	{
		if ((down == _size - 1 && _pArr[down][j].getCheck() == turn))
		{
			_winPos = new gpoint[5]{ {down - 4,j},{down - 3,j },{down - 2,j },{down - 1,j },{down ,j } };
			return true;
		}
		else if ((up == 0 && _pArr[up][j].getCheck() == turn))
		{
			_winPos = new gpoint[5]{ {up + 4,j},{up + 3,j },{up + 2,j },{up + 1,j },{up ,j } };
			return true;
		}
		else if (_pArr[down][j].getCheck() == -turn && _pArr[up][j].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {down - 5,j},{down - 4,j },{down - 3,j },{down - 2,j },{down - 1,j } };
			return true;
		}
		else if (_pArr[up][j].getCheck() == -turn && _pArr[down][j].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {up + 5,j},{up + 4 ,j },{up + 3,j },{up + 2,j },{up + 1,j } };
			return true;
		}
		else if (_pArr[up][j].getCheck() == _pArr[down][j].getCheck() && _pArr[down][j].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {down - 5,j},{down - 4,j },{down - 3,j },{down - 2,j },{down - 1,j } };
			return true;
		}
	}
	return false;
}

bool board::checkCol(int i, int j, int turn)
{
	int left = 0, right = 0;
	int count = 0, row = j;
	// kiểm tra cột
	while (row <= _size - 1 && _pArr[i][row].getCheck() == _pArr[i][j].getCheck() && _pArr[i][j].getCheck() == turn)
	{
		if (row == _size - 1)
		{
			count++;
			right = row;
			break;
		}
		else
		{
			count++;
			row++;
			right = row;
		}
	}
	count--;
	row = j;
	while (row >= 0 && _pArr[i][row].getCheck() == _pArr[i][j].getCheck() && _pArr[i][j].getCheck() == turn)
	{
		if (row == 0)
		{
			count++;
			left = row;
			break;
		}
		else
		{
			count++;
			row--;
			left = row;
		}
	}
	if (count > 4)
	{
		if (right == _size - 1 && _pArr[i][right].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {i,right},{i ,right - 1},{i ,right - 2},{i,right - 3},{i,right - 4} };
			return true;
		}
		else if (left == 0 && _pArr[i][left].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {i,left},{i ,left + 1},{i ,left + 2},{i,left + 3},{i,left + 4} };
			return true;
		}
		else if (_pArr[i][right].getCheck() == -turn && _pArr[i][left].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {i,right - 1},{i ,right - 2},{i ,right - 3},{i ,right - 4},{i ,right - 5} };
			return true;
		}
		else if (_pArr[i][left].getCheck() == -turn && _pArr[i][right].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {i,left + 1},{i ,left + 2},{i ,left + 3},{i ,left + 4},{i ,left + 5} };
			return true;
		}
		else if (_pArr[i][left].getCheck() == _pArr[i][right].getCheck() && _pArr[i][right].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {i,left + 1},{i ,left + 2},{i ,left + 3},{i ,left + 4},{i ,left + 5} };
			return true;
		}
	}
	return false;
}
bool board::checkDiag1(int i, int j, int turn)
{
	int LR_Col = 0, LR_Row = 0, UL_Col = 0, UL_Row = 0;
	// kiểm tra đường chéo 1
	int row = i, col = j, count = 0;
	while (col <= _size - 1 && row <= _size - 1 && _pArr[i][j].getCheck() == _pArr[row][col].getCheck() && _pArr[row][col].getCheck() == turn)
	{
		if ((col == _size - 1 && row == _size - 1) || (col == _size - 1) || (row == _size - 1))
		{
			count++;
			LR_Col = col;
			LR_Row = row;
			break;
		}
		else
		{
			count++;
			row++;
			col++;
			LR_Col = col;
			LR_Row = row;
		}
	}
	row = i; col = j, count--;
	while (row >= 0 && col >= 0 && _pArr[i][j].getCheck() == _pArr[row][col].getCheck() && _pArr[row][col].getCheck() == turn)
	{
		if ((col == 0 && row == 0) || (col == 0) || (row == 0))
		{
			count++;
			UL_Col = col;
			UL_Row = row;
			break;
		}
		else
		{
			count++;
			row--;
			col--;
			UL_Col = col;
			UL_Row = row;
		}
	}
	if (count > 4)
	{
		if (LR_Col == _size - 1 && _pArr[LR_Row][LR_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {LR_Row,LR_Col},{LR_Row - 1 ,LR_Col - 1},{LR_Row - 2,LR_Col - 2},{LR_Row - 3,LR_Col - 3},{LR_Row - 4,LR_Col - 4} };
			return true;
		}
		if (UL_Col == 0 && _pArr[UL_Row][UL_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {UL_Row + 0 ,UL_Col + 0},{UL_Row + 1,UL_Col + 1},{UL_Row + 2,UL_Col + 2},{UL_Row + 3,UL_Col + 3},{UL_Row + 4,UL_Col + 4} };
			return true;
		}
		if (LR_Row == _size - 1 && _pArr[LR_Row][LR_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {LR_Row,LR_Col},{LR_Row - 1 ,LR_Col - 1},{LR_Row - 2,LR_Col - 2},{LR_Row - 3,LR_Col - 3},{LR_Row - 4,LR_Col - 4} };
			return true;
		}
		if (UL_Row == 0 && _pArr[UL_Row][UL_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {LR_Row - 1 ,LR_Col - 1},{LR_Row - 2,LR_Col - 2},{LR_Row - 3,LR_Col - 3},{LR_Row - 4,LR_Col - 4},{LR_Row - 5,LR_Col - 5} };
			return true;
		}
		if (_pArr[LR_Row][LR_Col].getCheck() == -turn && _pArr[UL_Row][UL_Col].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {LR_Row - 1 ,LR_Col - 1},{LR_Row - 2,LR_Col - 2},{LR_Row - 3,LR_Col - 3},{LR_Row - 4,LR_Col - 4},{LR_Row - 5,LR_Col - 5} };
			return true;
		}
		if (_pArr[UL_Row][UL_Col].getCheck() == -turn && _pArr[LR_Row][LR_Col].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {UL_Row + 1 ,UL_Col + 1},{UL_Row + 2,UL_Col + 2},{UL_Row + 3,UL_Col + 3},{UL_Row + 4,UL_Col + 4},{UL_Row + 5,UL_Col + 5} };
			return true;
		}
		if (_pArr[UL_Row][UL_Col].getCheck() == _pArr[LR_Row][LR_Col].getCheck() && _pArr[LR_Row][LR_Col].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {UL_Row + 1 ,UL_Col + 1},{UL_Row + 2,UL_Col + 2},{UL_Row + 3,UL_Col + 3},{UL_Row + 4,UL_Col + 4},{UL_Row + 5,UL_Col + 5} };
			return true;
		}
	}
	return false;
}
bool board::checkDiag2(int i, int j, int turn)
{
	int LL_Row = 0, LL_Col = 0, UR_Row = 0, UR_Col = 0;
	// kiểm tra đường chéo 2
	int row = i, col = j, count = 0;
	while (col >= 0 && row <= _size - 1 && _pArr[i][j].getCheck() == _pArr[row][col].getCheck() && _pArr[row][col].getCheck() == turn)
	{
		if ((col == 0 && row == _size - 1) || (col == 0) || (row == _size - 1))
		{
			count++;
			LL_Col = col;
			LL_Row = row;
			break;
		}
		else
		{
			count++;
			row++;
			col--;
			LL_Col = col;
			LL_Row = row;
		}
	}
	row = i; col = j, count--;
	while (row >= 0 && col <= _size - 1 && _pArr[i][j].getCheck() == _pArr[row][col].getCheck() && _pArr[row][col].getCheck() == turn)
	{
		if ((row == 0 && col == _size - 1) || (col == _size - 1) || (row == 0))
		{
			count++;
			UR_Row = row;
			UR_Col = col;
			break;
		}
		else
		{
			count++;
			row--;
			col++;
			UR_Row = row;
			UR_Col = col;
		}
	}
	if (count > 4)
	{
		if (LL_Col == 0 && _pArr[LL_Row][LL_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {LL_Row,LL_Col},{LL_Row - 1 ,LL_Col + 1},{LL_Row - 2,LL_Col + 2},{LL_Row - 3,LL_Col + 3},{LL_Row - 4,LL_Col + 4} };
			return true;
		}
		else if (UR_Col == _size - 1 && _pArr[UR_Row][UR_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {UR_Row,UR_Col},{UR_Row + 1 ,UR_Col - 1},{UR_Row + 2,UR_Col - 2},{UR_Row + 3,UR_Col - 3},{UR_Row + 4,UR_Col - 4} };
			return true;
		}
		else if (LL_Row == _size - 1 && _pArr[LL_Row][LL_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {LL_Row,LL_Col},{LL_Row - 1 ,LL_Col + 1},{LL_Row - 2,LL_Col + 2},{LL_Row - 3,LL_Col + 3},{LL_Row - 4,LL_Col + 4} };
			return true;
		}
		else if (UR_Row == 0 && _pArr[UR_Row][UR_Col].getCheck() == turn)
		{
			_winPos = new gpoint[5]{ {UR_Row,UR_Col},{UR_Row + 1 ,UR_Col - 1},{UR_Row + 2,UR_Col - 2},{UR_Row + 3,UR_Col - 3},{UR_Row + 4,UR_Col - 4} };
			return true;
		}
		else if (_pArr[LL_Row][LL_Col].getCheck() == -turn && _pArr[UR_Row][UR_Col].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {LL_Row - 1 ,LL_Col + 1},{LL_Row - 2,LL_Col + 2},{LL_Row - 3,LL_Col + 3},{LL_Row - 4,LL_Col + 4},{LL_Row - 5,LL_Col + 5} };
			return true;
		}
		else if (_pArr[UR_Row][UR_Col].getCheck() == -turn && _pArr[LL_Row][LL_Col].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {UR_Row + 1 ,UR_Col - 1},{UR_Row + 2,UR_Col - 2},{UR_Row + 3,UR_Col - 3},{UR_Row + 4,UR_Col - 4},{UR_Row + 5,UR_Col - 5} };
			return true;
		}
		else if (_pArr[UR_Row][UR_Col].getCheck() == _pArr[LL_Row][LL_Col].getCheck() && _pArr[LL_Row][LL_Col].getCheck() != -turn)
		{
			_winPos = new gpoint[5]{ {UR_Row + 1 ,UR_Col - 1},{UR_Row + 2,UR_Col - 2},{UR_Row + 3,UR_Col - 3},{UR_Row + 4,UR_Col - 4},{UR_Row + 5,UR_Col - 5} };
			return true;
		}

	}
	return false;
}

long board::scoreAtkRow(int row, int col)
{
	long score_col = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && col + count1 < _size; count1++)
	{
		if (_pArr[row][col + count1].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row][col + count1].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row][col + count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && col + count2 < _size; count2++)
			{
				if (_pArr[row][col + count2].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row][col + count2].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row][col + count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && col - count1 >= 0; count1++)
	{
		if (_pArr[row][col - count1].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row][col - count1].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row][col - count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && col - count2 >= 0; count2++)
			{
				if (_pArr[row][col - count2].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row][col - count2].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row][col - count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_com1 >= 2)
	{
		return 0;
	}
	if (score_com1 == 0)
	{
		score_col += atkPoint[score_player1] * 2;
	}
	else
	{
		score_col += atkPoint[score_player1];
	}
	if (score_com2 == 0)
	{
		score_col += atkPoint[score_player2] * 2;
	}
	else
	{
		score_col += atkPoint[score_player2];
	}
	if (score_player1 >= score_player2)
	{
		score_col -= 1;
	}
	else
	{
		score_col -= 2;
	}
	if (score_player1 == 4)
	{
		score_col *= 2;
	}
	if (score_player1 == 0)
	{
		score_col += defPoint[score_com1] * 2;
	}
	else
	{
		score_col += defPoint[score_com1];
	}
	if (score_player2 == 0)
	{
		score_col += defPoint[score_com2] * 2;
	}
	else
	{
		score_col += defPoint[score_com2];
	}
	return score_col;
}
long board::scoreAtkCol(int row, int col)
{
	long score_row = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && row + count1 < _size; count1++)
	{
		if (_pArr[row + count1][col].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row + count1][col].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row + count1][col].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row + count2 < _size; count2++)
			{
				if (_pArr[row + count2][col].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row + count2][col].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row + count2][col].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && row - count1 >= 0; count1++)
	{
		if (_pArr[row - count1][col].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row - count1][col].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row - count1][col].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row - count2 >= 0; count2++)
			{
				if (_pArr[row - count2][col].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row - count2][col].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row - count2][col].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_com1 >= 2)
	{
		return 0;
	}
	if (score_com1 == 0)
	{
		score_row += atkPoint[score_player1] * 2;
	}
	else
	{
		score_row += atkPoint[score_player1];
	}
	if (score_com2 == 0)
	{
		score_row += atkPoint[score_player2] * 2;
	}
	else
	{
		score_row += atkPoint[score_player2];
	}
	if (score_player1 >= score_player2)
	{
		score_row -= 1;
	}
	else
	{
		score_row -= 2;
	}
	if (score_player1 == 4)
	{
		score_row *= 2;
	}
	if (score_player1 == 0)
	{
		score_row += defPoint[score_com1] * 2;
	}
	else
	{
		score_row += defPoint[score_com1];
	}
	if (score_player2 == 0)
	{
		score_row += defPoint[score_com2] * 2;
	}
	else
	{
		score_row += defPoint[score_com2];
	}
	return score_row;
}
long board::scoreAtkDiag1(int row, int col)
{
	long score_diag1 = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && row + count1 < _size && col + count1 < _size; count1++)
	{
		if (_pArr[row + count1][col + count1].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row + count1][col + count1].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row + count1][col + count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row + count2 < _size && col + count2 < _size; count2++)
			{
				if (_pArr[row + count2][col + count2].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row + count2][col + count2].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row + count2][col + count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && row - count1 >= 0 && col - count1 >= 0; count1++)
	{
		if (_pArr[row - count1][col - count1].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row - count1][col - count1].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row - count1][col - count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row - count2 >= 0 && col - count2 >= 0; count2++)
			{
				if (_pArr[row - count2][col - count2].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row - count2][col - count2].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row - count2][col - count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_com1 >= 2)
	{
		return 0;
	}
	if (score_com1 == 0)
	{
		score_diag1 += atkPoint[score_player1] * 2;
	}
	else
	{
		score_diag1 += atkPoint[score_player1];
	}
	if (score_com2 == 0)
	{
		score_diag1 += atkPoint[score_player2] * 2;
	}
	else
	{
		score_diag1 += atkPoint[score_player2];
	}
	if (score_player1 >= score_player2)
	{
		score_diag1 -= 1;
	}
	else
	{
		score_diag1 -= 2;
	}
	if (score_player1 == 4)
	{
		score_diag1 *= 2;
	}
	if (score_player1 == 0)
	{
		score_diag1 += defPoint[score_com1] * 2;
	}
	else
	{
		score_diag1 += defPoint[score_com1];
	}
	if (score_player2 == 0)
	{
		score_diag1 += defPoint[score_com2] * 2;
	}
	else
	{
		score_diag1 += defPoint[score_com2];
	}
	return score_diag1;
}
long board::scoreAtkDiag2(int row, int col)
{
	long score_diag2 = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && row + count1 < _size && col - count1 < _size; count1++)
	{
		if (_pArr[row + count1][col - count1].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row + count1][col - count1].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row + count1][col - count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row + count2 < _size && col - count2 < _size; count2++)
			{
				if (_pArr[row + count2][col - count2].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row + count2][col - count2].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row + count2][col - count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && row - count1 >= 0 && col + count1 >= 0; count1++)
	{
		if (_pArr[row - count1][col + count1].getCheck() == -1)
		{
			score_player1++;
		}
		if (_pArr[row - count1][col + count1].getCheck() == 1)
		{
			score_com1++;
			break;
		}
		if (_pArr[row - count1][col + count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row - count2 >= 0 && col + count2 >= 0; count2++)
			{
				if (_pArr[row - count2][col + count2].getCheck() == -1)
				{
					score_player2++;
				}
				if (_pArr[row - count2][col + count2].getCheck() == 1)
				{
					score_com2++;
					break;
				}
				if (_pArr[row - count2][col + count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_com1 >= 2)
	{
		return 0;
	}
	if (score_com1 == 0)
	{
		score_diag2 += atkPoint[score_player1] * 2;
	}
	else
	{
		score_diag2 += atkPoint[score_player1];
	}
	if (score_com2 == 0)
	{
		score_diag2 += atkPoint[score_player2] * 2;
	}
	else
	{
		score_diag2 += atkPoint[score_player2];
	}
	if (score_player1 >= score_player2)
	{
		score_diag2 -= 1;
	}
	else
	{
		score_diag2 -= 2;
	}
	if (score_player1 == 4)
	{
		score_diag2 *= 2;
	}
	if (score_player1 == 0)
	{
		score_diag2 += defPoint[score_com1] * 2;
	}
	else
	{
		score_diag2 += defPoint[score_com1];
	}
	if (score_player2 == 0)
	{
		score_diag2 += defPoint[score_com2] * 2;
	}
	else
	{
		score_diag2 += defPoint[score_com2];
	}
	return score_diag2;
}
long board::scoreDefRow(int row, int col)
{
	long  score_col = 0;
	long  score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && col + count1 < _size; count1++)
	{
		if (_pArr[row][col + count1].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row][col + count1].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row][col + count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && col + count2 < _size; count2++)
			{
				if (_pArr[row][col + count2].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row][col + count2].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row][col + count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && col - count1 >= 0; count1++)
	{
		if (_pArr[row][col - count1].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row][col - count1].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row][col - count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && col - count2 >= 0; count2++)
			{
				if (_pArr[row][col - count2].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row][col - count2].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row][col - count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_player1 == 2)
	{
		return 0;
	}
	if (score_player1 == 0)
	{
		score_col += defPoint[score_com1] * 2;
	}
	else
	{
		score_col += defPoint[score_com1];
	}
	if (score_player2 == 0)
		score_col += defPoint[score_com2] * 2;
	else
		score_col += defPoint[score_com2];
	if (score_com1 >= score_com2)
	{
		score_col -= 1;
	}
	else
	{
		score_col -= 2;
	}
	if (score_com1 == 4)
	{
		score_col *= 2;
	}
	return score_col;
}
long board::scoreDefCol(int row, int col)
{
	long score_row = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && row + count1 < _size; count1++)
	{
		if (_pArr[row + count1][col].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row + count1][col].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row + count1][col].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row + count2 < _size; count2++)
			{
				if (_pArr[row + count2][col].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row + count2][col].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row + count2][col].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && row - count1 >= 0; count1++)
	{
		if (_pArr[row - count1][col].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row - count1][col].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row - count1][col].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row - count2 >= 0; count2++)
			{
				if (_pArr[row - count2][col].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row - count2][col].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row - count2][col].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_player1 == 2)
	{
		return 0;
	}
	if (score_player1 == 0)
	{
		score_row += defPoint[score_com1] * 2;
	}
	else
	{
		score_row += defPoint[score_com1];
	}
	if (score_player2 == 0)
		score_row += defPoint[score_com2] * 2;
	else
		score_row += defPoint[score_com2];
	if (score_com1 >= score_com2)
	{
		score_row -= 1;
	}
	else
	{
		score_row -= 2;
	}
	if (score_com1 == 4)
	{
		score_row *= 2;
	}
	return score_row;
}
long board::scoreDefDiag1(int row, int col)
{
	long score_diag1 = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && row + count1 < _size && col + count1 < _size; count1++)
	{
		if (_pArr[row + count1][col + count1].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row + count1][col + count1].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row + count1][col + count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row + count2 < _size && col + count2 < _size; count2++)
			{
				if (_pArr[row + count2][col + count2].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row + count2][col + count2].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row + count2][col + count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && row - count1 >= 0 && col - count1 >= 0; count1++)
	{
		if (_pArr[row - count1][col - count1].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row - count1][col - count1].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row - count1][col - count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row - count2 >= 0 && col - count2 >= 0; count2++)
			{
				if (_pArr[row - count2][col - count2].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row - count2][col - count2].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row - count2][col - count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_player1 == 2)
	{
		return 0;
	}
	if (score_player1 == 0)
	{
		score_diag1 += defPoint[score_com1] * 2;
	}
	else
	{
		score_diag1 += defPoint[score_com1];
	}
	if (score_player2 == 0)
		score_diag1 += defPoint[score_com2] * 2;
	else
		score_diag1 += defPoint[score_com2];
	if (score_com1 >= score_com2)
	{
		score_diag1 -= 1;
	}
	else
	{
		score_diag1 -= 2;
	}
	if (score_com1 == 4)
	{
		score_diag1 *= 2;
	}
	return score_diag1;
}
long board::scoreDefDiag2(int row, int col)
{
	long score_diag2 = 0;
	long score_attack = 0;
	int score_player1 = 0;
	int score_player2 = 0;
	int score_com1 = 0;
	int score_com2 = 0;
	for (int count1 = 1; count1 < 6 && row + count1 < _size && col - count1 < _size; count1++)
	{
		if (_pArr[row + count1][col - count1].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row + count1][col - count1].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row + count1][col - count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row + count2 < _size && col - count2 < _size; count2++)
			{
				if (_pArr[row + count2][col - count2].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row + count2][col - count2].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row + count2][col - count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	for (int count1 = 1; count1 < 6 && row - count1 >= 0 && col + count1 >= 0; count1++)
	{
		if (_pArr[row - count1][col + count1].getCheck() == -1)
		{
			score_player1++;
			break;
		}
		if (_pArr[row - count1][col + count1].getCheck() == 1)
		{
			score_com1++;
		}
		if (_pArr[row - count1][col + count1].getCheck() == 0)
		{
			for (int count2 = 2; count2 < 7 && row - count2 >= 0 && col + count2 >= 0; count2++)
			{
				if (_pArr[row - count2][col + count2].getCheck() == -1)
				{
					score_player2++;
					break;
				}
				if (_pArr[row - count2][col + count2].getCheck() == 1)
				{
					score_com2++;
				}
				if (_pArr[row - count2][col + count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	if (score_player1 == 2)
	{
		return 0;
	}
	if (score_player1 == 0)
	{
		score_diag2 += defPoint[score_com1] * 2;
	}
	else
	{
		score_diag2 += defPoint[score_com1];
	}
	if (score_player2 == 0)
		score_diag2 += defPoint[score_com2] * 2;
	else
		score_diag2 += defPoint[score_com2];
	if (score_com1 >= score_com2)
	{
		score_diag2 -= 1;
	}
	else
	{
		score_diag2 -= 2;
	}
	if (score_com1 == 4)
	{
		score_diag2 *= 2;
	}
	return score_diag2;
}

gpoint board::PVC_easy()
{
	int i, j;
	do
	{
		i = getRandomInt(0, 13), j = getRandomInt(0, 13);
	} while (_pArr[i][j].getCheck() != 0);
	return gpoint(getXAt(i, j), getYAt(i, j));
}

gpoint board::PVC_hard()
{
	int row = 0;
	int col = 0;
	long point = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long atk = 0;
			long def = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				atk += scoreAtkRow(i, j);
				atk += scoreAtkCol(i, j);
				atk += scoreAtkDiag1(i, j);
				atk += scoreAtkDiag2(i, j);
				def += scoreDefRow(i, j);
				def += scoreDefCol(i, j);
				def += scoreDefDiag1(i, j);
				def += scoreDefDiag2(i, j);

				if (atk > def)
				{
					if (point < atk)
					{
						point = atk;
						row = i;
						col = j;
					}
				}
				else
				{
					if (point < def)
					{
						point = def;
						row = i;
						col = j;
					}
				}
			}
		}
	}
	return gpoint(getXAt(row, col), getYAt(row, col));
}

void board::loadBoard(ifstream& inFile)
{
	if (_size == 0)
		return;
	int check = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			inFile >> check;
			_pArr[i][j].setX(4 * j + _left + 3);
			_pArr[i][j].setY(2 * i + _top + 1);
			_pArr[i][j].setCheck(check);
			if (check == 1)
			{
				_countX++;
			}
			else if (check == -1)
			{
				_countO++;
			}
		}
	}
}

void board::saveBoard(ofstream& outFile)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			outFile << setw(3) << _pArr[i][j].getCheck();
		}
		outFile << endl;
	}
}

gpoint* board::getWinPos()
{
	gpoint* b = new gpoint[5];
	for (int i = 0; i < 5; i++)
	{
		int x = _winPos[i].getX(), y = _winPos[i].getY();
		b[i].setX(getXAt(x, y)), b[i].setY(getYAt(x, y));
	}
	return b;
}
