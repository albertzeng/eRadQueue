// dboFPFilmBox.H : Declaration of the CdboFPFilmBox class

#ifndef __DBOFPFILMBOX_H_
#define __DBOFPFILMBOX_H_

class CdboFPFilmBoxAccessor
{
public:
	LONG m_FilmBoxIndex;
	LONG m_FilmBoxFilmSession;
	LONG m_FilmBoxPRINT;
	TCHAR m_SOPInstUID[65];
	TCHAR m_SOPClassUID[65];
	TCHAR m_ImagesFileName[101];
	LONG m_ImagesFileSize;
	TCHAR m_FilmBoxImageFormat[513];
	TCHAR m_FilmBoxAnnotationFormat[17];
	TCHAR m_FilmBoxFilmOrientation[17];
	TCHAR m_FilmBoxFilmSizeID[17];
	TCHAR m_FilmBoxMagnification[17];
	TCHAR m_FilmBoxSmoothing[17];
	TCHAR m_FilmBoxBorderDensity[17];
	TCHAR m_FilmBoxEmptyImageDensity[17];
	LONG m_FilmBoxMinDensity;
	LONG m_FilmBoxMaxDensity;
	TCHAR m_FilmBoxTrim[17];
	TCHAR m_FilmBoxConfiguration[513];
	LONG m_FilmBoxIllumination;
	LONG m_FilmBoxAmbientLight;
	TCHAR m_FilmBoxResolutionID[17];

BEGIN_COLUMN_MAP(CdboFPFilmBoxAccessor)
	COLUMN_ENTRY(1, m_FilmBoxIndex)
	COLUMN_ENTRY(2, m_FilmBoxFilmSession)
	COLUMN_ENTRY(3, m_FilmBoxPRINT)
	COLUMN_ENTRY(4, m_SOPInstUID)
	COLUMN_ENTRY(5, m_SOPClassUID)
	COLUMN_ENTRY(6, m_ImagesFileName)
	COLUMN_ENTRY(7, m_ImagesFileSize)
	COLUMN_ENTRY(8, m_FilmBoxImageFormat)
	COLUMN_ENTRY(9, m_FilmBoxAnnotationFormat)
	COLUMN_ENTRY(10, m_FilmBoxFilmOrientation)
	COLUMN_ENTRY(11, m_FilmBoxFilmSizeID)
	COLUMN_ENTRY(12, m_FilmBoxMagnification)
	COLUMN_ENTRY(13, m_FilmBoxSmoothing)
	COLUMN_ENTRY(14, m_FilmBoxBorderDensity)
	COLUMN_ENTRY(15, m_FilmBoxEmptyImageDensity)
	COLUMN_ENTRY(16, m_FilmBoxMinDensity)
	COLUMN_ENTRY(17, m_FilmBoxMaxDensity)
	COLUMN_ENTRY(18, m_FilmBoxTrim)
	COLUMN_ENTRY(19, m_FilmBoxConfiguration)
	COLUMN_ENTRY(20, m_FilmBoxIllumination)
	COLUMN_ENTRY(21, m_FilmBoxAmbientLight)
	COLUMN_ENTRY(22, m_FilmBoxResolutionID)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboFPFilmBoxAccessor, _T(" \
	SELECT \
		FilmBoxIndex, \
		FilmBoxFilmSession, \
		FilmBoxPRINT, \
		SOPInstUID, \
		SOPClassUID, \
		ImagesFileName, \
		ImagesFileSize, \
		FilmBoxImageFormat, \
		FilmBoxAnnotationFormat, \
		FilmBoxFilmOrientation, \
		FilmBoxFilmSizeID, \
		FilmBoxMagnification, \
		FilmBoxSmoothing, \
		FilmBoxBorderDensity, \
		FilmBoxEmptyImageDensity, \
		FilmBoxMinDensity, \
		FilmBoxMaxDensity, \
		FilmBoxTrim, \
		FilmBoxConfiguration, \
		FilmBoxIllumination, \
		FilmBoxAmbientLight, \
		FilmBoxResolutionID  \
		FROM FPFilmBox"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOFPFILMBOX_H_
