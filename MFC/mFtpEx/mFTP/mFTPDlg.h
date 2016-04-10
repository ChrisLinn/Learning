
// mFTPDlg.h : ͷ�ļ�
//

#pragma once


// CmFTPDlg �Ի���
class CmFTPDlg : public CDialogEx
{
// ����
public:
	void List(CString strDir);
	BOOL IsDir(CString dir);
	CFtpConnection *pFtpConnection;
	CInternetSession pInetSession;
	CString m_filename;
	BOOL m_bDir;
	BOOL m_bConnected;
	CmFTPDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFTP_DIALOG };
	CListCtrl	m_listdir;
	CString	m_address;
	CString	m_user;
	CString	m_password;
	UINT	m_port;
	CString	m_state;

	virtual BOOL DestroyWindow();

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	afx_msg void OnConnect();
	afx_msg void OnUpload();
	afx_msg void OnDownload();
	afx_msg void OnDisconnect();
	afx_msg void OnUp();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
