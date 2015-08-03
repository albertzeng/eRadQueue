// ComboBoxCheck.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBoxCheck.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static WNDPROC _pWndProc = NULL;
static CComboBoxCheck* _pComboBoxCheck = NULL;

extern "C" static LRESULT FAR PASCAL ComboBoxCheckProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	switch (nMsg)
	{
	case WM_CHAR:
		{
			if (wParam == VK_SPACE)
			{
				INT nIndex = CallWindowProcA(_pWndProc, hWnd, LB_GETCURSEL, wParam, lParam);
				
				CRect rec;
				SendMessage(hWnd, LB_GETITEMRECT, nIndex, (LONG)(LPVOID) &rec);
				::InvalidateRect(hWnd, rec, FALSE);
				_pComboBoxCheck->SetCheck(nIndex, !_pComboBoxCheck->GetCheck(nIndex));
				_pComboBoxCheck->GetParent()->SendMessage(WM_COMMAND, MAKELONG(GetWindowLong(_pComboBoxCheck->m_hWnd, GWL_ID), CBN_SELCHANGE), (LPARAM)_pComboBoxCheck->m_hWnd);
				return 0;
			}
			break;
		}
		
	case WM_RBUTTONDOWN:
		{
			if (_pComboBoxCheck != NULL)
			{
				INT nCount = _pComboBoxCheck->GetCount();

				INT nSelectCount = 0;
				for (INT i = 0; i < nCount; i++)
					if (_pComboBoxCheck->GetCheck(i))
						nSelectCount++;
					
				::InvalidateRect(hWnd, 0, FALSE);
				_pComboBoxCheck->SelectAll(FALSE/*nSelectCount != nCount*/);
				_pComboBoxCheck->GetParent()->SendMessage(WM_COMMAND, MAKELONG(GetWindowLong(_pComboBoxCheck->m_hWnd, GWL_ID), CBN_SELCHANGE), (LPARAM) _pComboBoxCheck->m_hWnd);
			}
		}
		break;
		
	case WM_LBUTTONUP:
		return 0;
		
	case WM_LBUTTONDOWN:
		{
			CRect recClient;
			GetClientRect(hWnd, recClient);
			
			CPoint pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			
			if (PtInRect(recClient, pt))
			{
				INT nHeight = SendMessage(hWnd, LB_GETITEMHEIGHT, 0, 0);
				INT nTopIndex = SendMessage(hWnd, LB_GETTOPINDEX, 0, 0);
				
				INT nIndex = nTopIndex + pt.y / nHeight;
				
				CRect rec;
				SendMessage(hWnd, LB_GETITEMRECT, nIndex, (LONG)(LPVOID) &rec);
				if (PtInRect(rec, pt))
				{
					::InvalidateRect(hWnd, rec, FALSE);
					_pComboBoxCheck->SetCheck(nIndex, !_pComboBoxCheck->GetCheck(nIndex));
					_pComboBoxCheck->GetParent()->SendMessage(WM_COMMAND, MAKELONG(GetWindowLong(_pComboBoxCheck->m_hWnd, GWL_ID), CBN_SELCHANGE), (LPARAM)_pComboBoxCheck->m_hWnd);
				}
			}
		}
		break;
		
	case LB_GETCURSEL:
		return -1;
	}
	
	return CallWindowProc(_pWndProc, hWnd, nMsg, wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////
// CComboBoxCheck

CComboBoxCheck::CComboBoxCheck()
{
	this->m_hListBox		= NULL;
	this->m_bSetHeight		= FALSE;
	this->m_bTextUpdated	= FALSE;

	this->m_bSaveToFile		= FALSE;
	this->m_strName			= "ComboBoxCheck";
	this->m_strSubKey		= _T("SOFTWARE\\RADinfo.com.cn\\ComboBoxCheck\\ComboBoxCheck\\");
	this->m_strFileName		= "10000.ini";
}

CComboBoxCheck::~CComboBoxCheck()
{
}


BEGIN_MESSAGE_MAP(CComboBoxCheck, CComboBox)
	//{{AFX_MSG_MAP(CComboBoxCheck)
	ON_CONTROL_REFLECT(CBN_DROPDOWN, OnDropdown)
	ON_MESSAGE(WM_CTLCOLORLISTBOX, OnCtlColorListBox)
	ON_MESSAGE(WM_GETTEXT, OnGetText)
	ON_MESSAGE(WM_GETTEXTLENGTH, OnGetTextLength)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboBoxCheck message handlers

BOOL CComboBoxCheck::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class

	dwStyle &= ~(CBS_SIMPLE | CBS_DROPDOWN);

	dwStyle |= CBS_DROPDOWNLIST;

	dwStyle |= CBS_HASSTRINGS;
	dwStyle |= CBS_OWNERDRAWVARIABLE;

	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CComboBoxCheck::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	
	HDC dc = lpDrawItemStruct->hDC;

	CRect recBitmap = lpDrawItemStruct->rcItem;
	CRect recString = lpDrawItemStruct->rcItem;

	CString strBuffer;

	INT nCheck = 0; // 0 - NOTHING, 1 - Unchecked, 2 - Checked

	if ((LONG) lpDrawItemStruct->itemID < 0)
	{
		this->RecalculateWindowText();

		strBuffer = this->m_strWindowText;

		nCheck = 0;
	}
	else
	{
		this->GetLBText(lpDrawItemStruct->itemID, strBuffer);

		nCheck = 1;
		if (this->GetCheck(lpDrawItemStruct->itemID))
			nCheck = 2;

		TEXTMETRIC metrics;
		GetTextMetrics(dc, &metrics);

		recBitmap.left		= 0;
		recBitmap.right		= recBitmap.left + metrics.tmHeight + metrics.tmExternalLeading + 6;
		recBitmap.top		+= 1;
		recBitmap.bottom	-= 1;

		recString.left = recBitmap.right;
	}
	
	if (nCheck > 0)
	{
		::SetBkColor(dc, GetSysColor(COLOR_WINDOW));
		::SetTextColor(dc, GetSysColor(COLOR_WINDOWTEXT));

		UINT nState = DFCS_BUTTONCHECK;

		if (nCheck > 1)
			nState |= DFCS_CHECKED;

		::DrawFrameControl(dc, recBitmap, DFC_BUTTON, nState);
	}

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		::SetBkColor(dc, GetSysColor(COLOR_HIGHLIGHT));
		::SetTextColor(dc, GetSysColor(COLOR_HIGHLIGHTTEXT));
	}
	else if (lpDrawItemStruct->itemState & ODS_DISABLED)
	{
		::SetTextColor(dc, GetSysColor(COLOR_GRAYTEXT));
	}
	else
	{
		::SetBkColor(dc, GetSysColor(COLOR_WINDOW));
		::SetTextColor(dc, GetSysColor(COLOR_WINDOWTEXT));
	}

	::ExtTextOut(dc, 0, 0, ETO_OPAQUE, &recString, 0, 0, 0);
	::DrawText(dc, ' ' + strBuffer, strBuffer.GetLength() + 1, &recString, DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS);

	if ((lpDrawItemStruct->itemState & (ODS_FOCUS | ODS_SELECTED)) == (ODS_FOCUS | ODS_SELECTED))
		::DrawFocusRect(dc, &recString);
}

void CComboBoxCheck::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your code to determine the size of specified item
	
	CClientDC dc(this);
	CFont* pFont = dc.SelectObject(GetFont());

	if (pFont != NULL)
	{
		TEXTMETRIC metrics;
		dc.GetTextMetrics(&metrics);

		lpMeasureItemStruct->itemHeight = metrics.tmHeight + metrics.tmExternalLeading;
		lpMeasureItemStruct->itemHeight += 2;

		if (!this->m_bSetHeight)
		{
			this->m_bSetHeight = TRUE;
			SetItemHeight(-1, lpMeasureItemStruct->itemHeight);
		}

		dc.SelectObject(pFont);
	}
}

void CComboBoxCheck::OnDestroy() 
{
	this->UpdateRegistry(TRUE);

	CComboBox::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CComboBoxCheck::OnDropdown() 
{
	// TODO: Add your control notification handler code here

	_pComboBoxCheck = this;
}

LRESULT CComboBoxCheck::OnCtlColorListBox(WPARAM wParam, LPARAM lParam)
{
	if (this->m_hListBox == NULL)
	{
		HWND hWnd = (HWND) lParam;

		if (hWnd != 0 && hWnd != m_hWnd)
		{
			this->m_hListBox = hWnd;

			_pWndProc = (WNDPROC) ::GetWindowLong(this->m_hListBox, GWL_WNDPROC);

			::SetWindowLong(this->m_hListBox, GWL_WNDPROC, (LONG) ComboBoxCheckProc);
		}
	}

	return DefWindowProc(WM_CTLCOLORLISTBOX, wParam, lParam);
}

LRESULT CComboBoxCheck::OnGetText(WPARAM wParam, LPARAM lParam)
{
	this->RecalculateWindowText();

	if (lParam == 0)
		return 0;

	lstrcpyn((LPSTR) lParam, this->m_strWindowText, (INT) wParam);

	return this->m_strWindowText.GetLength();
}

LRESULT CComboBoxCheck::OnGetTextLength(WPARAM wParam, LPARAM lParam)
{
	this->RecalculateWindowText();

	return this->m_strWindowText.GetLength();
}

BOOL CComboBoxCheck::RecalculateWindowText()
{
	if (!this->m_bTextUpdated)
	{
		this->m_strWindowText.Empty();

		CString strSeparator = _T(", ");

		INT nCount = this->GetCount();
		for (INT i = 0; i < nCount; i++)
		{
			if (this->GetCheck(i))
			{
				CString strBuffer;
				this->GetLBText(i, strBuffer);

				if (!this->m_strWindowText.IsEmpty())
					this->m_strWindowText += strSeparator;

				this->m_strWindowText += strBuffer;
			}
		}

		this->m_bTextUpdated = TRUE;
	}

	return TRUE;
}

BOOL CComboBoxCheck::UpdateRegistry(BOOL bReadWrite)	//TRUE: Write, FALSE: Read
{
	LONG lRet = ERROR_SUCCESS;
	HKEY hKey = NULL;
	CString strBuffer;

	if (bReadWrite)	//Write
	{
		this->m_strSaveValue.Empty();
		for (INT i = 0; i < this->GetCount(); i++)
			if (this->GetCheck(i))
			{
				this->GetLBText(i, strBuffer);
				this->m_strSaveValue += "|";
				this->m_strSaveValue += strBuffer;
				this->m_strSaveValue += "|";
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
								 (CONST BYTE *) (LPCTSTR) this->m_strSaveValue, 
								 this->m_strSaveValue.GetLength() + 1);
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
					this->m_strSaveValue = pszData;
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
			::WritePrivateProfileString("ComboBoxCheck", this->m_strName, this->m_strSaveValue, this->m_strFileName);
		}
		else
		{
			char lpBuffer[1024];
			lRet = ::GetPrivateProfileString("ComboBoxCheck", this->m_strName, "", lpBuffer, sizeof(lpBuffer), this->m_strFileName);
			if (lRet > 0) this->m_strSaveValue = lpBuffer;
		}
	}

	if (!bReadWrite)	//Read
	{
	}

	return TRUE;
}

BOOL CComboBoxCheck::SelectAll(BOOL bCheck)
{
	for (INT i = 0; i < this->m_aCheck.GetSize(); i++)
		this->m_aCheck.ElementAt(i) = bCheck;

	this->m_bTextUpdated = FALSE;

	this->Invalidate(FALSE);

	return TRUE;
}

BOOL CComboBoxCheck::SetCheck(INT nIndex, BOOL bCheck)
{
	if (nIndex >= 0 && nIndex < this->m_aCheck.GetSize())
		this->m_aCheck.ElementAt(nIndex) = bCheck;

	this->m_bTextUpdated = FALSE;

	this->Invalidate(FALSE);

	return TRUE;
}

BOOL CComboBoxCheck::GetCheck(INT nIndex)
{
	if (nIndex >= 0 && nIndex < this->m_aCheck.GetSize())
		return this->m_aCheck.ElementAt(nIndex);

	return FALSE;
}

INT CComboBoxCheck::GetSelectCount()
{
	INT nSeleleCount = 0;
	for (INT i = 0; i < this->GetCount(); i++)
		if (this->GetCheck(i))
			nSeleleCount ++;
	
	return nSeleleCount;
}

BOOL CComboBoxCheck::LoadSave(LPCTSTR lpName, BOOL bSaveToFile, LPCTSTR lpFileName, LPCTSTR lpSubKey)
{
	this->m_strName = lpName;

	this->m_bSaveToFile = bSaveToFile;
	this->m_strFileName = lpFileName;

	this->m_strSubKey = lpSubKey;
	this->m_strSubKey += "ComboBoxCheck\\";

	this->UpdateRegistry(FALSE);

	for (INT i = 0; i < this->GetCount(); i++)
	{
		CString strBuffer;
		this->GetLBText(i, strBuffer);
		strBuffer.Insert(0, '|');
		strBuffer += '|';

		this->m_aCheck.Add(!(this->m_strSaveValue.Find(strBuffer, 0) < 0));
	}

	return TRUE;
}
