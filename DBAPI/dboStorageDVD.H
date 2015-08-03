// dboStorageDVD.H : Declaration of the CdboStorageDVD class

#ifndef __DBOSTORAGEDVD_H_
#define __DBOSTORAGEDVD_H_

class CdboStorageDVDAccessor
{
public:
	LONG m_DVDIndex;
	LONG m_HostsIndex;
	TCHAR m_FileSetID[17];
	TCHAR m_FileSetDescriptor[65];
	TCHAR m_FileSetUID[65];
	TCHAR m_DVDRemark[65];
	TCHAR m_TSFrom[17];
	TCHAR m_TSTo[17];
	LONG m_DVDPatients;
	LONG m_DVDStudies;
	LONG m_DVDSeries;
	LONG m_DVDImages;
	double m_DVDSpace;
	LONG m_DVDState;
	LONG m_DVDFlags;
	TCHAR m_DVDTS[17];
	TCHAR m_DVDTrack[20480];

BEGIN_COLUMN_MAP(CdboStorageDVDAccessor)
	COLUMN_ENTRY(1, m_DVDIndex)
	COLUMN_ENTRY(2, m_HostsIndex)
	COLUMN_ENTRY(3, m_FileSetID)
	COLUMN_ENTRY(4, m_FileSetDescriptor)
	COLUMN_ENTRY(5, m_FileSetUID)
	COLUMN_ENTRY(6, m_DVDRemark)
	COLUMN_ENTRY(7, m_TSFrom)
	COLUMN_ENTRY(8, m_TSTo)
	COLUMN_ENTRY(9, m_DVDPatients)
	COLUMN_ENTRY(10, m_DVDStudies)
	COLUMN_ENTRY(11, m_DVDSeries)
	COLUMN_ENTRY(12, m_DVDImages)
	COLUMN_ENTRY(13, m_DVDSpace)
	COLUMN_ENTRY(14, m_DVDState)
	COLUMN_ENTRY(15, m_DVDFlags)
	COLUMN_ENTRY(16, m_DVDTS)
	COLUMN_ENTRY(17, m_DVDTrack)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboStorageDVDAccessor, _T(" \
	SELECT \
		DVDIndex, \
		HostsIndex, \
		FileSetID, \
		FileSetDescriptor, \
		FileSetUID, \
		DVDRemark, \
		TSFrom, \
		TSTo, \
		DVDPatients, \
		DVDStudies, \
		DVDSeries, \
		DVDImages, \
		DVDSpace, \
		DVDState, \
		DVDFlags, \
		DVDTS, \
		DVDTrack  \
		FROM StorageDVD"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOSTORAGEDVD_H_
