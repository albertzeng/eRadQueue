// dbovMGRNodeClient.H : Declaration of the CdbovMGRNodeClient class

#ifndef __DBOVMGRNODECLIENT_H_
#define __DBOVMGRNODECLIENT_H_

class CdbovMGRNodeClientAccessor
{
public:
	LONG m_NodeIndex;
	TCHAR m_NodeName[65];
	LONG m_NodeKinds;
	TCHAR m_NodeAETitle[17];
	TCHAR m_NodeIPAddress[17];
	LONG m_NodePORTNumber;
	TCHAR m_NodeRemark[65];
	LONG m_NodeClientServer;
	LONG m_NodeClientClient;
	LONG m_NodeClientPrivilege;
	TCHAR m_NodeClientConfiguration[4001];

BEGIN_COLUMN_MAP(CdbovMGRNodeClientAccessor)
	COLUMN_ENTRY(1, m_NodeIndex)
	COLUMN_ENTRY(2, m_NodeName)
	COLUMN_ENTRY(3, m_NodeKinds)
	COLUMN_ENTRY(4, m_NodeAETitle)
	COLUMN_ENTRY(5, m_NodeIPAddress)
	COLUMN_ENTRY(6, m_NodePORTNumber)
	COLUMN_ENTRY(7, m_NodeRemark)
	COLUMN_ENTRY(8, m_NodeClientServer)
	COLUMN_ENTRY(9, m_NodeClientClient)
	COLUMN_ENTRY(10, m_NodeClientPrivilege)
	COLUMN_ENTRY(11, m_NodeClientConfiguration)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovMGRNodeClientAccessor, _T(" \
	SELECT \
		NodeIndex, \
		NodeName, \
		NodeKinds, \
		NodeAETitle, \
		NodeIPAddress, \
		NodePORTNumber, \
		NodeRemark, \
		NodeClientServer, \
		NodeClientClient, \
		NodeClientPrivilege, \
		NodeClientConfiguration  \
		FROM vMGRNodeClient"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVMGRNODECLIENT_H_
