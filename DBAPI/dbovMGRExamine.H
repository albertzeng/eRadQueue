// dbovMGRExamine.H : Declaration of the CdbovMGRExamine class

#ifndef __DBOVMGREXAMINE_H_
#define __DBOVMGREXAMINE_H_

class CdbovMGRExamineAccessor
{
public:
	LONG m_ExamineIndex;
	LONG m_ExamineDepartment;
	TCHAR m_ExamineCode[65];
	TCHAR m_ExamineSpell[17];
	TCHAR m_ExamineName[65];
	TCHAR m_ExamineAlias[65];
	TCHAR m_ExamineModalities[17];
	LONG m_ExamineDevice;
	LONG m_ExamineBodies;
	TCHAR m_ExamineClassified[65];
	TCHAR m_ExamineSpecs[65];
	TCHAR m_ExamineSpecsAlias[65];
	LONG m_ExamineTemplate;
	TCHAR m_ExamineTemplateAlias[65];
	double m_ExamineExecute;
	double m_ExamineReports;
	double m_ExaminePrice;
	TCHAR m_ExamineRemark[513];
	TCHAR m_ExamineTemplateRelative[201];
	TCHAR m_BodiesCode[65];
	TCHAR m_BodiesSpell[17];
	TCHAR m_BodiesName[65];
	TCHAR m_BodiesAlias[65];
	TCHAR m_BodiesRemark[65];
	TCHAR m_DeviceCode[65];
	TCHAR m_DeviceSpell[17];
	TCHAR m_DeviceName[65];
	TCHAR m_DeviceAlias[65];
	TCHAR m_DeviceModalities[17];
	TCHAR m_DeviceAETitle[17];
	TCHAR m_DeviceRemark[65];

BEGIN_COLUMN_MAP(CdbovMGRExamineAccessor)
	COLUMN_ENTRY(1, m_ExamineIndex)
	COLUMN_ENTRY(2, m_ExamineDepartment)
	COLUMN_ENTRY(3, m_ExamineCode)
	COLUMN_ENTRY(4, m_ExamineSpell)
	COLUMN_ENTRY(5, m_ExamineName)
	COLUMN_ENTRY(6, m_ExamineAlias)
	COLUMN_ENTRY(7, m_ExamineModalities)
	COLUMN_ENTRY(8, m_ExamineDevice)
	COLUMN_ENTRY(9, m_ExamineBodies)
	COLUMN_ENTRY(10, m_ExamineClassified)
	COLUMN_ENTRY(11, m_ExamineSpecs)
	COLUMN_ENTRY(12, m_ExamineSpecsAlias)
	COLUMN_ENTRY(13, m_ExamineTemplate)
	COLUMN_ENTRY(14, m_ExamineTemplateAlias)
	COLUMN_ENTRY(15, m_ExamineExecute)
	COLUMN_ENTRY(16, m_ExamineReports)
	COLUMN_ENTRY(17, m_ExaminePrice)
	COLUMN_ENTRY(18, m_ExamineRemark)
	COLUMN_ENTRY(19, m_ExamineTemplateRelative)
	COLUMN_ENTRY(20, m_BodiesCode)
	COLUMN_ENTRY(21, m_BodiesSpell)
	COLUMN_ENTRY(22, m_BodiesName)
	COLUMN_ENTRY(23, m_BodiesAlias)
	COLUMN_ENTRY(24, m_BodiesRemark)
	COLUMN_ENTRY(25, m_DeviceCode)
	COLUMN_ENTRY(26, m_DeviceSpell)
	COLUMN_ENTRY(27, m_DeviceName)
	COLUMN_ENTRY(28, m_DeviceAlias)
	COLUMN_ENTRY(29, m_DeviceModalities)
	COLUMN_ENTRY(30, m_DeviceAETitle)
	COLUMN_ENTRY(31, m_DeviceRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovMGRExamineAccessor, _T(" \
	SELECT \
		ExamineIndex, \
		ExamineDepartment, \
		ExamineCode, \
		ExamineSpell, \
		ExamineName, \
		ExamineAlias, \
		ExamineModalities, \
		ExamineDevice, \
		ExamineBodies, \
		ExamineClassified, \
		ExamineSpecs, \
		ExamineSpecsAlias, \
		ExamineTemplate, \
		ExamineTemplateAlias, \
		ExamineExecute, \
		ExamineReports, \
		ExaminePrice, \
		ExamineRemark, \
		ExamineTemplateRelative, \
		BodiesCode, \
		BodiesSpell, \
		BodiesName, \
		BodiesAlias, \
		BodiesRemark, \
		DeviceCode, \
		DeviceSpell, \
		DeviceName, \
		DeviceAlias, \
		DeviceModalities, \
		DeviceAETitle, \
		DeviceRemark  \
		FROM vMGRExamine"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVMGREXAMINE_H_
