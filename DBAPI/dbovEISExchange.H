// dbovEISExchange.H : Declaration of the CdbovEISExchange class

#ifndef __DBOVEISEXCHANGE_H_
#define __DBOVEISEXCHANGE_H_

class CdbovEISExchangeAccessor
{
public:
	LONG m_ExchangeIndex;
	LONG m_ExchangeCode;
	LONG m_ExchangeStudies;
	LONG m_ExchangeService;
	LONG m_ExchangeReports;
	TCHAR m_ExchangeTS[17];
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
	LONG m_StudiesSuspense;
	LONG m_StudiesFilms;
	LONG m_StudiesReviews;
	LONG m_StudiesMasculine;
	LONG m_StudiesKeenness;
	LONG m_StudiesConsultation;
	LONG m_StudiesLearn;
	TCHAR m_StudiesDate[9];
	TCHAR m_StudiesTime[7];
	TCHAR m_StudiesDoneDate[9];
	TCHAR m_StudiesDoneTime[7];
	TCHAR m_StudiesExamine[65];
	TCHAR m_StudiesExamineAlias[201];
	double m_StudiesExaminePrice;
	TCHAR m_StudiesBodiesCode[65];
	TCHAR m_StudiesBodies[65];
	TCHAR m_StudiesBodiesAlias[201];
	TCHAR m_StudiesModalities[65];
	TCHAR m_StudiesClassified[65];
	TCHAR m_StudiesAETitle[65];
	TCHAR m_RequestReason[513];
	LONG m_RequestDoctor;
	TCHAR m_RequestDoctorAlias[65];
	LONG m_RequestDepartment;
	TCHAR m_RequestDepartmentAlias[65];
	LONG m_RegisterDoctor;
	TCHAR m_RegisterDoctorAlias[65];
	TCHAR m_RegisterDate[9];
	TCHAR m_RegisterTime[7];
	LONG m_ExecuteDoctor;
	TCHAR m_ExecuteDoctorAlias[65];
	TCHAR m_ExecuteDate[9];
	TCHAR m_ExecuteTime[7];
	LONG m_ExecuteSeconds;
	LONG m_ExecuteDevice;
	TCHAR m_ExecuteTechnologies[513];
	TCHAR m_ExecuteComments[513];
	TCHAR m_AdmissionSourceHospital[65];
	TCHAR m_RequestElectronic[513];
	TCHAR m_RequestClinic[513];
	LONG m_StudiesChargeStatus;
	TCHAR m_StudiesChargeClassified[65];
	double m_StudiesChargeFilms;
	TCHAR m_ExecuteDeviceAlias[65];
	TCHAR m_ExecuteDeviceModel[65];
	TCHAR m_ExecuteDeviceHZ[65];
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
	LONG m_PatientsProtective;
	TCHAR m_PatientsOccupation[65];

BEGIN_COLUMN_MAP(CdbovEISExchangeAccessor)
	COLUMN_ENTRY(1, m_ExchangeIndex)
	COLUMN_ENTRY(2, m_ExchangeCode)
	COLUMN_ENTRY(3, m_ExchangeStudies)
	COLUMN_ENTRY(4, m_ExchangeService)
	COLUMN_ENTRY(5, m_ExchangeReports)
	COLUMN_ENTRY(6, m_ExchangeTS)
	COLUMN_ENTRY(7, m_StudiesIndex)
	COLUMN_ENTRY(8, m_StudiesDepartment)
	COLUMN_ENTRY(9, m_StudiesAge)
	COLUMN_ENTRY(10, m_StudiesSize)
	COLUMN_ENTRY(11, m_StudiesWeight)
	COLUMN_ENTRY(12, m_AdmissionSource)
	COLUMN_ENTRY(13, m_AdmissionEmergencies)
	COLUMN_ENTRY(14, m_AdmissionID)
	COLUMN_ENTRY(15, m_AdmissionLocation)
	COLUMN_ENTRY(16, m_AccessionPrearrange)
	COLUMN_ENTRY(17, m_AccessionNumber)
	COLUMN_ENTRY(18, m_StudiesInstUID)
	COLUMN_ENTRY(19, m_StudiesStatus)
	COLUMN_ENTRY(20, m_StudiesSuspense)
	COLUMN_ENTRY(21, m_StudiesFilms)
	COLUMN_ENTRY(22, m_StudiesReviews)
	COLUMN_ENTRY(23, m_StudiesMasculine)
	COLUMN_ENTRY(24, m_StudiesKeenness)
	COLUMN_ENTRY(25, m_StudiesConsultation)
	COLUMN_ENTRY(26, m_StudiesLearn)
	COLUMN_ENTRY(27, m_StudiesDate)
	COLUMN_ENTRY(28, m_StudiesTime)
	COLUMN_ENTRY(29, m_StudiesDoneDate)
	COLUMN_ENTRY(30, m_StudiesDoneTime)
	COLUMN_ENTRY(31, m_StudiesExamine)
	COLUMN_ENTRY(32, m_StudiesExamineAlias)
	COLUMN_ENTRY(33, m_StudiesExaminePrice)
	COLUMN_ENTRY(34, m_StudiesBodiesCode)
	COLUMN_ENTRY(35, m_StudiesBodies)
	COLUMN_ENTRY(36, m_StudiesBodiesAlias)
	COLUMN_ENTRY(37, m_StudiesModalities)
	COLUMN_ENTRY(38, m_StudiesClassified)
	COLUMN_ENTRY(39, m_StudiesAETitle)
	COLUMN_ENTRY(40, m_RequestReason)
	COLUMN_ENTRY(41, m_RequestDoctor)
	COLUMN_ENTRY(42, m_RequestDoctorAlias)
	COLUMN_ENTRY(43, m_RequestDepartment)
	COLUMN_ENTRY(44, m_RequestDepartmentAlias)
	COLUMN_ENTRY(45, m_RegisterDoctor)
	COLUMN_ENTRY(46, m_RegisterDoctorAlias)
	COLUMN_ENTRY(47, m_RegisterDate)
	COLUMN_ENTRY(48, m_RegisterTime)
	COLUMN_ENTRY(49, m_ExecuteDoctor)
	COLUMN_ENTRY(50, m_ExecuteDoctorAlias)
	COLUMN_ENTRY(51, m_ExecuteDate)
	COLUMN_ENTRY(52, m_ExecuteTime)
	COLUMN_ENTRY(53, m_ExecuteSeconds)
	COLUMN_ENTRY(54, m_ExecuteDevice)
	COLUMN_ENTRY(55, m_ExecuteTechnologies)
	COLUMN_ENTRY(56, m_ExecuteComments)
	COLUMN_ENTRY(57, m_AdmissionSourceHospital)
	COLUMN_ENTRY(58, m_RequestElectronic)
	COLUMN_ENTRY(59, m_RequestClinic)
	COLUMN_ENTRY(60, m_StudiesChargeStatus)
	COLUMN_ENTRY(61, m_StudiesChargeClassified)
	COLUMN_ENTRY(62, m_StudiesChargeFilms)
	COLUMN_ENTRY(63, m_ExecuteDeviceAlias)
	COLUMN_ENTRY(64, m_ExecuteDeviceModel)
	COLUMN_ENTRY(65, m_ExecuteDeviceHZ)
	COLUMN_ENTRY(66, m_PatientsIndex)
	COLUMN_ENTRY(67, m_PatientsName)
	COLUMN_ENTRY(68, m_PatientsAlias)
	COLUMN_ENTRY(69, m_PatientsID)
	COLUMN_ENTRY(70, m_PatientsIDAlias)
	COLUMN_ENTRY(71, m_PatientsSex)
	COLUMN_ENTRY(72, m_PatientsDOB)
	COLUMN_ENTRY(73, m_PatientsPhone)
	COLUMN_ENTRY(74, m_PatientsPostcode)
	COLUMN_ENTRY(75, m_PatientsAddress)
	COLUMN_ENTRY(76, m_PatientsCertificate)
	COLUMN_ENTRY(77, m_PatientsComments)
	COLUMN_ENTRY(78, m_PatientsProtective)
	COLUMN_ENTRY(79, m_PatientsOccupation)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovEISExchangeAccessor, _T(" \
	SELECT \
		ExchangeIndex, \
		ExchangeCode, \
		ExchangeStudies, \
		ExchangeService, \
		ExchangeReports, \
		ExchangeTS, \
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
		StudiesSuspense, \
		StudiesFilms, \
		StudiesReviews, \
		StudiesMasculine, \
		StudiesKeenness, \
		StudiesConsultation, \
		StudiesLearn, \
		StudiesDate, \
		StudiesTime, \
		StudiesDoneDate, \
		StudiesDoneTime, \
		StudiesExamine, \
		StudiesExamineAlias, \
		StudiesExaminePrice, \
		StudiesBodiesCode, \
		StudiesBodies, \
		StudiesBodiesAlias, \
		StudiesModalities, \
		StudiesClassified, \
		StudiesAETitle, \
		RequestReason, \
		RequestDoctor, \
		RequestDoctorAlias, \
		RequestDepartment, \
		RequestDepartmentAlias, \
		RegisterDoctor, \
		RegisterDoctorAlias, \
		RegisterDate, \
		RegisterTime, \
		ExecuteDoctor, \
		ExecuteDoctorAlias, \
		ExecuteDate, \
		ExecuteTime, \
		ExecuteSeconds, \
		ExecuteDevice, \
		ExecuteTechnologies, \
		ExecuteComments, \
		AdmissionSourceHospital, \
		RequestElectronic, \
		RequestClinic, \
		StudiesChargeStatus, \
		StudiesChargeClassified, \
		StudiesChargeFilms, \
		ExecuteDeviceAlias, \
		ExecuteDeviceModel, \
		ExecuteDeviceHZ, \
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
		PatientsProtective, \
		PatientsOccupation  \
		FROM vEISExchange"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVEISEXCHANGE_H_
