// dboEISService.H : Declaration of the CdboEISService class

#ifndef __DBOEISSERVICE_H_
#define __DBOEISSERVICE_H_

class CdboEISServiceAccessor
{
public:
	LONG m_ServiceIndex;
	LONG m_ServiceStudies;
	LONG m_ServiceResults;
	LONG m_ServiceExchange;
	LONG m_ServiceExamine;
	TCHAR m_ServiceExamineAlias[65];
	double m_ServiceExaminePrice;
	TCHAR m_ServiceModalities[17];
	LONG m_ServiceDevice;
	TCHAR m_ServiceDeviceAlias[65];
	TCHAR m_ServiceAETitle[17];
	TCHAR m_ServiceBodiesCode[65];
	LONG m_ServiceBodies;
	TCHAR m_ServiceBodiesAlias[65];
	TCHAR m_ServiceClassified[65];
	TCHAR m_ServiceSpecs[65];
	TCHAR m_ServiceSpecsAlias[65];
	LONG m_ExecuteDoctor;
	TCHAR m_ExecuteDoctorAlias[65];
	TCHAR m_ExecuteDate[9];
	TCHAR m_ExecuteTime[7];
	LONG m_ExecuteSeconds;
	LONG m_ExecuteDevice;

BEGIN_COLUMN_MAP(CdboEISServiceAccessor)
	COLUMN_ENTRY(1, m_ServiceIndex)
	COLUMN_ENTRY(2, m_ServiceStudies)
	COLUMN_ENTRY(3, m_ServiceResults)
	COLUMN_ENTRY(4, m_ServiceExchange)
	COLUMN_ENTRY(5, m_ServiceExamine)
	COLUMN_ENTRY(6, m_ServiceExamineAlias)
	COLUMN_ENTRY(7, m_ServiceExaminePrice)
	COLUMN_ENTRY(8, m_ServiceModalities)
	COLUMN_ENTRY(9, m_ServiceDevice)
	COLUMN_ENTRY(10, m_ServiceDeviceAlias)
	COLUMN_ENTRY(11, m_ServiceAETitle)
	COLUMN_ENTRY(12, m_ServiceBodiesCode)
	COLUMN_ENTRY(13, m_ServiceBodies)
	COLUMN_ENTRY(14, m_ServiceBodiesAlias)
	COLUMN_ENTRY(15, m_ServiceClassified)
	COLUMN_ENTRY(16, m_ServiceSpecs)
	COLUMN_ENTRY(17, m_ServiceSpecsAlias)
	COLUMN_ENTRY(18, m_ExecuteDoctor)
	COLUMN_ENTRY(19, m_ExecuteDoctorAlias)
	COLUMN_ENTRY(20, m_ExecuteDate)
	COLUMN_ENTRY(21, m_ExecuteTime)
	COLUMN_ENTRY(22, m_ExecuteSeconds)
	COLUMN_ENTRY(23, m_ExecuteDevice)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISServiceAccessor, _T(" \
	SELECT \
		ServiceIndex, \
		ServiceStudies, \
		ServiceResults, \
		ServiceExchange, \
		ServiceExamine, \
		ServiceExamineAlias, \
		ServiceExaminePrice, \
		ServiceModalities, \
		ServiceDevice, \
		ServiceDeviceAlias, \
		ServiceAETitle, \
		ServiceBodiesCode, \
		ServiceBodies, \
		ServiceBodiesAlias, \
		ServiceClassified, \
		ServiceSpecs, \
		ServiceSpecsAlias, \
		ExecuteDoctor, \
		ExecuteDoctorAlias, \
		ExecuteDate, \
		ExecuteTime, \
		ExecuteSeconds, \
		ExecuteDevice  \
		FROM EISService"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISSERVICE_H_
