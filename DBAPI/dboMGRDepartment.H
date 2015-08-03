// dboMGRDepartment.H : Declaration of the CdboMGRDepartment class

#ifndef __DBOMGRDEPARTMENT_H_
#define __DBOMGRDEPARTMENT_H_

class CdboMGRDepartmentAccessor
{
public:
	LONG m_DepartmentIndex;
	LONG m_DepartmentExamine;
	TCHAR m_DepartmentCode[65];
	TCHAR m_DepartmentSpell[17];
	TCHAR m_DepartmentName[65];
	TCHAR m_DepartmentAlias[65];
	TCHAR m_DepartmentRemark[65];

BEGIN_COLUMN_MAP(CdboMGRDepartmentAccessor)
	COLUMN_ENTRY(1, m_DepartmentIndex)
	COLUMN_ENTRY(2, m_DepartmentExamine)
	COLUMN_ENTRY(3, m_DepartmentCode)
	COLUMN_ENTRY(4, m_DepartmentSpell)
	COLUMN_ENTRY(5, m_DepartmentName)
	COLUMN_ENTRY(6, m_DepartmentAlias)
	COLUMN_ENTRY(7, m_DepartmentRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRDepartmentAccessor, _T(" \
	SELECT \
		DepartmentIndex, \
		DepartmentExamine, \
		DepartmentCode, \
		DepartmentSpell, \
		DepartmentName, \
		DepartmentAlias, \
		DepartmentRemark  \
		FROM MGRDepartment"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRDEPARTMENT_H_
