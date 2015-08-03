// ModuleViewer.h: interface for the CModuleViewer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULEVIEWER_H__1AE2F7F1_F7D6_4380_8986_5FF287D247CE__INCLUDED_)
#define AFX_MODULEVIEWER_H__1AE2F7F1_F7D6_4380_8986_5FF287D247CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

//////////////////////////////////////////////////////////////////////
// eRadViewer.dll

typedef MRET	(*VIEWER_SetParameter)		(CString strEISDatabase, CString strAETitle, CString strIPAddress, UINT nPORTNumber);
typedef MRET	(*VIEWER_OpenConfiguration)	();
typedef MRET	(*VIEWER_Start)				(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName);
typedef MRET	(*VIEWER_Close)				();
typedef MRET	(*VIEWER_PACSOpen)			(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
typedef MRET	(*VIEWER_PACSFilm)			(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
typedef MRET	(*VIEWER_LocalPACSOpen)		(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
typedef MRET	(*VIEWER_LocalPACSFilm)		(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);

typedef MRET	(*VIEWER_SendImages)		(CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
typedef MRET	(*VIEWER_OpenLocalPACS)		(LONG nStudiesIndex);

class CModuleViewer  
{
private:
	HMODULE						m_hModule;

private:
	MRET						LoadModule();

private:
	VIEWER_SetParameter			m_pSetParameter;
	VIEWER_OpenConfiguration	m_pOpenConfiguration;
	VIEWER_Start				m_pStart;
	VIEWER_Close				m_pClose;
	VIEWER_PACSOpen				m_pPACSOpen;
	VIEWER_PACSFilm				m_pPACSFilm;
	VIEWER_LocalPACSOpen		m_pLocalPACSOpen;
	VIEWER_LocalPACSFilm		m_pLocalPACSFilm;

public:
	VIEWER_SendImages			m_pSendImages;
	VIEWER_OpenLocalPACS		m_pOpenLocalPACS;

public:
	MRET						SetParameter(CString strEISDatabase, CString strAETitle, CString strIPAddress, UINT nPORTNumber);
	MRET						OpenConfiguration();

public:
	MRET						Start(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName);
	MRET						Close();

public:
	MRET						PACSOpen(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
	MRET						PACSFilm(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);

public:
	MRET						LocalPACSOpen(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
	MRET						LocalPACSFilm(LONG nStudiesIndex, CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);

public:
	MRET						SendImages(CString strPatientsID, CString strAccessionNumber, CString strStudiesInstUID);
	MRET						OpenLocalPACS(LONG nStudiesIndex);

public:
	CModuleViewer();
	virtual ~CModuleViewer();
};

#endif // !defined(AFX_MODULEVIEWER_H__1AE2F7F1_F7D6_4380_8986_5FF287D247CE__INCLUDED_)
