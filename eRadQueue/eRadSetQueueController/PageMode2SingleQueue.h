#if !defined(AFX_PAGEMODE2SINGLEQUEUE_H__EAB261FC_57B3_462F_87C5_E0173A197FEA__INCLUDED_)
#define AFX_PAGEMODE2SINGLEQUEUE_H__EAB261FC_57B3_462F_87C5_E0173A197FEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageMode2SingleQueue.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageMode2SingleQueue dialog

class CPageMode2SingleQueue : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageMode2SingleQueue)

public:
	CRunTime::CITEMController*	m_pController;

public:
	MRET	LoadDevice();

// Construction
public:
	CPageMode2SingleQueue();
	~CPageMode2SingleQueue();

// Dialog Data
	//{{AFX_DATA(CPageMode2SingleQueue)
	enum { IDD = IDD_DIALOG_MODE2_SINGLE_QUEUE };
	CListCtrlEx	m_listDevice;
	long	m_nMode2DeviceIndex;
	UINT	m_nMode2RefreshIdle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageMode2SingleQueue)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageMode2SingleQueue)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListDevice(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEMODE2SINGLEQUEUE_H__EAB261FC_57B3_462F_87C5_E0173A197FEA__INCLUDED_)
