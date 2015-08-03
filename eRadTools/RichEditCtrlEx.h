#if !defined(AFX_RICHEDITCTRLEX_H__03C0672E_AA42_40B9_A49C_A4BF4D560990__INCLUDED_)
#define AFX_RICHEDITCTRLEX_H__03C0672E_AA42_40B9_A49C_A4BF4D560990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RichEditCtrlEx.h : header file
//

#include <afxtempl.h>

#include "XmlParse.h"
#include "ToolsEx.h"

#define	RICHEDITCTRLEX_ADVANCED			0x0001
#define	RICHEDITCTRLEX_ADVANCED_EDIT	0x0002
#define	RICHEDITCTRLEX_REPORT			0x0004
#define	RICHEDITCTRLEX_REPORT_EDIT		0x0008

#define	ID_RICH_UNDO					101
#define	ID_RICH_CUT						102
#define	ID_RICH_COPY					103
#define	ID_RICH_PASTE					104
#define	ID_RICH_CLEAR					105
#define	ID_RICH_SELECT_ALL				106
#define ID_RICH_SET_FONT				107
#define ID_RICH_SELECTIVE_SET			108
#define ID_RICH_SELECTIVE_EDIT			109
#define ID_RICH_SELECTIVE_DELETE		110
#define ID_RICH_FORMAT_LEFT				111
#define ID_RICH_FORMAT_SPACE			112
#define ID_RICH_FORMAT_NUMBER			113
#define ID_RICH_REPORT_COPY				114
#define ID_RICH_REPORT_PASTE			115
#define ID_RICH_REPORT_APPEND			116


class CRichEditCtrlEx;

class CSelective  
{
public:
	LONG			m_nPos;
	CString			m_strValue;
	CStringArray	m_Selectives;

public:
	BOOL			Move(LONG nOffset);
	BOOL			OnSelective(LONG nPos, BOOL bSide);
	MRET			Load(CXmlParse* pXmlParse, IXMLDOMNode* pNode);

public:
	CSelective();
	virtual ~CSelective();
};

/////////////////////////////////////////////////////////////////////////////
// CSelectiveEdit window

class CSelectiveEdit : public CEdit
{
public:
	CRichEditCtrlEx*	m_pCtrl;

public:
	MRET				Update();

// Construction
public:
	CSelectiveEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectiveEdit)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSelectiveEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSelectiveEdit)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CSelectiveComboBox window

class CSelectiveComboBox : public CComboBox
{
public:
	CRichEditCtrlEx*	m_pCtrl;

public:
	MRET				Update();

// Construction
public:
	CSelectiveComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectiveComboBox)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSelectiveComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSelectiveComboBox)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnKillfocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CRichEditCtrlEx window

class CRichEditCtrlEx : public CRichEditCtrl
{
public:
	BOOL				m_bStaticEdge;
	LONG				m_nMode;
	LONG				m_nLineHeight;
	LONG				m_nComboBoxHeight;
	CRichEditCtrlEx*	m_pTargetCtrl;

public:
	LONG				m_nPosBeforeChange;
	LONG				m_nLenBeforeChange;
	LONG				m_nPosCutPaste;		// drag and drop
	LONG				m_nLenCutPaste;		// drag and drop

public:
	CList<CSelective*, CSelective*>	m_lstSelective;
	CSelective*			m_pSelectiveMouse;
	CSelectiveEdit*		m_pSelectiveEdit;
	CSelectiveComboBox*	m_pSelectiveComboBox;

public:
	CHARFORMAT			m_cfNormal;
	CHARFORMAT			m_cfSelective;

public:
	BOOL				Initialize(LONG nMode, CRichEditCtrlEx* pTargetCtrl = NULL, CSelectiveEdit* pSelectiveEdit = NULL, CSelectiveComboBox* pSelectiveComboBox = NULL);
	BOOL				IsSelectiveMode()		{ return (this->m_lstSelective.GetCount() > 0); }
	BOOL				ClearSelectives();
	BOOL				RemoveSelectives(LONG nPos, LONG nLen);
	LONG				GetCharFromPos(CPoint point);
	CSelective*			GetSelective(LONG nPos, BOOL bRight);
	CSelective*			GetSelective(CSelective* pSelective, BOOL bRight);

public:
	BOOL				SelectiveSet();
	BOOL				SelectiveEdit();
	BOOL				SelectiveDelete();
	BOOL				ParagraphAnalyse(CString& strValue, CList<LONG, LONG>& lstParagraphStart);
	BOOL				FormatLeft();
	BOOL				FormatSpace();
	BOOL				FormatNumber();
	BOOL				ShowUnderline(CSelective* pSelective, BOOL bShowUnderline);
	BOOL				ShowSelective(CSelective* pSelective);

public:
	MRET				UpdateSelective();
	MRET				UpdateSelectiveEdit();
	BOOL				TXTLoad(CString strValue);
	BOOL				TXTPlus(CString strValue, BOOL bCursorPlace = FALSE);
	BOOL				XMLLoad(CString strValue);
	BOOL				XMLPlus(CString strValue, BOOL bCursorPlace = FALSE);
	MRET				XMLParse(CString strValue, CString& strResult, CList<CSelective*, CSelective*>* plstSelective);
	MRET				XMLBuild(CString& strValue);
	BOOL				GetText(CString& strValue);

// Construction
public:
	CRichEditCtrlEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichEditCtrlEx)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL SetReadOnly(BOOL bReadOnly = TRUE);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRichEditCtrlEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRichEditCtrlEx)
	afx_msg void OnUndo() { Undo(); }
	afx_msg void OnCut() { Cut(); }
	afx_msg void OnCopy() { Copy(); }
	afx_msg void OnPaste() { PasteSpecial(CF_TEXT); }
	afx_msg void OnClear() { Clear(); }
	afx_msg void OnSelectAll() { SetSel(0, -1); }
	afx_msg void OnSelectiveSet() { SelectiveSet(); };
	afx_msg void OnSelectiveEdit() { SelectiveEdit(); };
	afx_msg void OnSelectiveDelete() { SelectiveDelete(); };
	afx_msg void OnFormatLeft() { FormatLeft(); };
	afx_msg void OnFormatSpace() { FormatSpace(); };
	afx_msg void OnFormatNumber() { FormatNumber(); };
	afx_msg void OnReportCopy() { GetParent()->SendMessage(WM_COMMAND, ID_RICH_REPORT_COPY, 0); };
	afx_msg void OnReportPaste() { GetParent()->SendMessage(WM_COMMAND, ID_RICH_REPORT_PASTE, 0); };
	afx_msg void OnReportAppend() { GetParent()->SendMessage(WM_COMMAND, ID_RICH_REPORT_APPEND, 0); };
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChange();
	afx_msg void OnProtected(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHEDITCTRLEX_H__03C0672E_AA42_40B9_A49C_A4BF4D560990__INCLUDED_)
