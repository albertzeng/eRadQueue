// dbovMGRDoctor.H : Declaration of the CdbovMGRDoctor class

#ifndef __DBOVMGRDOCTOR_H_
#define __DBOVMGRDOCTOR_H_

class CdbovMGRDoctorAccessor
{
public:
	LONG m_DoctorIndex;
	LONG m_DoctorDepartment;
	LONG m_DoctorPrivilege;
	TCHAR m_DoctorPrivilege2[17];
	TCHAR m_DoctorCode[17];
	TCHAR m_DoctorPassword[65];
	TCHAR m_DoctorName[65];
	TCHAR m_DoctorAlias[65];
	TCHAR m_DoctorPhone[65];
	TCHAR m_DoctorRemark[65];
	LONG m_DoctorDisable;
	LONG m_DoctorFlags;
	TCHAR m_DoctorGetSOPInstUID[65];
	LONG m_DoctorDepartmentExamine;
	LONG m_DepartmentExamine;
	TCHAR m_DepartmentCode[65];
	TCHAR m_DepartmentSpell[17];
	TCHAR m_DepartmentName[65];
	TCHAR m_DepartmentAlias[65];
	TCHAR m_DepartmentRemark[65];

BEGIN_COLUMN_MAP(CdbovMGRDoctorAccessor)
	COLUMN_ENTRY(1, m_DoctorIndex)
	COLUMN_ENTRY(2, m_DoctorDepartment)
	COLUMN_ENTRY(3, m_DoctorPrivilege)
	COLUMN_ENTRY(4, m_DoctorPrivilege2)
	COLUMN_ENTRY(5, m_DoctorCode)
	COLUMN_ENTRY(6, m_DoctorPassword)
	COLUMN_ENTRY(7, m_DoctorName)
	COLUMN_ENTRY(8, m_DoctorAlias)
	COLUMN_ENTRY(9, m_DoctorPhone)
	COLUMN_ENTRY(10, m_DoctorRemark)
	COLUMN_ENTRY(11, m_DoctorDisable)
	COLUMN_ENTRY(12, m_DoctorFlags)
	COLUMN_ENTRY(13, m_DoctorGetSOPInstUID)
	COLUMN_ENTRY(14, m_DoctorDepartmentExamine)
	COLUMN_ENTRY(15, m_DepartmentExamine)
	COLUMN_ENTRY(16, m_DepartmentCode)
	COLUMN_ENTRY(17, m_DepartmentSpell)
	COLUMN_ENTRY(18, m_DepartmentName)
	COLUMN_ENTRY(19, m_DepartmentAlias)
	COLUMN_ENTRY(20, m_DepartmentRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovMGRDoctorAccessor, _T(" \
	SELECT \
		DoctorIndex, \
		DoctorDepartment, \
		DoctorPrivilege, \
		DoctorPrivilege2, \
		DoctorCode, \
		DoctorPassword, \
		DoctorName, \
		DoctorAlias, \
		DoctorPhone, \
		DoctorRemark, \
		DoctorDisable, \
		DoctorFlags, \
		DoctorGetSOPInstUID, \
		DoctorDepartmentExamine, \
		DepartmentExamine, \
		DepartmentCode, \
		DepartmentSpell, \
		DepartmentName, \
		DepartmentAlias, \
		DepartmentRemark  \
		FROM vMGRDoctor"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVMGRDOCTOR_H_
