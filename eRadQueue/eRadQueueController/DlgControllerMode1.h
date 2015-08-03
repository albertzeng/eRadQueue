// DlgControllerMode1.h: interface for the CDlgControllerMode1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGCONTROLLERMODE1_H__6A7291EE_314F_405C_9751_B53AD5AEB798__INCLUDED_)
#define AFX_DLGCONTROLLERMODE1_H__6A7291EE_314F_405C_9751_B53AD5AEB798__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgController.h"

class CDlgControllerMode1 : public CDlgController  
{
public:
	COBList<CQueueCall>		m_lstQueueCallStorage;

public:
	virtual MRET			Load();

public:
	virtual BOOL			QueueCallManage();

public:
	CTime TIME;

public:
	CDlgControllerMode1();
	virtual ~CDlgControllerMode1();
};

#endif // !defined(AFX_DLGCONTROLLERMODE1_H__6A7291EE_314F_405C_9751_B53AD5AEB798__INCLUDED_)
