#include<Windows.h>
#include"ClassFactoryDllServerWithRegFile.h"

class CSumSubtract :public ISum, ISubtract
{

	//code
private:
	long m_cRef;

public:
	//constructor
	CSumSubtract(void);

	//destructor
	~CSumSubtract(void);

	//Functions of IUnknown

	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Functions of ISum and ISubtract

	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);

};

class CSumSubtractClassFactory :public IClassFactory
{
	//code
	//constructor
private:
	long m_cRef;

public:

	CSumSubtractClassFactory(void);

	//destructor
	~CSumSubtractClassFactory(void);

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

CSumSubtract::CSumSubtract(void)
{
	m_cRef = 1;
	InterlockedIncrement(&glNumberOfActiveComponent);
}

CSumSubtract::~CSumSubtract(void)
{
	InterlockedDecrement(&glNumberOfActiveComponent);
}

HRESULT CSumSubtract::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast<ISum *>(this);
	}
	else if (riid == IID_ISum)
	{
		*ppv = static_cast<ISum *>(this);
	}
	else if (riid == IID_ISubtract)
	{
		*ppv = static_cast<ISubtract *>(this);
	}

	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CSumSubtract::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(S_OK);
}

ULONG CSumSubtract::Release(void)
{
	InterlockedDecrement(&m_cRef);
	if (m_cRef = 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);

}

HRESULT CSumSubtract::SumOfTwoIntegers(int n1, int n2, int *pSum)
{
	*pSum = n1 + n2;
	return(S_OK);
}

HRESULT CSumSubtract::SubtractionOfTwoIntegers(int n1, int n2, int *pSub)
{
	*pSub = n1 - n2;
	return(S_OK);
}

CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
	m_cRef = 1;
}

CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	//code
}

HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void **ppv)
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

ULONG CSumSubtractClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CSumSubtractClassFactory::Release(void)
{
	InterlockedIncrement(&m_cRef);
		if (m_cRef == 0)
		{
			delete(this);
			return(0);
		}
		return(m_cRef);
}

HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
	CSumSubtract *pCSumSubtract = NULL;
	HRESULT hr;

	if (pUnkOuter != NULL)
	{
		return(CLASS_E_NOAGGREGATION);
	}
	pCSumSubtract = new CSumSubtract;
	if (pCSumSubtract == NULL)
	{
		return(E_OUTOFMEMORY);
	}
	hr = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();
	return(hr);
}

HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
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

HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	CSumSubtractClassFactory *pCSumSubtractClassFactory;
	HRESULT hr;

	if (rclsid != CLSID_SumSubtract)
	{
		return(CLASS_E_CLASSNOTAVAILABLE);
	}
	pCSumSubtractClassFactory = new CSumSubtractClassFactory;
	if (pCSumSubtractClassFactory == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	hr = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
	pCSumSubtractClassFactory->Release();
	return(hr);
}

HRESULT __stdcall DllCanUnloadNow(void)
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