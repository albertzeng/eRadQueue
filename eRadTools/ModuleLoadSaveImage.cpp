// ModuleLoadSaveImage.cpp: implementation of the CModuleLoadSaveImage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModuleLoadSaveImage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleLoadSaveImage::CModuleLoadSaveImage()
{
	this->m_hModule			= NULL;

	this->m_pGetFileFilter	= NULL;
	this->m_pLoadImage		= NULL;
	this->m_pSaveImage		= NULL;

	this->LoadModule();
}

CModuleLoadSaveImage::~CModuleLoadSaveImage()
{
	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleLoadSaveImage::LoadModule()
{
	HMODULE hModule = ::LoadLibrary(_T("eRadLoadSaveImage.DLL"));
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("eRadLoadSaveImage.DLL"));
	}

	this->m_hModule			= hModule;

	this->m_pGetFileFilter	= (LSIMAGE_GetFileFilter)	GetProcAddress(this->m_hModule, "API_GetFileFilter");
	this->m_pLoadImage		= (LSIMAGE_LoadImage)		GetProcAddress(this->m_hModule, "API_LoadImage");
	this->m_pSaveImage		= (LSIMAGE_SaveImage)		GetProcAddress(this->m_hModule, "API_SaveImage");

	return ME_OK;
}

LPCTSTR CModuleLoadSaveImage::GetFileFilter()
{
	if (this->m_pGetFileFilter == NULL)
		return NULL;

	return this->m_pGetFileFilter();
}

BOOL CModuleLoadSaveImage::LoadImage(CString strBMPFileName, CString strLoadFileName)
{
	if (this->m_pLoadImage == NULL)
		return FALSE;

	return this->m_pLoadImage(strBMPFileName, strLoadFileName);
}

BOOL CModuleLoadSaveImage::SaveImage(CString strBMPFileName, CString strSaveFileName)
{
	if (this->m_pSaveImage == NULL)
		return FALSE;

	return this->m_pSaveImage(strBMPFileName, strSaveFileName);
}
