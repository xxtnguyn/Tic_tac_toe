#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include "gpoint.h"
#include "common.h"

const long atkPoint[6] = { 0, 64, 4096, 262144, 16777216, 1073741824 }; //Mảng điểm tấn công
const long defPoint[6] = { 0, 8, 512, 32768, 2097152, 134217728 };      //Mảng điểm phòng thủ
using namespace std;

class board
{
private:
	int _size;              //Kích cỡ bàn cờ
	int _left, _top;        //Tọa độ bắt đầu bàn cờ
	int _countX, _countO;   //Đếm số quân cờ mỗi người chơi
	gpoint* _winPos;        //Vị trí 5 quân cờ thắng
	gpoint** _pArr;         //Mảng vị trí ô cờ
public:
	board(int, int, int);			//Phương thức dựng
	~board();						//Phương thức hủy
	int getSize();					//Lấy kích cỡ
	int getLeft();					//Lấy tọa độ ngang bắt đầu bàn cờ
	int getTop();					//Lấy tọa độ dọc bắt đầu bàn cờ
	int getCountX();				//Lấy số quân cờ X
	int getCountO();				//Lấy số quân cờ )
	int getXAt(int, int);			//Lấy tọa độ ngang tại ô
	int getYAt(int, int);			//Lấy tọa độ dọc tại ô
	void resetData();				//Cài lại bàn cờ
	void drawBoard();				//Vẽ bàn cờ
	int checkBoard(int, int, bool); //Kiểm tra tọa độ trên bàn cờ
	int testBoard(int, int);        //Kiểm tra thắng thua
	int getCheckAtXY(int, int);     //Lấy quân cờ ở ô
	bool checkRow(int, int, int);   //Kiểm tra thắng ỏ dòng
	bool checkCol(int, int, int);	//Kiểm tra thắng ở cột
	bool checkDiag1(int, int, int); //Kiểm tra thắng ở chéo 1
	bool checkDiag2(int, int, int); //Kiểm tra thắng ở chéo 2
	long scoreAtkRow(int, int);     //Tính điểm tấn công của dòng
	long scoreAtkCol(int, int);		//Tính điểm tấn công của cột
	long scoreAtkDiag1(int, int);   //Tính điểm tấn công của chéo 1
	long scoreAtkDiag2(int, int);   //Tính điểm tấn công của chéo 2
	long scoreDefRow(int, int);     //Tính điểm phòng thủ của dòng
	long scoreDefCol(int, int);		//Tính điểm phòng thủ của cột
	long scoreDefDiag1(int, int);	//Tính điểm phòng thủ của chéo 1
	long scoreDefDiag2(int, int);	//Tính điểm phòng thủ của chéo 2
	gpoint PVC_hard();				//Tìm vị trí chế độ máy khó
	gpoint PVC_easy();				//Tìm vị trí chế độ máy dễ
	void loadBoard(ifstream&);		//Load vị trí X,O
	void saveBoard(ofstream&);		//Lưu vị trí X,O
	gpoint* getWinPos();			//Lấy vị trí thắng
};
