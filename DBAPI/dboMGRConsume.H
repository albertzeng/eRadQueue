// dboMGRConsume.H : Declaration of the CdboMGRConsume class

#ifndef __DBOMGRCONSUME_H_
#define __DBOMGRCONSUME_H_

class CdboMGRConsumeAccessor
{
public:
	LONG m_ConsumeIndex;
	LONG m_ConsumeDepartment;
	TCHAR m_ConsumeSpell[17];
	TCHAR m_ConsumeClassified[65];
	TCHAR m_ConsumeName[65];
	TCHAR m_ConsumeSpecs[65];
	TCHAR m_ConsumeUnits[65];
	double m_ConsumePrice;
	LONG m_ConsumeExclusive;
	TCHAR m_ConsumeRemark[65];
	TCHAR m_ConsumeCode[65];

BEGIN_COLUMN_MAP(CdboMGRConsumeAccessor)
	COLUMN_ENTRY(1, m_ConsumeIndex)
	COLUMN_ENTRY(2, m_ConsumeDepartment)
	COLUMN_ENTRY(3, m_ConsumeSpell)
	COLUMN_ENTRY(4, m_ConsumeClassified)
	COLUMN_ENTRY(5, m_ConsumeName)
	COLUMN_ENTRY(6, m_ConsumeSpecs)
	COLUMN_ENTRY(7, m_ConsumeUnits)
	COLUMN_ENTRY(8, m_ConsumePrice)
	COLUMN_ENTRY(9, m_ConsumeExclusive)
	COLUMN_ENTRY(10, m_ConsumeRemark)
	COLUMN_ENTRY(11, m_ConsumeCode)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRConsumeAccessor, _T(" \
	SELECT \
		ConsumeIndex, \
		ConsumeDepartment, \
		ConsumeSpell, \
		ConsumeClassified, \
		ConsumeName, \
		ConsumeSpecs, \
		ConsumeUnits, \
		ConsumePrice, \
		ConsumeExclusive, \
		ConsumeRemark, \
		ConsumeCode  \
		FROM MGRConsume"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRCONSUME_H_
