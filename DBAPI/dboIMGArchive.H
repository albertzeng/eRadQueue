// dboIMGArchive.H : Declaration of the CdboIMGArchive class

#ifndef __DBOIMGARCHIVE_H_
#define __DBOIMGARCHIVE_H_

class CdboIMGArchiveAccessor
{
public:
	LONG m_ArchiveIndex;
	LONG m_ArchiveStudies;
	LONG m_ArchiveSeries;
	TCHAR m_ArchiveTS[17];
	LONG m_ArchiveTimes;
	LONG m_ArchiveCode;
	TCHAR m_ArchiveMessage[65];
	TCHAR m_ArchiveReworkTS[17];
	TCHAR m_ArchivePatientsName[65];
	TCHAR m_ArchivePatientsAlias[65];
	TCHAR m_ArchivePatientsID[65];
	TCHAR m_ArchivePatientsDOB[17];
	TCHAR m_ArchivePatientsSex[17];
	TCHAR m_ArchiveStudiesInstUID[65];
	TCHAR m_ArchiveAccessionNumber[65];

BEGIN_COLUMN_MAP(CdboIMGArchiveAccessor)
	COLUMN_ENTRY(1, m_ArchiveIndex)
	COLUMN_ENTRY(2, m_ArchiveStudies)
	COLUMN_ENTRY(3, m_ArchiveSeries)
	COLUMN_ENTRY(4, m_ArchiveTS)
	COLUMN_ENTRY(5, m_ArchiveTimes)
	COLUMN_ENTRY(6, m_ArchiveCode)
	COLUMN_ENTRY(7, m_ArchiveMessage)
	COLUMN_ENTRY(8, m_ArchiveReworkTS)
	COLUMN_ENTRY(9, m_ArchivePatientsName)
	COLUMN_ENTRY(10, m_ArchivePatientsAlias)
	COLUMN_ENTRY(11, m_ArchivePatientsID)
	COLUMN_ENTRY(12, m_ArchivePatientsDOB)
	COLUMN_ENTRY(13, m_ArchivePatientsSex)
	COLUMN_ENTRY(14, m_ArchiveStudiesInstUID)
	COLUMN_ENTRY(15, m_ArchiveAccessionNumber)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboIMGArchiveAccessor, _T(" \
	SELECT \
		ArchiveIndex, \
		ArchiveStudies, \
		ArchiveSeries, \
		ArchiveTS, \
		ArchiveTimes, \
		ArchiveCode, \
		ArchiveMessage, \
		ArchiveReworkTS, \
		ArchivePatientsName, \
		ArchivePatientsAlias, \
		ArchivePatientsID, \
		ArchivePatientsDOB, \
		ArchivePatientsSex, \
		ArchiveStudiesInstUID, \
		ArchiveAccessionNumber  \
		FROM IMGArchive"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOIMGARCHIVE_H_
