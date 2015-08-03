#if !defined(AFX_PAGEGENERAL_H__BEBCA22C_9466_4F9B_A309_9C058756B593__INCLUDED_)
#define AFX_PAGEGENERAL_H__BEBCA22C_9466_4F9B_A309_9C058756B593__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGeneral.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageGeneral dialog

class CPageGeneral : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageGeneral)

public:
	LONG	m_nCallDepartment;

public:
	MRET	LoadDepartment();
	MRET	LoadDevice();
	CString	GetDatabaseTXT(CString strConnect);

// Construction
public:
	CPageGeneral();
	~CPageGeneral();

// Dialog Data
	//{{AFX_DATA(CPageGeneral)
	enum { IDD = IDD_DIALOG_GENERAL };
	CListCtrlEx	m_listDevice;
	CComboBox	m_cboDepartment;
	BOOL	m_bLogTRACK;
	BOOL	m_bLogDEBUG;
	BOOL	m_bLogERROR;
	BOOL	m_bLogMESSAGE;
	UINT	m_nCallNode;
	CString	m_strCallName;
	CString	m_strCallConsole;
	CString	m_strCallDevice;
	CString m_strCallRoom;    //20121214
	CString m_strCallRoomNode;
	CString m_strMZQueue;
	CString m_strZYQueue;
	BOOL	m_bCallPriority;
	BOOL	m_bCallOrder;
	BOOL	m_bCallCaptureReport;
	BOOL	m_bCallCapture;
	BOOL	m_bCallReport;
	BOOL	m_bPrivateSaveToFile;
	BOOL	m_bCallComplete;
	BOOL	m_bCallReset;
	UINT	m_nCallIncrement;
	BOOL	m_bCallCancel;
	BOOL	m_bCallWait;
	BOOL	m_bAfternoon;
	CString	m_strAfternoonTime;
	UINT	m_nAutoRefresh;
	BOOL	m_bCallUnready;
	BOOL	m_bCallOrderNoReport;
	BOOL    m_bCallIQueueRoom;
	BOOL    m_bCallQueuePatientKind;
	BOOL    m_bNoPopOrderCall;
	BOOL    m_bCallPre;
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
	afx_msg void OnSelchangeComboDepartment();
	afx_msg void OnDblclkListDevice(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGENERAL_H__BEBCA22C_9466_4F9B_A309_9C058756B593__INCLUDED_)
