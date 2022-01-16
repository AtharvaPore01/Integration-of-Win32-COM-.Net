#include<Windows.h>
#include"MyDll.h"

double mass = 0.0;
double PersonWght = 0.0;

double w = 9.81;

double wght = 0.0;

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

extern "C" double Mass(double n)
{
	//code
	mass = n / w;
	//wght = mass * weight;
	return(mass);
}

extern "C" double Weight(double m, double gravity)
{
	wght = m * gravity;
	return(wght);
}

extern "C" double PersonWeight(double ms)
{
	PersonWght = ms * w;
	return(PersonWght);
}
