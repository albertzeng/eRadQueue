// dboIMGNearline.H : Declaration of the CdboIMGNearline class

#ifndef __DBOIMGNEARLINE_H_
#define __DBOIMGNEARLINE_H_

class CdboIMGNearlineAccessor
{
public:
	LONG m_NearlineIndex;
	LONG m_NearlineClosed;
	LONG m_NearlineYM;
	TCHAR m_Nearline[65];
	TCHAR m_NearlineRemark[65];

BEGIN_COLUMN_MAP(CdboIMGNearlineAccessor)
	COLUMN_ENTRY(1, m_NearlineIndex)
	COLUMN_ENTRY(2, m_NearlineClosed)
	COLUMN_ENTRY(3, m_NearlineYM)
	COLUMN_ENTRY(4, m_Nearline)
	COLUMN_ENTRY(5, m_NearlineRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboIMGNearlineAccessor, _T(" \
	SELECT \
		NearlineIndex, \
		NearlineClosed, \
		NearlineYM, \
		Nearline, \
		NearlineRemark  \
		FROM IMGNearline"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOIMGNEARLINE_H_
