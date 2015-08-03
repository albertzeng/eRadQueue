// dbovIMGArchive.H : Declaration of the CdbovIMGArchive class

#ifndef __DBOVIMGARCHIVE_H_
#define __DBOVIMGARCHIVE_H_

class CdbovIMGArchiveAccessor
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
	TCHAR m_SeriesInstUID[65];
	TCHAR m_SeriesNumber[17];
	TCHAR m_SeriesModality[17];
	TCHAR m_SeriesBodyPart[17];
	LONG m_SeriesImages;
	LONG m_SeriesArchive;
	LONG m_SeriesFlags;
	TCHAR m_StudiesDate[17];
	TCHAR m_StudiesTime[17];
	TCHAR m_AccessionNumber[65];
	TCHAR m_StudiesDescription[65];
	TCHAR m_StudiesID[17];
	LONG m_StudiesSeries;
	LONG m_StudiesImages;
	LONG m_StudiesArchive;
	LONG m_StudiesFlags;
	TCHAR m_StudiesTargetAE[101];
	LONG m_PatientsIndex;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsAlias[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsDOB[17];
	TCHAR m_PatientsSex[17];
	LONG m_PatientsFlags;
	TCHAR m_PatientsSourceAE[17];

BEGIN_COLUMN_MAP(CdbovIMGArchiveAccessor)
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
	COLUMN_ENTRY(16, m_SeriesInstUID)
	COLUMN_ENTRY(17, m_SeriesNumber)
	COLUMN_ENTRY(18, m_SeriesModality)
	COLUMN_ENTRY(19, m_SeriesBodyPart)
	COLUMN_ENTRY(20, m_SeriesImages)
	COLUMN_ENTRY(21, m_SeriesArchive)
	COLUMN_ENTRY(22, m_SeriesFlags)
	COLUMN_ENTRY(23, m_StudiesDate)
	COLUMN_ENTRY(24, m_StudiesTime)
	COLUMN_ENTRY(25, m_AccessionNumber)
	COLUMN_ENTRY(26, m_StudiesDescription)
	COLUMN_ENTRY(27, m_StudiesID)
	COLUMN_ENTRY(28, m_StudiesSeries)
	COLUMN_ENTRY(29, m_StudiesImages)
	COLUMN_ENTRY(30, m_StudiesArchive)
	COLUMN_ENTRY(31, m_StudiesFlags)
	COLUMN_ENTRY(32, m_StudiesTargetAE)
	COLUMN_ENTRY(33, m_PatientsIndex)
	COLUMN_ENTRY(34, m_PatientsName)
	COLUMN_ENTRY(35, m_PatientsAlias)
	COLUMN_ENTRY(36, m_PatientsID)
	COLUMN_ENTRY(37, m_PatientsDOB)
	COLUMN_ENTRY(38, m_PatientsSex)
	COLUMN_ENTRY(39, m_PatientsFlags)
	COLUMN_ENTRY(40, m_PatientsSourceAE)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovIMGArchiveAccessor, _T(" \
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
		ArchiveAccessionNumber, \
		SeriesInstUID, \
		SeriesNumber, \
		SeriesModality, \
		SeriesBodyPart, \
		SeriesImages, \
		SeriesArchive, \
		SeriesFlags, \
		StudiesDate, \
		StudiesTime, \
		AccessionNumber, \
		StudiesDescription, \
		StudiesID, \
		StudiesSeries, \
		StudiesImages, \
		StudiesArchive, \
		StudiesFlags, \
		StudiesTargetAE, \
		PatientsIndex, \
		PatientsName, \
		PatientsAlias, \
		PatientsID, \
		PatientsDOB, \
		PatientsSex, \
		PatientsFlags, \
		PatientsSourceAE  \
		FROM vIMGArchive"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVIMGARCHIVE_H_
