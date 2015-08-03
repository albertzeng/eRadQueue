// dboStorageOrderStudies.H : Declaration of the CdboStorageOrderStudies class

#ifndef __DBOSTORAGEORDERSTUDIES_H_
#define __DBOSTORAGEORDERSTUDIES_H_

class CdboStorageOrderStudiesAccessor
{
public:
	LONG m_SOSOrder;
	LONG m_SOSStudies;
	LONG m_SOSSeries;
	LONG m_SOSImages;

BEGIN_COLUMN_MAP(CdboStorageOrderStudiesAccessor)
	COLUMN_ENTRY(1, m_SOSOrder)
	COLUMN_ENTRY(2, m_SOSStudies)
	COLUMN_ENTRY(3, m_SOSSeries)
	COLUMN_ENTRY(4, m_SOSImages)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboStorageOrderStudiesAccessor, _T(" \
	SELECT \
		SOSOrder, \
		SOSStudies, \
		SOSSeries, \
		SOSImages  \
		FROM StorageOrderStudies"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOSTORAGEORDERSTUDIES_H_
