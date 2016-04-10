// Exp8View.cpp : implementation of the CExp8View class
//

#include "stdafx.h"
#include "Exp8.h"
#include "Pic.h"
#include "Exp8Doc.h"
#include "Exp8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CExp8View

IMPLEMENT_DYNCREATE(CExp8View, CView)

BEGIN_MESSAGE_MAP(CExp8View, CView)
	//{{AFX_MSG_MAP(CExp8View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_ELLIPSE, OnDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, OnUpdateDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, OnUpdateDrawRect)
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExp8View construction/destruction

CExp8View::CExp8View()
{
	// TODO: add construction code here
	X0=0;
	Y0=0;
	X1=0;
	Y1=0;
	shape=0;
	num=0;
}

CExp8View::~CExp8View()
{
}

BOOL CExp8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExp8View drawing

void CExp8View::OnDraw(CDC* pDC)
{
	CExp8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CPen Pen;
	Pen.CreatePen(PS_DASH,1,RGB(0,0,0));

	for(int i=0;i<num;i++)
		{
			switch(pic[i].shape)
			{
			case 0:	
				pDC->MoveTo(pic[i].X0,pic[i].Y0);
				pDC->LineTo(pic[i].X1,pic[i].Y1);
				break;
			case 1:
				pDC->Rectangle(pic[i].X0,pic[i].Y0,pic[i].X1,pic[i].Y1);
				break;
			case 2:
				pDC->Ellipse(pic[i].X0,pic[i].Y0,pic[i].X1,pic[i].Y1);
				break;
			}
		}

}

/////////////////////////////////////////////////////////////////////////////
// CExp8View printing

BOOL CExp8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExp8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExp8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExp8View diagnostics

#ifdef _DEBUG
void CExp8View::AssertValid() const
{
	CView::AssertValid();
}

void CExp8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp8Doc* CExp8View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp8Doc)));
	return (CExp8Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExp8View message handlers

void CExp8View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	X0 = point.x;
	Y0 = point.y;

	CView::OnLButtonDown(nFlags, point);
}

void CExp8View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pic[num].shape = shape;
	pic[num].X0=X0;
	pic[num].Y0=Y0;
	pic[num].X1=X1;
	pic[num].Y1=Y1;
	num++;
	Invalidate(TRUE);
	CView::OnLButtonUp(nFlags, point);
}

void CExp8View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(nFlags & MK_LBUTTON)
	{
		CClientDC dc(this);
		CPen PenBK,Pen,*pOldPen;
		PenBK.CreatePen(PS_SOLID,1,RGB(255,255,255));
		pOldPen = dc.SelectObject(&PenBK);
		switch(shape)
		{
		case 0:
			dc.MoveTo(X0,Y0);
			dc.LineTo(X1,Y1);
			break;
		case 1:
			dc.Rectangle(X0,Y0,X1,Y1);
			break;
		case 2:
			dc.Ellipse(X0,Y0,X1,Y1);
			break;
		}
		
		Pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
		dc.SelectObject(&Pen);
		

		X1 = point.x;
		Y1 = point.y;


		switch(shape)
		{
		case 0:
			dc.MoveTo(X0,Y0);
			dc.LineTo(X1,Y1);
			break;
		case 1:
			dc.Rectangle(X0,Y0,X1,Y1);
			break;
		case 2:
			dc.Ellipse(X0,Y0,X1,Y1);
			break;
		}

		dc.SelectObject(pOldPen);
	}
	
	CView::OnMouseMove(nFlags, point);
}





void CExp8View::OnDrawEllipse() 
{
	// TODO: Add your command handler code here
	shape=2;
}

void CExp8View::OnUpdateDrawEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		if(shape == 2)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}

void CExp8View::OnDrawLine() 
{
	// TODO: Add your command handler code here
	shape=0;
}


void CExp8View::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if(shape == 0)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}



void CExp8View::OnDrawRect() 
{
	// TODO: Add your command handler code here
	shape=1;
}

void CExp8View::OnUpdateDrawRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		if(shape == 1)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}
