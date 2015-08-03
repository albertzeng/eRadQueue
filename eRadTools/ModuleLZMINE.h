// ModuleLZMINE.h: interface for the CModuleLZMINE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULELZMINE_H__0B579994_5DB5_432B_8E18_490804B29ED7__INCLUDED_)
#define AFX_MODULELZMINE_H__0B579994_5DB5_432B_8E18_490804B29ED7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

//////////////////////////////////////////////////////////////////////
// LzmineDecode.dll.dll

typedef BOOL (*LZMINE_Decode)(CString* pstrInput, CString& strOutput);

class CModuleLZMINE  
{
private:
	HMODULE					m_hModule;

private:
	MRET					LoadModule();

private:
	LZMINE_Decode			m_pDecode;

public:
	BOOL					Decode(CString* pstrInput, CString& strOutput);

public:
	CModuleLZMINE();
	virtual ~CModuleLZMINE();
};

#endif // !defined(AFX_MODULELZMINE_H__0B579994_5DB5_432B_8E18_490804B29ED7__INCLUDED_)
