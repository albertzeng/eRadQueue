// RichEditCtrlEx.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "RichEditCtrlEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// CSelective Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSelective::CSelective()
{
	this->m_nPos = 0;
}

CSelective::~CSelective()
{

}

BOOL CSelective::Move(LONG nOffset)
{
	this->m_nPos += nOffset;

	return TRUE;
}

BOOL CSelective::OnSelective(LONG nPos, BOOL bSide)
{
	if (nPos < this->m_nPos || nPos > this->m_nPos + this->m_strValue.GetLength())
		return FALSE;

	if (!bSide && (nPos == this->m_nPos || nPos == this->m_nPos + this->m_strValue.GetLength()))
		return FALSE;

	return TRUE;
}

MRET CSelective::Load(CXmlParse* pXmlParse, IXMLDOMNode* pNode)
{
	this->m_strValue.Empty();

	IXMLDOMNode* pChild = NULL;
	MRET rc = pXmlParse->GetFirstChildNode(pNode, &pChild);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	BOOL bFirstChild = TRUE;
	while (pChild != NULL)
	{
		CString strName, strValue;
		rc = pXmlParse->GetNodeName(pChild, strName);
		if (rc != ME_OK)
		{
			if (pChild) pChild->Release();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		strName.MakeUpper();
		if (strName == _T("ITEM"))
		{
			rc = pXmlParse->GetNodeValue(pChild, strValue);
			if (rc != ME_OK)
			{
				if (pChild) pChild->Release();
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}

//			strValue.Replace('\r', ' ');
//			strValue.Replace('\n', ' ');

			this->m_Selectives.Add(strValue);
		}
		else if (bFirstChild)
		{
			rc = pXmlParse->GetNodeValue(pNode, this->m_strValue);
			if (rc != ME_OK)
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}

//			this->m_strValue.Replace('\r', ' ');
//			this->m_strValue.Replace('\n', ' ');
		}
		else
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, strName);
		}

		IXMLDOMNode* pSibling = NULL;

		rc = pXmlParse->GetNextSiblingNode(pChild, &pSibling);
		if (rc != ME_OK)
		{
			if (pChild) pChild->Release();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		if (pChild) pChild->Release();

		pChild = pSibling;
	}

	return ME_OK;
}

/////////////////////////////////////////////////////////////////////////////
// CSelectiveEdit

CSelectiveEdit::CSelectiveEdit()
{
	this->m_pCtrl = NULL;
}

CSelectiveEdit::~CSelectiveEdit()
{
}


BEGIN_MESSAGE_MAP(CSelectiveEdit, CEdit)
	//{{AFX_MSG_MAP(CSelectiveEdit)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectiveEdit message handlers

BOOL CSelectiveEdit::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	CSelective* pSelective = (CSelective*) ::GetWindowLong(this->m_hWnd, GWL_USERDATA);

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_ESCAPE:
			{
				this->ShowWindow(SW_HIDE);
				return TRUE;
			}
			break;
		default:
			break;
		}
	}

	return CEdit::PreTranslateMessage(pMsg);
}

void CSelectiveEdit::OnKillFocus(CWnd* pNewWnd) 
{
	CEdit::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here

	this->m_pCtrl->UpdateSelectiveEdit();	
}

MRET CSelectiveEdit::Update()
{
	if (this->m_pCtrl == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	MRET rc = this->m_pCtrl->UpdateSelectiveEdit();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	return ME_OK;
}

/////////////////////////////////////////////////////////////////////////////
// CSelectiveComboBox

CSelectiveComboBox::CSelectiveComboBox()
{
	this->m_pCtrl = NULL;
}

CSelectiveComboBox::~CSelectiveComboBox()
{
}


BEGIN_MESSAGE_MAP(CSelectiveComboBox, CComboBox)
	//{{AFX_MSG_MAP(CSelectiveComboBox)
	ON_WM_KILLFOCUS()
	ON_CONTROL_REFLECT(CBN_KILLFOCUS, OnKillfocus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectiveComboBox message handlers

BOOL CSelectiveComboBox::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	CSelective* pSelective = (CSelective*) ::GetWindowLong(this->m_hWnd, GWL_USERDATA);

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_ESCAPE:
			{
				this->ShowWindow(SW_HIDE);
				return TRUE;
			}
			break;
		case VK_RETURN:
			{
				this->m_pCtrl->UpdateSelective();

				LONG nPos = pSelective->m_nPos + pSelective->m_strValue.GetLength();
				this->m_pCtrl->SetSel(nPos, nPos);
				this->m_pCtrl->SetFocus();
				return TRUE;
			}
			break;
		case VK_LEFT:
			{
				this->m_pCtrl->UpdateSelective();

				LONG nPos = pSelective->m_nPos;
				pSelective = this->m_pCtrl->GetSelective(pSelective, FALSE);
				if (pSelective != NULL)
					this->m_pCtrl->ShowSelective(pSelective);
				else
				{
					this->m_pCtrl->SetSel(nPos, nPos);
					this->m_pCtrl->SetFocus();
				}
				return TRUE;
			}
			break;
		case VK_RIGHT:
			{
				this->m_pCtrl->UpdateSelective();

				LONG nPos = pSelective->m_nPos + pSelective->m_strValue.GetLength();
				pSelective = this->m_pCtrl->GetSelective(pSelective, TRUE);
				if (pSelective != NULL)
					this->m_pCtrl->ShowSelective(pSelective);
				else
				{
					this->m_pCtrl->SetSel(nPos, nPos);
					this->m_pCtrl->SetFocus();
				}
				return TRUE;
			}
			break;
		default:
			break;
		}
	}

	return CComboBox::PreTranslateMessage(pMsg);
}

void CSelectiveComboBox::OnKillFocus(CWnd* pNewWnd) 
{
	CComboBox::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here

//	if (this != pNewWnd->GetParent())
//		this->m_pCtrl->UpdateSelective();
}

void CSelectiveComboBox::OnKillfocus() 
{
	// TODO: Add your control notification handler code here

	if (this != this->GetFocus() && this->IsWindowVisible())
		this->m_pCtrl->UpdateSelective();
}

MRET CSelectiveComboBox::Update()
{
	if (this->m_pCtrl == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	MRET rc = this->m_pCtrl->UpdateSelective();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	return ME_OK;
}

/////////////////////////////////////////////////////////////////////////////
// CRichEditCtrlEx

CRichEditCtrlEx::CRichEditCtrlEx()
{
	this->m_bStaticEdge			= FALSE;
	this->m_nMode				= 0;
	this->m_nLineHeight			= 0;
	this->m_nComboBoxHeight		= 0;
	this->m_pTargetCtrl			= NULL;
	this->m_nPosBeforeChange	= 0;
	this->m_nLenBeforeChange	= 0;
	this->m_nPosCutPaste		= 0;
	this->m_nLenCutPaste		= 0;
	this->m_pSelectiveMouse		= NULL;
	this->m_pSelectiveEdit		= NULL;
	this->m_pSelectiveComboBox	= NULL;
}

CRichEditCtrlEx::~CRichEditCtrlEx()
{
	this->ClearSelectives();
}


BEGIN_MESSAGE_MAP(CRichEditCtrlEx, CRichEditCtrl)
	//{{AFX_MSG_MAP(CRichEditCtrlEx)
	ON_COMMAND(ID_RICH_UNDO, OnUndo)
	ON_COMMAND(ID_RICH_CUT, OnCut)
	ON_COMMAND(ID_RICH_COPY, OnCopy)
	ON_COMMAND(ID_RICH_PASTE, OnPaste)
	ON_COMMAND(ID_RICH_CLEAR, OnClear)
	ON_COMMAND(ID_RICH_SELECT_ALL, OnSelectAll)
	ON_COMMAND(ID_RICH_SELECTIVE_SET, OnSelectiveSet)
	ON_COMMAND(ID_RICH_SELECTIVE_EDIT, OnSelectiveEdit)
	ON_COMMAND(ID_RICH_SELECTIVE_DELETE, OnSelectiveDelete)
	ON_COMMAND(ID_RICH_FORMAT_LEFT, OnFormatLeft)
	ON_COMMAND(ID_RICH_FORMAT_SPACE, OnFormatSpace)
	ON_COMMAND(ID_RICH_FORMAT_NUMBER, OnFormatNumber)
	ON_COMMAND(ID_RICH_REPORT_COPY, OnReportCopy)
	ON_COMMAND(ID_RICH_REPORT_PASTE, OnReportPaste)
	ON_COMMAND(ID_RICH_REPORT_APPEND, OnReportAppend)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_VSCROLL()
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_NOTIFY_REFLECT(EN_PROTECTED, OnProtected)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRichEditCtrlEx message handlers

BOOL CRichEditCtrlEx::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			{
				if (this->m_pTargetCtrl != NULL && !(this->m_pTargetCtrl->GetStyle() & ES_READONLY))
				{
					CString strValue = this->GetSelText();
					if (!strValue.IsEmpty())
					{
						this->m_pTargetCtrl->ReplaceSel(strValue, TRUE);
						this->m_pTargetCtrl->SetFocus();
						return TRUE;
					}
				}
			}
			break;
		case VK_LEFT:
			{
				if ((this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT) && !(this->GetStyle() & ES_READONLY))
				{
					CHARRANGE charrange;
					this->GetSel(charrange);
					CSelective* pSelective = this->GetSelective(charrange.cpMin, FALSE);
					if (pSelective != NULL && charrange.cpMin == pSelective->m_nPos + pSelective->m_strValue.GetLength())
					{
						this->ShowSelective(pSelective);
						return TRUE;
					}
				}
			}
			break;
		case VK_RIGHT:
			{
				if ((this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT) && !(this->GetStyle() & ES_READONLY))
				{
					CHARRANGE charrange;
					this->GetSel(charrange);
					CSelective* pSelective = this->GetSelective(charrange.cpMax, TRUE);
					if (pSelective != NULL && charrange.cpMax == pSelective->m_nPos)
					{
						this->ShowSelective(pSelective);
						return TRUE;
					}
				}
			}
			break;
		default:
			break;
		}
	}

	return CRichEditCtrl::PreTranslateMessage(pMsg);
}

BOOL CRichEditCtrlEx::SetReadOnly(BOOL bReadOnly)
{
	// TODO: Add your specialized code here and/or call the base class

	this->SetBackgroundColor(!bReadOnly, COLOR_CTRL_READONLY);

	return CRichEditCtrl::SetReadOnly(bReadOnly);
}

void CRichEditCtrlEx::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	if (this->m_bStaticEdge)
		this->ModifyStyleEx(0, WS_EX_STATICEDGE);

	CRichEditCtrl::PreSubclassWindow();
}

void CRichEditCtrlEx::OnSetFocus(CWnd* pOldWnd) 
{
	CRichEditCtrl::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here

}

void CRichEditCtrlEx::OnKillFocus(CWnd* pNewWnd) 
{
	CRichEditCtrl::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here

}

void CRichEditCtrlEx::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CRichEditCtrl::OnLButtonDblClk(nFlags, point);

	if (this->m_pTargetCtrl != NULL && !(this->m_pTargetCtrl->GetStyle() & ES_READONLY))
	{
		LONG nPos = this->GetCharFromPos(point);
		if (nPos < this->GetTextLength())
		{
			CString strValue;
			this->GetWindowText(strValue);
			LONG nPos1 = strValue.Find('\n', nPos);
			if (nPos1 != -1)
				strValue = strValue.Left(nPos1);
			nPos1 = strValue.ReverseFind('\n');
			if (nPos1 != -1)
				strValue = strValue.Mid(nPos1 + 1);

			strValue.TrimRight();

			this->m_pTargetCtrl->TXTPlus(strValue);
			this->m_pTargetCtrl->GetWindowText(strValue);
			this->m_pTargetCtrl->SetSel(strValue.GetLength(), strValue.GetLength());
			this->m_pTargetCtrl->SetFocus();
		}
	}
}

void CRichEditCtrlEx::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT && !(this->GetStyle() & ES_READONLY))
	{
		if (this->m_pSelectiveEdit != NULL && this->m_pSelectiveEdit->IsWindowVisible())
			this->m_pSelectiveEdit->Update();

		if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
			this->m_pSelectiveComboBox->Update();
	}

	CRichEditCtrl::OnLButtonDown(nFlags, point);
}

void CRichEditCtrlEx::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CRichEditCtrl::OnLButtonUp(nFlags, point);

	if (this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT && !(this->GetStyle() & ES_READONLY))
	{
		if (this->m_pSelectiveEdit != NULL && this->m_pSelectiveEdit->IsWindowVisible())
			this->m_pSelectiveEdit->Update();

		if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
			this->m_pSelectiveComboBox->Update();

		if (this->m_lstSelective.GetCount() > 0 && this->GetSelectionType() == SEL_EMPTY)
		{
			LONG nPos = this->GetCharFromPos(point);
			if (nPos < this->GetTextLength())
			{
				POSITION POS = this->m_lstSelective.GetHeadPosition();
				while (POS != NULL)
				{
					CSelective* pSelective = this->m_lstSelective.GetNext(POS);
					if (pSelective->OnSelective(nPos, TRUE))
					{
						this->ShowSelective(pSelective);
						break;
					}
				}
			}
		}
	}
}

void CRichEditCtrlEx::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	this->SetFocus();

	BOOL bReadOnly = (this->GetStyle() & ES_READONLY);
	BOOL bSelected = (this->GetSelectionType() != SEL_EMPTY);
	BOOL bOnSelective = (this->m_pSelectiveMouse != NULL);
	BOOL bSetSelective = FALSE;
	if (!bReadOnly && bSelected)
	{
		CString strSelect;
		strSelect = this->GetSelText();
		if ((strSelect.Find(_T("\r")) == -1) && (strSelect.Find(_T("\n")) == -1))
		{
			LONG nStart = 0;
			LONG nClose = 0;

			this->GetSel(nStart, nClose);

			POSITION POS = this->m_lstSelective.GetHeadPosition();
			while (POS != NULL)
			{
				CSelective* pSelective = this->m_lstSelective.GetNext(POS);
				if (nClose <= pSelective->m_nPos)
				{
					bSetSelective = TRUE;
					break;
				}
				else if (nStart < pSelective->m_nPos + pSelective->m_strValue.GetLength())
					break;
			}

			if (POS == NULL) bSetSelective = TRUE;
		}
	}

	CMenu menu;
	
	menu.CreatePopupMenu();
	menu.AppendMenu(0, ID_RICH_UNDO,				"撤销(&U)");
	menu.AppendMenu(0, MF_SEPARATOR);
	menu.AppendMenu(0, ID_RICH_CUT,					"剪切(&T)");
	menu.AppendMenu(0, ID_RICH_COPY,				"复制(&C)");
	menu.AppendMenu(0, ID_RICH_PASTE,				"粘贴(&P)");
	menu.AppendMenu(0, ID_RICH_CLEAR,				"删除(&D)");
	menu.AppendMenu(0, MF_SEPARATOR);
	menu.AppendMenu(0, ID_RICH_SELECT_ALL,			"全选(&A)");
	
	menu.EnableMenuItem(ID_RICH_UNDO,				MF_BYCOMMAND | ((!bReadOnly && CanUndo())	? 0 : MF_GRAYED));
	menu.EnableMenuItem(ID_RICH_CUT,				MF_BYCOMMAND | ((!bReadOnly && bSelected)	? 0 : MF_GRAYED));
	menu.EnableMenuItem(ID_RICH_COPY,				MF_BYCOMMAND | ((bSelected)					? 0 : MF_GRAYED));
	menu.EnableMenuItem(ID_RICH_PASTE,				MF_BYCOMMAND | ((!bReadOnly && CanPaste())	? 0 : MF_GRAYED));
	menu.EnableMenuItem(ID_RICH_CLEAR,				MF_BYCOMMAND | ((!bReadOnly && bSelected)	? 0 : MF_GRAYED));

	if (this->m_nMode & (RICHEDITCTRLEX_REPORT | RICHEDITCTRLEX_REPORT_EDIT))
	{
		menu.AppendMenu(0, MF_SEPARATOR);
		menu.AppendMenu(0, ID_RICH_REPORT_COPY,			"复制报告");

		if (this->m_nMode & RICHEDITCTRLEX_REPORT_EDIT)
		{
			menu.AppendMenu(0, ID_RICH_REPORT_PASTE,		"粘贴报告");
			menu.AppendMenu(0, ID_RICH_REPORT_APPEND,		"追加报告");
			menu.AppendMenu(0, MF_SEPARATOR);	
			menu.AppendMenu(0, ID_RICH_FORMAT_LEFT,			"左对齐(&L)");
			menu.AppendMenu(0, ID_RICH_FORMAT_SPACE,		"段首空格(&S)");
			menu.AppendMenu(0, ID_RICH_FORMAT_NUMBER,		"段首编号(&N)");

			menu.EnableMenuItem(ID_RICH_REPORT_PASTE,		MF_BYCOMMAND | ((!bReadOnly && ::IsClipboardFormatAvailable(::RegisterClipboardFormat(_T("CF_REPORT")))) ? 0 : MF_GRAYED));
			menu.EnableMenuItem(ID_RICH_REPORT_APPEND,		MF_BYCOMMAND | ((!bReadOnly && ::IsClipboardFormatAvailable(::RegisterClipboardFormat(_T("CF_REPORT")))) ? 0 : MF_GRAYED));

			menu.EnableMenuItem(ID_RICH_FORMAT_LEFT,		MF_BYCOMMAND | ((!bReadOnly)				? 0 : MF_GRAYED));
			menu.EnableMenuItem(ID_RICH_FORMAT_SPACE,		MF_BYCOMMAND | ((!bReadOnly)				? 0 : MF_GRAYED));
			menu.EnableMenuItem(ID_RICH_FORMAT_NUMBER,		MF_BYCOMMAND | ((!bReadOnly)				? 0 : MF_GRAYED));
		}
	}

	if (this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT)
	{
		menu.AppendMenu(0, MF_SEPARATOR);
		menu.AppendMenu(0, ID_RICH_SELECTIVE_SET,		"设为选择项(&O)");
		menu.AppendMenu(0, ID_RICH_SELECTIVE_EDIT,		"编辑选择项(&E)");
		menu.AppendMenu(0, ID_RICH_SELECTIVE_DELETE,	"撤消选择项(&D)");

		menu.EnableMenuItem(ID_RICH_SELECTIVE_SET,		MF_BYCOMMAND | ((bSetSelective)				? 0 : MF_GRAYED));
		menu.EnableMenuItem(ID_RICH_SELECTIVE_EDIT,		MF_BYCOMMAND | ((bOnSelective)				? 0 : MF_GRAYED));
		menu.EnableMenuItem(ID_RICH_SELECTIVE_DELETE,	MF_BYCOMMAND | ((bOnSelective)				? 0 : MF_GRAYED));
	}

	CPoint pt;
	::GetCursorPos(&pt);
	menu.TrackPopupMenu(TPM_RIGHTBUTTON, pt.x, pt.y, this);
//	menu.DestroyMenu();

	CRichEditCtrl::OnRButtonUp(nFlags, point);
}

void CRichEditCtrlEx::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT)
	{
		LONG nPos = this->GetCharFromPos(point);

		this->m_pSelectiveMouse = NULL;

		POSITION POS = this->m_lstSelective.GetHeadPosition();
		while (POS != NULL)
		{
			CSelective* pSelective = this->m_lstSelective.GetNext(POS);
			if (pSelective->OnSelective(nPos, TRUE))
			{
				this->m_pSelectiveMouse = pSelective;
				break;
			}
		}
	}

	CRichEditCtrl::OnMouseMove(nFlags, point);
}

void CRichEditCtrlEx::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

	if (this->m_nMode & RICHEDITCTRLEX_ADVANCED_EDIT)
	{
		if (this->m_pSelectiveEdit != NULL && this->m_pSelectiveEdit->IsWindowVisible())
			this->m_pSelectiveEdit->Update();

		if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
			this->m_pSelectiveComboBox->Update();
	}

	CRichEditCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CRichEditCtrlEx::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CRichEditCtrl::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	if (this->m_nLenBeforeChange == -1)
		return;

	if (this->m_nLenCutPaste > 0)
	{
		this->RemoveSelectives(this->m_nPosCutPaste, this->m_nLenCutPaste);

		this->m_nPosCutPaste = 0;
		this->m_nLenCutPaste = 0;
	}

	LONG nOffset = this->GetTextLength() - this->m_nLenBeforeChange;
	if (nOffset != 0)
	{
		POSITION POS = this->m_lstSelective.GetHeadPosition();
		while (POS != NULL)
		{
			CSelective* pSelective = this->m_lstSelective.GetNext(POS);
			if (pSelective->m_nPos >= this->m_nPosBeforeChange)
				pSelective->Move(nOffset);
		}
	}

	CSelective* pSelective = this->GetSelective(this->m_nPosBeforeChange, TRUE);
	LONG nStart = 0, nClose = 0;
	this->GetSel(nStart, nClose);
	this->SetSel(this->m_nPosBeforeChange, (pSelective != NULL) ? pSelective->m_nPos : this->GetTextLength());
	this->SetSelectionCharFormat(m_cfNormal);
	this->SetSel(nStart, nClose);
	this->EmptyUndoBuffer();
}

void CRichEditCtrlEx::OnProtected(NMHDR* pNMHDR, LRESULT* pResult) 
{
	ENPROTECTED* pEP = (ENPROTECTED*) pNMHDR;

	TRACE(_T("CALL CRichEditCtrlEx::OnProtected(), MSG = 0x%0X\n"), pEP->msg);

	*pResult = 0;

	if (this->m_lstSelective.GetCount() == 0)
	{
		this->m_nLenBeforeChange = -1;

		static BOOL bCutPaste = FALSE;
		switch (pEP->msg)
		{
		case WM_CUT:
			if (!bCutPaste)
				bCutPaste = TRUE;
			break;
		case WM_PASTE:
			if (!bCutPaste)
			{
				bCutPaste = FALSE;

				this->PasteSpecial(CF_TEXT);

				*pResult = TRUE;
			}
			break;
		case WM_MOUSEMOVE:
			break;
		default:
			bCutPaste = FALSE;
			break;
		}

		return;
	}

	POSITION POS = this->m_lstSelective.GetHeadPosition();
	while (POS != NULL)
	{
		CSelective* pSelective = this->m_lstSelective.GetNext(POS);
		if (pSelective->OnSelective(pEP->chrg.cpMin, FALSE) || pSelective->OnSelective(pEP->chrg.cpMax, FALSE))
		{
			*pResult = TRUE;
			return;
		}
	}

	this->m_nLenBeforeChange = this->GetTextLength();
	switch (pEP->msg)
	{
	case WM_CUT:
		{
			this->m_nPosBeforeChange = pEP->chrg.cpMin;
			this->m_nPosCutPaste = pEP->chrg.cpMin;
			this->m_nLenCutPaste = pEP->chrg.cpMax - pEP->chrg.cpMin;
		}
		break;
	case WM_PASTE:
		if (this->m_nLenCutPaste > 0)
		{
			this->RemoveSelectives(this->m_nPosCutPaste, this->m_nLenCutPaste);

			POSITION POS = this->m_lstSelective.GetHeadPosition();
			while (POS != NULL)
			{
				CSelective* pSelective = this->m_lstSelective.GetNext(POS);
				if (pSelective->m_nPos >= this->m_nPosCutPaste)
					pSelective->Move(-this->m_nLenCutPaste);
			}

			this->m_nLenBeforeChange -= this->m_nLenCutPaste;
			this->m_nPosBeforeChange = pEP->chrg.cpMin;
			if (pEP->chrg.cpMin > this->m_nPosCutPaste)
				this->m_nPosBeforeChange -= this->m_nLenCutPaste;

			this->m_nPosCutPaste = 0;
			this->m_nLenCutPaste = 0;

//			this->PasteSpecial(CF_TEXT);	// ???
//			*pResult = TRUE;
		}
		else
		{
			this->m_nPosBeforeChange = pEP->chrg.cpMin;
			this->RemoveSelectives(pEP->chrg.cpMin, pEP->chrg.cpMax - pEP->chrg.cpMin);
		}
		break;
	case WM_CHAR:
	case WM_KEYDOWN:
	case WM_SETTEXT:
		{
			this->m_nPosBeforeChange = pEP->chrg.cpMin;
			this->RemoveSelectives(pEP->chrg.cpMin, pEP->chrg.cpMax - pEP->chrg.cpMin);
		}
		break;
	case WM_MOUSEMOVE:
		break;
	case EM_SETCHARFORMAT:
		break;
	default:
		{
			CString strMessage;
			strMessage.Format(_T("MSG: 0x%0X, WPARAM: %d, LPARAM: %d, CPMIN: %d, CPMAX: %d"), pEP->msg, pEP->wParam, pEP->lParam, pEP->chrg.cpMin, pEP->chrg.cpMax);
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, strMessage);
		}
		break;
	}

	this->EmptyUndoBuffer();
}

BOOL CRichEditCtrlEx::Initialize(LONG nMode, CRichEditCtrlEx* pTargetCtrl, CSelectiveEdit* pSelectiveEdit, CSelectiveComboBox* pSelectiveComboBox)
{
	this->m_nMode = nMode;
	this->m_pTargetCtrl = pTargetCtrl;
	this->m_pSelectiveEdit = pSelectiveEdit;
	this->m_pSelectiveComboBox = pSelectiveComboBox;

	while (TRUE)
	{
		CString strBuffer;
		this->GetWindowText(strBuffer);
		this->SetWindowText(strBuffer + _T(" TEXT "));
		if (this->GetLineCount() > 1)
		{
			CPoint ptLine1 = this->GetCharPos(this->LineIndex(0));
			CPoint ptLine2 = this->GetCharPos(this->LineIndex(1));
			this->m_nLineHeight = ptLine2.y - ptLine1.y;
			this->SetWindowText(_T(""));
			break;
		}
	}

	if (this->m_pSelectiveComboBox != NULL)
	{
		CRect rec;
		this->m_pSelectiveComboBox->GetClientRect(&rec);
		this->m_nComboBoxHeight = rec.Height();
	}

	this->GetSelectionCharFormat(this->m_cfNormal);
	this->GetSelectionCharFormat(this->m_cfSelective);

	this->m_cfNormal.dwMask = CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE | CFM_STRIKEOUT | CFM_PROTECTED | CFM_SIZE | CFM_COLOR | CFM_FACE | CFM_CHARSET;
	this->m_cfNormal.dwEffects = CFE_PROTECTED;
	this->m_cfNormal.crTextColor = RGB(0, 0, 0);

	this->m_cfSelective.dwMask = this->m_cfNormal.dwMask;
	this->m_cfSelective.dwEffects = CFE_PROTECTED | CFE_UNDERLINE;
	this->m_cfSelective.crTextColor = RGB(0, 0, 255);

	this->SetEventMask(this->GetEventMask() |  (ENM_PROTECTED | ENM_CHANGE));

	return TRUE;
}

BOOL CRichEditCtrlEx::ClearSelectives()
{
	while (!this->m_lstSelective.IsEmpty())
		delete this->m_lstSelective.RemoveHead();

	return TRUE;
}

BOOL CRichEditCtrlEx::RemoveSelectives(LONG nPos, LONG nLen)
{
	POSITION POS = this->m_lstSelective.GetHeadPosition();
	while (POS != NULL)
	{
		POSITION POS1 = POS;
		CSelective* pSelective = this->m_lstSelective.GetNext(POS);
		if (nPos <= pSelective->m_nPos && (nPos + nLen) >= pSelective->m_nPos + pSelective->m_strValue.GetLength())
		{
			this->m_lstSelective.RemoveAt(POS1);
			delete pSelective;
		}
	}

	return TRUE;
}

LONG CRichEditCtrlEx::GetCharFromPos(CPoint point)
{
	if (!::IsWindow(this->m_hWnd))
		return -1;

	POINTL lpt;
	lpt.x = point.x;
	lpt.y = point.y;

	return (LONG)::SendMessage(this->m_hWnd, EM_CHARFROMPOS, 0, (LPARAM) &lpt);
}

CSelective* CRichEditCtrlEx::GetSelective(LONG nPos, BOOL bRight)
{
	if (bRight)
	{
		POSITION POS = this->m_lstSelective.GetHeadPosition();
		while (POS != NULL)
		{
			CSelective* pSelective = this->m_lstSelective.GetNext(POS);
			if (nPos <= pSelective->m_nPos)
				return pSelective;
		}
	}
	else
	{
		POSITION POS = this->m_lstSelective.GetTailPosition();
		while (POS != NULL)
		{
			CSelective* pSelective = this->m_lstSelective.GetPrev(POS);
			if (nPos >= pSelective->m_nPos + pSelective->m_strValue.GetLength())
				return pSelective;
		}
	}

	return NULL;
}

CSelective* CRichEditCtrlEx::GetSelective(CSelective* pSelective, BOOL bRight)
{
	POSITION POS = this->m_lstSelective.Find(pSelective);
	if (POS != NULL)
	{
		if (bRight)
		{
			this->m_lstSelective.GetNext(POS);
			if (POS != NULL)
				return this->m_lstSelective.GetAt(POS);
		}
		else
		{
			this->m_lstSelective.GetPrev(POS);
			if (POS != NULL)
				return this->m_lstSelective.GetAt(POS);
		}
	}

	return NULL;
}

BOOL CRichEditCtrlEx::SelectiveSet()
{
	LONG nStart = 0;
	LONG nClose = 0;
	this->GetSel(nStart, nClose);

	CSelective* pSelective = new CSelective;
	pSelective->m_nPos = nStart;
	pSelective->m_strValue = this->GetSelText();
	pSelective->m_Selectives.Add(pSelective->m_strValue);

	POSITION POS1 = NULL;
	POSITION POS = this->m_lstSelective.GetHeadPosition();
	while (POS != NULL)
	{
		POS1 = POS;
		CSelective* pSelective = this->m_lstSelective.GetNext(POS);
		if (nClose <= pSelective->m_nPos)
			break;
	}

	if (POS1 == NULL)
		this->m_lstSelective.AddHead(pSelective);
	else if (POS == NULL)
		this->m_lstSelective.AddTail(pSelective);
	else
		this->m_lstSelective.InsertBefore(POS1, pSelective);

	this->ShowUnderline(pSelective, TRUE);

	return TRUE;
}

BOOL CRichEditCtrlEx::SelectiveEdit()
{
	if (this->m_pSelectiveMouse == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	if (this->m_pSelectiveEdit == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	this->m_pSelectiveEdit->m_pCtrl = this;

	::SetWindowLong(this->m_pSelectiveEdit->m_hWnd, GWL_USERDATA, (LONG) this->m_pSelectiveMouse);

	CString strValue;
	for (LONG i = 0; i < this->m_pSelectiveMouse->m_Selectives.GetSize(); i++)
	{
		strValue += this->m_pSelectiveMouse->m_Selectives.ElementAt(i);
		strValue += _T("\r\n");
	}

	CRect recCtrl;
	this->GetClientRect(&recCtrl);
	recCtrl.bottom -= this->m_nLineHeight;

	CPoint pt = this->GetCharPos(this->m_pSelectiveMouse->m_nPos);
	if (!recCtrl.PtInRect(pt))
	{
		LONG nLine = this->LineFromChar(this->m_pSelectiveMouse->m_nPos) - this->GetFirstVisibleLine() - 3;
		if (nLine != 0)
			this->LineScroll(nLine);

		pt = this->GetCharPos(this->m_pSelectiveMouse->m_nPos);
	}

	this->ClientToScreen(&pt);
	this->GetParent()->ScreenToClient(&pt);

	CRect recParent;
	this->GetParent()->GetClientRect(&recParent);

	LONG nReservedSpace = 10;

	CSize theSize(300, 200);
	if (pt.y + this->m_nLineHeight + theSize.cy > recParent.bottom)
		pt.y -= theSize.cy;
	else
		pt.y += this->m_nLineHeight;

	if (pt.x + theSize.cx + nReservedSpace > recParent.right)
		theSize.cx = recParent.right - pt.x - nReservedSpace;

	this->m_pSelectiveEdit->SetWindowPos(&wndTop, pt.x, pt.y, theSize.cx, theSize.cy, SWP_SHOWWINDOW);
	this->m_pSelectiveEdit->SetWindowText(strValue);
	this->m_pSelectiveEdit->SetFocus();

	return TRUE;
}

BOOL CRichEditCtrlEx::SelectiveDelete()
{
	if (this->m_pSelectiveMouse == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	this->ShowUnderline(this->m_pSelectiveMouse, FALSE);

	POSITION POS = this->m_lstSelective.Find(this->m_pSelectiveMouse);
	if (POS != NULL)
	{
		delete this->m_pSelectiveMouse;

		this->m_lstSelective.RemoveAt(POS);
	}

	this->m_pSelectiveMouse = NULL;

	return TRUE;
}

BOOL CRichEditCtrlEx::ParagraphAnalyse(CString& strValue, CList<LONG, LONG>& lstParagraphStart)
{
	LONG i = 0;
	LONG nPos = 0;
	while ((nPos = strValue.Find('\n', nPos)) != -1)
	{
		lstParagraphStart.AddTail(i);
		i = ++nPos;
	}

	if (i < strValue.GetLength())
		lstParagraphStart.AddTail(i);

	return TRUE;
}

BOOL CRichEditCtrlEx::FormatLeft()
{
	CList<LONG, LONG> lstParagraphStart;

	CString strBuffer;
	this->GetText(strBuffer);
	this->ParagraphAnalyse(strBuffer, lstParagraphStart);

	LONG nOffset = 0;
	LONG nStart = 0, nClose = 0;
	while (lstParagraphStart.GetCount() > 0)
	{
		nStart = nClose = lstParagraphStart.RemoveHead();
		while (strBuffer.GetAt(nClose) == ' ')
			nClose++;

		this->SetSel(nStart - nOffset, nClose - nOffset);
		this->ReplaceSel(_T(""));

		nOffset += nClose - nStart;
	}

	return TRUE;
}

BOOL CRichEditCtrlEx::FormatSpace()
{
	CList<LONG, LONG> lstParagraphStart;

	CString strBuffer;
	this->GetText(strBuffer);
	this->ParagraphAnalyse(strBuffer, lstParagraphStart);

	LONG nOffset = 0;
	LONG nStart = 0, nClose = 0;
	while (lstParagraphStart.GetCount() > 0)
	{
		nStart = nClose = lstParagraphStart.RemoveHead();
		while (strBuffer.GetAt(nClose) == ' ')
			nClose++;

		this->SetSel(nStart - nOffset, nClose - nOffset);
		this->ReplaceSel(_T("    "));

		nOffset += nClose - nStart - 4;
	}

	return TRUE;
}

BOOL CRichEditCtrlEx::FormatNumber()
{
	CList<LONG, LONG> lstParagraphStart;

	CString strBuffer;
	this->GetText(strBuffer);
	this->ParagraphAnalyse(strBuffer, lstParagraphStart);

	LONG nOrder = 1;
	CString strOrder;

	LONG nOffset = 0;
	LONG nStart = 0;
	while (lstParagraphStart.GetCount() > 0)
	{
		nStart = lstParagraphStart.RemoveHead();
		while (strBuffer.GetAt(nStart) == ' ')
			nStart++;

		strOrder.Format(_T("%d. "), nOrder++);
		if (strOrder == strBuffer.Mid(nStart, strOrder.GetLength()))
			continue;

		this->SetSel(nStart + nOffset, nStart + nOffset);
		this->ReplaceSel(strOrder);
		nOffset += strOrder.GetLength();
	}

	return TRUE;
}

BOOL CRichEditCtrlEx::ShowUnderline(CSelective* pSelective, BOOL bShowUnderline)
{
	CHARFORMAT* pCF = bShowUnderline ? &this->m_cfSelective : &this->m_cfNormal;
	if (pSelective != NULL)
	{
		LONG nEnd = pSelective->m_nPos + pSelective->m_strValue.GetLength();
		this->SetSel(pSelective->m_nPos, nEnd);
		this->SetSelectionCharFormat(*pCF);	
		this->SetSel(nEnd, nEnd);
	}
	else
	{
		POSITION POS = this->m_lstSelective.GetHeadPosition();
		while (POS != NULL)
		{
			CSelective* pSelective = this->m_lstSelective.GetNext(POS);

			LONG nEnd = pSelective->m_nPos + pSelective->m_strValue.GetLength();
			this->SetSel(pSelective->m_nPos, nEnd);
			this->SetSelectionCharFormat(*pCF);	
			this->SetSel(nEnd, nEnd);
		}
	}

	this->EmptyUndoBuffer();

	return TRUE;
}

BOOL CRichEditCtrlEx::ShowSelective(CSelective* pSelective)
{
	if (this->m_pSelectiveComboBox == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	this->m_pSelectiveComboBox->m_pCtrl = this;

	::SetWindowLong(this->m_pSelectiveComboBox->m_hWnd, GWL_USERDATA, (LONG) pSelective);

	this->m_pSelectiveComboBox->ResetContent();
	for (LONG i = 0; i < pSelective->m_Selectives.GetSize(); i++)
	{
		if (pSelective->m_strValue == pSelective->m_Selectives.ElementAt(i))
			break;
	}
	if (i == pSelective->m_Selectives.GetSize())
		this->m_pSelectiveComboBox->AddString(pSelective->m_strValue);
	for (i = 0; i < pSelective->m_Selectives.GetSize(); i++)
		this->m_pSelectiveComboBox->AddString(pSelective->m_Selectives.ElementAt(i));

	CRect recCtrl;
	this->GetClientRect(&recCtrl);
	recCtrl.bottom -= this->m_nLineHeight;

	CPoint pt = this->GetCharPos(pSelective->m_nPos);
	if (!recCtrl.PtInRect(pt))
	{
		LONG nLine = this->LineFromChar(pSelective->m_nPos) - this->GetFirstVisibleLine() - 3;
		if (nLine != 0)
			this->LineScroll(nLine);

		pt = this->GetCharPos(pSelective->m_nPos);
	}

	this->ClientToScreen(&pt);
	this->GetParent()->ScreenToClient(&pt);

	CRect recParent;
	this->GetParent()->GetClientRect(&recParent);

	CSize theSize(0, this->m_nComboBoxHeight);

	CPoint pt1 = this->GetCharPos(pSelective->m_nPos + pSelective->m_strValue.GetLength());
	this->ClientToScreen(&pt1);
	this->GetParent()->ScreenToClient(&pt1);

	LONG nReservedSpace = 10;

	theSize.cx = pt1.x - pt.x + 24;
	if (pt1.y != pt.y || (pt.x + theSize.cx + nReservedSpace) > recParent.right)
		theSize.cx = recParent.right - pt.x - nReservedSpace;

	this->m_pSelectiveComboBox->SetWindowPos(&wndTop, pt.x, pt.y, theSize.cx, theSize.cy, SWP_SHOWWINDOW);
	this->m_pSelectiveComboBox->SetDroppedWidth(recParent.right - pt.x - nReservedSpace);
	this->m_pSelectiveComboBox->SetWindowText(pSelective->m_strValue);
	this->m_pSelectiveComboBox->SetFocus();
	this->m_pSelectiveComboBox->ShowDropDown();

	return TRUE;
}

MRET CRichEditCtrlEx::UpdateSelective()
{
	if (this->m_pSelectiveComboBox == NULL || !this->m_pSelectiveComboBox->IsWindowVisible() && ::GetWindowLong(this->m_pSelectiveComboBox->m_hWnd, GWL_USERDATA) == 0)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	this->m_pSelectiveComboBox->ShowWindow(SW_HIDE);

	CSelective* pSelective = (CSelective*) ::GetWindowLong(this->m_pSelectiveComboBox->m_hWnd, GWL_USERDATA);
	POSITION POS = this->m_lstSelective.Find(pSelective);
	if (POS == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}
	else
	{
		CString strReplace(pSelective->m_strValue);
		this->m_pSelectiveComboBox->GetWindowText(pSelective->m_strValue);
//		while (pSelective->m_strValue.GetLength() < strReplace.GetLength())	// ???
//			pSelective->m_strValue = " " + pSelective->m_strValue;
		if (pSelective->m_strValue != strReplace)
		{
			this->SetEventMask(this->GetEventMask() & ~(ENM_PROTECTED | ENM_CHANGE));

			this->SetSel(pSelective->m_nPos, pSelective->m_nPos + strReplace.GetLength());
			this->ReplaceSel(pSelective->m_strValue);
			this->ShowUnderline(pSelective, TRUE);

			this->SetEventMask(this->GetEventMask() |  (ENM_PROTECTED | ENM_CHANGE));

			LONG nOffset = pSelective->m_strValue.GetLength() - strReplace.GetLength();

			this->m_lstSelective.GetNext(POS);
			while (POS != NULL)
			{
				CSelective* pSelective1 = this->m_lstSelective.GetNext(POS);
				pSelective1->Move(nOffset);
			}
		}
	}

	return ME_OK;
}

MRET CRichEditCtrlEx::UpdateSelectiveEdit()
{
	if (this->m_pSelectiveEdit == NULL || !this->m_pSelectiveEdit->IsWindowVisible() || ::GetWindowLong(this->m_pSelectiveEdit->m_hWnd, GWL_USERDATA) == 0)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	this->m_pSelectiveEdit->ShowWindow(SW_HIDE);

	CSelective* pSelective = (CSelective*) ::GetWindowLong(this->m_pSelectiveEdit->m_hWnd, GWL_USERDATA);
	POSITION POS = this->m_lstSelective.Find(pSelective);
	if (POS == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}
	else
	{
		pSelective->m_Selectives.RemoveAll();

		CString strTXT;
		this->m_pSelectiveEdit->GetWindowText(strTXT);

		LONG nPos = -1;
		while ((nPos = strTXT.Find(_T("\r\n"), 0)) != -1)
		{
			pSelective->m_Selectives.Add(strTXT.Left(nPos));
			strTXT = strTXT.Mid(nPos + 2);
		}

		if (strTXT.GetLength() > 0)
			pSelective->m_Selectives.Add(strTXT);

		if (pSelective->m_Selectives.GetSize() == 0)
			pSelective->m_Selectives.Add(pSelective->m_strValue);
	}

	return ME_OK;
}

BOOL CRichEditCtrlEx::TXTLoad(CString strValue)
{
	if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
		this->m_pSelectiveComboBox->ShowWindow(SW_HIDE);

	this->ClearSelectives();
	this->SetSel(0, -1);
	this->SetSelectionCharFormat(this->m_cfNormal);
	this->ReplaceSel(strValue);
	this->SetSel(0, 0);
	LONG nLine = this->LineFromChar(0) - this->GetFirstVisibleLine();
	if (nLine != 0)
		this->LineScroll(nLine);

	this->EmptyUndoBuffer();

	return TRUE;
}

BOOL CRichEditCtrlEx::TXTPlus(CString strValue, BOOL bCursorPlace)
{
	if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
		this->m_pSelectiveComboBox->Update();

	CString strTXT, strPlus;
	this->GetWindowText(strTXT);
	if (strValue.GetLength() > 0)
	{
		if (bCursorPlace)
		{
			strPlus = strValue + _T("\r\n");
			
			this->ReplaceSel(strPlus);
		}
		else
		{
			if (strTXT.GetLength() > 0 && strTXT.GetAt(strTXT.GetLength() - 1) != '\r' && strTXT.GetAt(strTXT.GetLength() - 1) != '\n')
				strPlus = _T("\r\n");

			strPlus += strValue;

			this->SetSel(strTXT.GetLength(), strTXT.GetLength());
			this->ReplaceSel(strPlus);
			this->SetSel(strTXT.GetLength(), strTXT.GetLength());

			LONG nLine = this->LineFromChar(strTXT.GetLength()) - this->GetFirstVisibleLine() - 3;
			if (nLine != 0)
				this->LineScroll(nLine);
		}
	}

	this->EmptyUndoBuffer();

	return TRUE;
}

BOOL CRichEditCtrlEx::XMLLoad(CString strValue)
{
	if (!(this->m_nMode & (RICHEDITCTRLEX_ADVANCED | RICHEDITCTRLEX_ADVANCED_EDIT)))
		return FALSE;

	if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
		this->m_pSelectiveComboBox->ShowWindow(SW_HIDE);

	this->SetEventMask(this->GetEventMask() & ~(ENM_PROTECTED | ENM_CHANGE));

	this->ClearSelectives();
	this->SetWindowText(_T(""));

	this->SetEventMask(this->GetEventMask() |  (ENM_PROTECTED | ENM_CHANGE));

	BOOL bSuccess = TRUE;
	if (strValue.GetLength() > 0)
		bSuccess = this->XMLPlus(strValue);

	return bSuccess;
}

BOOL CRichEditCtrlEx::XMLPlus(CString strValue, BOOL bCursorPlace)	// ???
{
	if (!(this->m_nMode & (RICHEDITCTRLEX_ADVANCED | RICHEDITCTRLEX_ADVANCED_EDIT)))
		return FALSE;

	if (this->m_pSelectiveComboBox != NULL && this->m_pSelectiveComboBox->IsWindowVisible())
		this->m_pSelectiveComboBox->Update();

	BOOL bSuccess = TRUE;
	if (strValue.GetLength() > 0)
	{
		CString strTXT, strXML;
		this->GetWindowText(strTXT);

		CList<CSelective*, CSelective*>	lstSelective;
		MRET rc = this->XMLParse(strValue, strXML, &lstSelective);
		if (rc != ME_OK)
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, strValue);

			bSuccess = FALSE;
			while (!lstSelective.IsEmpty())
				delete lstSelective.RemoveHead();
		}
		else
		{
			this->SetEventMask(this->GetEventMask() & ~(ENM_PROTECTED | ENM_CHANGE));

			this->m_lstSelective.AddTail(&lstSelective);
			this->SetWindowText(strTXT + strXML);
			this->SetSel(0, -1);
			this->SetSelectionCharFormat(this->m_cfNormal);
			this->ShowUnderline(NULL, TRUE);
			this->SetSel(strTXT.GetLength(), strTXT.GetLength());

			LONG nLine = this->LineFromChar(strTXT.GetLength()) - this->GetFirstVisibleLine() - 3;
			if (nLine != 0)
				this->LineScroll(nLine);

			this->SetEventMask(this->GetEventMask() |  (ENM_PROTECTED | ENM_CHANGE));
		}
	}

	this->EmptyUndoBuffer();

	return bSuccess;
}

MRET CRichEditCtrlEx::XMLParse(CString strValue, CString& strResult, CList<CSelective*, CSelective*>* plstSelective)
{
	CString strTXT;
	this->GetWindowText(strTXT);
	if (strTXT.GetLength() > 0 && strTXT.GetAt(strTXT.GetLength() - 1) != '\r' && strTXT.GetAt(strTXT.GetLength() - 1) != '\n')
		strResult = _T("\r\n");

	CXmlParse XmlParse;
	MRET rc = XmlParse.LoadXml(strValue);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, rc, strValue);
	}

	CSelective* pSelective = NULL;

	IXMLDOMNode* pChild = NULL;
	rc = XmlParse.GetFirstChildNode(NULL, &pChild);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	while (pChild != NULL)
	{
		CString strName, strValue;
		rc = XmlParse.GetNodeName(pChild, strName);
		if (rc != ME_OK)
		{
			if (pChild) pChild->Release();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		strName.MakeUpper();
		if (strName == _T("#TEXT"))
			;
		else if (strName == _T("TEXT"))
		{
			rc = XmlParse.GetNodeValue(pChild, strValue);
			if (rc != ME_OK)
			{
				if (pChild) pChild->Release();
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}

			if (strValue.GetLength() > 1 && strValue.GetAt(0) == '&' && strValue.GetAt(strValue.GetLength() - 1) == '&')
				strValue = strValue.Mid(1, strValue.GetLength() - 2);

			strValue.Replace(_T("\n"), _T("\r\n"));
			strValue.Replace(_T("\r\r\n"), _T("\r\n"));

			strResult += strValue;
		}
		else if (strName == _T("OPTION"))
		{
			pSelective = new CSelective;
			rc = pSelective->Load(&XmlParse, pChild);
			if (rc != ME_OK)
			{
				delete pSelective;
				if (pChild) pChild->Release();
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}

			plstSelective->AddTail(pSelective);
			pSelective->m_nPos = strTXT.GetLength() + strResult.GetLength();
			strResult += pSelective->m_strValue;
		}
		else
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, strName);
		}

		IXMLDOMNode* pSibling = NULL;

		rc = XmlParse.GetNextSiblingNode(pChild, &pSibling);
		if (rc != ME_OK)
		{
			if (pChild) pChild->Release();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		if (pChild) pChild->Release();

		pChild = pSibling;
	}

	return ME_OK;
}

MRET CRichEditCtrlEx::XMLBuild(CString& strValue)
{
	CString strTXT, strBuffer;
	this->GetText(strTXT);

	LONG nPos = 0;

	IXMLDOMNode* pRoot = NULL;
	IXMLDOMNode* pNode = NULL;
	IXMLDOMNode* pSubNode = NULL;

	CXmlParse XmlParse;
	MRET rc = XmlParse.LoadXml();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	pRoot = XmlParse.SetNode(NULL, _T("ROOT"), _T(""));
	if (pRoot == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	POSITION POS = this->m_lstSelective.GetHeadPosition();
	while (POS != NULL)
	{
		CSelective* pSelective = this->m_lstSelective.GetNext(POS);
		if (nPos < pSelective->m_nPos)
		{
			strBuffer = strTXT.Mid(nPos, pSelective->m_nPos - nPos);
			XmlParse.AddSpace(pRoot, _T("\n  "));
			pNode = XmlParse.SetNode(pRoot, _T("TEXT"), strBuffer);
			if (pNode != NULL)
				pNode->Release();
			else
			{
				pRoot->Release();
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
			}
		}

		nPos = pSelective->m_nPos;

		XmlParse.AddSpace(pRoot, _T("\n  "));
		pNode = XmlParse.SetNode(pRoot, _T("OPTION"), pSelective->m_strValue);
		if (pNode == NULL)
		{
			pRoot->Release();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		for (LONG i = 0; i < pSelective->m_Selectives.GetSize(); i++)
		{
			pSubNode = XmlParse.SetNode(pNode, _T("ITEM"), pSelective->m_Selectives.ElementAt(i));
			if (pSubNode != NULL)
				pSubNode->Release();
			else
			{
				pNode->Release();
				pRoot->Release();
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
			}
		}

		pNode->Release();

		nPos += pSelective->m_strValue.GetLength();
	}

	if (nPos < strTXT.GetLength())
	{
		strBuffer = strTXT.Mid(nPos, strTXT.GetLength() - nPos);
		XmlParse.AddSpace(pRoot, _T("\n  "));
		pNode = XmlParse.SetNode(pRoot, _T("TEXT"), strBuffer);
		if (pNode != NULL)
			pNode->Release();
		else
		{
			pRoot->Release();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}
	}

	XmlParse.AddSpace(pRoot, _T("\n"));

	pRoot->Release();

	rc = XmlParse.SaveXml(strValue);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	return ME_OK;
}

BOOL CRichEditCtrlEx::GetText(CString& strValue)
{
	this->GetWindowText(strValue);

	strValue.TrimRight();
	strValue.Replace(_T("\n"), _T("\r\n"));
	strValue.Replace(_T("\r\r\n"), _T("\r\n"));

	return TRUE;
}
