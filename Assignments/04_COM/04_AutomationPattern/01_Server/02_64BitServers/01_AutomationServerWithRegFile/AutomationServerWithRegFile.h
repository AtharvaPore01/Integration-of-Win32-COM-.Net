#pragma once
#include<Windows.h>
class IMyMath : public IDispatch
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0;
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0;
};

// {9F01B006-83A8-4BC5-A2FD-044C56B23725}
const CLSID CLSID_MyMath = { 0x9f01b006, 0x83a8, 0x4bc5, 0xa2, 0xfd, 0x4, 0x4c, 0x56, 0xb2, 0x37, 0x25 };

//{D4C18907-3BD9-40D6-A25F-6FDA752A6EDC}
const IID IID_IMyMath = { 0xd4c18907, 0x3bd9, 0x40d6, 0xa2, 0x5f, 0x6f, 0xda, 0x75, 0x2a, 0x6e, 0xdc };
