#if !defined(AFX_DLGQUEUE_H__E01B355D_533A_427C_AEF4_1BA7CF369AC4__INCLUDED_)
#define AFX_DLGQUEUE_H__E01B355D_533A_427C_AEF4_1BA7CF369AC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgQueue.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgQueue dialog
static UINT WM_MEDICALREFRESH = ::RegisterWindowMessage("WM_MEDICALREFRESH");

class CDlgQueue : public CDialog
{
public:
	BOOL			m_bInitDialog;
	CString			m_strTitle;
	CSize			m_NormalSize;
	BOOL			m_bShowNormal;
	BOOL            m_bFirstRun;  //20121210
public:
	LONG			m_nQueueIndexCall;
	CStringArray	m_aQueueDevice;
	CStringArray	m_aQueueConsole;
	CALLBACK_QUEUE_CALL_PROC	m_lpcbQueueCallProc;
	CStringArray    m_aQueueRoom;
	CStringArray    m_aQueueRoomNode;

public:
	BOOL			Layout();
	BOOL			ShowQueue(BOOL bShowNormal = FALSE);
	BOOL			ChangeStatus();
	MRET			CallQueue(COleSession* pSession, LONG nQueueIndex, LONG nQueueStatus);
	MRET			CallQueueOrder(LONG nQueueCallAction);
	MRET			CallQueueSelect(LONG nQueueCallAction);
	MRET			CallQueueComplete(COleSession* pSession, LONG nQueueIndex);
	MRET			CallQueueReset(COleSession* pSession, LONG nQueueIndex);
	MRET			CallQueueUnready(COleSession* pSession, LONG nQueueIndex);
	MRET			CallQueueCancel(COleSession* pSession, LONG nQueueIndex);
	MRET			RefreshQueue(CString strFilter);
	MRET			RefreshQueue(LONG nIndex, CdboEISQueue& dboQueue);

public:
	MRET			SetQueueCallProc(CALLBACK_QUEUE_CALL_PROC lpcbQueueCallProc);
	MRET			StartQueueCall(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName);
	MRET			CloseQueueCall();
	MRET			QueueCallComplete(LONG nStudiesIndex);

// Construction
public:
	void FixMoving(UINT fwSide, LPRECT pRect);
	void DoShow();
	void DoHide();
	CDlgQueue(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgQueue)
	enum { IDD = IDD_DIALOG_QUEUE };
	CComboBoxCheck	m_cboQueueStatus;
	CComboBox       m_cboQueueRoom;    //20121214
	CComboBoxCheck  m_cboQueueSetting;
	CListCtrlEx	m_listQueue;
	BOOL	m_bAutoRefresh;
	BOOL	m_bCallWait;
	BOOL	m_bCallAllRoom;
	BOOL    m_bGeneralMode;
	int		m_nQueueCallRoom;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgQueue)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	private:
		BOOL m_isSizeChanged;    
		BOOL m_isSetTimer;     
		INT  m_edgeHeight;     
		INT  m_edgeWidth;       
		INT  m_hideMode;       
		BOOL m_hsFinished;      
		BOOL m_hiding;          
	                            
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgQueue)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDestroy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButtonCallOrder();
	afx_msg void OnButtonCallCaptureReport();
	afx_msg void OnButtonCallCapture();
	afx_msg void OnButtonCallReport();
	afx_msg void OnButtonCallRepeat();
	afx_msg void OnButtonRefresh();
	afx_msg void OnButtonCallComplete();
	afx_msg void OnButtonCallReset();
	afx_msg void OnButtonCallUnready();
	afx_msg void OnButtonCallCancel();
	afx_msg void OnClickListQueue(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListQueue(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickListQueue(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonCallPre();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGQUEUE_H__E01B355D_533A_427C_AEF4_1BA7CF369AC4__INCLUDED_)
