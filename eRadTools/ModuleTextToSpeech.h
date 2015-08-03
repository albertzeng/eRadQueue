// ModuleTextToSpeech.h: interface for the CModuleTextToSpeech class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULETEXTTOSPEECH_H__9E731852_9B6C_4110_BBA0_BAABFEFDD1E2__INCLUDED_)
#define AFX_MODULETEXTTOSPEECH_H__9E731852_9B6C_4110_BBA0_BAABFEFDD1E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

//////////////////////////////////////////////////////////////////////
// eRadTextToSpeech.DLL

typedef MRET	(*SPEECH_SpeakText)		(LPCTSTR lpSpeakContent, LONG nVoiceRate, LONG nVoiceVolume, LONG nVoiceClass, CString strVoiceDescription);
typedef MRET	(*SPEECH_GetVoiceList)	(CStringArray *pArray);


class CModuleTextToSpeech  
{
private:
	HMODULE						m_hModule;

private:
	MRET						LoadModule();

private:
	SPEECH_SpeakText			m_pSpeakText;
	SPEECH_GetVoiceList			m_pGetVoiceList;

public:
	MRET						SpeakText(CString strSpeakContent, LONG nVoiceRate, LONG nVoiceVolume, LONG nVoiceClass, CString strVoiceDescription);
	MRET						GetVoiceList(CStringArray *pArray);

public:
	CModuleTextToSpeech();
	virtual ~CModuleTextToSpeech();

};

#endif // !defined(AFX_MODULETEXTTOSPEECH_H__9E731852_9B6C_4110_BBA0_BAABFEFDD1E2__INCLUDED_)
