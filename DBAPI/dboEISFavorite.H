// dboEISFavorite.H : Declaration of the CdboEISFavorite class

#ifndef __DBOEISFAVORITE_H_
#define __DBOEISFAVORITE_H_

class CdboEISFavoriteAccessor
{
public:
	LONG m_FavoriteIndex;
	LONG m_FavoriteDoctor;
	LONG m_FavoriteParent;
	LONG m_FavoriteOrder;
	TCHAR m_FavoriteName[65];
	TCHAR m_FavoriteRemark[65];

BEGIN_COLUMN_MAP(CdboEISFavoriteAccessor)
	COLUMN_ENTRY(1, m_FavoriteIndex)
	COLUMN_ENTRY(2, m_FavoriteDoctor)
	COLUMN_ENTRY(3, m_FavoriteParent)
	COLUMN_ENTRY(4, m_FavoriteOrder)
	COLUMN_ENTRY(5, m_FavoriteName)
	COLUMN_ENTRY(6, m_FavoriteRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISFavoriteAccessor, _T(" \
	SELECT \
		FavoriteIndex, \
		FavoriteDoctor, \
		FavoriteParent, \
		FavoriteOrder, \
		FavoriteName, \
		FavoriteRemark  \
		FROM EISFavorite"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISFAVORITE_H_
