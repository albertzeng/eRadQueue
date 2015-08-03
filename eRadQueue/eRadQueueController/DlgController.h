#if !defined(AFX_DLGCONTROLLER_H__855E870B_4ACF_4EFB_AFEA_A1D3B6D78CDB__INCLUDED_)
#define AFX_DLGCONTROLLER_H__855E870B_4ACF_4EFB_AFEA_A1D3B6D78CDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgController.h : header file
//

#include "iFly_TTS.h"


class CDlgQueueController;

/////////////////////////////////////////////////////////////////////////////
// CDlgController dialog

class CDlgController : public CDialog
{
public:
	class CQueueCall  
	{
	public:
		LONG			m_nCallIndex;
		LONG			m_nQueueIndex;
		LONG			m_nStudiesIndex;
		LONG			m_nQueueStatus;
	public:
		CString			m_strQueueDeviceAlias;
		CString			m_strQueueNumber;
		CString			m_strPatientsAlias;
		CString			m_strPatientsID;
		CString			m_strAdmissionID;
		CString			m_strAccessionNumber;
		CString			m_strExamineAlias;
		CString			m_strCallName;
		CString			m_strQueueClass;
		CString			m_strQueueStatus;
		CString         m_strQueueTs;
	    LONG            m_nCallNode;                //20111027
	public:
		CQueueCall()
		{
			this->m_nCallIndex		= 0;
			this->m_nQueueIndex		= 0;
			this->m_nStudiesIndex	= 0;
			this->m_nQueueStatus	= 0;
		}
		virtual ~CQueueCall() {}
	};

public:
	CDlgQueueController*	m_pParent;
	CRunTime::CITEMController*	m_pController;

public:
	BOOL					m_bExit;
	HANDLE					m_hExitEvent;
	BOOL                    m_bVideo;

public:
	HTTSINSTANCE        	m_hTTSInstance;

public:
	CRect					m_recTitle;
	CFont*					m_pFontTitle;

public:
	CRect					m_recScroll;
	CFont*					m_pFontScroll;
	LONG					m_nScrollOffset;
	LONG                    m_nQueueScrollOffset;

public:
	CRect					m_recQueueCall;
	CFont*					m_pFontQueueCall;
	LONG					m_nRowsHeight;
	LONG					m_nColsWidth;
	COBList<CQueueCall>		m_lstQueueCall;
	
public:
	virtual BOOL			ArrangeCalculate();
	virtual BOOL			DrawTitle(CDC* pDC);
	virtual BOOL			DrawScroll(CDC* pDC);
	virtual BOOL			DrawQueueCall(CDC* pDC);
	virtual void			DrawQueueScrollCall();
	virtual BOOL			PlayQueueCallVoice(CQueueCall* pQueueCall);

public:
	virtual BOOL			ContentReplace(CString& strQueueCall, CQueueCall* pQueueCall);
	virtual BOOL			LoadQueueCall(CQueueCall* pQueueCall, CdboEISQueue& dboQueue);
	virtual BOOL			LoadQueueCall(CQueueCall* pQueueCall, CdbovEISQueueCall& dbovQueueCall);
	virtual BOOL			LoadQueueCall(CQueueCall* pQueueCall, CdbovEISWorksLists& dbovWorklists);
	virtual CQueueCall*		FindQueueCall();
	

public:
	virtual BOOL			QueueCallManage() = 0;

protected:
	static DWORD WINAPI		TProcQueue(LPVOID lpvParameter);

// Construction
public:
	CDlgController(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgController)
	enum { IDD = IDD_DIALOG_CONTROLLER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgController)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgController)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDestroy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONTROLLER_H__855E870B_4ACF_4EFB_AFEA_A1D3B6D78CDB__INCLUDED_)
