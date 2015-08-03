// ModuleTextToSpeech.cpp: implementation of the CModuleTextToSpeech class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModuleTextToSpeech.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModuleTextToSpeech::CModuleTextToSpeech()
{
	this->m_hModule				= NULL;
	this->m_pSpeakText			= NULL;
	this->LoadModule();
}

CModuleTextToSpeech::~CModuleTextToSpeech()
{
	if (this->m_hModule != NULL)
		::FreeLibrary(this->m_hModule);
}

MRET CModuleTextToSpeech::LoadModule()
{
	HMODULE hModule = ::LoadLibrary(_T("eRadTextToSpeech.DLL"));
	if (hModule == NULL)
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("eRadTextToSpeech.DLL"));
	}

	this->m_hModule				= hModule;
	this->m_pSpeakText			= (SPEECH_SpeakText)		GetProcAddress(this->m_hModule, "API_SpeakText");
	this->m_pGetVoiceList		= (SPEECH_GetVoiceList)		GetProcAddress(this->m_hModule, "API_GetVoiceList");

	return ME_OK;
}

MRET CModuleTextToSpeech::SpeakText(CString strSpeakContent, LONG nVoiceRate, LONG nVoiceVolume, LONG nVoiceClass, CString strVoiceDescription)
{
	if (this->m_pSpeakText == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}
	
#ifdef CATCH_EXCEPTION                                      //20120227
				try
#endif // CATCH_EXCEPTION
				{
					return this->m_pSpeakText(strSpeakContent, nVoiceRate, nVoiceVolume, nVoiceClass, strVoiceDescription);
				}
#ifdef CATCH_EXCEPTION
				catch (...) {
					try {
						LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_CATCH_EXCEPTION, _T("CModuleTextToSpeech::SpeakText!"));
					}
					catch (...) {}
				}
#endif // CATCH_EXCEPTION
	
}

MRET CModuleTextToSpeech::GetVoiceList(CStringArray *pArray)
{
	if (this->m_pGetVoiceList == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION);
	}

	return this->m_pGetVoiceList(pArray);
}