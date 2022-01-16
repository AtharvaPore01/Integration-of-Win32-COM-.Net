//Libraries
#pragma comment(lib, "PhyDll.lib")
#pragma comment(lib, "MathDEFDll.lib")
#pragma comment(lib, "ChemDEFDll.lib")
#pragma comment(lib, "ChemComDll.lib")

//Headers
#include<Windows.h>
#include<stdio.h>
//Headers Created by Developer
#include"ChemComDll.h"
#include"ChemDEFDll.h"
#include"MathDEFDll.h"
#include"MyResource.h"
#include"MyDll.h"




LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

//Functions of clear
void ClearPhysics(HWND hDlg)
{
	SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETEARTHWGHT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETEARTHWGHT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETMASS), TEXT(""));
	CheckRadioButton(hDlg, ID_RBMARS, ID_RBNEPTUNE, BST_UNCHECKED);
	CheckRadioButton(hDlg, ID_RBPHYSICS, ID_RBPHYSICS, BST_UNCHECKED);

}
void ClearMaths(HWND hDlg)
{
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDEONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDETWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDETHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETYONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETYTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETYTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDERESULT), TEXT(""));

	CheckRadioButton(hDlg, ID_RBSIDE, ID_RBANGLE, BST_UNCHECKED);
	CheckRadioButton(hDlg, ID_RBMATHS, ID_RBMATHS, BST_UNCHECKED);

	SetWindowText(GetDlgItem(hDlg, ID_ETAGLONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLRESULT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), TEXT(""));
}
void ClearSide(HWND hDlg)
{
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDEONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDETWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDETHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETYONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETYTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETYTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETSIDERESULT), TEXT(""));
}
void ClearAngle(HWND hDlg)
{
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETAGLRESULT), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), TEXT(""));
}
void ClearRefrigeratorAndAC(HWND hDlg)
{
	
	//Refrigerator
	SetWindowText(GetDlgItem(hDlg, ID_ETQTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQFOUR), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETCOPONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWD), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBREF), TEXT(""));

	//AC
	SetWindowText(GetDlgItem(hDlg, ID_ETQFIVE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQSIX), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETCOPTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWORK), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBAC), TEXT(""));
}
void ClearACAndHeatEngine(HWND hDlg)
{
	
	//HeatEngine
	SetWindowText(GetDlgItem(hDlg, ID_ETQONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETEFFICIENCY), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWORKDONE), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBHEATENGINE), TEXT(""));
	//AC
	SetWindowText(GetDlgItem(hDlg, ID_ETQFIVE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQSIX), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETCOPTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWORK), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBAC), TEXT(""));
}
void ClearHeatEngineAndReferigerator(HWND hDlg)
{
	
	//HeatEngine
	SetWindowText(GetDlgItem(hDlg, ID_ETQONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETEFFICIENCY), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWORKDONE), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBHEATENGINE), TEXT(""));
	//Refrigerator
	SetWindowText(GetDlgItem(hDlg, ID_ETQTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQFOUR), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETCOPONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWD), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBREF), TEXT(""));
}
void ClearChemistry(HWND hDlg)
{
	//HeatEngine
	SetWindowText(GetDlgItem(hDlg, ID_ETQONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETEFFICIENCY), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWORKDONE), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBHEATENGINE), TEXT(""));
	//AC
	SetWindowText(GetDlgItem(hDlg, ID_ETQFIVE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQSIX), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETCOPTWO), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWORK), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBAC), TEXT(""));
	//Refrigerator
	SetWindowText(GetDlgItem(hDlg, ID_ETQTHREE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETQFOUR), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETCOPONE), TEXT(""));
	SetWindowText(GetDlgItem(hDlg, ID_ETWD), TEXT(""));
	//SetWindowText(GetDlgItem(hDlg, ID_PBREF), TEXT(""));
	CheckRadioButton(hDlg, ID_RBHEATENGINE, ID_RBAC, BST_UNCHECKED);
	CheckRadioButton(hDlg, ID_RBCHEMISTRY, ID_RBCHEMISTRY, BST_UNCHECKED);
}

//Functions to Enable & disable
void EnableAngle(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLONE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTWO), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTHREE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), TRUE);

	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLEA), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_PBANGLEA), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLRESULT), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), TRUE);
}
void DisableAngle(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLEA), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBANGLEA), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLRESULT), FALSE);
	//EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), FALSE);
}
void EnableSide(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDEONE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETWO), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETHREE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYONE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTWO), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTHREE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDERESULT), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLES), TRUE);
}
void DisableSide(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDEONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTHREE), FALSE);
	
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDERESULT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLES), FALSE);

}
void EnablePhysics(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_ETEARTHWGHT), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETGRAVITY), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETMWGHT), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETMASS), TRUE);
	//planets
	EnableWindow(GetDlgItem(hDlg, ID_RBMARS), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMOON), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBVENUS), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEARTH), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBJUPITER), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMERCURY), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSATURN), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBNEPTUNE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBURANUS), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBPLUTO), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBTITAN), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEUROPA), TRUE);

	//maths
	EnableWindow(GetDlgItem(hDlg, ID_RBANGLE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSIDE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDEONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDERESULT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLES), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), FALSE);


	//Chemistry
	//Heat Engine
	EnableWindow(GetDlgItem(hDlg, ID_ETQONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEFFICIENCY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORKDONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBHEATENGINE), FALSE);
	//Refrigerator
	EnableWindow(GetDlgItem(hDlg, ID_ETQTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQFOUR), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWD), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBREF), FALSE);
	//AC
	EnableWindow(GetDlgItem(hDlg, ID_ETQFIVE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQSIX), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORK), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBAC), FALSE);
}
void EnableMaths(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_RBANGLE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSIDE), TRUE);

	//phy
	EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEARTHWGHT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETGRAVITY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETMWGHT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMARS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMOON), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBVENUS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEARTH), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBJUPITER), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMERCURY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSATURN), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBNEPTUNE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBURANUS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBPLUTO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBTITAN), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEUROPA), FALSE);

	//Chemistry
	//Heat Engine
	EnableWindow(GetDlgItem(hDlg, ID_ETQONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEFFICIENCY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORKDONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBHEATENGINE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBHEATENGINE), FALSE);
	//Refrigerator
	EnableWindow(GetDlgItem(hDlg, ID_ETQTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQFOUR), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWD), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBREF), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBREF), FALSE);
	//AC
	EnableWindow(GetDlgItem(hDlg, ID_ETQFIVE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQSIX), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORK), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBAC), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBAC), FALSE);
}
void EnableChemistry(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_RBHEATENGINE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBREF), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_RBAC), TRUE);

	//phy
	EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEARTHWGHT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETGRAVITY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETMWGHT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMARS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMOON), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBVENUS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEARTH), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBJUPITER), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMERCURY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSATURN), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBNEPTUNE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBURANUS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBPLUTO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBTITAN), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEUROPA), FALSE);

	//Maths
	EnableWindow(GetDlgItem(hDlg, ID_RBANGLE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSIDE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDEONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDERESULT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLES), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), FALSE);
}

void EnableHeatEngine(HWND hDlg)
{
	EnableWindow(GetDlgItem(hDlg, ID_ETQONE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQTWO), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEFFICIENCY), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORKDONE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_PBHEATENGINE), TRUE);

	//Refrigerator
	EnableWindow(GetDlgItem(hDlg, ID_ETQTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQFOUR), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWD), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBREF), FALSE);

	//AC
	EnableWindow(GetDlgItem(hDlg, ID_ETQFIVE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQSIX), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORK), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBAC), FALSE);
}
void EnableRefrigerator(HWND hDlg)
{
	//Heat Engine
	EnableWindow(GetDlgItem(hDlg, ID_ETQONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEFFICIENCY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORKDONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBHEATENGINE), FALSE);

	//Refrigerator
	EnableWindow(GetDlgItem(hDlg, ID_ETQTHREE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQFOUR), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPONE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWD), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_PBREF), TRUE);

	//AC
	EnableWindow(GetDlgItem(hDlg, ID_ETQFIVE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQSIX), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORK), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBAC), FALSE);
}
void EnableAC(HWND hDlg)
{
	//Heat Engine
	EnableWindow(GetDlgItem(hDlg, ID_ETQONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEFFICIENCY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORKDONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBHEATENGINE), FALSE);

	//Refrigerator
	EnableWindow(GetDlgItem(hDlg, ID_ETQTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQFOUR), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWD), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBREF), FALSE);

	//AC
	EnableWindow(GetDlgItem(hDlg, ID_ETQFIVE), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQSIX), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPTWO), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORK), TRUE);
	EnableWindow(GetDlgItem(hDlg, ID_PBAC), TRUE);
}
void DisableAll(HWND hDlg)
{
	//phy
	EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEARTHWGHT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETGRAVITY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETMWGHT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMARS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMOON), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBVENUS), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBEARTH), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBJUPITER), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBMERCURY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSATURN), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBNEPTUNE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBURANUS), FALSE);

	//Maths
	EnableWindow(GetDlgItem(hDlg, ID_RBANGLE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_RBSIDE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDEONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDETHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETYTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETSIDERESULT), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBTRIANGLES), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETAGLTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETANGLERESULT), FALSE);
	//Chemistry
	//Heat Engine
	EnableWindow(GetDlgItem(hDlg, ID_ETQONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETEFFICIENCY), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORKDONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBHEATENGINE), FALSE);
	//Refrigerator
	EnableWindow(GetDlgItem(hDlg, ID_ETQTHREE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQFOUR), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPONE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWD), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBREF), FALSE);
	//AC
	EnableWindow(GetDlgItem(hDlg, ID_ETQFIVE), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETQSIX), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETCOPTWO), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_ETWORK), FALSE);
	EnableWindow(GetDlgItem(hDlg, ID_PBAC), FALSE);
}
//Global Declarations for bimap
/*
HDC hdc, hdcMem;
PAINTSTRUCT ps;
RECT rc;
BITMAP bm;
HBITMAP hbmOld;
HFONT hFont;
static HINSTANCE hInstance;
static char bitmap;
static HBITMAP hMyBitmap;
HWND hDlg;
*/
//Structures
struct Physics
{
	float weight;
	float gravity;
	float result;
	float ms;
	int pstatus;
}ph;

struct Math
{
	double sx1, sx2, sx3, sy1, sy2, sy3, angle1, angle2, angle3;
	double s1, s2, s3;
	
}mm;

struct Chemistry
{
	float q1, q2, efficiency, workdone, CoPr, CoPac;
}ch;

//function for bitmap loading
/*
void bitmapload(void)
{
	hdc = GetDC(hDlg);
	GetClientRect(hDlg, &rc);

	hdcMem = CreateCompatibleDC(hdc);
	hbmOld = (HBITMAP)SelectObject(hdcMem, hMyBitmap);

	GetObject(hMyBitmap, sizeof(bm), &bm);
	BitBlt(hdc, 325, 180, 100, 100, hdcMem, 0, 0, SRCCOPY); //performs a bit-block transfer
	SelectObject(hdcMem, hbmOld);
	ReleaseDC(hDlg, hdc);
}
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("Window Colouring"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);


	ShowWindow(hwnd, SW_MAXIMIZE);
	
	UpdateWindow(hwnd);

	

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HDC hdc;
//	PAINTSTRUCT ps;
	RECT rc;
	static HBRUSH hMyBrush;
	GetClientRect(hwnd, &rc);
	static char key;



	switch (iMsg)
	{
		HDC hdc, hdcMem;
		PAINTSTRUCT ps;
		RECT rc;
		BITMAP bm;
		HBITMAP hbmOld;
		//HFONT hFont;
		static HINSTANCE hInstance;
		static char bitmap;
		static HBITMAP hMyBitmap;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_SPACE:
			//hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
 			DialogBox(hInstance, "DATAENTRY", hwnd, DlgProc);
			//InvalidateRect(hwnd, &rc, 0);
			break;
		}

		break;

	case WM_CREATE:
		hMyBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MYBITMAP));
		break;


	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rc);

		hdcMem = CreateCompatibleDC(hdc);
		hbmOld = (HBITMAP)SelectObject(hdcMem, hMyBitmap);

		GetObject(hMyBitmap, sizeof(bm), &bm);	
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY); //performs a bit-block transfer
		SelectObject(hdcMem, hbmOld);


		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(0, 0, 0));
		DrawText(hdc, "Press SpaceBar to Continue...!!", -1, &rc, DT_CENTER | DT_SINGLELINE | DT_RIGHT);

		//He Went to Editor On Wednesday, In Unique Situation Cause Our Clip Quality Pitch Family have some FaceName.
		
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		DeleteObject(hMyBitmap);
		PostQuitMessage(0);
		break;

	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Dll related initialisation
	//float n = 0.0;

	
	TCHAR str[255];
	HMODULE hLib = NULL;
	typedef float(*pfnMass) (float);
	pfnMass pfn = NULL;
	char PhysicsFileName[20] = "PhysicsFile";
	char ChemistryFileName[20] = "ChemistryFile";
	char MathematicsFileName[20] = "MathematicsFile";
	
	//DialogBox Related Initialisation
	FILE *file = NULL;
	static HWND hwnd, HandleIs;
	static HINSTANCE hInstance;
	
	//variables for physics
	char wght[7], gravity[7], mas[7];
	static float mass, weight;

	//variables for mathematics
	char x1[7], x2[7], x3[7], y1[7], y2[7], y3[7], a1[7], a2[7], a3[7],Triangle_Side_Result[20], Triangle_Angle_Result[20], Angle_Result[20];
	double side1, side2, side3, angle, triangle;

	//variables for chemistry
	char q1[7], q2[7], work[7];
	static float q_1, q_2, E, WD, COPr, COPac;

	static HDC hdc;
	//HMENU hMenu;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		
		SetFocus(GetDlgItem(hDlg, ID_ETEARTHWGHT));
		SendDlgItemMessage(hDlg, ID_RBPHYSICS, BM_SETCHECK, 0, 0);
		SendDlgItemMessage(hDlg, ID_RBCHEMISTRY, BM_SETCHECK, 0, 0);
		SendDlgItemMessage(hDlg, ID_RBMATHS, BM_SETCHECK, 0, 0);
	//	SendDlgItemMessage(hDlg, ID_RBBIOLOGY, BM_SETCHECK, 0, 0);
	
		return(TRUE);
		break;

	case WM_COMMAND:

		switch (HIWORD(wParam))
		{
		case EN_SETFOCUS:

			HandleIs = GetFocus();

			if (HandleIs == GetDlgItem(hDlg, ID_ETMASS))
			{
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
					//	SendDlgItemMessage(hDlg, ID_RBMARS, BST_UNCHECKED, 0, 0);
				}
				if (ph.weight != NULL)
				{

					//1
					//SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("3.71"));
					
					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					//AppendMenu((HMENU)hDlg, MF_STRING, ID_ETMASS, str);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);
				}
			}
			if (HandleIs == GetDlgItem(hDlg, ID_ETMWGHT))
			{
				GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
				ph.gravity = atof(gravity);
				GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
				ph.ms = atof(mas);

				weight = Weight(ph.gravity, ph.ms);
				sprintf_s(str, "%f", weight);
				SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
			}

			break;
		}

		switch (wParam)
		{

		case ID_RBPHYSICS:
			//Enable Physics and Disable Other Subjects
			EnablePhysics(hDlg);
			//MessageBox(hDlg, TEXT("Please Save Your Data Before Switching the RadioiButton...!!"), TEXT("Information"), MB_OK | MB_ICONINFORMATION);
			//Clear Other Subject's Data
			ClearMaths(hDlg);
			ClearChemistry(hDlg);
			//
			

			break;
		case ID_RBMATHS:
			//Enable Mathematics and Disable Other Subjects
			EnableMaths(hDlg);
			//MessageBox(hDlg, TEXT("Please Save Your Data Before Switching the RadioiButton...!!"), TEXT("Information"), MB_OK | MB_ICONINFORMATION);
			//Clear Other Subject's Data
			ClearPhysics(hDlg);
			ClearChemistry(hDlg);
			break;
		case ID_RBCHEMISTRY:
			//Enable Chemistry
			Initialise();
			EnableChemistry(hDlg);
			//MessageBox(hDlg, TEXT("Please Save Your Data Before Switching the RadioiButton...!!"), TEXT("Information"), MB_OK | MB_ICONINFORMATION);
			//Clear Other Subject's Data
			ClearPhysics(hDlg);
			ClearMaths(hDlg);
			break;
		
//--------------------------------------------Physics Implementation--------------------------------------------

		case ID_RBMARS:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				//	SendDlgItemMessage(hDlg, ID_RBMARS, BST_UNCHECKED, 0, 0);
				}
				if (ph.weight != NULL)
				{
					
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("3.71"));
					
					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					//AppendMenu((HMENU)hDlg, MF_STRING, ID_ETMASS, str);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);
					

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				break;

			case ID_RBMOON:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				//	SendDlgItemMessage(hDlg, ID_RBMOON, BST_UNCHECKED, 0, 0);
				}

				else if (ph.weight != NULL)
				{
						//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("1.62"));
					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
						EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}
				break;
				
			case ID_RBVENUS:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				//	SendDlgItemMessage(hDlg, ID_RBVENUS, BST_UNCHECKED, 0, 0);
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("8.87"));
					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}
					break;

			case ID_RBEARTH:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);

				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
					//SendDlgItemMessage(hDlg, ID_RBEARTH, BST_UNCHECKED, 0, 0);
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("9.8"));

					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}

				break;
			case ID_RBJUPITER:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("24.79"));


					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}

				break;
			case ID_RBMERCURY:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("3.7"));


					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}

					break;
			case ID_RBNEPTUNE:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);
				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("11.15"));
					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}

				break;
			case ID_RBSATURN:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);

				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("10.44"));

					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}
					break;
			case ID_RBURANUS:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);

				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}
					
				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("8.87"));

					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}

				break;
			
			case ID_RBEUROPA:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);

				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}

				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("1.315"));

					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}
				break;
			case ID_RBTITAN:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);

				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}

				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("1.352"));

					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}
				break;
			case ID_RBPLUTO:
				GetDlgItemText(hDlg, ID_ETEARTHWGHT, wght, 7);
				ph.weight = atof(wght);

				if (ph.weight == NULL)
				{
					MessageBox(hwnd, TEXT("Please Enter The Weight First...!"), TEXT("Error"), MB_OK | MB_ICONERROR);
					if (IDOK)
					{
						CheckRadioButton(hDlg, ID_RBMARS, ID_RBEUROPA, BST_UNCHECKED);
					}

				}

				else if (ph.weight != NULL)
				{
					//1
					SetWindowText(GetDlgItem(hDlg, ID_ETGRAVITY), TEXT("0.62"));

					mass = Mass(ph.weight);
					sprintf_s(str, "%f", mass);
					SetWindowText(GetDlgItem(hDlg, ID_ETMASS), str);

					//2
					GetDlgItemText(hDlg, ID_ETGRAVITY, gravity, 7);
					ph.gravity = atof(gravity);
					GetDlgItemText(hDlg, ID_ETMASS, mas, 7);
					ph.ms = atof(mas);

					weight = Weight(ph.gravity, ph.ms);
					sprintf_s(str, "%f", weight);
					SetWindowText(GetDlgItem(hDlg, ID_ETMWGHT), str);
				}
				else
				{
					EnableWindow(GetDlgItem(hDlg, ID_ETMASS), FALSE);
				}
				break;
				
//--------------------------------------------MatheMatics Implementation--------------------------------------------

		case ID_RBSIDE:
			//Gets Enabled
			EnableSide(hDlg);

			//Remain Disabled
			DisableAngle(hDlg);

			//reset
			ClearAngle(hDlg);
			break;
		

		case ID_RBANGLE:
			//Gets Enabled
			EnableAngle(hDlg);

			//Remain Disabled
			DisableSide(hDlg);

			//reset
			ClearSide(hDlg);
			break;
		
		case ID_PBTRIANGLES:
			if (ID_RBSIDE)
			{
				//side
				GetDlgItemText(hDlg, ID_ETSIDEONE, x1, 7);
				mm.sx1 = atof(x1);
				GetDlgItemText(hDlg, ID_ETSIDETWO, x2, 7);
				mm.sx2 = atof(x2);
				GetDlgItemText(hDlg, ID_ETSIDETHREE, x3, 7);
				mm.sx3 = atof(x3);

				GetDlgItemText(hDlg, ID_ETYONE, y1, 7);
				mm.sy1 = atof(y1);
				GetDlgItemText(hDlg, ID_ETYTWO, y2, 7);
				mm.sy2 = atof(y2);
				GetDlgItemText(hDlg, ID_ETYTHREE, y3, 7);
				mm.sy3 = atof(y3);

				/*if ((mm.sx1 == NULL || mm.sx2 == NULL || mm.sx3 == NULL) || (mm.sy1 == NULL || mm.sy2 == NULL || mm.sy3 == NULL))
				{
					MessageBox(hDlg, TEXT("X1 or X2 or X3 or Y1 or Y2 or Y3 is Missing...!!! OR All Fields are 0"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
				}
				*/
				//else
				//{
					side1 = FirstSide(mm.sx1, mm.sx2, mm.sy1, mm.sy2);

					side2 = SecondSide(mm.sx2, mm.sx3, mm.sy2, mm.sy3);

					side3 = ThirdSide(mm.sx3, mm.sx1, mm.sy3, mm.sy1);
	
				//}
				if ((side1 == side2) && (side2 == side3) && (side3 == side1))
				{

					//	void bitmapload();
					//	hMyBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(EBITMAP));

					wsprintf(str, TEXT("Equilateral"));
					SetWindowText(GetDlgItem(hDlg, ID_ETSIDERESULT), str);
				}
				if (((side1 == side2) || (side2 == side3)) || ((side3 == side1)))
				{

					//	void bitmapload();
					//	hMyBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IBITMAP));

					wsprintf(str, TEXT("Isosceles"));
					SetWindowText(GetDlgItem(hDlg, ID_ETSIDERESULT), str);
				}
				if ((side1 != side2) && (side2 != side3) && (side3 != side1))
				{

					//void bitmapload();
					//hMyBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(SBITMAP));

					wsprintf(str, TEXT("Scelen"));
					SetWindowText(GetDlgItem(hDlg, ID_ETSIDERESULT), str);
				}
				


				
			}
			///

			
			break;
			

		case ID_PBTRIANGLEA:

			
			GetDlgItemText(hDlg, ID_ETAGLONE, a1, 7);
			mm.angle1 = atof(a1);
			GetDlgItemText(hDlg, ID_ETAGLTWO, a2, 7);
			mm.angle2 = atof(a2);
			GetDlgItemText(hDlg, ID_ETAGLTHREE, a3, 7);
			mm.angle3 = atof(a3);
			triangle = TriangleIs(mm.angle1, mm.angle2, mm.angle3);
			if (triangle == 1.0)
			{
				wsprintf(str, TEXT("Equilateral"));
				SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), str);
			}
			else if (triangle == 2.0)
			{
				wsprintf(str, TEXT("Isosceles"));
				SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), str);
			}
			else if (triangle == 3.0)
			{
				wsprintf(str, TEXT("Scelen"));
				SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), str);
			}
			else if (triangle == 8.0)
			{
				wsprintf(str, TEXT("Right Isosceles"));
				SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), str);
			}
			else if (triangle == 7.0)
			{
				wsprintf(str, TEXT("Check the Angles"));
				SetWindowText(GetDlgItem(hDlg, ID_ETANGLERESULT), str);
			}

			break;

		case ID_PBANGLEA:
			GetDlgItemText(hDlg, ID_ETAGLONE, a1, 7);
			mm.angle1 = atof(a1);
			GetDlgItemText(hDlg, ID_ETAGLTWO, a2, 7);
			mm.angle2 = atof(a2);
			GetDlgItemText(hDlg, ID_ETAGLTHREE, a3, 7);
			mm.angle3 = atof(a3);
			//triangle = TriangleIs(mm.angle1, mm.angle2, mm.angle3);
			angle = AngleIs(mm.angle1, mm.angle2, mm.angle3);
				if (angle == 4.0)
				{
					wsprintf(str, TEXT("Acute Angle"));
					SetWindowText(GetDlgItem(hDlg, ID_ETAGLRESULT), str);
				}
				else if (angle == 5.0)
				{
					wsprintf(str, TEXT("Right Angle"));
					SetWindowText(GetDlgItem(hDlg, ID_ETAGLRESULT), str);
				}
				else if(angle == 6.0)
				{
					wsprintf(str, TEXT("Obtuse Angle"));
					SetWindowText(GetDlgItem(hDlg, ID_ETAGLRESULT), str);
				}
				else if (angle == 7.0)
				{
					wsprintf(str, TEXT("Check the Angles"));
					SetWindowText(GetDlgItem(hDlg, ID_ETAGLRESULT), str);
				}

			break;
//--------------------------------------------Chemistry Implementation--------------------------------------------
			/*char q1[7], q2[7], eff[7], work[7], copr[7], copac[7];
			float q1, q2, E, WD, COPr, COPac;*/
		case ID_RBHEATENGINE:
			EnableHeatEngine(hDlg);
			ClearRefrigeratorAndAC(hDlg);
			break;
		case ID_RBREF:
			EnableRefrigerator(hDlg);
			ClearACAndHeatEngine(hDlg);
			break;
		case ID_RBAC:
			EnableAC(hDlg);
			ClearHeatEngineAndReferigerator(hDlg);
			break;

		case ID_PBHEATENGINE:

			GetDlgItemText(hDlg, ID_ETQONE, q1, 7);		//q1
			ch.q1 = atof(q1);
			GetDlgItemText(hDlg, ID_ETQTWO, q2, 7);		//q2
			ch.q2 = atof(q2);

			WD = HeatEngineWD(ch.q1, ch.q2);				//WorkDone
			sprintf_s(str, "%f", WD);
			SetWindowText(GetDlgItem(hDlg, ID_ETWORKDONE), str);
			
			//GetDlgItemText(hDlg, ID_ETWORKDONE, work, 7);		//q2
			//ch.workdone = atof(work);
			
			E = HeatEngineEff(WD, ch.q1);			//Efficiency
			sprintf_s(str, "%f", E);
			SetWindowText(GetDlgItem(hDlg, ID_ETEFFICIENCY), str);
			
			break;
		case ID_PBREF:
			
			GetDlgItemText(hDlg, ID_ETQTHREE, q2, 7);		//q2
			ch.q2 = atof(q2);
			GetDlgItemText(hDlg, ID_ETWD, work, 7);		//WorkDone
			ch.workdone = atof(work);

			q_1 = RefrigeratorQ1(ch.q2, ch.workdone);				//q1
			sprintf_s(str, "%f", q_1);
			SetWindowText(GetDlgItem(hDlg, ID_ETQFOUR), str);

			COPr = RefrigeratorCoP(ch.q2, ch.workdone);	//COP Refrigerator
			sprintf_s(str, "%f", COPr);
			SetWindowText(GetDlgItem(hDlg, ID_ETCOPONE), str);

			break;
		case ID_PBAC:

			GetDlgItemText(hDlg, ID_ETQFIVE, q1, 7);
			ch.q1 = atof(q1);
			GetDlgItemText(hDlg, ID_ETWORK, work, 7);
			ch.workdone = atof(work);

			q_2 = AirConditionerQ2(ch.q1, ch.workdone);
			sprintf_s(str, "%f", q_2);
			SetWindowText(GetDlgItem(hDlg, ID_ETQSIX), str);

			COPac = AirConditionerCoP(ch.q1, ch.workdone);
			sprintf_s(str, "%f", COPac);
			SetWindowText(GetDlgItem(hDlg, ID_ETCOPTWO), str);

			break;

		case ID_PBSAVE:
			

//			Physics Data
			if(IsDlgButtonChecked(hDlg, ID_RBPHYSICS))
			{
				wsprintf(str, "%s.txt", PhysicsFileName);
				fopen_s(&file, str, "w+");
				
				fprintf_s(file, "Physics Data:\n\n");
				fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
				fprintf_s(file, "Weight Of a Person On Earth		:	%2f\n", ph.weight);
				fprintf_s(file, "Mass Is					:	%2f\n", mass);
				fprintf_s(file, "Planet's Gravity			:	%2f\n", ph.gravity);
				fprintf_s(file, "Weight Of a Person On Selected Planet	:	%2f\n", weight);
				fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
				MessageBox(hwnd, TEXT("Data is saved successfully...!!"), TEXT("DataEntry Confirmation"), MB_OK | MB_ICONINFORMATION);

				fclose(file);
			}
//			Mathematics Data
			if (IsDlgButtonChecked(hDlg, ID_RBMATHS))
			{
				if (IsDlgButtonChecked(hDlg, ID_RBSIDE))
				{
					wsprintf(str, "%s.txt", MathematicsFileName);
					fopen_s(&file, str, "w+");
					//fopen_s(&file, TEXT("Mathematics.txt"), "a");
					fprintf_s(file, "\nMathematics Data:\n");
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fprintf_s(file, "Triangle Type Using Sides\n");
					fprintf_s(file, "X1	 :	%f\n", mm.sx1);
					fprintf_s(file, "X2	 :	%f\n", mm.sx2);
					fprintf_s(file, "X3	 :	%f\n\n", mm.sx3);

					fprintf_s(file, "Y1	 :	%f\n", mm.sy1);
					fprintf_s(file, "Y2	 :	%f\n", mm.sy2);
					fprintf_s(file, "Y3	 :	%f\n\n", mm.sy3);

					GetDlgItemText(hDlg, ID_ETSIDERESULT, Triangle_Side_Result, 20);
					fprintf_s(file, "Trinangle Is	:	%s\n\n", Triangle_Side_Result);
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fclose(file);
				}
				if (IsDlgButtonChecked(hDlg, ID_RBANGLE))
				{
					wsprintf(str, "%s.txt", MathematicsFileName);
					fopen_s(&file, str, "w+");
					//fopen_s(&file, TEXT("Mathematics.txt"), "a");
					fprintf_s(file, "\nMathematics Data:\n");
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fprintf_s(file, "Angle and Triangle Type Using Angles\n");
					fprintf_s(file, "First Angle  :		%f\n", mm.angle1);
					fprintf_s(file, "Second Angle :		%f\n", mm.angle2);
					fprintf_s(file, "Third Angle  :		%f\n", mm.angle3);

					GetDlgItemText(hDlg, ID_ETANGLERESULT, Triangle_Angle_Result, 20);
					fprintf_s(file, "Trinangle Is	:	%s\n\n", Triangle_Angle_Result);

					GetDlgItemText(hDlg, ID_ETAGLRESULT, Angle_Result, 20);
					fprintf_s(file, "Angle Is	:	%s\n\n", Angle_Result);
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fclose(file);
				}

				MessageBox(hwnd, TEXT("Data is saved successfully...!!"), TEXT("DataEntry Confirmation"), MB_OK | MB_ICONINFORMATION);

				
			}
//			Chemistry Data
			if (IsDlgButtonChecked(hDlg, ID_RBCHEMISTRY))
			{
				if (IsDlgButtonChecked(hDlg, ID_RBHEATENGINE))
				{
					wsprintf(str, "%s.txt", ChemistryFileName);
					fopen_s(&file, str, "w+");
					//fopen_s(&file, TEXT("Chemistry.txt"), "a");
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fprintf_s(file, "Heat Engine\n");
					fprintf_s(file, "_________________________________________\n");
					fprintf_s(file, "|Q1		|	%f	|\n", ch.q1);
					fprintf_s(file, "|Q2		|	%f	|\n", ch.q2);
					fprintf_s(file, "|Work Done Is	|	%f	|\n", WD);
					fprintf_s(file, "|Efficiency Is	|	%f	|\n", E);
					fprintf_s(file, "_________________________________________\n");
					
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fclose(file);
				}
				
				if (IsDlgButtonChecked(hDlg, ID_RBREF))
				{
					wsprintf(str, "%s.txt", ChemistryFileName);
					fopen_s(&file, str, "w+");
					//fopen_s(&file, TEXT("Chemistry.txt"), "a");
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fprintf_s(file, "Referigerator\n");
					fprintf_s(file, "_______________________________________________________\n");
					fprintf_s(file, "|Q1				|	%f	|\n", q_1);
					fprintf_s(file, "|Q2				|	%f	|\n", ch.q2);
					fprintf_s(file, "|Work Done			|	%f	|\n", ch.workdone);
					fprintf_s(file, "|Coefficient Of Performance	|	%f	|\n", COPr);
					fprintf_s(file, "_______________________________________________________\n");

					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fclose(file);

				}
				if (IsDlgButtonChecked(hDlg, ID_RBAC))
				{
					wsprintf(str, "%s.txt", ChemistryFileName);
					fopen_s(&file, str, "w+");
					//fopen_s(&file, TEXT("Chemistry.txt"), "a");
					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
					fprintf_s(file, "Air Conditioner\n");
					fprintf_s(file, "________________________________________________________\n");
					fprintf_s(file, "|Q1				|	%f	|\n", ch.q1);
					fprintf_s(file, "|Q2				|	%f	|\n", q_2);
					fprintf_s(file, "|Work Done			|	%f	|\n", ch.workdone);
					fprintf_s(file, "|Coefficient Of Performance	|	%f	|\n", COPac);
					fprintf_s(file, "________________________________________________________\n");

					fprintf_s(file, "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
				}
				
				
				MessageBox(hwnd, TEXT("Data is saved successfully...!!"), TEXT("DataEntry Confirmation"), MB_OK | MB_ICONINFORMATION);
				
			}
			//fopen_s(&file, TEXT("Chemistry.txt"), "w+");
			//fclose(file);
			break;

		case ID_PBRESET:
			ClearPhysics(hDlg);
			ClearMaths(hDlg);
			ClearChemistry(hDlg);
			
			DisableAll(hDlg);
			DisableAngle(hDlg);
			DisableSide(hDlg);
			break;

		case IDCANCEL:
			UnInitialise();
			EndDialog(hDlg, 0);
			break;

		}
		return(TRUE);

	case WM_CTLCOLORDLG:

		
		/*SetTextColor(hdc, RGB(0, 255, 0));
		SetBkMode(hdc, RGB(0, 0, 0));*/
		return(INT_PTR)CreateSolidBrush(RGB(0, 0, 0));


		break;
	case WM_CTLCOLORSTATIC:
		hdc = HDC(wParam);
		SetTextColor(hdc, RGB(0, 255, 0));
		SetBkColor(hdc, RGB(0,0,0));
		return(INT_PTR)CreateSolidBrush(RGB(0, 0, 0));
		break;
	case WM_CTLCOLOREDIT:
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkColor(hdc, RGB(255, 255, 255));
		return(INT_PTR)CreateSolidBrush(RGB(255, 0, 0));
		break;

	
	}
	return(FALSE);
}
