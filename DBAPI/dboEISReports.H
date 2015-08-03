// dboEISReports.H : Declaration of the CdboEISReports class

#ifndef __DBOEISREPORTS_H_
#define __DBOEISREPORTS_H_

class CdboEISReportsAccessor
{
public:
	LONG m_ReportsIndex;
	LONG m_ReportsStudies;
	LONG m_ReportsResults;
	LONG m_ReportsStatus;
	LONG m_ReportsOutStatus;
	LONG m_RecordsDoctor;
	TCHAR m_RecordsDoctorAlias[65];
	TCHAR m_RecordsDate[9];
	TCHAR m_RecordsTime[7];
	LONG m_ReportsDoctor;
	TCHAR m_ReportsDoctorAlias[65];
	TCHAR m_ReportsDate[9];
	TCHAR m_ReportsTime[7];
	LONG m_ApproveDoctor;
	TCHAR m_ApproveDoctorAlias[65];
	TCHAR m_ApproveDate[9];
	TCHAR m_ApproveTime[7];
	LONG m_ReviewsChange;
	LONG m_ReviewsDoctor;
	TCHAR m_ReviewsDoctorAlias[65];
	TCHAR m_ReviewsDate[9];
	TCHAR m_ReviewsTime[7];
	TCHAR m_ReportsConclusion[20480];
	TCHAR m_ReportsEvidences[20480];
	TCHAR m_ReportsTechnologies[20480];
	TCHAR m_ReportsComments[20480];

BEGIN_COLUMN_MAP(CdboEISReportsAccessor)
	COLUMN_ENTRY(1, m_ReportsIndex)
	COLUMN_ENTRY(2, m_ReportsStudies)
	COLUMN_ENTRY(3, m_ReportsResults)
	COLUMN_ENTRY(4, m_ReportsStatus)
	COLUMN_ENTRY(5, m_ReportsOutStatus)
	COLUMN_ENTRY(6, m_RecordsDoctor)
	COLUMN_ENTRY(7, m_RecordsDoctorAlias)
	COLUMN_ENTRY(8, m_RecordsDate)
	COLUMN_ENTRY(9, m_RecordsTime)
	COLUMN_ENTRY(10, m_ReportsDoctor)
	COLUMN_ENTRY(11, m_ReportsDoctorAlias)
	COLUMN_ENTRY(12, m_ReportsDate)
	COLUMN_ENTRY(13, m_ReportsTime)
	COLUMN_ENTRY(14, m_ApproveDoctor)
	COLUMN_ENTRY(15, m_ApproveDoctorAlias)
	COLUMN_ENTRY(16, m_ApproveDate)
	COLUMN_ENTRY(17, m_ApproveTime)
	COLUMN_ENTRY(18, m_ReviewsChange)
	COLUMN_ENTRY(19, m_ReviewsDoctor)
	COLUMN_ENTRY(20, m_ReviewsDoctorAlias)
	COLUMN_ENTRY(21, m_ReviewsDate)
	COLUMN_ENTRY(22, m_ReviewsTime)
	COLUMN_ENTRY(23, m_ReportsConclusion)
	COLUMN_ENTRY(24, m_ReportsEvidences)
	COLUMN_ENTRY(25, m_ReportsTechnologies)
	COLUMN_ENTRY(26, m_ReportsComments)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISReportsAccessor, _T(" \
	SELECT \
		ReportsIndex, \
		ReportsStudies, \
		ReportsResults, \
		ReportsStatus, \
		ReportsOutStatus, \
		RecordsDoctor, \
		RecordsDoctorAlias, \
		RecordsDate, \
		RecordsTime, \
		ReportsDoctor, \
		ReportsDoctorAlias, \
		ReportsDate, \
		ReportsTime, \
		ApproveDoctor, \
		ApproveDoctorAlias, \
		ApproveDate, \
		ApproveTime, \
		ReviewsChange, \
		ReviewsDoctor, \
		ReviewsDoctorAlias, \
		ReviewsDate, \
		ReviewsTime, \
		ReportsConclusion, \
		ReportsEvidences, \
		ReportsTechnologies, \
		ReportsComments  \
		FROM EISReports"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISREPORTS_H_
