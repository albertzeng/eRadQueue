// TabCtrlEx.cpp : implementation file
//

#include "stdafx.h"
#include "TabCtrlEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabCtrlEx

CTabCtrlEx::CTabCtrlEx()
{
	this->m_pBrush = new CBrush(::GetSysColor(COLOR_WINDOW));
	this->m_pBrushEmphasis = new CBrush(::GetSysColor(COLOR_WINDOW));
}

CTabCtrlEx::~CTabCtrlEx()
{
	delete this->m_pBrush;
	delete this->m_pBrushEmphasis;
}


BEGIN_MESSAGE_MAP(CTabCtrlEx, CTabCtrl)
	//{{AFX_MSG_MAP(CTabCtrlEx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabCtrlEx message handlers

void CTabCtrlEx::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	CRect recCtrl, recBlank;
	this->GetWindowRect(&recCtrl);
	this->GetItemRect(this->GetItemCount() - 1, recBlank);

	recBlank.left = recBlank.right;
	recBlank.right = recCtrl.right - recCtrl.left;
	recBlank.top -= 2;

	CRect recBack(lpDrawItemStruct->rcItem);
	CRect recFore(lpDrawItemStruct->rcItem);
	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		recBack.DeflateRect(0, 0, 0, 0);
		recFore.DeflateRect(2, 2, 2, 1);
	}
	else
	{
		recBack.DeflateRect(-2, -2, -2, -2);
		recFore.DeflateRect(0, 2, 0, -2);

		if (lpDrawItemStruct->itemID == 0)
			recBack.left = 0;
	}

	pDC->SetBkMode(TRANSPARENT);
	if ((lpDrawItemStruct->itemState & ODS_SELECTED) && 
		(lpDrawItemStruct->itemAction & (ODA_SELECT | ODA_DRAWENTIRE)))
	{
		pDC->FillRect(&recBack, this->m_pBrushEmphasis);
	}
	else if (lpDrawItemStruct->itemAction & ODA_DRAWENTIRE)
	{
		pDC->FillRect(&recBack, this->m_pBrush);
	}

	pDC->FillRect(&recBlank, this->m_pBrush);

	char lpTabText[1024];
	memset(lpTabText, 0, sizeof(lpTabText));

	TC_ITEM ti;
	
	ti.mask = TCIF_TEXT;
	ti.pszText = lpTabText;
	ti.cchTextMax = sizeof(lpTabText) - 1;
	this->GetItem(lpDrawItemStruct->itemID, &ti);

	if ((lpDrawItemStruct->itemState & ODS_SELECTED) && 
		(lpDrawItemStruct->itemAction & (ODA_SELECT | ODA_DRAWENTIRE)))
	{
		pDC->TextOut(recFore.left + 6, recFore.top + 1, ti.pszText);
	}
	else if (lpDrawItemStruct->itemAction & ODA_DRAWENTIRE)
	{
		pDC->TextOut(recFore.left + 4, recFore.top + 1, ti.pszText);
	}
}

BOOL CTabCtrlEx::SetBackColor(COLORREF rgbBackColor, COLORREF rgbBackColorEmphasis)
{
	delete this->m_pBrush;
	this->m_pBrush = new CBrush(rgbBackColor);

	delete this->m_pBrushEmphasis;
	this->m_pBrushEmphasis = new CBrush(rgbBackColorEmphasis);

	return TRUE;
}

BOOL CTabCtrlEx::SetItemText(LONG nIndex, LPSTR lpValue)
{
	TCITEM ti;	  
	ti.mask = TCIF_TEXT;
	ti.pszText = lpValue;
	this->SetItem(nIndex, &ti);

	return TRUE;
}
