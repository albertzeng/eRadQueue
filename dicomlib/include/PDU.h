// PDU.h: interface for the CPDU class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PDU_H__394E1D14_65EA_4A14_8767_DEADCE35F23C__INCLUDED_)
#define AFX_PDU_H__394E1D14_65EA_4A14_8767_DEADCE35F23C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma pack(1)

// PS 3.8-2001 9.3
#define PDU_A_ASSOCIATE_RQ					0x01
#define PDU_A_ASSOCIATE_AC					0x02
#define PDU_A_ASSOCIATE_RJ					0x03
#define PDU_P_DATA_TF						0x04
#define PDU_A_RELEASE_RQ					0x05
#define PDU_A_RELEASE_RP					0x06
#define PDU_A_ABORT							0x07

#define ITEM_APP_CONTEXT					0x10
#define ITEM_PRES_CONTEXT_RQ				0x20
#define ITEM_PRES_CONTEXT_AC				0x21
#define ITEM_ABSTRACT_SYNTAX				0x30
#define ITEM_TRANSFER_SYNTAX				0x40
#define ITEM_USER_INFO						0x50
#define ITEM_MAX_LENGTH						0x51
#define ITEM_IMP_CLASS_UID					0x52
#define ITEM_ASYN_OP_WIN					0x53
#define ITEM_SCP_SCU_ROLE					0x54
#define ITEM_IMP_VER_NAME					0x55
#define ITEM_SOP_CLASS_EXT					0x56

#define PDV_TYPE_COMMAND					0x01
#define PDV_TYPE_LAST						0x02

// PS 3.8-2001 9.3.3.2
#define	RESULT_ACCEPTANCE					0
#define	REASON_USER_REJECTION				1
#define	REASON_NO_REASON					2
#define	REASON_ABSTRACT_NOT_SUPPORTED		3
#define	REASON_TRANSFER_NOT_SUPPORTED		4

// PS 3.8-2001 9.3.4
#define	RESULT_REJECTED_PERMANENT			1
#define	RESULT_REJECTED_TRANSIENT			2

#define	SOURCE_SERVICE_USER					1
#define	SOURCE_PROVIDER_ACSE				2
#define	SOURCE_PROVIDER_PRESENTATION		3

#define	REASON_NO_REASON_GIVEN				1
#define	REASON_APPLICATION_CONTEXT_NAME		2
#define	REASON_CALLING_AE_TITLE				3
#define	REASON_CALLED_AE_TITLE				7
/*
#define	REASON_NO_REASON_GIVEN				1
*/
#define	REASON_PROTOCOL_VERSION				2

#define	REASON_TEMPORARY_CONGESTION			1
#define	REASON_LOCAL_LIMIT_EXCEEDED			2

// PS 3.8-2001 9.3.8
#define	SOURCE_USER_ABORT					0
#define	SOURCE_PROVIDER_ABORT				2

#define	REASON_NOT_SPECIFIED				0
#define	REASON_UNRECOGNIZED_PDU				1
#define	REASON_UNEXPECTED_PDU				2
#define	REASON_UNRECOGNIZED_PARAMETER		4
#define	REASON_UNEXPECTED_PARAMETER			5
#define	REASON_INVALID_PARAMETER			6

#define DCM_CONNECT_TIMEOUT					120000
#define DCM_SEND_TIMEOUT					100000
#define DCM_RECEIVE_TIMEOUT					100000

#define	DCM_MAXIMUM_PDU_LENGTH				0x8000

#define	DCM_LOCAL_IP_ADDRESS				_T("127.0.0.1")

class CPDU;
class CService;
class CPresContext;
class CUserInfo;
class CUserInfoItem;

class CNode  
{
private:
	SOCKET		m_Socket;
	Uint32		m_nConnectTimeOut;
	Uint32		m_nSendTimeOut;
	Uint32		m_nReceiveTimeOut;

public:
	Uint32		m_nIndex;
	Uint16		m_nPort;
	Uint32		m_nNodeMask;
	Uint32		m_nServiceMask;
	CString		m_strAETitle;
	CString		m_strIPAddress;
	CString		m_strDescription;

public:
	CNode&		operator =(CNode& Node);

public:
	MRET		SetTimeOut(Uint32 nConnect, Uint32 nSend, Uint32 nReceive);
	MRET		GetTimeOut(Uint32& nConnect, Uint32& nSend, Uint32& nReceive);

public:
	MRET		Initialize();	// Listen network
	MRET		Listen(CNode*& pConnect, Uint32 nTimeOut, BOOL bBlock);	// Listen network
	MRET		Connect(CNode* pLocalNode = NULL, Uint32 nTimeOut = 0);
	MRET		Peek(BOOL& bHasInput);
	MRET		DisConnect();

public:
	MRET		NetworkSend(LPVOID lpvBuffer, Uint32 nLength);
	MRET		NetworkReceive(LPVOID lpvBuffer, Uint32 nLength);
	MRET		ReceivePDU(CPDU*& pPDU);

public:
	CNode();
	virtual ~CNode();
};


class CPDU  
{
friend class CNode;

protected:
	struct CPrePDU {
		BYTE		Label;
		BYTE		Res1;
		Uint32		Len;
	} m_PrePDU;

	LPBYTE			m_lpStream;
	CNode*			m_pConnect;	// Refer to another instance.

public:
	virtual BYTE	GetLabel()				{ return this->m_PrePDU.Label; }
	virtual MRET	Send(CNode* pConnect);
	virtual MRET	Parse() = 0;
	virtual MRET	Built() = 0;
	virtual MRET	GetLength() = 0;

public:
	static	MRET	ReceivePDU(CPDU*& pPDU, CNode* pConnect);
	static	MRET	ReceivePDUPDataTF(CPDU*& pPDU, CNode* pConnect, BOOL bParse = FALSE);

public:
	CPDU();
	virtual ~CPDU();
};


class CPDUAssociate : public CPDU  
{
private:
	struct CHead {
		Uint16		ProtocolVersion;
		Uint16		Res1;
		BYTE		CalledAETitle[16];
		BYTE		CallingAETitle[16];
		BYTE		Res2[32];
	} m_Head;

	struct CPreAppContext {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
	} m_PreAppContext;

	CString			m_strCallingAETitle;
	CString			m_strCalledAETitle;

	CString			m_strAppContextName;

	COBList<CPresContext>*	m_pPresContextList;
	CUserInfo*		m_pUserInfo;

protected:
	virtual MRET	Parse();
	virtual MRET	Built();
	virtual MRET	GetLength();

public:
			COBList<CPresContext>*	GetPresContextList()			{ return this->m_pPresContextList; }
			COBList<CUserInfoItem>*	GetUserInfoItemList();
			MRET	AddPresContext(CPresContext* pPresContext);
			MRET	AddUserInfoItem(CUserInfoItem* pUserInfoItem);

			MRET	BuildAAssociateRQ(LPCTSTR lpCalledAETitle, LPCTSTR lpCallingAETitle);
			MRET	BuildAAssociateAC(CPDUAssociate* pAAssociateRQ);

			Uint32	GetMaxLength();
			LPCTSTR	GetCallingAETitle()		{ return this->m_strCallingAETitle; }
			LPCTSTR	GetCalledAETitle()		{ return this->m_strCalledAETitle; }

			// A-ASSOCIATE-AC
			MRET	RebuildAC(CPDUAssociate* pAAssociateRQ);
			BOOL	METAMember(LPCTSTR lpMETA, LPCTSTR lpAS);
			BOOL	AcceptAbstractSyntax(LPCTSTR lpAS, LPCTSTR lpMETA = NULL);
			BYTE	GetContextID(LPCTSTR lpAS, LPCTSTR lpMETA = NULL);
			LPCTSTR	GetAbstractSyntax(BYTE nContextID);
			LPCTSTR	GetTransferSyntax(BYTE nContextID);

public:
	CPDUAssociate();
	virtual ~CPDUAssociate();
};


class CPresContext  
{
private:
	struct CHead {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
		BYTE		ContextID;
		BYTE		Res2;
		BYTE		ResultReason;
		BYTE		Res3;
	} m_Head;

	struct CPreSyntax {
	   BYTE			Label;
	   BYTE			Res1;
	   Uint16		Len;
	};

	CString			m_strAS;
	STRING_ARRAY	m_aAcceptableTS;

public:
			MRET	BuildRQ(BYTE nContextID, LPCTSTR lpAS, LPCTSTR lpTS);
			MRET	AddTransferSyntax(LPCTSTR lpTS);

			MRET	BuildAC(CPresContext* pRQ, STRING_ARRAY* pAcceptableTS);
			BYTE	GetResultReason()		{ return this->m_Head.ResultReason; }
			LPCTSTR	GetTransferSyntax()		{ return this->m_aAcceptableTS.ElementAt(0); }
			MRET	SetAbstractSyntax(LPCTSTR lpAS);

			BOOL	IsMatching(LPCTSTR lpAS, LPCTSTR lpTS);
			BYTE	GetContextID()			{ return this->m_Head.ContextID; }
			LPCTSTR	GetAbstractSyntax()		{ return this->m_strAS; }

public:
	virtual BYTE	GetLabel()				{ return this->m_Head.Label; }
	virtual MRET	Parse(CIstream* pIOstream);
	virtual MRET	Built(COstream* pIOstream);
	virtual MRET	GetLength(Uint32& nLength);

public:
	CPresContext();
	virtual ~CPresContext();
};


class CUserInfo  
{
private:
	struct CHead {
	   BYTE			Label;
	   BYTE			Res1;
	   Uint16		Len;
	} m_Head;

	struct CMaxLength {
	   BYTE			Label;
	   BYTE			Res1;
	   Uint16		Len;
	   Uint32		MaxLen;
	} m_MaxLength;

	struct CPreImpClassUID {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
	} m_PreImpClassUID;

	CString			m_strImpClassUID;
	COBList<CUserInfoItem>*	m_pUserInfoItemList;

public:
			Uint32	GetMaxLength()							{ return this->m_MaxLength.MaxLen; }
			MRET	SetMaxLength(Uint32 nMaxLength);
			LPCTSTR	GetImpClassUID()						{ return this->m_strImpClassUID; }
			MRET	SetImpClassUID(LPCTSTR lpImpClassUID);
			COBList<CUserInfoItem>*	GetUserInfoItemList()	{ return this->m_pUserInfoItemList; }
			MRET	AddUserInfoItem(CUserInfoItem* pUserInfoItem);

public:
	virtual BYTE	GetLabel()								{ return this->m_Head.Label; }
	virtual MRET	Parse(CIstream* pIOstream);
	virtual MRET	Built(COstream* pIOstream);
	virtual MRET	GetLength(Uint32& nLength);

public:
	CUserInfo();
	virtual ~CUserInfo();
};


class CUserInfoItem  
{
public:
	virtual BYTE	GetLabel() = 0;
	virtual MRET	Parse(CIstream* pIOstream) = 0;
	virtual MRET	Built(COstream* pIOstream) = 0;
	virtual MRET	GetLength(Uint32& nLength) = 0;

public:
	CUserInfoItem();
	virtual ~CUserInfoItem();
};


class CUIAsynOpWin : public CUserInfoItem  
{
private:
	struct CHead {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
		Uint16		Invoked;
		Uint16		Performed;
	} m_Head;

public:
			MRET	SetValue(Uint16 nInvoked, Uint16 nPerformed);
			Uint16	GetInvokedValue()		{ return this->m_Head.Invoked; }
			Uint16	GetPerformedValue()		{ return this->m_Head.Performed; }

public:
	virtual BYTE	GetLabel()				{ return this->m_Head.Label; }
	virtual MRET	Parse(CIstream* pIOstream);
	virtual MRET	Built(COstream* pIOstream);
	virtual MRET	GetLength(Uint32& nLength);

public:
	CUIAsynOpWin();
	virtual ~CUIAsynOpWin();
};


class CUIScpScuRole : public CUserInfoItem  
{
private:
	struct CHead {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
		Uint16		UIDLen;
	} m_Head;

	CString			m_strUID;

	struct CRole {
		BYTE		Scu;
		BYTE		Scp;
	} m_Role;

public:
			MRET	SetValue(LPCTSTR lpUID, BYTE nScu, BYTE nScp);
			LPCTSTR	GetSOPClassUID()		{ return this->m_strUID; }
			BYTE	GetScuValue()			{ return this->m_Role.Scu; }
			BYTE	GetScpValue()			{ return this->m_Role.Scp; }

public:
	virtual BYTE	GetLabel()				{ return this->m_Head.Label; }
	virtual MRET	Parse(CIstream* pIOstream);
	virtual MRET	Built(COstream* pIOstream);
	virtual MRET	GetLength(Uint32& nLength);

public:
	CUIScpScuRole();
	virtual ~CUIScpScuRole();
};


class CUIImpVerName : public CUserInfoItem  
{
private:
	struct CHead {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
	} m_Head;

	CString			m_strName;

public:
		LPCTSTR		GetValue()				{ return this->m_strName; }

public:
	virtual BYTE	GetLabel()				{ return this->m_Head.Label; }
	virtual MRET	Parse(CIstream* pIOstream);
	virtual MRET	Built(COstream* pIOstream);
	virtual MRET	GetLength(Uint32& nLength);

public:
	CUIImpVerName();
	virtual ~CUIImpVerName();
};


class CUISOPClassExt : public CUserInfoItem  
{
private:
	struct CHead {
		BYTE		Label;
		BYTE		Res1;
		Uint16		Len;
		Uint16		UIDLen;
	} m_Head;

	CString			m_strUID;
	LPBYTE			m_lpInfo;

public:
			MRET	SetValue(LPCTSTR lpUID, LPBYTE lpValue, Uint16 wLength);
			LPCTSTR	GetSOPClassUID()		{ return this->m_strUID; }
			LPBYTE	GetValue()				{ return this->m_lpInfo; }

public:
	virtual BYTE	GetLabel()				{ return this->m_Head.Label; }
	virtual MRET	Parse(CIstream* pIOstream);
	virtual MRET	Built(COstream* pIOstream);
	virtual MRET	GetLength(Uint32& nLength);

public:
	CUISOPClassExt();
	virtual ~CUISOPClassExt();
};


class CPDUPDataTF : public CPDU  
{
friend class CIProducerNetwork;

private:
	struct CPrePDV {
		Uint32		Len;
		BYTE		ContextID;
		BYTE		ControlHeader;
	};

	BOOL			m_bCompleted;
	BYTE			m_nContextID;

	Uint32			m_nLength;	// PDV Value
	LPBYTE			m_lpBuffer;	// PDV Value

	CObCommand*		m_pObCommand;

protected:
	virtual MRET	Send(CNode* pConnect)	{ return ME_ERR_FUNCTION; }
	virtual MRET	Parse();
	virtual MRET	Built()					{ return ME_ERR_FUNCTION; }
	virtual MRET	GetLength()				{ return ME_ERR_FUNCTION; }

private:
			MRET	Send(CNode* pConnect, Uint32 nMaxLength, BYTE nContextID, BOOL bCommand, LPBYTE lpStream, Uint32 nLength, CService* pService = NULL);

public:
			BYTE	GetContextID()			{ return this->m_nContextID; }
			CObCommand*	GetCommandObject(BOOL bRemove = FALSE);
			MRET	ParseFullMessage(CElementSet*& pDataSet, LPCTSTR lpTS);

public:
			MRET	Send(CNode* pConnect, Uint32 nMaxLength, BYTE nContextID, LPCTSTR lpTS, CObCommand* pObCommand, CObBasic* pDataObject);
			MRET	Send(CNode* pConnect, Uint32 nMaxLength, BYTE nContextID, CObCommand* pObCommand, LPBYTE lpStream, Uint32 nLength, CService* pService = NULL);

public:
	CPDUPDataTF();
	virtual ~CPDUPDataTF();
};


class CPDUTerminate : public CPDU  
{
private:
	struct CHead {
		BYTE		Res1;
		BYTE		Result;
		BYTE		Source;
		BYTE		Reason;
	} m_Head;

protected:
	virtual MRET	Parse();
	virtual MRET	Built();
	virtual MRET	GetLength();

public:
			MRET	BuildAAssociateAJ(BYTE Result, BYTE Source, BYTE Reason);
			MRET	BuildAReleaseRQ();
			MRET	BuildAReleaseRP();
			MRET	BuildAAbort(BYTE Source, BYTE Reason);
			BYTE	GetResult()				{ return this->m_Head.Result; }
			BYTE	GetSource()				{ return this->m_Head.Source; }
			BYTE	GetReason()				{ return this->m_Head.Reason; }

public:
	CPDUTerminate();
	virtual ~CPDUTerminate();
};

#pragma pack()

#endif // !defined(AFX_PDU_H__394E1D14_65EA_4A14_8767_DEADCE35F23C__INCLUDED_)
