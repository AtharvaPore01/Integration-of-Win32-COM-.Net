#include<Windows.h>
#include<iostream>
#include"ClassFactoryDllServerWithRegFile.h"

using namespace std;

//Global Variables
ISum *pISum = NULL;
ISum *pISumAgain = NULL;

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
	
	cout << "We got the ISum Successfully...!\n";

	hr = pISum->QueryInterface(IID_ISum, (void **)&pISumAgain);
	
	
	if (FAILED(hr))
	{
		cout << "ISum Interface cannot be obtained\n";
		exit(0);
	}
	cout << "We got the ISumAgain Successfully...!\n";
	
	cout << "**********Reflexivity is Proved**********\n";

	CoUninitialize();
	return(0);
}
