// ImageBoxEx.cpp : implementation file
//

#include "stdafx.h"
#include "ImageBoxEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageBoxEx

CImageBoxEx::CImageBoxEx()
{
	this->m_bIsChecked		= FALSE;
	this->m_bIsPressed		= FALSE;
	this->m_bIsFocused		= FALSE;
	this->m_bIsMouseActive	= FALSE;
	this->m_bIsTransparent	= FALSE;
	this->m_pbmRestore		= NULL;
	this->m_pToolTipCtrl	= NULL;
	this->m_nAlign			= E_ALIGN_ON; 
	this->m_hCursor			= NULL;

	this->ResetColors(FALSE);

	::ZeroMemory(&this->m_Icons, sizeof(this->m_Icons));
}

CImageBoxEx::~CImageBoxEx()
{
	if (this->m_dcBackground.m_hDC && this->m_pbmRestore)
		this->m_dcBackground.SelectObject(this->m_pbmRestore);

	if (this->m_hCursor)
		::DestroyCursor(this->m_hCursor);

	if (this->m_pToolTipCtrl != NULL)
	{
		this->m_pToolTipCtrl->DestroyWindow();
		delete this->m_pToolTipCtrl;
	}

	this->FreeResources();
}


BEGIN_MESSAGE_MAP(CImageBoxEx, CButton)
	//{{AFX_MSG_MAP(CImageBoxEx)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CANCELMODE()
	ON_WM_GETDLGCODE()
	ON_WM_SYSCOLORCHANGE()
	ON_WM_ACTIVATE()
	ON_WM_ENABLE()
	ON_WM_SETCURSOR()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP

	ON_MESSAGE(BM_SETSTYLE, OnSetStyle)
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageBoxEx message handlers

LRESULT CImageBoxEx::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class

	if (message == WM_LBUTTONDBLCLK) message = WM_LBUTTONDOWN;

	return CButton::DefWindowProc(message, wParam, lParam);
}

void CImageBoxEx::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	this->m_bIsTransparent = (this->GetExStyle() & WS_EX_TRANSPARENT);

	CButton::PreSubclassWindow();
}

BOOL CImageBoxEx::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	if (this->m_pToolTipCtrl != NULL)
		this->m_pToolTipCtrl->RelayEvent(pMsg);

	return CButton::PreTranslateMessage(pMsg);
}

void CImageBoxEx::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	
	this->m_bIsFocused	= (lpDrawItemStruct->itemState & ODS_FOCUS);
	this->m_bIsPressed	= (lpDrawItemStruct->itemState & ODS_SELECTED);
	
	pDC->SetBkMode(TRANSPARENT);
	if (this->m_bIsTransparent)
		this->DrawBackground(pDC);
	
	CRect recCaption;
	if (this->m_Icons[0].m_hIcon)
		this->DrawIcon(pDC, lpDrawItemStruct->rcItem, recCaption);
	
	if (this->m_nAlign != E_ALIGN_NONE)
	{
		CString strCaption;
		this->GetWindowText(strCaption);
		
		CRect recRange = recCaption;
		pDC->DrawText(strCaption, -1, recCaption, DT_WORDBREAK | DT_CENTER | DT_CALCRECT);
		
		recCaption.OffsetRect((recRange.Width() - recCaption.Width()) / 2, (recRange.Height() - recCaption.Height()) / 2);
		
		pDC->SetTextColor(RGB(255, 255, 255));
		for (LONG i = -1; i <= 1; i++)
		{
			for (LONG k = -1; k <= 1; k++)
			{
				CRect rect = recCaption;
				rect.OffsetRect(i, k);
				pDC->DrawText(strCaption, -1, rect, DT_WORDBREAK | DT_CENTER);
			}
		}

		if (!this->IsWindowEnabled())
		{
			pDC->SetTextColor(RGB(192, 192, 192));
		}
		else if (this->m_bIsChecked)
		{
			pDC->SetBkColor(this->m_rgbColors[E_COLOR_BACK_CHECK]);
			pDC->SetTextColor(this->m_rgbColors[E_COLOR_FORE_CHECK]);
		}
		else if (this->m_bIsFocused)
		{
			pDC->SetBkColor(this->m_rgbColors[E_COLOR_BACK_FOCUS]);
			pDC->SetTextColor(this->m_rgbColors[E_COLOR_FORE_FOCUS]);
		}
		else if (this->m_bIsMouseActive || this->m_bIsPressed)
		{
			pDC->SetBkColor(this->m_rgbColors[E_COLOR_BACK_ON]);
			pDC->SetTextColor(this->m_rgbColors[E_COLOR_FORE_ON]);
		}
		else
		{
			pDC->SetBkColor(this->m_rgbColors[E_COLOR_BACK]);
			pDC->SetTextColor(this->m_rgbColors[E_COLOR_FORE]);
		}
		
		pDC->DrawText(strCaption, -1, recCaption, DT_WORDBREAK | DT_CENTER);
	}
}

HBRUSH CImageBoxEx::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here

	return (HBRUSH) ::GetStockObject(NULL_BRUSH);

	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return NULL;
}

void CImageBoxEx::OnCancelMode() 
{
	CButton::OnCancelMode();
	
	// TODO: Add your message handler code here

	this->ResetMouseActive();
}

UINT CImageBoxEx::OnGetDlgCode() 
{
	// TODO: Add your message handler code here and/or call default

	return CButton::OnGetDlgCode();
}

void CImageBoxEx::OnSysColorChange() 
{
	CButton::OnSysColorChange();
	
	// TODO: Add your message handler code here

	this->m_dcBackground.DeleteDC();
	this->m_bmBackground.DeleteObject();
}

void CImageBoxEx::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CButton::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here

	if (nState == WA_INACTIVE)
		this->ResetMouseActive();
}

void CImageBoxEx::OnEnable(BOOL bEnable) 
{
	CButton::OnEnable(bEnable);
	
	// TODO: Add your message handler code here

	if (!bEnable)
		this->ResetMouseActive();
}

BOOL CImageBoxEx::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default

	if (this->m_hCursor != NULL)
	{
		::SetCursor(this->m_hCursor);

		return TRUE;
	}

	return CButton::OnSetCursor(pWnd, nHitTest, message);
}

void CImageBoxEx::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here

	this->ResetMouseActive();
}

void CImageBoxEx::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (this->m_bIsMouseActive || !(nFlags & MK_LBUTTON))
	{
		this->ClientToScreen(&point);
		CWnd* pWnd = CWnd::WindowFromPoint(point);

		if (pWnd == NULL || pWnd->m_hWnd != this->m_hWnd)
			this->ResetMouseActive();
		else
		{
			if (!this->m_bIsMouseActive)
			{
				this->m_bIsMouseActive = TRUE;
				this->Invalidate();

				TRACKMOUSEEVENT TME;
				TME.cbSize = sizeof(TME);
				TME.dwFlags = TME_LEAVE;
				TME.hwndTrack = this->m_hWnd;
				::_TrackMouseEvent(&TME);
			}
		}
	}
	
	CButton::OnMouseMove(nFlags, point);
}

LRESULT CImageBoxEx::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	this->ResetMouseActive();

	return 0;
}

LRESULT CImageBoxEx::OnSetStyle(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

BOOL CImageBoxEx::FreeResources()
{
	if (this->m_Icons[0].m_hIcon) ::DestroyIcon(this->m_Icons[0].m_hIcon);
	if (this->m_Icons[1].m_hIcon) ::DestroyIcon(this->m_Icons[1].m_hIcon);
	if (this->m_Icons[2].m_hIcon) ::DestroyIcon(this->m_Icons[2].m_hIcon);
	
	::ZeroMemory(&this->m_Icons, sizeof(this->m_Icons));
	
	return TRUE;
}

BOOL CImageBoxEx::ResetMouseActive()
{
	if (this->m_bIsMouseActive)
	{
		this->m_bIsMouseActive = FALSE;
		
		this->Invalidate();
	}
	
	return TRUE;
}

BOOL CImageBoxEx::CreateToolTipCtrl()
{
	if (this->m_pToolTipCtrl == NULL)
	{
		this->m_pToolTipCtrl = new CToolTipCtrl;
		this->m_pToolTipCtrl->Create(this);
		this->m_pToolTipCtrl->Activate(FALSE);
		this->m_pToolTipCtrl->SendMessage(TTM_SETMAXTIPWIDTH, 0, 200);
	}

	return TRUE;
}

BOOL CImageBoxEx::SetToolTip(LONG nIDValue, BOOL bActivate)
{
	CString strValue;
	strValue.LoadString(nIDValue);
	if (strValue.IsEmpty())
		return this->SetToolTip(strValue, bActivate);

	return FALSE;
}

BOOL CImageBoxEx::SetToolTip(LPCTSTR lpValue, BOOL bActivate)
{
	if (lpValue == NULL)
		return FALSE;

	this->CreateToolTipCtrl();

	if (this->m_pToolTipCtrl->GetToolCount() == 0)
	{
		CRect rect;
		this->GetClientRect(rect);
		this->m_pToolTipCtrl->AddTool(this, lpValue, rect, 1);
	}

	this->m_pToolTipCtrl->UpdateTipText(lpValue, this, 1);
	this->m_pToolTipCtrl->Activate(bActivate);

	return TRUE;
}

BOOL CImageBoxEx::ResetColors(BOOL bRepaint)
{
	this->m_rgbColors[E_COLOR_BACK]			= ::GetSysColor(COLOR_BTNFACE);
	this->m_rgbColors[E_COLOR_FORE]			= ::GetSysColor(COLOR_BTNTEXT);
	this->m_rgbColors[E_COLOR_BACK_ON]		= ::GetSysColor(COLOR_BTNFACE);
	this->m_rgbColors[E_COLOR_FORE_ON]		= RGB(0, 0, 255);
	this->m_rgbColors[E_COLOR_BACK_FOCUS]	= ::GetSysColor(COLOR_BTNFACE);
	this->m_rgbColors[E_COLOR_FORE_FOCUS]	= RGB(0, 0, 255);
	this->m_rgbColors[E_COLOR_BACK_CHECK]	= ::GetSysColor(COLOR_BTNFACE);
	this->m_rgbColors[E_COLOR_FORE_CHECK]	= RGB(255, 0, 0);
	
	if (bRepaint)
		this->Invalidate();
	
	return TRUE;
}

BOOL CImageBoxEx::SetColor(BYTE nColorIndex, COLORREF rgbColor, BOOL bRepaint)
{
	if (nColorIndex >= E_COLOR_MAX_COUNT)
		return FALSE;
	
	this->m_rgbColors[nColorIndex] = rgbColor;
	
	if (bRepaint)
		this->Invalidate();
	
	return TRUE;
}

BOOL CImageBoxEx::GetColor(BYTE nColorIndex, COLORREF& rgbColor)
{
	if (nColorIndex >= E_COLOR_MAX_COUNT)
		return FALSE;
	
	rgbColor = this->m_rgbColors[nColorIndex];
	
	return TRUE;
}

BOOL CImageBoxEx::SetIcon(LONG nIDIconIn, LONG nIDIconOut, LONG nIDIconDsiable)
{
	HINSTANCE hInstResource = ::AfxFindResourceHandle(MAKEINTRESOURCE(nIDIconIn), RT_GROUP_ICON);
	
	HICON hIconIn = (HICON) ::LoadImage(hInstResource, MAKEINTRESOURCE(nIDIconIn), IMAGE_ICON, 0, 0, 0);
	HICON hIconOut = (HICON) ::LoadImage(hInstResource, MAKEINTRESOURCE(nIDIconOut), IMAGE_ICON, 0, 0, 0);
	HICON hIconDisable = (HICON) ::LoadImage(hInstResource, MAKEINTRESOURCE(nIDIconDsiable), IMAGE_ICON, 0, 0, 0);
	
	return this->SetIcon(hIconIn, hIconOut, hIconDisable);
}

BOOL CImageBoxEx::SetIcon(HICON hIconIn, HICON hIconOut, HICON hIconDisable)
{
	if (hIconIn == NULL && hIconOut == NULL && hIconDisable == NULL)
		return FALSE;
	
	this->FreeResources();
	
	ICONINFO ii;
	
	this->m_Icons[0].m_hIcon = hIconIn;
	::ZeroMemory(&ii, sizeof(ICONINFO));
	if (!GetIconInfo(hIconIn, &ii))
		return FALSE;
	
	this->m_Icons[0].m_nIconX = (DWORD) (ii.xHotspot * 2);
	this->m_Icons[0].m_nIconY = (DWORD) (ii.yHotspot * 2);
	::DeleteObject(ii.hbmMask);
	::DeleteObject(ii.hbmColor);
	
	this->m_Icons[1].m_hIcon = hIconOut;
	::ZeroMemory(&ii, sizeof(ICONINFO));
	if (!GetIconInfo(hIconOut, &ii))
		return FALSE;
	
	this->m_Icons[1].m_nIconX = (DWORD) (ii.xHotspot * 2);
	this->m_Icons[1].m_nIconY = (DWORD) (ii.yHotspot * 2);
	::DeleteObject(ii.hbmMask);
	::DeleteObject(ii.hbmColor);
	
	this->m_Icons[2].m_hIcon = hIconDisable;
	::ZeroMemory(&ii, sizeof(ICONINFO));
	if (!GetIconInfo(hIconDisable, &ii))
		return FALSE;
	
	this->m_Icons[2].m_nIconX = (DWORD) (ii.xHotspot * 2);
	this->m_Icons[2].m_nIconY = (DWORD) (ii.yHotspot * 2);
	::DeleteObject(ii.hbmMask);
	::DeleteObject(ii.hbmColor);
	
	this->Invalidate();
	
	return TRUE;
}

BOOL CImageBoxEx::SetAlign(LONG nAlign, BOOL bRepaint)
{
	switch (nAlign)
	{    
	case E_ALIGN_ON:
	case E_ALIGN_NONE:
	case E_ALIGN_V_BOTTOM:
		this->m_nAlign = nAlign;
		break;
	default:
		return FALSE;
	}
	
	if (bRepaint)
		this->Invalidate();
	
	return TRUE;
}

BOOL CImageBoxEx::SetCheck(BOOL bCheck, BOOL bRepaint)
{
	if (this->m_bIsChecked != bCheck)
	{
		this->m_bIsChecked = bCheck;

		if (bRepaint)
			this->Invalidate();
	}

	return TRUE;
}

BOOL CImageBoxEx::DrawBackground(CDC* pDC)
{
	CClientDC dcClient(this->GetParent());
	
	CRect recClient;
	CRect recWindow;
	this->GetClientRect(recClient);
	this->GetWindowRect(recWindow);
	this->GetParent()->ScreenToClient(recWindow);
	
	if (this->m_dcBackground.m_hDC == NULL && this->GetTopLevelParent() == CWnd::GetForegroundWindow())
	{
		this->m_dcBackground.CreateCompatibleDC(&dcClient);
		this->m_bmBackground.CreateCompatibleBitmap(&dcClient, recClient.Width(), recClient.Height());
		this->m_pbmRestore = this->m_dcBackground.SelectObject(&this->m_bmBackground);
		this->m_dcBackground.BitBlt(0, 0, recClient.Width(), recClient.Height(), &dcClient, recWindow.left, recWindow.top, SRCCOPY);
	}
	
	pDC->BitBlt(0, 0, recClient.Width(), recClient.Height(), &this->m_dcBackground, 0, 0, SRCCOPY);
	
	return TRUE;
}

BOOL CImageBoxEx::DrawTransparent(BOOL bRepaint)
{
	this->m_bIsTransparent = TRUE;
	
	if (this->m_dcBackground.m_hDC != NULL && this->m_pbmRestore != NULL)
		this->m_dcBackground.SelectObject(this->m_pbmRestore);
	
	this->m_dcBackground.DeleteDC();
	this->m_bmBackground.DeleteObject();
	
	if (bRepaint)
		this->Invalidate();
	
	return TRUE;
}

BOOL CImageBoxEx::DrawPrepare(CRect recRange, LONG nIconX, LONG nIconY, CRect& recImage, CRect& recCaption)
{
	recImage = recRange;
	recCaption = recRange;
	switch (this->m_nAlign)
	{
	case E_ALIGN_ON:
	case E_ALIGN_NONE:
		recImage.left += (recImage.Width() - nIconX) / 2;
		recImage.top += (recImage.Height() - nIconY) / 2;
		break;
		
	case E_ALIGN_V_BOTTOM:
		recImage.left += (recImage.Width() - nIconX) / 2;
		recImage.top = 3;
		recCaption.top += nIconY;
		break;

	default:
		return FALSE;
	}
    
	if (this->m_bIsPressed)
	{
		recImage.OffsetRect(1, 1);
		recCaption.OffsetRect(1, 1);
	}
	
	return TRUE;
}

BOOL CImageBoxEx::DrawIcon(CDC* pDC, CRect recRange, CRect& recCaption)
{
	BYTE nIndex = 0;
	
	if (!this->IsWindowEnabled())
		nIndex = 2;
	else
	{
		if (((this->m_bIsPressed || this->m_bIsMouseActive)))
			nIndex = 0;
		else
			nIndex = (this->m_Icons[1].m_hIcon == NULL) ? 0 : 1;
	}
	
	CRect recImage;
	this->DrawPrepare(recRange, this->m_Icons[nIndex].m_nIconX, this->m_Icons[nIndex].m_nIconY, recImage, recCaption);
	
	pDC->DrawState(recImage.TopLeft(), recImage.Size(), this->m_Icons[nIndex].m_hIcon, DSS_NORMAL, (HBRUSH) NULL);
	
	return TRUE;
}
