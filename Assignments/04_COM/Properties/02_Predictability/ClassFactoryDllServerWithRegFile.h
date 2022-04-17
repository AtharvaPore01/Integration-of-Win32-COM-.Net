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
// {8EAD62D6-D57A-48AD-BC24-3D4C32E9F615}
const CLSID CLSID_SumSubtract = { 0x8ead62d6, 0xd57a, 0x48ad, 0xbc, 0x24, 0x3d, 0x4c, 0x32, 0xe9, 0xf6, 0x15 };

// {2265BDA7-E99D-42A8-ABE4-82933AD414A1}
const IID IID_ISum = { 0x2265bda7, 0xe99d, 0x42a8, 0xab, 0xe4, 0x82, 0x93, 0x3a, 0xd4, 0x14, 0xa1 };

// {B2FA9442-92E7-4A6C-87DB-EC82BE61D673}
const IID IID_ISubtract = { 0xb2fa9442, 0x92e7, 0x4a6c, 0x87, 0xdb, 0xec, 0x82, 0xbe, 0x61, 0xd6, 0x73 };


	

