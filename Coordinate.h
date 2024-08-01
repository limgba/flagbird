#pragma once
#include <windows.h>	
//#include "Column.h"
#include <stdio.h>	


class Coordinate
{
public:
	Coordinate();
	Coordinate(const Coordinate &coor);
	void setCoordinate(SHORT x, SHORT y);						//��������
	void setBirdCoordinate(SHORT x, SHORT y);
	SHORT upward(SHORT y);										//��������
	SHORT downward(SHORT y);									//��������
	SHORT leftward(SHORT x);									//��������
	SHORT rightward(SHORT x);									//��������
public:
	SHORT m_iX;
	SHORT m_iY;
	SHORT m_iYconst;											//��ʱ����
	SHORT m_iXR=m_iX+5;										//������X����

	SHORT birdXTail;
	SHORT birdY;
	SHORT birdXHead= birdXTail + 1;
	SHORT birdYB= birdY;										//��ʱ����

	SHORT spaceTopY;											//�ɷ��е�����һ��
	SHORT spaceBottomY;										//�ɷ��е�����һ��
	SHORT isdeath;
};

Coordinate::Coordinate()
{
	m_iX = 0;
	m_iY = 0;
	//HANDLE hOut;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);					// ��ȡ��׼����豸���
}
Coordinate::Coordinate(const Coordinate &coor)
{
	m_iX = 0;
	m_iY = 0;
	//HANDLE hOut;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);					// ��ȡ��׼����豸���
}
void Coordinate::setCoordinate(SHORT x, SHORT y)
{
	m_iX = x;
	m_iY = y;
	COORD pos = { m_iX, m_iY };								//��������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Coordinate::setBirdCoordinate(SHORT x, SHORT y)
{
	birdXTail = x;
	birdY = y;
	COORD pos = { birdXTail, birdY };								//��������
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


