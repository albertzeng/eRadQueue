// dbovQACSPatients.H : Declaration of the CdbovQACSPatients class

#ifndef __DBOVQACSPATIENTS_H_
#define __DBOVQACSPATIENTS_H_

class CdbovQACSPatientsAccessor
{
public:
	LONG m_PatientsIndex;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsAlias[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsDOB[17];
	TCHAR m_PatientsSex[17];
	LONG m_PatientsStudies;
	LONG m_PatientsSeries;
	LONG m_PatientsImages;
	LONG m_PatientsFlags;
	TCHAR m_PatientsTS[17];
	TCHAR m_PatientsSourceAE[17];

BEGIN_COLUMN_MAP(CdbovQACSPatientsAccessor)
	COLUMN_ENTRY(1, m_PatientsIndex)
	COLUMN_ENTRY(2, m_PatientsName)
	COLUMN_ENTRY(3, m_PatientsAlias)
	COLUMN_ENTRY(4, m_PatientsID)
	COLUMN_ENTRY(5, m_PatientsDOB)
	COLUMN_ENTRY(6, m_PatientsSex)
	COLUMN_ENTRY(7, m_PatientsStudies)
	COLUMN_ENTRY(8, m_PatientsSeries)
	COLUMN_ENTRY(9, m_PatientsImages)
	COLUMN_ENTRY(10, m_PatientsFlags)
	COLUMN_ENTRY(11, m_PatientsTS)
	COLUMN_ENTRY(12, m_PatientsSourceAE)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovQACSPatientsAccessor, _T(" \
	SELECT \
		PatientsIndex, \
		PatientsName, \
		PatientsAlias, \
		PatientsID, \
		PatientsDOB, \
		PatientsSex, \
		PatientsStudies, \
		PatientsSeries, \
		PatientsImages, \
		PatientsFlags, \
		PatientsTS, \
		PatientsSourceAE  \
		FROM vQACSPatients"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVQACSPATIENTS_H_
