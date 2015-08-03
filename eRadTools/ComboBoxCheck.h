#if !defined(AFX_COMBOBOXCHECK_H__187CECD8_1C56_4D67_B448_CB8C38542201__INCLUDED_)
#define AFX_COMBOBOXCHECK_H__187CECD8_1C56_4D67_B448_CB8C38542201__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboBoxCheck.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboBoxCheck window

class CComboBoxCheck : public CComboBox
{
protected:
	CUIntArray	m_aCheck;
	HWND		m_hListBox;
	BOOL		m_bSetHeight;
	BOOL		m_bTextUpdated;
	CString		m_strWindowText;

protected:
	BOOL		m_bSaveToFile;
	CString		m_strName;
	CString		m_strSaveValue;
	CString		m_strSubKey;
	CString		m_strFileName;

protected:
	BOOL		RecalculateWindowText();
	BOOL		UpdateRegistry(BOOL bReadWrite);	//TRUE: Write, FALSE: Read

public:
	BOOL		SelectAll(BOOL bCheck = FALSE);
	BOOL		SetCheck(INT nIndex, BOOL bCheck);
	BOOL		GetCheck(INT nIndex);
	INT			GetSelectCount();
	BOOL		LoadSave(LPCTSTR lpName, BOOL bSaveToFile, LPCTSTR lpFileName, LPCTSTR lpSubKey);

// Construction
public:
	CComboBoxCheck();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBoxCheck)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComboBoxCheck();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComboBoxCheck)
	afx_msg void OnDestroy();
	afx_msg void OnDropdown();
	afx_msg LRESULT OnCtlColorListBox(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetText(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetTextLength(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOXCHECK_H__187CECD8_1C56_4D67_B448_CB8C38542201__INCLUDED_)
