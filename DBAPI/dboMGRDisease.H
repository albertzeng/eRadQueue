// dboMGRDisease.H : Declaration of the CdboMGRDisease class

#ifndef __DBOMGRDISEASE_H_
#define __DBOMGRDISEASE_H_

class CdboMGRDiseaseAccessor
{
public:
	LONG m_DiseaseIndex;
	LONG m_DiseaseDepartment;
	LONG m_DiseaseKinds;
	LONG m_DiseaseParent;
	LONG m_DiseaseOrder;
	TCHAR m_DiseaseCode[65];
	TCHAR m_DiseaseName[257];
	TCHAR m_DiseaseAlias[257];

BEGIN_COLUMN_MAP(CdboMGRDiseaseAccessor)
	COLUMN_ENTRY(1, m_DiseaseIndex)
	COLUMN_ENTRY(2, m_DiseaseDepartment)
	COLUMN_ENTRY(3, m_DiseaseKinds)
	COLUMN_ENTRY(4, m_DiseaseParent)
	COLUMN_ENTRY(5, m_DiseaseOrder)
	COLUMN_ENTRY(6, m_DiseaseCode)
	COLUMN_ENTRY(7, m_DiseaseName)
	COLUMN_ENTRY(8, m_DiseaseAlias)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRDiseaseAccessor, _T(" \
	SELECT \
		DiseaseIndex, \
		DiseaseDepartment, \
		DiseaseKinds, \
		DiseaseParent, \
		DiseaseOrder, \
		DiseaseCode, \
		DiseaseName, \
		DiseaseAlias  \
		FROM MGRDisease"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRDISEASE_H_
