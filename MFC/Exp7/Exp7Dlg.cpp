// Exp7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Exp7.h"
#include "Exp7Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExp7Dlg dialog

CExp7Dlg::CExp7Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExp7Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExp7Dlg)
	m_bCheckShow = TRUE;
	m_szRGB = _T("RGB(125,125,125)");
	m_nPenStyle = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExp7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExp7Dlg)
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_Red);
	DDX_Control(pDX, IDC_SCROLLBAR_GREEN, m_Green);
	DDX_Control(pDX, IDC_SCROLLBAR_BLUE, m_Blue);
	DDX_Check(pDX, IDC_CHECK_SHOW, m_bCheckShow);
	DDX_Text(pDX, IDC_EDIT_RGB, m_szRGB);
	DDX_Radio(pDX, IDC_RADIO_SOLID, m_nPenStyle);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExp7Dlg, CDialog)
	//{{AFX_MSG_MAP(CExp7Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_QUIT, OnButtonQuit)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, OnButtonShow)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExp7Dlg message handlers

BOOL CExp7Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Red.SetScrollRange(0,255);
	m_Green.SetScrollRange(0,255);
	m_Blue.SetScrollRange(0,255);

	m_Red.SetScrollPos(125);
	m_Green.SetScrollPos(125);
	m_Blue.SetScrollPos(125);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExp7Dlg::OnPaint() 
{
	CPaintDC dc(this);
	CPen Pen,*pOldPen;
	CBrush Brush,*pOldBrush;
	char tex[100];

	UpdateData(TRUE);
		if(m_bCheckShow)
		{
			switch(m_nPenStyle)
			{
			case 0:
				Pen.CreatePen(PS_SOLID,1,
						RGB(0,0,0));
				break;
			case 1:
				Pen.CreatePen(PS_DASH,1,
						RGB(0,0,0));
				break;
			case 2:
				Pen.CreatePen(PS_DASHDOT,1,
						RGB(0,0,0));
				break;
			case 3:
				Pen.CreatePen(PS_DASHDOTDOT,1,
						RGB(0,0,0));
				break;
			}
			pOldPen=dc.SelectObject(&Pen);
			Brush.CreateSolidBrush(RGB(m_Red.GetScrollPos(),m_Green.GetScrollPos(),m_Blue.GetScrollPos()));
			pOldBrush=dc.SelectObject(&Brush);
			dc.Rectangle(45,45,520,190);
			dc.SelectObject(pOldPen);
			dc.SelectObject(pOldBrush);
		}
		else
		{
			pOldPen=(CPen*)dc.SelectStockObject(NULL_PEN);
			pOldBrush=(CBrush*)dc.SelectStockObject(NULL_BRUSH);
			dc.Rectangle(50,50,530,200);
			dc.SelectObject(pOldPen);
			dc.SelectObject(pOldBrush);
		}
		/*	sprintf(tex,"%d",m_nPenStyle);
			dc.TextOut(10,10,tex,strlen(tex));
			CDialog::OnPaint(); */
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExp7Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}




void CExp7Dlg::OnButtonQuit() 
{
	// TODO: Add your control notification handler code here

	CExp7Dlg::DestroyWindow();
}



void CExp7Dlg::OnButtonShow() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Invalidate(TRUE);
}

void CExp7Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
		UINT pos;

	switch(nSBCode)
	{
	case SB_THUMBTRACK:
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		pos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(pos-10);
		break;
	case SB_LINERIGHT:
		pos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(pos+10);
		break;
	case SB_PAGELEFT:
		pos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(pos-30);
		break;
	case SB_PAGERIGHT:
		pos = pScrollBar->GetScrollPos();
		pScrollBar->SetScrollPos(pos+30);
		break;
	}

	m_szRGB.Format("RGB(%d,%d,%d)",
		m_Red.GetScrollPos(),
		m_Green.GetScrollPos(),
		m_Blue.GetScrollPos()
		);

	UpdateData(FALSE);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
