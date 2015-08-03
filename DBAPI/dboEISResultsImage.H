// dboEISResultsImage.H : Declaration of the CdboEISResultsImage class

#ifndef __DBOEISRESULTSIMAGE_H_
#define __DBOEISRESULTSIMAGE_H_

class CdboEISResultsImageAccessor
{
public:
	LONG m_RIIndex;
	LONG m_RIResults;
	LONG m_RIOrder;
	TCHAR m_RISOPInstUID[65];
	TCHAR m_RIGetSOPInstUID[65];
	TCHAR m_RILabel[65];
	TCHAR m_RIRemark[65];
	TCHAR m_RITS[17];

BEGIN_COLUMN_MAP(CdboEISResultsImageAccessor)
	COLUMN_ENTRY(1, m_RIIndex)
	COLUMN_ENTRY(2, m_RIResults)
	COLUMN_ENTRY(3, m_RIOrder)
	COLUMN_ENTRY(4, m_RISOPInstUID)
	COLUMN_ENTRY(5, m_RIGetSOPInstUID)
	COLUMN_ENTRY(6, m_RILabel)
	COLUMN_ENTRY(7, m_RIRemark)
	COLUMN_ENTRY(8, m_RITS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISResultsImageAccessor, _T(" \
	SELECT \
		RIIndex, \
		RIResults, \
		RIOrder, \
		RISOPInstUID, \
		RIGetSOPInstUID, \
		RILabel, \
		RIRemark, \
		RITS  \
		FROM EISResultsImage"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISRESULTSIMAGE_H_
