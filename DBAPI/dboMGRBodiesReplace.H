// dboMGRBodiesReplace.H : Declaration of the CdboMGRBodiesReplace class

#ifndef __DBOMGRBODIESREPLACE_H_
#define __DBOMGRBODIESREPLACE_H_

class CdboMGRBodiesReplaceAccessor
{
public:
	LONG m_ReplaceIndex;
	LONG m_ReplaceBodies;
	TCHAR m_ReplaceAETitle[65];
	TCHAR m_ReplaceProcedureID[65];
	TCHAR m_ReplaceProcedureDS[65];
	TCHAR m_ReplaceStepID[65];
	TCHAR m_ReplaceStepDS[65];
	TCHAR m_ReplaceReserved1[65];
	TCHAR m_ReplaceReserved2[65];
	TCHAR m_ReplaceReserved3[65];
	TCHAR m_ReplaceReserved4[65];

BEGIN_COLUMN_MAP(CdboMGRBodiesReplaceAccessor)
	COLUMN_ENTRY(1, m_ReplaceIndex)
	COLUMN_ENTRY(2, m_ReplaceBodies)
	COLUMN_ENTRY(3, m_ReplaceAETitle)
	COLUMN_ENTRY(4, m_ReplaceProcedureID)
	COLUMN_ENTRY(5, m_ReplaceProcedureDS)
	COLUMN_ENTRY(6, m_ReplaceStepID)
	COLUMN_ENTRY(7, m_ReplaceStepDS)
	COLUMN_ENTRY(8, m_ReplaceReserved1)
	COLUMN_ENTRY(9, m_ReplaceReserved2)
	COLUMN_ENTRY(10, m_ReplaceReserved3)
	COLUMN_ENTRY(11, m_ReplaceReserved4)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRBodiesReplaceAccessor, _T(" \
	SELECT \
		ReplaceIndex, \
		ReplaceBodies, \
		ReplaceAETitle, \
		ReplaceProcedureID, \
		ReplaceProcedureDS, \
		ReplaceStepID, \
		ReplaceStepDS, \
		ReplaceReserved1, \
		ReplaceReserved2, \
		ReplaceReserved3, \
		ReplaceReserved4  \
		FROM MGRBodiesReplace"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRBODIESREPLACE_H_
