#if !defined(AFX_TABCTRLEX_H__472468C5_B41B_45F1_A3FC_96E0C95FA1EE__INCLUDED_)
#define AFX_TABCTRLEX_H__472468C5_B41B_45F1_A3FC_96E0C95FA1EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabCtrlEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabCtrlEx window

class CTabCtrlEx : public CTabCtrl
{
public:
	CBrush*		m_pBrush;
	CBrush*		m_pBrushEmphasis;

public:
	BOOL		SetBackColor(COLORREF rgbBackColor, COLORREF rgbBackColorEmphasis);
	BOOL		SetItemText(LONG nIndex, LPSTR lpValue);

// Construction
public:
	CTabCtrlEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabCtrlEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTabCtrlEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTabCtrlEx)
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABCTRLEX_H__472468C5_B41B_45F1_A3FC_96E0C95FA1EE__INCLUDED_)
