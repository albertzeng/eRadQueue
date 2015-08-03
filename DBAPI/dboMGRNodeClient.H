// dboMGRNodeClient.H : Declaration of the CdboMGRNodeClient class

#ifndef __DBOMGRNODECLIENT_H_
#define __DBOMGRNODECLIENT_H_

class CdboMGRNodeClientAccessor
{
public:
	LONG m_NodeClientServer;
	LONG m_NodeClientClient;
	LONG m_NodeClientPrivilege;
	TCHAR m_NodeClientConfiguration[4001];

BEGIN_COLUMN_MAP(CdboMGRNodeClientAccessor)
	COLUMN_ENTRY(1, m_NodeClientServer)
	COLUMN_ENTRY(2, m_NodeClientClient)
	COLUMN_ENTRY(3, m_NodeClientPrivilege)
	COLUMN_ENTRY(4, m_NodeClientConfiguration)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRNodeClientAccessor, _T(" \
	SELECT \
		NodeClientServer, \
		NodeClientClient, \
		NodeClientPrivilege, \
		NodeClientConfiguration  \
		FROM MGRNodeClient"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRNODECLIENT_H_
