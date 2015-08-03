// dboFPAssociation.H : Declaration of the CdboFPAssociation class

#ifndef __DBOFPASSOCIATION_H_
#define __DBOFPASSOCIATION_H_

class CdboFPAssociationAccessor
{
public:
	LONG m_AssociationIndex;
	LONG m_AssociationPRINT;
	TCHAR m_AssociationCalledAE[17];
	TCHAR m_AssociationSourceAE[17];
	TCHAR m_AssociationSourceIP[17];
	LONG m_AssociationFlags;
	TCHAR m_AssociationTS[17];

BEGIN_COLUMN_MAP(CdboFPAssociationAccessor)
	COLUMN_ENTRY(1, m_AssociationIndex)
	COLUMN_ENTRY(2, m_AssociationPRINT)
	COLUMN_ENTRY(3, m_AssociationCalledAE)
	COLUMN_ENTRY(4, m_AssociationSourceAE)
	COLUMN_ENTRY(5, m_AssociationSourceIP)
	COLUMN_ENTRY(6, m_AssociationFlags)
	COLUMN_ENTRY(7, m_AssociationTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboFPAssociationAccessor, _T(" \
	SELECT \
		AssociationIndex, \
		AssociationPRINT, \
		AssociationCalledAE, \
		AssociationSourceAE, \
		AssociationSourceIP, \
		AssociationFlags, \
		AssociationTS  \
		FROM FPAssociation"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOFPASSOCIATION_H_
