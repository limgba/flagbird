#pragma once
#include "Coordinate.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include "Column.h"
#include <conio.h>
using namespace std;

class Bird:public Coordinate
{
public:
	Bird();
	void setBird(int y, Coordinate &birdCoor);
	bool isDeath(Coordinate &birdCoor, Coordinate &coor);
	void isInColumn(Bird &bird, Coordinate &birdCoor, Coordinate &coor);
public:
	string up =		{ "↗" };
	string run =	{ "囧" };
	string down =	{ "↘" };
	string death =	{ "卐" };
	string space2 =	{ "  " };
	string space =	{ "      " };
};

Bird::Bird()
{
	birdXTail=30;
	birdXHead = birdXTail+1;
	birdY=13;
}

void Bird::setBird(int y,Coordinate &birdCoor)
{
	birdCoor.birdXTail = 30;
	birdCoor.birdXHead = birdCoor.birdXTail + 1;
	birdCoor.birdY = y;
	birdCoor.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
	cout << run;
}

bool Bird::isDeath(Coordinate &birdCoor,Coordinate &coor)
{
	if (birdCoor.birdXHead >= coor.m_iX && birdCoor.birdXTail <= coor.m_iXR &&
		birdCoor.birdY < coor.spaceTopY  ||				//撞到上半边柱子
		birdCoor.birdXHead >= coor.m_iX && birdCoor.birdXTail <= coor.m_iXR &&
		birdCoor.birdY > coor.spaceBottomY ||			//撞到下半边柱子
		birdCoor.birdXHead < coor.m_iX && birdCoor.birdXTail > coor.m_iXR &&
		birdCoor.birdY <= 0 ||							//在最上面一行
		birdCoor.birdXHead < coor.m_iX && birdCoor.birdXTail > coor.m_iXR &&
		birdCoor.birdY >= 24)							//在最下面一行
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Bird::isInColumn(Bird &bird,Coordinate &birdCoor, Coordinate &coor)
{
	if(bird.isDeath(birdCoor, coor) == true)
	{
		bird.isdeath = 0;
	}
}