// dboMGRPhrase.H : Declaration of the CdboMGRPhrase class

#ifndef __DBOMGRPHRASE_H_
#define __DBOMGRPHRASE_H_

class CdboMGRPhraseAccessor
{
public:
	LONG m_PhraseIndex;
	LONG m_PhraseDepartment;
	LONG m_PhraseDoctor;
	LONG m_PhraseKinds;
	LONG m_PhraseOrder;
	LONG m_PhraseMaster;
	TCHAR m_PhraseGather[65];
	TCHAR m_PhraseContent[257];

BEGIN_COLUMN_MAP(CdboMGRPhraseAccessor)
	COLUMN_ENTRY(1, m_PhraseIndex)
	COLUMN_ENTRY(2, m_PhraseDepartment)
	COLUMN_ENTRY(3, m_PhraseDoctor)
	COLUMN_ENTRY(4, m_PhraseKinds)
	COLUMN_ENTRY(5, m_PhraseOrder)
	COLUMN_ENTRY(6, m_PhraseMaster)
	COLUMN_ENTRY(7, m_PhraseGather)
	COLUMN_ENTRY(8, m_PhraseContent)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRPhraseAccessor, _T(" \
	SELECT \
		PhraseIndex, \
		PhraseDepartment, \
		PhraseDoctor, \
		PhraseKinds, \
		PhraseOrder, \
		PhraseMaster, \
		PhraseGather, \
		PhraseContent  \
		FROM MGRPhrase"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRPHRASE_H_
