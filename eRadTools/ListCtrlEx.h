#if !defined(AFX_LISTCTRLEX_H__370E9EE1_3E32_45BE_A30C_DD7A3A5CBA54__INCLUDED_)
#define AFX_LISTCTRLEX_H__370E9EE1_3E32_45BE_A30C_DD7A3A5CBA54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListCtrlEx.h : header file
//


/////////////////////////////////////////////////////////////////////////////
#define WM_REFRESH_LIST_MESSAGE			WM_USER + 1978
#define ID_LIST_COLUMN_BASE				32900

typedef struct _LISTCOLUMN {
	int index;		//Zero-based.
	int fmt;
	int iOrder;		//One-based.
	int compare;
	int cx;

	char name[64];
} LISTCOLUMN, FAR *LPLISTCOLUMN; 

enum ListCompareType
{
	ELCT_INTEGER = 0,
	ELCT_LONG,
	ELCT_DOUBLE,
	ELCT_STRING_CASE,
	ELCT_STRING_NOCASE
};

#define BEGIN_LISTCOLUMNMAP(member, count)									\
	{																				\
		CListCtrlEx *pList = &member;												\
		pList->m_nColumnCount = count;												\
		pList->m_pOrderArray = (LPINT) malloc(count * sizeof(INT));					\
		memset(pList->m_pOrderArray, 0, count * sizeof(INT));						\
		pList->m_pColumnMap = (LPINT) malloc(count * sizeof(INT));					\
		memset(pList->m_pColumnMap, 0, count * sizeof(INT));						\
		pList->m_pColumnArray = (LPLISTCOLUMN) malloc(count * sizeof(LISTCOLUMN));	\
		memset(pList->m_pColumnArray, 0, count * sizeof(LISTCOLUMN));				\
		pList->CreateArrowList();													\
																					\
		int index = 0;																\
		CString strName;

#define LISTCOLUMNMAP(IDS_Name, nWidth, nFormat, nCompare)							\
		{																			\
			if (index < pList->m_nColumnCount)										\
			{																		\
				pList->m_pColumnArray[index].index = index;							\
				pList->m_pColumnArray[index].cx = nWidth;							\
				pList->m_pColumnArray[index].compare = nCompare;					\
				pList->m_pColumnArray[index].fmt = nFormat;							\
				pList->m_pColumnArray[index].iOrder = index + 1;					\
				if (!strName.LoadString(IDS_Name))									\
					strName = "";													\
				strncpy(pList->m_pColumnArray[index].name,							\
						strName,													\
						sizeof(pList->m_pColumnArray[index].name) - 1);				\
				index++;															\
			}																		\
		}

#define END_LISTCOLUMNMAP()															\
		pList->m_nColumnCount = index;												\
		pList->UpdateRegistry(FALSE);												\
		index = 0;																	\
		for (int i = 0; i < pList->m_nColumnCount; i++)								\
		{																			\
			if (pList->m_pColumnArray[i].iOrder > 0)								\
			{																		\
				pList->InsertColumn(index,											\
									pList->m_pColumnArray[i].name,					\
									pList->m_pColumnArray[i].fmt,					\
									pList->m_pColumnArray[i].cx,					\
									i);												\
				pList->m_pColumnMap[i] = index + 1;									\
				pList->m_pOrderArray[pList->m_pColumnArray[i].iOrder - 1] = index;	\
				index++;															\
			}																		\
		}																			\
		if (!pList->m_bHideColumn)													\
		{																			\
			for (int i = 0; i < pList->m_nColumnCount; i++)							\
			{																		\
				if (pList->m_pColumnArray[i].iOrder == 0)							\
				{																	\
					pList->InsertColumn(index,										\
										pList->m_pColumnArray[i].name,				\
										pList->m_pColumnArray[i].fmt,				\
										pList->m_pColumnArray[i].cx,				\
										i);											\
					pList->m_pColumnMap[i] = index + 1;								\
					pList->m_pColumnArray[i].iOrder = index + 1;					\
					pList->m_pOrderArray[pList->m_pColumnArray[i].iOrder - 1] = index;	\
					index++;														\
				}																	\
			}																		\
		}																			\
		pList->SetColumnOrderArray(index, pList->m_pOrderArray);					\
	}


/////////////////////////////////////////////////////////////////////////////
// CListCtrlEx window

class CListCtrlEx : public CListCtrl
{
// Construction
public:
	CListCtrlEx();

// Attributes
public:
	UINT m_nIdentifier;

	BOOL m_bSaveToFile;
	BOOL m_bHideColumn;
	CString m_strName;
	CString m_strSubKey;
	CString m_strFileName;

	int m_nColumnCount;
	int *m_pOrderArray;
	int *m_pColumnMap;
	LISTCOLUMN *m_pColumnArray;

	BOOL	m_bUseFont;
	CFont	m_hFont;

	COLORREF m_aColor[20];
	CStringArray m_aValue;
	BOOL AddColorScheme(CString strValue, COLORREF rgbColor);
	BOOL LoadSave(LPCTSTR lpName, BOOL bSaveToFile, LPCTSTR lpFileName, LPCTSTR lpSubKey, BOOL bHideColumn = TRUE);

private:
	static UINT s_nIdentifier;

	HICON m_hIcon1;
	HICON m_hIcon2;

	int m_nSortColumn;
	int m_nCompareType;

	CImageList m_nArrowList;

// Operations
public:
	void CreateArrowList();
	BOOL UpdateRegistry(BOOL bReadWrite);	//TRUE: Write, FALSE: Read

	int GetColumnCount();
	int GetColumnOrder(int nSubItem);

	BOOL SetItemText(int nItem, int nSubItem, LPCTSTR lpszText);
	BOOL SetItemText(int nItem, int nSubItem, long nValue);

	void SortListCtrl();
	void SortListCtrlNone();

private:
	void OnNotifyNmRClick();

	BOOL RefreshColumn();
	BOOL RefreshList();

	void QuickSort(int nSortColumn);
	void QuickSort(int nFirst, int nLast);
	int Partition(int nFirst, int nLast);
	BOOL SwapRow(int nRow1, int nRow2);
	virtual BOOL CompareBy(CString str1, CString str2);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlEx)
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlEx)
	afx_msg void OnColumnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void OnMenuListColumn(UINT nID);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLEX_H__370E9EE1_3E32_45BE_A30C_DD7A3A5CBA54__INCLUDED_)
