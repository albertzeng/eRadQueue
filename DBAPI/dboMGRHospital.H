// dboMGRHospital.H : Declaration of the CdboMGRHospital class

#ifndef __DBOMGRHOSPITAL_H_
#define __DBOMGRHOSPITAL_H_

class CdboMGRHospitalAccessor
{
public:
	LONG m_HospitalIndex;
	TCHAR m_HospitalName[65];
	TCHAR m_HospitalCode[65];
	TCHAR m_HospitalRemark[65];

BEGIN_COLUMN_MAP(CdboMGRHospitalAccessor)
	COLUMN_ENTRY(1, m_HospitalIndex)
	COLUMN_ENTRY(2, m_HospitalName)
	COLUMN_ENTRY(3, m_HospitalCode)
	COLUMN_ENTRY(4, m_HospitalRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRHospitalAccessor, _T(" \
	SELECT \
		HospitalIndex, \
		HospitalName, \
		HospitalCode, \
		HospitalRemark  \
		FROM MGRHospital"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRHOSPITAL_H_
