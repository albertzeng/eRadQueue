#if !defined(AFX_DLGLOGIN_H__D8A5C743_7076_4B65_B54B_5CB9C54D7CB6__INCLUDED_)
#define AFX_DLGLOGIN_H__D8A5C743_7076_4B65_B54B_5CB9C54D7CB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLogin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog

class CDlgLogin : public CDialog
{
public:
	LONG		m_nDoctorIndex;
	LONG		m_nDoctorDepartment;
	LONG		m_nDoctorPrivilege;
	CString		m_strDoctorPassword;
	
public:
	static MRET	AutoLogin(CString strDoctorCode);

// Construction
public:
	CDlgLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLogin)
	enum { IDD = IDD_DIALOG_LOGIN };
	CButton	m_ibLogin;
	CString	m_strCode;
	CString	m_strDepartment;
	CString	m_strName;
	CString	m_strPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CDlgLogin)
		// NOTE: the ClassWizard will add member functions here
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnKillfocusEditCode();
	afx_msg void OnButtonLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGIN_H__D8A5C743_7076_4B65_B54B_5CB9C54D7CB6__INCLUDED_)
