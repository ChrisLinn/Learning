// Exp7.h : main header file for the EXP7 application
//

#if !defined(AFX_EXP7_H__1A4468DE_EB21_42AA_B116_E6FA4B2829FF__INCLUDED_)
#define AFX_EXP7_H__1A4468DE_EB21_42AA_B116_E6FA4B2829FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExp7App:
// See Exp7.cpp for the implementation of this class
//

class CExp7App : public CWinApp
{
public:
	CExp7App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp7App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExp7App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP7_H__1A4468DE_EB21_42AA_B116_E6FA4B2829FF__INCLUDED_)
