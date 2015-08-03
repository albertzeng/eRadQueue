// eRadQueueCall.h : main header file for the ERADQUEUECALL DLL
//

#if !defined(AFX_ERADQUEUECALL_H__2DC6C133_AC80_4993_A7C5_BFAFC51D3D8C__INCLUDED_)
#define AFX_ERADQUEUECALL_H__2DC6C133_AC80_4993_A7C5_BFAFC51D3D8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "ERadQueueCall_i.h"

/////////////////////////////////////////////////////////////////////////////

#include "RunTime.h"
#include "ToolsEx.h"
#include "ListCtrlEx.h"
#include "ComboBoxCheck.h"

#include "ModuleQueueCall.h"

#include "SetSheet.h"
#include "PageGeneral.h"
#include "DlgQueue.h"

#define	ID_TIMER_QUEUE_ACTIVE	1001
#define	ID_TIMER_QUEUE_REFRESH	1002
#define ID_TIMER_QUEUE_NORMAL_HIDE   1003
#define ID_TIMER_QUEUE_HIDE   1004
#define ID_TIMER_QUEUE_SHOW   1005

#define REGISTER_LOCATION		"SOFTWARE\\RADinfo.com.cn\\eRadQueueCall\\"

#define	TXT_QUEUE_CLASS_EMERGENT	_T("º±’Ô")
#define	TXT_QUEUE_CLASS_EXCEPTIVE	_T("Ãÿ’Ô")
#define	TXT_QUEUE_CLASS_PREARRANGE	_T("‘§‘º")

/////////////////////////////////////////////////////////////////////////////
// CERadQueueCallApp
// See eRadQueueCall.cpp for the implementation of this class
//

class CERadQueueCallApp : public CWinApp
{
public:
	CERadQueueCallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CERadQueueCallApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CERadQueueCallApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERADQUEUECALL_H__2DC6C133_AC80_4993_A7C5_BFAFC51D3D8C__INCLUDED_)
