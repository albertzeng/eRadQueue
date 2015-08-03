// dbovMGRBodiesReplace.H : Declaration of the CdbovMGRBodiesReplace class

#ifndef __DBOVMGRBODIESREPLACE_H_
#define __DBOVMGRBODIESREPLACE_H_

class CdbovMGRBodiesReplaceAccessor
{
public:
	LONG m_BodiesIndex;
	LONG m_BodiesDepartment;
	TCHAR m_BodiesCode[65];
	TCHAR m_BodiesSpell[17];
	TCHAR m_BodiesName[65];
	TCHAR m_BodiesAlias[65];
	TCHAR m_BodiesRemark[65];
	LONG m_ReplaceIndex;
	TCHAR m_ReplaceAETitle[65];
	TCHAR m_ReplaceProcedureID[65];
	TCHAR m_ReplaceProcedureDS[65];
	TCHAR m_ReplaceStepID[65];
	TCHAR m_ReplaceStepDS[65];
	TCHAR m_ReplaceReserved1[65];
	TCHAR m_ReplaceReserved2[65];
	TCHAR m_ReplaceReserved3[65];
	TCHAR m_ReplaceReserved4[65];

BEGIN_COLUMN_MAP(CdbovMGRBodiesReplaceAccessor)
	COLUMN_ENTRY(1, m_BodiesIndex)
	COLUMN_ENTRY(2, m_BodiesDepartment)
	COLUMN_ENTRY(3, m_BodiesCode)
	COLUMN_ENTRY(4, m_BodiesSpell)
	COLUMN_ENTRY(5, m_BodiesName)
	COLUMN_ENTRY(6, m_BodiesAlias)
	COLUMN_ENTRY(7, m_BodiesRemark)
	COLUMN_ENTRY(8, m_ReplaceIndex)
	COLUMN_ENTRY(9, m_ReplaceAETitle)
	COLUMN_ENTRY(10, m_ReplaceProcedureID)
	COLUMN_ENTRY(11, m_ReplaceProcedureDS)
	COLUMN_ENTRY(12, m_ReplaceStepID)
	COLUMN_ENTRY(13, m_ReplaceStepDS)
	COLUMN_ENTRY(14, m_ReplaceReserved1)
	COLUMN_ENTRY(15, m_ReplaceReserved2)
	COLUMN_ENTRY(16, m_ReplaceReserved3)
	COLUMN_ENTRY(17, m_ReplaceReserved4)
END_COLUMN_MAP()

DEFINE_COMMAND(CdbovMGRBodiesReplaceAccessor, _T(" \
	SELECT \
		BodiesIndex, \
		BodiesDepartment, \
		BodiesCode, \
		BodiesSpell, \
		BodiesName, \
		BodiesAlias, \
		BodiesRemark, \
		ReplaceIndex, \
		ReplaceAETitle, \
		ReplaceProcedureID, \
		ReplaceProcedureDS, \
		ReplaceStepID, \
		ReplaceStepDS, \
		ReplaceReserved1, \
		ReplaceReserved2, \
		ReplaceReserved3, \
		ReplaceReserved4  \
		FROM vMGRBodiesReplace"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOVMGRBODIESREPLACE_H_
