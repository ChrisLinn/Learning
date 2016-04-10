// Exp8Doc.h : interface of the CExp8Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXP8DOC_H__5BA747C3_5B99_4406_ADB7_FB228922D0CF__INCLUDED_)
#define AFX_EXP8DOC_H__5BA747C3_5B99_4406_ADB7_FB228922D0CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExp8Doc : public CDocument
{
protected: // create from serialization only
	CExp8Doc();
	DECLARE_DYNCREATE(CExp8Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExp8Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExp8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExp8Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXP8DOC_H__5BA747C3_5B99_4406_ADB7_FB228922D0CF__INCLUDED_)
