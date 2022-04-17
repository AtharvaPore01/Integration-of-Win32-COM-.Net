#pragma once
#include<Windows.h>

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
// {3E178AF8-8EF7-431D-8812-6CDCE66DA684}
const CLSID CLSID_MultiplyDivide = { 0x3e178af8, 0x8ef7, 0x431d, 0x88, 0x12, 0x6c, 0xdc, 0xe6, 0x6d, 0xa6, 0x84 };

// {2425B021-2990-451A-BB35-107CF53AF897}
const IID IID_IMultiply = { 0x2425b021, 0x2990, 0x451a, 0xbb, 0x35, 0x10, 0x7c, 0xf5, 0x3a, 0xf8, 0x97 };

// {EFF29AB8-CF4C-4E63-847F-D85ACD0CA98B}
const IID IID_IDivide = { 0xeff29ab8, 0xcf4c, 0x4e63, 0x84, 0x7f, 0xd8, 0x5a, 0xcd, 0xc, 0xa9, 0x8b };
