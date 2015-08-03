// dboEISFavoriteStudies.H : Declaration of the CdboEISFavoriteStudies class

#ifndef __DBOEISFAVORITESTUDIES_H_
#define __DBOEISFAVORITESTUDIES_H_

class CdboEISFavoriteStudiesAccessor
{
public:
	LONG m_FSIndex;
	LONG m_FSFavorite;
	LONG m_FSStudies;
	TCHAR m_FSRemark[65];

BEGIN_COLUMN_MAP(CdboEISFavoriteStudiesAccessor)
	COLUMN_ENTRY(1, m_FSIndex)
	COLUMN_ENTRY(2, m_FSFavorite)
	COLUMN_ENTRY(3, m_FSStudies)
	COLUMN_ENTRY(4, m_FSRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISFavoriteStudiesAccessor, _T(" \
	SELECT \
		FSIndex, \
		FSFavorite, \
		FSStudies, \
		FSRemark  \
		FROM EISFavoriteStudies"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISFAVORITESTUDIES_H_
