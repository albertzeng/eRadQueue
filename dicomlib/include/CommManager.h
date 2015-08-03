// CommManager.h: interface for the CCommManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMMANAGER_H__F3F8DF5B_9325_4CEA_8DE4_19A47D3FEF69__INCLUDED_)
#define AFX_COMMMANAGER_H__F3F8DF5B_9325_4CEA_8DE4_19A47D3FEF69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


typedef MRET (CALLBACK* NETWORK_PROC)(BOOL bSend, BOOL bReceive, Uint32 nSend, Uint32 nReceive);

class CCommManager  
{
private:
	CNode*					m_pLocalNode;
	COBList<CNode>*			m_pNodeList;
	COBList<CAcceptableAS>*	m_pAcceptableASList;
	COBList<CServiceClass>*	m_pServiceClassList;

private:
	COBList<CFileStorage>*	m_pFileStorageList;
	CString					m_strTmpSave;
	CString					m_strTrackSave;
	CString					m_strFileStorage;

private:
	BOOL					m_bInitialize;
	BOOL					m_bRun;
	Uint32					m_nThreadCount;
	HANDLE					m_hStopEvent;
	BOOL					m_bCheckAETitle;
	BOOL					m_bCheckIPAddress;
	BOOL					m_bTrackCommunication;

private:
	CRITICAL_SECTION		m_csCommManager;
	NETWORK_PROC			m_lpcbNetworkProc;

private:
	Uint32					m_nMaxLength;
	CString					m_strUIDRoot;
	CString					m_strImpClassUID;
	CString					m_strImpVersionName;

private:
	Uint32					m_nConnectTimeOut;
	Uint32					m_nSendTimeOut;
	Uint32					m_nReceiveTimeOut;

public:
	static MRET				Initialize(BOOL bNetworkListen = TRUE, BOOL CheckAETitle = TRUE, BOOL bCheckIPAddress = FALSE, BOOL bTrackCommunication = FALSE);
	static MRET				DeInitialize();

public:
	static DWORD WINAPI		ListenThreadProc(LPVOID lpvParameter);
	static DWORD WINAPI		AcceptThreadProc(LPVOID lpvParameter);

public:
	static MRET				ServiceProvide(CNode* pConnect, CPDUAssociate* pAAssociateAC, COBList<CServiceClass>* pContextList);

public:
	static MRET				AddRemoteNode(CNode* pNode);
	static MRET				AddServiceClass(CServiceClass* pServiceClass);
	static MRET				AddFileStorage(CFileStorage* pFileStorage);

public:
	static BOOL				SetLocalNode(CNode* pNode);
	static MRET				SetFileStorage(LPCTSTR lpFileStorage);
	static MRET				SetMaxLength(Uint32 nMaxLength);
	static MRET				SetUIDRoot(LPCTSTR lpUIDRoot);
	static MRET				SetImpClassUID(LPCTSTR lpUID);
	static MRET				SetImpVersionName(LPCTSTR lpName);
	static MRET				SetNetworkTimeOut(Uint32 nConnect, Uint32 nSend, Uint32 nReceive);
	static MRET				SetNetworkProc(NETWORK_PROC lpcbNetworkProc);

public:
	static CNode*			GetLocalNode();
	static LPCTSTR			GetFileStorage();
	static Uint32			GetMaxLength();
	static LPCTSTR			GetUIDRoot();
	static LPCTSTR			GetImpClassUID();
	static LPCTSTR			GetImpVersionName();
	static MRET				GetNetworkTimeOut(Uint32& nConnect, Uint32& nSend, Uint32& nReceive);
	static NETWORK_PROC		GetNetworkProc();

public:
	static CNode*			GetPeerNode(LPCTSTR lpAETitle);
	static COBList<CNode>*	GetRemodeNodeList();
	static COBList<CAcceptableAS>*	GetAcceptableASList();
	static CServiceClass*	GetServiceClass(LPCTSTR lpAS, CNode* pConnect);
	static COBList<CFileStorage>*	GetFileStorageList();
	static LPCTSTR			SelectFileStorage();
	static BOOL				GetCheckAETitle();
	static BOOL				GetCheckIPAddress();
	static BOOL				GetTrackCommunication();
	static CRITICAL_SECTION*GetCriticalSection();
	static LPCTSTR			GetNewUID(CString& strNewUID);
	static LPCTSTR			GetTMPFileName(CString& strFileName);
	static LPCTSTR			GetTrackFileName(CString& strFileName);
	static LPCTSTR			GetNewFileName(CString& strFileName, CObImage* pObImage, LPCTSTR lpDir = NULL);

public:
	CCommManager();
	virtual ~CCommManager();
};

#endif // !defined(AFX_COMMMANAGER_H__F3F8DF5B_9325_4CEA_8DE4_19A47D3FEF69__INCLUDED_)
