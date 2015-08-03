#if !defined(AFX_PAGEGENERAL_H__BEBCA22C_9466_4F9B_A309_9C058756B593__INCLUDED_)
#define AFX_PAGEGENERAL_H__BEBCA22C_9466_4F9B_A309_9C058756B593__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGeneral.h : header file
//

#include "ModuleTextToSpeech.h"

/////////////////////////////////////////////////////////////////////////////
// CPageGeneral dialog

class CPageGeneral : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageGeneral)

public:
	CModuleTextToSpeech	m_ModuleTTS;

public:
	MRET				LoadDepartment();
	CString				GetDatabaseTXT(CString strConnect);

// Construction
public:
	CPageGeneral();
	~CPageGeneral();

// Dialog Data
	//{{AFX_DATA(CPageGeneral)
	enum { IDD = IDD_DIALOG_GENERAL };
	CComboBox	m_cboVoiceClass;
	CComboBox	m_cboDepartment;
	BOOL	m_bLogTRACK;
	BOOL	m_bLogDEBUG;
	BOOL	m_bLogERROR;
	BOOL	m_bLogMESSAGE;
	long	m_nVoiceRate;
	long	m_nVoiceVolume;
	CString	m_strVoicePlay;
	BOOL	m_bAutoLogin;
	BOOL    m_bHideName;
	CString	m_strAutoDoctorCode;

	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageGeneral)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageGeneral)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonEISDatabase();
	afx_msg void OnButtonVoicePlay();
	afx_msg void OnSelchangeComboDepartment();
	afx_msg void OnSelchangeComboVoiceClass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGENERAL_H__BEBCA22C_9466_4F9B_A309_9C058756B593__INCLUDED_)
