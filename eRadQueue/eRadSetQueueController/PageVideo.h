#if !defined(AFX_PAGEVIDEO_H__A0D02A53_E9E3_4B77_9A51_B1FD16988FDC__INCLUDED_)
#define AFX_PAGEVIDEO_H__A0D02A53_E9E3_4B77_9A51_B1FD16988FDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageVideo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageVideo dialog

class CPageVideo : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageVideo)

public:
	CRunTime::CITEMVideo*	m_pVideo;

public:
	CRunTime::CITEMController*	m_pController;

public:
	HBRUSH			m_brushController;
	CFont*			m_pFontController;

public:
	COLORREF		m_clrVideoForeground;

public:
	BOOL Initialize();
	BOOL DoValidate(BOOL bInsert = TRUE);
	void RefreshVideo();
	void RefreshVideo(LONG nIndex, CRunTime::CITEMVideo* pVideo);

// Construction
public:
	CPageVideo();
	~CPageVideo();

// Dialog Data
	//{{AFX_DATA(CPageVideo)
	enum { IDD = IDD_DIALOG_VIDEO };
	CListCtrlEx	m_listVideo;
	UINT	m_nVideoOrder;
	UINT	m_nVideoLength;
	CString	m_strVideoContent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageVideo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageVideo)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonInsert();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListVideo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonVideoForeground();
	//}}AFX_MSG
	afx_msg void OnRefreshList(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVIDEO_H__A0D02A53_E9E3_4B77_9A51_B1FD16988FDC__INCLUDED_)
