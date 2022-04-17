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
// {F5D1FC87-F69A-47C0-9E74-A16C9302156F}
const CLSID CLSID_MultiplyDivide = { 0xf5d1fc87, 0xf69a, 0x47c0, 0x9e, 0x74, 0xa1, 0x6c, 0x93, 0x2, 0x15, 0x6f };

// {B2C96488-282F-419C-ACD9-515A0973572D}
const IID IID_IMultiply = { 0xb2c96488, 0x282f, 0x419c, 0xac, 0xd9, 0x51, 0x5a, 0x9, 0x73, 0x57, 0x2d };

// {9E36AFF6-89CD-4C99-9580-B880013F98B5}
const IID IID_IDivide = { 0x9e36aff6, 0x89cd, 0x4c99, 0x95, 0x80, 0xb8, 0x80, 0x1, 0x3f, 0x98, 0xb5 };
