#if !defined(AFX_PAGEMODE1REPORT_H__810A22D2_AC77_4D20_8E3D_CE89126AA5F4__INCLUDED_)
#define AFX_PAGEMODE1REPORT_H__810A22D2_AC77_4D20_8E3D_CE89126AA5F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageMode1Report.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageMode1Report dialog

class CPageMode1Report : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageMode1Report)

public:
	CRunTime::CITEMController*	m_pController;

// Construction
public:
	CPageMode1Report();
	~CPageMode1Report();

// Dialog Data
	//{{AFX_DATA(CPageMode1Report)
	enum { IDD = IDD_DIALOG_MODE1_REPORT };
	CComboBoxCheck	m_cboMode1ExcludeOutStatus;
	CComboBoxCheck	m_cboMode1AdmissionSource;
	CComboBoxCheck	m_cboMode1SourceHospital;
	UINT	m_nMode1TimeRange;
	UINT	m_nMode1TimeDelay;
	UINT	m_nMode1RefreshIdle;
	UINT	m_nMode1RefreshScreen;
	int		m_nMode1OrderMode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageMode1Report)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageMode1Report)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboMode1AdmissionSource();
	afx_msg void OnSelchangeComboMode1ExcludeOutStatus();
	afx_msg void OnSelchangeComboMode1SourceHospital();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEMODE1REPORT_H__810A22D2_AC77_4D20_8E3D_CE89126AA5F4__INCLUDED_)
