// DBOJHPDZSXX.H : Declaration of the CdboJHPDZSXX class

#ifndef __DBOJHPDZSXX_H_
#define __DBOJHPDZSXX_H_

class CdboJHPDZSXXAccessor
{
public:
	TCHAR m_ZSBH[11];
	TCHAR m_ZSMC[21];

BEGIN_COLUMN_MAP(CdboJHPDZSXXAccessor)
	COLUMN_ENTRY(1, m_ZSBH)
	COLUMN_ENTRY(2, m_ZSMC)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboJHPDZSXXAccessor, _T(" \
	SELECT \
		ZSBH, \
		ZSMC  \
		FROM PD_ZSXX"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOJHPDZSXX_H_
