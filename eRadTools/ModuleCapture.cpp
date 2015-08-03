// ModuleCapture.cpp: implementation of the CModuleCapture class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <afxtempl.h>
#include "ModuleCapture.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleCapture::CModuleCapture()
{
	this->m_hModule				= NULL;
	this->m_bOpened				= FALSE;
	this->m_bVideoCapable		= FALSE;
	this->m_bAudioCapable		= FALSE;
	this->m_bCaptureAVI			= FALSE;
	this->m_strAVIFileName		.Empty();

	this->m_pEnumDevice			= NULL;
	this->m_pOpenConfiguration	= NULL;
	this->m_pOpen				= NULL;
	this->m_pClose				= NULL;
	this->m_pGetVideoFormat		= NULL;
	this->m_pVideoOwner			= NULL;
	this->m_pCaptureAVI			= NULL;
	this->m_pCaptureBMP			= NULL;
}

CModuleCapture::~CModuleCapture()
{
	if (this->m_pClose != NULL)
		this->m_pClose();
	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleCapture::LoadModule(LPCTSTR lpName)
{
	this->m_strName = lpName;
	HMODULE hModule = ::LoadLibrary(this->m_strName);
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, this->m_strName);
	}

	this->m_hModule				= hModule;

	this->m_pEnumDevice			= (CAPTURE_EnumDevice)			GetProcAddress(this->m_hModule, "API_EnumDevice");
	this->m_pOpenConfiguration	= (CAPTURE_OpenConfiguration)	GetProcAddress(this->m_hModule, "API_OpenConfiguration");
	this->m_pOpen				= (CAPTURE_Open)				GetProcAddress(this->m_hModule, "API_Open");
	this->m_pClose				= (CAPTURE_Close)				GetProcAddress(this->m_hModule, "API_Close");
	this->m_pGetVideoFormat		= (CAPTURE_GetVideoFormat)		GetProcAddress(this->m_hModule, "API_GetVideoFormat");
	this->m_pVideoOwner			= (CAPTURE_SetVideoOwner)		GetProcAddress(this->m_hModule, "API_SetVideoOwner");
	this->m_pCaptureAVI			= (CAPTURE_CaptureAVI)			GetProcAddress(this->m_hModule, "API_CaptureAVI");
	this->m_pCaptureBMP			= (CAPTURE_CaptureBMP)			GetProcAddress(this->m_hModule, "API_CaptureBMP");

	return ME_OK;
}

MRET CModuleCapture::EnumDevice(E_DEVICE_CATEGORY eDeviceCategory, CArray<CString, CString>* pArray)
{
	if (this->m_pEnumDevice == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pEnumDevice(eDeviceCategory, pArray);
}

MRET CModuleCapture::OpenConfiguration(BOOL bRunTime, LPCTSTR lpCaption)
{
	if (this->m_pOpenConfiguration == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pOpenConfiguration(bRunTime, lpCaption);
}

MRET CModuleCapture::Open(LPCTSTR lpVideoCaptureDevice, LPCTSTR lpVideoCompressor, LPCTSTR lpAudioCaptureDevice, LPCTSTR lpAudioCompressor)
{
	if (this->m_pOpen == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	if (this->m_bOpened)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	MRET rc = this->m_pOpen(lpVideoCaptureDevice, lpVideoCompressor, lpAudioCaptureDevice, lpAudioCompressor);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	this->m_bOpened			= TRUE;
	this->m_bVideoCapable	= (lpVideoCaptureDevice != NULL);
	this->m_bAudioCapable	= (lpAudioCaptureDevice != NULL);

	return ME_OK;
}

MRET CModuleCapture::Close()
{
	if (this->m_pClose == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	if (!this->m_bOpened)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	MRET rc = this->m_pClose();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	this->m_bOpened			= FALSE;
	this->m_bVideoCapable	= FALSE;
	this->m_bAudioCapable	= FALSE;
	this->m_bCaptureAVI		= FALSE;
	this->m_strAVIFileName	.Empty();

	return ME_OK;
}

MRET CModuleCapture::GetVideoFormat(LPBITMAPINFOHEADER lpBMPInfoHeader)
{
	if (this->m_pGetVideoFormat == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	if (!this->m_bOpened || !this->m_bVideoCapable || lpBMPInfoHeader == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	return this->m_pGetVideoFormat(lpBMPInfoHeader);
}

MRET CModuleCapture::SetVideoOwner(HWND hWnd)
{
	if (this->m_pVideoOwner == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	if (!this->m_bOpened || !this->m_bVideoCapable)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	return this->m_pVideoOwner(hWnd);
}

MRET CModuleCapture::CaptureAVI(LPCTSTR lpFileName, BOOL bCaptureVideo, BOOL bCaptureAudio)
{
	if (this->m_pCaptureAVI == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	if (!this->m_bOpened)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	if (lpFileName == NULL)
	{
		if (!this->m_bCaptureAVI)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}
	}
	else
	{
		if (this->m_bCaptureAVI || (!bCaptureVideo && !bCaptureAudio))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		if ((bCaptureVideo && !this->m_bVideoCapable) || (bCaptureAudio && !this->m_bAudioCapable))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}
	}

	MRET rc = this->m_pCaptureAVI(lpFileName, bCaptureVideo, bCaptureAudio);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	this->m_bCaptureAVI = (lpFileName != NULL);
	this->m_strAVIFileName = lpFileName;

	return ME_OK;
}

MRET CModuleCapture::CaptureBMP(LONG& nBufferSize, LPVOID& lpvBuffer)
{
	if (this->m_pCaptureBMP == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	if (!this->m_bOpened || !this->m_bVideoCapable || lpvBuffer == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	return this->m_pCaptureBMP(nBufferSize, lpvBuffer);
}
