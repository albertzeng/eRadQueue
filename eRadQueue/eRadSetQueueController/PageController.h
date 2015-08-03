#if !defined(AFX_PAGECONTROLLER_H__C95BF80E_74CE_48C0_84FD_8752BB34687B__INCLUDED_)
#define AFX_PAGECONTROLLER_H__C95BF80E_74CE_48C0_84FD_8752BB34687B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageController.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageController dialog

class CPageController : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageController)

public:
	CRunTime::CITEMController* m_pController;

public:
	HBRUSH			m_brushController;
	CFont*			m_pFontController;
	HBRUSH			m_brushScroll;
	CFont*			m_pFontScroll;
	HBRUSH			m_brushTitle;
	CFont*			m_pFontTitle;

public:
	CString			m_strControllerFontName;
	LONG			m_nControllerFontSize;
	COLORREF		m_clrControllerBackground;
	CString			m_strScrollFontName;
	LONG			m_nScrollFontSize;
	COLORREF		m_clrScrollBackground;
	COLORREF		m_clrScrollForeground;
	CString			m_strTitleFontName;
	LONG			m_nTitleFontSize;
	COLORREF		m_clrTitleBackground;
	COLORREF		m_clrTitleForeground;

public:
	BOOL Initialize();
	BOOL DoValidate(BOOL bInsert = TRUE);
	BOOL ShowPreview();
	void RefreshController();
	void RefreshController(LONG nIndex, CRunTime::CITEMController* pController);


// Construction
public:
	CPageController();
	~CPageController();

// Dialog Data
	//{{AFX_DATA(CPageController)
	enum { IDD = IDD_DIALOG_CONTROLLER };
	CListCtrlEx	m_listController;
	UINT	m_nControllerNode;
	CString	m_strControllerName;
	long	m_nControllerLeft;
	long	m_nControllerTop;
	long	m_nControllerWidth;
	long	m_nControllerHeight;
	UINT	m_nControllerRows;
	BOOL	m_bScrollEnable;
	UINT	m_nScrollHeight;
	long	m_nScrollSpeed;
	long    m_nQueueScrollSpeed;
	CString	m_strScrollContent;
	int		m_nControllerMode;
	BOOL	m_bControllerFromTop;
	BOOL	m_bTitleEnable;
	CString	m_strTitleContent;
	UINT	m_nTitleHeight;
	UINT	m_nControllerCols;
	BOOL	m_bDesc;
	BOOL    m_bScroll;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageController)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageController)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonInsert();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListController(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListController(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonControllerBackground();
	afx_msg void OnButtonControllerFont();
	afx_msg void OnButtonScrollBackground();
	afx_msg void OnButtonScrollForeground();
	afx_msg void OnButtonScrollFont();
	afx_msg void OnButtonTitleBackground();
	afx_msg void OnButtonTitleForeground();
	afx_msg void OnButtonTitleFont();
	//}}AFX_MSG
	afx_msg void OnRefreshList(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONTROLLER_H__C95BF80E_74CE_48C0_84FD_8752BB34687B__INCLUDED_)
