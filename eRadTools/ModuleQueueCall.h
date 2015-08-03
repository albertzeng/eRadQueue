// ModuleQueueCall.h: interface for the CModuleQueueCall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULEQUEUECALL_H__176DEAB6_7FF8_4449_89D3_782A9852D65B__INCLUDED_)
#define AFX_MODULEQUEUECALL_H__176DEAB6_7FF8_4449_89D3_782A9852D65B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

#define WM_QUEUE_CALL			WM_USER + 1974

enum E_QUEUE_CALL_ACTION
{
	E_QUEUE_CALL_ORDER,
	E_QUEUE_CALL_CAPTURE_REPORT,
	E_QUEUE_CALL_CAPTURE,
	E_QUEUE_CALL_REPORT,
	E_QUEUE_CALL_REPEAT,
	E_QUEUE_CALL_SELECT,
	E_QUEUE_CALL_COMPLETE,
	E_QUEUE_CALL_RESET,
	E_QUEUE_CALL_UNREADY,
	E_QUEUE_CALL_CANCEL,
	E_QUEUE_CALL_PRECALL
};

typedef MRET (CALLBACK* CALLBACK_QUEUE_CALL_PROC)		(LONG nQueueIndex, LONG nQueueCallAction);

//////////////////////////////////////////////////////////////////////
// eRadQueueCall.dll

typedef MRET	(*QUEUECALL_OpenConfiguration)			();
typedef MRET	(*QUEUECALL_SetQueueCallProc)			(CALLBACK_QUEUE_CALL_PROC lpcbQueueCallProc);
typedef MRET	(*QUEUECALL_StartQueueCall)				(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName);
typedef MRET	(*QUEUECALL_CloseQueueCall)				();
typedef MRET    (*QUEUECALL_QueueCallComplete)          (LONG nQueueIndex);
class CModuleQueueCall  
{
private:
	HMODULE						m_hModule;

private:
	MRET						LoadModule();

private:
	QUEUECALL_OpenConfiguration	m_pOpenConfiguration;
	QUEUECALL_SetQueueCallProc	m_pSetQueueCallProc;
	QUEUECALL_StartQueueCall	m_pStartQueueCall;
	QUEUECALL_CloseQueueCall	m_pCloseQueueCall;
	QUEUECALL_QueueCallComplete m_pQueueCallComplete;

public:
	MRET						OpenConfiguration();
	MRET						SetQueueCallProc(CALLBACK_QUEUE_CALL_PROC lpcbQueueCallProc);
	MRET						StartQueueCall(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName);
	MRET						CloseQueueCall();
	MRET                        QueueCallComplete(LONG nQueueIndex);
public:
	CModuleQueueCall();
	virtual ~CModuleQueueCall();
};

#endif // !defined(AFX_MODULEQUEUECALL_H__176DEAB6_7FF8_4449_89D3_782A9852D65B__INCLUDED_)
