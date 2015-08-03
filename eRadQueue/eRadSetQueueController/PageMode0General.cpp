// PageMode0General.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageMode0General.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageMode0General property page

IMPLEMENT_DYNCREATE(CPageMode0General, CPropertyPage)

CPageMode0General::CPageMode0General() : CPropertyPage(CPageMode0General::IDD)
{
	//{{AFX_DATA_INIT(CPageMode0General)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPageMode0General::~CPageMode0General()
{
}

void CPageMode0General::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageMode0General)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageMode0General, CPropertyPage)
	//{{AFX_MSG_MAP(CPageMode0General)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageMode0General message handlers
