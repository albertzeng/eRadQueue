// dboMGRTemplate.H : Declaration of the CdboMGRTemplate class

#ifndef __DBOMGRTEMPLATE_H_
#define __DBOMGRTEMPLATE_H_

class CdboMGRTemplateAccessor
{
public:
	LONG m_TemplateIndex;
	LONG m_TemplateDepartment;
	LONG m_TemplateDoctor;
	LONG m_TemplateKinds;
	LONG m_TemplateParent;
	LONG m_TemplateOrder;
	TCHAR m_TemplateCode[65];
	TCHAR m_TemplateName[65];
	TCHAR m_TemplateRemark[65];
	TCHAR m_TemplateTechnologies[20480];
	TCHAR m_TemplateEvidences[20480];
	TCHAR m_TemplateConclusion[20480];

BEGIN_COLUMN_MAP(CdboMGRTemplateAccessor)
	COLUMN_ENTRY(1, m_TemplateIndex)
	COLUMN_ENTRY(2, m_TemplateDepartment)
	COLUMN_ENTRY(3, m_TemplateDoctor)
	COLUMN_ENTRY(4, m_TemplateKinds)
	COLUMN_ENTRY(5, m_TemplateParent)
	COLUMN_ENTRY(6, m_TemplateOrder)
	COLUMN_ENTRY(7, m_TemplateCode)
	COLUMN_ENTRY(8, m_TemplateName)
	COLUMN_ENTRY(9, m_TemplateRemark)
	COLUMN_ENTRY(10, m_TemplateTechnologies)
	COLUMN_ENTRY(11, m_TemplateEvidences)
	COLUMN_ENTRY(12, m_TemplateConclusion)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRTemplateAccessor, _T(" \
	SELECT \
		TemplateIndex, \
		TemplateDepartment, \
		TemplateDoctor, \
		TemplateKinds, \
		TemplateParent, \
		TemplateOrder, \
		TemplateCode, \
		TemplateName, \
		TemplateRemark, \
		TemplateTechnologies, \
		TemplateEvidences, \
		TemplateConclusion  \
		FROM MGRTemplate"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRTEMPLATE_H_
