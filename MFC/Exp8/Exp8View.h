// Exp8View.h : interface of the CExp8View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXP8VIEW_H__A9A718ED_E0EC_4ED7_AB90_000150DDC873__INCLUDED_)
#define AFX_EXP8VIEW_H__A9A718ED_E0EC_4ED7_AB90_000150DDC873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pic.h"

class CExp8View : public CView
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CExp8View)
// Attributes
public:

	CExp8View();
	CExp8Doc* GetDocument();
	
	int X0;
	int Y0;
	int X1;
	int Y1;
	int shape;
	int num;

	Pic pic[100];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp8View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExp8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExp8View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawEllipse();
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnDrawRect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Exp8View.cpp
inline CExp8Doc* CExp8View::GetDocument()
   { return (CExp8Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP8VIEW_H__A9A718ED_E0EC_4ED7_AB90_000150DDC873__INCLUDED_)
