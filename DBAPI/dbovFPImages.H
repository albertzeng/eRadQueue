// dbovFPImages.H : Declaration of the CdbovFPImages class

#ifndef __DBOVFPIMAGES_H_
#define __DBOVFPIMAGES_H_

class CdbovFPImagesAccessor
{
public:
	LONG m_FilmSessionIndex;
	LONG m_FilmSessionAssociation;
	LONG m_FilmSessionAvailable;
	LONG m_FilmSessionPRINT;
	LONG m_FilmSessionFilmBox;
	LONG m_FilmSessionArchive;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsDOB[17];
	TCHAR m_PatientsSex[17];
	TCHAR m_StudiesInstUID[65];
	TCHAR m_StudiesDate[65];
	TCHAR m_AccessionNumber[65];
	TCHAR m_SeriesInstUID[65];
	LONG m_FilmBoxIndex;
	LONG m_FilmBoxFilmSession;
	LONG m_FilmBoxPRINT;
	TCHAR m_SOPInstUID[65];
	TCHAR m_SOPClassUID[65];
	TCHAR m_ImagesFileName[101];
	LONG m_ImagesFileSize;

BEGIN_COLUMN_MAP(CdbovFPImagesAccessor)
	COLUMN_ENTRY(1, m_FilmSessionIndex)
	COLUMN_ENTRY(2, m_FilmSessionAssociation)
	COLUMN_ENTRY(3, m_FilmSessionAvailable)
	COLUMN_ENTRY(4, m_FilmSessionPRINT)
	COLUMN_ENTRY(5, m_FilmSessionFilmBox)
	COLUMN_ENTRY(6, m_FilmSessionArchive)
	COLUMN_ENTRY(7, m_PatientsName)
	COLUMN_ENTRY(8, m_PatientsID)
	COLUMN_ENTRY(9, m_PatientsDOB)
	COLUMN_ENTRY(10, m_PatientsSex)
	COLUMN_ENTRY(11, m_StudiesInstUID)
	COLUMN_ENTRY(12, m_StudiesDate)
	COLUMN_ENTRY(13, m_AccessionNumber)
	COLUMN_ENTRY(14, m_SeriesInstUID)
	COLUMN_ENTRY(15, m_FilmBoxIndex)
	COLUMN_ENTRY(16, m_FilmBoxFilmSession)
	COLUMN_ENTRY(17, m_FilmBoxPRINT)
	COLUMN_ENTRY(18, m_SOPInstUID)
	COLUMN_ENTRY(19, m_SOPClassUID)
	COLUMN_ENTRY(20, m_ImagesFileName)
	COLUMN_ENTRY(21, m_ImagesFileSize)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovFPImagesAccessor, _T(" \
	SELECT \
		FilmSessionIndex, \
		FilmSessionAssociation, \
		FilmSessionAvailable, \
		FilmSessionPRINT, \
		FilmSessionFilmBox, \
		FilmSessionArchive, \
		PatientsName, \
		PatientsID, \
		PatientsDOB, \
		PatientsSex, \
		StudiesInstUID, \
		StudiesDate, \
		AccessionNumber, \
		SeriesInstUID, \
		FilmBoxIndex, \
		FilmBoxFilmSession, \
		FilmBoxPRINT, \
		SOPInstUID, \
		SOPClassUID, \
		ImagesFileName, \
		ImagesFileSize  \
		FROM vFPImages"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVFPIMAGES_H_
