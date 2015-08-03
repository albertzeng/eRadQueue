// dboEISStudiesQC.H : Declaration of the CdboEISStudiesQC class

#ifndef __DBOEISSTUDIESQC_H_
#define __DBOEISSTUDIESQC_H_

class CdboEISStudiesQCAccessor
{
public:
	LONG m_SQCIndex;
	LONG m_SQCStudies;
	LONG m_SQCDoctor;
	TCHAR m_SQCDoctorAlias[65];
	TCHAR m_SQCTS[17];
	LONG m_SQCKinds;
	TCHAR m_SQCClass[65];
	TCHAR m_SQCRight[201];
	TCHAR m_SQCFalse[201];
	TCHAR m_SQCEvidences[4001];
	TCHAR m_SQCConclusion[1025];

BEGIN_COLUMN_MAP(CdboEISStudiesQCAccessor)
	COLUMN_ENTRY(1, m_SQCIndex)
	COLUMN_ENTRY(2, m_SQCStudies)
	COLUMN_ENTRY(3, m_SQCDoctor)
	COLUMN_ENTRY(4, m_SQCDoctorAlias)
	COLUMN_ENTRY(5, m_SQCTS)
	COLUMN_ENTRY(6, m_SQCKinds)
	COLUMN_ENTRY(7, m_SQCClass)
	COLUMN_ENTRY(8, m_SQCRight)
	COLUMN_ENTRY(9, m_SQCFalse)
	COLUMN_ENTRY(10, m_SQCEvidences)
	COLUMN_ENTRY(11, m_SQCConclusion)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISStudiesQCAccessor, _T(" \
	SELECT \
		SQCIndex, \
		SQCStudies, \
		SQCDoctor, \
		SQCDoctorAlias, \
		SQCTS, \
		SQCKinds, \
		SQCClass, \
		SQCRight, \
		SQCFalse, \
		SQCEvidences, \
		SQCConclusion  \
		FROM EISStudiesQC"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISSTUDIESQC_H_
