#include "gpoint.h"

gpoint::gpoint()
{
	_x = _y = _check = 0;
}

gpoint::gpoint(int pX, int pY)
{
	_x = pX; _y = pY;
	_check = 0;
}

int gpoint::getX()
{
	return _x;
}

int gpoint::getY()
{
	return _y;
}

int gpoint::getCheck()
{
	return _check;
}

void gpoint::setX(int pX)
{
	_x = pX;
}

void gpoint::setY(int pY)
{
	_y = pY;
}

bool gpoint::setCheck(int pCheck)
{
	if (pCheck == -1 || pCheck == 1 || pCheck == 0)
	{
		_check = pCheck;
		return true;
	}
	return false;
}
