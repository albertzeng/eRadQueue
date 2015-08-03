// ServiceClass.h: interface for the CServiceClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVICECLASS_H__88ED1124_248E_4E6E_9616_960906337D11__INCLUDED_)
#define AFX_SERVICECLASS_H__88ED1124_248E_4E6E_9616_960906337D11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDCMInfo;
class CImageFile;

class CServiceClass  
{
private:
	BOOL					m_bServiceProvider;

public:
	CNode*					m_pNode;		// Refer to another instance if Service Provider

protected:
	CPDUAssociate*			m_pAAssociateRQ;
	CPDUAssociate*			m_pAAssociateAC;// Refer to another instance if Service Provider

	STRING_ARRAY			m_AbstractSyntax;
	STRING_ARRAY			m_TransferSyntax;

public:
	CPDUAssociate*			GetAAssociateAC()	{ return this->m_pAAssociateAC; }

// Service User
public:
			MRET			BuildAssociation(LPCTSTR lpAETitle, CNode* pLocalNode = NULL);
			MRET			BuildAssociation(CNode* pServerNode, CNode* pLocalNode = NULL);
			MRET			AssociationNegotiation(LPCTSTR lpCallingAETitle);
			MRET			ReleaseAssociation();

protected:
	virtual MRET			BuildPresContext();
	virtual MRET			BuildUserInfo()	{ return ME_OK; }

// Service Provider
public:
	virtual STRING_ARRAY*	GetTransferableTS(LPCTSTR lpAS)	{ return &this->m_TransferSyntax; }
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect);
	virtual	CServiceClass*	CreateContext(CNode* pNode, CPDUAssociate* pAAssociateAC)	{ return NULL; }
	virtual MRET			ContextStart()	{ return ME_OK; }
	virtual MRET			ContextClose(MRET nReturnCode)	{ return ME_OK; }
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }

public:
	virtual MRET			AnswerRoleSelection(CUIScpScuRole* pRequest, CUIScpScuRole*& pResponse)	{ return ME_OK; }
	virtual MRET			AnswerExtendedNegotiation(CUISOPClassExt* pRequest, CUISOPClassExt*& pResponse)	{ return ME_OK; }

public:
	CServiceClass();
	virtual ~CServiceClass();
};


class CEchoService : public CServiceClass, public CService  
{
// Service User
public:
			MRET			Echo(LPCTSTR lpAETitle);
			MRET			Echo(CNode* pServerNode);
	virtual MRET			Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);

protected:
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)	{ return ME_OK; }

// Service Provider
public:
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return (new CEchoService); }

protected:
	virtual MRET			OnRequest();
	virtual MRET			Response(CObCommand* pResponseCommand, CObBasic* pResponseObject = NULL);

public:
	CEchoService();
	virtual ~CEchoService();
};


class CMwlService : public CServiceClass, public CCFind  
{
public:
	COBList<CObMwlManagement>	m_ObMwlManagementList;

// Service User
public:
			MRET			Find(LPCTSTR lpAETitle, CObMwlManagement* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			Find(CNode* pServerNode, CObMwlManagement* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

protected:
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

// Service Provider
public:
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect)	{ return ((pConnect->m_nServiceMask & ESP_C_FIND_MWL) == 0) ? FALSE : CServiceClass::CanProcess(lpAS, pConnect); }
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }	// Must be Overloaded

protected:
			MRET			AddObject(CObMwlManagement* pObject)	{ this->m_ObMwlManagementList.AddTail(pObject); return ME_OK; }
	virtual MRET			OnRequest();
	virtual MRET			OnFind(CObMwlManagement* pObMwl)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

public:
	CMwlService();
	virtual ~CMwlService();
};


class CGpwlService : public CServiceClass, public CCFind  
{
public:
	COBList<CObGpwlManagement>	m_ObGpwlManagementList;

// Service User
public:
			MRET			Find(LPCTSTR lpAETitle, CObGpwlManagement* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			Find(CNode* pServerNode, CObGpwlManagement* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

protected:
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

// Service Provider
public:
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect)	{ return ((pConnect->m_nServiceMask & ESP_C_FIND_GPWL) == 0) ? FALSE : CServiceClass::CanProcess(lpAS, pConnect); }
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }	// Must be Overloaded

protected:
			MRET			AddObject(CObGpwlManagement* pObject)	{ this->m_ObGpwlManagementList.AddTail(pObject); return ME_OK; }
	virtual MRET			OnRequest();
	virtual MRET			OnFind(CObGpwlManagement* pObGpwl)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

public:
	CGpwlService();
	virtual ~CGpwlService();
};


class CFindService : public CServiceClass, public CCFind  
{
protected:
	E_QR_MODE				m_eMode;
	E_QR_LEVEL				m_eLevel;

public:
	COBList<CObQR>			m_ObResultList;

// Service User
protected:
	virtual MRET			BuildPresContext();
	virtual MRET			BuildUserInfo();

public:
			MRET			Find(LPCTSTR lpAETitle, CObQR* pRequestObject, E_QR_MODE eMode, E_QR_LEVEL eLevel, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			Find(CNode* pServerNode, CObQR* pRequestObject, E_QR_MODE eMode, E_QR_LEVEL eLevel, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

protected:
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

// Service Provider
public:
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect)	{ return ((pConnect->m_nServiceMask & ESP_C_FIND) == 0) ? FALSE : CServiceClass::CanProcess(lpAS, pConnect); }
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }	// Must be Overloaded

public:
	virtual MRET			AnswerExtendedNegotiation(CUISOPClassExt* pRequest, CUISOPClassExt*& pResponse);

protected:
			MRET			AddObject(CObQR* pObject)	{ this->m_ObResultList.AddTail(pObject); return ME_OK; }
			MRET			SendObject(CObQR* pObject);
	virtual MRET			OnRequest();
	virtual MRET			OnFind(CObQR* pObQR)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

public:
	CFindService();
	virtual ~CFindService();
};


class CGetService : public CServiceClass, public CCGet  
{
public:
	Uint16					m_nFileCount;
	Uint16					m_nCompleted;
	Uint16					m_nFailed;
	Uint16					m_nWarning;

protected:
	E_QR_MODE				m_eMode;
	E_QR_LEVEL				m_eLevel;
	COBList<CImageFile>*	m_pFileList;	// C-GET SCP
	CObRetrieveResponse		m_obRetrieveResponse;	// C-GET SCP

// Service User
protected:
	virtual MRET			BuildPresContext();
	virtual MRET			BuildUserInfo();

public:
			MRET			RetrieveImages(LPCTSTR lpAETitle, CObQR* pRequestObject, E_QR_MODE eMode, E_QR_LEVEL eLevel, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			RetrieveImages(CNode* pServerNode, CObQR* pRequestObject, E_QR_MODE eMode, E_QR_LEVEL eLevel, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			OnRetrieveImages(CObQR* pRequestObject, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

	virtual MRET			OnReceiveImage(CImageFile* pImageFile)		{ return ME_ERR_FUNCTION; }	// Must be Overloaded
			MRET			StoreResponse(CObCommand* pStoreRequest, Uint16 nStatus);	// C-STORE Response.

protected:
	virtual MRET			OnReceive(CPDUPDataTF* pPDataTF, Uint16* pStatus = NULL);
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

// Service Provider
public:
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect)	{ return ((pConnect->m_nServiceMask & ESP_C_GET) == 0) ? FALSE : CServiceClass::CanProcess(lpAS, pConnect); }
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }	// Must be Overloaded

public:
	virtual MRET			AnswerExtendedNegotiation(CUISOPClassExt* pRequest, CUISOPClassExt*& pResponse);

protected:
			MRET			AddFile(LPCTSTR lpFileName);
			MRET			SendFiles();
			MRET			SendResponse(Uint16 nStatus = 0);
	virtual MRET			OnRequest();
	virtual MRET			OnFind(CObQR* pObQR)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

public:
	CGetService();
	virtual ~CGetService();
};


class CMoveService : public CServiceClass, public CCMove  
{
friend class CStoreService;

protected:
	E_QR_MODE				m_eMode;
	E_QR_LEVEL				m_eLevel;
	Uint16					m_nMessageID;	// C-MOVE SCU
	CStoreService*			m_pStoreService;	// C-MOVE SCP
	CObRetrieveResponse		m_obRetrieveResponse;	// C-MOVE SCP

// Service User
protected:
	virtual MRET			BuildPresContext();
	virtual MRET			BuildUserInfo();

public:
	virtual MRET			Request(CObCommand* pRequestCommand, CObBasic* pRequestObject = NULL);
			MRET			TransferImages(LPCTSTR lpAETitle, CObQR* pRequestObject, E_QR_MODE eMode, E_QR_LEVEL eLevel, LPCTSTR lpMoveDestination = NULL, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			TransferImages(CNode* pServerNode, CObQR* pRequestObject, E_QR_MODE eMode, E_QR_LEVEL eLevel, LPCTSTR lpMoveDestination = NULL, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			OnTransferImages(CObQR* pRequestObject, LPCTSTR lpMoveDestination = NULL, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

	virtual MRET			OnReceiveImage(CImageFile* pImageFile)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

protected:
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

// Service Provider
public:
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect)	{ return ((pConnect->m_nServiceMask & ESP_C_MOVE) == 0) ? FALSE : CServiceClass::CanProcess(lpAS, pConnect); }
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }	// Must be Overloaded

public:
	virtual MRET			AnswerExtendedNegotiation(CUISOPClassExt* pRequest, CUISOPClassExt*& pResponse);

protected:
			MRET			AddFile(LPCTSTR lpFileName);
			MRET			SendResponse(Uint16 nStatus = 0);
	virtual MRET			OnRequest();
	virtual MRET			OnFind(CObQR* pObQR)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

public:
	CMoveService();
	virtual ~CMoveService();
};


class CStoreService : public CServiceClass, public CCStore  
{
friend class CMoveService;

public:
	Uint16					m_nFileCount;
	Uint16					m_nCompleted;
	Uint16					m_nFailed;
	Uint16					m_nWarning;

protected:
	COBList<CImageFile>*	m_pFileList;			// C-STORE SCU / C-MOVE SCP
	CMoveService*			m_pMoveService;			// C-MOVE SCP, Refer to another instance.

// Service User
public:
	virtual MRET			BuildPresContext();

public:
			MRET			AddFile(LPCTSTR lpFileName);
			MRET			AddFile(CImageFile* pImageFile);
			MRET			SendFiles(LPCTSTR lpAETitle, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			SendFiles(CNode* pServerNode, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);
			MRET			SendFiles(CMoveService* pMoveService, Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);	// C-MOVE SCP
			MRET			OnSendFiles(Uint16 nPriority = COMMAND_PRIORITY_MEDIUM);

protected:
	virtual MRET			OnResponse(CObCommand* pResponseCommand, CObBasic*& pResponseObject);

// Service Provider
public:
	virtual STRING_ARRAY*	GetTransferableTS(LPCTSTR lpAS);
	virtual BOOL			CanProcess(LPCTSTR lpAS, CNode* pConnect);
	virtual CService*		CreateService(CObCommand* pRequestCommand)	{ return NULL; }	// Must be Overloaded

public:
	virtual	MRET			AddFailed()	{ return ME_OK; }
	virtual	MRET			AddCompleted()	{ return ME_OK; }

public:
	virtual MRET			Execute(CPDUPDataTF* pPDataTF);
	virtual MRET			OnStoreRequest(CPDUPDataTF* pPDataTF, CMoveService* pMoveService = NULL);
	virtual MRET			OnReceiveImage(CImageFile* pImageFile)	{ return ME_ERR_FUNCTION; }	// Must be Overloaded

public:
	CStoreService();
	virtual ~CStoreService();
};

#endif // !defined(AFX_SERVICECLASS_H__88ED1124_248E_4E6E_9616_960906337D11__INCLUDED_)
