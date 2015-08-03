// dboEISQueueControl.H : Declaration of the CdboEISQueueControl class

#ifndef __DBOEISQUEUECONTROL_H_
#define __DBOEISQUEUECONTROL_H_

class CdboEISQueueControlAccessor
{
public:
	LONG m_QueueControlDevice;
	LONG m_QueueControlDate;
	LONG m_QueueControlAfternoon;
	LONG m_QueueControlEmergent;
	LONG m_QueueControlPrearrange;
	LONG m_QueueControlCurrent;

BEGIN_COLUMN_MAP(CdboEISQueueControlAccessor)
	COLUMN_ENTRY(1, m_QueueControlDevice)
	COLUMN_ENTRY(2, m_QueueControlDate)
	COLUMN_ENTRY(3, m_QueueControlAfternoon)
	COLUMN_ENTRY(4, m_QueueControlEmergent)
	COLUMN_ENTRY(5, m_QueueControlPrearrange)
	COLUMN_ENTRY(6, m_QueueControlCurrent)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISQueueControlAccessor, _T(" \
	SELECT \
		QueueControlDevice, \
		QueueControlDate, \
		QueueControlAfternoon, \
		QueueControlEmergent, \
		QueueControlPrearrange, \
		QueueControlCurrent  \
		FROM EISQueueControl"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISQUEUECONTROL_H_
