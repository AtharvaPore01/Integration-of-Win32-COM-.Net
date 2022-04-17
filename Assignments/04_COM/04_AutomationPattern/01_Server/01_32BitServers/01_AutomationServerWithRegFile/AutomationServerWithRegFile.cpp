//Header File
#include<Windows.h>
#include<stdio.h>
#include"AutomationServerWithRegFile.h"

//CoClass Declaration
class CMyMath :public IMyMath
{
private:
	long m_cRef;
	ITypeInfo *m_pITypeInfo;

public:
	//Constructor
	CMyMath(void);

	//Destructor
	~CMyMath(void);

	//IUnknown Specific Method Declaration
	HRESULT __stdcall QueryInterface(REFIID, void **);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IDispatch Specific Method Declaration
	HRESULT __stdcall GetTypeInfoCount(UINT *);
	HRESULT __stdcall GetTypeInfo(UINT, LCID, ITypeInfo **);
	HRESULT __stdcall GetIDsOfNames(REFIID, LPOLESTR *, UINT, LCID, DISPID *);
	HRESULT __stdcall Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);

	//Sum Specific Method
	HRESULT __stdcall SumOfTwoIntegers(int, int, int *);

	//Subtraction Specific Method
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *);

	//Custom Method
	HRESULT InitInstance(void);
};

//Class Factory Declaration
class CMyMathClassFactory :public IClassFactory
{
private:
	long m_cRef;

public:
	//Constructor
	CMyMathClassFactory(void);

	//Destructor
	~CMyMathClassFactory(void);

	//IUnknown Specific Method Declaration
	HRESULT __stdcall QueryInterface(REFIID, void **);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory Specific Method Declaration
	HRESULT __stdcall CreateInstance(IUnknown *, REFIID, void **);
	HRESULT __stdcall LockServer(BOOL);
};
//global dll module
HMODULE ghModule = NULL;

//global variable declaration
long glNumberOfActiveComponents = 0;
long glNumberOfServerLocks = 0;

// {1523BC6C-CE5F-4183-8260-CCC59234D79E}
const GUID LIBID_AutomationServer = { 0x1523bc6c, 0xce5f, 0x4183, 0x82, 0x60, 0xcc, 0xc5, 0x92, 0x34, 0xd7, 0x9e };

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

//Implementation of constructor
CMyMath::CMyMath(void)
{
	m_cRef = 1;

	InterlockedIncrement(&glNumberOfActiveComponents);
}

//Implementation of Destructor
CMyMath::~CMyMath(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);
}

//Implementation of IUnknown's Methods
HRESULT CMyMath::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown)
	{
		*ppv = static_cast<IMyMath *>(this);
	}
	else if (riid == IID_IDispatch)
	{
		*ppv = static_cast<IMyMath *>(this);
	}
	else if (riid == IID_IMyMath)
	{
		*ppv = static_cast<IMyMath *>(this);
	}
	else
	{
		*ppv = NULL;
		return(E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown *>(*ppv)->AddRef();
	return(S_OK);
}
ULONG CMyMath::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(S_OK);
}
ULONG CMyMath::Release(void)
{
	InterlockedDecrement(&m_cRef);

	if (m_cRef == 0)
	{
		m_pITypeInfo->Release();
		m_pITypeInfo = NULL;		
		delete(this);
		return(0);
	}
	return(m_cRef);
}

//Implementation of IMyMath's Methods
HRESULT CMyMath::SumOfTwoIntegers(int n1, int n2, int *pSum)
{
	*pSum = n1 + n2;
	return(S_OK);
}
HRESULT CMyMath::SubtractionOfTwoIntegers(int n1, int n2, int *pSubtraction)
{
	*pSubtraction = n1 - n2;
	return(S_OK);
}

HRESULT CMyMath::InitInstance(void)
{
	//function Declaration
	void ComErrorDescriptionString(HWND, HRESULT);

	//variable Declaration
	HRESULT hr;
	ITypeLib *pITypeLib = NULL;

	//code
	if (m_pITypeInfo == NULL)
	{
		hr = LoadRegTypeLib(LIBID_AutomationServer,
			1, 0,
			0x00,
			&pITypeLib);

		if (FAILED(hr))
		{
			ComErrorDescriptionString(NULL, hr);
			return(hr);
		}

		hr = pITypeLib->GetTypeInfoOfGuid(IID_IMyMath, &m_pITypeInfo);
		if (FAILED(hr))
		{
			ComErrorDescriptionString(NULL, hr);
			pITypeLib->Release();
			return(hr);
		}
		pITypeLib->Release();
	}
	return(S_OK);
}

//Implementation Of IDispatch Methods
HRESULT CMyMath::GetTypeInfoCount(UINT *pCountTypeInfo)
{
	*pCountTypeInfo = 1;
	return(S_OK);
}
HRESULT CMyMath::GetTypeInfo(UINT iTypeInfo, LCID lcid, ITypeInfo **ppITypeInfo)
{
	*ppITypeInfo = NULL;
	if (iTypeInfo != 0)
	{
		return(DISP_E_BADINDEX);
	}
	m_pITypeInfo->AddRef();
	*ppITypeInfo = m_pITypeInfo;
	return(S_OK);
}

HRESULT CMyMath::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
	return(DispGetIDsOfNames(m_pITypeInfo, rgszNames, cNames, rgDispId));
}

HRESULT CMyMath::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
	HRESULT hr;
	
	hr = DispInvoke(this,
		m_pITypeInfo,
		dispIdMember,
		wFlags,
		pDispParams,
		pVarResult,
		pExcepInfo,
		puArgErr);

	return(hr);
}

//Implematation of CMyMathClassFactory's Methods
CMyMathClassFactory::CMyMathClassFactory(void)
{
	m_cRef = 1;
}
CMyMathClassFactory::~CMyMathClassFactory(void)
{
	//code
}
HRESULT CMyMathClassFactory::QueryInterface(REFIID riid, void **ppv)
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
ULONG CMyMathClassFactory::AddRef(void)
{
	InterlockedIncrement(&m_cRef);
	return(m_cRef);
}
ULONG CMyMathClassFactory::Release(void)
{
	InterlockedIncrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return(0);
	}
	return(m_cRef);
}

//Implementation of IClassFactory's Method
HRESULT CMyMathClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
	CMyMath *pCMyMath = NULL;
	HRESULT hr;

	if (pUnkOuter != NULL)
	{
		return(CLASS_E_NOAGGREGATION);
	}
	pCMyMath = new CMyMath;
	if (pCMyMath == NULL)
	{
		return(E_OUTOFMEMORY);
	}
	pCMyMath->InitInstance();
	hr = pCMyMath->QueryInterface(riid, ppv);
	pCMyMath->Release();
	return(hr);
}
HRESULT CMyMathClassFactory::LockServer(BOOL fLock)
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

//Implementation of the functions which are to be exported
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	MessageBox(NULL,TEXT("InDllGetClassObject "),TEXT("INFO"),MB_OK);
	CMyMathClassFactory *pCMyMathClassFactory = NULL;
	HRESULT hr;

	if (rclsid != CLSID_MyMath)
	{
		return(CLASS_E_CLASSNOTAVAILABLE);
	}

	pCMyMathClassFactory = new CMyMathClassFactory;

	if (pCMyMathClassFactory == NULL)
	{
		return(E_OUTOFMEMORY);
	}

	hr = pCMyMathClassFactory->QueryInterface(riid, ppv);
	pCMyMathClassFactory->Release();

	MessageBox(NULL, TEXT("InDllGetClassObject2 "), TEXT("INFO"), MB_OK);
	return(hr);
}

extern "C" HRESULT __stdcall DllCanUnloadNow(void)
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

void ComErrorDescriptionString(HWND hwnd, HRESULT hr)
{
	TCHAR *szErrorMessage = NULL;
	TCHAR str[255];

	if (FACILITY_WINDOWS == HRESULT_FACILITY(hr))
	{
		hr = HRESULT_CODE(hr);
		if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			hr,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&szErrorMessage,
			0,
			NULL) != 0)
		{
			sprintf_s(str, TEXT("%#x : %s"), hr, szErrorMessage);
			LocalFree(szErrorMessage);
		}
		else
		{
			sprintf_s(str, TEXT("Could not found description for error - %#x."), hr);
		}

	}
	MessageBox(hwnd, str, TEXT("COM ERROR"), MB_OK | MB_ICONERROR);
}

