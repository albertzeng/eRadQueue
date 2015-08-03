// SetSheet.cpp : implementation file
//

#include "stdafx.h"
#include "eRadQueueCall.h"
#include "SetSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSheet

IMPLEMENT_DYNAMIC(CSetSheet, CPropertySheet)

CSetSheet::CSetSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	this->m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetSheet::CSetSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	this->m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSetSheet::~CSetSheet()
{
}


BEGIN_MESSAGE_MAP(CSetSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSetSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSheet message handlers

BOOL CSetSheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// TODO: Add your specialized code here

	this->SetIcon(m_hIcon, TRUE);
	this->SetIcon(m_hIcon, FALSE);

	return bResult;
}
