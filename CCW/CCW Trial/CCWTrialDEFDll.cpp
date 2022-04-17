#import "atharva.tlb" no_namespace, raw_interfaces_only
#include "atharva.tlh"
#include<Windows.h>
#include<stdio.h>

//Global Variables
HRESULT hr;
//float iMultiply;
TCHAR str[255];
HWND hwnd;
IMathematics *pIMath;
long iMultiply;
CLSID clsidMath;

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	//code

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
	return(TRUE);

}

extern "C" float Multiply(long num1, long num2)
{
	hr = CLSIDFromProgID(L"ManagedServerForInterop.Math", &clsidMath);
	hr = CoCreateInstance(clsidMath, NULL, CLSCTX_INPROC_SERVER, __uuidof(IMathematics), (void **)&pIMath);
	hr = pIMath->MultiplicationOfTwoIntegers(num1, num2, &iMultiply);

	return(iMultiply);
}
