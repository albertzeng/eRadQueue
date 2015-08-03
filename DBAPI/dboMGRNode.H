// dboMGRNode.H : Declaration of the CdboMGRNode class

#ifndef __DBOMGRNODE_H_
#define __DBOMGRNODE_H_

class CdboMGRNodeAccessor
{
public:
	LONG m_NodeIndex;
	TCHAR m_NodeName[65];
	LONG m_NodeKinds;
	LONG m_NodeManagement;
	TCHAR m_NodeAETitle[17];
	TCHAR m_NodeIPAddress[17];
	LONG m_NodePORTNumber;
	TCHAR m_NodeRemark[65];
	TCHAR m_NodeConfiguration[4001];

BEGIN_COLUMN_MAP(CdboMGRNodeAccessor)
	COLUMN_ENTRY(1, m_NodeIndex)
	COLUMN_ENTRY(2, m_NodeName)
	COLUMN_ENTRY(3, m_NodeKinds)
	COLUMN_ENTRY(4, m_NodeManagement)
	COLUMN_ENTRY(5, m_NodeAETitle)
	COLUMN_ENTRY(6, m_NodeIPAddress)
	COLUMN_ENTRY(7, m_NodePORTNumber)
	COLUMN_ENTRY(8, m_NodeRemark)
	COLUMN_ENTRY(9, m_NodeConfiguration)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRNodeAccessor, _T(" \
	SELECT \
		NodeIndex, \
		NodeName, \
		NodeKinds, \
		NodeManagement, \
		NodeAETitle, \
		NodeIPAddress, \
		NodePORTNumber, \
		NodeRemark, \
		NodeConfiguration  \
		FROM MGRNode"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRNODE_H_
