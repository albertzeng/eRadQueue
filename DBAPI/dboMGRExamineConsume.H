// dboMGRExamineConsume.H : Declaration of the CdboMGRExamineConsume class

#ifndef __DBOMGREXAMINECONSUME_H_
#define __DBOMGREXAMINECONSUME_H_

class CdboMGRExamineConsumeAccessor
{
public:
	LONG m_ECExamine;
	LONG m_ECConsume;
	double m_ECConsumeCount;

BEGIN_COLUMN_MAP(CdboMGRExamineConsumeAccessor)
	COLUMN_ENTRY(1, m_ECExamine)
	COLUMN_ENTRY(2, m_ECConsume)
	COLUMN_ENTRY(3, m_ECConsumeCount)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRExamineConsumeAccessor, _T(" \
	SELECT \
		ECExamine, \
		ECConsume, \
		ECConsumeCount  \
		FROM MGRExamineConsume"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGREXAMINECONSUME_H_
