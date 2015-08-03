// dboMGRPrivilege.H : Declaration of the CdboMGRPrivilege class

#ifndef __DBOMGRPRIVILEGE_H_
#define __DBOMGRPRIVILEGE_H_

class CdboMGRPrivilegeAccessor
{
public:
	LONG m_PrivilegeIndex;
	LONG m_PrivilegeOrder;
	LONG m_PrivilegeValue;
	TCHAR m_PrivilegeName[65];
	TCHAR m_PrivilegeRemark[65];

BEGIN_COLUMN_MAP(CdboMGRPrivilegeAccessor)
	COLUMN_ENTRY(1, m_PrivilegeIndex)
	COLUMN_ENTRY(2, m_PrivilegeOrder)
	COLUMN_ENTRY(3, m_PrivilegeValue)
	COLUMN_ENTRY(4, m_PrivilegeName)
	COLUMN_ENTRY(5, m_PrivilegeRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRPrivilegeAccessor, _T(" \
	SELECT \
		PrivilegeIndex, \
		PrivilegeOrder, \
		PrivilegeValue, \
		PrivilegeName, \
		PrivilegeRemark  \
		FROM MGRPrivilege"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRPRIVILEGE_H_
