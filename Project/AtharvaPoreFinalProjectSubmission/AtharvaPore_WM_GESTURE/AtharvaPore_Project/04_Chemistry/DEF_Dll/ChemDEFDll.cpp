#pragma comment(lib, "ChemComDll.lib")
//Headers
#include<Windows.h>
#include<stdio.h>
#include"ChemComDll.h"
#include"ChemDEFDll.h"

//global variables
double q1, q2, E, WD, COPr, COPac;
HWND hwnd;
//main
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	//code
	//Initialise();
	
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

extern "C" double HeatEngineWD(double q_1, double q_2)
{
	if(q_1 == NULL || q_2 == NULL)
	{
		MessageBox(hwnd, TEXT("Q1 or Q2 field is Empty...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
	}
	//Initialise();
	WD = Work_Done(q_1, q_2);			//WorkDone
	//UnInitialise();
	return(WD);
	
}
extern "C" double HeatEngineEff(double W, double q_1)
{
	if(W == NULL || q_1 == NULL)
	{
		MessageBox(hwnd, TEXT("Wordone Filed or Q1 field is Empty...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
	}
	else
	{
		E = EfficiencyOfHeatEngine(W, q_1);					//Efficiency
	}
														//UnInitialise();
	return(E);
	
}

extern "C" double RefrigeratorQ1(double q_2, double W)
{
	if (W == NULL || q_2 == NULL)
	{
		MessageBox(hwnd, TEXT("Wordone Filed or Q2 field is Empty...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
		
	}
	else
	{
		q1 = Q_1(q_2, W);
		
	}
	return(q1);
	
}

extern "C" double RefrigeratorCoP(double W, double q_2)
{
	if (W == NULL || q_2 == NULL)
	{
		MessageBox(hwnd, TEXT("Wordone Filed or Q2 field is Empty...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
		
	}
	else
	{
		COPr = Coefficient_Of_PerformanceR(W, q_2);
		
	}
	return(COPr);
}

extern "C" double AirConditionerQ2(double q_1, double W)
{
	if (W == NULL || q_1 == NULL)
	{
		MessageBox(hwnd, TEXT("Wordone Filed or Q1 field is Empty...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
	}
	
	else
	{
		q2 = Q_2(q_1, W);
		
	}
	return(q2);
	
}

extern "C" double AirConditionerCoP(double W, double q_1)
{
	if (W == NULL || q_1 == NULL)
	{
		MessageBox(hwnd, TEXT("Wordone Filed or Q1 field is Empty...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
	}
	else
	{
		COPac = Coefficient_Of_PerformanceAC(q_1, W);
		
	}
	return(COPac);
}
	






