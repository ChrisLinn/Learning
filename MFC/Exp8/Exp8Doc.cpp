// Exp8Doc.cpp : implementation of the CExp8Doc class
//

#include "stdafx.h"
#include "Exp8.h"

#include "Exp8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExp8Doc

IMPLEMENT_DYNCREATE(CExp8Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp8Doc, CDocument)
	//{{AFX_MSG_MAP(CExp8Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExp8Doc construction/destruction

CExp8Doc::CExp8Doc()
{
	// TODO: add one-time construction code here

}

CExp8Doc::~CExp8Doc()
{
}

BOOL CExp8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExp8Doc serialization

void CExp8Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExp8Doc diagnostics

#ifdef _DEBUG
void CExp8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExp8Doc commands
