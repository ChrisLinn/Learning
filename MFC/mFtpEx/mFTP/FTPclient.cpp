// FTPclient.cpp : implementation file
//

#include "stdafx.h"
#include "ͨ��.h"
#include "FTPclient.h"
#include "ClassXP.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFTPclient dialog


CFTPclient::CFTPclient(CWnd* pParent /*=NULL*/)
	: CDialog(CFTPclient::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFTPclient)
	m_address = _T("");
	m_user = _T("");
	m_password = _T("");
	m_port = 0;
	m_state = _T("");
	//}}AFX_DATA_INIT
	m_address="ftp.itmy520.com";
	m_user="down";
	m_password="down";
	m_port=21;
	m_bConnected=FALSE;
	m_bDir=FALSE;
}


void CFTPclient::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFTPclient)
	DDX_Control(pDX, IDC_LIST1, m_listdir);
	DDX_Text(pDX, IDC_HOST_ADDRESS, m_address);
	DDX_Text(pDX, IDC_USER, m_user);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_PORT, m_port);
	DDX_Text(pDX, IDC_STATTE, m_state);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFTPclient, CDialog)
	//{{AFX_MSG_MAP(CFTPclient)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_UPLOAD, OnUpload)
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST1, OnSetfocusList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPclient message handlers

void CFTPclient::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strServerName;  //��������
	CString strObject;     //��ѯ������
	INTERNET_PORT nPort;
	DWORD dwServiceType;   //��������
	CWaitCursor cursor;
	if(!AfxParseURL(m_address,dwServiceType,strServerName,strObject,nPort))  //�����õ�ַ
	{    
	 CString strFtpURL=_T("ftp://");  //�������ɹ��ڵ�ַǰ��ftp://
	 strFtpURL+=m_address;
	 if(!AfxParseURL(strFtpURL,dwServiceType,strServerName,strObject,nPort))
	 {  //�ٴν���,�����ɹ�,������ĵ�ַ����
		 MessageBox("��Ч��ַ!",MB_OK);
		 return;
     }
	}
	//����õ�ַ�ṩftp����,�ҷ��������Ʋ�Ϊ��ʱ,�������Ӳ���
	if((dwServiceType==INTERNET_SERVICE_FTP)&&!strServerName.IsEmpty())
	{
	 try
	 {  //���������������,��������
	  pFtpConnection=pInetSession.GetFtpConnection(strServerName,m_user,m_password,m_port,TRUE);
	 }
	 catch(CInternetException* pEx)
	   { pEx->Delete();
	      pFtpConnection=NULL;
	   }
	}
	else
	{  //�������ַ���ṩFTP����
		MessageBox("��ЧFTP�����ַ",MB_OK);
	  }
	  //�����ӳɹ�,�����б���ͼ
	if(pFtpConnection!=NULL)
	{
	  m_bConnected=TRUE;
	  m_state="���ӳɹ�";
	  CString CurrentDirectory;
	  pFtpConnection->GetCurrentDirectory(CurrentDirectory);  //�õ����ӵĵ�ǰĿ¼
	  List(CurrentDirectory);   //�б�����
	}
	else
	{
	  m_state="����ʧ��";
	}
	UpdateData(FALSE);
}

void CFTPclient::OnUpload() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 CString pathname;
	 CFileDialog dlg(true);  //���ļ��Ի���
	 if(dlg.DoModal()==IDOK)
	 {
	   pathname=dlg.GetPathName();  //�õ��ϴ��ļ���·��
	 }
	 
      pFtpConnection->PutFile(pathname,pathname);  //�ϴ��ļ�
	}
}

void CFTPclient::OnDownload() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 if(!m_bDir)
	 {  //ѡ��Ϊ�ļ�
		 CString pathname;
		 CFileDialog dlg(false);  //�����ļ��Ի���
		 char fileme[500]={0};
		 strcpy(fileme,m_filename);
		 dlg.m_ofn.lpstrFile=fileme;  //���浽���ص��ļ���
          if(dlg.DoModal()==IDOK)
		  {
		    pathname=dlg.GetPathName(); //�õ����浽���ص��ļ�·��
		  }  //m_filenameΪ���ѡ�еķ������ϵ��ļ���,��IsDir()�õ�
		  pFtpConnection->GetFile(m_filename,pathname);
	 }
	 else {MessageBox("ѡ��Ϊ��Ŀ¼,��������");
	 }
	}
}

void CFTPclient::OnDisconnect() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 pFtpConnection->Close();  //�ر��������������
      m_bConnected=FALSE;
	  m_state="�Ͽ�����";
	  UpdateData(FALSE);
	}
}

void CFTPclient::OnUp() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	  CString CurDir;
	  pFtpConnection->GetCurrentDirectory(CurDir);  //�õ���ǰĿ¼
	   if(CurDir=="/")
	   {
	    MessageBox("λ�ڸ�Ŀ¼","����");
		return;
	   }
	   int pos=CurDir.ReverseFind('/');  //���ַ���ĩ�˿�ʼ�����ַ�'/'
       if(pos==-1)
	  {
	   MessageBox("���ܷ����ϼ�Ŀ¼","����");
	   return;
	  }
	   CString updir;
	   updir=CurDir.Left(pos);  //�õ��ϼ�Ŀ¼��
	   if(pos==0)
		   updir="/";
	       List(updir);  //��Ŀ¼
	}
}

void CFTPclient::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{    //�ú�����Ӧ���˫���б���ͼ�ؼ���Ϣ
	// TODO: Add your control notification handler code here
	CWaitCursor cursor;
	if(m_listdir.GetSelectedCount()!=1)
		return;
	POSITION pos=m_listdir.GetFirstSelectedItemPosition();
	UINT nIndex=m_listdir.GetNextSelectedItem(pos);
	CString strName=m_listdir.GetItemText(nIndex,0); //����б���ͼѡ���������
	if(IsDir(strName))  //��Ϊ�ļ�  ����
	{
	 List(strName);  //��Ϊ��Ŀ¼,˫���б����г���Ŀ¼����
	}
	else {
	 OnDownload();  //��Ϊ�ļ�,˫���б��������ļ�
	}
	*pResult = 0;
}

void CFTPclient::OnSetfocusList1(NMHDR* pNMHDR, LRESULT* pResult) 
{        //�ú�����Ӧ�б���ͼ��Ľ����¼�
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 if(m_listdir.GetSelectedCount()!=1)
		 return;
	 //����б���ͼѡ���������
	 POSITION pos=m_listdir.GetFirstSelectedItemPosition();
	 UINT nIndex=m_listdir.GetNextSelectedItem(pos);
	 CString strName=m_listdir.GetItemText(nIndex,0);
	 m_bDir=IsDir(strName);
	}
	*pResult = 0;
}

BOOL CFTPclient::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	CImageList* pImageList=new CImageList();
	pImageList->Create(15,15,TRUE,1,2);  //����ͼ���б�
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_DIR);     //��Ŀ¼��Ӧͼ��
	pImageList->Add(&bitmap,(COLORREF)0xFFFFFF);  //��ͼ���б�������ͼ��
     bitmap.DeleteObject();
	 bitmap.LoadBitmap(IDB_FILE);  //�ļ���Ӧͼ��
	 pImageList->Add(&bitmap,(COLORREF)0xFFFFFF);  //��ͼ���б�������ͼ��
    bitmap.DeleteObject();
	m_listdir.SetImageList(pImageList,LVSIL_NORMAL);  //ָ��һ��ͼ���б��б���ͼ�ؼ�
	pFtpConnection=NULL;
	pImageList->Detach();    //��ͼ���б���CImagelist�������
//	ClassXP(NULL,TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFTPclient::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pFtpConnection!=NULL)
	{
	  pFtpConnection->Close();
	  delete pFtpConnection;
	}
	return CDialog::DestroyWindow();
}

BOOL CFTPclient::IsDir(CString dir)  //�ж����б���ͼ����ѡ���ļ�������Ŀ¼
{
   BOOL direc=FALSE;
   CFtpFileFind finder(pFtpConnection);
   BOOL bWorking=finder.FindFile("*");  //*������������ļ�
   while(bWorking)
   {
	   bWorking=finder.FindNextFile();  //������һ���ļ�
       if(strcmp(dir,finder.GetFileName())==0)
	   {
		    if(finder.IsDirectory())   //Ϊ��Ŀ¼
			{
				direc=TRUE;
				break;
			}
			else
			{
			  m_filename=finder.GetFileName();
			}
	   }
   }
      finder.Close();
	  return(direc);
}

void CFTPclient::List(CString strDir)  //�����г���ѡ��Ŀ¼������(��Ŀ¼���ļ�)
{ 
	CString str;
	CWaitCursor cursor;   //��ʾ�ȴ����
	CString filename;
	int strFlag;
	int Index=0;
	CString CurrentDirectory;
	pFtpConnection->GetCurrentDirectory(CurrentDirectory);  //��ȡ�˴����ӵĵ�ǰĿ¼
	if(!pFtpConnection->SetCurrentDirectory(strDir)) //����FTP��ǰĿ¼ΪstrDir
	{
      str="Ŀ¼���ܸı�";
      UpdateData(FALSE);
      return;
	}
	str="������Ŀ¼"+strDir;
	m_listdir.DeleteAllItems();  //ɾ����ͼ�ؼ���������
	CFtpFileFind finder(pFtpConnection);
	BOOL bWorking=finder.FindFile("*");  //���������ļ�
	while(bWorking)
	{
	  bWorking=finder.FindNextFile();   //������һ���ļ�
	  if(finder.IsDirectory())   //��Ϊ��Ŀ¼
		  strFlag=0;             //ʹ��Ŀ¼ͼ��
	  else      //��Ϊ�ļ�
		  strFlag=1;            //ʹ���ļ�ͼ��
	  //���б���ͼ�ؼ��в���һ������
	  m_listdir.InsertItem(Index++,finder.GetFileName(),strFlag);
	}
        finder.Close();
		m_state=str;
		UpdateData(FALSE);
	
}
