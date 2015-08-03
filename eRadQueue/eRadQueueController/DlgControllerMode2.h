// DlgControllerMode2.h: interface for the CDlgControllerMode2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGCONTROLLERMODE2_H__279ABD97_1787_4816_B97F_172A1D2D1B2F__INCLUDED_)
#define AFX_DLGCONTROLLERMODE2_H__279ABD97_1787_4816_B97F_172A1D2D1B2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgController.h"

class CDlgControllerMode2 : public CDlgController  
{
public:
	COBList<CQueueCall>		m_lstQueueCallStorage;

public:
	virtual MRET			Load();

public:
	virtual BOOL			QueueCallManage();
	
public:
	CTime    TIME;
public:
	CDlgControllerMode2();
	virtual ~CDlgControllerMode2();
};

#endif // !defined(AFX_DLGCONTROLLERMODE2_H__279ABD97_1787_4816_B97F_172A1D2D1B2F__INCLUDED_)
