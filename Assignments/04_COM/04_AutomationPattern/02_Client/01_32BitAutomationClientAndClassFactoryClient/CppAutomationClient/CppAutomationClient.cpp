//Headers
#include<Windows.h>
#include<stdio.h>
#include"AutomationServerWithRegFile.h"

//Global Function Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR iCmdLine, int iCmdShow)
{
	//Variable Declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("COM Automation Client of C++");

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbWndExtra = 0;
	wndclass.cbClsExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;

	//Register the window
	RegisterClassEx(&wndclass);

	//Create window
	hwnd = CreateWindow(AppName,
		TEXT("Client of COM Automation"),
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

	return((int)msg.wParam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function declaration
	void ComErrorDescriptionString(HWND, HRESULT);
	
	//Variable Declaration
	IDispatch *pIDispatch = NULL;
	HRESULT hr;
	DISPID dispid;
	OLECHAR *szFunctionName1 = (wchar_t *)L"SumOfTwoIntegers";
	OLECHAR *szFunctionaName2 = (wchar_t *)L"SubtractionOfTwoIntegers";
	VARIANT vArg[2], vRet;
	DISPPARAMS param = { vArg, 0, 2, NULL };
/*
	Following Structure is of DISPPARAMS Declared Above as DISPPARAMS param = { vArg, 0, 2, NULL } which is of type
	spot initialization of the structure.

	struct DISPPARAMS
	{
		VARIANTARG *rgvarg;				----> vArg
		DISPID *rgdispidNamedArgs;		----> NULL
		UINT cArgs;						----> 2
		UINT cNamedArgs;				----> 0
	};

*/

	int iNum1, iNum2;
	TCHAR str[255];

	//code
	switch (iMsg)
	{
	case WM_CREATE:
		//COM initialization
		hr = CoInitialize(NULL);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			MessageBox(hwnd, TEXT("Component Can Not be created."), TEXT("Error"), MB_OK | MB_ICONERROR);
			DestroyWindow(hwnd);
			exit(0);
		}

		hr = CoCreateInstance(CLSID_MyMath, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void **)&pIDispatch);
		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			MessageBox(hwnd, TEXT("Component Can Not be created."), TEXT("Error"), MB_OK | MB_ICONERROR);
			DestroyWindow(hwnd);
			exit(0);
		}

		iNum1 = 75;
		iNum2 = 25;
		// as DispParams rgvargs member receives parameters in reverse order
		
		VariantInit(vArg);
		vArg[0].vt = VT_INT;
		vArg[0].intVal = iNum2;
		vArg[1].vt = VT_INT;
		vArg[1].intVal = iNum1;

		//Filling in the DISPPARAMS param = { vArg, 0, 2, NULL };

		param.cArgs = 2;
		param.rgdispidNamedArgs = NULL;
		param.cNamedArgs = 0;
		param.rgvarg = vArg;

		VariantInit(&vRet);

		hr = pIDispatch->GetIDsOfNames(IID_NULL,
			&szFunctionName1,
			1,
			GetUserDefaultLCID(),
			&dispid);
		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			MessageBox(hwnd, TEXT("Component Can Not be created."), TEXT("Error"), MB_OK | MB_ICONERROR);
			pIDispatch->Release();
			DestroyWindow(hwnd);
			//exit(0);
		}

		hr = pIDispatch->Invoke(dispid,
			IID_NULL,
			GetUserDefaultLCID(),
			DISPATCH_METHOD,
			&param,
			&vRet,
			NULL,
			NULL);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			MessageBox(hwnd, TEXT("Component Can Not be created."), TEXT("Error"), MB_OK | MB_ICONERROR);
			pIDispatch->Release();
			DestroyWindow(hwnd);
			//exit(0);
		}
		else
		{
			wsprintf(str, TEXT("Sum of %d and %d is %d"), iNum1, iNum2, vRet.lVal);
			MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
		}
		
		hr = pIDispatch->GetIDsOfNames(IID_NULL,
			&szFunctionaName2,
			1,
			GetUserDefaultLCID(),
			&dispid);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			MessageBox(hwnd, TEXT("Component Can Not be created."), TEXT("Error"), MB_OK | MB_ICONERROR);
			pIDispatch->Release();
			DestroyWindow(hwnd);
			//exit(0);
		}

		hr = pIDispatch->Invoke(dispid,
			IID_NULL,
			GetUserDefaultLCID(),
			DISPATCH_METHOD,
			&param,
			&vRet,
			NULL,
			NULL);
		if (FAILED(hr))
		{
			ComErrorDescriptionString(hwnd, hr);
			MessageBox(hwnd, TEXT("Component Can Not be created."), TEXT("Error"), MB_OK | MB_ICONERROR);
			pIDispatch->Release();
			DestroyWindow(hwnd);
			//exit(0);
		}
		else
		{
			wsprintf(str, TEXT("Subtraction of %d and %d is %d"), iNum1, iNum2, vRet.lVal);
			MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
		}

		//clean-up
		VariantClear(vArg);
		VariantClear(&vRet);
		pIDispatch->Release();
		pIDispatch = NULL;
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		CoUninitialize();
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
