// dboFPServices.H : Declaration of the CdboFPServices class

#ifndef __DBOFPSERVICES_H_
#define __DBOFPSERVICES_H_

class CdboFPServicesAccessor
{
public:
	LONG m_ServicesIndex;
	LONG m_ServicesAssociation;
	LONG m_ServicesFilmSession;
	LONG m_ServicesCommandField;
	TCHAR m_ServicesSOPInstUID[65];
	TCHAR m_ServicesSOPClassUID[65];
	LONG m_ServicesID;
	LONG m_ServicesDataSet;
	LONG m_ServicesAnnexIndex;
	LONG m_ServicesFlags;
	TCHAR m_ServicesTS[17];

BEGIN_COLUMN_MAP(CdboFPServicesAccessor)
	COLUMN_ENTRY(1, m_ServicesIndex)
	COLUMN_ENTRY(2, m_ServicesAssociation)
	COLUMN_ENTRY(3, m_ServicesFilmSession)
	COLUMN_ENTRY(4, m_ServicesCommandField)
	COLUMN_ENTRY(5, m_ServicesSOPInstUID)
	COLUMN_ENTRY(6, m_ServicesSOPClassUID)
	COLUMN_ENTRY(7, m_ServicesID)
	COLUMN_ENTRY(8, m_ServicesDataSet)
	COLUMN_ENTRY(9, m_ServicesAnnexIndex)
	COLUMN_ENTRY(10, m_ServicesFlags)
	COLUMN_ENTRY(11, m_ServicesTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboFPServicesAccessor, _T(" \
	SELECT \
		ServicesIndex, \
		ServicesAssociation, \
		ServicesFilmSession, \
		ServicesCommandField, \
		ServicesSOPInstUID, \
		ServicesSOPClassUID, \
		ServicesID, \
		ServicesDataSet, \
		ServicesAnnexIndex, \
		ServicesFlags, \
		ServicesTS  \
		FROM FPServices"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOFPSERVICES_H_
