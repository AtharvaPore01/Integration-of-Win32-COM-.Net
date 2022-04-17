#include<Windows.h>
#include"ContainmentInnerComponentWithRegFile.h"

class CMultiplyDivide :public IMultiply, IDivide
{

	//code
private:
	long m_cRef;

public:
	//constructor
	CMultiplyDivide(void);

	//destructor
	~CMultiplyDivide(void);

	//Functions of IUnknown

	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//Functions of ISum and ISubtract

	HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*);
	HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*);

};

class CMultiplyDivideClassFactory :public IClassFactory
{
	//code
	//constructor
private:
	long m_cRef;

public:

	CMultiplyDivideClassFactory(void);

	//destructor
	~CMultiplyDivideClassFactory(void);

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

CMultiplyDivide::CMultiplyDivide(void)
{
	m_cRef = 1;
	InterlockedIncrement(&glNumberOfActiveComponent);
}

CMultiplyDivide::~CMultiplyDivide(void)
{
	InterlockedDecrement(&glNumberOfActiveComponent);
}

HRESULT CMultiplyDivide::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast<IMultiply *>(this);
	}
	
	else if (riid == IID_IMultiply)
	{
		*ppv = static_cast<IMultiply *>(this);
	}
	else if (riid == IID_IDivide)
	{
		*ppv = static_cast<IDivide *>(this);
	}

	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return(S_OK);
}

ULONG CMultiplyDivide::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(S_OK);
}

ULONG CMultiplyDivide::Release(void)
{
	InterlockedDecrement(&m_cRef);
	if (m_cRef = 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);

}

HRESULT CMultiplyDivide::MultiplicationOfTwoIntegers(int n1, int n2, int *pMul)
{
	*pMul = n1 * n2;
	return(S_OK);
}

HRESULT CMultiplyDivide::DivisionOfTwoIntegers(int n1, int n2, int *pDiv)
{
	*pDiv = n1 / n2;
	return(S_OK);
}

CMultiplyDivideClassFactory::CMultiplyDivideClassFactory(void)
{
	m_cRef = 1;
}

CMultiplyDivideClassFactory::~CMultiplyDivideClassFactory(void)
{
	//code
}

HRESULT CMultiplyDivideClassFactory::QueryInterface(REFIID riid, void **ppv)
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

ULONG CMultiplyDivideClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}

ULONG CMultiplyDivideClassFactory::Release(void)
{
	InterlockedIncrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);
}

HRESULT CMultiplyDivideClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
	CMultiplyDivide *pCMultiplyDivide = NULL;
	HRESULT hr;

	if (pUnkOuter != NULL)
	{
		return(CLASS_E_NOAGGREGATION);
	}
	pCMultiplyDivide = new CMultiplyDivide;
	if (pCMultiplyDivide == NULL)
	{
		return(E_OUTOFMEMORY);
	}
	hr = pCMultiplyDivide->QueryInterface(riid, ppv);
	pCMultiplyDivide->Release();
	return(hr);
}

HRESULT CMultiplyDivideClassFactory::LockServer(BOOL fLock)
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
	CMultiplyDivideClassFactory *pCMultiplyDivideClassFactory;
	HRESULT hr;

	if (rclsid != CLSID_MultiplyDivide)
	{
		return(CLASS_E_CLASSNOTAVAILABLE);
	}
	pCMultiplyDivideClassFactory = new CMultiplyDivideClassFactory;
	if (pCMultiplyDivideClassFactory == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	hr = pCMultiplyDivideClassFactory->QueryInterface(riid, ppv);
	pCMultiplyDivideClassFactory->Release();
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
