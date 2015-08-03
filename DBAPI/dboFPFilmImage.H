// dboFPFilmImage.H : Declaration of the CdboFPFilmImage class

#ifndef __DBOFPFILMIMAGE_H_
#define __DBOFPFILMIMAGE_H_

class CdboFPFilmImageAccessor
{
public:
	LONG m_FilmImageIndex;
	LONG m_FilmImageFilmBox;
	LONG m_FilmImageFilmSession;
	LONG m_FilmImagePosition;
	TCHAR m_FilmImagePolarity[17];
	TCHAR m_FilmImageMagnification[17];
	TCHAR m_FilmImageSmoothing[17];
	TCHAR m_FilmImageConfiguration[513];
	TCHAR m_FilmImageRequestedSize[17];
	TCHAR m_FilmImageDecimateCrop[17];
	TCHAR m_FilmImagePhotometric[17];
	LONG m_FilmImageRows;
	LONG m_FilmImageColumns;
	LONG m_FilmImageBitsAllocated;
	LONG m_FilmImageBitsStored;
	TCHAR m_FilmImageImageNumber[17];
	TCHAR m_FilmImageFrameNumber[65];
	TCHAR m_FilmImageSOPInstUID[65];
	TCHAR m_FilmImageSOPClassUID[65];
	TCHAR m_FilmImageSeriesInstUID[65];
	TCHAR m_FilmImageStudiesInstUID[65];
	TCHAR m_FilmImagePatientsID[65];
	TCHAR m_ImageReadAccessionNumber[65];
	TCHAR m_ImageReadPatientsID[65];
	TCHAR m_ImageReadPatientsName[65];

BEGIN_COLUMN_MAP(CdboFPFilmImageAccessor)
	COLUMN_ENTRY(1, m_FilmImageIndex)
	COLUMN_ENTRY(2, m_FilmImageFilmBox)
	COLUMN_ENTRY(3, m_FilmImageFilmSession)
	COLUMN_ENTRY(4, m_FilmImagePosition)
	COLUMN_ENTRY(5, m_FilmImagePolarity)
	COLUMN_ENTRY(6, m_FilmImageMagnification)
	COLUMN_ENTRY(7, m_FilmImageSmoothing)
	COLUMN_ENTRY(8, m_FilmImageConfiguration)
	COLUMN_ENTRY(9, m_FilmImageRequestedSize)
	COLUMN_ENTRY(10, m_FilmImageDecimateCrop)
	COLUMN_ENTRY(11, m_FilmImagePhotometric)
	COLUMN_ENTRY(12, m_FilmImageRows)
	COLUMN_ENTRY(13, m_FilmImageColumns)
	COLUMN_ENTRY(14, m_FilmImageBitsAllocated)
	COLUMN_ENTRY(15, m_FilmImageBitsStored)
	COLUMN_ENTRY(16, m_FilmImageImageNumber)
	COLUMN_ENTRY(17, m_FilmImageFrameNumber)
	COLUMN_ENTRY(18, m_FilmImageSOPInstUID)
	COLUMN_ENTRY(19, m_FilmImageSOPClassUID)
	COLUMN_ENTRY(20, m_FilmImageSeriesInstUID)
	COLUMN_ENTRY(21, m_FilmImageStudiesInstUID)
	COLUMN_ENTRY(22, m_FilmImagePatientsID)
	COLUMN_ENTRY(23, m_ImageReadAccessionNumber)
	COLUMN_ENTRY(24, m_ImageReadPatientsID)
	COLUMN_ENTRY(25, m_ImageReadPatientsName)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboFPFilmImageAccessor, _T(" \
	SELECT \
		FilmImageIndex, \
		FilmImageFilmBox, \
		FilmImageFilmSession, \
		FilmImagePosition, \
		FilmImagePolarity, \
		FilmImageMagnification, \
		FilmImageSmoothing, \
		FilmImageConfiguration, \
		FilmImageRequestedSize, \
		FilmImageDecimateCrop, \
		FilmImagePhotometric, \
		FilmImageRows, \
		FilmImageColumns, \
		FilmImageBitsAllocated, \
		FilmImageBitsStored, \
		FilmImageImageNumber, \
		FilmImageFrameNumber, \
		FilmImageSOPInstUID, \
		FilmImageSOPClassUID, \
		FilmImageSeriesInstUID, \
		FilmImageStudiesInstUID, \
		FilmImagePatientsID, \
		ImageReadAccessionNumber, \
		ImageReadPatientsID, \
		ImageReadPatientsName  \
		FROM FPFilmImage"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOFPFILMIMAGE_H_
