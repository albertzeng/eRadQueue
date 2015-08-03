// AttributeVR.h: interface for the CAttributeVR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATTRIBUTEVR_H__BCFD9E0A_F03B_4538_9DE9_D0E6DB42B649__INCLUDED_)
#define AFX_ATTRIBUTEVR_H__BCFD9E0A_F03B_4538_9DE9_D0E6DB42B649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum E_VR
{
	EVR_AE,				// Application Entity		16 bytes maximum
	EVR_AS,				// Age String				 4 bytes
	EVR_AT,				// Attribute Tag			 4 bytes
	EVR_CS,				// Code String				16 bytes maximum
	EVR_DA,				// Date						 8 bytes
	EVR_DS,				// Decimal String			16 bytes maximum
	EVR_DT,				// Date Time				26 bytes maximum
	EVR_FL,				// Floating Point Single	 4 bytes
	EVR_FD,				// Floating Point Double	 8 bytes
	EVR_IS,				// Integer String			12 bytes maximum
	EVR_LO,				// Long String				64 chars maximum
	EVR_LT,				// Long Text			 10240 chars maximum
	EVR_OB,				// Other Byte String
	EVR_OF,				// Other Float String
	EVR_OW,				// Other Word String
	EVR_PN,				// Person Name				64 chars maximum
	EVR_SH,				// Short String				16 bytes maximum
	EVR_SL,				// Signed Long				 4 bytes
	EVR_SQ,				// Sequence of Items
	EVR_SS,				// Signed Short				 2 bytes
	EVR_ST,				// Short Text			  1024 chars maximum
	EVR_TM,				// Time						16 bytes maximum
	EVR_UI,				// Unique Identifier (UID)	64 bytes maximum
	EVR_UL,				// Unsigned Long			 4 bytes
	EVR_UN,				// Unknown
	EVR_US,				// Unsigned Short			 2 bytes
	EVR_UT,				// Unlimited Text

	EVR_ox,				// OB or OW
	EVR_xs,				// SS or US
	EVR_na,				// Not Applicable

	EVR_ITEM,			// Used internally
	EVR_FILE_META,		// Used internally
	EVR_FILE_DATA,		// Used internally
	EVR_FILE_DICOMDIR,	// Used internally

	EVR_PIXEL_SQ,		// Used internally
	EVR_PIXEL_FRAME,	// Used internally
	EVR_PIXEL_FRAGMENT,	// Used internally

	EVR_PIXEL_ELEMENT,	// Used internally
//	EVR_OVERL_ELEMENT,	// Used internally

	EVR_UNKNOWN,		// Used internally
	EVR_UNKNOWN2B		// Used internally
};


class CAttributeVR  
{
public:
	struct CSingleVR
	{
		E_VR		VR;
		LPCTSTR		lpName;
		Uint32		nUnitLength;
		Uint32		nMinLength;
		Uint32		nMaxLength;
		Uint32		nProperties;
	};

protected:
	E_VR			m_eVR;

public:
	CAttributeVR&	operator =(CAttributeVR& VR)	{ m_eVR = VR.m_eVR; return *this; }

	MRET			SetEVR(E_VR eVR)				{ m_eVR = eVR; return ME_OK; }
	MRET			SetEVR(LPCTSTR lpName);
	MRET			SetEVR(CAttributeVR& VR)		{ m_eVR = VR.m_eVR; return ME_OK; }
	E_VR			GetEVR()						{ return m_eVR; }
	E_VR			GetValidEVR();
	LPCTSTR			GetName();
	LPCTSTR			GetValidName();
	Uint32			GetUnitLength();
	Uint32			GetMinLength();
	Uint32			GetMaxLength();
	BOOL			IsString();
	BOOL			IsStandardVR();
	BOOL			IsInternalUse();
	BOOL			IsExtendedLength();
	BOOL			IsEquivalent(CAttributeVR& VR);

public:
	CAttributeVR(E_VR eVR)							{ SetEVR(eVR); };
	CAttributeVR(LPCTSTR lpName)					{ SetEVR(lpName); };
	CAttributeVR(CAttributeVR& VR)					{ m_eVR = VR.m_eVR; };
	CAttributeVR();
	virtual ~CAttributeVR();
};

#endif // !defined(AFX_ATTRIBUTEVR_H__BCFD9E0A_F03B_4538_9DE9_D0E6DB42B649__INCLUDED_)
