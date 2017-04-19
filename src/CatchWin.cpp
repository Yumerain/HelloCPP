//============================================================================
// Name        : CatchWin.cpp
// Author      : 八爪章鱼
// Version     :
// Copyright   : 没有版权
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
			cout << "获取鼠标位置出错 -> fail(" << GetLastError() << ")" << endl;
			Sleep(1000);
			continue;
		}
		cout << "获取鼠标位置成功 -> (" << point.x << "," << point.y << ")" << endl;
		//获取桌面句柄：WindowFromPoint该函数获得包含指定点的窗口的句柄
		HWND hwnd = WindowFromPoint(point);
		if (hwnd == NULL || hwnd == INVALID_HANDLE_VALUE) {
			cout << "获取坐标点处(" << point.x << "," << point.y << ")" << "的窗口出错：" << GetLastError() << endl;
			Sleep(1000);
			continue;
		}
		//
		cout << "成功获取窗口 -> 句柄=" << hwnd << endl;
		// 线程挂起2秒
		Sleep(2000);
	}
	system("pause");
	return 0;
}
