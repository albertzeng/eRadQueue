#if !defined(AFX_PAGEMODE0GENERAL_H__49700FF8_5670_4C97_AD64_4C0243EB1103__INCLUDED_)
#define AFX_PAGEMODE0GENERAL_H__49700FF8_5670_4C97_AD64_4C0243EB1103__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageMode0General.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageMode0General dialog

class CPageMode0General : public CPropertyPage
{
	DECLARE_DYNCREATE(CPageMode0General)

// Construction
public:
	CPageMode0General();
	~CPageMode0General();

// Dialog Data
	//{{AFX_DATA(CPageMode0General)
	enum { IDD = IDD_DIALOG_MODE0_GENERAL };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPageMode0General)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPageMode0General)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEMODE0GENERAL_H__49700FF8_5670_4C97_AD64_4C0243EB1103__INCLUDED_)
