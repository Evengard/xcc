// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__CA392AEC_CC6E_11D4_B606_0000B4936994__INCLUDED_)
#define AFX_CHILDFRM_H__CA392AEC_CC6E_11D4_B606_0000B4936994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXCCModCreatorView;

class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributes
protected:
	CSplitterWnd m_wndSplitter;
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CXCCModCreatorView* GetRightPane();
// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
	afx_msg void OnFileExport();
	afx_msg void OnEditSelectAll();
	afx_msg void OnEditInvertSelection();
	afx_msg void OnViewRefresh();
	afx_msg void OnViewOptions();
	afx_msg void OnViewLaunch();
	afx_msg void OnModClearGameDirectory();
	afx_msg void OnModActivate();
	afx_msg void OnModDeactivate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__CA392AEC_CC6E_11D4_B606_0000B4936994__INCLUDED_)
