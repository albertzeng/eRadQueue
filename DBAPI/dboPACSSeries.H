// dboPACSSeries.H : Declaration of the CdboPACSSeries class

#ifndef __DBOPACSSERIES_H_
#define __DBOPACSSERIES_H_

class CdboPACSSeriesAccessor
{
public:
	LONG m_SeriesIndex;
	LONG m_PatientsIndex;
	LONG m_StudiesIndex;
	TCHAR m_SeriesInstUID[65];
	TCHAR m_SeriesNumber[17];
	TCHAR m_SeriesDate[17];
	TCHAR m_SeriesTime[17];
	TCHAR m_SeriesModality[17];
	TCHAR m_SeriesBodyPart[17];
	TCHAR m_SeriesFrameUID[65];
	LONG m_SeriesImages;
	LONG m_SeriesAvailable;
	LONG m_SeriesArchive;
	LONG m_SeriesStorage;
	LONG m_SeriesDVDIndex;
	TCHAR m_SeriesFileSetID[17];
	TCHAR m_SeriesFileSetUID[65];
	LONG m_SeriesFlags;
	TCHAR m_SeriesTS[17];

BEGIN_COLUMN_MAP(CdboPACSSeriesAccessor)
	COLUMN_ENTRY(1, m_SeriesIndex)
	COLUMN_ENTRY(2, m_PatientsIndex)
	COLUMN_ENTRY(3, m_StudiesIndex)
	COLUMN_ENTRY(4, m_SeriesInstUID)
	COLUMN_ENTRY(5, m_SeriesNumber)
	COLUMN_ENTRY(6, m_SeriesDate)
	COLUMN_ENTRY(7, m_SeriesTime)
	COLUMN_ENTRY(8, m_SeriesModality)
	COLUMN_ENTRY(9, m_SeriesBodyPart)
	COLUMN_ENTRY(10, m_SeriesFrameUID)
	COLUMN_ENTRY(11, m_SeriesImages)
	COLUMN_ENTRY(12, m_SeriesAvailable)
	COLUMN_ENTRY(13, m_SeriesArchive)
	COLUMN_ENTRY(14, m_SeriesStorage)
	COLUMN_ENTRY(15, m_SeriesDVDIndex)
	COLUMN_ENTRY(16, m_SeriesFileSetID)
	COLUMN_ENTRY(17, m_SeriesFileSetUID)
	COLUMN_ENTRY(18, m_SeriesFlags)
	COLUMN_ENTRY(19, m_SeriesTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboPACSSeriesAccessor, _T(" \
	SELECT \
		SeriesIndex, \
		PatientsIndex, \
		StudiesIndex, \
		SeriesInstUID, \
		SeriesNumber, \
		SeriesDate, \
		SeriesTime, \
		SeriesModality, \
		SeriesBodyPart, \
		SeriesFrameUID, \
		SeriesImages, \
		SeriesAvailable, \
		SeriesArchive, \
		SeriesStorage, \
		SeriesDVDIndex, \
		SeriesFileSetID, \
		SeriesFileSetUID, \
		SeriesFlags, \
		SeriesTS  \
		FROM PACSSeries"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOPACSSERIES_H_
