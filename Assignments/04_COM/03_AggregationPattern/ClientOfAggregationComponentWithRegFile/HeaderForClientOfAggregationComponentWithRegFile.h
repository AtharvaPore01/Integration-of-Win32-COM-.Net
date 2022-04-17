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
// {1FC63CDA-8321-4E2E-A546-608FD219F232}
const CLSID CLSID_SumSubtract = { 0x1fc63cda, 0x8321, 0x4e2e, 0xa5, 0x46, 0x60, 0x8f, 0xd2, 0x19, 0xf2, 0x32 };

// {7DA3D7DE-34A8-409F-97C4-881AA7741AF2}
const IID IID_ISum = { 0x7da3d7de, 0x34a8, 0x409f, 0x97, 0xc4, 0x88, 0x1a, 0xa7, 0x74, 0x1a, 0xf2 };

// {EAB31F12-9C91-40F3-B7D0-32FE0E5BE582}
const IID IID_ISubtract = { 0xeab31f12, 0x9c91, 0x40f3, 0xb7, 0xd0, 0x32, 0xfe, 0xe, 0x5b, 0xe5, 0x82 };

// {2425B021-2990-451A-BB35-107CF53AF897}
const IID IID_IMultiply = { 0x2425b021, 0x2990, 0x451a, 0xbb, 0x35, 0x10, 0x7c, 0xf5, 0x3a, 0xf8, 0x97 };

// {EFF29AB8-CF4C-4E63-847F-D85ACD0CA98B}
const IID IID_IDivide = { 0xeff29ab8, 0xcf4c, 0x4e63, 0x84, 0x7f, 0xd8, 0x5a, 0xcd, 0xc, 0xa9, 0x8b };
