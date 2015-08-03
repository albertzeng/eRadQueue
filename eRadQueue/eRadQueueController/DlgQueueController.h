#if !defined(AFX_DLGQUEUECONTROLLER_H__F5DD2DDD_10D3_4307_8EC1_AF3F3846EF95__INCLUDED_)
#define AFX_DLGQUEUECONTROLLER_H__F5DD2DDD_10D3_4307_8EC1_AF3F3846EF95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgQueueController.h : header file
//

#define MAX_CONTROLLER_COUNT			10

/////////////////////////////////////////////////////////////////////////////
// CDlgQueueController dialog

class CDlgQueueController : public CDialog
{
public:
	CModuleTextToSpeech	m_ModuleTTS;
	CRITICAL_SECTION	m_CriticalSection;
	CDlgController*		m_pDlgController[MAX_CONTROLLER_COUNT];

// Construction
public:
	CDlgQueueController(CWnd* pParent = NULL);   // standard constructor

// Attributes
public:
	HICON m_hIcon;

// Dialog Data
	//{{AFX_DATA(CDlgQueueController)
	enum { IDD = IDD_DIALOG_QUEUE_CONTROLLER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgQueueController)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgQueueController)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonHide();
	afx_msg void OnButtonExit();
	afx_msg void OnShowHide();
	afx_msg void OnExit();
	//}}AFX_MSG
	afx_msg void OnTrayIcon(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGQUEUECONTROLLER_H__F5DD2DDD_10D3_4307_8EC1_AF3F3846EF95__INCLUDED_)
