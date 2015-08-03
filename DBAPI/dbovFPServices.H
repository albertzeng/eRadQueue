// dbovFPServices.H : Declaration of the CdbovFPServices class

#ifndef __DBOVFPSERVICES_H_
#define __DBOVFPSERVICES_H_

class CdbovFPServicesAccessor
{
public:
	LONG m_ServicesIndex;
	LONG m_ServicesAssociation;
	LONG m_ServicesFilmSession;
	LONG m_ServicesCommandField;
	TCHAR m_ServicesSOPInstUID[65];
	TCHAR m_ServicesSOPClassUID[65];
	LONG m_ServicesID;
	LONG m_ServicesDataSet;
	LONG m_ServicesAnnexIndex;
	LONG m_ServicesFlags;
	TCHAR m_ServicesTS[17];
	LONG m_AnnexIndex;
	TCHAR m_AnnexSOPInstUID[65];
	TCHAR m_AnnexSOPClassUID[65];
	TCHAR m_AnnexFileName[101];
	LONG m_AnnexFileSize;
	LONG m_AnnexAvailable;
	LONG m_AnnexStorage;
	LONG m_AnnexStorageServer;
	LONG m_AnnexDVDIndex;
	TCHAR m_AnnexFileSetID[17];
	TCHAR m_AnnexFileSetUID[65];
	LONG m_AnnexFlags;
	TCHAR m_AnnexTS[17];
	TCHAR m_AnnexSourceAE[17];
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsDOB[17];
	TCHAR m_PatientsSex[17];
	TCHAR m_StudiesInstUID[65];
	TCHAR m_StudiesDate[17];
	TCHAR m_AccessionNumber[65];

BEGIN_COLUMN_MAP(CdbovFPServicesAccessor)
	COLUMN_ENTRY(1, m_ServicesIndex)
	COLUMN_ENTRY(2, m_ServicesAssociation)
	COLUMN_ENTRY(3, m_ServicesFilmSession)
	COLUMN_ENTRY(4, m_ServicesCommandField)
	COLUMN_ENTRY(5, m_ServicesSOPInstUID)
	COLUMN_ENTRY(6, m_ServicesSOPClassUID)
	COLUMN_ENTRY(7, m_ServicesID)
	COLUMN_ENTRY(8, m_ServicesDataSet)
	COLUMN_ENTRY(9, m_ServicesAnnexIndex)
	COLUMN_ENTRY(10, m_ServicesFlags)
	COLUMN_ENTRY(11, m_ServicesTS)
	COLUMN_ENTRY(12, m_AnnexIndex)
	COLUMN_ENTRY(13, m_AnnexSOPInstUID)
	COLUMN_ENTRY(14, m_AnnexSOPClassUID)
	COLUMN_ENTRY(15, m_AnnexFileName)
	COLUMN_ENTRY(16, m_AnnexFileSize)
	COLUMN_ENTRY(17, m_AnnexAvailable)
	COLUMN_ENTRY(18, m_AnnexStorage)
	COLUMN_ENTRY(19, m_AnnexStorageServer)
	COLUMN_ENTRY(20, m_AnnexDVDIndex)
	COLUMN_ENTRY(21, m_AnnexFileSetID)
	COLUMN_ENTRY(22, m_AnnexFileSetUID)
	COLUMN_ENTRY(23, m_AnnexFlags)
	COLUMN_ENTRY(24, m_AnnexTS)
	COLUMN_ENTRY(25, m_AnnexSourceAE)
	COLUMN_ENTRY(26, m_PatientsName)
	COLUMN_ENTRY(27, m_PatientsID)
	COLUMN_ENTRY(28, m_PatientsDOB)
	COLUMN_ENTRY(29, m_PatientsSex)
	COLUMN_ENTRY(30, m_StudiesInstUID)
	COLUMN_ENTRY(31, m_StudiesDate)
	COLUMN_ENTRY(32, m_AccessionNumber)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovFPServicesAccessor, _T(" \
	SELECT \
		ServicesIndex, \
		ServicesAssociation, \
		ServicesFilmSession, \
		ServicesCommandField, \
		ServicesSOPInstUID, \
		ServicesSOPClassUID, \
		ServicesID, \
		ServicesDataSet, \
		ServicesAnnexIndex, \
		ServicesFlags, \
		ServicesTS, \
		AnnexIndex, \
		AnnexSOPInstUID, \
		AnnexSOPClassUID, \
		AnnexFileName, \
		AnnexFileSize, \
		AnnexAvailable, \
		AnnexStorage, \
		AnnexStorageServer, \
		AnnexDVDIndex, \
		AnnexFileSetID, \
		AnnexFileSetUID, \
		AnnexFlags, \
		AnnexTS, \
		AnnexSourceAE, \
		PatientsName, \
		PatientsID, \
		PatientsDOB, \
		PatientsSex, \
		StudiesInstUID, \
		StudiesDate, \
		AccessionNumber  \
		FROM vFPServices"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVFPSERVICES_H_
