// DlgControllerMode0.h: interface for the CDlgControllerMode0 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGCONTROLLERMODE0_H__05B9B935_DA52_4063_9AFF_CF3A449FCFDD__INCLUDED_)
#define AFX_DLGCONTROLLERMODE0_H__05B9B935_DA52_4063_9AFF_CF3A449FCFDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgController.h"

class CDlgControllerMode0 : public CDlgController  
{
public:
	virtual BOOL			QueueCallManage();
public:
//	CTime   TIME;
public:
	CDlgControllerMode0();
	virtual ~CDlgControllerMode0();
};

#endif // !defined(AFX_DLGCONTROLLERMODE0_H__05B9B935_DA52_4063_9AFF_CF3A449FCFDD__INCLUDED_)
