// dboIMGAviFile.H : Declaration of the CdboIMGAviFile class

#ifndef __DBOIMGAVIFILE_H_
#define __DBOIMGAVIFILE_H_

class CdboIMGAviFileAccessor
{
public:
	LONG m_AviIndex;
	TCHAR m_AviFileName[101];
	LONG m_AviFileSize;
	LONG m_AviToDICOM;
	TCHAR m_AviTS[17];
	LONG m_AviTimes;
	LONG m_AviCode;
	TCHAR m_AviMessage[65];
	TCHAR m_AviReworkTS[17];
	TCHAR m_AviPatientsName[65];
	TCHAR m_AviPatientsAlias[65];
	TCHAR m_AviPatientsID[65];
	TCHAR m_AviPatientsDOB[17];
	TCHAR m_AviPatientsSex[17];
	TCHAR m_AviStudiesInstUID[65];
	TCHAR m_AviAccessionNumber[65];

BEGIN_COLUMN_MAP(CdboIMGAviFileAccessor)
	COLUMN_ENTRY(1, m_AviIndex)
	COLUMN_ENTRY(2, m_AviFileName)
	COLUMN_ENTRY(3, m_AviFileSize)
	COLUMN_ENTRY(4, m_AviToDICOM)
	COLUMN_ENTRY(5, m_AviTS)
	COLUMN_ENTRY(6, m_AviTimes)
	COLUMN_ENTRY(7, m_AviCode)
	COLUMN_ENTRY(8, m_AviMessage)
	COLUMN_ENTRY(9, m_AviReworkTS)
	COLUMN_ENTRY(10, m_AviPatientsName)
	COLUMN_ENTRY(11, m_AviPatientsAlias)
	COLUMN_ENTRY(12, m_AviPatientsID)
	COLUMN_ENTRY(13, m_AviPatientsDOB)
	COLUMN_ENTRY(14, m_AviPatientsSex)
	COLUMN_ENTRY(15, m_AviStudiesInstUID)
	COLUMN_ENTRY(16, m_AviAccessionNumber)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboIMGAviFileAccessor, _T(" \
	SELECT \
		AviIndex, \
		AviFileName, \
		AviFileSize, \
		AviToDICOM, \
		AviTS, \
		AviTimes, \
		AviCode, \
		AviMessage, \
		AviReworkTS, \
		AviPatientsName, \
		AviPatientsAlias, \
		AviPatientsID, \
		AviPatientsDOB, \
		AviPatientsSex, \
		AviStudiesInstUID, \
		AviAccessionNumber  \
		FROM IMGAviFile"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOIMGAVIFILE_H_
