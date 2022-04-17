#pragma once
#include<Windows.h>

class ISum :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0;
};

class ISubtract :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0;
};
// {B3210F83-2434-4A2D-A0B6-3B87AAD137A5}
const CLSID CLSID_SumSubtract = { 0xb3210f83, 0x2434, 0x4a2d, 0xa0, 0xb6, 0x3b, 0x87, 0xaa, 0xd1, 0x37, 0xa5 };

// {5CC69CD9-8FC3-4B51-835B-BF41AA6C0663}
const IID IID_ISum = { 0x5cc69cd9, 0x8fc3, 0x4b51, 0x83, 0x5b, 0xbf, 0x41, 0xaa, 0x6c, 0x6, 0x63 };

// {471B4C73-8681-4B72-A795-21E974DB2989}
const IID IID_ISubtract = { 0x471b4c73, 0x8681, 0x4b72, 0xa7, 0x95, 0x21, 0xe9, 0x74, 0xdb, 0x29, 0x89 };
