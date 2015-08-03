// ModuleAgreement.cpp: implementation of the CModuleAgreement class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModuleAgreement.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleAgreement::CModuleAgreement()
{
	this->m_hModule			= NULL;

	this->m_pPrint			= NULL;

	this->LoadModule();
}

CModuleAgreement::~CModuleAgreement()
{
	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleAgreement::LoadModule()
{
	HMODULE hModule = ::LoadLibrary(_T("eRadAgreement.DLL"));
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("eRadAgreement.DLL"));
	}

	this->m_hModule			= hModule;

	this->m_pPrint	= (AGREEMENT_Print)	GetProcAddress(this->m_hModule, "API_Print");

	return ME_OK;
}

MRET CModuleAgreement::Print(LPVOID lpvWorklist)
{
	if (this->m_pPrint == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	if (lpvWorklist == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	return this->m_pPrint(lpvWorklist);
}
