// dboEISQueue.H : Declaration of the CdboEISQueue class

#ifndef __DBOEISQUEUE_H_
#define __DBOEISQUEUE_H_

class CdboEISQueueAccessor
{
public:
	LONG m_QueueIndex;
	LONG m_QueueDevice;
	TCHAR m_QueueDeviceAlias[65];
	LONG m_QueueDate;
	LONG m_QueueAfternoon;
	LONG m_QueueEmergent;
	LONG m_QueuePrearrange;
	LONG m_QueueNumber;
	LONG m_QueueStatus;
	TCHAR m_QueueTS[17];
	LONG m_QueueStudies;
	LONG m_QueueService;
	TCHAR m_PatientsAlias[65];
	TCHAR m_PatientsID[65];
	TCHAR m_AdmissionID[65];
	TCHAR m_AccessionNumber[65];
	TCHAR m_ExamineAlias[201];
	TCHAR m_BodiesAlias[201];
	LONG m_QueueNumberReset;
	LONG m_QueueCallNode;
	TCHAR m_QueueCallName[65];
	TCHAR m_QueueCallTS[17];
	TCHAR m_QueueNumberExtension[65];

BEGIN_COLUMN_MAP(CdboEISQueueAccessor)
	COLUMN_ENTRY(1, m_QueueIndex)
	COLUMN_ENTRY(2, m_QueueDevice)
	COLUMN_ENTRY(3, m_QueueDeviceAlias)
	COLUMN_ENTRY(4, m_QueueDate)
	COLUMN_ENTRY(5, m_QueueAfternoon)
	COLUMN_ENTRY(6, m_QueueEmergent)
	COLUMN_ENTRY(7, m_QueuePrearrange)
	COLUMN_ENTRY(8, m_QueueNumber)
	COLUMN_ENTRY(9, m_QueueStatus)
	COLUMN_ENTRY(10, m_QueueTS)
	COLUMN_ENTRY(11, m_QueueStudies)
	COLUMN_ENTRY(12, m_QueueService)
	COLUMN_ENTRY(13, m_PatientsAlias)
	COLUMN_ENTRY(14, m_PatientsID)
	COLUMN_ENTRY(15, m_AdmissionID)
	COLUMN_ENTRY(16, m_AccessionNumber)
	COLUMN_ENTRY(17, m_ExamineAlias)
	COLUMN_ENTRY(18, m_BodiesAlias)
	COLUMN_ENTRY(19, m_QueueNumberReset)
	COLUMN_ENTRY(20, m_QueueCallNode)
	COLUMN_ENTRY(21, m_QueueCallName)
	COLUMN_ENTRY(22, m_QueueCallTS)
	COLUMN_ENTRY(23, m_QueueNumberExtension)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISQueueAccessor, _T(" \
	SELECT \
		QueueIndex, \
		QueueDevice, \
		QueueDeviceAlias, \
		QueueDate, \
		QueueAfternoon, \
		QueueEmergent, \
		QueuePrearrange, \
		QueueNumber, \
		QueueStatus, \
		QueueTS, \
		QueueStudies, \
		QueueService, \
		PatientsAlias, \
		PatientsID, \
		AdmissionID, \
		AccessionNumber, \
		ExamineAlias, \
		BodiesAlias, \
		QueueNumberReset, \
		QueueCallNode, \
		QueueCallName, \
		QueueCallTS,  \
		QueueNumberExtension \
		FROM EISQueue"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISQUEUE_H_
