#include<Windows.h>
#include"AggregationInnerComponentWithRegFile.h"
#include"AggregationOuterComponentWithRegFile.h"

//Class Declaration

class CSumSubtract :public ISum, ISubtract
{
private:
	long m_cRef;
	IUnknown *m_pIUnknownInner; //IUnknown of inner will be stored here

	IMultiply *m_pIMul;
	IDivide *m_pIDiv;

public:
	
	//constructor
	CSumSubtract(void);
	
	//destructor
	~CSumSubtract(void);
	
	//Methods of IUnknown
	HRESULT __stdcall QueryInterface(REFIID, void **);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);
	
	//Methods of ISum and ISubtract(Inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int *);
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *);

	//Method For Inner Component Creation
	HRESULT __stdcall InitializeInnerComponent(void);
};
class CSumSubtractClassFactory :public IClassFactory
{
private:
	long m_cRef;
public:
	
	//contructor
	CSumSubtractClassFactory(void);
	
	//destructor
	~CSumSubtractClassFactory(void);
	
	//Methods of IUnknown
	HRESULT __stdcall QueryInterface(REFIID, void **);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);
	
	//Methods of ClassFactory
	HRESULT __stdcall CreateInstance(IUnknown *, REFIID, void **);
	HRESULT __stdcall LockServer(BOOL);
};

//global variables
long glNumberOfActiveComponents = 0;
long glNumberOfServerLocks = 0;

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
	m_pIUnknownInner = NULL;
	m_cRef = 1;

	m_pIMul = NULL;
	m_pIDiv = NULL;


	InterlockedIncrement(&glNumberOfActiveComponents); //increment global counter
}

CSumSubtract::~CSumSubtract(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);

	if (m_pIMul)
	{
		m_pIMul->Release();
		m_pIMul = NULL;
	}
	if (m_pIDiv)
	{
		m_pIDiv->Release();
		m_pIDiv = NULL;
	}

}
//Implementation of IUnknown's Method
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
	else if (riid == IID_IMultiply)
	{
		return(m_pIUnknownInner->QueryInterface(riid, ppv));
	}
	else if (riid == IID_IDivide)
	{
		return(m_pIUnknownInner->QueryInterface(riid, ppv));
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
	return(m_cRef);
}

ULONG CSumSubtract::Release(void)
{
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);
}

//Implementation of ISum's Method
HRESULT CSumSubtract::SumOfTwoIntegers(int n1, int n2, int *pSum)
{
	*pSum = n1 + n2;
	return(S_OK);
}
//Implementation of ISubtract's Method
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int n1, int n2, int *pSub)
{
	*pSub = n1 - n2;
	return(S_OK);
}

HRESULT CSumSubtract::InitializeInnerComponent(void)
{
	//variable declaration
	HRESULT hr;
	//code
	hr = CoCreateInstance(CLSID_MultiplyDivide,
		reinterpret_cast<IUnknown *>(this),
		CLSCTX_INPROC_SERVER,
		IID_IUnknown,
		(void **)&m_pIUnknownInner);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IUnknown Interface cannot be obtain from Inner Component"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return(E_FAIL);
	}

	hr = m_pIUnknownInner->QueryInterface(IID_IMultiply, (void **)&m_pIMul);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IMultiply Interface cannot be obtain from Inner Component"), TEXT("Error"), MB_OK | MB_ICONERROR);
		
		m_pIUnknownInner->Release();
		m_pIUnknownInner = NULL;
		
		return(E_FAIL);
	}
	hr = m_pIUnknownInner->QueryInterface(IID_IDivide, (void **)&m_pIDiv);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("IDivide Interface cannot be obtain from Inner Component"), TEXT("Error"), MB_OK | MB_ICONERROR);

		m_pIUnknownInner->Release();
		m_pIUnknownInner = NULL;

		return(E_FAIL);
	}
}

//Class Factory Implementation
CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
	m_cRef = 1;
}

CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	//code
}
//Implementation of CSumSubtractClassFactory IUnknown's Methods
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

	hr = pCSumSubtract->InitializeInnerComponent();
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("Failed To Initialise Inner Component"), TEXT("Error"), MB_OK | MB_ICONERROR);
		pCSumSubtract->Release();
		return(hr);
	}

	hr = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();
	return(hr);
}
HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
	{
		InterlockedIncrement(&glNumberOfServerLocks);
	}
	else
	{
		InterlockedDecrement(&glNumberOfServerLocks);
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
	if ((glNumberOfActiveComponents == 0) && (glNumberOfServerLocks == 0))
	{
		return(S_OK);
	}
	else
	{
		return(S_FALSE);
	}
}
