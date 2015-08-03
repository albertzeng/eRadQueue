// dboMGRSpecs.H : Declaration of the CdboMGRSpecs class

#ifndef __DBOMGRSPECS_H_
#define __DBOMGRSPECS_H_

class CdboMGRSpecsAccessor
{
public:
	LONG m_SpecsIndex;
	LONG m_SpecsDepartment;
	TCHAR m_SpecsCode[65];
	TCHAR m_SpecsSpell[17];
	TCHAR m_SpecsName[65];
	TCHAR m_SpecsAlias[65];
	TCHAR m_SpecsRemark[65];

BEGIN_COLUMN_MAP(CdboMGRSpecsAccessor)
	COLUMN_ENTRY(1, m_SpecsIndex)
	COLUMN_ENTRY(2, m_SpecsDepartment)
	COLUMN_ENTRY(3, m_SpecsCode)
	COLUMN_ENTRY(4, m_SpecsSpell)
	COLUMN_ENTRY(5, m_SpecsName)
	COLUMN_ENTRY(6, m_SpecsAlias)
	COLUMN_ENTRY(7, m_SpecsRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRSpecsAccessor, _T(" \
	SELECT \
		SpecsIndex, \
		SpecsDepartment, \
		SpecsCode, \
		SpecsSpell, \
		SpecsName, \
		SpecsAlias, \
		SpecsRemark  \
		FROM MGRSpecs"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRSPECS_H_
