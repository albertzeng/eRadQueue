// dboEISPatients.H : Declaration of the CdboEISPatients class

#ifndef __DBOEISPATIENTS_H_
#define __DBOEISPATIENTS_H_

class CdboEISPatientsAccessor
{
public:
	LONG m_PatientsIndex;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsAlias[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsIDAlias[65];
	TCHAR m_PatientsSex[9];
	TCHAR m_PatientsDOB[9];
	TCHAR m_PatientsPhone[65];
	TCHAR m_PatientsPostcode[65];
	TCHAR m_PatientsAddress[65];
	TCHAR m_PatientsCertificate[65];
	TCHAR m_PatientsComments[513];
	LONG m_PatientsProtective;
	TCHAR m_PatientsOccupation[65];

BEGIN_COLUMN_MAP(CdboEISPatientsAccessor)
	COLUMN_ENTRY(1, m_PatientsIndex)
	COLUMN_ENTRY(2, m_PatientsName)
	COLUMN_ENTRY(3, m_PatientsAlias)
	COLUMN_ENTRY(4, m_PatientsID)
	COLUMN_ENTRY(5, m_PatientsIDAlias)
	COLUMN_ENTRY(6, m_PatientsSex)
	COLUMN_ENTRY(7, m_PatientsDOB)
	COLUMN_ENTRY(8, m_PatientsPhone)
	COLUMN_ENTRY(9, m_PatientsPostcode)
	COLUMN_ENTRY(10, m_PatientsAddress)
	COLUMN_ENTRY(11, m_PatientsCertificate)
	COLUMN_ENTRY(12, m_PatientsComments)
	COLUMN_ENTRY(13, m_PatientsProtective)
	COLUMN_ENTRY(14, m_PatientsOccupation)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISPatientsAccessor, _T(" \
	SELECT \
		PatientsIndex, \
		PatientsName, \
		PatientsAlias, \
		PatientsID, \
		PatientsIDAlias, \
		PatientsSex, \
		PatientsDOB, \
		PatientsPhone, \
		PatientsPostcode, \
		PatientsAddress, \
		PatientsCertificate, \
		PatientsComments, \
		PatientsProtective, \
		PatientsOccupation  \
		FROM EISPatients"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISPATIENTS_H_
