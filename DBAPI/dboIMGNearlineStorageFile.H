// dboIMGNearlineStorageFile.H : Declaration of the CdboIMGNearlineStorageFile class

#ifndef __DBOIMGNEARLINESTORAGEFILE_H_
#define __DBOIMGNEARLINESTORAGEFILE_H_

class CdboIMGNearlineStorageFileAccessor
{
public:
	LONG m_NLFileIndex;
	LONG m_NLFileStatus;
	TCHAR m_NLFileSource[101];
	TCHAR m_NLFileTarget[101];
	TCHAR m_NLFileTS[17];
	LONG m_NLFileTimes;
	LONG m_NLFileCode;
	TCHAR m_NLFileMessage[65];
	TCHAR m_NLFileReworkTS[17];

BEGIN_COLUMN_MAP(CdboIMGNearlineStorageFileAccessor)
	COLUMN_ENTRY(1, m_NLFileIndex)
	COLUMN_ENTRY(2, m_NLFileStatus)
	COLUMN_ENTRY(3, m_NLFileSource)
	COLUMN_ENTRY(4, m_NLFileTarget)
	COLUMN_ENTRY(5, m_NLFileTS)
	COLUMN_ENTRY(6, m_NLFileTimes)
	COLUMN_ENTRY(7, m_NLFileCode)
	COLUMN_ENTRY(8, m_NLFileMessage)
	COLUMN_ENTRY(9, m_NLFileReworkTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboIMGNearlineStorageFileAccessor, _T(" \
	SELECT \
		NLFileIndex, \
		NLFileStatus, \
		NLFileSource, \
		NLFileTarget, \
		NLFileTS, \
		NLFileTimes, \
		NLFileCode, \
		NLFileMessage, \
		NLFileReworkTS  \
		FROM IMGNearlineStorageFile"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOIMGNEARLINESTORAGEFILE_H_
