// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgProxy.h"
#include "eRadQueueControllerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueControllerDlgAutoProxy

IMPLEMENT_DYNCREATE(CeRadQueueControllerDlgAutoProxy, CCmdTarget)

CeRadQueueControllerDlgAutoProxy::CeRadQueueControllerDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CeRadQueueControllerDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CeRadQueueControllerDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CeRadQueueControllerDlgAutoProxy::~CeRadQueueControllerDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CeRadQueueControllerDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CeRadQueueControllerDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CeRadQueueControllerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CeRadQueueControllerDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CeRadQueueControllerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IERadQueueController to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {EC77BB09-1E78-4244-A274-F6D9772085DC}
static const IID IID_IERadQueueController =
{ 0xec77bb09, 0x1e78, 0x4244, { 0xa2, 0x74, 0xf6, 0xd9, 0x77, 0x20, 0x85, 0xdc } };

BEGIN_INTERFACE_MAP(CeRadQueueControllerDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CeRadQueueControllerDlgAutoProxy, IID_IERadQueueController, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {24FCB792-8383-4EB6-9205-A4ECDFF5D8FA}
IMPLEMENT_OLECREATE2(CeRadQueueControllerDlgAutoProxy, "ERadQueueController.Application", 0x24fcb792, 0x8383, 0x4eb6, 0x92, 0x5, 0xa4, 0xec, 0xdf, 0xf5, 0xd8, 0xfa)

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueControllerDlgAutoProxy message handlers
