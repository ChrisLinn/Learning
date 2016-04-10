#include "Draw.h"
BEGIN_MESSAGE_MAP(CDrawWnd, CFrameWnd)
ON_MESSAGE(WM_LBUTTONDOWN,OnLButtonDown)
ON_MESSAGE(WM_MOUSEMOVE,OnMouseMove)
ON_MESSAGE(WM_PAINT,OnPaint)
END_MESSAGE_MAP()

BOOL CDrawApp::InitInstance()
{
CDrawWnd *pFrame = new CDrawWnd();
pFrame->Create(0,_T("Êó±ê»æÍ¼³ÌÐò"));
pFrame->ShowWindow(m_nCmdShow);
pFrame->UpdateWindow();
this->m_pMainWnd = pFrame;
return TRUE;
}

CDrawWnd::CDrawWnd()
{
	x1=0;
	y1=0;
	x2=0;
	y2=0;
	flag=0;
}



LRESULT CDrawWnd::OnPaint(WPARAM wParam,LPARAM lParam)
{
	CPaintDC dc(this);
	CPen pen,*pOldPen;
	if(flag==1)
	{	
	pen.CreatePen(PS_SOLID,2,RGB(0,0,0));
	pOldPen=dc.SelectObject(&pen);
	dc.Rectangle(x1,y1,x2,y2);
	dc.SelectObject(pOldPen);
	}
	if(flag==2)
	{	
	pen.CreatePen(PS_SOLID,2,RGB(0,0,0));
	pOldPen=dc.SelectObject(&pen);
	dc.Ellipse(x1,y1,x2,y2);
	dc.SelectObject(pOldPen);
	}
	flag=0;
	return 0;
}

LRESULT CDrawWnd::OnLButtonDown(WPARAM wParam,LPARAM lParam)
{
	 x1=LOWORD(lParam);
	 y1=HIWORD(lParam);
	 return 0;
}
LRESULT CDrawWnd::OnMouseMove(WPARAM wParam,LPARAM lParam)
{
	if((wParam&MK_CONTROL)&&(wParam&MK_LBUTTON))
		{
			flag=1;
			x2=LOWORD(lParam);
			y2=HIWORD(lParam);
			Invalidate(TRUE);
		}
	else if((wParam&MK_SHIFT)&&(wParam&MK_LBUTTON))
		{
			flag=2;
			x2=LOWORD(lParam);
			y2=HIWORD(lParam);
			Invalidate(TRUE);
		}
	return 0;
}
/**/