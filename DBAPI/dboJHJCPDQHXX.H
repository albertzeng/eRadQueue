// DBOJHJCPDQHXX.H : Declaration of the CdboJHJCPDQHXX class

#ifndef __DBOJHJCPDQHXX_H_
#define __DBOJHJCPDQHXX_H_

class CdboJHJCPDQHXXAccessor
{
public:
	LONG m_XH;
	LONG m_DLXH;
	LONG m_DLH;
	TCHAR m_JZKH[41];
	TCHAR m_BRXM[21];
	LONG m_XB;
	LONG m_CKBH;
	DBTIMESTAMP m_CXSJ;
	LONG m_JHBZ;
	DBTIMESTAMP m_JHSJ;
	TCHAR m_JHCK[11];
	LONG m_JHXH;
	DBTIMESTAMP m_QHSJ;
	TCHAR m_DDCK[11];
	LONG m_DDSX;
	LONG m_SFXH;
	LONG m_YLXH;
	LONG m_MZZY;
	LONG m_YJSB;
	TCHAR m_KSDM[11];
	TCHAR m_BRLX[21];
	TCHAR m_YYH[41];
	TCHAR m_YYSD[41];
	TCHAR m_FPHM[41];

BEGIN_COLUMN_MAP(CdboJHJCPDQHXXAccessor)
	COLUMN_ENTRY(1, m_XH)
	COLUMN_ENTRY(2, m_DLXH)
	COLUMN_ENTRY(3, m_DLH)
	COLUMN_ENTRY(4, m_JZKH)
	COLUMN_ENTRY(5, m_BRXM)
	COLUMN_ENTRY(6, m_XB)
	COLUMN_ENTRY(7, m_CKBH)
	COLUMN_ENTRY(8, m_CXSJ)
	COLUMN_ENTRY(9, m_JHBZ)
	COLUMN_ENTRY(10, m_JHSJ)
	COLUMN_ENTRY(11, m_JHCK)
	COLUMN_ENTRY(12, m_JHXH)
	COLUMN_ENTRY(13, m_QHSJ)
	COLUMN_ENTRY(14, m_DDCK)
	COLUMN_ENTRY(15, m_DDSX)
	COLUMN_ENTRY(16, m_SFXH)
	COLUMN_ENTRY(17, m_YLXH)
	COLUMN_ENTRY(18, m_MZZY)
	COLUMN_ENTRY(19, m_YJSB)
	COLUMN_ENTRY(20, m_KSDM)
	COLUMN_ENTRY(21, m_BRLX)
	COLUMN_ENTRY(22, m_YYH)
	COLUMN_ENTRY(23, m_YYSD)
	COLUMN_ENTRY(24, m_FPHM)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboJHJCPDQHXXAccessor, _T(" \
	SELECT \
		XH, \
		DLXH, \
		DLH, \
		JZKH, \
		BRXM, \
		XB, \
		CKBH, \
		CXSJ, \
		JHBZ, \
		JHSJ, \
		JHCK, \
		JHXH, \
		QHSJ, \
		DDCK, \
		DDSX, \
		SFXH, \
		YLXH, \
		MZZY, \
		YJSB, \
		KSDM, \
		BRLX, \
		YYH, \
		YYSD, \
		FPHM  \
		FROM JCPD_QHXX"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOJHJCPDQHXX_H_
