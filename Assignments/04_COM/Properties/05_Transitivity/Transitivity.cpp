#include<Windows.h>
#include<iostream>
#include"ServerSumSubtractMultiplyDivide.h"

using namespace std;

//Global Variables
ISum *pISum = NULL;
ISubtract *pISubtract = NULL;
IMultiply *pIMul = NULL;
//code
int main()
{
	HRESULT hr;
	TCHAR str[255];

	hr = CoInitialize(NULL);

	hr = CoCreateInstance(CLSID_SumSubtract, NULL, CLSCTX_INPROC_SERVER, IID_ISum, (void **)&pISum);
	if (FAILED(hr))
	{
		cout << "ISum Interface cannot be obtained\n";
		exit(0);
	}

	cout << "We got the ISum Successfully...!\n";

	hr = pISum->QueryInterface(IID_ISubtract, (void **)&pISubtract);


	if (FAILED(hr))
	{
		cout << "ISubtract Interface cannot be obtained\n";
		exit(0);
	}
	cout << "We got the ISubtract Successfully...!\n";
	pISum->Release();
	pISum = NULL;

	hr = pISubtract->QueryInterface(IID_IMultiply, (void **)&pIMul);

	if (FAILED(hr))
	{
		cout << "IMultiply Interface cannot be obtained\n";
		exit(0);
	}

	hr = pIMul->QueryInterface(IID_ISum, (void **)&pISum);
	if (FAILED(hr))
	{
		cout << "ISum Interface cannot be obtained\n";
		exit(0);
	}

	cout << "We got the ISum From pIMul Successfully...!\n";

	cout << "**********Transitivity is Proved**********\n";

	CoUninitialize();
	return(0);
}
