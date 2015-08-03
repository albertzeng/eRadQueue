// dboEISExchange.H : Declaration of the CdboEISExchange class

#ifndef __DBOEISEXCHANGE_H_
#define __DBOEISEXCHANGE_H_

class CdboEISExchangeAccessor
{
public:
	LONG m_ExchangeIndex;
	LONG m_ExchangeCode;
	LONG m_ExchangeStudies;
	LONG m_ExchangeService;
	LONG m_ExchangeReports;
	TCHAR m_ExchangeTS[17];

BEGIN_COLUMN_MAP(CdboEISExchangeAccessor)
	COLUMN_ENTRY(1, m_ExchangeIndex)
	COLUMN_ENTRY(2, m_ExchangeCode)
	COLUMN_ENTRY(3, m_ExchangeStudies)
	COLUMN_ENTRY(4, m_ExchangeService)
	COLUMN_ENTRY(5, m_ExchangeReports)
	COLUMN_ENTRY(6, m_ExchangeTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISExchangeAccessor, _T(" \
	SELECT \
		ExchangeIndex, \
		ExchangeCode, \
		ExchangeStudies, \
		ExchangeService, \
		ExchangeReports, \
		ExchangeTS  \
		FROM EISExchange"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISEXCHANGE_H_
