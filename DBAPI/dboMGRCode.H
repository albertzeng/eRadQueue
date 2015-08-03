// dboMGRCode.H : Declaration of the CdboMGRCode class

#ifndef __DBOMGRCODE_H_
#define __DBOMGRCODE_H_

class CdboMGRCodeAccessor
{
public:
	LONG m_CodeIndex;
	LONG m_CodeDepartment;
	LONG m_CodeInside;
	TCHAR m_CodeClassified[65];
	TCHAR m_CodeValue[65];
	TCHAR m_CodeRemark[65];

BEGIN_COLUMN_MAP(CdboMGRCodeAccessor)
	COLUMN_ENTRY(1, m_CodeIndex)
	COLUMN_ENTRY(2, m_CodeDepartment)
	COLUMN_ENTRY(3, m_CodeInside)
	COLUMN_ENTRY(4, m_CodeClassified)
	COLUMN_ENTRY(5, m_CodeValue)
	COLUMN_ENTRY(6, m_CodeRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRCodeAccessor, _T(" \
	SELECT \
		CodeIndex, \
		CodeDepartment, \
		CodeInside, \
		CodeClassified, \
		CodeValue, \
		CodeRemark  \
		FROM MGRCode"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRCODE_H_
