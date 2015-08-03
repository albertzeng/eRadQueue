// dboEISStudiesReviews.H : Declaration of the CdboEISStudiesReviews class

#ifndef __DBOEISSTUDIESREVIEWS_H_
#define __DBOEISSTUDIESREVIEWS_H_

class CdboEISStudiesReviewsAccessor
{
public:
	LONG m_SRStudies;
	LONG m_SRDoctor;
	TCHAR m_SRDoctorAlias[65];
	TCHAR m_SRDate[9];
	TCHAR m_SRTime[7];
	LONG m_SRRight;
	TCHAR m_SRSource[201];
	TCHAR m_SRClinical[1025];
	TCHAR m_SRPathologic[1025];
	TCHAR m_SRComments[4001];

BEGIN_COLUMN_MAP(CdboEISStudiesReviewsAccessor)
	COLUMN_ENTRY(1, m_SRStudies)
	COLUMN_ENTRY(2, m_SRDoctor)
	COLUMN_ENTRY(3, m_SRDoctorAlias)
	COLUMN_ENTRY(4, m_SRDate)
	COLUMN_ENTRY(5, m_SRTime)
	COLUMN_ENTRY(6, m_SRRight)
	COLUMN_ENTRY(7, m_SRSource)
	COLUMN_ENTRY(8, m_SRClinical)
	COLUMN_ENTRY(9, m_SRPathologic)
	COLUMN_ENTRY(10, m_SRComments)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISStudiesReviewsAccessor, _T(" \
	SELECT \
		SRStudies, \
		SRDoctor, \
		SRDoctorAlias, \
		SRDate, \
		SRTime, \
		SRRight, \
		SRSource, \
		SRClinical, \
		SRPathologic, \
		SRComments  \
		FROM EISStudiesReviews"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISSTUDIESREVIEWS_H_
