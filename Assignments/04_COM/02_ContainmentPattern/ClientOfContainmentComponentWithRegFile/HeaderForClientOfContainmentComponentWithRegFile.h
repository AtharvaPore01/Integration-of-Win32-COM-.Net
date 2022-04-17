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
class IMultiply :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int *) = 0;
};

class IDivide :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int *) = 0;
};
// {B3210F83-2434-4A2D-A0B6-3B87AAD137A5}
const CLSID CLSID_SumSubtract = { 0xb3210f83, 0x2434, 0x4a2d, 0xa0, 0xb6, 0x3b, 0x87, 0xaa, 0xd1, 0x37, 0xa5 };

// {5CC69CD9-8FC3-4B51-835B-BF41AA6C0663}
const IID IID_ISum = { 0x5cc69cd9, 0x8fc3, 0x4b51, 0x83, 0x5b, 0xbf, 0x41, 0xaa, 0x6c, 0x6, 0x63 };

// {471B4C73-8681-4B72-A795-21E974DB2989}
const IID IID_ISubtract = { 0x471b4c73, 0x8681, 0x4b72, 0xa7, 0x95, 0x21, 0xe9, 0x74, 0xdb, 0x29, 0x89 };
// {B2C96488-282F-419C-ACD9-515A0973572D}
const IID IID_IMultiply = { 0xb2c96488, 0x282f, 0x419c, 0xac, 0xd9, 0x51, 0x5a, 0x9, 0x73, 0x57, 0x2d };

// {9E36AFF6-89CD-4C99-9580-B880013F98B5}
const IID IID_IDivide = { 0x9e36aff6, 0x89cd, 0x4c99, 0x95, 0x80, 0xb8, 0x80, 0x1, 0x3f, 0x98, 0xb5 };
