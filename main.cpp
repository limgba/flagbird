//������ɼ��ΪG������--------------------------------------------------
//ÿN������һ������
//���ӳ�����N��ÿ�룬�����ƶ�
//�Ѷ����ӣ����Ӽ����С���ٶȼӿ�
//
//С���������������ƶ�
//С�����Ϸ�
//С����������
//С��ɹ����ӣ���������

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
	SetConsoleTitle(L"����Թ����˵�3��(����W=�� S=�� С���̡�=���� С���̡�=���� �ո�=������  )");
	while (1)
	{
		HANDLE thread[nCount];
		hSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
		thread[0] = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);		//�����˶�
		thread[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);		//���˶�
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
