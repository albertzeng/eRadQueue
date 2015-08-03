// ModuleLoadSaveImage.h: interface for the CModuleLoadSaveImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULELOADSAVEIMAGE_H__750160E7_719F_4655_9E7E_2EDC20D04435__INCLUDED_)
#define AFX_MODULELOADSAVEIMAGE_H__750160E7_719F_4655_9E7E_2EDC20D04435__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

//////////////////////////////////////////////////////////////////////
// eRadLoadSaveImage.dll

typedef LPCTSTR	(*LSIMAGE_GetFileFilter)	();
typedef BOOL	(*LSIMAGE_LoadImage)		(CString strBMPFileName, CString strLoadFileName);
typedef BOOL	(*LSIMAGE_SaveImage)		(CString strBMPFileName, CString strSaveFileName);

class CModuleLoadSaveImage  
{
private:
	HMODULE					m_hModule;

private:
	MRET					LoadModule();

private:
	LSIMAGE_GetFileFilter	m_pGetFileFilter;
	LSIMAGE_LoadImage		m_pLoadImage;
	LSIMAGE_SaveImage		m_pSaveImage;

public:
	LPCTSTR					GetFileFilter();

public:
	BOOL					LoadImage(CString strBMPFileName, CString strLoadFileName);
	BOOL					SaveImage(CString strBMPFileName, CString strSaveFileName);

public:
	CModuleLoadSaveImage();
	virtual ~CModuleLoadSaveImage();
};

#endif // !defined(AFX_MODULELOADSAVEIMAGE_H__750160E7_719F_4655_9E7E_2EDC20D04435__INCLUDED_)
