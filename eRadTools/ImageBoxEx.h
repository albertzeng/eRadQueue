#if !defined(AFX_IMAGEBOXEX_H__03839345_0D9C_4D94_9122_F936DBDF3578__INCLUDED_)
#define AFX_IMAGEBOXEX_H__03839345_0D9C_4D94_9122_F936DBDF3578__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageBoxEx.h : header file
//

#define	SET_IMAGEBOX_PARAMETER(MEMBER, ALIAN, CX, CY, ICON1, ICON2, ICON3)	\
	{																\
		HICON hIcon1 = (HICON) LoadImage(NULL, (ICON1), IMAGE_ICON, (CX), (CY), LR_LOADFROMFILE);	\
		HICON hIcon2 = (HICON) LoadImage(NULL, (ICON2), IMAGE_ICON, (CX), (CY), LR_LOADFROMFILE);	\
		HICON hIcon3 = (HICON) LoadImage(NULL, (ICON3), IMAGE_ICON, (CX), (CY), LR_LOADFROMFILE);	\
		if (hIcon1 == NULL || hIcon2 == NULL || hIcon3 == NULL)		\
		{															\
			LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, GetLastError());	\
		}															\
		CString strBuffer;											\
		MEMBER.GetWindowText(strBuffer);							\
		LONG nPos = strBuffer.Find(_T("\n"));						\
		if (nPos != -1)												\
		{															\
			MEMBER.SetWindowText(strBuffer.Left(nPos));				\
			MEMBER.SetToolTip(strBuffer.Mid(nPos + 1));				\
		}															\
		MEMBER.SetIcon(hIcon3, hIcon2, hIcon1);						\
		MEMBER.SetAlign(ALIAN);										\
	}																\


/////////////////////////////////////////////////////////////////////////////
// CImageBoxEx window

class CImageBoxEx : public CButton
{
public:
	enum
	{
		E_ALIGN_ON = 0,
		E_ALIGN_NONE,
		E_ALIGN_V_BOTTOM
	};

	enum
	{
		E_COLOR_BACK = 0,
		E_COLOR_FORE,
		E_COLOR_BACK_ON,
		E_COLOR_FORE_ON,
		E_COLOR_BACK_FOCUS,
		E_COLOR_FORE_FOCUS,
		E_COLOR_BACK_CHECK,
		E_COLOR_FORE_CHECK,

		E_COLOR_MAX_COUNT
	};

	struct STRUCT_ICONS
	{
		HICON		m_hIcon;
		LONG		m_nIconX;
		LONG		m_nIconY;
	};

public:
	BOOL			m_bIsChecked;
	BOOL			m_bIsPressed;
	BOOL			m_bIsFocused;
	BOOL			m_bIsMouseActive;
	BOOL			m_bIsTransparent;
	CToolTipCtrl*	m_pToolTipCtrl;
	CBitmap*		m_pbmRestore;
	CDC				m_dcBackground;
	CBitmap			m_bmBackground;
	LONG			m_nAlign;
	HCURSOR			m_hCursor;
	COLORREF		m_rgbColors[E_COLOR_MAX_COUNT];
	STRUCT_ICONS	m_Icons[3];

public:
	BOOL			FreeResources();
	BOOL			ResetMouseActive();
	BOOL			CreateToolTipCtrl();
	BOOL			SetToolTip(LONG nIDValue, BOOL bActivate = TRUE);
	BOOL			SetToolTip(LPCTSTR lpValue, BOOL bActivate = TRUE);
	BOOL			ResetColors(BOOL bRepaint = TRUE);
	BOOL			SetColor(BYTE nColorIndex, COLORREF rgbColor, BOOL bRepaint = TRUE);
	BOOL			GetColor(BYTE nColorIndex, COLORREF& rgbColor);
	BOOL			SetIcon(HICON hIconIn, HICON hIconOut, HICON hIconDisable);
	BOOL			SetIcon(LONG nIDIconIn, LONG nIDIconOut, LONG nIDIconDisable);
	BOOL			SetAlign(LONG nAlign, BOOL bRepaint = TRUE);
	BOOL			SetCheck(BOOL bCheck, BOOL bRepaint = TRUE);
	BOOL			DrawBackground(CDC* pDC);
	BOOL			DrawTransparent(BOOL bRepaint = FALSE);
	BOOL			DrawPrepare(CRect recRange, LONG nIconX, LONG nIconY, CRect& recImage, CRect& recCaption);
	BOOL			DrawIcon(CDC* pDC, CRect recRange, CRect& recCaption);

// Construction
public:
	CImageBoxEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageBoxEx)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageBoxEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CImageBoxEx)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnCancelMode();
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnSysColorChange();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetStyle(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEBOXEX_H__03839345_0D9C_4D94_9122_F936DBDF3578__INCLUDED_)
