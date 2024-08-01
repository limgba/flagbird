#pragma once
#include <windows.h>	
//#include "Column.h"
#include <stdio.h>	


class Coordinate
{
public:
	Coordinate();
	Coordinate(const Coordinate &coor);
	void setCoordinate(SHORT x, SHORT y);						//设置坐标
	void setBirdCoordinate(SHORT x, SHORT y);
	SHORT upward(SHORT y);										//坐标上移
	SHORT downward(SHORT y);									//坐标下移
	SHORT leftward(SHORT x);									//坐标左移
	SHORT rightward(SHORT x);									//坐标右移
public:
	SHORT m_iX;
	SHORT m_iY;
	SHORT m_iYconst;											//暂时无用
	SHORT m_iXR=m_iX+5;										//柱子右X坐标

	SHORT birdXTail;
	SHORT birdY;
	SHORT birdXHead= birdXTail + 1;
	SHORT birdYB= birdY;										//暂时无用

	SHORT spaceTopY;											//可飞行的最上一行
	SHORT spaceBottomY;										//可飞行的最下一行
	SHORT isdeath;
};

Coordinate::Coordinate()
{
	m_iX = 0;
	m_iY = 0;
	//HANDLE hOut;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);					// 获取标准输出设备句柄
}
Coordinate::Coordinate(const Coordinate &coor)
{
	m_iX = 0;
	m_iY = 0;
	//HANDLE hOut;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);					// 获取标准输出设备句柄
}
void Coordinate::setCoordinate(SHORT x, SHORT y)
{
	m_iX = x;
	m_iY = y;
	COORD pos = { m_iX, m_iY };								//设置坐标
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Coordinate::setBirdCoordinate(SHORT x, SHORT y)
{
	birdXTail = x;
	birdY = y;
	COORD pos = { birdXTail, birdY };								//设置坐标
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

SHORT Coordinate::upward(SHORT y)
{
	m_iY+=y;
	return y;
}

SHORT Coordinate::downward(SHORT y)
{
	m_iY -= y;
	return y;
}

SHORT Coordinate::leftward(SHORT x)
{
	m_iX -= x;
	return x;
}

SHORT Coordinate::rightward(SHORT x)
{
	m_iX += x;
	return x;
}


