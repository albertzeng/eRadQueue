// dboPACSFailedImages.H : Declaration of the CdboPACSFailedImages class

#ifndef __DBOPACSFAILEDIMAGES_H_
#define __DBOPACSFAILEDIMAGES_H_

class CdboPACSFailedImagesAccessor
{
public:
	LONG m_FailedIndex;
	TCHAR m_FailedImagesFileName[101];
	TCHAR m_FailedTS[17];
	LONG m_FailedTimes;
	LONG m_FailedCode;
	TCHAR m_FailedMessage[65];
	TCHAR m_FailedReworkTS[17];

BEGIN_COLUMN_MAP(CdboPACSFailedImagesAccessor)
	COLUMN_ENTRY(1, m_FailedIndex)
	COLUMN_ENTRY(2, m_FailedImagesFileName)
	COLUMN_ENTRY(3, m_FailedTS)
	COLUMN_ENTRY(4, m_FailedTimes)
	COLUMN_ENTRY(5, m_FailedCode)
	COLUMN_ENTRY(6, m_FailedMessage)
	COLUMN_ENTRY(7, m_FailedReworkTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboPACSFailedImagesAccessor, _T(" \
	SELECT \
		FailedIndex, \
		FailedImagesFileName, \
		FailedTS, \
		FailedTimes, \
		FailedCode, \
		FailedMessage, \
		FailedReworkTS  \
		FROM PACSFailedImages"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOPACSFAILEDIMAGES_H_
