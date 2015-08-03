// dboEISResults.H : Declaration of the CdboEISResults class

#ifndef __DBOEISRESULTS_H_
#define __DBOEISRESULTS_H_

class CdboEISResultsAccessor
{
public:
	LONG m_ResultsIndex;
	LONG m_ResultsStudies;
	LONG m_ResultsReports;
	TCHAR m_ResultsExamine[65];
	TCHAR m_ResultsExamineAlias[201];
	TCHAR m_ResultsBodiesCode[65];
	TCHAR m_ResultsBodies[65];
	TCHAR m_ResultsBodiesAlias[201];
	TCHAR m_ResultsDate[9];
	TCHAR m_ResultsTime[7];
	TCHAR m_ResultsTemplate[65];
	TCHAR m_ResultsOutDate[9];
	TCHAR m_ResultsOutTime[7];
	TCHAR m_ResultsComments[513];

BEGIN_COLUMN_MAP(CdboEISResultsAccessor)
	COLUMN_ENTRY(1, m_ResultsIndex)
	COLUMN_ENTRY(2, m_ResultsStudies)
	COLUMN_ENTRY(3, m_ResultsReports)
	COLUMN_ENTRY(4, m_ResultsExamine)
	COLUMN_ENTRY(5, m_ResultsExamineAlias)
	COLUMN_ENTRY(6, m_ResultsBodiesCode)
	COLUMN_ENTRY(7, m_ResultsBodies)
	COLUMN_ENTRY(8, m_ResultsBodiesAlias)
	COLUMN_ENTRY(9, m_ResultsDate)
	COLUMN_ENTRY(10, m_ResultsTime)
	COLUMN_ENTRY(11, m_ResultsTemplate)
	COLUMN_ENTRY(12, m_ResultsOutDate)
	COLUMN_ENTRY(13, m_ResultsOutTime)
	COLUMN_ENTRY(14, m_ResultsComments)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISResultsAccessor, _T(" \
	SELECT \
		ResultsIndex, \
		ResultsStudies, \
		ResultsReports, \
		ResultsExamine, \
		ResultsExamineAlias, \
		ResultsBodiesCode, \
		ResultsBodies, \
		ResultsBodiesAlias, \
		ResultsDate, \
		ResultsTime, \
		ResultsTemplate, \
		ResultsOutDate, \
		ResultsOutTime, \
		ResultsComments  \
		FROM EISResults"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISRESULTS_H_
