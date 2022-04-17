//Header
#include<windows.h>
#include"ServerSumSubtractMultiplyDivide.h"

//global Function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable declaration
ISum *pISum = NULL;
ISubtract *pISubtract = NULL;
IMultiply *pIMul = NULL;
IDivide *pIDiv = NULL;

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Variable Declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("COM Client");

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
	void SafeInterfaceRelease(void);

	//Variable Declaration
	HRESULT hr;
	int iNum1, iNum2, iSum, iMul;
	TCHAR str[255];

	//code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISum Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
			DestroyWindow(hwnd);
		}

		iNum1 = 55;
		iNum2 = 45;

		pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);

		wsprintf(str, TEXT("Sum of %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);

		hr = pISum->QueryInterface(IID_ISubtract, (void **)&pISubtract);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("ISubtract Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
			DestroyWindow(hwnd);
		}
		pISum->Release();
		pISum = NULL;

		iNum1 = 300;
		iNum2 = 155;

		pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSum);

		pISubtract->Release();
		pISubtract = NULL;

		wsprintf(str, TEXT("Subtraction of %d and %d is %d"), iNum1, iNum2, iSum);
		MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);

		hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_IMultiply, (void **)&pIMul);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("IMultiplication Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
			DestroyWindow(hwnd);
		}

		iNum1 = 20;
		iNum2 = 20;

		pIMul->MultiplicationOfTwoIntegers(iNum1, iNum2, &iMul);

		wsprintf(str, TEXT("Multiplication of %d and %d is %d"), iNum1, iNum2, iMul);
		MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);

		hr = pIMul->QueryInterface(IID_IDivide, (void **)&pIDiv);

		pIMul->Release();
		pIMul = NULL;

		iNum1 = 50;
		iNum2 = 5;

		pIDiv->DivisionOfTwoIntegers(iNum1, iNum2, &iMul);

		pIDiv->Release();
		pIDiv = NULL;

		wsprintf(str, TEXT("Division of %d and %d is %d"), iNum1, iNum2, iMul);
		MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);


		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void SafeInterfaceRelease(void)
{
	if (pISum)
	{
		pISum->Release();
		pISum = NULL;
	}
	if (pISubtract)
	{
		pISubtract->Release();
		pISubtract = NULL;
	}
	if (pIMul)
	{
		pIMul->Release();
		pIMul = NULL;
	}
	if (pIDiv)
	{
		pIDiv->Release();
		pIDiv = NULL;
	}
}
