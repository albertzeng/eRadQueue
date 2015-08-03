// dboEISStudiesConsultation.H : Declaration of the CdboEISStudiesConsultation class

#ifndef __DBOEISSTUDIESCONSULTATION_H_
#define __DBOEISSTUDIESCONSULTATION_H_

class CdboEISStudiesConsultationAccessor
{
public:
	LONG m_ConsultationStudies;
	TCHAR m_ConsultationDate[9];
	TCHAR m_ConsultationTime[7];
	TCHAR m_ConsultationDoctor[201];
	TCHAR m_ConsultationDoctorAlias[201];
	LONG m_ConsultationAnnexIndex;
	LONG m_ConsultationRecordDoctor;
	TCHAR m_ConsultationRecordDoctorAlias[65];
	TCHAR m_ConsultationRecord[4001];
	TCHAR m_ConsultationConclusion[1025];

BEGIN_COLUMN_MAP(CdboEISStudiesConsultationAccessor)
	COLUMN_ENTRY(1, m_ConsultationStudies)
	COLUMN_ENTRY(2, m_ConsultationDate)
	COLUMN_ENTRY(3, m_ConsultationTime)
	COLUMN_ENTRY(4, m_ConsultationDoctor)
	COLUMN_ENTRY(5, m_ConsultationDoctorAlias)
	COLUMN_ENTRY(6, m_ConsultationAnnexIndex)
	COLUMN_ENTRY(7, m_ConsultationRecordDoctor)
	COLUMN_ENTRY(8, m_ConsultationRecordDoctorAlias)
	COLUMN_ENTRY(9, m_ConsultationRecord)
	COLUMN_ENTRY(10, m_ConsultationConclusion)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISStudiesConsultationAccessor, _T(" \
	SELECT \
		ConsultationStudies, \
		ConsultationDate, \
		ConsultationTime, \
		ConsultationDoctor, \
		ConsultationDoctorAlias, \
		ConsultationAnnexIndex, \
		ConsultationRecordDoctor, \
		ConsultationRecordDoctorAlias, \
		ConsultationRecord, \
		ConsultationConclusion  \
		FROM EISStudiesConsultation"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISSTUDIESCONSULTATION_H_
