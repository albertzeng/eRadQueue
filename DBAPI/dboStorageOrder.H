// dboStorageOrder.H : Declaration of the CdboStorageOrder class

#ifndef __DBOSTORAGEORDER_H_
#define __DBOSTORAGEORDER_H_

class CdboStorageOrderAccessor
{
public:
	LONG m_OrderIndex;
	LONG m_OrderStorageServer;
	LONG m_OrderSubmit;
	TCHAR m_FileSetID[65];
	TCHAR m_FileSetDescriptor[65];
	TCHAR m_FileSetUID[65];
	TCHAR m_OrderRemark[65];
	LONG m_OrderStudies;
	LONG m_OrderSeries;
	LONG m_OrderImages;
	double m_OrderSpace;
	LONG m_OrderStatus;
	LONG m_OrderFlags;
	TCHAR m_OrderMedia[65];
	TCHAR m_OrderTS[65];
	TCHAR m_OrderTrack[20480];

BEGIN_COLUMN_MAP(CdboStorageOrderAccessor)
	COLUMN_ENTRY(1, m_OrderIndex)
	COLUMN_ENTRY(2, m_OrderStorageServer)
	COLUMN_ENTRY(3, m_OrderSubmit)
	COLUMN_ENTRY(4, m_FileSetID)
	COLUMN_ENTRY(5, m_FileSetDescriptor)
	COLUMN_ENTRY(6, m_FileSetUID)
	COLUMN_ENTRY(7, m_OrderRemark)
	COLUMN_ENTRY(8, m_OrderStudies)
	COLUMN_ENTRY(9, m_OrderSeries)
	COLUMN_ENTRY(10, m_OrderImages)
	COLUMN_ENTRY(11, m_OrderSpace)
	COLUMN_ENTRY(12, m_OrderStatus)
	COLUMN_ENTRY(13, m_OrderFlags)
	COLUMN_ENTRY(14, m_OrderMedia)
	COLUMN_ENTRY(15, m_OrderTS)
	COLUMN_ENTRY(16, m_OrderTrack)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboStorageOrderAccessor, _T(" \
	SELECT \
		OrderIndex, \
		OrderStorageServer, \
		OrderSubmit, \
		FileSetID, \
		FileSetDescriptor, \
		FileSetUID, \
		OrderRemark, \
		OrderStudies, \
		OrderSeries, \
		OrderImages, \
		OrderSpace, \
		OrderStatus, \
		OrderFlags, \
		OrderMedia, \
		OrderTS, \
		OrderTrack  \
		FROM StorageOrder"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOSTORAGEORDER_H_
