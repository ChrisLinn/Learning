// Exp8.h : main header file for the EXP8 application
//

#if !defined(AFX_EXP8_H__5A30C90C_C146_49C6_9B65_AA434CB4DE55__INCLUDED_)
#define AFX_EXP8_H__5A30C90C_C146_49C6_9B65_AA434CB4DE55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExp8App:
// See Exp8.cpp for the implementation of this class
//

class CExp8App : public CWinApp
{
public:
	CExp8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExp8App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP8_H__5A30C90C_C146_49C6_9B65_AA434CB4DE55__INCLUDED_)
