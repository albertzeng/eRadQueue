// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectToken wrapper class

class ISpeechObjectToken : public COleDispatchDriver
{
public:
	ISpeechObjectToken() {}		// Calls COleDispatchDriver default constructor
	ISpeechObjectToken(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISpeechObjectToken(const ISpeechObjectToken& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetId();
	LPDISPATCH GetCategory();
	CString GetDescription(long Locale);
	CString GetAttribute(LPCTSTR AttributeName);
	LPUNKNOWN CreateInstance(LPUNKNOWN pUnkOuter, long ClsContext);
	BOOL MatchesAttributes(LPCTSTR Attributes);
};
/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectTokenCategory wrapper class

class ISpeechObjectTokenCategory : public COleDispatchDriver
{
public:
	ISpeechObjectTokenCategory() {}		// Calls COleDispatchDriver default constructor
	ISpeechObjectTokenCategory(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISpeechObjectTokenCategory(const ISpeechObjectTokenCategory& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetId();
	void SetDefault(LPCTSTR lpszNewValue);
	CString GetDefault();
	void SetId(LPCTSTR Id, BOOL CreateIfNotExist);
	LPDISPATCH EnumerateTokens(LPCTSTR RequiredAttributes, LPCTSTR OptionalAttributes);
};
/////////////////////////////////////////////////////////////////////////////
// ISpeechObjectTokens wrapper class

class ISpeechObjectTokens : public COleDispatchDriver
{
public:
	ISpeechObjectTokens() {}		// Calls COleDispatchDriver default constructor
	ISpeechObjectTokens(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISpeechObjectTokens(const ISpeechObjectTokens& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	LPDISPATCH Item(long Index);
};
/////////////////////////////////////////////////////////////////////////////
// ISpeechVoice wrapper class

class ISpeechVoice : public COleDispatchDriver
{
public:
	ISpeechVoice() {}		// Calls COleDispatchDriver default constructor
	ISpeechVoice(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISpeechVoice(const ISpeechVoice& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetStatus();
	LPDISPATCH GetVoice();
	void SetRefVoice(LPDISPATCH newValue);
	LPDISPATCH GetAudioOutput();
	void SetRefAudioOutput(LPDISPATCH newValue);
	LPDISPATCH GetAudioOutputStream();
	void SetRefAudioOutputStream(LPDISPATCH newValue);
	long GetRate();
	void SetRate(long nNewValue);
	long GetVolume();
	void SetVolume(long nNewValue);
	long GetEventInterests();
	void SetEventInterests(long nNewValue);
	void SetPriority(long nNewValue);
	long GetPriority();
	void SetAlertBoundary(long nNewValue);
	long GetAlertBoundary();
	void SetSynchronousSpeakTimeout(long nNewValue);
	long GetSynchronousSpeakTimeout();
	long Speak(LPCTSTR Text, long Flags);
	long SpeakStream(LPDISPATCH Stream, long Flags);
	void Pause();
	void Resume();
	long Skip(LPCTSTR Type, long NumItems);
	LPDISPATCH GetVoices(LPCTSTR RequiredAttributes, LPCTSTR OptionalAttributes);
	LPDISPATCH GetAudioOutputs(LPCTSTR RequiredAttributes, LPCTSTR OptionalAttributes);
	BOOL WaitUntilDone(long msTimeout);
	BOOL IsUISupported(LPCTSTR TypeOfUI, VARIANT* ExtraData);
	void DisplayUI(long hWndParent, LPCTSTR Title, LPCTSTR TypeOfUI, VARIANT* ExtraData);
};
