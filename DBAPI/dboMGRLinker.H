// dboMGRLinker.H : Declaration of the CdboMGRLinker class

#ifndef __DBOMGRLINKER_H_
#define __DBOMGRLINKER_H_

class CdboMGRLinkerAccessor
{
public:
	LONG m_LinkerIndex;
	LONG m_LinkerNode;
	LONG m_LinkerCurrent;
	LONG m_LinkerActive;
	TCHAR m_LinkerName[65];
	TCHAR m_LinkerRemark[65];
	TCHAR m_LinkerConfiguration[4001];

BEGIN_COLUMN_MAP(CdboMGRLinkerAccessor)
	COLUMN_ENTRY(1, m_LinkerIndex)
	COLUMN_ENTRY(2, m_LinkerNode)
	COLUMN_ENTRY(3, m_LinkerCurrent)
	COLUMN_ENTRY(4, m_LinkerActive)
	COLUMN_ENTRY(5, m_LinkerName)
	COLUMN_ENTRY(6, m_LinkerRemark)
	COLUMN_ENTRY(7, m_LinkerConfiguration)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRLinkerAccessor, _T(" \
	SELECT \
		LinkerIndex, \
		LinkerNode, \
		LinkerCurrent, \
		LinkerActive, \
		LinkerName, \
		LinkerRemark, \
		LinkerConfiguration  \
		FROM MGRLinker"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRLINKER_H_
