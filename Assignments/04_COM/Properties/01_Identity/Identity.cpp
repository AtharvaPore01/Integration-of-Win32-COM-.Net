#include<Windows.h>
#include<iostream>
#include"ClassFactoryDllServerWithRegFile.h"

using namespace std;

//Global Variables
ISum *pISum = NULL;
ISubtract *pISubtract = NULL;
IUnknown *pIUnknownFromISum = NULL;
IUnknown *pIUnknownFromISubtract = NULL;

//code
int main()
{
	HRESULT hr;
	TCHAR str[255];

	hr = CoInitialize(NULL);
	
	hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
	if(FAILED(hr))
	{
		cout<<"ISum Interface cannot be obtained\n";
		exit(0);
	}
	pISum->QueryInterface(IID_ISubtract, (void **)&pISubtract);
	
	pISum->QueryInterface(IID_IUnknown, (void **)&pIUnknownFromISum);
	pISubtract->QueryInterface(IID_IUnknown, (void **)&pIUnknownFromISubtract);
	
	

	if(pIUnknownFromISum == pIUnknownFromISubtract)
	{
		cout<<"Identity is proved\n";
	}
	
	CoUninitialize();
	return(0);
}
