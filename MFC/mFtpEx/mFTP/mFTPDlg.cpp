
// mFTPDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mFTP.h"
#include "mFTPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmFTPDlg 对话框




CmFTPDlg::CmFTPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmFTPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//{{AFX_DATA_INIT(CmFTPDlg)
	m_address = _T("");
	m_user = _T("");
	m_password = _T("");
	m_port = 0;
	m_state = _T("");
	//}}AFX_DATA_INIT
	m_address="ftp.byethost16.com";
	m_user="b16_16416285";
	m_password="EELABUPC";
	m_port=21;
	m_bConnected=FALSE;
	m_bDir=FALSE;
}	

void CmFTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listdir);
	DDX_Text(pDX, IDC_HOST_ADDRESS, m_address);
	DDX_Text(pDX, IDC_USER, m_user);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_PORT, m_port);
	DDX_Text(pDX, IDC_STATTE, m_state);
}

BEGIN_MESSAGE_MAP(CmFTPDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_UPLOAD, OnUpload)
	ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST1, OnSetfocusList1)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmFTPDlg 消息处理程序

BOOL CmFTPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CImageList* pImageList=new CImageList();
	pImageList->Create(15,15,TRUE,1,2);  //创建图像列表
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_DIR);     //子目录对应图像
	pImageList->Add(&bitmap,(COLORREF)0xFFFFFF);  //在图像列表中增加图像
     bitmap.DeleteObject();
	 bitmap.LoadBitmap(IDB_FILE);  //文件对应图像
	 pImageList->Add(&bitmap,(COLORREF)0xFFFFFF);  //在图像列表中增加图像
    bitmap.DeleteObject();
	m_listdir.SetImageList(pImageList,LVSIL_NORMAL);  //指定一个图像列表到列表视图控件
	pFtpConnection=NULL;
	pImageList->Detach();    //把图像列表与CImagelist对象分离
//	ClassXP(NULL,TRUE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmFTPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmFTPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmFTPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CmFTPDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strServerName;  //服务器名
	CString strObject;     //查询对象名
	INTERNET_PORT nPort;
	DWORD dwServiceType;   //服务类型
	CWaitCursor cursor;
	if(!AfxParseURL(m_address,dwServiceType,strServerName,strObject,nPort))  //解析该地址
	{    
	 CString strFtpURL=_T("ftp://");  //解析不成功在地址前加ftp://
	 strFtpURL+=m_address;
	 if(!AfxParseURL(strFtpURL,dwServiceType,strServerName,strObject,nPort))
	 {  //再次解析,还不成功,则输入的地址错误
		 MessageBox(_T("无效地址!"),MB_OK);
		 return;
     }
	}
	//如果该地址提供ftp服务,且服务器名称不为空时,进行连接操作
	if((dwServiceType==INTERNET_SERVICE_FTP)&&!strServerName.IsEmpty())
	{
	 try
	 {  //向服务器发送请求,建立连接
	  pFtpConnection=pInetSession.GetFtpConnection(strServerName,m_user,m_password,m_port,TRUE);
	 }
	 catch(CInternetException* pEx)
	   { pEx->Delete();
	      pFtpConnection=NULL;
	   }
	}
	else
	{  //该网络地址不提供FTP服务
		MessageBox(_T("无效FTP网络地址"),MB_OK);
	  }
	  //如连接成功,更新列表视图
	if(pFtpConnection!=NULL)
	{
	  m_bConnected=TRUE;
	  m_state="连接成功";
	  CString CurrentDirectory;
	  pFtpConnection->GetCurrentDirectory(CurrentDirectory);  //得到连接的当前目录
	  List(CurrentDirectory);   //列表内容
	}
	else
	{
	  m_state="连接失败";
	}
	UpdateData(FALSE);
}

void CmFTPDlg::OnUpload() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 CString pathname;
	 CFileDialog dlg(true);  //打开文件对话框
	 if(dlg.DoModal()==IDOK)
	 {
	   pathname=dlg.GetPathName();  //得到上传文件的路径
	 }
	 
      pFtpConnection->PutFile(pathname,pathname);  //上传文件
	}
}

void CmFTPDlg::OnDownload() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 if(!m_bDir)
	 {  //选择为文件
		 CString pathname;
		 CFileDialog dlg(false);  //保存文件对话框
		 char fileme[500]={0}; 
		 strcpy(fileme,m_filename);
		 //dlg.m_ofn.lpstrFile=(LPWSTR)fileme;  //保存到本地的文件名
		 dlg.m_ofn.lpstrFile=(LPSTR)fileme;  //保存到本地的文件名
          if(dlg.DoModal()==IDOK)
		  {
		    pathname=dlg.GetPathName(); //得到保存到本地的文件路径
		  }  //m_filename为鼠标选中的服务器上的文件名,由IsDir()得到
		  pFtpConnection->GetFile(m_filename,pathname);
	 }
	 else {MessageBox(_T("选择为子目录,不能下载"));
	 }
	}
}

void CmFTPDlg::OnDisconnect() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 pFtpConnection->Close();  //关闭与服务器的连接
      m_bConnected=FALSE;
	  m_state="断开连接";
	  UpdateData(FALSE);
	}
}

void CmFTPDlg::OnUp() 
{
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	  CString CurDir;
	  pFtpConnection->GetCurrentDirectory(CurDir);  //得到当前目录
	   if(CurDir=="/")
	   {
	    MessageBox(_T("位于根目录"),_T("错误"));
		return;
	   }
	   int pos=CurDir.ReverseFind('/');  //从字符串末端开始查找字符'/'
       if(pos==-1)
	  {
	   MessageBox(_T("不能返回上级目录"),_T("错误"));
	   return;
	  }
	   CString updir;
	   updir=CurDir.Left(pos);  //得到上级目录名
	   if(pos==0)
		   updir="/";
	       List(updir);  //列目录
	}
}

void CmFTPDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{    //该函数对应鼠标双击列表视图控件消息
	// TODO: Add your control notification handler code here
	CWaitCursor cursor;
	if(m_listdir.GetSelectedCount()!=1)
		return;
	POSITION pos=m_listdir.GetFirstSelectedItemPosition();
	UINT nIndex=m_listdir.GetNextSelectedItem(pos);
	CString strName=m_listdir.GetItemText(nIndex,0); //获得列表视图选中项的名字
	if(IsDir(strName))  //如为文件  返回
	{
	 List(strName);  //如为子目录,双击列表项列出子目录内容
	}
	else {
	 OnDownload();  //如为文件,双击列表项下载文件
	}
	*pResult = 0;
}

void CmFTPDlg::OnSetfocusList1(NMHDR* pNMHDR, LRESULT* pResult) 
{        //该函数响应列表视图项的焦点事件
	// TODO: Add your control notification handler code here
	if(m_bConnected)
	{
	 if(m_listdir.GetSelectedCount()!=1)
		 return;
	 //获得列表视图选中项的名字
	 POSITION pos=m_listdir.GetFirstSelectedItemPosition();
	 UINT nIndex=m_listdir.GetNextSelectedItem(pos);
	 CString strName=m_listdir.GetItemText(nIndex,0);
	 m_bDir=IsDir(strName);
	}
	*pResult = 0;
}

BOOL CmFTPDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pFtpConnection!=NULL)
	{
	  pFtpConnection->Close();
	  delete pFtpConnection;
	}
	return CDialog::DestroyWindow();
}

BOOL CmFTPDlg::IsDir(CString dir)  //判断在列表视图中是选择文件还是子目录
{
   BOOL direc=FALSE;
   CFtpFileFind finder(pFtpConnection);
   BOOL bWorking=finder.FindFile("*");  //*代表查找所有文件
   while(bWorking)
   {
	   bWorking=finder.FindNextFile();  //查找下一个文件
       if(strcmp(dir,finder.GetFileName())==0)
	   {
		    if(finder.IsDirectory())   //为子目录
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

void CmFTPDlg::List(CString strDir)  //用于列出所选子目录的内容(子目录和文件)
{ 
	CString str;
	CWaitCursor cursor;   //显示等待光标
	CString filename;
	int strFlag;
	int Index=0;
	CString CurrentDirectory;
	pFtpConnection->GetCurrentDirectory(CurrentDirectory);  //获取此次连接的当前目录
	if(!pFtpConnection->SetCurrentDirectory(strDir)) //设置FTP当前目录为strDir
	{
      str="目录不能改变";
      UpdateData(FALSE);
      return;
	}
	str="进入子目录"+strDir;
	m_listdir.DeleteAllItems();  //删除视图控件中所有项
	CFtpFileFind finder(pFtpConnection);
	BOOL bWorking=finder.FindFile("*");  //查找所有文件
	while(bWorking)
	{
	  bWorking=finder.FindNextFile();   //查找下一个文件
	  if(finder.IsDirectory())   //如为子目录
		  strFlag=0;             //使用目录图像
	  else      //如为文件
		  strFlag=1;            //使用文件图像
	  //向列表视图控件中插入一个新项
	  m_listdir.InsertItem(Index++,finder.GetFileName(),strFlag);
	}
        finder.Close();
		m_state=str;
		UpdateData(FALSE);
	
}
