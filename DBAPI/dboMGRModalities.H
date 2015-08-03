// dboMGRModalities.H : Declaration of the CdboMGRModalities class

#ifndef __DBOMGRMODALITIES_H_
#define __DBOMGRMODALITIES_H_

class CdboMGRModalitiesAccessor
{
public:
	LONG m_ModalitiesIndex;
	TCHAR m_ModalitiesName[17];
	TCHAR m_ModalitiesRemark[65];
	LONG m_ModalitiesDepartment;

BEGIN_COLUMN_MAP(CdboMGRModalitiesAccessor)
	COLUMN_ENTRY(1, m_ModalitiesIndex)
	COLUMN_ENTRY(2, m_ModalitiesName)
	COLUMN_ENTRY(3, m_ModalitiesRemark)
	COLUMN_ENTRY(4, m_ModalitiesDepartment)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRModalitiesAccessor, _T(" \
	SELECT \
		ModalitiesIndex, \
		ModalitiesName, \
		ModalitiesRemark, \
		ModalitiesDepartment  \
		FROM MGRModalities"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRMODALITIES_H_
