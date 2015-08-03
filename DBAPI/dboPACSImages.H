// dboPACSImages.H : Declaration of the CdboPACSImages class

#ifndef __DBOPACSIMAGES_H_
#define __DBOPACSIMAGES_H_

class CdboPACSImagesAccessor
{
public:
	LONG m_ImagesIndex;
	LONG m_PatientsIndex;
	LONG m_StudiesIndex;
	LONG m_SeriesIndex;
	TCHAR m_SOPInstUID[65];
	TCHAR m_SOPClassUID[65];
	TCHAR m_TransferSyntax[65];
	TCHAR m_ImagesNumber[17];
	TCHAR m_ImagesPhotometric[17];
	TCHAR m_ImagesPosition[65];
	TCHAR m_ImagesOrientation[101];
	TCHAR m_ImagesPixelSpacing[65];
	TCHAR m_ImagerPixelSpacing[65];
	LONG m_ImagesRows;
	LONG m_ImagesColumns;
	LONG m_BitsAllocated;
	LONG m_BitsStored;
	TCHAR m_ImagesFileName[101];
	LONG m_ImagesFileSize;
	LONG m_ImagesAvailable;
	LONG m_ImagesArchive;
	LONG m_ImagesCompression;
	LONG m_ImagesStorage;
	LONG m_DVDIndex;
	TCHAR m_FileSetID[17];
	TCHAR m_FileSetUID[65];
	LONG m_ImagesFlags;
	TCHAR m_ImagesTS[17];
	TCHAR m_ImagesSourceAE[17];

BEGIN_COLUMN_MAP(CdboPACSImagesAccessor)
	COLUMN_ENTRY(1, m_ImagesIndex)
	COLUMN_ENTRY(2, m_PatientsIndex)
	COLUMN_ENTRY(3, m_StudiesIndex)
	COLUMN_ENTRY(4, m_SeriesIndex)
	COLUMN_ENTRY(5, m_SOPInstUID)
	COLUMN_ENTRY(6, m_SOPClassUID)
	COLUMN_ENTRY(7, m_TransferSyntax)
	COLUMN_ENTRY(8, m_ImagesNumber)
	COLUMN_ENTRY(9, m_ImagesPhotometric)
	COLUMN_ENTRY(10, m_ImagesPosition)
	COLUMN_ENTRY(11, m_ImagesOrientation)
	COLUMN_ENTRY(12, m_ImagesPixelSpacing)
	COLUMN_ENTRY(13, m_ImagerPixelSpacing)
	COLUMN_ENTRY(14, m_ImagesRows)
	COLUMN_ENTRY(15, m_ImagesColumns)
	COLUMN_ENTRY(16, m_BitsAllocated)
	COLUMN_ENTRY(17, m_BitsStored)
	COLUMN_ENTRY(18, m_ImagesFileName)
	COLUMN_ENTRY(19, m_ImagesFileSize)
	COLUMN_ENTRY(20, m_ImagesAvailable)
	COLUMN_ENTRY(21, m_ImagesArchive)
	COLUMN_ENTRY(22, m_ImagesCompression)
	COLUMN_ENTRY(23, m_ImagesStorage)
	COLUMN_ENTRY(24, m_DVDIndex)
	COLUMN_ENTRY(25, m_FileSetID)
	COLUMN_ENTRY(26, m_FileSetUID)
	COLUMN_ENTRY(27, m_ImagesFlags)
	COLUMN_ENTRY(28, m_ImagesTS)
	COLUMN_ENTRY(29, m_ImagesSourceAE)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboPACSImagesAccessor, _T(" \
	SELECT \
		ImagesIndex, \
		PatientsIndex, \
		StudiesIndex, \
		SeriesIndex, \
		SOPInstUID, \
		SOPClassUID, \
		TransferSyntax, \
		ImagesNumber, \
		ImagesPhotometric, \
		ImagesPosition, \
		ImagesOrientation, \
		ImagesPixelSpacing, \
		ImagerPixelSpacing, \
		ImagesRows, \
		ImagesColumns, \
		BitsAllocated, \
		BitsStored, \
		ImagesFileName, \
		ImagesFileSize, \
		ImagesAvailable, \
		ImagesArchive, \
		ImagesCompression, \
		ImagesStorage, \
		DVDIndex, \
		FileSetID, \
		FileSetUID, \
		ImagesFlags, \
		ImagesTS, \
		ImagesSourceAE  \
		FROM PACSImages"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOPACSIMAGES_H_
