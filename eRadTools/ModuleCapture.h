// ModuleCapture.h: interface for the CModuleCapture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULECAPTURE_H__DF0E9194_89B2_45F7_A491_AED05FFF5FF1__INCLUDED_)
#define AFX_MODULECAPTURE_H__DF0E9194_89B2_45F7_A491_AED05FFF5FF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

enum E_DEVICE_CATEGORY
{
	EDC_VIDEO_INPUT_DEVICE,			// CLSID_VideoInputDeviceCategory
	EDC_VIDEO_COMPRESSOR,			// CLSID_VideoCompressorCategory
	EDC_AUDIO_INPUT_DEVICE,			// CLSID_AudioInputDeviceCategory
	EDC_AUDIO_COMPRESSOR			// CLSID_AudioCompressorCategory
};

//////////////////////////////////////////////////////////////////////
// eRadCaptureXXX.dll

typedef MRET (*CAPTURE_EnumDevice)			(E_DEVICE_CATEGORY eDeviceCategory, CArray<CString, CString>* pArray);
typedef MRET (*CAPTURE_OpenConfiguration)	(BOOL bRunTime, LPCTSTR lpCaption);
typedef MRET (*CAPTURE_Open)				(LPCTSTR lpVideoCaptureDevice, LPCTSTR lpVideoCompressor, LPCTSTR lpAudioCaptureDevice, LPCTSTR lpAudioCompressor);
typedef MRET (*CAPTURE_Close)				();
typedef MRET (*CAPTURE_GetVideoFormat)		(LPBITMAPINFOHEADER lpBMPInfoHeader);
typedef MRET (*CAPTURE_SetVideoOwner)		(HWND hWnd);
typedef MRET (*CAPTURE_CaptureAVI)			(LPCTSTR lpFileName, BOOL bCaptureVideo, BOOL bCaptureAudio);
typedef MRET (*CAPTURE_CaptureBMP)			(LONG& nBufferSize, LPVOID& lpvBuffer);

//////////////////////////////////////////////////////////////////////

class CModuleCapture  
{
private:
	CString						m_strName;
	HMODULE						m_hModule;

public:
	BOOL						m_bOpened;
	BOOL						m_bVideoCapable;
	BOOL						m_bAudioCapable;
	BOOL						m_bCaptureAVI;
	CString						m_strAVIFileName;

public:
	MRET						LoadModule(LPCTSTR lpName);

public:
	CAPTURE_EnumDevice			m_pEnumDevice;
	CAPTURE_OpenConfiguration	m_pOpenConfiguration;
	CAPTURE_Open				m_pOpen;
	CAPTURE_Close				m_pClose;
	CAPTURE_GetVideoFormat		m_pGetVideoFormat;
	CAPTURE_SetVideoOwner		m_pVideoOwner;
	CAPTURE_CaptureAVI			m_pCaptureAVI;
	CAPTURE_CaptureBMP			m_pCaptureBMP;

public:
	MRET						EnumDevice(E_DEVICE_CATEGORY eDeviceCategory, CArray<CString, CString>* pArray);
	MRET						OpenConfiguration(BOOL bRunTime, LPCTSTR lpCaption);

public:
	MRET						Open(LPCTSTR lpVideoCaptureDevice, LPCTSTR lpVideoCompressor, LPCTSTR lpAudioCaptureDevice, LPCTSTR lpAudioCompressor);
	MRET						Close();

public:
	MRET						GetVideoFormat(LPBITMAPINFOHEADER lpBMPInfoHeader);
	MRET						SetVideoOwner(HWND hWnd);
	MRET						CaptureAVI(LPCTSTR lpFileName, BOOL bCaptureVideo, BOOL bCaptureAudio);
	MRET						CaptureBMP(LONG& nBufferSize, LPVOID& lpvBuffer);

public:
	CModuleCapture();
	virtual ~CModuleCapture();
};

#endif // !defined(AFX_MODULECAPTURE_H__DF0E9194_89B2_45F7_A491_AED05FFF5FF1__INCLUDED_)
