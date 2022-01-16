#include<Windows.h>
#include<math.h>
#include"MathCOMDll.h"

float angle;


class CTriangle :public ISideOne, ISideTwo, ISideThree, IAngleOfTriangle, ITypeOfTriangle
{

	//code
private:
	long m_cRef;

public:
	//constructor
	CTriangle(void);

	//destructor
	~CTriangle(void);

	//Functions of IUnknown

	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Function of ISide

	HRESULT __stdcall SideOne(double, double, double, double, double *);
	HRESULT __stdcall SideTwo(double, double, double, double, double *);
	HRESULT __stdcall SideThree(double, double, double, double, double *);
	HRESULT __stdcall AngleIs(double, double, double, double *);
	HRESULT __stdcall TriangleIs(double, double, double, double *);
	
};

class CTriangleClassFactory :public IClassFactory
{
	//code
	//constructor
private:
	long m_cRef;

public:

	CTriangleClassFactory(void);

	//destructor
	~CTriangleClassFactory(void);

	//Functions of IUnknown

	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Functions of IClassFactory

	HRESULT __stdcall CreateInstance(IUnknown *, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

//global declaration

long glNumberOfActiveComponent = 0;
long glNumberOfServerLock = 0;

//DllMain

BOOL WINAPI DllMain(HINSTANCE hLib, DWORD dwReason, LPVOID lpReserved)
{
	//code

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return(TRUE);
}

CTriangle::CTriangle(void)
{
	m_cRef = 1;
	InterlockedIncrement(&glNumberOfActiveComponent);
}

CTriangle::~CTriangle(void)
{
	InterlockedDecrement(&glNumberOfActiveComponent);
}

HRESULT CTriangle::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast<ISideOne *>(this);
	}
	else if (riid == IID_ISideOne)
	{
		*ppv = static_cast<ISideOne *>(this);
	}
	else if (riid == IID_ISideTwo)
	{
		*ppv = static_cast<ISideTwo *>(this);
	}
	else if (riid == IID_ISideThree)
	{
		*ppv = static_cast<ISideThree *>(this);
	}
	else if (riid == IID_IAngleOfTriangle)
	{
		*ppv = static_cast<IAngleOfTriangle *>(this);
	}
	else if (riid == IID_ITypeOfTriangle)
	{
		*ppv = static_cast<ITypeOfTriangle *>(this);
	}
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CTriangle::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(S_OK);
}

ULONG CTriangle::Release(void)
{
	InterlockedDecrement(&m_cRef);
	if (m_cRef = 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);

}

HRESULT CTriangle::SideOne(double x1, double x2, double y1, double y2, double *pS1)
{
	*pS1 = sqrtf((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
	//*pS2 = sqrtf((pow((x2 - x3), 2) + pow((y2 - y3), 2)));
	//*pS3 = sqrtf((pow((x3 - x1), 2) + pow((y3 - y1), 2)));
	
	return(S_OK);
}
HRESULT CTriangle::SideTwo(double x2, double x3, double y2, double y3, double *pS2)
{
	*pS2 = sqrtf((pow((x3 - x2), 2) + pow((y3 - y2), 2)));
	return(S_OK);
}
HRESULT CTriangle::SideThree(double x3, double x1, double y3, double y1, double *pS3)
{
	*pS3 = sqrtf((pow((x1 - x3), 2) + pow((y1 - y3), 2)));
	return(S_OK);
}
HRESULT CTriangle::TriangleIs(double a1, double a2, double a3, double *pAngle)
{
	angle = a1 + a2 + a3;
	if ((angle < 180) || (angle > 180))
	{
		*pAngle = 7.0; //Error
		return(S_OK);
	}
	else if (angle == 180)
	{
		if ((a1 == a2) && (a2 == a3) && (a3 == a1))
		{
			*pAngle = 1.0; //equilateral
			return(S_OK);
		}
		else if ((a1 == a2) || (a2 == a3) || (a3 == a1))
		{
			if (((a1 || a2 || a3) == 90))
			{
				*pAngle = 8.0; //IsoscelesRightAngleTriangle
				return(S_OK);
			}
			*pAngle = 2.0; //Isosceles
			return(S_OK);
		}
		
		else if((a1 != a2) &&(a2!=a3)&&(a3!=a1))
		{
			*pAngle = 3.0; //Scalene
			return(S_OK);
		}
	}
}

HRESULT CTriangle::AngleIs(double a1, double a2, double a3, double *pAngle)
{
	angle = a1 + a2 + a3;
	if ((angle < 180) || (angle > 180))
	{
		*pAngle = 7.0; //Error
		return(S_OK);
	}
	else if ((a1 >= 100 || a2>=100 || a3>=100))
	{
		
			*pAngle = 6.0; //Obtuse
			return(S_OK);	
	}
	else if (((a1 == 90 || a2 == 90 || a3 == 90)))
	{
		*pAngle = 5.0; //RightAngleTriangle
		return(S_OK);
	}
	else if (((a1 && a2 && a3) < 100))
	{
		*pAngle = 4.0; //Acute
		return(S_OK);
	}
}

//HRESULT CSumSubtract::SubtractionOfTwoIntegers(int n1, int n2, int *pSub)
//{
//	*pSub = n1 - n2;
//	return(S_OK);
//}

CTriangleClassFactory::CTriangleClassFactory(void)
{
	m_cRef = 1;
}

CTriangleClassFactory::~CTriangleClassFactory(void)
{
	//code
}

HRESULT CTriangleClassFactory::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast<IClassFactory *>(this);
	}
	else if (riid == IID_IClassFactory)
	{
		*ppv = static_cast<IClassFactory *>(this);
	}
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return(S_OK);

}

ULONG CTriangleClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CTriangleClassFactory::Release(void)
{
	InterlockedIncrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);
}

HRESULT CTriangleClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
	CTriangle *pCTriangle = NULL;
	HRESULT hr;

	if (pUnkOuter != NULL)
	{
		return(CLASS_E_NOAGGREGATION);
	}
	pCTriangle = new CTriangle;
	if (pCTriangle == NULL)
	{
		return(E_OUTOFMEMORY);
	}
	hr = pCTriangle->QueryInterface(riid, ppv);
	pCTriangle->Release();
	return(hr);
}

HRESULT CTriangleClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
	{
		InterlockedIncrement(&glNumberOfServerLock);
	}
	else
	{
		InterlockedDecrement(&glNumberOfServerLock);
	}
	return(S_OK);

}

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	CTriangleClassFactory *pCTriangleClassFactory;
	HRESULT hr;

	if (rclsid != CLSID_Triangle)
	{
		return(CLASS_E_CLASSNOTAVAILABLE);
	}
	pCTriangleClassFactory = new CTriangleClassFactory;
	if (pCTriangleClassFactory == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	hr = pCTriangleClassFactory->QueryInterface(riid, ppv);
	pCTriangleClassFactory->Release();
	return(hr);
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	if ((glNumberOfActiveComponent == 0) && (glNumberOfServerLock == 0))
	{
		return(S_OK);
	}
	else
	{
		return(S_FALSE);
	}
}
