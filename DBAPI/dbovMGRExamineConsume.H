// dbovMGRExamineConsume.H : Declaration of the CdbovMGRExamineConsume class

#ifndef __DBOVMGREXAMINECONSUME_H_
#define __DBOVMGREXAMINECONSUME_H_

class CdbovMGRExamineConsumeAccessor
{
public:
	LONG m_ECExamine;
	LONG m_ECConsume;
	double m_ECConsumeCount;
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

BEGIN_COLUMN_MAP(CdbovMGRExamineConsumeAccessor)
	COLUMN_ENTRY(1, m_ECExamine)
	COLUMN_ENTRY(2, m_ECConsume)
	COLUMN_ENTRY(3, m_ECConsumeCount)
	COLUMN_ENTRY(4, m_ConsumeDepartment)
	COLUMN_ENTRY(5, m_ConsumeSpell)
	COLUMN_ENTRY(6, m_ConsumeClassified)
	COLUMN_ENTRY(7, m_ConsumeName)
	COLUMN_ENTRY(8, m_ConsumeSpecs)
	COLUMN_ENTRY(9, m_ConsumeUnits)
	COLUMN_ENTRY(10, m_ConsumePrice)
	COLUMN_ENTRY(11, m_ConsumeExclusive)
	COLUMN_ENTRY(12, m_ConsumeRemark)
	COLUMN_ENTRY(13, m_ConsumeCode)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovMGRExamineConsumeAccessor, _T(" \
	SELECT \
		ECExamine, \
		ECConsume, \
		ECConsumeCount, \
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
		FROM vMGRExamineConsume"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVMGREXAMINECONSUME_H_
