// dboIMGNearlineStorage.H : Declaration of the CdboIMGNearlineStorage class

#ifndef __DBOIMGNEARLINESTORAGE_H_
#define __DBOIMGNEARLINESTORAGE_H_

class CdboIMGNearlineStorageAccessor
{
public:
	LONG m_NLStorageIndex;
	LONG m_NLStorageStatus;
	LONG m_NLStorageYM;
	TCHAR m_NLStorageSource[65];
	TCHAR m_NLStorageTarget[65];
	TCHAR m_NLStorageTS[17];

BEGIN_COLUMN_MAP(CdboIMGNearlineStorageAccessor)
	COLUMN_ENTRY(1, m_NLStorageIndex)
	COLUMN_ENTRY(2, m_NLStorageStatus)
	COLUMN_ENTRY(3, m_NLStorageYM)
	COLUMN_ENTRY(4, m_NLStorageSource)
	COLUMN_ENTRY(5, m_NLStorageTarget)
	COLUMN_ENTRY(6, m_NLStorageTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboIMGNearlineStorageAccessor, _T(" \
	SELECT \
		NLStorageIndex, \
		NLStorageStatus, \
		NLStorageYM, \
		NLStorageSource, \
		NLStorageTarget, \
		NLStorageTS  \
		FROM IMGNearlineStorage"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOIMGNEARLINESTORAGE_H_
