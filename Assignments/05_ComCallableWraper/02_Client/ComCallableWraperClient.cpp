#import "Math.tlb" no_namespaces, raw_interfaces_only
#include "math.tlh"

#include<Windows.h>
#include<stdio.h>



//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("COM Automation Client");

	//COM
	HRESULT hr;

	//COM initialisation
	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	//WNDCLASSEX Initialization
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

	//register above class
	RegisterClassEx(&wndclass);

	//create window
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

	// message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	CoUninitialize();
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function declaration
	void ComErrorDescriptionString(HWND, HRESULT);

	HRESULT hr;
	long iNum1, iNum2, iMultiply;
	TCHAR str[255];

	switch (iMsg)
	{
	case WM_CREATE:
		CLSID clsidMath;
		iNum1 = 10;
		iNum2 = 20;
		iMultiply = 0;


		IMath *pIMath;
		hr = CLSIDFromProgID(L"ManagedServerForInterop.Math", &clsidMath);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			DestroyWindow(hwnd);
		}

		hr = CoCreateInstance(clsidMath, NULL, CLSCTX_INPROC_SERVER, __uuidof(_Math), (void **)&pIMath);
		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			DestroyWindow(hwnd);
		}
		
		hr = pIMath->MultiplicationOfTwoIntegers(10, 10, &iMultiply);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			DestroyWindow(hwnd);
		}
		wsprintf(str, TEXT("Multiplication of %d and %d is %d"), iNum1, iNum2, iMultiply);
		MessageBox(hwnd, str, TEXT("Multiplication by CCW"), MB_OK);

		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
void ComErrorDescriptionString(HWND hwnd, HRESULT hr)
{
	TCHAR *szErrorMessage = NULL;
	TCHAR str[255];

	if (FACILITY_WINDOWS == HRESULT_FACILITY(hr))
	{
		hr = HRESULT_CODE(hr);
		if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			hr,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&szErrorMessage,
			0,
			NULL) != 0)
		{
			sprintf_s(str, TEXT("%#x : %s"), hr, szErrorMessage);
			LocalFree(szErrorMessage);
		}
		else
		{
			sprintf_s(str, TEXT("Could not found description for error - %#x."), hr);
		}

	}
	MessageBox(hwnd, str, TEXT("COM ERROR"), MB_OK | MB_ICONERROR);
}
