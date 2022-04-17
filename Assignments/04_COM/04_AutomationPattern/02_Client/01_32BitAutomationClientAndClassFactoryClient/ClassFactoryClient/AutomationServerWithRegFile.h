#pragma once
#include<Windows.h>
class IMyMath : public IDispatch
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0;
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0;
};

// {F8506914-3E4C-4665-BB4B-689F559E7480}
const CLSID CLSID_MyMath = { 0xf8506914, 0x3e4c, 0x4665, 0xbb, 0x4b, 0x68, 0x9f, 0x55, 0x9e, 0x74, 0x80 };

// {2E0F96FD-E25A-4820-91F1-9D3DF3B639D3}
const IID IID_IMyMath = { 0x2e0f96fd, 0xe25a, 0x4820, 0x91, 0xf1, 0x9d, 0x3d, 0xf3, 0xb6, 0x39, 0xd3 };
