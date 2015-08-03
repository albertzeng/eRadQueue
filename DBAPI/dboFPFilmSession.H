// dboFPFilmSession.H : Declaration of the CdboFPFilmSession class

#ifndef __DBOFPFILMSESSION_H_
#define __DBOFPFILMSESSION_H_

class CdboFPFilmSessionAccessor
{
public:
	LONG m_FilmSessionIndex;
	LONG m_FilmSessionAssociation;
	LONG m_FilmSessionAvailable;
	LONG m_FilmSessionPRINT;
	LONG m_FilmSessionColor;
	LONG m_FilmSessionCollation;
	TCHAR m_FilmSessionCopies[17];
	TCHAR m_FilmSessionPriority[17];
	TCHAR m_FilmSessionMedium[17];
	TCHAR m_FilmSessionDestination[17];
	TCHAR m_FilmSessionLabel[65];
	TCHAR m_FilmSessionMemAlloc[17];
	TCHAR m_FilmSessionOwnerID[17];
	LONG m_FilmSessionFilmBox;
	LONG m_FilmSessionRepeats;
	TCHAR m_FilmSessionReplaceAE[17];
	TCHAR m_FilmSessionReplaceIP[17];
	TCHAR m_FilmSessionCalledAE[17];
	LONG m_FilmSessionExecute;
	LONG m_FilmSessionTimes;
	LONG m_FilmSessionCode;
	TCHAR m_FilmSessionMessage[65];
	TCHAR m_FilmSessionReworkTS[17];
	LONG m_FilmSessionArchive;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsDOB[17];
	TCHAR m_PatientsSex[17];
	TCHAR m_StudiesInstUID[65];
	TCHAR m_StudiesDate[65];
	TCHAR m_AccessionNumber[65];
	TCHAR m_SeriesInstUID[65];

BEGIN_COLUMN_MAP(CdboFPFilmSessionAccessor)
	COLUMN_ENTRY(1, m_FilmSessionIndex)
	COLUMN_ENTRY(2, m_FilmSessionAssociation)
	COLUMN_ENTRY(3, m_FilmSessionAvailable)
	COLUMN_ENTRY(4, m_FilmSessionPRINT)
	COLUMN_ENTRY(5, m_FilmSessionColor)
	COLUMN_ENTRY(6, m_FilmSessionCollation)
	COLUMN_ENTRY(7, m_FilmSessionCopies)
	COLUMN_ENTRY(8, m_FilmSessionPriority)
	COLUMN_ENTRY(9, m_FilmSessionMedium)
	COLUMN_ENTRY(10, m_FilmSessionDestination)
	COLUMN_ENTRY(11, m_FilmSessionLabel)
	COLUMN_ENTRY(12, m_FilmSessionMemAlloc)
	COLUMN_ENTRY(13, m_FilmSessionOwnerID)
	COLUMN_ENTRY(14, m_FilmSessionFilmBox)
	COLUMN_ENTRY(15, m_FilmSessionRepeats)
	COLUMN_ENTRY(16, m_FilmSessionReplaceAE)
	COLUMN_ENTRY(17, m_FilmSessionReplaceIP)
	COLUMN_ENTRY(18, m_FilmSessionCalledAE)
	COLUMN_ENTRY(19, m_FilmSessionExecute)
	COLUMN_ENTRY(20, m_FilmSessionTimes)
	COLUMN_ENTRY(21, m_FilmSessionCode)
	COLUMN_ENTRY(22, m_FilmSessionMessage)
	COLUMN_ENTRY(23, m_FilmSessionReworkTS)
	COLUMN_ENTRY(24, m_FilmSessionArchive)
	COLUMN_ENTRY(25, m_PatientsName)
	COLUMN_ENTRY(26, m_PatientsID)
	COLUMN_ENTRY(27, m_PatientsDOB)
	COLUMN_ENTRY(28, m_PatientsSex)
	COLUMN_ENTRY(29, m_StudiesInstUID)
	COLUMN_ENTRY(30, m_StudiesDate)
	COLUMN_ENTRY(31, m_AccessionNumber)
	COLUMN_ENTRY(32, m_SeriesInstUID)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboFPFilmSessionAccessor, _T(" \
	SELECT \
		FilmSessionIndex, \
		FilmSessionAssociation, \
		FilmSessionAvailable, \
		FilmSessionPRINT, \
		FilmSessionColor, \
		FilmSessionCollation, \
		FilmSessionCopies, \
		FilmSessionPriority, \
		FilmSessionMedium, \
		FilmSessionDestination, \
		FilmSessionLabel, \
		FilmSessionMemAlloc, \
		FilmSessionOwnerID, \
		FilmSessionFilmBox, \
		FilmSessionRepeats, \
		FilmSessionReplaceAE, \
		FilmSessionReplaceIP, \
		FilmSessionCalledAE, \
		FilmSessionExecute, \
		FilmSessionTimes, \
		FilmSessionCode, \
		FilmSessionMessage, \
		FilmSessionReworkTS, \
		FilmSessionArchive, \
		PatientsName, \
		PatientsID, \
		PatientsDOB, \
		PatientsSex, \
		StudiesInstUID, \
		StudiesDate, \
		AccessionNumber, \
		SeriesInstUID  \
		FROM FPFilmSession"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOFPFILMSESSION_H_
