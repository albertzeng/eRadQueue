// JHJCPDJHXX.H : Declaration of the CdboJHJCPDJHXX class

#ifndef __JHJCPDJHXX_H_
#define __JHJCPDJHXX_H_

class CdboJHJCPDJHXXAccessor
{
public:
	DB_NUMERIC m_XH;
	DB_NUMERIC m_QHXH;
	TCHAR m_JZKH[41];
	TCHAR m_BRXM[21];
	TCHAR m_CKBH[11];
	DB_NUMERIC m_XSBZ;
	DBTIMESTAMP m_JZRQ;
	TCHAR m_KSDM[11];

BEGIN_COLUMN_MAP(CdboJHJCPDJHXXAccessor)
	COLUMN_ENTRY_PS(1, 10, 0, m_XH)
	COLUMN_ENTRY_PS(2, 10, 0, m_QHXH)
	COLUMN_ENTRY(3, m_JZKH)
	COLUMN_ENTRY(4, m_BRXM)
	COLUMN_ENTRY(5, m_CKBH)
	COLUMN_ENTRY_PS(6, 1, 0, m_XSBZ)
	COLUMN_ENTRY(7, m_JZRQ)
	COLUMN_ENTRY(8, m_KSDM)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboJHJCPDJHXXAccessor, _T(" \
	SELECT \
		XH, \
		QH_XH, \
		JZKH, \
		BRXM, \
		CKBH, \
		XSBZ, \
		JZRQ, \
		KSDM  \
		FROM JH.JCPD_JHXX"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __JHJCPDJHXX_H_
