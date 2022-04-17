#include<Windows.h>
#include<iostream>
#include"ClassFactoryDllServerWithRegFile.h"

using namespace std;

//Global Variables
ISum *pISum = NULL;
//ISum *pISumForISubtract = NULL;
ISubtract *pISubtract = NULL;

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

	pISum->Release();
	pISum = NULL;

	cout << "ISum Released...!\n";
	
	Sleep(5000);

	hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
	
	cout << "We got the ISum Successfully again...!\n";
		
	CoUninitialize();
	return(0);
}
