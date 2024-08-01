//随机生成间隔为G的柱子--------------------------------------------------
//每N秒生成一对柱子
//柱子持续以N次每秒，向左移动
//难度增加，柱子间隔变小，速度加快
//
//小鸟向下自由落体移动
//小鸟向上飞
//小鸟碰到柱子
//小鸟飞过柱子，分数增加

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
#include "Coordinate.h"		
#include "Column.h"
#include "winAPI.h"
const DWORD nCount =3;


int main()
{
	SetConsoleTitle(L"你绝对过不了第3波(键盘W=↑ S=↓ 小键盘↑=↑↑ 小键盘↓=↓↓ 空格=↑↑↑  )");
	while (1)
	{
		HANDLE thread[nCount];
		hSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
		thread[0] = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);		//柱子运动
		thread[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);		//鱼运动
		thread[2] = CreateThread(NULL, 0, ThreadProc3, NULL, 0, NULL);
		WaitForMultipleObjects(nCount, thread, TRUE, INFINITE);
		CloseHandle(hSemaphore);
		
		for (int i = 0;i < nCount;i++)
		{
			CloseHandle(thread[i]);
		}
	}
	CloseHandle(hOutput);
	CloseHandle(hOutBuf);
}
