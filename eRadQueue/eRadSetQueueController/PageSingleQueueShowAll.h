#if !defined(AFX_PAGESINGLEQUEUESHOWALL_H__9772FCA8_8E4B_47EA_97FF_D4D76208AA6D__INCLUDED_)
#define AFX_PAGESINGLEQUEUESHOWALL_H__9772FCA8_8E4B_47EA_97FF_D4D76208AA6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSingleQueueShowAll.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageSingleQueueShowAll dialog

class CPageSingleQueueShowAll : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageSingleQueueShowAll)

public:
	CRunTime::CITEMController*	m_pController;
	CRunTime::CITEMColumn* m_pColumner;

MRET LoadDevice();
void RefreshColumnSet(LONG nIndex, CRunTime::CITEMColumn* pColumn);
BOOL ShowPreview();
BOOL Initialize();


public:
	CString			m_strColumnFontName;
	LONG			m_nColumnFontSize;
	COLORREF		m_clrColumnForeground;
	COLORREF		m_clrColumnBackground;
	
    CString			m_strColumnNameFontName;
	LONG			m_nColumnNameFontSize;
	COLORREF		m_clrColumnNameForeground;
    COLORREF		m_clrColumnNameBackground;


public:
	HBRUSH			m_brushColumnName;
	CFont*			m_pFontColumnName;
	HBRUSH			m_brushColumn;
	CFont*			m_pFontColumn;

   

// Construction
public:
	CPageSingleQueueShowAll();
	~CPageSingleQueueShowAll();

// Dialog Data
	//{{AFX_DATA(CPageSingleQueueShowAll)
	enum { IDD = IDD_DIALOG_MODE3_SINGLE_QUEUE_SHOWALL };
	CListCtrlEx	m_MODE3ListColumnSet;
	CListCtrlEx	m_MODE3ListQueue;
	UINT		m_MODE3ColumnRight;
	UINT		m_MODE3ColumnTop;
	UINT		m_MODE3QueueIndex;
	UINT		m_MODE3RenovateTime;
	UINT		m_MODE3ColumnRows;
	CString	m_MODE3ColumnName;
	UINT		m_MODE3ColumnLines;
	UINT		m_MODE3ColumnLeft;
	UINT		m_MODE3ColumnId;
	UINT		m_MODE3ColumnBottom;
	BOOL	m_bShowHorizontal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageSingleQueueShowAll)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageSingleQueueShowAll)
	afx_msg void OnButtonMODE3Add();
	afx_msg void OnButtonMODE3Change();
	afx_msg void OnButtonMODE3ColumnNameFtcolor();
	afx_msg void OnButtonMODE3ColumnNameBkcolor();
	afx_msg void OnButtonMODE3ColumnNameFont();
	afx_msg void OnButtonMODE3ColumnFont();
    afx_msg void OnButtonMODE3ColumnBkcolor();
	afx_msg void OnButtonMODE3Delete();
	afx_msg void OnDblclkListMODE3Queue(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnClickListMode3Columnset(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnButtonMode3ColumnFtcolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};





//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESINGLEQUEUESHOWALL_H__9772FCA8_8E4B_47EA_97FF_D4D76208AA6D__INCLUDED_)
