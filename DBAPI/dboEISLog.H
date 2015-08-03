// dboEISLog.H : Declaration of the CdboEISLog class

#ifndef __DBOEISLOG_H_
#define __DBOEISLOG_H_

class CdboEISLogAccessor
{
public:
	LONG m_LogIndex;
	LONG m_LogLevel;
	LONG m_LogCode;
	TCHAR m_LogOperate[65];
	TCHAR m_LogRADModule[65];
	TCHAR m_LogIPAddress[17];
	LONG m_LogDoctor;
	TCHAR m_LogDoctorAlias[65];
	TCHAR m_LogPatientsID[65];
	TCHAR m_LogPatientsName[65];
	TCHAR m_LogPatientsAlias[65];
	TCHAR m_LogAccessionNumber[65];
	TCHAR m_LogContent[513];
	TCHAR m_LogTS[17];

BEGIN_COLUMN_MAP(CdboEISLogAccessor)
	COLUMN_ENTRY(1, m_LogIndex)
	COLUMN_ENTRY(2, m_LogLevel)
	COLUMN_ENTRY(3, m_LogCode)
	COLUMN_ENTRY(4, m_LogOperate)
	COLUMN_ENTRY(5, m_LogRADModule)
	COLUMN_ENTRY(6, m_LogIPAddress)
	COLUMN_ENTRY(7, m_LogDoctor)
	COLUMN_ENTRY(8, m_LogDoctorAlias)
	COLUMN_ENTRY(9, m_LogPatientsID)
	COLUMN_ENTRY(10, m_LogPatientsName)
	COLUMN_ENTRY(11, m_LogPatientsAlias)
	COLUMN_ENTRY(12, m_LogAccessionNumber)
	COLUMN_ENTRY(13, m_LogContent)
	COLUMN_ENTRY(14, m_LogTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISLogAccessor, _T(" \
	SELECT \
		LogIndex, \
		LogLevel, \
		LogCode, \
		LogOperate, \
		LogRADModule, \
		LogIPAddress, \
		LogDoctor, \
		LogDoctorAlias, \
		LogPatientsID, \
		LogPatientsName, \
		LogPatientsAlias, \
		LogAccessionNumber, \
		LogContent, \
		LogTS  \
		FROM EISLog"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISLOG_H_
