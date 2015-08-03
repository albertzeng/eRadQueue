// dboEISStudiesConsume.H : Declaration of the CdboEISStudiesConsume class

#ifndef __DBOEISSTUDIESCONSUME_H_
#define __DBOEISSTUDIESCONSUME_H_

class CdboEISStudiesConsumeAccessor
{
public:
	LONG m_SCIndex;
	LONG m_SCStudies;
	LONG m_SCConsume;
	TCHAR m_SCClassified[65];
	TCHAR m_SCName[65];
	TCHAR m_SCSpecs[65];
	TCHAR m_SCUnits[65];
	double m_SCPrice;
	double m_SCCount;

BEGIN_COLUMN_MAP(CdboEISStudiesConsumeAccessor)
	COLUMN_ENTRY(1, m_SCIndex)
	COLUMN_ENTRY(2, m_SCStudies)
	COLUMN_ENTRY(3, m_SCConsume)
	COLUMN_ENTRY(4, m_SCClassified)
	COLUMN_ENTRY(5, m_SCName)
	COLUMN_ENTRY(6, m_SCSpecs)
	COLUMN_ENTRY(7, m_SCUnits)
	COLUMN_ENTRY(8, m_SCPrice)
	COLUMN_ENTRY(9, m_SCCount)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISStudiesConsumeAccessor, _T(" \
	SELECT \
		SCIndex, \
		SCStudies, \
		SCConsume, \
		SCClassified, \
		SCName, \
		SCSpecs, \
		SCUnits, \
		SCPrice, \
		SCCount  \
		FROM EISStudiesConsume"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISSTUDIESCONSUME_H_
