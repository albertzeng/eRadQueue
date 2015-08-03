// LzmineDecode.h : main header file for the LZMINEDECODE DLL
//

#if !defined(AFX_LZMINEDECODE_H__807CC199_BD19_49AE_BB65_882ADA9789F0__INCLUDED_)
#define AFX_LZMINEDECODE_H__807CC199_BD19_49AE_BB65_882ADA9789F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLzmineDecodeApp
// See LzmineDecode.cpp for the implementation of this class
//

class CLzmineDecodeApp : public CWinApp
{
public:
	CLzmineDecodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLzmineDecodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CLzmineDecodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LZMINEDECODE_H__807CC199_BD19_49AE_BB65_882ADA9789F0__INCLUDED_)
