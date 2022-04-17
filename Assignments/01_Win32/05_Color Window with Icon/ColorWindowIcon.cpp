#include<Windows.h>
#include<wingdi.h>
#include"MyIcon.h"



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("Window Colouring"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	static HDC hdc;
	RECT rc;
	HBRUSH hMyBrush;
	GetClientRect(hwnd, &rc);
	static char key;
	
	switch (iMsg)
	{
	
	case WM_KEYDOWN:
		
		switch (wParam)
		{
		case 'R':
			key = 'R';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'G':
			key = 'G';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'B':
			key = 'B';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'C':
			key = 'C';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'Y':
			key = 'Y';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'W':
			key = 'W';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'K':
			key = 'K';
			InvalidateRect(hwnd, &rc, 0);
			break;
		case 'M':
			key = 'M';
			InvalidateRect(hwnd, &rc, 0);
			break;
		default:
			key = 'd';
			break;

		}

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);
		SelectObject(hdc, &hMyBrush);
		switch (key)
		{
		case 'R':
			hMyBrush = CreateSolidBrush(RGB(255, 0, 0));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'G':
			hMyBrush = CreateSolidBrush(RGB(0, 255, 0));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'B':
			hMyBrush = CreateSolidBrush(RGB(0, 0, 255));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'C':
			hMyBrush = CreateSolidBrush(RGB(0, 255, 255));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'Y':
			hMyBrush = CreateSolidBrush(RGB(255, 255, 0));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'W':
			hMyBrush = CreateSolidBrush(RGB(255, 255, 255));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'K':
			hMyBrush = CreateSolidBrush(RGB(0, 0, 0));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		case 'M':
			hMyBrush = CreateSolidBrush(RGB(255, 0, 255));
			FillRect(hdc, &rc, hMyBrush);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		default:
			hMyBrush = CreateSolidBrush(RGB(128, 128, 128));
			FillRect(hdc, &rc, hMyBrush);

			break;
		}
		DeleteObject(hMyBrush);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
