// dboEISStudiesDisease.H : Declaration of the CdboEISStudiesDisease class

#ifndef __DBOEISSTUDIESDISEASE_H_
#define __DBOEISSTUDIESDISEASE_H_

class CdboEISStudiesDiseaseAccessor
{
public:
	LONG m_SDStudies;
	LONG m_SDDisease;

BEGIN_COLUMN_MAP(CdboEISStudiesDiseaseAccessor)
	COLUMN_ENTRY(1, m_SDStudies)
	COLUMN_ENTRY(2, m_SDDisease)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISStudiesDiseaseAccessor, _T(" \
	SELECT \
		SDStudies, \
		SDDisease  \
		FROM EISStudiesDisease"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISSTUDIESDISEASE_H_
