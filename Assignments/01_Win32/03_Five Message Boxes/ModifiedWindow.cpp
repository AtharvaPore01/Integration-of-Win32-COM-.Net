#include<Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	MSG msg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("MyApp");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("MyModifiedWindow"),
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
	TCHAR str[255];
	static int a = 5;

	switch (iMsg)
	{

	case WM_CREATE:
		MessageBox(hwnd, TEXT("WM_CREATE Message is sent"), TEXT("First Message Box"), MB_OKCANCEL | MB_ICONINFORMATION);
		break;

	case WM_KEYDOWN:
		MessageBox(hwnd, TEXT("WM_KEYDOWN Message is sent"), TEXT("Second Message Box"), MB_OK | MB_ICONERROR);
		break;

	case WM_LBUTTONDOWN:
			MessageBox(hwnd, TEXT("WM_LBUTTONDOWN Message is sent"), TEXT("My Message"), MB_YESNO | MB_ICONEXCLAMATION);
			break;
	
	case WM_MOVE:
		MessageBox(hwnd, TEXT("WM_MOVE Message is sent"), TEXT("My Message"), MB_OK | MB_ICONHAND);
		break;
	
	case WM_SIZE:
		MessageBox(hwnd, TEXT("WM_SIZE Message is sent"), TEXT("My Message"), MB_YESNOCANCEL | MB_ICONASTERISK);
		break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
