// LOG.h: interface for the CLOG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOG_H__421DEED9_7676_4C56_BB1F_F5F4DB6C72B0__INCLUDED_)
#define AFX_LOG_H__421DEED9_7676_4C56_BB1F_F5F4DB6C72B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define LL_TRACK						0x00000001
#define LL_DEBUG						0x00000002
#define	LL_ERROR						0x00000004
#define	LL_MESSAGE						0x00000008
#define	LL_MASK							0x0000FFFF

#define LD_MSGBOX						0x00010000
#define LD_FILE							0x00020000
#define LD_ALL							0xFFFF0000


#ifndef MRET
#define	MRET							LONG
#endif

#define	ME_OK							0
#define	ME_ERR_RESERVED					8888

#define	ME_ERR_CONFIGURATION			1
#define	ME_ERR_BADPARAMETER				2

#ifndef ME_ERR_BADDATA
#define	ME_ERR_BADDATA					3
#endif

#define	ME_ERR_CANNOT_PROCESS			4
#define	ME_ERR_PROCESS_ERROR			5
#define	ME_ERR_UNSUPPORTED_OPERATION	6
#define	ME_ERR_UNSUPPORTED_FORMAT		7
#define	ME_ERR_FUNCTION					8
#define	ME_ERR_CATCH_EXCEPTION			9

#define	ME_ERR_BEGINTHREAD				21
#define	ME_ERR_ALLOC_MEM				22
#define	ME_ERR_DATA_BUFFER				23
#define	ME_ERR_DATA_STREAM				24

#define	ME_ERR_OPENLOGFILE				31

#define	ME_ERR_CREATE_DIRECTORY			51
#define	ME_ERR_OPEN_FILE				52
#define	ME_ERR_READ_FILE				53
#define	ME_ERR_WRITE_FILE				54
#define	ME_ERR_GETFILESIZE				55
#define	ME_ERR_SETFILEPOINTER			56
#define	ME_ERR_CREATEFILEMAPPING		57
#define	ME_ERR_MAPVIEWOFFILE			58
#define	ME_ERR_SAVE_FILE				59

#define	ME_ERR_FILE_FORMAT				61
#define	ME_ERR_IMAGE_FILE				62
#define	ME_ERR_NOIMAGESEND				63
#define	ME_ERR_STORE_WARNING			64
#define	ME_ERR_STORE_FAILED				65
#define	ME_ERR_TRANSFER_SYNTAX			66
#define	ME_ERR_IMAGE_EXISTED			67
#define	ME_ERR_NO_PRIVILEGE				68

#define	ME_ERR_UNKNOWN_NODE				71
#define	ME_ERR_REMOTE_RELEASE			72
#define	ME_ERR_REMOTE_ABORT				73
#define	ME_ERR_INVALID_PDU				74
#define	ME_ERR_INVALID_PDU_ITEM			75
#define	ME_ERR_INVALID_COMMAND			76
#define	ME_ERR_MISS_IDENTIFIER			77
#define	ME_ERR_SOPCLASS_UNACCEPTED		78
#define	ME_ERR_INVALID_SOPCLASS			79
#define	ME_ERR_INVALID_QR_LEVEL			80
#define	ME_ERR_INVALID_IDENTIFIER		81
#define	ME_ERR_RESPONSE_ERROR			82
#define	ME_ERR_QUERY_RETRIEVE			83

#define	ME_ERR_LOCAL_REJECTED			88
#define	ME_ERR_REMOTE_REJECTED			89

#define	ME_ERR_FIND_ATTRIBUTE			91
#define	ME_ERR_ATTRIBUTE_VR				92
#define	ME_ERR_ATTIRBUTE_EXISTED		93

#define	ME_ERR_TCPIP_WSASTARTUP			101
#define	ME_ERR_TCPIP_WSACLEANUP			102
#define	ME_ERR_TCPIP_SOCKET				103
#define	ME_ERR_TCPIP_CLOSESOCKET		104
#define	ME_ERR_TCPIP_INVALIDSOCKET		105
#define	ME_ERR_TCPIP_BIND				106
#define	ME_ERR_TCPIP_LISTEN				107
#define	ME_ERR_TCPIP_ACCEPT				108
#define	ME_ERR_TCPIP_SELECT				109
#define	ME_ERR_TCPIP_SEND				110
#define	ME_ERR_TCPIP_RECV				111
#define	ME_ERR_TCPIP_CONNECTTIMEOUT		112
#define	ME_ERR_TCPIP_SENDTIMEOUT		113
#define	ME_ERR_TCPIP_RECEIVETIMEOUT		114
#define	ME_ERR_TCPIP_INETADDR			115
#define	ME_ERR_TCPIP_SETSOCKOPT			116
#define	ME_ERR_TCPIP_IOCTLSOCKET		117
#define	ME_ERR_TCPIP_CONNECT			118
#define	ME_ERR_TCPIP_CONNECTIONCLOSED	119

#define	ME_ERR_DB_CONFIGURATION			201
#define	ME_ERR_DB_OPEN					202
#define	ME_ERR_DB_OPEN_SESSION			203
#define	ME_ERR_DB_START_TRANSACTION		204
#define	ME_ERR_DB_COMMIT_TRANSACTION	205
#define	ME_ERR_DB_OPEN_TABLE			206
#define	ME_ERR_DB_OPEN_VIEW				207
#define	ME_ERR_DB_EXECUTE_PROCEDURE		208
#define	ME_ERR_DB_FIND_RECORD			209
#define	ME_ERR_DB_INSERT				210
#define	ME_ERR_DB_UPDATE				211
#define	ME_ERR_DB_DELETE				212

#define	ME_ERR_COINITIALIZE				251

#define	ME_ERR_JPEG_ENCODE				301
#define	ME_ERR_JPEG_DECODE				302
#define	ME_ERR_JPEG_SUSPENDED			303

#define	ME_ERR_AVI_FILEOPEN				321
#define	ME_ERR_AVI_FILEINFO				322
#define	ME_ERR_AVI_GETSTREAM			323
#define	ME_ERR_AVI_STREAMINFO			324
#define	ME_ERR_AVI_GETFRAMEOPEN			325
#define	ME_ERR_AVI_GETFRAME				326

#define	ME_ERR_DELETE_FILE				401
#define	ME_ERR_FAILURES_EXIST			402
#define	ME_ERR_UNMATCHABLE				403
#define	ME_ERR_QR_CONFIRM				404
#define	ME_ERR_SC_CONFIRM_TIMEOUT		405
#define	ME_ERR_GET_DISK_FREE_SPACE		406
#define	ME_ERR_XML_OPEN					407
#define	ME_ERR_XML_ADD_NODE				408
#define	ME_ERR_XML_GET_VALUE			409
#define	ME_ERR_XML_LOAD					410
#define	ME_ERR_XML_GET					411

class CLOG  
{
public:
	struct CSingleLOG
	{
		LONG			nLogCode;
		LPCTSTR			lpMessage;
	};

private:
	CRITICAL_SECTION	m_CriticalSection;
	DWORD				m_dwLength;
	LPCTSTR*			m_ppErrorMessage;
	LONG				m_nLogLevel;
	CString				m_strLogFile;
	CString				m_strLogDir;

public:
	static MRET			Initialize();
	static LPCTSTR		GetMessage(DWORD dwCode);
	static void			SetParameter(LONG nLogLevel, LPCTSTR lpLogFile = NULL);
	static void			DoLog(LONG nLevel, CString& strMessage);
	static void			DoLog(LONG nLevel, LPCTSTR lpMessage);
	static void			LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode);
	static void			LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode, LPCTSTR lpMessage);
	static void			LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode, LONG nMinor);
	static void			LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode, LONG nMinor, LPCTSTR lpMessage);

public:
	CLOG();
	virtual ~CLOG();
};

#define LOG_MESSAGE(Level, Message)									\
	{																\
		CLOG::DoLog(Level, Message);								\
	}																\

#define LOG_ERROR(Level, Code)										\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code);			\
	}																\

#define LOG_RET_ERROR(Level, Code)									\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code);			\
		return Code;												\
	}																\

#define LOG_ERROR_MESSAGE(Level, Code, Message)						\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code, Message);	\
	}																\

#define LOG_RET_ERROR_MESSAGE(Level, Code, Message)					\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code, Message);	\
		return Code;												\
	}																\

#define LOG_ERROR_MINOR(Level, Code, Minor)							\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code, Minor);		\
	}																\

#define LOG_RET_ERROR_MINOR(Level, Code, Minor)						\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code, Minor);		\
		return Code;												\
	}																\

#define LOG_ERROR_MINOR_MESSAGE(Level, Code, Minor, Message)		\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code, Minor, Message);	\
	}																\

#define LOG_RET_ERROR_MINOR_MESSAGE(Level, Code, Minor, Message)	\
	{																\
		CLOG::LogError(__FILE__, __LINE__, Level, Code, Minor, Message);	\
		return Code;												\
	}																\


#define OBPOS	LPVOID

template<class T> class COBList  
{
public:
	class COBNode  
	{
	public:
		COBNode*	m_pNext;
		COBNode*	m_pPrev;
		T*			m_pObject;

	public:
		COBNode(T* pObject)
		{
			this->m_pNext	= NULL;
			this->m_pPrev	= NULL;
			this->m_pObject	= pObject;
		}

		virtual ~COBNode()
		{
			delete m_pObject;
			delete m_pNext;
		}
	};

private:
	DWORD			m_nSize;
	COBNode*		m_pHead;
	COBNode*		m_pTail;
	OBPOS			m_pCurrent;

public:
	DWORD GetSize()
	{
		return this->m_nSize;
	}

	BOOL Replace(OBPOS& POS, T* pObject)
	{
		if (this->m_nSize == 0 || POS == NULL)
			return FALSE;

		delete ((COBNode*) POS)->m_pObject;
		((COBNode*) POS)->m_pObject = pObject;

		return TRUE;
	}

	T* Remove(OBPOS& POS)
	{
		if (this->m_nSize == 0 || POS == NULL)
			return NULL;

		COBNode* pNode = (COBNode*) POS;

		if (pNode->m_pPrev == NULL)
			this->m_pHead = pNode->m_pNext;
		else
			pNode->m_pPrev->m_pNext = pNode->m_pNext;

		if (pNode->m_pNext == NULL)
			this->m_pTail = pNode->m_pPrev;
		else
			pNode->m_pNext->m_pPrev = pNode->m_pPrev;

		this->m_nSize--;

		POS = pNode->m_pNext;
		T* pObject = pNode->m_pObject;

		pNode->m_pNext = NULL;
		pNode->m_pPrev = NULL;
		pNode->m_pObject = NULL;

		delete pNode;

		return pObject;
	}

	T* GetHead(OBPOS& POS)
	{
		POS = this->m_pHead;
		return (POS != NULL) ? ((COBNode*) POS)->m_pObject : NULL;
	}

	T* GetTail(OBPOS& POS)
	{
		POS = this->m_pTail;
		return (POS != NULL) ? ((COBNode*) POS)->m_pObject : NULL;
	}

	T* GetPrev(OBPOS& POS)
	{
		if (POS != NULL) POS = ((COBNode*) POS)->m_pPrev;
		return (POS != NULL) ? ((COBNode*) POS)->m_pObject : NULL;
	}

	T* GetNext(OBPOS& POS)
	{
		if (POS != NULL) POS = ((COBNode*) POS)->m_pNext;
		return (POS != NULL) ? ((COBNode*) POS)->m_pObject : NULL;
	}

	T* GetAt(UINT Index)
	{
		OBPOS POS = NULL;
		for (T* pObject =GetHead(POS); pObject != NULL; pObject = GetNext(POS))
			if (--Index == 0)
				return pObject;
		return NULL;	
	}

	OBPOS AddHead(T* pObject)
	{
		if (pObject == NULL)
			return NULL;

		if (this->m_nSize == 0)
		{
			this->m_pHead = this->m_pTail = new COBNode(pObject);
			this->m_nSize++;
		}
		else
		{
			COBNode* pNode = new COBNode(pObject);
			pNode->m_pNext = this->m_pHead;
			this->m_pHead->m_pPrev = pNode;
			this->m_pHead = pNode;
			this->m_nSize++;
		}

		return this->m_pHead;
	}

	OBPOS AddTail(T* pObject)
	{
		if (pObject == NULL)
			return NULL;

		if (this->m_nSize == 0)
		{
			this->m_pHead = this->m_pTail = new COBNode(pObject);
			this->m_nSize++;
		}
		else
		{
			COBNode* pNode = new COBNode(pObject);
			pNode->m_pPrev = this->m_pTail;
			this->m_pTail->m_pNext = pNode;
			this->m_pTail = pNode;
			this->m_nSize++;
		}

		return this->m_pTail;
	}

	OBPOS AddPrev(OBPOS POS, T* pObject)
	{
		if (pObject == NULL)
			return NULL;

		if (this->m_nSize == 0 || POS == NULL)
			return this->AddHead(pObject);

		COBNode* pCurrent = (COBNode*) POS;
		COBNode* pNode = new COBNode(pObject);

		if (pCurrent->m_pPrev == NULL)
			this->m_pHead = pNode;
		else
			pCurrent->m_pPrev->m_pNext = pNode;

		pNode->m_pPrev = pCurrent->m_pPrev;
		pNode->m_pNext = pCurrent;

		pCurrent->m_pPrev = pNode;

		this->m_nSize++;

		return pNode;
	}

	OBPOS AddNext(OBPOS POS, T* pObject)
	{
		if (pObject == NULL)
			return NULL;

		if (this->m_nSize == 0 || POS == NULL)
			return this->AddTail(pObject);

		COBNode* pCurrent = (COBNode*) POS;
		COBNode* pNode = new COBNode(pObject);

		if (pCurrent->m_pNext == NULL)
			this->m_pTail = pNode;
		else
			pCurrent->m_pNext->m_pPrev = pNode;

		pNode->m_pNext = pCurrent->m_pNext;
		pNode->m_pPrev = pCurrent;

		pCurrent->m_pNext = pNode;

		this->m_nSize++;

		return pNode;
	}

	BOOL	Replace(T* pObject)	{ return this->Replace(this->m_pCurrent, pObject);	}
	T*		Remove()			{ return this->Remove (this->m_pCurrent);	}
	T*		GetHead()			{ return this->GetHead(this->m_pCurrent);	}
	T*		GetTail()			{ return this->GetTail(this->m_pCurrent);	}
	T*		GetPrev()			{ return this->GetPrev(this->m_pCurrent);	}
	T*		GetNext()			{ return this->GetNext(this->m_pCurrent);	}
	OBPOS	AddPrev(T* pObject)	{ return this->AddPrev(this->m_pCurrent, pObject);	}
	OBPOS	AddNext(T* pObject)	{ return this->AddNext(this->m_pCurrent, pObject);	}

public:
	COBList()
	{
		this->m_nSize		= 0;
		this->m_pHead		= NULL;
		this->m_pTail		= NULL;
		this->m_pCurrent	= NULL;
	}

	virtual ~COBList()
	{
		while (this->GetHead() != NULL) delete this->Remove();
//		delete this->m_pHead;
	}
};


template<class TKey, class TValue> class COBFind  
{
public:
	struct CSingle
	{
		TKey m_Key;
		TValue m_Value;
	};

public:
	TKey m_DefaultKey;
	TValue m_DefaultValue;
	COBList<CSingle> m_lstValue;

public:
	UINT GetSize()
	{
		return this->m_lstValue.GetSize();
	}

	BOOL SetDefault(TKey key, TValue value)
	{
		this->m_DefaultKey = key;
		this->m_DefaultValue = value;

		return TRUE;
	}

	BOOL Add(TKey key, TValue value)
	{
		CSingle* pSingle = new CSingle;
		pSingle->m_Key = key;
		pSingle->m_Value = value;

		this->m_lstValue.AddTail(pSingle);

		return TRUE;
	}

	TKey& GetKey(UINT nIndex)
	{
		if (nIndex < this->GetSize())
		{
			OBPOS POS = NULL;
			for (CSingle* pSingle = this->m_lstValue.GetHead(POS); pSingle != NULL; pSingle = this->m_lstValue.GetNext(POS))
				if (nIndex-- == 0)
					return pSingle->m_Key;
		}

		return this->m_DefaultKey;
	}

	TValue& GetValue(UINT nIndex)
	{
		if (nIndex < this->GetSize())
		{
			OBPOS POS = NULL;
			for (CSingle* pSingle = this->m_lstValue.GetHead(POS); pSingle != NULL; pSingle = this->m_lstValue.GetNext(POS))
				if (nIndex-- == 0)
					return pSingle->m_Value;
		}

		return this->m_DefaultValue;
	}

	TKey& FindKey(TValue value)
	{
		OBPOS POS = NULL;
		for (CSingle* pSingle = this->m_lstValue.GetHead(POS); pSingle != NULL; pSingle = this->m_lstValue.GetNext(POS))
			if (pSingle->m_Value == value)
				return pSingle->m_Key;

		return this->m_DefaultKey;
	}

	TValue& FindValue(TKey key)
	{
		OBPOS POS = NULL;
		for (CSingle* pSingle = this->m_lstValue.GetHead(POS); pSingle != NULL; pSingle = this->m_lstValue.GetNext(POS))
			if (pSingle->m_Key == key)
				return pSingle->m_Value;

		return this->m_DefaultValue;
	}

public:
	COBFind() {}
	virtual ~COBFind() {}
};

typedef COBFind<long, long>			COBFindLL;
typedef COBFind<long, CString>		COBFindLS;
typedef COBFind<CString, CString>	COBFindSS;
typedef COBFind<CString, long>		COBFindSL;

#endif // !defined(AFX_LOG_H__421DEED9_7676_4C56_BB1F_F5F4DB6C72B0__INCLUDED_)
