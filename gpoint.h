#pragma once
class gpoint
{
private:
	int _x;				//Tọa độ ngang
	int _y;				//Tọa độ dọc
	int _check;			//quân cờ trên ô, 1: X, 0: trống, -1: O
public:
	gpoint();			//Phương thức tạo lập
	gpoint(int, int);	//Phương thức tạo lập
	int getX();			//Lấy tọa độ ngang
	int getY();			//Lấy tọa độ dọc
	int getCheck();		//Lấy quân cờ
	void setX(int);		//Gán tọa độ ngang
	void setY(int);		//Gán tọa độ dọc
	bool setCheck(int);	//Gán quân cờ
};
