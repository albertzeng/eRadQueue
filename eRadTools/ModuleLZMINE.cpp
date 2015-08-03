// ModuleLZMINE.cpp: implementation of the CModuleLZMINE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModuleLZMINE.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleLZMINE::CModuleLZMINE()
{
	this->m_hModule		= NULL;
	this->m_pDecode		= NULL;

	this->LoadModule();
}

CModuleLZMINE::~CModuleLZMINE()
{
	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleLZMINE::LoadModule()
{
	HMODULE hModule = ::LoadLibrary(_T("LzmineDecode.DLL"));
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("LzmineDecode.DLL"));
	}

	this->m_hModule = hModule;

	this->m_pDecode = (LZMINE_Decode) GetProcAddress(this->m_hModule, "API_DecodeLZMINE");

	return ME_OK;
}

BOOL CModuleLZMINE::Decode(CString* pstrInput, CString& strOutput)
{
	strOutput = *pstrInput;

	CString strBuffer;
	strBuffer = pstrInput->Left(6);
	if (strBuffer != _T("LZMINE"))
		return TRUE;

	if (this->m_pDecode == NULL)
		return FALSE;

	return this->m_pDecode(pstrInput, strOutput);
}
