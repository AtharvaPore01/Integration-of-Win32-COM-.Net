#include<Windows.h>
#include<stdio.h>
#include"MathDEFDll.h"
#include"MathCOMDll.h"

//varibles Declaration
HWND hwnd;
HRESULT hr;
TCHAR str[255];
ISideOne *pISideOne = NULL;
ISideTwo *pISideTwo = NULL;
ISideThree *pISideThree = NULL;
IAngleOfTriangle *pIAngle = NULL;
ITypeOfTriangle *pITriangle = NULL;
double s1, s2, s3, triangle, angle;




BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	//code
	

	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	CoUninitialize();
	return(TRUE);

}

extern "C" double FirstSide(double x1, double x2, double y1, double y2)
{
	
	

	hr = CoCreateInstance(CLSID_Triangle, NULL, CLSCTX_INPROC_SERVER, IID_ISideOne, (void **)&pISideOne);
	if (FAILED(hr))
	{
		MessageBox(hwnd, TEXT("ISideOne Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}

	pISideOne->SideOne(x1, x2, y1, y2, &s1);
	//sprintf_s(str, TEXT("Side One with vertices %f, %f, %f, %f is %f"), x1, x2, y1, y2, s1);
	//MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
	pISideOne->Release();
	pISideOne = NULL;

	return(s1);

}
extern "C" double SecondSide(double x2, double x3, double y2, double y3)
{
	hr = CoCreateInstance(CLSID_Triangle, NULL, CLSCTX_INPROC_SERVER, IID_ISideTwo, (void **)&pISideTwo);
	if (FAILED(hr))
	{
		MessageBox(hwnd, TEXT("ISideTwo Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}

	pISideTwo->SideTwo(x2, x3, y2, y3, &s2);
	//sprintf_s(str, TEXT("Side Two with vertices %f, %f, %f, %f is %f"), x2, x3, y2, y3, s2);
	//MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
	pISideTwo->Release();
	pISideOne = NULL;

	return(s2);
}
extern "C" double ThirdSide(double x3, double x1, double y3, double y1)
{
	hr = CoCreateInstance(CLSID_Triangle, NULL, CLSCTX_INPROC_SERVER, IID_ISideThree, (void **)&pISideThree);
	if (FAILED(hr))
	{
		MessageBox(hwnd, TEXT("ISideThree Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}

	pISideThree->SideThree(x3, x1, y3, y1, &s3);
	//sprintf_s(str, TEXT("Side Three with vertices %f, %f, %f, %f is %f"), x3, x1, y3, y1, s3);
	//MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
	pISideThree->Release();
	pISideThree = NULL;

	return(s3);
}

extern "C" double TriangleIs(double a1, double a2, double a3)
{
	hr = CoCreateInstance(CLSID_Triangle, NULL, CLSCTX_INPROC_SERVER, IID_ITypeOfTriangle, (void **)&pITriangle);
	if (FAILED(hr))
	{
		MessageBox(hwnd, TEXT("ITypeOfTriangle Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	
	pITriangle->TriangleIs(a1, a2, a3, &triangle);
	//sprintf_s(str, TEXT("Triangle With Angles %f, %f, %f is %f"), a1, a2, a3, triangle);
	//MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
	pITriangle->Release();
	pITriangle = NULL;

	return(triangle);

}

extern "C" double AngleIs(double a1, double a2, double a3)
{
	hr = CoCreateInstance(CLSID_Triangle, NULL, CLSCTX_INPROC_SERVER, IID_IAngleOfTriangle, (void **)&pIAngle);
	if (FAILED(hr))
	{
		MessageBox(hwnd, TEXT("IAngleOfTriangle Interface Cannot be obtained"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}

	pIAngle->AngleIs(a1, a2, a3, &angle);
	//sprintf_s(str, TEXT("Type of Triangle With Angles %f, %f, %f is %f"), a1, a2, a3, angle);
	//MessageBox(hwnd, str, TEXT("RESULT"), MB_OK);
	pIAngle->Release();
	pIAngle= NULL;

	return(angle);

}
