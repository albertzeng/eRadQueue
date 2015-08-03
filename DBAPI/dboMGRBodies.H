// dboMGRBodies.H : Declaration of the CdboMGRBodies class

#ifndef __DBOMGRBODIES_H_
#define __DBOMGRBODIES_H_

class CdboMGRBodiesAccessor
{
public:
	LONG m_BodiesIndex;
	LONG m_BodiesDepartment;
	TCHAR m_BodiesCode[65];
	TCHAR m_BodiesSpell[17];
	TCHAR m_BodiesName[65];
	TCHAR m_BodiesAlias[65];
	TCHAR m_BodiesRemark[65];
	TCHAR m_BodiesCodeLinker[65];

BEGIN_COLUMN_MAP(CdboMGRBodiesAccessor)
	COLUMN_ENTRY(1, m_BodiesIndex)
	COLUMN_ENTRY(2, m_BodiesDepartment)
	COLUMN_ENTRY(3, m_BodiesCode)
	COLUMN_ENTRY(4, m_BodiesSpell)
	COLUMN_ENTRY(5, m_BodiesName)
	COLUMN_ENTRY(6, m_BodiesAlias)
	COLUMN_ENTRY(7, m_BodiesRemark)
	COLUMN_ENTRY(8, m_BodiesCodeLinker)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRBodiesAccessor, _T(" \
	SELECT \
		BodiesIndex, \
		BodiesDepartment, \
		BodiesCode, \
		BodiesSpell, \
		BodiesName, \
		BodiesAlias, \
		BodiesRemark, \
		BodiesCodeLinker  \
		FROM MGRBodies"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRBODIES_H_
