// dbovEISWorksService.H : Declaration of the CdbovEISWorksService class

#ifndef __DBOVEISWORKSSERVICE_H_
#define __DBOVEISWORKSSERVICE_H_

class CdbovEISWorksServiceAccessor
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
	LONG m_PatientsProtective;
	TCHAR m_PatientsOccupation[65];
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
	LONG m_ResultsIndex;
	LONG m_ResultsReports;
	TCHAR m_ResultsExamine[65];
	TCHAR m_ResultsExamineAlias[201];
	TCHAR m_ResultsBodiesCode[65];
	TCHAR m_ResultsBodies[65];
	TCHAR m_ResultsBodiesAlias[201];
	TCHAR m_ResultsDate[9];
	TCHAR m_ResultsTime[7];
	TCHAR m_ResultsTemplate[65];
	TCHAR m_ResultsOutDate[9];
	TCHAR m_ResultsOutTime[7];
	TCHAR m_ResultsComments[513];
	LONG m_ReportsIndex;
	LONG m_ReportsStatus;
	LONG m_ReportsOutStatus;
	LONG m_RecordsDoctor;
	TCHAR m_RecordsDoctorAlias[65];
	TCHAR m_RecordsDate[9];
	TCHAR m_RecordsTime[7];
	LONG m_ReportsDoctor;
	TCHAR m_ReportsDoctorAlias[65];
	TCHAR m_ReportsDate[9];
	TCHAR m_ReportsTime[7];
	LONG m_ApproveDoctor;
	TCHAR m_ApproveDoctorAlias[65];
	TCHAR m_ApproveDate[9];
	TCHAR m_ApproveTime[7];
	TCHAR m_ReportsConclusion[20480];
	TCHAR m_ReportsEvidences[20480];
	TCHAR m_ReportsTechnologies[20480];
	TCHAR m_ReportsComments[20480];
	LONG m_ServiceIndex;
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
	LONG m_ExecuteDoctor;
	TCHAR m_ExecuteDoctorAlias[65];
	TCHAR m_ExecuteDate[9];
	TCHAR m_ExecuteTime[7];
	LONG m_ExecuteSeconds;
	LONG m_ExecuteDevice;

BEGIN_COLUMN_MAP(CdbovEISWorksServiceAccessor)
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
	COLUMN_ENTRY(13, m_PatientsProtective)
	COLUMN_ENTRY(14, m_PatientsOccupation)
	COLUMN_ENTRY(15, m_StudiesIndex)
	COLUMN_ENTRY(16, m_StudiesDepartment)
	COLUMN_ENTRY(17, m_StudiesAge)
	COLUMN_ENTRY(18, m_StudiesSize)
	COLUMN_ENTRY(19, m_StudiesWeight)
	COLUMN_ENTRY(20, m_AdmissionSource)
	COLUMN_ENTRY(21, m_AdmissionEmergencies)
	COLUMN_ENTRY(22, m_AdmissionID)
	COLUMN_ENTRY(23, m_AdmissionLocation)
	COLUMN_ENTRY(24, m_AccessionPrearrange)
	COLUMN_ENTRY(25, m_AccessionNumber)
	COLUMN_ENTRY(26, m_StudiesInstUID)
	COLUMN_ENTRY(27, m_StudiesStatus)
	COLUMN_ENTRY(28, m_StudiesSuspense)
	COLUMN_ENTRY(29, m_StudiesFilms)
	COLUMN_ENTRY(30, m_StudiesReviews)
	COLUMN_ENTRY(31, m_StudiesMasculine)
	COLUMN_ENTRY(32, m_StudiesKeenness)
	COLUMN_ENTRY(33, m_StudiesConsultation)
	COLUMN_ENTRY(34, m_StudiesLearn)
	COLUMN_ENTRY(35, m_StudiesDate)
	COLUMN_ENTRY(36, m_StudiesTime)
	COLUMN_ENTRY(37, m_StudiesDoneDate)
	COLUMN_ENTRY(38, m_StudiesDoneTime)
	COLUMN_ENTRY(39, m_StudiesExamine)
	COLUMN_ENTRY(40, m_StudiesExamineAlias)
	COLUMN_ENTRY(41, m_StudiesExaminePrice)
	COLUMN_ENTRY(42, m_StudiesBodiesCode)
	COLUMN_ENTRY(43, m_StudiesBodies)
	COLUMN_ENTRY(44, m_StudiesBodiesAlias)
	COLUMN_ENTRY(45, m_StudiesModalities)
	COLUMN_ENTRY(46, m_StudiesClassified)
	COLUMN_ENTRY(47, m_StudiesAETitle)
	COLUMN_ENTRY(48, m_RequestReason)
	COLUMN_ENTRY(49, m_RequestDoctor)
	COLUMN_ENTRY(50, m_RequestDoctorAlias)
	COLUMN_ENTRY(51, m_RequestDepartment)
	COLUMN_ENTRY(52, m_RequestDepartmentAlias)
	COLUMN_ENTRY(53, m_RegisterDoctor)
	COLUMN_ENTRY(54, m_RegisterDoctorAlias)
	COLUMN_ENTRY(55, m_RegisterDate)
	COLUMN_ENTRY(56, m_RegisterTime)
	COLUMN_ENTRY(57, m_ExecuteTechnologies)
	COLUMN_ENTRY(58, m_ExecuteComments)
	COLUMN_ENTRY(59, m_AdmissionSourceHospital)
	COLUMN_ENTRY(60, m_RequestElectronic)
	COLUMN_ENTRY(61, m_RequestClinic)
	COLUMN_ENTRY(62, m_StudiesChargeStatus)
	COLUMN_ENTRY(63, m_StudiesChargeClassified)
	COLUMN_ENTRY(64, m_StudiesChargeFilms)
	COLUMN_ENTRY(65, m_ExecuteDeviceAlias)
	COLUMN_ENTRY(66, m_ExecuteDeviceModel)
	COLUMN_ENTRY(67, m_ExecuteDeviceHZ)
	COLUMN_ENTRY(68, m_ResultsIndex)
	COLUMN_ENTRY(69, m_ResultsReports)
	COLUMN_ENTRY(70, m_ResultsExamine)
	COLUMN_ENTRY(71, m_ResultsExamineAlias)
	COLUMN_ENTRY(72, m_ResultsBodiesCode)
	COLUMN_ENTRY(73, m_ResultsBodies)
	COLUMN_ENTRY(74, m_ResultsBodiesAlias)
	COLUMN_ENTRY(75, m_ResultsDate)
	COLUMN_ENTRY(76, m_ResultsTime)
	COLUMN_ENTRY(77, m_ResultsTemplate)
	COLUMN_ENTRY(78, m_ResultsOutDate)
	COLUMN_ENTRY(79, m_ResultsOutTime)
	COLUMN_ENTRY(80, m_ResultsComments)
	COLUMN_ENTRY(81, m_ReportsIndex)
	COLUMN_ENTRY(82, m_ReportsStatus)
	COLUMN_ENTRY(83, m_ReportsOutStatus)
	COLUMN_ENTRY(84, m_RecordsDoctor)
	COLUMN_ENTRY(85, m_RecordsDoctorAlias)
	COLUMN_ENTRY(86, m_RecordsDate)
	COLUMN_ENTRY(87, m_RecordsTime)
	COLUMN_ENTRY(88, m_ReportsDoctor)
	COLUMN_ENTRY(89, m_ReportsDoctorAlias)
	COLUMN_ENTRY(90, m_ReportsDate)
	COLUMN_ENTRY(91, m_ReportsTime)
	COLUMN_ENTRY(92, m_ApproveDoctor)
	COLUMN_ENTRY(93, m_ApproveDoctorAlias)
	COLUMN_ENTRY(94, m_ApproveDate)
	COLUMN_ENTRY(95, m_ApproveTime)
	COLUMN_ENTRY(96, m_ReportsConclusion)
	COLUMN_ENTRY(97, m_ReportsEvidences)
	COLUMN_ENTRY(98, m_ReportsTechnologies)
	COLUMN_ENTRY(99, m_ReportsComments)
	COLUMN_ENTRY(100, m_ServiceIndex)
	COLUMN_ENTRY(101, m_ServiceExamine)
	COLUMN_ENTRY(102, m_ServiceExamineAlias)
	COLUMN_ENTRY(103, m_ServiceExaminePrice)
	COLUMN_ENTRY(104, m_ServiceModalities)
	COLUMN_ENTRY(105, m_ServiceDevice)
	COLUMN_ENTRY(106, m_ServiceDeviceAlias)
	COLUMN_ENTRY(107, m_ServiceAETitle)
	COLUMN_ENTRY(108, m_ServiceBodiesCode)
	COLUMN_ENTRY(109, m_ServiceBodies)
	COLUMN_ENTRY(110, m_ServiceBodiesAlias)
	COLUMN_ENTRY(111, m_ServiceClassified)
	COLUMN_ENTRY(112, m_ExecuteDoctor)
	COLUMN_ENTRY(113, m_ExecuteDoctorAlias)
	COLUMN_ENTRY(114, m_ExecuteDate)
	COLUMN_ENTRY(115, m_ExecuteTime)
	COLUMN_ENTRY(116, m_ExecuteSeconds)
	COLUMN_ENTRY(117, m_ExecuteDevice)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovEISWorksServiceAccessor, _T(" \
SELECT \
PatientsIndex,\
PatientsName,\
PatientsAlias,\
PatientsID,\
PatientsIDAlias,\
PatientsSex,\
PatientsDOB,\
PatientsPhone,\
PatientsPostcode,\
PatientsAddress,\
PatientsCertificate,\
PatientsComments,\
PatientsProtective,\
PatientsOccupation,\
StudiesIndex,\
StudiesDepartment,\
StudiesAge,\
StudiesSize,\
StudiesWeight,\
AdmissionSource,\
AdmissionEmergencies,\
AdmissionID,\
AdmissionLocation,\
AccessionPrearrange,\
AccessionNumber,\
StudiesInstUID,\
StudiesStatus,\
StudiesSuspense,\
StudiesFilms,\
StudiesReviews,\
StudiesMasculine,\
StudiesKeenness,\
StudiesConsultation,\
StudiesLearn,\
StudiesDate,\
StudiesTime,\
StudiesDoneDate,\
StudiesDoneTime,\
StudiesExamine,\
StudiesExamineAlias,\
StudiesExaminePrice,\
StudiesBodiesCode,\
StudiesBodies,\
StudiesBodiesAlias,\
StudiesModalities,\
StudiesClassified,\
StudiesAETitle,\
RequestReason,\
RequestDoctor,\
RequestDoctorAlias,\
RequestDepartment,\
RequestDepartmentAlias,\
RegisterDoctor,\
RegisterDoctorAlias,\
RegisterDate,\
RegisterTime,\
ExecuteTechnologies,\
ExecuteComments,\
AdmissionSourceHospital,\
RequestElectronic,\
RequestClinic,\
StudiesChargeStatus,\
StudiesChargeClassified,\
StudiesChargeFilms,\
ExecuteDeviceAlias,\
ExecuteDeviceModel,\
ExecuteDeviceHZ,\
ResultsIndex,\
ResultsReports,\
ResultsExamine,\
ResultsExamineAlias,\
ResultsBodiesCode,\
ResultsBodies,\
ResultsBodiesAlias,\
ResultsDate,\
ResultsTime,\
ResultsTemplate,\
ResultsOutDate,\
ResultsOutTime,\
ResultsComments,\
ReportsIndex,\
ReportsStatus,\
ReportsOutStatus,\
RecordsDoctor,\
RecordsDoctorAlias,\
RecordsDate,\
RecordsTime,\
ReportsDoctor,\
ReportsDoctorAlias,\
ReportsDate,\
ReportsTime,\
ApproveDoctor,\
ApproveDoctorAlias,\
ApproveDate,\
ApproveTime,\
ReportsConclusion,\
ReportsEvidences,\
ReportsTechnologies,\
ReportsComments,\
ServiceIndex,\
ServiceExamine,\
ServiceExamineAlias,\
ServiceExaminePrice,\
ServiceModalities,\
ServiceDevice,\
ServiceDeviceAlias,\
ServiceAETitle,\
ServiceBodiesCode,\
ServiceBodies,\
ServiceBodiesAlias,\
ServiceClassified,\
ExecuteDoctor,\
ExecuteDoctorAlias,\
ExecuteDate,\
ExecuteTime,\
ExecuteSeconds,\
ExecuteDevice  \
FROM vEISWorksService"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVEISWORKSSERVICE_H_
