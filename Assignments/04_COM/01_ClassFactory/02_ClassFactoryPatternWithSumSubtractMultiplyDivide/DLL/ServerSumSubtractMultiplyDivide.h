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

// {F82D77FE-539D-492E-B40C-64880029AE0C}
const CLSID CLSID_SumSubtract = { 0xf82d77fe, 0x539d, 0x492e, 0xb4, 0xc, 0x64, 0x88, 0x0, 0x29, 0xae, 0xc };

// {80E683AA-40E7-4330-818A-A58BB0D7C83F}
const IID IID_ISum = { 0x80e683aa, 0x40e7, 0x4330, 0x81, 0x8a, 0xa5, 0x8b, 0xb0, 0xd7, 0xc8, 0x3f };

// {F79B240E-DE44-40C5-8E87-6F0EAC038400}
const IID IID_ISubtract = { 0xf79b240e, 0xde44, 0x40c5, 0x8e, 0x87, 0x6f, 0xe, 0xac, 0x3, 0x84, 0x0 };

// {CF1469C4-C659-4256-8583-951933835F63}
const IID IID_IMultiply = { 0xcf1469c4, 0xc659, 0x4256, 0x85, 0x83, 0x95, 0x19, 0x33, 0x83, 0x5f, 0x63 };

// {CA2CF158-02D3-4D58-9F8C-057381A7477B}
const IID IID_IDivide = { 0xca2cf158, 0x2d3, 0x4d58, 0x9f, 0x8c, 0x5, 0x73, 0x81, 0xa7, 0x47, 0x7b };
