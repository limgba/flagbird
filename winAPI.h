#pragma once
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
#include "Coordinate.h"		
#include "Column.h"
#include "Score.h"
Column column;
Coordinate coor;
Coordinate coor2;
Coordinate coor3;
Coordinate coor4;
Coordinate coor5;
Coordinate coor6;
Coordinate coor7;
Coordinate birdCoor;
Bird bird;
Score score;
HANDLE hSemaphore;
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hOutBuf = CreateConsoleScreenBuffer(
	GENERIC_READ | GENERIC_WRITE,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	CONSOLE_TEXTMODE_BUFFER,
	NULL
);
HANDLE hOutCur = nullptr;
//HANDLE hOutBuf2 = CreateConsoleScreenBuffer(
//	GENERIC_READ | GENERIC_WRITE,
//	FILE_SHARE_READ | FILE_SHARE_WRITE,
//	NULL,
//	CONSOLE_TEXTMODE_BUFFER,
//	NULL
//);
//HANDLE hOutBuf3 = CreateConsoleScreenBuffer(
//	GENERIC_READ | GENERIC_WRITE,
//	FILE_SHARE_READ | FILE_SHARE_WRITE,
//	NULL,
//	CONSOLE_TEXTMODE_BUFFER,
//	NULL
//);
DWORD bytes = 0;
CONSOLE_CURSOR_INFO cci;
COORD coord = { 0,0 };
const COORD zero_coord = { 0,0 };

const int X = 0;
const int Y = 0;
const int MCOL = 120;
const int MROW = 30;
std::string space_str(MCOL * MROW, ' ');
CHAR_INFO buffer[MROW * MCOL];
COORD coordBufSize = { MCOL, MROW };
COORD coordBufCoord = { X, Y };
SMALL_RECT rect = { X, Y, MCOL, MROW };


DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
	srand((unsigned int)time(NULL));
	int random[8];
	Coordinate empty1;
	int k = 1;
	bird.isdeath = 1;
	birdCoor.birdY = 13;
	score.m_iScore = 0;
	int difficulty = 700;
	int speed = 50;

	SetConsoleActiveScreenBuffer(hOutBuf);
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);
	
	while (bird.isdeath)
	{
		for (int i = 0;i < 8;i++)
		{
			random[i] = rand() % 16 + 2;
		}
		SetConsoleCursorPosition(hOutput, zero_coord);
		printf("%s", space_str.c_str());
		SetConsoleCursorPosition(hOutput, zero_coord);
		cout << "第" << k << "波 速度：" << 375 - speed << " 当前分数" << score.m_iScore << endl;
		ReadConsoleOutput(hOutput, buffer, coordBufSize, coordBufCoord, &rect);
		WriteConsoleOutput(hOutBuf, buffer, coordBufSize, coordBufCoord, &rect);
		int conditionX = 55;								//判断条件：X所在位置
		int interval = 74 - conditionX;						//柱子间隔
		column.randomY(random[1], coor);
		column.randomY(random[2], coor2);
		column.randomY(random[3], coor3);
		column.randomY(random[4], coor4);
		column.randomY(random[5], coor5);
		column.randomY(random[6], coor6);
		column.randomY(random[7], coor7);
		if (score.m_iScore == difficulty * 1)
		{
			speed -= 20;
		}
		else if (score.m_iScore == difficulty * 2)
		{
			speed -= 20;
		}
		else if (score.m_iScore == difficulty * 3)
		{
			speed -= 10;
		}
		for (int i = conditionX + interval * 7;i>0;i--)
		{
			WaitForSingleObject(hSemaphore, INFINITE);
			SetConsoleCursorPosition(hOutput, zero_coord);
			printf("%s", space_str.c_str());
			SetConsoleCursorPosition(hOutput, zero_coord);
			column.firstColumn(random[1], coor);
			column.nextColumn(random[2], conditionX, coor, coor2);
			column.nextColumn(random[3], conditionX, coor2, coor3);
			column.nextColumn(random[4], conditionX, coor3, coor4);
			column.nextColumn(random[5], conditionX, coor4, coor5);
			column.nextColumn(random[6], conditionX, coor5, coor6);
			column.nextColumn(random[7], conditionX, coor6, coor7);
			bird.setBird(birdCoor.birdY, birdCoor);
			empty1.setBirdCoordinate(0, 0);
			cout << "第" << k << "波 速度：" << 375-speed << " 当前分数" << score.m_iScore << endl;
			ReadConsoleOutput(hOutput, buffer, coordBufSize, coordBufCoord, &rect);
			WriteConsoleOutput(hOutBuf, buffer, coordBufSize, coordBufCoord, &rect);
			ReleaseSemaphore(hSemaphore, 1, NULL);

			Sleep(speed);
			bird.isInColumn(bird, birdCoor, coor);
			bird.isInColumn(bird, birdCoor, coor2);
			bird.isInColumn(bird, birdCoor, coor3);
			bird.isInColumn(bird, birdCoor, coor4);
			bird.isInColumn(bird, birdCoor, coor5);
			bird.isInColumn(bird, birdCoor, coor6);
			bird.isInColumn(bird, birdCoor, coor7);
			if (birdCoor.birdXTail == coor.m_iX + 5 ||
				birdCoor.birdXTail == coor2.m_iX + 5 ||
				birdCoor.birdXTail == coor3.m_iX + 5 ||
				birdCoor.birdXTail == coor4.m_iX + 5 ||
				birdCoor.birdXTail == coor5.m_iX + 5 ||
				birdCoor.birdXTail == coor6.m_iX + 5 ||
				birdCoor.birdXTail == coor7.m_iX + 5)//小鸟的尾巴.X == 柱子右边.X
			{
				score.m_iScore+=100;
			}
			if (bird.isdeath == 0)
			{
				empty1.setBirdCoordinate(0, 0);
				cout << "第" << k << "波 速度：" << 375 - speed << " 当前分数" << score.m_iScore << endl;
				cout << "您一共通过了" << k - 1 << "关\n游戏已结束,请按任意键继续" << endl;
				ReadConsoleOutput(hOutput, buffer, coordBufSize, coordBufCoord, &rect);
				WriteConsoleOutput(hOutBuf, buffer, coordBufSize, coordBufCoord, &rect);
				return 0;
			}
		}
		k++;
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParam)
{
	Coordinate empty2;
	birdCoor.birdY=13;
	bird.isdeath = 1;
	while(bird.isdeath)
	{
			SetConsoleActiveScreenBuffer(hOutBuf);
			Sleep(300);
			if(bird.isdeath == 0){return 0;}
			WaitForSingleObject(hSemaphore, INFINITE);
			empty2.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
			cout << bird.space;
			birdCoor.birdY++;
			bird.setBird(birdCoor.birdY, birdCoor);
			ReleaseSemaphore(hSemaphore,1,NULL);
	}
	return 0;
}

DWORD WINAPI ThreadProc3(LPVOID lpParam)
{
	Coordinate empty3;
	bird.isdeath = 1;
	birdCoor.birdY = 13;
	while (bird.isdeath)
	{
			int key = _getch();
			if (key == 119)//w
			{
				WaitForSingleObject(hSemaphore, INFINITE);
				empty3.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
				cout << bird.space;
				birdCoor.birdY -= 2;
				bird.setBird(birdCoor.birdY, birdCoor);
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
			if (key == 72)//↑
			{
				WaitForSingleObject(hSemaphore, INFINITE);
				empty3.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
				cout << bird.space;
				birdCoor.birdY -= 3;
				bird.setBird(birdCoor.birdY, birdCoor);
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
			if (key == 32)//space
			{
				WaitForSingleObject(hSemaphore, INFINITE);
				empty3.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
				cout << bird.space;
				birdCoor.birdY -= 4;
				bird.setBird(birdCoor.birdY, birdCoor);
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
			if (key == 115)//s
			{
				WaitForSingleObject(hSemaphore, INFINITE);
				empty3.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
				cout << bird.space;
				birdCoor.birdY++;
				bird.setBird(birdCoor.birdY, birdCoor);
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
			if (key == 80)//↓
			{
				WaitForSingleObject(hSemaphore, INFINITE);
				empty3.setBirdCoordinate(birdCoor.birdXTail, birdCoor.birdY);
				cout << bird.space;
				birdCoor.birdY+=2;
				bird.setBird(birdCoor.birdY, birdCoor);
				ReleaseSemaphore(hSemaphore, 1, NULL);
			}
	}
	return 0;
}

