// ModuleViewer.cpp: implementation of the CModuleViewer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModuleViewer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleViewer::CModuleViewer()
{
	this->m_hModule				= NULL;

	this->m_pSetParameter		= NULL;
	this->m_pOpenConfiguration	= NULL;
	this->m_pStart				= NULL;
	this->m_pClose				= NULL;
	this->m_pPACSOpen			= NULL;
	this->m_pPACSFilm			= NULL;
	this->m_pLocalPACSOpen		= NULL;
	this->m_pLocalPACSFilm		= NULL;

	this->m_pSendImages			= NULL;
	this->m_pOpenLocalPACS		= NULL;

	this->LoadModule();
}

CModuleViewer::~CModuleViewer()
{
	if (this->m_pClose != NULL)
		this->m_pClose();

	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleViewer::LoadModule()
{
	HMODULE hModule = ::LoadLibrary(_T("eRadViewer.DLL"));
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("eRadLoadSaveImage.DLL"));
	}

	this->m_hModule			= hModule;

	this->m_pSetParameter		= (VIEWER_SetParameter)		GetProcAddress(this->m_hModule, "API_SetParameter");
	this->m_pOpenConfiguration	= (VIEWER_OpenConfiguration)GetProcAddress(this->m_hModule, "API_OpenConfiguration");
	this->m_pStart				= (VIEWER_Start)			GetProcAddress(this->m_hModule, "API_Start");
	this->m_pClose				= (VIEWER_Close)			GetProcAddress(this->m_hModule, "API_Close");
	this->m_pPACSOpen			= (VIEWER_PACSOpen)			GetProcAddress(this->m_hModule, "API_PACSOpen");
	this->m_pPACSFilm			= (VIEWER_PACSFilm)			GetProcAddress(this->m_hModule, "API_PACSFilm");
	this->m_pLocalPACSOpen		= (VIEWER_LocalPACSOpen)	GetProcAddress(this->m_hModule, "API_LocalPACSOpen");
	this->m_pLocalPACSFilm		= (VIEWER_LocalPACSFilm)	GetProcAddress(this->m_hModule, "API_LocalPACSFilm");
	this->m_pSendImages			= (VIEWER_SendImages)		GetProcAddress(this->m_hModule, "API_SendImages");
	this->m_pOpenLocalPACS		= (VIEWER_OpenLocalPACS)	GetProcAddress(this->m_hModule, "API_OpenLocalPACS");

	return ME_OK;
}

MRET CModuleViewer::SetParameter(CString strEISDatabase, CString strAETitle, CString strIPAddress, UINT nPORTNumber)
{
	if (this->m_pSetParameter == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pSetParameter(strEISDatabase, strAETitle, strIPAddress, nPORTNumber);
}

MRET CModuleViewer::OpenConfiguration()
{
	if (this->m_pOpenConfiguration == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pOpenConfiguration();
}

MRET CModuleViewer::Start(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName)
{
	if (this->m_pStart == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pStart(nDoctorIndex, nDoctorDepartment, nDoctorPrivilege, strDoctorCode, strDoctorName);
}

MRET CModuleViewer::Close()
{
	if (this->m_pClose == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pClose();
}

MRET CModuleViewer::PACSOpen(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID)
{
	if (this->m_pPACSOpen == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pPACSOpen(nStudiesIndex, strPatientsID, strAccessionNumber, strStudiesInstUID);
}

MRET CModuleViewer::PACSFilm(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID)
{
	if (this->m_pPACSFilm == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pPACSFilm(nStudiesIndex, strPatientsID, strAccessionNumber, strStudiesInstUID);
}

MRET CModuleViewer::LocalPACSOpen(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID)
{
	if (this->m_pLocalPACSOpen == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pLocalPACSOpen(nStudiesIndex, strPatientsID, strAccessionNumber, strStudiesInstUID);
}

MRET CModuleViewer::LocalPACSFilm(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID)
{
	if (this->m_pLocalPACSFilm == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pLocalPACSFilm(nStudiesIndex, strPatientsID, strAccessionNumber, strStudiesInstUID);
}

MRET CModuleViewer::SendImages(CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID)
{
	if (this->m_pSendImages == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pSendImages(strPatientsID, strAccessionNumber, strStudiesInstUID);
}

MRET CModuleViewer::OpenLocalPACS(LONG nStudiesIndex)
{
	if (this->m_pOpenLocalPACS == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pOpenLocalPACS(nStudiesIndex);
}
