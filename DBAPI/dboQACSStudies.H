// dboQACSStudies.H : Declaration of the CdboQACSStudies class

#ifndef __DBOQACSSTUDIES_H_
#define __DBOQACSSTUDIES_H_

class CdboQACSStudiesAccessor
{
public:
	LONG m_StudiesIndex;
	LONG m_PatientsIndex;
	TCHAR m_StudiesInstUID[65];
	TCHAR m_StudiesDate[17];
	TCHAR m_StudiesTime[17];
	TCHAR m_AccessionNumber[65];
	TCHAR m_StudiesDescription[65];
	TCHAR m_StudiesID[17];
	LONG m_StudiesSeries;
	LONG m_StudiesImages;
	LONG m_StudiesAvailable;
	LONG m_StudiesArchive;
	LONG m_StorageHostsIndex;
	LONG m_StorageState;
	LONG m_StudiesDVDIndex;
	TCHAR m_StudiesFileSetID[17];
	TCHAR m_StudiesFileSetUID[65];
	LONG m_StudiesFlags;
	TCHAR m_StudiesTS[17];
	TCHAR m_StudiesTargetAE[101];

BEGIN_COLUMN_MAP(CdboQACSStudiesAccessor)
	COLUMN_ENTRY(1, m_StudiesIndex)
	COLUMN_ENTRY(2, m_PatientsIndex)
	COLUMN_ENTRY(3, m_StudiesInstUID)
	COLUMN_ENTRY(4, m_StudiesDate)
	COLUMN_ENTRY(5, m_StudiesTime)
	COLUMN_ENTRY(6, m_AccessionNumber)
	COLUMN_ENTRY(7, m_StudiesDescription)
	COLUMN_ENTRY(8, m_StudiesID)
	COLUMN_ENTRY(9, m_StudiesSeries)
	COLUMN_ENTRY(10, m_StudiesImages)
	COLUMN_ENTRY(11, m_StudiesAvailable)
	COLUMN_ENTRY(12, m_StudiesArchive)
	COLUMN_ENTRY(13, m_StorageHostsIndex)
	COLUMN_ENTRY(14, m_StorageState)
	COLUMN_ENTRY(15, m_StudiesDVDIndex)
	COLUMN_ENTRY(16, m_StudiesFileSetID)
	COLUMN_ENTRY(17, m_StudiesFileSetUID)
	COLUMN_ENTRY(18, m_StudiesFlags)
	COLUMN_ENTRY(19, m_StudiesTS)
	COLUMN_ENTRY(20, m_StudiesTargetAE)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboQACSStudiesAccessor, _T(" \
	SELECT \
		StudiesIndex, \
		PatientsIndex, \
		StudiesInstUID, \
		StudiesDate, \
		StudiesTime, \
		AccessionNumber, \
		StudiesDescription, \
		StudiesID, \
		StudiesSeries, \
		StudiesImages, \
		StudiesAvailable, \
		StudiesArchive, \
		StorageHostsIndex, \
		StorageState, \
		StudiesDVDIndex, \
		StudiesFileSetID, \
		StudiesFileSetUID, \
		StudiesFlags, \
		StudiesTS, \
		StudiesTargetAE  \
		FROM QACSStudies"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOQACSSTUDIES_H_
