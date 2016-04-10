#if !defined(AFX_FTPCLIENT_H__4F167D08_278D_4582_90ED_6B999468B35C__INCLUDED_)
#define AFX_FTPCLIENT_H__4F167D08_278D_4582_90ED_6B999468B35C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FTPclient.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFTPclient dialog

class CFTPclient : public CDialog
{
// Construction
public:
	void List(CString strDir);
	BOOL IsDir(CString dir);
	CFtpConnection *pFtpConnection;
	CInternetSession pInetSession;
	CString m_filename;
	BOOL m_bDir;
	BOOL m_bConnected;
	CFTPclient(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFTPclient)
	enum { IDD = IDD_FTP_CLIENT };
	CListCtrl	m_listdir;
	CString	m_address;
	CString	m_user;
	CString	m_password;
	UINT	m_port;
	CString	m_state;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPclient)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFTPclient)
	afx_msg void OnConnect();
	afx_msg void OnUpload();
	afx_msg void OnDownload();
	afx_msg void OnDisconnect();
	afx_msg void OnUp();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPCLIENT_H__4F167D08_278D_4582_90ED_6B999468B35C__INCLUDED_)
