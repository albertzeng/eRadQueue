// ModuleQueueCall.cpp: implementation of the CModuleQueueCall class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModuleQueueCall.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleQueueCall::CModuleQueueCall()
{
	this->m_hModule				= NULL;

	this->m_pOpenConfiguration	= NULL;
	this->m_pSetQueueCallProc	= NULL;
	this->m_pStartQueueCall		= NULL;
	this->m_pCloseQueueCall		= NULL;
	this->m_pQueueCallComplete  = NULL;
	this->LoadModule();
}

CModuleQueueCall::~CModuleQueueCall()
{
	if (this->m_pCloseQueueCall != NULL)
		this->m_pCloseQueueCall();

	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleQueueCall::LoadModule()
{
	HMODULE hModule = ::LoadLibrary(_T("eRadQueueCall.DLL"));
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("eRadQueueCall.DLL"));
	}

	this->m_hModule					= hModule;
	this->m_pOpenConfiguration		= (QUEUECALL_OpenConfiguration)	GetProcAddress(this->m_hModule, "API_OpenConfiguration");
	this->m_pSetQueueCallProc		= (QUEUECALL_SetQueueCallProc)	GetProcAddress(this->m_hModule, "API_SetQueueCallProc");
	this->m_pStartQueueCall			= (QUEUECALL_StartQueueCall)	GetProcAddress(this->m_hModule, "API_StartQueueCall");
	this->m_pCloseQueueCall			= (QUEUECALL_CloseQueueCall)	GetProcAddress(this->m_hModule, "API_CloseQueueCall");
	this->m_pQueueCallComplete      = (QUEUECALL_QueueCallComplete) GetProcAddress(this->m_hModule, "API_QueueCallComplete");
	return ME_OK;
}

MRET CModuleQueueCall::QueueCallComplete(LONG nQueueIndex)
{
	if (this->m_pQueueCallComplete == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}
	
	return this->m_pQueueCallComplete(nQueueIndex);
}

MRET CModuleQueueCall::OpenConfiguration()
{
	if (this->m_pOpenConfiguration == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pOpenConfiguration();
}

MRET CModuleQueueCall::SetQueueCallProc(CALLBACK_QUEUE_CALL_PROC lpcbQueueCallProc)
{
	if (this->m_pSetQueueCallProc == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pSetQueueCallProc(lpcbQueueCallProc);
}

MRET CModuleQueueCall::StartQueueCall(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName)
{
	if (this->m_pStartQueueCall == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pStartQueueCall(nDoctorIndex, nDoctorDepartment, nDoctorPrivilege, strDoctorCode, strDoctorName);
}

MRET CModuleQueueCall::CloseQueueCall()
{
	if (this->m_pCloseQueueCall == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pCloseQueueCall();
}
