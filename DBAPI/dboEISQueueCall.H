// dboEISQueueCall.H : Declaration of the CdboEISQueueCall class

#ifndef __DBOEISQUEUECALL_H_
#define __DBOEISQUEUECALL_H_

class CdboEISQueueCallAccessor
{
public:
	LONG m_CallIndex;
	LONG m_CallQueue;
	LONG m_CallConsole;
	LONG m_CallNode;
	TCHAR m_CallName[65];
	TCHAR m_CallTS[17];

BEGIN_COLUMN_MAP(CdboEISQueueCallAccessor)
	COLUMN_ENTRY(1, m_CallIndex)
	COLUMN_ENTRY(2, m_CallQueue)
	COLUMN_ENTRY(3, m_CallConsole)
	COLUMN_ENTRY(4, m_CallNode)
	COLUMN_ENTRY(5, m_CallName)
	COLUMN_ENTRY(6, m_CallTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISQueueCallAccessor, _T(" \
	SELECT \
		CallIndex, \
		CallQueue, \
		CallConsole, \
		CallNode, \
		CallName, \
		CallTS  \
		FROM EISQueueCall"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISQUEUECALL_H_
