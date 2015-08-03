// dboMGRControl.H : Declaration of the CdboMGRControl class

#ifndef __DBOMGRCONTROL_H_
#define __DBOMGRCONTROL_H_

class CdboMGRControlAccessor
{
public:
	LONG m_ControlIndex;
	LONG m_ControlInside;
	LONG m_ControlCurrent;
	TCHAR m_ControlRemark[65];

BEGIN_COLUMN_MAP(CdboMGRControlAccessor)
	COLUMN_ENTRY(1, m_ControlIndex)
	COLUMN_ENTRY(2, m_ControlInside)
	COLUMN_ENTRY(3, m_ControlCurrent)
	COLUMN_ENTRY(4, m_ControlRemark)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRControlAccessor, _T(" \
	SELECT \
		ControlIndex, \
		ControlInside, \
		ControlCurrent, \
		ControlRemark  \
		FROM MGRControl"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRCONTROL_H_
