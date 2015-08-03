// dboIMGOperate.H : Declaration of the CdboIMGOperate class

#ifndef __DBOIMGOPERATE_H_
#define __DBOIMGOPERATE_H_

class CdboIMGOperateAccessor
{
public:
	LONG m_OperateIndex;
	LONG m_OperatePACSStudies;
	LONG m_OperateQACSStudies;
	TCHAR m_OperateTargetAE[17];
	LONG m_OperateCommands;
	TCHAR m_OperateTS[17];
	LONG m_OperateTimes;
	LONG m_OperateCode;
	TCHAR m_OperateMessage[65];
	TCHAR m_OperateReworkTS[17];
	TCHAR m_OperateTransactionUID[65];

BEGIN_COLUMN_MAP(CdboIMGOperateAccessor)
	COLUMN_ENTRY(1, m_OperateIndex)
	COLUMN_ENTRY(2, m_OperatePACSStudies)
	COLUMN_ENTRY(3, m_OperateQACSStudies)
	COLUMN_ENTRY(4, m_OperateTargetAE)
	COLUMN_ENTRY(5, m_OperateCommands)
	COLUMN_ENTRY(6, m_OperateTS)
	COLUMN_ENTRY(7, m_OperateTimes)
	COLUMN_ENTRY(8, m_OperateCode)
	COLUMN_ENTRY(9, m_OperateMessage)
	COLUMN_ENTRY(10, m_OperateReworkTS)
	COLUMN_ENTRY(11, m_OperateTransactionUID)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboIMGOperateAccessor, _T(" \
	SELECT \
		OperateIndex, \
		OperatePACSStudies, \
		OperateQACSStudies, \
		OperateTargetAE, \
		OperateCommands, \
		OperateTS, \
		OperateTimes, \
		OperateCode, \
		OperateMessage, \
		OperateReworkTS, \
		OperateTransactionUID  \
		FROM IMGOperate"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOIMGOPERATE_H_
