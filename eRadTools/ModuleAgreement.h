// ModuleAgreement.h: interface for the CModuleAgreement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULEAGREEMENT_H__DF83A056_365E_4BCD_B34D_C67D5D183F80__INCLUDED_)
#define AFX_MODULEAGREEMENT_H__DF83A056_365E_4BCD_B34D_C67D5D183F80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

//////////////////////////////////////////////////////////////////////
// eRadAgreement.dll

typedef MRET	(*AGREEMENT_Print)(LPVOID lpvWorklist);

class CModuleAgreement  
{
private:
	HMODULE					m_hModule;

private:
	MRET					LoadModule();

private:
	AGREEMENT_Print			m_pPrint;

public:
	MRET					Print(LPVOID lpvWorklist);

public:
	CModuleAgreement();
	virtual ~CModuleAgreement();
};

#endif // !defined(AFX_MODULEAGREEMENT_H__DF83A056_365E_4BCD_B34D_C67D5D183F80__INCLUDED_)
