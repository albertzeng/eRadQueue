// dboEISMessage.H : Declaration of the CdboEISMessage class

#ifndef __DBOEISMESSAGE_H_
#define __DBOEISMESSAGE_H_

class CdboEISMessageAccessor
{
public:
	LONG m_MessageIndex;
	LONG m_MessageDepartment;
	LONG m_MessageDoctor;
	TCHAR m_MessageDoctorAlias[65];
	LONG m_MessageNodeKinds;
	TCHAR m_MessageIPAddress[65];
	LONG m_MessageRecvDoctor;
	TCHAR m_MessageRecvDoctorAlias[65];
	LONG m_MessageRecvNodeKinds;
	LONG m_MessageStudies;
	LONG m_MessageLevel;
	TCHAR m_MessageClassified[65];
	TCHAR m_MessageContent[513];
	TCHAR m_MessageTS[17];

BEGIN_COLUMN_MAP(CdboEISMessageAccessor)
	COLUMN_ENTRY(1, m_MessageIndex)
	COLUMN_ENTRY(2, m_MessageDepartment)
	COLUMN_ENTRY(3, m_MessageDoctor)
	COLUMN_ENTRY(4, m_MessageDoctorAlias)
	COLUMN_ENTRY(5, m_MessageNodeKinds)
	COLUMN_ENTRY(6, m_MessageIPAddress)
	COLUMN_ENTRY(7, m_MessageRecvDoctor)
	COLUMN_ENTRY(8, m_MessageRecvDoctorAlias)
	COLUMN_ENTRY(9, m_MessageRecvNodeKinds)
	COLUMN_ENTRY(10, m_MessageStudies)
	COLUMN_ENTRY(11, m_MessageLevel)
	COLUMN_ENTRY(12, m_MessageClassified)
	COLUMN_ENTRY(13, m_MessageContent)
	COLUMN_ENTRY(14, m_MessageTS)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboEISMessageAccessor, _T(" \
	SELECT \
		MessageIndex, \
		MessageDepartment, \
		MessageDoctor, \
		MessageDoctorAlias, \
		MessageNodeKinds, \
		MessageIPAddress, \
		MessageRecvDoctor, \
		MessageRecvDoctorAlias, \
		MessageRecvNodeKinds, \
		MessageStudies, \
		MessageLevel, \
		MessageClassified, \
		MessageContent, \
		MessageTS  \
		FROM EISMessage"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOEISMESSAGE_H_
