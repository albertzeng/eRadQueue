// dbovEISMwl.H : Declaration of the CdbovEISMwl class

#ifndef __DBOVEISMWL_H_
#define __DBOVEISMWL_H_

class CdbovEISMwlAccessor
{
public:
	LONG m_PatientsIndex;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsAlias[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsIDAlias[65];
	TCHAR m_PatientsSex[9];
	TCHAR m_PatientsDOB[9];
	TCHAR m_PatientsPhone[65];
	TCHAR m_PatientsPostcode[65];
	TCHAR m_PatientsAddress[65];
	TCHAR m_PatientsCertificate[65];
	TCHAR m_PatientsComments[513];
	LONG m_StudiesIndex;
	LONG m_StudiesDepartment;
	TCHAR m_StudiesAge[5];
	LONG m_StudiesSize;
	LONG m_StudiesWeight;
	LONG m_AdmissionSource;
	LONG m_AdmissionEmergencies;
	TCHAR m_AdmissionID[65];
	TCHAR m_AdmissionLocation[65];
	TCHAR m_AccessionPrearrange[65];
	TCHAR m_AccessionNumber[65];
	TCHAR m_StudiesInstUID[65];
	LONG m_StudiesStatus;
	TCHAR m_StudiesDate[9];
	TCHAR m_StudiesTime[7];
	TCHAR m_StudiesDoneDate[9];
	TCHAR m_StudiesDoneTime[7];
	TCHAR m_RequestReason[513];
	LONG m_RequestDoctor;
	TCHAR m_RequestDoctorAlias[65];
	LONG m_RequestDepartment;
	TCHAR m_RequestDepartmentAlias[65];
	LONG m_RegisterDoctor;
	TCHAR m_RegisterDoctorAlias[65];
	TCHAR m_RegisterDate[9];
	TCHAR m_RegisterTime[7];
	LONG m_ServiceIndex;
	LONG m_ServiceExamine;
	TCHAR m_ServiceExamineAlias[65];
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

BEGIN_COLUMN_MAP(CdbovEISMwlAccessor)
	COLUMN_ENTRY(1, m_PatientsIndex)
	COLUMN_ENTRY(2, m_PatientsName)
	COLUMN_ENTRY(3, m_PatientsAlias)
	COLUMN_ENTRY(4, m_PatientsID)
	COLUMN_ENTRY(5, m_PatientsIDAlias)
	COLUMN_ENTRY(6, m_PatientsSex)
	COLUMN_ENTRY(7, m_PatientsDOB)
	COLUMN_ENTRY(8, m_PatientsPhone)
	COLUMN_ENTRY(9, m_PatientsPostcode)
	COLUMN_ENTRY(10, m_PatientsAddress)
	COLUMN_ENTRY(11, m_PatientsCertificate)
	COLUMN_ENTRY(12, m_PatientsComments)
	COLUMN_ENTRY(13, m_StudiesIndex)
	COLUMN_ENTRY(14, m_StudiesDepartment)
	COLUMN_ENTRY(15, m_StudiesAge)
	COLUMN_ENTRY(16, m_StudiesSize)
	COLUMN_ENTRY(17, m_StudiesWeight)
	COLUMN_ENTRY(18, m_AdmissionSource)
	COLUMN_ENTRY(19, m_AdmissionEmergencies)
	COLUMN_ENTRY(20, m_AdmissionID)
	COLUMN_ENTRY(21, m_AdmissionLocation)
	COLUMN_ENTRY(22, m_AccessionPrearrange)
	COLUMN_ENTRY(23, m_AccessionNumber)
	COLUMN_ENTRY(24, m_StudiesInstUID)
	COLUMN_ENTRY(25, m_StudiesStatus)
	COLUMN_ENTRY(26, m_StudiesDate)
	COLUMN_ENTRY(27, m_StudiesTime)
	COLUMN_ENTRY(28, m_StudiesDoneDate)
	COLUMN_ENTRY(29, m_StudiesDoneTime)
	COLUMN_ENTRY(30, m_RequestReason)
	COLUMN_ENTRY(31, m_RequestDoctor)
	COLUMN_ENTRY(32, m_RequestDoctorAlias)
	COLUMN_ENTRY(33, m_RequestDepartment)
	COLUMN_ENTRY(34, m_RequestDepartmentAlias)
	COLUMN_ENTRY(35, m_RegisterDoctor)
	COLUMN_ENTRY(36, m_RegisterDoctorAlias)
	COLUMN_ENTRY(37, m_RegisterDate)
	COLUMN_ENTRY(38, m_RegisterTime)
	COLUMN_ENTRY(39, m_ServiceIndex)
	COLUMN_ENTRY(40, m_ServiceExamine)
	COLUMN_ENTRY(41, m_ServiceExamineAlias)
	COLUMN_ENTRY(42, m_ServiceModalities)
	COLUMN_ENTRY(43, m_ServiceDevice)
	COLUMN_ENTRY(44, m_ServiceDeviceAlias)
	COLUMN_ENTRY(45, m_ServiceAETitle)
	COLUMN_ENTRY(46, m_ServiceBodiesCode)
	COLUMN_ENTRY(47, m_ServiceBodies)
	COLUMN_ENTRY(48, m_ServiceBodiesAlias)
	COLUMN_ENTRY(49, m_ServiceClassified)
	COLUMN_ENTRY(50, m_ServiceSpecs)
	COLUMN_ENTRY(51, m_ServiceSpecsAlias)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovEISMwlAccessor, _T(" \
	SELECT \
		PatientsIndex, \
		PatientsName, \
		PatientsAlias, \
		PatientsID, \
		PatientsIDAlias, \
		PatientsSex, \
		PatientsDOB, \
		PatientsPhone, \
		PatientsPostcode, \
		PatientsAddress, \
		PatientsCertificate, \
		PatientsComments, \
		StudiesIndex, \
		StudiesDepartment, \
		StudiesAge, \
		StudiesSize, \
		StudiesWeight, \
		AdmissionSource, \
		AdmissionEmergencies, \
		AdmissionID, \
		AdmissionLocation, \
		AccessionPrearrange, \
		AccessionNumber, \
		StudiesInstUID, \
		StudiesStatus, \
		StudiesDate, \
		StudiesTime, \
		StudiesDoneDate, \
		StudiesDoneTime, \
		RequestReason, \
		RequestDoctor, \
		RequestDoctorAlias, \
		RequestDepartment, \
		RequestDepartmentAlias, \
		RegisterDoctor, \
		RegisterDoctorAlias, \
		RegisterDate, \
		RegisterTime, \
		ServiceIndex, \
		ServiceExamine, \
		ServiceExamineAlias, \
		ServiceModalities, \
		ServiceDevice, \
		ServiceDeviceAlias, \
		ServiceAETitle, \
		ServiceBodiesCode, \
		ServiceBodies, \
		ServiceBodiesAlias, \
		ServiceClassified, \
		ServiceSpecs, \
		ServiceSpecsAlias  \
		FROM vEISMwl"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVEISMWL_H_
