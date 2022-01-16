//Headers
#include<Windows.h>
#include<stdio.h>
#include"ChemComDll.h"

//CCW Headers
#import "ChemistryDotNetDll.tlb" no_namespace, raw_interfaces_only
#include "Debug\chemistrydotnetdll.tlh"

//Global Variables for ccw
HWND hwnd;
HRESULT hr;
CLSID clsidChemistry;
IChemistry *pIChemistry;
void ComErrorDescriptionString(HWND, HRESULT);
float pQ1, pQ2, E, WD, COPr, COPac;
//void Initialise(void);
//void UnInitialise(void);


//main
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	
	//Initialise();
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
	//UnInitialise();
	return(TRUE);

}


extern "C" void Initialise(void)
{
	
	hr = CoInitialize(NULL);

	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	//MessageBox(NULL, TEXT("COM Library Chalu Zali"), TEXT("Program"), MB_OK | MB_ICONERROR);
}



//Q1 = W + Q2
extern "C" double Q_1(double w, double q2)
{
	//hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	hr = CLSIDFromProgID(L"Chemistry.ChemistryDotNetDll", &clsidChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	hr = CoCreateInstance(clsidChemistry, NULL, CLSCTX_INPROC_SERVER, __uuidof(IChemistry), (void **)&pIChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}

	hr = pIChemistry->Q1(w, q2, &pQ1);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//CoUninitialize();
	return(pQ1);
}

//Q2 = Q1 - W
extern "C" double Q_2(double w, double q1)
{
	//hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	hr = CLSIDFromProgID(L"Chemistry.ChemistryDotNetDll", &clsidChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	hr = CoCreateInstance(clsidChemistry, NULL, CLSCTX_INPROC_SERVER, __uuidof(IChemistry), (void **)&pIChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}

	hr = pIChemistry->q2(q1, w, &pQ2);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//CoUninitialize();
	return(pQ2);
}

//Efficiency = W / Q1
extern "C" double EfficiencyOfHeatEngine(double w, double q1)
{
	//hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	hr = CLSIDFromProgID((wchar_t *)L"Chemistry.ChemistryDotNetDll", &clsidChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//MessageBox(NULL, TEXT("CoCreateInstance"), TEXT("EfficiencyOfHeatEngine"), MB_OK);
	hr = CoCreateInstance(clsidChemistry, NULL, CLSCTX_INPROC_SERVER, __uuidof(IChemistry), (void **)&pIChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
//	MessageBox(NULL, TEXT("CoCreateInstance Succeeded"), TEXT("EfficiencyOfHeatEngine"), MB_OK);
	hr = pIChemistry->Efficiency(w, q1, &E);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//CoUninitialize();
	return(E);
}

//WorkDone = Q1-Q2
extern "C" double Work_Done(double q1, double q2)
{
	//hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	hr = CLSIDFromProgID((wchar_t *)L"Chemistry.ChemistryDotNetDll", &clsidChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//MessageBox(NULL, TEXT("CoCreateInstance"), TEXT("Work_Done"), MB_OK);
	hr = CoCreateInstance(clsidChemistry, NULL, CLSCTX_INPROC_SERVER, __uuidof(IChemistry), (void **)&pIChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//MessageBox(NULL, TEXT("CoCreateInstance Succeeded"), TEXT("Work_Done"), MB_OK);
	hr = pIChemistry->WorkDone(q1, q2, &WD);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//CoUninitialize();
	return(WD);
}

//COP = Q2 / W
//This COP is of Refrigerator
extern "C" double Coefficient_Of_PerformanceR(double w, double q2)
{
	//hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	hr = CLSIDFromProgID(L"Chemistry.ChemistryDotNetDll", &clsidChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	hr = CoCreateInstance(clsidChemistry, NULL, CLSCTX_INPROC_SERVER, __uuidof(IChemistry), (void **)&pIChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}

	hr = pIChemistry->CoefficientOfPerformanceR(q2, w, &COPr);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//CoUninitialize();
	return(COPr);
}

//COP = Q1 / W
//This COP is of Air Conditioner
extern "C" double Coefficient_Of_PerformanceAC(double w, double q1)
{
	//hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Chalu Honar Nahi...!\n Ghari Ja...!"), TEXT("Program Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	hr = CLSIDFromProgID(L"Chemistry.ChemistryDotNetDll", &clsidChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	hr = CoCreateInstance(clsidChemistry, NULL, CLSCTX_INPROC_SERVER, __uuidof(IChemistry), (void **)&pIChemistry);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}

	hr = pIChemistry->CoefficientOfPerformanceAC(w, q1, &COPac);
	if (FAILED(hr))
	{
		ComErrorDescriptionString(hwnd, hr);
		DestroyWindow(hwnd);
	}
	//CoUninitialize();
	return(COPac);
}

extern "C" void UnInitialise(void)
{
	//pIChemistry == NULL;
	CoUninitialize();
	//MessageBox(NULL, TEXT("COM Library Chalu banda Zali"), TEXT("Program"), MB_OK | MB_ICONERROR);
	
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
			wsprintf(str, TEXT(" %s"), hr, szErrorMessage);
			LocalFree(szErrorMessage);
		}
		else
		{
			sprintf_s(str, TEXT("Could not found description for error - %#x."), hr);
		}

	}
	MessageBox(hwnd, str, TEXT("COM ERROR"), MB_OK | MB_ICONERROR);
}
