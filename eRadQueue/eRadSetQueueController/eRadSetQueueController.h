// eRadSetQueueController.h : main header file for the ERADSETQUEUECONTROLLER DLL
//

#if !defined(AFX_ERADSETQUEUECONTROLLER_H__9E939CE9_C026_4C4C_9133_B521D22D2CC1__INCLUDED_)
#define AFX_ERADSETQUEUECONTROLLER_H__9E939CE9_C026_4C4C_9133_B521D22D2CC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "ERadSetQueueController_i.h"

/////////////////////////////////////////////////////////////////////////////

#include "RunTime.h"
#include "ToolsEx.h"
#include "ListCtrlEx.h"
#include "ComboBoxCheck.h"

#include "SetSheet.h"
#include "PageGeneral.h"
#include "PageController.h"
#include "PageMode0General.h"
#include "PageMode1Report.h"
#include "PageMode2SingleQueue.h"
#include "PageVideo.h"
#include "PageVoice.h"

#define REGISTER_LOCATION		"SOFTWARE\\RADinfo.com.cn\\eRadConfiguration\\"

/////////////////////////////////////////////////////////////////////////////
// CERadSetQueueControllerApp
// See eRadSetQueueController.cpp for the implementation of this class
//

class CERadSetQueueControllerApp : public CWinApp
{
public:
	CERadSetQueueControllerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CERadSetQueueControllerApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CERadSetQueueControllerApp)
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

#endif // !defined(AFX_ERADSETQUEUECONTROLLER_H__9E939CE9_C026_4C4C_9133_B521D22D2CC1__INCLUDED_)
