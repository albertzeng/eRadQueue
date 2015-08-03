// TAG.h: interface for the CTAG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TAG_H__A02415F0_5C12_4EDA_B4C5_CADF6FA2125B__INCLUDED_)
#define AFX_TAG_H__A02415F0_5C12_4EDA_B4C5_CADF6FA2125B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	DCM_UnknownAttributeName	_T("????")

#define DCM_ItemTAG					(CTAG(DCM_Item))
#define DCM_InternalTAG				(CTAG(CTIndex(0xFFFE, 0xFFFE)))

///////////////////////////////////////////////////////////////////////////////
#include "TAG.inc"
///////////////////////////////////////////////////////////////////////////////

class CTIndex  
{
private:
	Uint16			m_nGNumber;
	Uint16			m_nENumber;

public:
	CTIndex&		operator = (CTIndex& TIndex)			{ Set(TIndex); return *this; }
	BOOL			operator ==(CTIndex& TIndex)			{ return ((GetGNumber() == TIndex.GetGNumber()) && (GetENumber() == TIndex.GetENumber())); }
	BOOL			operator !=(CTIndex& TIndex)			{ return !(*this == TIndex); }
	BOOL			operator < (CTIndex& TIndex)			{ return ((GetGNumber() < TIndex.GetGNumber()) || ((GetGNumber() == TIndex.GetGNumber()) && (GetENumber() < TIndex.GetENumber()))); }
	BOOL			operator > (CTIndex& TIndex)			{ return ((GetGNumber() > TIndex.GetGNumber()) || ((GetGNumber() == TIndex.GetGNumber()) && (GetENumber() > TIndex.GetENumber()))); }
	BOOL			operator <=(CTIndex& TIndex)			{ return (*this < TIndex) || (*this == TIndex); }
	BOOL			operator >=(CTIndex& TIndex)			{ return (*this > TIndex) || (*this == TIndex); }

	BOOL			Set(CTIndex& TIndex)					{ m_nGNumber = TIndex.m_nGNumber; m_nENumber = TIndex.m_nENumber; return TRUE; }
	BOOL			Set(Uint16 nGNumber, Uint16 nENumber)	{ m_nGNumber = nGNumber; m_nENumber = nENumber; return TRUE; }
	BOOL			SetGNumber(Uint16 nGNumber)				{ m_nGNumber = nGNumber; return TRUE; }
	BOOL			SetENumber(Uint16 nENumber)				{ m_nENumber = nENumber; return TRUE; }
	Uint16			GetGNumber()							{ return m_nGNumber; }
	Uint16			GetENumber()							{ return m_nENumber; }

	Uint32			Hashed()								{ return (((GetGNumber() << 16) & 0xFFFF0000) | (GetENumber() & 0xFFFF)); }

public:
	CTIndex(CTIndex& TIndex)								{ m_nGNumber = TIndex.m_nGNumber; m_nENumber = TIndex.m_nENumber; }
	CTIndex(Uint16 nGNumber, Uint16 nENumber)				{ m_nGNumber = nGNumber; m_nENumber = nENumber; }
	CTIndex()			{ this->m_nGNumber	= 0xFFFF; this->m_nENumber	= 0xFFFF; }
	virtual ~CTIndex()	{}
};


class CTAG : public CTIndex  
{
private:
	CAttributeVR	m_VR;
	CString			m_strAttributeName;
	CString			m_strPrivateCreator;

public:
	CTAG&			operator =(CTAG& TAG);

	CAttributeVR	SetEVR(E_VR eVR)						{ m_VR.SetEVR(eVR); return m_VR; }
	CAttributeVR	GetVR()									{ return m_VR; }
	E_VR			GetEVR()								{ return m_VR.GetEVR(); }
	LPCTSTR			GetVRName()								{ return m_VR.GetName(); }
	CTIndex&		GetTIndex()								{ return *this; }
	LPCTSTR			GetArrtibuteName();
	LPCTSTR			GetPrivateCreator()						{ return m_strPrivateCreator; }
	BOOL			IsUnknownVR();
	BOOL			LookupVR();
	BOOL			SetPrivateCreator(LPCTSTR lpCreator)	{ m_strAttributeName.Empty(); m_strPrivateCreator = lpCreator; return TRUE; }

public:
	CTAG(CTIndex& TIndex);
	CTAG(Uint16 nGNumber, Uint16 nENumber);
	CTAG(CTIndex& TIndex, CAttributeVR& VR);
	CTAG(CTIndex& TIndex, E_VR eVR);
	CTAG(Uint16 nGNumber, Uint16 nENumber, CAttributeVR& VR);
	CTAG(CTAG& TAG);
	CTAG();
	virtual ~CTAG();
};

#endif // !defined(AFX_TAG_H__A02415F0_5C12_4EDA_B4C5_CADF6FA2125B__INCLUDED_)
