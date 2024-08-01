#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
using namespace std;
#include "Coordinate.h"
#include "Bird.h"
#include <cassert>


/*
 ■■
 ■■
 ■■
 ■■
 ■■
■■■*/

class Column:public Coordinate
{
public:
	void buildColumn(int y, Coordinate &coor);
	void buildColumn(int x,int y, Coordinate &coor);
	void emptyColumn(int x, int y, Coordinate &coor);
	void randomY(int y, Coordinate &coor);
	void firstColumn(int y1, Coordinate &coor);
	void nextColumn(int y2,  int conditionX, Coordinate &coor, Coordinate &coor2);
	void shiftLeftColumn(int birdY, Bird &bird, Coordinate &birdCoor, int y1, Coordinate &coor, int y2, Coordinate &coor2, int y3, Coordinate &coor3, int y4, Coordinate &coor4, int y5, Coordinate &coor5, int y6, Coordinate &coor6, int y7, Coordinate &coor7);
	void printBlock(int x,int y, Coordinate &coor);
	void printImported(int x,int y, Coordinate &coor);
	void printSpace(int x, int y, Coordinate &coor);
protected:
	string block=	 { " ■■"  };
	string imported= { "■■■" };
	string space =	 { "      " };
};




void Column::buildColumn(int y,Coordinate &coor)
{

	assert(y <= 18 && y >= 2);
	coor.m_iX = 74;
	coor.m_iY = y;
	coor.m_iXR = coor.m_iX + 5;
	coor.spaceTopY=y;
	coor.spaceBottomY=y+3;
	int bottom = 30;										//屏幕高度										
	int interval = 5;										//柱子间隔
	int columnY = 0;										//柱子出生位置

	for (int i = 0;i<y - 1;i++)								//打印上半部分柱子
	{
		printBlock(coor.m_iX, columnY,coor);
		columnY++;
	}
	printImported(coor.m_iX, columnY,coor);
	coor.m_iY += interval;									//设置柱子间隔
	printImported(coor.m_iX, coor.m_iY,coor);
	for (int i = 0;i<bottom - interval- y;i++)			//打印下半部分柱子
	{
		coor.m_iY++;
		printBlock(coor.m_iX, coor.m_iY,coor);
	}

}

void Column::buildColumn(int x, int y,Coordinate &coor)
{

	assert(y <= 18 && y >= 2);
	coor.m_iX = x;
	coor.m_iY = y;
	coor.m_iXR = coor.m_iX + 5;
	coor.spaceTopY = y ;
	coor.spaceBottomY = y + 3;
	int bottom = 30;										//屏幕高度										
	int interval = 5;										//柱子间隔
	int columnY = 0;										//柱子出生位置
	for (int i = 0;i<y - 1;i++)								//打印上半部分柱子
	{
		printBlock(coor.m_iX, columnY,coor);
		columnY++;
	}
	printImported(coor.m_iX, columnY, coor);
	coor.m_iY += interval;									//设置柱子间隔
	printImported(coor.m_iX, coor.m_iY, coor);
	for (int i = 0;i<bottom - interval - y;i++)			//打印下半部分柱子
	{
		coor.m_iY++;
		printBlock(coor.m_iX, coor.m_iY, coor);
	}

}

void Column::emptyColumn(int x, int y,Coordinate &coor)
{

	assert(y <= 18 && y >= 2);
	coor.m_iX = x;
	coor.m_iY = y;
	coor.m_iXR = coor.m_iX+5;
	int bottom = 25;										//屏幕高度										
	int interval = 5;										//柱子间隔
	int columnY = 0;										//柱子出生位置
	for (int i = 0;i<y - 1;i++)								//打印上半部分柱子
	{
		printSpace(coor.m_iX, columnY,coor);
		columnY++;
	}
	printSpace(coor.m_iX, columnY,coor);
	coor.m_iY += interval;									//设置柱子间隔
	printSpace(coor.m_iX, coor.m_iY,coor);
	for (int i = 0;i<bottom - interval - y;i++)			//打印下半部分柱子
	{
		coor.m_iY++;
		printSpace(coor.m_iX, coor.m_iY,coor);
	}
	coor.spaceTopY = -1;
	coor.spaceBottomY = 26;

}

void Column::randomY(int y, Coordinate &coor)
{
	coor.m_iYconst = y;
	coor.spaceTopY = y + 1;
	coor.spaceBottomY = y + 4;
	coor.m_iX = 74;
	coor.m_iY = y;
}

void Column::firstColumn(int y1,Coordinate &coor)
{
	
	if (coor.m_iX <= 74 && coor.m_iX>0)
	{

		coor.m_iX--;
		buildColumn(coor.m_iX, y1, coor);

	}
	else if (coor.m_iX == 0)
	{
		coor.spaceTopY = -1;
		coor.spaceBottomY = 26;
		emptyColumn(coor.m_iX, y1, coor);
		system("cls");
		coor.m_iX--;
	}
}

void Column::nextColumn(int y2, int conditionX,Coordinate &coor, Coordinate &nextCoor)
{
	
	if (coor.m_iX <= conditionX && nextCoor.m_iX>0)
	{

		nextCoor.m_iX--;
		buildColumn(nextCoor.m_iX, y2, nextCoor);

	}
	else if (nextCoor.m_iX == 0)
	{
		nextCoor.spaceTopY = -1;
		nextCoor.spaceBottomY = 26;
		emptyColumn(nextCoor.m_iX, y2, nextCoor);
		system("cls");
		nextCoor.m_iX--;
	}
}

void Column::shiftLeftColumn(int birdY, Bird &bird, Coordinate &birdCoor, int y1,Coordinate &coor, int y2,Coordinate &coor2,int y3, Coordinate &coor3, int y4, Coordinate &coor4, int y5, Coordinate &coor5, int y6, Coordinate &coor6, int y7, Coordinate &coor7)
{
	int conditionX = 55;								//判断条件：X所在位置
	int interval = 74 - conditionX;						//柱子间隔
	randomY(y1, coor);
	randomY(y2, coor2);
	randomY(y3, coor3);
	randomY(y4, coor4);
	randomY(y5, coor5);
	randomY(y6, coor6);
	randomY(y7, coor7);	
	//getchar();
	//cout << coor.spaceBottomY<<" "<<coor.spaceTopY << " " << coor.m_iX<<endl;
	//cout << bird.isDeath(coor)<<" "<<birdCoor.birdXHead << " " << birdCoor.birdXTail << " " << birdCoor.birdY;
	for (int i = conditionX + interval * 7;i>0;i--)
	{
		//Sleep(speed);
		bird.isInColumn(bird, birdCoor, coor);if (bird.isdeath == 1) { return; }
		bird.isInColumn(bird, birdCoor, coor2);if (bird.isdeath == 1) { return; }
		bird.isInColumn(bird, birdCoor, coor3);if (bird.isdeath == 1) { return; }
		bird.isInColumn(bird, birdCoor, coor4);if (bird.isdeath == 1) { return; }
		bird.isInColumn(bird, birdCoor, coor5);if (bird.isdeath == 1) { return; }
		bird.isInColumn(bird, birdCoor, coor6);if (bird.isdeath == 1) { return; }
		bird.isInColumn(bird, birdCoor, coor7);if (bird.isdeath == 1) { return; }

		firstColumn(y1, coor);
		nextColumn(y2, conditionX, coor, coor2);
		nextColumn(y3, conditionX, coor2, coor3);
		nextColumn(y4, conditionX, coor3, coor4);
		nextColumn(y5, conditionX, coor4, coor5);
		nextColumn(y6, conditionX, coor5, coor6);
		nextColumn(y7, conditionX, coor6, coor7);

		bird.setBird(birdCoor.birdY,bird);
	}	
}

void Column::printBlock(int x, int y,Coordinate &coor)
{

	coor.setCoordinate(x,y);
	cout << block;

}

void Column::printImported(int x, int y, Coordinate &coor)
{

	coor.setCoordinate(x, y);
	cout << imported;

}

void Column::printSpace(int x, int y, Coordinate &coor)
{

	coor.setCoordinate(x, y);
	cout << space;

}