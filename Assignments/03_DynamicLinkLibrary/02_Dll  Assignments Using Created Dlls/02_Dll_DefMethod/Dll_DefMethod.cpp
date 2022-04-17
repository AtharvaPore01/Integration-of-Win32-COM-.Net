#include<Windows.h>
#include"MyDll.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declaration

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyDll");

	//code

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("My Dll Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);

	//MessageLoop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//variable declaration

	int n = 36;
	int square;
	TCHAR str[255];

	//Dll
	HMODULE hLib = NULL;
	typedef int(*pfnMakeSquare) (int);
	pfnMakeSquare pfn = NULL;

	//code

	switch (iMsg)
	{

	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'S':
			
			hLib = LoadLibrary(TEXT("DllUsingModuleDefinitionFile.dll"));
			if (hLib == NULL)
			{
				MessageBox(hwnd, TEXT("Dll didn't get load...\n Exiting the program...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
				DestroyWindow(hwnd);
			}

			//GetProcAddress(hLib, "MakeSquare");
			pfn = (pfnMakeSquare)GetProcAddress(hLib, "MakeSquare");
			square = pfn(n);

			wsprintf(str, "%d", square);
			MessageBox(hwnd, str, TEXT("Sqaure of Number is"), MB_OK);

			FreeLibrary(hLib);
			break;
		}

		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
