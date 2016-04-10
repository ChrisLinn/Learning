// Exp7Dlg.h : header file
//

#if !defined(AFX_EXP7DLG_H__4BFEDEA6_51D7_4C3E_83A5_99D6E3EA9722__INCLUDED_)
#define AFX_EXP7DLG_H__4BFEDEA6_51D7_4C3E_83A5_99D6E3EA9722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExp7Dlg dialog

class CExp7Dlg : public CDialog
{
// Construction
public:
	CExp7Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExp7Dlg)
	enum { IDD = IDD_EXP7_DIALOG };
	CScrollBar	m_Red;
	CScrollBar	m_Green;
	CScrollBar	m_Blue;
	BOOL	m_bCheckShow;
	CString	m_szRGB;
	int		m_nPenStyle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp7Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExp7Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonQuit();
	afx_msg void OnButtonShow();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP7DLG_H__4BFEDEA6_51D7_4C3E_83A5_99D6E3EA9722__INCLUDED_)
