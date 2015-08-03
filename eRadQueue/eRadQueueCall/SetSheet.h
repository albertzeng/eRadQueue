#if !defined(AFX_SETSHEET_H__EE5BB6E9_4BC1_4ADF_9CFA_745255E2CFE7__INCLUDED_)
#define AFX_SETSHEET_H__EE5BB6E9_4BC1_4ADF_9CFA_745255E2CFE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetSheet

class CSetSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetSheet)

// Construction
public:
	CSetSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSetSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	HICON m_hIcon;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetSheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSetSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSetSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSHEET_H__EE5BB6E9_4BC1_4ADF_9CFA_745255E2CFE7__INCLUDED_)
