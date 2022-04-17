#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

DWORD WINAPI ThreadProc1(LPVOID);
DWORD WINAPI ThreadProc2(LPVOID);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
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
	static HANDLE hThreadOne, hThreadTwo;
	switch (iMsg)
	{
	case WM_CREATE:
		hThreadOne = CreateThread(NULL, 
									0, 
								(LPTHREAD_START_ROUTINE)ThreadProc1, 
								(LPVOID)hwnd, 
									0, 
									NULL);

		hThreadTwo = CreateThread(NULL,
									0, 
								(LPTHREAD_START_ROUTINE)ThreadProc2, 
								(LPVOID)hwnd,
									0, 
									NULL);

		if (hThreadOne == NULL)
		{
			MessageBox(hwnd, TEXT("Creation of first thread is failed...!!"), TEXT("Error"), MB_OK | MB_ICONERROR);
		}

		if (hThreadTwo == NULL)
		{
			MessageBox(hwnd, TEXT("Creation of second thread is failed...!!"), TEXT("Error"), MB_OK | MB_ICONERROR);
		}
		break;
	
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("It is Fourth Thread...!!"), TEXT("Thread"), MB_OK | MB_ICONINFORMATION);
		break;

	case WM_DESTROY:
		
		CloseHandle(hThreadOne);
		CloseHandle(hThreadTwo);

		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

DWORD WINAPI ThreadProc1(LPVOID param)
{
	HWND hwnd;
	HDC hdc;
	TCHAR str[255];

	hwnd = (HWND)param;
	hdc = GetDC(hwnd);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(0, 255, 0));

	for (int i = 0; i <= 32768; i++)
	{
		wsprintf(str, TEXT("Incrementing = %d"), i);
		TextOut(hdc, 5, 5, str, (int)_tcslen(str));
	}
	ReleaseDC(hwnd, hdc);
	return(0);
}

DWORD WINAPI ThreadProc2(LPVOID param)
{
	HWND hwnd;
	HDC hdc;
	TCHAR str[255];

	hwnd = (HWND)param;
	hdc = GetDC(hwnd);
	SetBkColor(hdc, RGB(0, 0, 0));
	SetTextColor(hdc, RGB(0, 255, 0));

	for (int i = 32768; i >= 0; i--)
	{
		wsprintf(str, TEXT("Decrementing = %d"), i);
		TextOut(hdc, 5, 30, str, (int)_tcslen(str));
	}
	ReleaseDC(hwnd, hdc);
	return(0);
}
