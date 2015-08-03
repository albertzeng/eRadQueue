// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "sapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectToken properties

/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectToken operations

CString ISpeechObjectToken::GetId()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH ISpeechObjectToken::GetCategory()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString ISpeechObjectToken::GetDescription(long Locale)
{
	CString result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		Locale);
	return result;
}

CString ISpeechObjectToken::GetAttribute(LPCTSTR AttributeName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		AttributeName);
	return result;
}

LPUNKNOWN ISpeechObjectToken::CreateInstance(LPUNKNOWN pUnkOuter, long ClsContext)
{
	LPUNKNOWN result;
	static BYTE parms[] =
		VTS_UNKNOWN VTS_I4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, parms,
		pUnkOuter, ClsContext);
	return result;
}

BOOL ISpeechObjectToken::MatchesAttributes(LPCTSTR Attributes)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Attributes);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectTokenCategory properties

/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectTokenCategory operations

CString ISpeechObjectTokenCategory::GetId()
{
	CString result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void ISpeechObjectTokenCategory::SetDefault(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString ISpeechObjectTokenCategory::GetDefault()
{
	CString result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void ISpeechObjectTokenCategory::SetId(LPCTSTR Id, BOOL CreateIfNotExist)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BOOL;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Id, CreateIfNotExist);
}

LPDISPATCH ISpeechObjectTokenCategory::EnumerateTokens(LPCTSTR RequiredAttributes, LPCTSTR OptionalAttributes)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		RequiredAttributes, OptionalAttributes);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectTokens properties

/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectTokens operations

long ISpeechObjectTokens::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH ISpeechObjectTokens::Item(long Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// ISpeechVoice properties

/////////////////////////////////////////////////////////////////////////////
// ISpeechVoice operations

LPDISPATCH ISpeechVoice::GetStatus()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ISpeechVoice::GetVoice()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetRefVoice(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH ISpeechVoice::GetAudioOutput()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetRefAudioOutput(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x3, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

LPDISPATCH ISpeechVoice::GetAudioOutputStream()
{
	LPDISPATCH result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetRefAudioOutputStream(LPDISPATCH newValue)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms,
		 newValue);
}

long ISpeechVoice::GetRate()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetRate(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ISpeechVoice::GetVolume()
{
	long result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetVolume(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ISpeechVoice::GetEventInterests()
{
	long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetEventInterests(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void ISpeechVoice::SetPriority(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ISpeechVoice::GetPriority()
{
	long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetAlertBoundary(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ISpeechVoice::GetAlertBoundary()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ISpeechVoice::SetSynchronousSpeakTimeout(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ISpeechVoice::GetSynchronousSpeakTimeout()
{
	long result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long ISpeechVoice::Speak(LPCTSTR Text, long Flags)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Text, Flags);
	return result;
}

long ISpeechVoice::SpeakStream(LPDISPATCH Stream, long Flags)
{
	long result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_I4;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Stream, Flags);
	return result;
}

void ISpeechVoice::Pause()
{
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ISpeechVoice::Resume()
{
	InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long ISpeechVoice::Skip(LPCTSTR Type, long NumItems)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4;
	InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		Type, NumItems);
	return result;
}

LPDISPATCH ISpeechVoice::GetVoices(LPCTSTR RequiredAttributes, LPCTSTR OptionalAttributes)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x11, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		RequiredAttributes, OptionalAttributes);
	return result;
}

LPDISPATCH ISpeechVoice::GetAudioOutputs(LPCTSTR RequiredAttributes, LPCTSTR OptionalAttributes)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		RequiredAttributes, OptionalAttributes);
	return result;
}

BOOL ISpeechVoice::WaitUntilDone(long msTimeout)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		msTimeout);
	return result;
}

BOOL ISpeechVoice::IsUISupported(LPCTSTR TypeOfUI, VARIANT* ExtraData)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x15, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		TypeOfUI, ExtraData);
	return result;
}

void ISpeechVoice::DisplayUI(long hWndParent, LPCTSTR Title, LPCTSTR TypeOfUI, VARIANT* ExtraData)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BSTR VTS_PVARIANT;
	InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 hWndParent, Title, TypeOfUI, ExtraData);
}
