// eRadQueueControllerDlg.h : header file
//

#if !defined(AFX_ERADQUEUECONTROLLERDLG_H__884F06EC_BC25_4B90_B967_3B024E458359__INCLUDED_)
#define AFX_ERADQUEUECONTROLLERDLG_H__884F06EC_BC25_4B90_B967_3B024E458359__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CeRadQueueControllerDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueControllerDlg dialog

class CeRadQueueControllerDlg : public CDialog
{
	DECLARE_DYNAMIC(CeRadQueueControllerDlg);
	friend class CeRadQueueControllerDlgAutoProxy;

// Construction
public:
	CeRadQueueControllerDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CeRadQueueControllerDlg();

// Dialog Data
	//{{AFX_DATA(CeRadQueueControllerDlg)
	enum { IDD = IDD_ERADQUEUECONTROLLER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CeRadQueueControllerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CeRadQueueControllerDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CeRadQueueControllerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERADQUEUECONTROLLERDLG_H__884F06EC_BC25_4B90_B967_3B024E458359__INCLUDED_)
