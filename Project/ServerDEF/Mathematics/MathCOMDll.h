#pragma once
#include<Windows.h>
#define EQUILATERAL 1.0
#define ISOSCELES 2.0
#define SCELENE 3.0
#define ACUTE 4.0
#define RIGHT 5.0
#define OBTUSE 6.0
#define ERROR 7.0
#define RIGHTISO 8.0

class ISideOne :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall SideOne(double, double, double, double, double *) = 0;
};

class ISideTwo :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall SideTwo(double, double, double, double, double *) = 0;
};

class ISideThree :public IUnknown
{
	//code
public:
	virtual HRESULT __stdcall SideThree(double, double, double, double, double *) = 0;
};

class IAngleOfTriangle :public IUnknown
{
public:
	virtual HRESULT __stdcall AngleIs(double, double, double, double *) = 0;

};

class ITypeOfTriangle :public IUnknown
{
public:
	virtual HRESULT __stdcall TriangleIs(double, double, double, double *) = 0;
};


// {9FEEA118-1F56-4943-AC8B-EB1CBE1A22F6}
const CLSID CLSID_Triangle = { 0x9feea118, 0x1f56, 0x4943, 0xac, 0x8b, 0xeb, 0x1c, 0xbe, 0x1a, 0x22, 0xf6 };

// {77941505-CF88-4368-A15D-D5527878D9E9}
const IID IID_ISideOne = { 0x77941505, 0xcf88, 0x4368, 0xa1, 0x5d, 0xd5, 0x52, 0x78, 0x78, 0xd9, 0xe9 };

// {1B29A3C6-2F7D-41F0-AF3F-D5AF98B9437D}
const IID IID_ISideTwo = { 0x1b29a3c6, 0x2f7d, 0x41f0, 0xaf, 0x3f, 0xd5, 0xaf, 0x98, 0xb9, 0x43, 0x7d };

// {673B2A6E-D050-467B-875C-029E54087637}
const IID IID_ISideThree = { 0x673b2a6e, 0xd050, 0x467b, 0x87, 0x5c, 0x2, 0x9e, 0x54, 0x8, 0x76, 0x37 };

// {23A663BC-18A5-4B8D-B317-44AD10116F17}
const IID IID_IAngleOfTriangle = { 0x23a663bc, 0x18a5, 0x4b8d, 0xb3, 0x17, 0x44, 0xad, 0x10, 0x11, 0x6f, 0x17 };

// {82FD8BEE-8238-442B-8F9B-5813A7762F58}
const IID IID_ITypeOfTriangle = { 0x82fd8bee, 0x8238, 0x442b, 0x8f, 0x9b, 0x58, 0x13, 0xa7, 0x76, 0x2f, 0x58 };
