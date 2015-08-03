// dboMGRTemplateDisease.H : Declaration of the CdboMGRTemplateDisease class

#ifndef __DBOMGRTEMPLATEDISEASE_H_
#define __DBOMGRTEMPLATEDISEASE_H_

class CdboMGRTemplateDiseaseAccessor
{
public:
	LONG m_TDTemplate;
	LONG m_TDDisease;

BEGIN_COLUMN_MAP(CdboMGRTemplateDiseaseAccessor)
	COLUMN_ENTRY(1, m_TDTemplate)
	COLUMN_ENTRY(2, m_TDDisease)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRTemplateDiseaseAccessor, _T(" \
	SELECT \
		TDTemplate, \
		TDDisease  \
		FROM MGRTemplateDisease"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRTEMPLATEDISEASE_H_
