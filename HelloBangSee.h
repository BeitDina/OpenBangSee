// HelloBangSee.h : main header file for the HELLOBANGSEE application
//

#if !defined(AFX_HELLOBANGSEE_H__0A70C329_21C5_409B_8E52_ADA094148D37__INCLUDED_)
#define AFX_HELLOBANGSEE_H__0A70C329_21C5_409B_8E52_ADA094148D37__INCLUDED_
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "signal.h"
#include "win32cond.h"
#include <wincrypt.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHelloBangSeeApp:
// See HelloBangSee.cpp for the implementation of this class
//

class CHelloBangSeeApp : public CWinApp
{
public:
	CHelloBangSeeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelloBangSeeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHelloBangSeeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELLOBANGSEE_H__0A70C329_21C5_409B_8E52_ADA094148D37__INCLUDED_)
