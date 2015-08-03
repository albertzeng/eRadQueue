#if !defined(AFX_PAGEVOICE_H__6BAD3EB7_B233_468F_9517_A85D0193EDF7__INCLUDED_)
#define AFX_PAGEVOICE_H__6BAD3EB7_B233_468F_9517_A85D0193EDF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageVoice.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageVoice dialog

class CPageVoice : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageVoice)

public:
	CRunTime::CITEMController*	m_pController;

// Construction
public:
	CPageVoice();
	~CPageVoice();

// Dialog Data
	//{{AFX_DATA(CPageVoice)
	enum { IDD = IDD_DIALOG_VOICE };
	BOOL	m_bVoiceEnable;
	CString	m_strVoiceFormat;
	UINT	m_nVoiceRepeat;
	UINT	m_nVoiceInterval;
	BOOL	m_bpromptVoiceEnable;
	BOOL	m_bUseKdfx;
	CString	m_strSeriesId;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageVoice)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageVoice)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVOICE_H__6BAD3EB7_B233_468F_9517_A85D0193EDF7__INCLUDED_)
