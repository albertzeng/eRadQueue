// eRadTextToSpeech.h : main header file for the ERADTEXTTOSPEECH DLL
//

#if !defined(AFX_ERADTEXTTOSPEECH_H__65C9759C_C3A4_4D6C_97D2_F904BD29AB8B__INCLUDED_)
#define AFX_ERADTEXTTOSPEECH_H__65C9759C_C3A4_4D6C_97D2_F904BD29AB8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Log.h"
/////////////////////////////////////////////////////////////////////////////
// CERadTextToSpeechApp
// See eRadTextToSpeech.cpp for the implementation of this class
//

class CERadTextToSpeechApp : public CWinApp
{
public:
	CERadTextToSpeechApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CERadTextToSpeechApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CERadTextToSpeechApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERADTEXTTOSPEECH_H__65C9759C_C3A4_4D6C_97D2_F904BD29AB8B__INCLUDED_)
