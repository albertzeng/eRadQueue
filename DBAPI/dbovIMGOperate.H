// dbovIMGOperate.H : Declaration of the CdbovIMGOperate class

#ifndef __DBOVIMGOPERATE_H_
#define __DBOVIMGOPERATE_H_

class CdbovIMGOperateAccessor
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
	LONG m_PatientsIndex;
	TCHAR m_PatientsName[65];
	TCHAR m_PatientsAlias[65];
	TCHAR m_PatientsID[65];
	TCHAR m_PatientsDOB[17];
	TCHAR m_PatientsSex[17];
	LONG m_PatientsStudies;
	LONG m_PatientsSeries;
	LONG m_PatientsImages;
	LONG m_PatientsFlags;
	TCHAR m_PatientsTS[17];
	TCHAR m_PatientsSourceAE[17];
	LONG m_StudiesIndex;
	TCHAR m_StudiesInstUID[65];
	TCHAR m_StudiesDate[17];
	TCHAR m_StudiesTime[17];
	TCHAR m_AccessionNumber[65];
	TCHAR m_StudiesDescription[65];
	TCHAR m_StudiesID[17];
	LONG m_StudiesSeries;
	LONG m_StudiesImages;
	LONG m_StudiesAvailable;
	LONG m_StudiesArchive;
	LONG m_StorageHostsIndex;
	LONG m_StorageState;
	LONG m_StudiesDVDIndex;
	TCHAR m_StudiesFileSetID[17];
	TCHAR m_StudiesFileSetUID[65];
	LONG m_StudiesFlags;
	TCHAR m_StudiesTS[17];
	TCHAR m_StudiesTargetAE[101];

BEGIN_COLUMN_MAP(CdbovIMGOperateAccessor)
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
	COLUMN_ENTRY(12, m_PatientsIndex)
	COLUMN_ENTRY(13, m_PatientsName)
	COLUMN_ENTRY(14, m_PatientsAlias)
	COLUMN_ENTRY(15, m_PatientsID)
	COLUMN_ENTRY(16, m_PatientsDOB)
	COLUMN_ENTRY(17, m_PatientsSex)
	COLUMN_ENTRY(18, m_PatientsStudies)
	COLUMN_ENTRY(19, m_PatientsSeries)
	COLUMN_ENTRY(20, m_PatientsImages)
	COLUMN_ENTRY(21, m_PatientsFlags)
	COLUMN_ENTRY(22, m_PatientsTS)
	COLUMN_ENTRY(23, m_PatientsSourceAE)
	COLUMN_ENTRY(24, m_StudiesIndex)
	COLUMN_ENTRY(25, m_StudiesInstUID)
	COLUMN_ENTRY(26, m_StudiesDate)
	COLUMN_ENTRY(27, m_StudiesTime)
	COLUMN_ENTRY(28, m_AccessionNumber)
	COLUMN_ENTRY(29, m_StudiesDescription)
	COLUMN_ENTRY(30, m_StudiesID)
	COLUMN_ENTRY(31, m_StudiesSeries)
	COLUMN_ENTRY(32, m_StudiesImages)
	COLUMN_ENTRY(33, m_StudiesAvailable)
	COLUMN_ENTRY(34, m_StudiesArchive)
	COLUMN_ENTRY(35, m_StorageHostsIndex)
	COLUMN_ENTRY(36, m_StorageState)
	COLUMN_ENTRY(37, m_StudiesDVDIndex)
	COLUMN_ENTRY(38, m_StudiesFileSetID)
	COLUMN_ENTRY(39, m_StudiesFileSetUID)
	COLUMN_ENTRY(40, m_StudiesFlags)
	COLUMN_ENTRY(41, m_StudiesTS)
	COLUMN_ENTRY(42, m_StudiesTargetAE)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovIMGOperateAccessor, _T(" \
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
		OperateTransactionUID, \
		PatientsIndex, \
		PatientsName, \
		PatientsAlias, \
		PatientsID, \
		PatientsDOB, \
		PatientsSex, \
		PatientsStudies, \
		PatientsSeries, \
		PatientsImages, \
		PatientsFlags, \
		PatientsTS, \
		PatientsSourceAE, \
		StudiesIndex, \
		StudiesInstUID, \
		StudiesDate, \
		StudiesTime, \
		AccessionNumber, \
		StudiesDescription, \
		StudiesID, \
		StudiesSeries, \
		StudiesImages, \
		StudiesAvailable, \
		StudiesArchive, \
		StorageHostsIndex, \
		StorageState, \
		StudiesDVDIndex, \
		StudiesFileSetID, \
		StudiesFileSetUID, \
		StudiesFlags, \
		StudiesTS, \
		StudiesTargetAE  \
		FROM vIMGOperate"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVIMGOPERATE_H_
