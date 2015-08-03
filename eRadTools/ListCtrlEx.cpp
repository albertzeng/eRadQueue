// ListCtrlEx.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrlEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlEx

UINT CListCtrlEx::s_nIdentifier = 0;

CListCtrlEx::CListCtrlEx()
{
	m_bHideColumn = TRUE;
	m_bSaveToFile = FALSE;
	m_strName = "ListCtrlEx";
	m_strSubKey = _T("SOFTWARE\\RADinfo.com.cn\\ListCtrlEx\\ListCtrlEx\\");
	m_strFileName = "10000.ini";

	s_nIdentifier++;
	m_nIdentifier = s_nIdentifier;

	m_nSortColumn = 1;

	m_pOrderArray = NULL;
	m_pColumnMap = NULL;
	m_pColumnArray = NULL;
	
	BYTE ANDmaskIcon1[] = {
		0xE7, 0xFF,
		0xE7, 0xFF,
		0xC3, 0xFF,
		0xDB, 0xFF,
		0x99, 0xFF,
		0xBD, 0xFF,
		0x3C, 0xFF,
		0x00, 0xFF,
	};

	BYTE XORmaskIcon1[] = {
		0x08, 0x00,
		0x08, 0x00,
		0x0C, 0x00,
		0x04, 0x00,
		0x06, 0x00,
		0x02, 0x00,
		0x03, 0x00,
		0xFF, 0x00,
	};
	
	BYTE ANDmaskIcon2[] = {
		0x00, 0xFF,
		0x3C, 0xFF,
		0xBD, 0xFF,
		0x99, 0xFF,
		0xDB, 0xFF,
		0xC3, 0xFF,
		0xE7, 0xFF,
		0xE7, 0xFF,
	};
	
	BYTE XORmaskIcon2[] = {
		0x00, 0x00,
		0x03, 0x00,
		0x02, 0x00,
		0x06, 0x00,
		0x04, 0x00,
		0x0C, 0x00,
		0x08, 0x00,
		0x08, 0x00,
	};

	this->m_hIcon1 = ::CreateIcon(
		NULL, // application instance 
		8, // icon width 
		8, // icon height 
		1, // number of XOR planes 
		1, // number of bits per pixel 
		ANDmaskIcon1, // AND bitmask 
		XORmaskIcon1); // XOR bitmask 
	
	this->m_hIcon2 = ::CreateIcon(
		NULL, // application instance 
		8, // icon width 
		8, // icon height 
		1, // number of XOR planes 
		1, // number of bits per pixel 
		ANDmaskIcon2, // AND bitmask 
		XORmaskIcon2); // XOR bitmask 
	
	for (int i=0; i < 20; i++)
		this->m_aColor[i] = RGB(255, 255, 255);
	
	this->m_bUseFont = FALSE;
	this->m_hFont.CreateFont(-18,0,0,0,FW_NORMAL,0,0,0,0,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_ROMAN,"宋体");
}

CListCtrlEx::~CListCtrlEx()
{
	if (m_pOrderArray != NULL)
		free(m_pOrderArray);
	if (m_pColumnMap != NULL)
		free(m_pColumnMap);
	if (m_pColumnArray != NULL)
		free(m_pColumnArray);
}


BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)
	//{{AFX_MSG_MAP(CListCtrlEx)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnClick)
	ON_WM_DESTROY()
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)	
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_LIST_COLUMN_BASE, ID_LIST_COLUMN_BASE + 100, OnMenuListColumn)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlEx message handlers

BOOL CListCtrlEx::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (wParam==0 && ( (NMHDR*) lParam)->code == NM_RCLICK)
	{
		OnNotifyNmRClick();
	}

	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

void CListCtrlEx::OnColumnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	LVCOLUMN column;
	column.mask = LVCF_WIDTH | LVCF_ORDER | LVCF_SUBITEM;
	this->GetColumn(pNMListView->iSubItem, &column);
	int nSortColumn = column.iSubItem + 1;
	if (abs(this->m_nSortColumn) == nSortColumn)
		this->m_nSortColumn = - this->m_nSortColumn;
	else
		this->m_nSortColumn = nSortColumn;

	QuickSort(this->m_nSortColumn);
	
	*pResult = 0;
}

void CListCtrlEx::OnDestroy() 
{
	this->RefreshColumn();
	this->UpdateRegistry(TRUE);

	CListCtrl::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CListCtrlEx::OnNotifyNmRClick()
{
	CMenu theMenu;
	theMenu.CreatePopupMenu();

	UINT nFlags;
	for (int i = 0; i < this->m_nColumnCount; i++)
	{
		nFlags = 0;
		if (i == 0)
			nFlags |= MF_DISABLED | MF_GRAYED;
		else
			nFlags |= MF_ENABLED;
		if (this->m_pColumnArray[i].iOrder > 0)
			nFlags |= MF_CHECKED;

		theMenu.AppendMenu(nFlags, ID_LIST_COLUMN_BASE + i, this->m_pColumnArray[i].name);
	}

	POINT curPos;
	::GetCursorPos(&curPos);
	theMenu.TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON, 
						   curPos.x, curPos.y, 
						   this, NULL);
}

void CListCtrlEx::CreateArrowList()
{
	CWinApp *theApp = AfxGetApp();
	this->m_nArrowList.Create(8, 8, ILC_MASK, 2, 0);

	this->m_nArrowList.Add(this->m_hIcon1);
	this->m_nArrowList.Add(this->m_hIcon2);

	if (this->m_bUseFont) this->SetFont(&this->m_hFont);
}

void CListCtrlEx::OnMenuListColumn(UINT nID)
{
	if (this->m_bHideColumn)
	{
		int nColumn;
		nColumn = nID - ID_LIST_COLUMN_BASE;

		if (nColumn > this->m_nColumnCount || nColumn < 0)
			return;

		if (this->m_pColumnArray[nColumn].iOrder > 0)
		{
			int nColumnCount = this->GetColumnCount();

			LVCOLUMN column;
			column.mask = LVCF_WIDTH | LVCF_ORDER | LVCF_SUBITEM;
			for (int i = 0; i < nColumnCount; i++)
			{
				this->GetColumn(i, &column);
				if (column.iSubItem == nColumn)
				{
					this->DeleteColumn(i);
					this->m_pColumnArray[nColumn].iOrder = 0;
					break;
				}
			}

			this->RefreshColumn();
		}
		else
		{
			this->InsertColumn(this->m_pColumnArray[nColumn].index,
							   this->m_pColumnArray[nColumn].name,
							   this->m_pColumnArray[nColumn].fmt,
							   this->m_pColumnArray[nColumn].cx,
							   nColumn);

			this->RefreshColumn();
			this->RefreshList();
		}
	}
}

BOOL CListCtrlEx::UpdateRegistry(BOOL bReadWrite)	//TRUE: Write, FALSE: Read
{
	LONG lRet = ERROR_SUCCESS;
	HKEY hKey = NULL;
	CString strValue, strBuffer;

	if (bReadWrite)	//Write
	{
		//Format: "Sort;iOrder cx;iOrder cx;......"
		strValue.Format("%d;", this->m_nSortColumn);

		for (int i = 0; i < this->m_nColumnCount; i++)
		{
			strBuffer.Format("%d %d;", 
							 this->m_pColumnArray[i].iOrder, 
							 this->m_pColumnArray[i].cx);
			strValue += strBuffer;
		}
	}

	if (!this->m_bSaveToFile)
	{
		lRet = RegOpenKeyEx(HKEY_CURRENT_USER, 
							m_strSubKey, 
							NULL, 
							KEY_ALL_ACCESS, 
							&hKey);
		if (lRet != ERROR_SUCCESS)
		{
			DWORD dwDisposition = 0;
			
			lRet = RegCreateKeyEx(HKEY_CURRENT_USER, 
								  m_strSubKey, 
								  NULL, 
								  NULL, 
								  0, 
								  KEY_ALL_ACCESS, 
								  NULL, 
								  &hKey, 
								  &dwDisposition);
			if (lRet != ERROR_SUCCESS)
				return FALSE;
		}
		
		if (bReadWrite)	//Write
		{
			lRet = RegSetValueEx(hKey, 
								 m_strName, 
								 NULL, 
								 REG_SZ, 
								 (CONST BYTE *) (LPCTSTR) strValue, 
								 strValue.GetLength() + 1);
		}
		else	//Read
		{
			DWORD dwType = -1;
			DWORD dwSize = -1;

			lRet = RegQueryValueEx(hKey, 
								   m_strName, 
								   NULL, 
								   &dwType, 
								   NULL, 
								   &dwSize);
			if (lRet == ERROR_SUCCESS && dwType == REG_SZ)
			{
				UCHAR *pszData = new UCHAR[dwSize];
				
				lRet = RegQueryValueEx(hKey, 
									   m_strName, 
									   NULL, 
									   &dwType, 
									   pszData, 
									   &dwSize);
				if (lRet == ERROR_SUCCESS && dwType == REG_SZ)
				{
					strValue = pszData;
					delete pszData;
				}
				else
				{
					delete pszData;
					RegCloseKey(hKey);
					return FALSE;
				}
			}
		}

		RegCloseKey(hKey);
	}
	else
	{
		if (bReadWrite)	//Write
		{
			::WritePrivateProfileString("ListCtrlEx", this->m_strName, strValue, this->m_strFileName);
		}
		else
		{
			char lpBuffer[1024];
			lRet = ::GetPrivateProfileString("ListCtrlEx", this->m_strName, "", lpBuffer, sizeof(lpBuffer), this->m_strFileName);
			if (lRet > 0) strValue = lpBuffer;
		}
	}

	if (!bReadWrite)	//Read
	{
		if (strValue.IsEmpty())
			return FALSE;

		int nStart = 0, nEnd = 0, nRead = 0;
		int nSort, iOrder, cx;

		nEnd = strValue.Find(";");
		if (nEnd == -1)
			return FALSE;
		strBuffer = strValue.Mid(nStart, nEnd - nStart);
		nStart = nEnd + 1;
		nRead = sscanf(strBuffer, "%d", &nSort);
		if (nRead == 1 && nSort != 0 && abs(nSort) <= this->m_nColumnCount)
			this->m_nSortColumn = nSort;
		else 
			return FALSE;

		int *pBuffer = new int[this->m_nColumnCount * 2];
		for (int i = 0; i < this->m_nColumnCount; i++)
		{
			nEnd = strValue.Find(";", nStart);
			if (nEnd == -1)
			{
				delete pBuffer;
				return FALSE;
			}
			strBuffer = strValue.Mid(nStart, nEnd - nStart);
			nStart = nEnd + 1;
			nRead = sscanf(strBuffer, "%d %d", &iOrder, &cx);
			if (nRead == 2 && iOrder >=0 && iOrder <= this->m_nColumnCount && cx >=0)
			{
				pBuffer[i*2] = iOrder;
				pBuffer[i*2 + 1] = cx;
			}
			else 
			{
				delete pBuffer;
				return FALSE;
			}
		}

		for (i = 0; i < this->m_nColumnCount; i++)
		{
			this->m_pColumnArray[i].iOrder = pBuffer[i*2];
			this->m_pColumnArray[i].cx = (pBuffer[i*2 + 1] < 10) ? 3 : pBuffer[i*2 + 1];
		}
		
		delete pBuffer;
	}

	return TRUE;
}

int CListCtrlEx::GetColumnCount()
{
	CHeaderCtrl* pHeaderCtrl = GetHeaderCtrl();
    if(pHeaderCtrl!=NULL) 
		return pHeaderCtrl->GetItemCount();
	else
		return 0;
}

int CListCtrlEx::GetColumnOrder(int nSubItem)
{
	if (nSubItem < 0 || nSubItem >= this->GetColumnCount())
		return -1;

	LVCOLUMN column;
	column.mask = LVCF_WIDTH | LVCF_ORDER | LVCF_SUBITEM;

	this->GetColumn(nSubItem, &column);

	return (column.iOrder);
}

BOOL CListCtrlEx::RefreshColumn()
{
	for (int i = 0; i < this->m_nColumnCount; i++)
		this->m_pColumnMap[i] = 0;

	int nColumnCount = this->GetColumnCount();

	LVCOLUMN column;
	column.mask = LVCF_WIDTH | LVCF_ORDER | LVCF_SUBITEM;
	for (i = 0; i < nColumnCount; i++)
	{
		this->GetColumn(i, &column);
		this->m_pColumnArray[column.iSubItem].iOrder = column.iOrder + 1;
		this->m_pColumnArray[column.iSubItem].cx = column.cx;

		this->m_pColumnMap[column.iSubItem] = i + 1;
	}
	
	int index = 0;
	for (i = 0; i < this->m_nColumnCount; i++)
	{
		if (this->m_pColumnArray[i].iOrder > 0)
		{
			//this->m_pColumnMap[i] = index + 1;
			this->m_pOrderArray[index] = this->m_pColumnArray[i].iOrder - 1;
			index++;
		}
	}

	return TRUE;
}

BOOL CListCtrlEx::RefreshList()
{
	this->DeleteAllItems();

	CWnd *pWnd = GetParent();
	if (pWnd != NULL)
		pWnd->SendMessage(WM_REFRESH_LIST_MESSAGE, m_nIdentifier);

	return TRUE;
}

BOOL CListCtrlEx::SetItemText(int nItem, int nSubItem, LPCTSTR lpszText)
{
	if (nSubItem < this->m_nColumnCount && this->m_pColumnMap[nSubItem] > 0)
		CListCtrl::SetItemText(nItem, this->m_pColumnMap[nSubItem] - 1, lpszText);
	return TRUE;
}

BOOL CListCtrlEx::SetItemText(int nItem, int nSubItem, long nValue)
{
	CString strBuffer;
	strBuffer.Format("%d", nValue);

	if (nSubItem < this->m_nColumnCount && this->m_pColumnMap[nSubItem] > 0)
		CListCtrl::SetItemText(nItem, this->m_pColumnMap[nSubItem] - 1, strBuffer);
	return TRUE;
}

void CListCtrlEx::SortListCtrl()
{
	if (this->m_pColumnMap[abs(this->m_nSortColumn) - 1] > 0)
		QuickSort(this->m_nSortColumn);
}

void CListCtrlEx::SortListCtrlNone()
{
	if (this->m_pColumnMap[abs(this->m_nSortColumn) - 1] > 0)
	{
		CHeaderCtrl* pHeaderCtrl = GetHeaderCtrl();
		pHeaderCtrl->SetImageList(&this->m_nArrowList);

		HDITEM hdrItem;
		int nColumns = pHeaderCtrl->GetItemCount();
		for (int index = 0; index < nColumns; index++)
		{
			hdrItem.mask = HDI_FORMAT | HDI_IMAGE | HDI_LPARAM;
			pHeaderCtrl->GetItem(index, &hdrItem);

			hdrItem.fmt = hdrItem.fmt & HDF_JUSTIFYMASK | HDF_STRING;
			pHeaderCtrl->SetItem(index, &hdrItem);
		}
	}
}

void CListCtrlEx::QuickSort(int nSortColumn)
{
	if (this->m_pColumnMap[abs(nSortColumn) - 1] > 0)
	{
		this->m_nSortColumn = nSortColumn;
		this->m_nCompareType = this->m_pColumnArray[abs(nSortColumn) - 1].compare;
	}
	else
		return;

	QuickSort(0, GetItemCount()-1);

	CHeaderCtrl* pHeaderCtrl = GetHeaderCtrl();
	pHeaderCtrl->SetImageList(&this->m_nArrowList);

	HDITEM hdrItem;
	int nColumns = pHeaderCtrl->GetItemCount();
	for (int index = 0; index < nColumns; index++)
	{
		hdrItem.mask = HDI_FORMAT | HDI_IMAGE | HDI_LPARAM;
		pHeaderCtrl->GetItem(index, &hdrItem);
		if (abs(this->m_nSortColumn) - 1 ==  hdrItem.lParam && this->m_nSortColumn > 0)
		{
			hdrItem.iImage = 0;
			hdrItem.fmt = hdrItem.fmt & HDF_JUSTIFYMASK | HDF_IMAGE | HDF_STRING | HDF_BITMAP_ON_RIGHT;
		}
		else if (abs(this->m_nSortColumn) - 1 == hdrItem.lParam && this->m_nSortColumn < 0)
		{
			hdrItem.iImage = 1;
			hdrItem.fmt = hdrItem.fmt & HDF_JUSTIFYMASK | HDF_IMAGE | HDF_STRING | HDF_BITMAP_ON_RIGHT;
		}
		else
			hdrItem.fmt = hdrItem.fmt & HDF_JUSTIFYMASK | HDF_STRING;

		pHeaderCtrl->SetItem(index, &hdrItem);
	}
}

void CListCtrlEx::QuickSort(int nFirst, int nLast)
{
	if (nFirst < nLast)
	{
		int nMiddle = Partition(nFirst, nLast);
		QuickSort(nFirst, nMiddle);
		QuickSort(nMiddle + 1, nLast);
	}
}

int CListCtrlEx::Partition(int nFirst, int nLast)
{
	CString strThis, strMiddle;

	int nColumn = this->m_pColumnMap[abs(this->m_nSortColumn) - 1] - 1;

	int nLow = nFirst - 1;
	int nHigh = nLast + 1;
	strMiddle = GetItemText(nFirst, nColumn);

	while (nLow < nHigh)
	{
		do
		{
			nHigh--;
			strThis = GetItemText(nHigh, nColumn);
		} while (CompareBy(strThis, strMiddle));

		do
		{
			nLow++;
			strThis = GetItemText(nLow, nColumn);
		} while (CompareBy(strMiddle, strThis));

		if (nLow < nHigh)
			SwapRow(nLow, nHigh);
	}

	return nHigh;
}

BOOL CListCtrlEx::SwapRow(int nRow1, int nRow2)
{
	BOOL bOk = FALSE;

	int nMaxRows = GetItemCount();

	if ( (nRow1 >= 0) && (nRow1 < nMaxRows) && (nRow2 >= 0) && (nRow2 < nMaxRows) && (nRow1 != nRow2) )
	{
		int nMaxColumns = GetColumnCount();

		LV_ITEM lvItem1, lvItem2;

		CStringArray rowText;
		rowText.SetSize(nMaxColumns);

		for(int i = 0; i < nMaxColumns; i++)
		{
			rowText[i] = GetItemText(nRow1, i);
		}

		lvItem1.mask = LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
		lvItem1.iItem = nRow1;
		lvItem1.iSubItem = 0;
		lvItem1.stateMask = LVIS_CUT | LVIS_DROPHILITED | LVIS_FOCUSED | LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
		lvItem2 = lvItem1;
		lvItem2.iItem = nRow2;

		GetItem(&lvItem1);
		GetItem(&lvItem2);

		for(i = 0; i < nMaxColumns; i++)
		{
			CListCtrl::SetItemText(nRow1, i, GetItemText(nRow2, i));
		}

		lvItem2.iItem = nRow1;
		SetItem(&lvItem2);

		for(i = 0; i < nMaxColumns; i++)
		{
			CListCtrl::SetItemText(nRow2, i, rowText[i]);
		}

		lvItem1.iItem = nRow2;
		SetItem(&lvItem1);
	}

	return bOk;
}

BOOL CListCtrlEx::CompareBy(CString str1, CString str2)
{
	BOOL bReturn = FALSE;

	switch (this->m_nCompareType)
	{
	case ELCT_INTEGER:
		{
			UCHAR nChar = str1.GetAt(0);                                                  //20140313 余杭排队号有前缀情况排序
			UCHAR nChar2 = str2.GetAt(0); 
			BOOL  bStr = FALSE;
			if ((nChar >= 0x41 && nChar <= 0x5A) || (nChar >= 0x61 && nChar <= 0x7A))
			{
				bStr = TRUE;
				str1 = str1.Mid(1);
				str2 = str2.Mid(1);
			}                                                                             //20140313

			int val1 = atoi(str1);
			int val2 = atoi(str2);

			if (this->m_nSortColumn > 0)                                                  //20140313
			{
				if(nChar != nChar2 && bStr)
					bReturn =  (nChar < nChar2);
				else
					bReturn =  (val1 > val2);
			}
			else
			{
				if(nChar != nChar2 && bStr)
					bReturn =  (nChar > nChar2);
				else
					bReturn =  (val1 < val2);
			}
			break;
		}
	case ELCT_LONG:
		{
			long val1 = atol(str1);
			long val2 = atol(str2);

			if (this->m_nSortColumn > 0)
				bReturn =  (val1 > val2);
			else
				bReturn =  (val1 < val2);
			break;
		}
	case ELCT_DOUBLE:
		{
			double val1 = atof(str1);
			double val2 = atof(str2);

			if (this->m_nSortColumn > 0)
				bReturn =  (val1 > val2);
			else
				bReturn =  (val1 < val2);
			break;
		}
	case ELCT_STRING_NOCASE:
		{
			str1.MakeUpper();
			str2.MakeUpper();
		}
	case ELCT_STRING_CASE:
	default:
		{
			if (this->m_nSortColumn > 0)
				bReturn =  (str1 > str2);
			else
				bReturn =  (str1 < str2);
			break;
		}
	}

	return bReturn;
}

void CListCtrlEx::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = CDRF_DODEFAULT;

	LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW) pNMHDR;
	
	if (lplvcd->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (lplvcd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if (lplvcd->nmcd.dwDrawStage == (CDDS_ITEMPREPAINT | CDDS_SUBITEM))
	{
		if (this->m_bUseFont) ::SelectObject(lplvcd->nmcd.hdc, this->m_hFont);


		int nItem = lplvcd->nmcd.dwItemSpec;
		CString strValue = this->GetItemText(nItem, lplvcd->iSubItem);

		BOOL bChangeBackColor = FALSE;
		COLORREF rgbBackColor = RGB(235, 240, 244);
		if (!strValue.IsEmpty())
		{
			int nSize = this->m_aValue.GetSize();
			for (int i = 0; i < nSize; i++)
			{
				if (strValue == this->m_aValue.GetAt(i))
				{
					bChangeBackColor = TRUE;
					rgbBackColor = this->m_aColor[i];
					break;
				}
			}
		}

		if ((nItem / 3) % 2 != 0 || bChangeBackColor)
		{
			lplvcd->clrTextBk = rgbBackColor;
			*pResult = CDRF_NEWFONT;
		}
		else
		{
			lplvcd->clrTextBk = RGB(255, 255, 255);
			*pResult = CDRF_NEWFONT;
		}
	}
}

BOOL CListCtrlEx::AddColorScheme(CString strValue, COLORREF rgbColor)
{
	if (strValue.IsEmpty())
		return FALSE;
	if (rgbColor < 0)
		return FALSE;
	if (this->m_aValue.GetSize() < 20)
	{
		this->m_aValue.Add(strValue);
		this->m_aColor[this->m_aValue.GetSize() - 1] = rgbColor;
		return TRUE;
	}
	return FALSE;
}

BOOL CListCtrlEx::LoadSave(LPCTSTR lpName, BOOL bSaveToFile, LPCTSTR lpFileName, LPCTSTR lpSubKey, BOOL bHideColumn)
{
	this->m_strName = lpName;

	this->m_bHideColumn = bHideColumn;
	this->m_bSaveToFile = bSaveToFile;
	this->m_strFileName = lpFileName;

	this->m_strSubKey = lpSubKey;
	this->m_strSubKey += "ListCtrlEx\\";

	return TRUE;
}
