//============================================================================
// Name        : CatchWin.cpp
// Author      : ��צ����
// Version     :
// Copyright   : û�а�Ȩ
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <windows.h>
#include <iostream>
using namespace std;

int main() {
	BOOL ret;
	while (true) {
		POINT point;
		ret = GetCursorPos(&point);
		if (!ret) {
			cout << "��ȡ���λ�ó��� -> fail(" << GetLastError() << ")" << endl;
			Sleep(1000);
			continue;
		}
		cout << "��ȡ���λ�óɹ� -> (" << point.x << "," << point.y << ")" << endl;
		//��ȡ��������WindowFromPoint�ú�����ð���ָ����Ĵ��ڵľ��
		HWND hwnd = WindowFromPoint(point);
		if (hwnd == NULL || hwnd == INVALID_HANDLE_VALUE) {
			cout << "��ȡ����㴦(" << point.x << "," << point.y << ")" << "�Ĵ��ڳ���" << GetLastError() << endl;
			Sleep(1000);
			continue;
		}
		//
		cout << "�ɹ���ȡ���� -> ���=" << hwnd << endl;
		// �̹߳���2��
		Sleep(2000);
	}
	system("pause");
	return 0;
}
