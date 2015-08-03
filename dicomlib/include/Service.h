// Service.h: interface for the CService class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVICE_H__A9D346D1_72D5_42CC_B958_5FAAC36CA5B0__INCLUDED_)
#define AFX_SERVICE_H__A9D346D1_72D5_42CC_B958_5FAAC36CA5B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	DATA_SET_TYPE_YES					0x0000
#define	DATA_SET_TYPE_NO					0x0101
#define	DATA_SET_TYPE_IDENTIFIER			0x0102

#define	COMMAND_PRIORITY_MEDIUM				0x0000
#define	COMMAND_PRIORITY_HIGH				0x0001
#define	COMMAND_PRIORITY_LOW				0x0002


#define	C_STORE_RQ							0x0001
#define	C_STORE_RSP							0x8001
#define	C_GET_RQ							0x0010
#define	C_GET_RSP							0x8010
#define	C_FIND_RQ							0x0020
#define	C_FIND_RSP							0x8020
#define	C_MOVE_RQ							0x0021
#define	C_MOVE_RSP							0x8021
#define	C_ECHO_RQ							0x0030
#define	C_ECHO_RSP							0x8030
#define	C_CANCEL_RQ							0x0FFF


#define	N_EVENT_REPORT_RQ					0x0100
#define	N_EVENT_REPORT_RSP					0x8100
#define	N_GET_RQ							0x0110
#define	N_GET_RSP							0x8110
#define	N_SET_RQ							0x0120
#define	N_SET_RSP							0x8120
#define	N_ACTION_RQ							0x0130
#define	N_ACTION_RSP						0x8130
#define	N_CREATE_RQ							0x0140
#define	N_CREATE_RSP						0x8140
#define	N_DELETE_RQ							0x0150
#define	N_DELETE_RSP						0x8150


#define	ST_SUCCESS							0x0000
#define	ST_SUCCESS_PARTIAL					0x0001
#define	ST_SUCCESS_NONE						0x0002
#define	ST_SUCCESS_UNKNOWN					0x0003
#define	ST_PENDING							0xFF00
#define	ST_PENDING_WARNING					0xFF01
#define	ST_CANCEL							0xFE00
#define	ST_WARNING							0xB000
#define	ST_WARNING_DOES_NOT_MATCH			0xB007
#define	ST_WARNING_ELEMENTS_DISCARDED		0xB006
#define	ST_ATTRIBUTE_LIST_ERROR				0x0107
#define	ST_ATTRIBUTE_VALUE_OUT_OF_RANGE		0x0116
#define	ST_CANNOT_UNDERSTAND				0xC000
#define	ST_DOES_NOT_MATCH_SOP_CLASS			0xA900
#define	ST_FAILED							0xC000
#define	ST_MOVE_DESTINATION_UNKNOWN			0xA801
#define	ST_OUT_OF_RESOURCES					0xA700
#define	ST_UNABLE_TO_CALCULATE				0xA701
#define	ST_UNABLE_TO_PERFORM				0xA702
#define	ST_SOP_CLASS_NOT_SUPPORTED			0x0122
#define	ST_CLASS_INSTANCE_CONFLICT			0x0119
#define	ST_DUPLICATE_SOP_INSTANCE			0x0111
#define	ST_DUPLICATE_INVOCATION				0x0210
#define	ST_INVALID_ARGUMENT_VALUE			0x0115
#define	ST_INVALID_ATTRIBUTE_VALUE			0x0106
#define	ST_INVALID_OBJECT_INSTANCE			0x0117
#define	ST_MISSING_ATTRIBUTE				0x0120
#define	ST_MISSING_ATTRIBUTE_VALUE			0x0121
#define	ST_MISTYPED_ARGUMENT				0x0212
#define	ST_NO_SUCH_ARGUMENT					0x0114
#define	ST_NO_SUCH_ATTRIBUTE				0x0105
#define	ST_NO_SUCH_EVENT_TYPE				0x0113
#define	ST_NO_SUCH_OBJECT_INSTANCE			0x0112
#define	ST_NO_SUCH_SOP_CLASS				0x0118
#define	ST_PROCESSING_FAILURE				0x0110
#define	ST_RESOURCE_LIMITATION				0x0213
#define	ST_UNRECOGNIZED_OPERATION			0x0211
#define	ST_NO_SUCH_ACTION_TYPE				0x0123


class CServiceClass;

class CService  
{
protected:
	CString			m_strSOPClass;
	CRuntimeClass*	m_pRequestRuntimeClass;
	CRuntimeClass*	m_pResponseRuntimeClass;

	BYTE			m_nContextID;
	CString			m_strMETASOPClass;

	BOOL			m_bCancelRequest;

	CObCommand*		m_pRequestCommand;	// Refer to another instance.
	CObBasic*		m_pRequestObject;	// Refer to another instance.

	CNode*			m_pConnect;			// Refer to another instance.
	CPDUAssociate*	m_pAssociationAC;	// Refer to another instance.

public:
	static	Uint16	GetMessageID();
	static	Uint16	GetMessageIDCMoveSCU();

public:
			MRET	SetSOPClass(LPCTSTR lpSOPClass)		{ this->m_strSOPClass = lpSOPClass; return ME_OK; }
			MRET	SetMETASOPClass(LPCTSTR lpSOPClass)	{ this->m_strMETASOPClass = lpSOPClass; return ME_OK; }
			MRET	SetParameter(CNode* pConnect, CPDUAssociate* pAssociationAC);
			MRET	SendMessage(CObCommand* pCommand, LPCTSTR lpAS = NULL);
			MRET	SendMessage(CObCommand* pCommand, CObBasic* pObject, LPCTSTR lpAS = NULL);
			MRET	SendMessage(CObCommand* pCommand, CElementSet* pDataSet, LPCTSTR lpAS = NULL);

public:
			CNode*			GetConnect()				{ return this->m_pConnect; }
			CPDUAssociate*	GetAssociationAC()			{ return this->m_pAssociationAC; }
			LPCTSTR	GetCallingAETitle()					{ return (this->m_pAssociationAC == NULL) ? NULL : this->m_pAssociationAC->GetCallingAETitle(); }
			LPCTSTR	GetCalledAETitle()					{ return (this->m_pAssociationAC == NULL) ? NULL : this->m_pAssociationAC->GetCalledAETitle(); }
	virtual MRET	SetSendStatus(Uint32 nFileLength, Uint32 nSendLength)	{ return ME_OK; }	// C-GET, C-MOVE, C-STORE
	virtual MRET	SetReceiveStatus(Uint32 nReceiveLength)					{ return ME_OK; }	// C-GET, C-MOVE, C-STORE

// Service User
public:
			MRET	Cancel()							{ this->m_bCancelRequest = TRUE; return ME_OK; }	// C-FIND, C-GET, C-MOVE, C-STORE
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL) = 0;

protected:
			MRET	CancelRequest();		// C-FIND, C-GET, C-MOVE
			MRET	Receive(Uint16* pStatus = NULL);
			MRET	Receive(CObCommand*& pResponseCommand, CObBasic*& pResponseObject, Uint16* pStatus = NULL);	// DIMSE-N
	virtual MRET	OnReceive(CPDUPDataTF* pPDataTF, Uint16* pStatus = NULL);
	virtual MRET	OnReceive(CPDUPDataTF* pPDataTF, CObCommand*& pResponseCommand, CObBasic*& pResponseObject, Uint16* pStatus = NULL);	// DIMSE-N
	virtual MRET	OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)		{ return ME_ERR_FUNCTION; }

// Service Provider
public:
	virtual MRET	Execute(CPDUPDataTF* pPDataTF);
	virtual MRET	ServiceCallback(MRET nReturnCode)	{ return ME_OK; }

protected:
			MRET	CheckCancelRequest();	// C-FIND, C-GET, C-MOVE
	virtual MRET	OnRequest()							{ return ME_ERR_FUNCTION; }
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL) = 0;
	virtual MRET	ResponseCallback(CObCommand* pResponseCommand, CObBasic* pResponseObject)	{ return ME_OK; }

public:
	CService(LPCTSTR lpSOPClass, CRuntimeClass* pRequestRuntimeClass, CRuntimeClass* pResponseRuntimeClass = NULL);
	virtual ~CService();
};


class CCStore : public CService  
{
// Service User	- OnResponse() must be overloaded.
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);
			MRET	Invoke(CObBasic* pRequestObject, LPCTSTR lpSOPInstance, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus);

public:
	CCStore(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CCStore();
};


class CCGet : public CService  
{
// Service User - OnResponse() must be overloaded.
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);
			MRET	Invoke(CObBasic* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);

public:
	CCGet(LPCTSTR lpSOPClass, CRuntimeClass* pRequestRuntimeClass, CRuntimeClass* pResponseRuntimeClass);
	virtual ~CCGet();
};


class CCMove : public CService  
{
// Service User - OnResponse() must be overloaded.
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);
			MRET	Invoke(LPCTSTR lpMoveDestination, CObBasic* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);

public:
	CCMove(LPCTSTR lpSOPClass, CRuntimeClass* pRequestRuntimeClass, CRuntimeClass* pResponseRuntimeClass);
	virtual ~CCMove();
};


class CCFind : public CService  
{
// Service User - OnResponse() must be overloaded.
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);
			MRET	Invoke(CObBasic* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

// Service Provider - OnRequest() must be overloaded.
protected:
			LONG	m_nResponseCount;
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus, CObBasic* pResponseObject = NULL);

public:
	CCFind(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CCFind();
};


class CNEvent : public CService  
{
// Service User
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);	// OnResponse() must be overloaded.
			MRET	Invoke(Uint16 nEventTypeID, LPCTSTR lpSOPInstance, CObBasic* pRequestObject);	// OnResponse() must be overloaded.
			MRET	Invoke(Uint16 nEventTypeID, LPCTSTR lpSOPInstance, CObBasic* pRequestObject, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);
			MRET	Invoke(Uint16 nEventTypeID, LPCTSTR lpSOPInstance, CElementSet* pDataSet, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus, CObBasic* pResponseObject);

	// Status for response: X - Canceled, I - Inside Tasks, O - Derived Class' Tasks, D - Data Set
	// X - 0x0119 - class-instance conflict:
	// X - 0x0210 - duplicate invocation:
	// OD- 0x0115 - invalid argument value:
	// I - 0x0117 - invalid SOP Instance:
	// X - 0x0212 - mistyped argument:
	// O - 0x0114 - no such argument:
	// O - 0x0113 - no such event type:
	// I - 0x0118 - no such SOP class:
	// O - 0x0112 - no such SOP Instance:
	// O!- 0x0110 - processing failure:
	// O - 0x0213 - resource limitation:
	// O - 0x0000 - success:
	// I - 0x0211 - unrecognized operation:

public:
	CNEvent(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CNEvent();
};


class CNGet : public CService  
{
// Service User
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CElementSet* pDataSet);
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus, CElementSet* pDataSet);
			MRET	SendResponse(Uint16 nStatus, CObBasic* pResponseObject);

	// Status for response: X - Canceled, I - Inside Tasks, O - Derived Class' Tasks, D - Data Set
	// O!- 0x0107 - attribute list error:
	// X - 0x0119 - class-instance conflict:
	// X - 0x0210 - duplicate invocation:
	// I - 0x0117 - invalid SOP Instance:
	// X - 0x0212 - mistyped argument:
	// I - 0x0118 - no such SOP class:
	// O - 0x0112 - no such SOP Instance:
	// O!- 0x0110 - processing failure:
	// O - 0x0213 - resource limitation:
	// OD- 0x0000 - success:
	// I - 0x0211 - unrecognized operation:

public:
	CNGet(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CNGet();
};


class CNSet : public CService  
{
// Service User
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance, CObBasic* pRequestObject);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance, CObBasic* pRequestObject, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);
			MRET	Invoke(LPCTSTR lpSOPInstance, CElementSet* pDataSet, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus, CObBasic* pResponseObject);

	// Status for response: X - Canceled, I - Inside Tasks, O - Derived Class' Tasks, D - Data Set
	// X - 0x0119 - class-instance conflict:
	// X - 0x0210 - duplicate invocation:
	// OD- 0x0106 - invalid Attribute Value:
	// X - 0x0212 - mistyped argument:
	// I - 0x0117 - invalid SOP Instance:
	// OD- 0x0121 - missing Attribute Value:
	// O!- 0x0105 - no such Attribute:
	// I - 0x0118 - no such SOP class:
	// O - 0x0112 - no such SOP Instance:
	// O!- 0x0110 - processing failure:
	// O - 0x0213 - resource limitation:
	// O - 0x0000 - success:
	// I - 0x0211 - unrecognized operation:

public:
	CNSet(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CNSet();
};


class CNAction : public CService  
{
// Service User
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);	// OnResponse() must be overloaded.
			MRET	Invoke(Uint16 nActionTypeID, LPCTSTR lpSOPInstance, CObBasic* pRequestObject);	// OnResponse() must be overloaded.
			MRET	Invoke(Uint16 nActionTypeID, LPCTSTR lpSOPInstance, CObBasic* pRequestObject, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);
			MRET	Invoke(Uint16 nActionTypeID, LPCTSTR lpSOPInstance, CElementSet* pDataSet, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus, CObBasic* pResponseObject);

	// Status for response: X - Canceled, I - Inside Tasks, O - Derived Class' Tasks, D - Data Set
	// X - 0x0119 - class-instance conflict:
	// X - 0x0210 - duplicate invocation:
	// OD- 0x0115 - invalid argument value:
	// I - 0x0117 - invalid SOP Instance:
	// X - 0x0212 - mistyped argument:
	// O - 0x0123 - no such action:
	// O - 0x0114 - no such argument:
	// I - 0x0118 - no such SOP class:
	// O - 0x0112 - no such SOP Instance:
	// O!- 0x0110 - processing failure:
	// O - 0x0213 - resource limitation:
	// O - 0x0000 - success:
	// I - 0x0211 - unrecognized operation:

public:
	CNAction(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CNAction();
};


class CNCreate : public CService  
{
// Service User
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance, CObBasic* pRequestObject);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance, CObBasic* pRequestObject, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);
			MRET	Invoke(LPCTSTR lpSOPInstance, CElementSet* pDataSet, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus, LPCTSTR lpSOPInstance, CObBasic* pResponseObject);

	// Status for response: X - Canceled, I - Inside Tasks, O - Derived Class' Tasks, D - Data Set
	// X - 0x0119 - class-instance conflict:
	// X - 0x0210 - duplicate invocation:
	// O - 0x0111 - duplicate SOP Instance:
	// OD- 0x0106 - invalid Attribute Value:
	// I - 0x0117 - invalid SOP Instance:
	// O!- 0x0120 - missing Attribute:
	// OD- 0x0121 - missing Attribute Value:
	// X - 0x0212 - mistyped argument:
	// O!- 0x0105 - no such Attribute:
	// I - 0x0118 - no such SOP class:
	// O - 0x0112 - no such SOP Instance:
	// O!- 0x0110 - processing failure:
	// O - 0x0213 - resource limitation:
	// O - 0x0000 - success:
	// I - 0x0211 - unrecognized operation:

public:
	CNCreate(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CNCreate();
};


class CNDelete : public CService  
{
// Service User
public:
	virtual MRET	Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance);	// OnResponse() must be overloaded.
			MRET	Invoke(LPCTSTR lpSOPInstance, CObCommand*& pResponseCommand, CObBasic*& pResponseObject);

// Service Provider - OnRequest() must be overloaded.
protected:
	virtual MRET	Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);
			MRET	SendResponse(Uint16 nStatus);

	// Status for response: X - Canceled, I - Inside Tasks, O - Derived Class' Tasks, D - Data Set
	// X - 0x0119 - class-instance conflict:
	// X - 0x0210 - duplicate invocation:
	// I - 0x0117 - invalid SOP Instance:
	// X - 0x0212 - mistyped argument:
	// I - 0x0118 - no such SOP class:
	// O - 0x0112 - no such SOP Instance:
	// O!- 0x0110 - processing failure:
	// O - 0x0213 - resource limitation:
	// O - 0x0000 - success:
	// I - 0x0211 - unrecognized operation:

public:
	CNDelete(LPCTSTR lpSOPClass, CRuntimeClass* pRuntimeClass);
	virtual ~CNDelete();
};

#endif // !defined(AFX_SERVICE_H__A9D346D1_72D5_42CC_B958_5FAAC36CA5B0__INCLUDED_)
