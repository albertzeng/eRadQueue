// dboMGRDevice.H : Declaration of the CdboMGRDevice class

#ifndef __DBOMGRDEVICE_H_
#define __DBOMGRDEVICE_H_

class CdboMGRDeviceAccessor
{
public:
	LONG m_DeviceIndex;
	LONG m_DeviceDepartment;
	TCHAR m_DeviceCode[65];
	TCHAR m_DeviceSpell[17];
	TCHAR m_DeviceName[65];
	TCHAR m_DeviceAlias[65];
	TCHAR m_DeviceModalities[17];
	TCHAR m_DeviceAETitle[17];
	TCHAR m_DeviceRemark[65];
	LONG m_DeviceFlags;

BEGIN_COLUMN_MAP(CdboMGRDeviceAccessor)
	COLUMN_ENTRY(1, m_DeviceIndex)
	COLUMN_ENTRY(2, m_DeviceDepartment)
	COLUMN_ENTRY(3, m_DeviceCode)
	COLUMN_ENTRY(4, m_DeviceSpell)
	COLUMN_ENTRY(5, m_DeviceName)
	COLUMN_ENTRY(6, m_DeviceAlias)
	COLUMN_ENTRY(7, m_DeviceModalities)
	COLUMN_ENTRY(8, m_DeviceAETitle)
	COLUMN_ENTRY(9, m_DeviceRemark)
	COLUMN_ENTRY(10, m_DeviceFlags)
END_COLUMN_MAP()

DEFINE_COMMAND(CdboMGRDeviceAccessor, _T(" \
	SELECT \
		DeviceIndex, \
		DeviceDepartment, \
		DeviceCode, \
		DeviceSpell, \
		DeviceName, \
		DeviceAlias, \
		DeviceModalities, \
		DeviceAETitle, \
		DeviceRemark, \
		DeviceFlags  \
		FROM MGRDevice"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // __DBOMGRDEVICE_H_
