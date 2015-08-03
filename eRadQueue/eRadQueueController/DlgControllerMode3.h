// DlgControllerMode3.h: interface for the CDlgControllerMode3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGCONTROLLERMODE3_H__DC970A37_D278_42FA_B0E2_D9200D210220__INCLUDED_)
#define AFX_DLGCONTROLLERMODE3_H__DC970A37_D278_42FA_B0E2_D9200D210220__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgController.h"
#include <vector>



class CDlgControllerMode3 : public CDlgController  
{
public:
	virtual BOOL			QueueCallManage();
	virtual MRET            Load();
   	virtual BOOL            DrawQueueCall(CDC* pDC);
	virtual BOOL            ArrangeCalculate();

public:
	CTime TIME;


public:
	COBList<CQueueCall>		m_lstQueueCallStorage;
	COBList<RECT>           m_rectcolumn;


//	CFont* m_pFontColumnName;
//	CFont* m_pFontColumn;
public:
	CDlgControllerMode3();
	virtual ~CDlgControllerMode3();
};

#endif // !defined(AFX_DLGCONTROLLERMODE3_H__DC970A37_D278_42FA_B0E2_D9200D210220__INCLUDED_)
