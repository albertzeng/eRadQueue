// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__1A47F9FF_4A7E_4FC8_BD56_36AD66253887__INCLUDED_)
#define AFX_DLGPROXY_H__1A47F9FF_4A7E_4FC8_BD56_36AD66253887__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CeRadQueueControllerDlg;

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueControllerDlgAutoProxy command target

class CeRadQueueControllerDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CeRadQueueControllerDlgAutoProxy)

	CeRadQueueControllerDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CeRadQueueControllerDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CeRadQueueControllerDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CeRadQueueControllerDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CeRadQueueControllerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CeRadQueueControllerDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CeRadQueueControllerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__1A47F9FF_4A7E_4FC8_BD56_36AD66253887__INCLUDED_)
