// PageSingleQueueShowAll.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageSingleQueueShowAll.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageSingleQueueShowAll property page

IMPLEMENT_DYNCREATE(CPageSingleQueueShowAll, CPropertyPage)

CPageSingleQueueShowAll::CPageSingleQueueShowAll() : CPropertyPage(CPageSingleQueueShowAll::IDD)
{
	//{{AFX_DATA_INIT(CPageSingleQueueShowAll)
	m_MODE3ColumnRight = 0;
	m_MODE3ColumnTop = 0;
	m_MODE3QueueIndex = 0;
	m_MODE3RenovateTime = 0;
	m_MODE3ColumnRows = 0;
	m_MODE3ColumnName = _T("");
	m_MODE3ColumnLines = 0;
	m_MODE3ColumnLeft = 0;
	m_MODE3ColumnId = 0;
	m_MODE3ColumnBottom = 0;
	m_bShowHorizontal = FALSE;
	//}}AFX_DATA_INIT
	this->m_pFontColumnName		= NULL;
	this->m_pFontColumn       	= NULL;
	this->m_pColumner       	= NULL;

}

CPageSingleQueueShowAll::~CPageSingleQueueShowAll()
{
}

void CPageSingleQueueShowAll::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageSingleQueueShowAll)
	DDX_Control(pDX, IDC_LIST_MODE3_COLUMNSET, m_MODE3ListColumnSet);
	DDX_Control(pDX, IDC_LIST_MODE3_QUEUE, m_MODE3ListQueue);
	DDX_Text(pDX, IDC_MODE3_COLUMN_RIGHT, m_MODE3ColumnRight);
	DDX_Text(pDX, IDC_MODE3_COLUMN_TOP, m_MODE3ColumnTop);
	DDX_Text(pDX, IDC_EDIT_MODE3_QUEUEINDEX, m_MODE3QueueIndex);
	DDX_Text(pDX, IDC_EDIT_MODE3_RENOVATETIME, m_MODE3RenovateTime);
	DDX_Text(pDX, IDC_MODE3_COLUMN_ROWS, m_MODE3ColumnRows);
	DDX_Text(pDX, IDC_MODE3_COLUMN_NAME, m_MODE3ColumnName);
	DDX_Text(pDX, IDC_MODE3_COLUMN_LINES, m_MODE3ColumnLines);
	DDX_Text(pDX, IDC_MODE3_COLUMN_LEFT, m_MODE3ColumnLeft);
	DDX_Text(pDX, IDC_MODE3_COLUMN_ID, m_MODE3ColumnId);
	DDX_Text(pDX, IDC_MODE3_COLUMN_BOTTOM, m_MODE3ColumnBottom);
	DDX_Check(pDX, IDC_CHECK_BShowHorizontal, m_bShowHorizontal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageSingleQueueShowAll, CPropertyPage)
	//{{AFX_MSG_MAP(CPageSingleQueueShowAll)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_ADD, OnButtonMODE3Add)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_CHANGE, OnButtonMODE3Change)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_COLUME_NAME_FTCOLOR, OnButtonMODE3ColumnNameFtcolor)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_COLUMN_NAME_BKCOLOR, OnButtonMODE3ColumnNameBkcolor)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_COLUMN_NAME_FONT, OnButtonMODE3ColumnNameFont)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_COLUMN_FONT, OnButtonMODE3ColumnFont)
	ON_BN_CLICKED(IDC_BUTTON_MODE3_COLUMN_BKCOLOR, OnButtonMODE3ColumnBkcolor)
    ON_BN_CLICKED(IDC_BUTTON_MODE3_DELETE, OnButtonMODE3Delete)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_MODE3_QUEUE, OnDblclkListMODE3Queue)
	ON_WM_CANCELMODE()
	ON_NOTIFY(NM_CLICK, IDC_LIST_MODE3_COLUMNSET, OnClickListMode3Columnset)
	ON_WM_CTLCOLOR()
	ON_WM_CAPTURECHANGED()
	ON_BN_CLICKED(IDC_BUTTON_MODE3_COLUMN_FTCOLOR, OnButtonMode3ColumnFtcolor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageSingleQueueShowAll message handlers

void CPageSingleQueueShowAll::OnButtonMODE3Add() 
{
	// TODO: Add your control notification handler code here
	
	if (!this->UpdateData())
		return;
	CRunTime::CITEMColumn* pcolumn = new CRunTime::CITEMColumn;
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnId,pcolumn->m_MODE3ColumnId);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnName,pcolumn->m_MODE3ColumnName);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnTop,pcolumn->m_MODE3ColumnTop);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnLeft,pcolumn->m_MODE3ColumnLeft);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnRight,pcolumn->m_MODE3ColumnRight);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnBottom,pcolumn->m_MODE3ColumnBottom);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnRows,pcolumn->m_MODE3ColumnRows);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnLines,pcolumn->m_MODE3ColumnLines);

	SET_RIGHT_FROM_LEFT(this->m_strColumnFontName,			pcolumn->m_strColumnFontName);
	SET_RIGHT_FROM_LEFT(this->m_nColumnFontSize,			pcolumn->m_nColumnFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnBackground,		pcolumn->m_clrColumnBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnForeground,		pcolumn->m_clrColumnForeground);
	
	SET_RIGHT_FROM_LEFT(this->m_strColumnNameFontName,		pcolumn->m_strColumnNameFontName);
	SET_RIGHT_FROM_LEFT(this->m_nColumnNameFontSize,		pcolumn->m_nColumnNameFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnNameBackground,	pcolumn->m_clrColumnNameBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnNameForeground,	pcolumn->m_clrColumnNameForeground);

	this->m_pController->m_lstColumn.AddTail(pcolumn);
	LONG nIndex = this->m_MODE3ListColumnSet.InsertItem(0, _T(""));
	
	this->RefreshColumnSet(nIndex, pcolumn);

}


void CPageSingleQueueShowAll::RefreshColumnSet(LONG nIndex, CRunTime::CITEMColumn* pColumn)
{
	this->m_MODE3ListColumnSet.SetItemText(nIndex, 0, pColumn->m_MODE3ColumnId);
	this->m_MODE3ListColumnSet.SetItemText(nIndex, 1, pColumn->m_MODE3ColumnName);
	
	this->m_MODE3ListColumnSet.SetItemData(nIndex, (DWORD) (LPVOID) pColumn);
}


void CPageSingleQueueShowAll::OnButtonMODE3Change() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (this->m_pColumner== NULL)
	{
		SET_RIGHT_FROM_LEFT(this->m_MODE3QueueIndex,			this->m_pController->m_MODE3QueueIndex);
    	SET_RIGHT_FROM_LEFT(this->m_MODE3RenovateTime,		    this->m_pController->m_MODE3RenovateTime);
		return;
	}

	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnRight,			this->m_pColumner->m_MODE3ColumnRight);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnTop,				this->m_pColumner->m_MODE3ColumnTop);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnRows,			this->m_pColumner->m_MODE3ColumnRows);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnName,			this->m_pColumner->m_MODE3ColumnName);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnLines,			this->m_pColumner->m_MODE3ColumnLines);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnLeft,			this->m_pColumner->m_MODE3ColumnLeft);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnId,				this->m_pColumner->m_MODE3ColumnId);
	SET_RIGHT_FROM_LEFT(this->m_MODE3ColumnBottom,			this->m_pColumner->m_MODE3ColumnBottom);

	SET_RIGHT_FROM_LEFT(this->m_strColumnFontName,			this->m_pColumner->m_strColumnFontName);
	SET_RIGHT_FROM_LEFT(this->m_nColumnFontSize,			this->m_pColumner->m_nColumnFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnBackground,			this->m_pColumner->m_clrColumnBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnForeground,			this->m_pColumner->m_clrColumnForeground);
	
	SET_RIGHT_FROM_LEFT(this->m_strColumnNameFontName,			this->m_pColumner->m_strColumnNameFontName);
	SET_RIGHT_FROM_LEFT(this->m_nColumnNameFontSize,			this->m_pColumner->m_nColumnNameFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnNameBackground,			this->m_pColumner->m_clrColumnNameBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrColumnNameForeground,			this->m_pColumner->m_clrColumnNameForeground);

	OBPOS POS = NULL;

	LVFINDINFO lvFindInfo;
	lvFindInfo.flags = LVFI_PARAM;
	lvFindInfo.lParam = (DWORD) (LPVOID) this->m_pColumner;
	
	LONG nIndex = this->m_MODE3ListColumnSet.FindItem(&lvFindInfo);
	
	if (nIndex != -1) this->RefreshColumnSet(nIndex, this->m_pColumner);
	
	this->UpdateData();

}

void CPageSingleQueueShowAll::OnButtonMODE3ColumnNameFtcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlgColor(this->m_clrColumnNameForeground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrColumnNameForeground = dlgColor.GetColor();
		
			this->ShowPreview();
	}
}

void CPageSingleQueueShowAll::OnButtonMODE3ColumnFont() 
{
	// TODO: Add your control notification handler code here
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_strColumnFontName);
	lf.lfHeight = this->m_nColumnFontSize;
	
	CFontDialog dlgFont(&lf, CF_EFFECTS | CF_SCREENFONTS, NULL, this);
	if (dlgFont.DoModal() == IDOK)
	{
		dlgFont.GetCurrentFont(&lf);
		this->m_strColumnFontName = lf.lfFaceName;
		this->m_nColumnFontSize = lf.lfHeight;
		
		this->ShowPreview();
	}
}

void CPageSingleQueueShowAll::OnButtonMODE3ColumnBkcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlgColor(this->m_clrColumnBackground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrColumnBackground = dlgColor.GetColor();
		
			this->ShowPreview();
	}
	
}

void CPageSingleQueueShowAll::OnButtonMODE3ColumnNameBkcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlgColor(this->m_clrColumnNameBackground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrColumnNameBackground = dlgColor.GetColor();
		
		this->ShowPreview();
	}
	
}

void CPageSingleQueueShowAll::OnButtonMODE3ColumnNameFont() 
{
	// TODO: Add your control notification handler code here
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_strColumnNameFontName);
	lf.lfHeight = this->m_nColumnNameFontSize;
	
	CFontDialog dlgFont(&lf, CF_EFFECTS | CF_SCREENFONTS, NULL, this);
	if (dlgFont.DoModal() == IDOK)
	{
		dlgFont.GetCurrentFont(&lf);
		this->m_strColumnNameFontName = lf.lfFaceName;
		this->m_nColumnNameFontSize = lf.lfHeight;
		
		this->ShowPreview();
	}
}

void CPageSingleQueueShowAll::OnButtonMODE3Delete() 
{
	// TODO: Add your control notification handler code here
	if (this->m_pColumner != NULL)
	{
		OBPOS POS = NULL;
		for (CRunTime::CITEMColumn* IT = this->m_pController->m_lstColumn.GetHead(POS);IT !=NULL;IT = this->m_pController->m_lstColumn.GetNext(POS))
		{
			if (IT == this->m_pColumner)
			{
                delete this->m_pController->m_lstColumn.Remove(POS);
				LVFINDINFO lvFindInfo;
				lvFindInfo.flags = LVFI_PARAM;
				lvFindInfo.lParam = (DWORD) (LPVOID) this->m_pColumner;
				
				LONG nIndex = this->m_MODE3ListColumnSet.FindItem(&lvFindInfo);
				if (nIndex != -1) this->m_MODE3ListColumnSet.DeleteItem(nIndex);
				
			}
		}
}
	
}


void CPageSingleQueueShowAll::OnDblclkListMODE3Queue(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	this->UpdateData();
	
	LONG nIndex = this->m_MODE3ListQueue.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex != -1)
		this->m_MODE3QueueIndex= this->m_MODE3ListQueue.GetItemData(nIndex);
	
	this->UpdateData(FALSE);
	
	*pResult = 0;
}

BOOL CPageSingleQueueShowAll::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

// TODO: Add extra initialization here

this->m_MODE3ListQueue.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
this->m_MODE3ListQueue.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
this->m_MODE3ListQueue.LoadSave(_T("eRadConfiguration.eRadSetQueueController.DeviceMode3"), FALSE, _T(""), REGISTER_LOCATION);

BEGIN_LISTCOLUMNMAP(m_MODE3ListQueue, 2)
LISTCOLUMNMAP(IDS_DEVICE_INDEX,		100,		LVCFMT_LEFT,	ELCT_INTEGER)
LISTCOLUMNMAP(IDS_DEVICE_NAME,		200,		LVCFMT_LEFT,	ELCT_STRING_CASE)
END_LISTCOLUMNMAP()


this->m_MODE3ListColumnSet.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
this->m_MODE3ListColumnSet.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
this->m_MODE3ListColumnSet.LoadSave(_T("eRadConfiguration.eRadSetQueueController.MODE3ListColumnSet"), FALSE, _T(""), REGISTER_LOCATION);

BEGIN_LISTCOLUMNMAP(m_MODE3ListColumnSet, 2)
LISTCOLUMNMAP(IDS_COLUMNID,	        100,		LVCFMT_LEFT,	ELCT_INTEGER)
LISTCOLUMNMAP(IDS_COLUMNNAME,		200,		LVCFMT_LEFT,	ELCT_STRING_CASE)
END_LISTCOLUMNMAP()

MRET rc = this->LoadDevice();
if (rc != ME_OK)
{
	LOG_ERROR(LL_ERROR | LD_ALL, rc);
}

this->m_MODE3ListColumnSet.DeleteAllItems();
OBPOS POS = NULL;
for (CRunTime::CITEMColumn* IT = this->m_pController->m_lstColumn.GetHead(POS); IT != NULL; IT = this->m_pController->m_lstColumn.GetNext(POS))
{
	
	LONG nIndex = this->m_MODE3ListColumnSet.InsertItem(0, _T(""));
	
	this->RefreshColumnSet(nIndex, IT);
}

this->m_MODE3ListColumnSet.SortListCtrl();

this->Initialize();



return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPageSingleQueueShowAll::OnCancelMode() 
{
	CPropertyPage::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

MRET CPageSingleQueueShowAll::LoadDevice()
{
	this->m_MODE3ListQueue.DeleteAllItems();
	
	if (!CRunTime::GetGeneral()->m_strEISDatabase.IsEmpty())
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
		}
		
		CString strFilter;
		strFilter.Format(_T("WHERE DeviceDepartment = %d"), CRunTime::GetGeneral()->m_nUseDepartment);
		
		CdboMGRDevice dboDevice;
		dboDevice.SetDataSource(pSession);
		if (FAILED(dboDevice.Open(strFilter)))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		}
		
		LONG nIndex = 0;
		while (dboDevice.MoveNext() == S_OK)
		{
			nIndex = this->m_MODE3ListQueue.InsertItem(0,		_T(""));
			this->m_MODE3ListQueue.SetItemText(nIndex, 0,		dboDevice.m_DeviceIndex);
			this->m_MODE3ListQueue.SetItemText(nIndex, 1,		dboDevice.m_DeviceName);
			
			this->m_MODE3ListQueue.SetItemData(nIndex++, dboDevice.m_DeviceIndex);
		}
		
		dboDevice.Close();
	}
	
	return ME_OK;
}


void CPageSingleQueueShowAll::OnClickListMode3Columnset(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LONG nIndex = this->m_MODE3ListColumnSet.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex == -1)
		return;
	this->m_pColumner = (CRunTime::CITEMColumn*) this->m_MODE3ListColumnSet.GetItemData(nIndex);
	

	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnRight,			this->m_pColumner->m_MODE3ColumnRight);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnTop,				this->m_pColumner->m_MODE3ColumnTop);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnRows,			this->m_pColumner->m_MODE3ColumnRows);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnName,			this->m_pColumner->m_MODE3ColumnName);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnLines,			this->m_pColumner->m_MODE3ColumnLines);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnLeft,			this->m_pColumner->m_MODE3ColumnLeft);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnId,				this->m_pColumner->m_MODE3ColumnId);
	SET_LEFT_FROM_RIGHT(this->m_MODE3ColumnBottom,			this->m_pColumner->m_MODE3ColumnBottom);

	SET_LEFT_FROM_RIGHT(this->m_strColumnFontName,			this->m_pColumner->m_strColumnFontName);
	SET_LEFT_FROM_RIGHT(this->m_nColumnFontSize,			this->m_pColumner->m_nColumnFontSize);
	SET_LEFT_FROM_RIGHT(this->m_clrColumnBackground,			this->m_pColumner->m_clrColumnBackground);
	SET_LEFT_FROM_RIGHT(this->m_clrColumnForeground,			this->m_pColumner->m_clrColumnForeground);

	SET_LEFT_FROM_RIGHT(this->m_strColumnNameFontName,			this->m_pColumner->m_strColumnNameFontName);
	SET_LEFT_FROM_RIGHT(this->m_nColumnNameFontSize,			this->m_pColumner->m_nColumnNameFontSize);
	SET_LEFT_FROM_RIGHT(this->m_clrColumnNameBackground,			this->m_pColumner->m_clrColumnNameBackground);
	SET_LEFT_FROM_RIGHT(this->m_clrColumnNameForeground,			this->m_pColumner->m_clrColumnNameForeground);
	

	this->UpdateData(FALSE);
    this->ShowPreview();
	*pResult = 0;
}

BOOL CPageSingleQueueShowAll::ShowPreview()
{
	this->m_brushColumnName = CreateSolidBrush(this->m_clrColumnNameBackground);
	
	if (this->m_pFontColumnName != NULL)
		delete this->m_pFontColumnName;
	this->m_pFontColumnName = new CFont;
	LOGFONT lf1;
	memset(&lf1, 0, sizeof(LOGFONT));
	strcpy(lf1.lfFaceName, this->m_strColumnNameFontName);
	lf1.lfHeight = this->m_nColumnNameFontSize;
	this->m_pFontColumnName->CreateFontIndirect(&lf1);
	this->GetDlgItem(IDC_MODE3_COLUMN_NAME_DEMO)->SetFont(this->m_pFontColumnName);
	this->GetDlgItem(IDC_MODE3_COLUMN_NAME_DEMO)->Invalidate();
	
	this->m_brushColumn = CreateSolidBrush(this->m_clrColumnBackground);
	
	if (this->m_pFontColumn!= NULL)
		delete this->m_pFontColumn;
	this->m_pFontColumn = new CFont;
	LOGFONT lf2;
	memset(&lf2, 0, sizeof(LOGFONT));
	strcpy(lf2.lfFaceName, this->m_strColumnFontName);
	lf2.lfHeight = this->m_nColumnFontSize;
	this->m_pFontColumn->CreateFontIndirect(&lf2);
	this->GetDlgItem(IDC_MODE3_COLUMN_DEMO)->SetFont(this->m_pFontColumn);
	this->GetDlgItem(IDC_MODE3_COLUMN_DEMO)->Invalidate();
	
	
	return TRUE;
}

BOOL CPageSingleQueueShowAll::Initialize()
{
	LOGFONT lf;
	this->GetFont()->GetLogFont(&lf);

	this->m_strColumnFontName = lf.lfFaceName;
	this->m_nColumnFontSize = lf.lfHeight;
	this->m_clrColumnForeground = RGB(0, 0, 255);
	this->m_clrColumnBackground = RGB(0, 0, 0);

	this->m_strColumnNameFontName= lf.lfFaceName;
	this->m_nColumnNameFontSize= lf.lfHeight;
	this->m_clrColumnNameForeground = RGB(0, 0, 255);
	this->m_clrColumnNameBackground = RGB(0, 0, 0);


	this->m_MODE3ColumnRight = 0;
	this->m_MODE3ColumnTop= 0;
	this->m_MODE3ColumnRows = 1;
	this->m_MODE3ColumnName = _T("");
	this->m_MODE3ColumnLines = 1;
	this->m_MODE3ColumnLeft = 0;
	this->m_MODE3ColumnId = 0;
	this->m_MODE3ColumnBottom = 0;
	
	this->UpdateData(FALSE);
	
	this->ShowPreview();
	
	return TRUE;
}


HBRUSH CPageSingleQueueShowAll::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_MODE3_COLUMN_NAME_DEMO:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(this->m_clrColumnNameBackground);
		pDC->SetTextColor(m_clrColumnNameForeground);
		return this->m_brushColumnName;
	case IDC_MODE3_COLUMN_DEMO:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(this->m_clrColumnBackground);
		pDC->SetTextColor(this->m_clrColumnForeground);
		return this->m_brushColumn;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CPageSingleQueueShowAll::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CPropertyPage::OnCaptureChanged(pWnd);
}

void CPageSingleQueueShowAll::OnButtonMode3ColumnFtcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlgColor(this->m_clrColumnForeground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrColumnForeground = dlgColor.GetColor();
		
		this->ShowPreview();
	}
	
}

//////////////////////////////////////////////////////////////////////
// CPageMode3SingleQueueList Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

