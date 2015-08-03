// dboEISExchangeFailed.H : Declaration of the CdboEISExchangeFailed class

#ifndef __DBOEISEXCHANGEFAILED_H_
#define __DBOEISEXCHANGEFAILED_H_

class CdboEISExchangeFailedAccessor
{
public:
	LONG m_FailedIndex;
	LONG m_FailedLinker;
	LONG m_FailedExchange;
	TCHAR m_FailedTS[17];
	LONG m_FailedTimes;
	LONG m_FailedCode;
	TCHAR m_FailedMessage[65];
	TCHAR m_FailedReworkTS[17];

BEGIN_COLUMN_MAP(CdboEISExchangeFailedAccessor)
	COLUMN_ENTRY(1, m_FailedIndex)
	COLUMN_ENTRY(2, m_FailedLinker)
	COLUMN_ENTRY(3, m_FailedExchange)
	COLUMN_ENTRY(4, m_FailedTS)
	COLUMN_ENTRY(5, m_FailedTimes)
	COLUMN_ENTRY(6, m_FailedCode)
	COLUMN_ENTRY(7, m_FailedMessage)
	COLUMN_ENTRY(8, m_FailedReworkTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISExchangeFailedAccessor, _T(" \
	SELECT \
		FailedIndex, \
		FailedLinker, \
		FailedExchange, \
		FailedTS, \
		FailedTimes, \
		FailedCode, \
		FailedMessage, \
		FailedReworkTS  \
		FROM EISExchangeFailed"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISEXCHANGEFAILED_H_
