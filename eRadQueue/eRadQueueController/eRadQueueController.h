// eRadQueueController.h : main header file for the ERADQUEUECONTROLLER application
//

#if !defined(AFX_ERADQUEUECONTROLLER_H__82D0E096_1276_4679_A14E_4CBD17F3BFB7__INCLUDED_)
#define AFX_ERADQUEUECONTROLLER_H__82D0E096_1276_4679_A14E_4CBD17F3BFB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "ERadQueueController_i.h"

/////////////////////////////////////////////////////////////////////////////

#include "RunTime.h"

#include "ModuleTextToSpeech.h"

#include "DlgController.h"
#include "DlgControllerMode0.h"
#include "DlgControllerMode1.h"
#include "DlgControllerMode2.h"
#include "DlgControllerMode3.h"
#include "DlgQueueController.h"

#define WM_TRAY_ICON					WM_USER + 1975

#define	ID_TIMER_SCROLL					1001
#define ID_TIMER_QUEUESCROLL            1002

#define	TXT_QUEUE_CLASS_EMERGENT		_T("¼±Õï")
#define	TXT_QUEUE_CLASS_PREARRANGE		_T("Ô¤Ô¼")
#define	TXT_QUEUE_CLASS_TEZHEN		    _T("ÌØÕï")


#define	TXT_QUEUE_STATUS_WAIT			_T("µÈºò")
#define	TXT_QUEUE_STATUS_EXAMINE		_T("¼ì²é")

#define TXT_QUEUE_CALL_STATUS           _T("ÒÑºô½Ð")

#define REGISTER_LOCATION				_T("SOFTWARE\\RADinfo.com.cn\\eRadQueueController\\")

#define	PRIVILEGE_ADMINISTRATION		((CRunTime::GetUser()->m_nDoctorPrivilege & (OP_ADMINISTRATION | OP_ADMINISTRATION_DEPARTMENT)) != 0)
#define	PRIVILEGE_REGISTER				((CRunTime::GetUser()->m_nDoctorPrivilege & (OP_REGISTER)) != 0)
#define	PRIVILEGE_PERFORMER				((CRunTime::GetUser()->m_nDoctorPrivilege & (OP_PERFORMER)) != 0)
#define	PRIVILEGE_PACS					((CRunTime::GetUser()->m_nDoctorPrivilege & (OP_ADMINISTRATION_PACS)) != 0)


/////////////////////////////////////////////////////////////////////////////
// CeRadQueueController:
// See eRadQueueController.cpp for the implementation of this class
//

class CeRadQueueController : public CWinApp
{
public:
	CeRadQueueController();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CeRadQueueController)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CeRadQueueController)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERADQUEUECONTROLLER_H__82D0E096_1276_4679_A14E_4CBD17F3BFB7__INCLUDED_)
