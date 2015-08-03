// Element.h: interface for the CElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMENT_H__0C709014_9B14_48F0_A37F_61B97F945977__INCLUDED_)
#define AFX_ELEMENT_H__0C709014_9B14_48F0_A37F_61B97F945977__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CElement;
class CElementSQ;

class CDCMObject  
{
protected:
	CTAG			m_TAG;
	Uint32			m_nLength;

public:
	CDCMObject*		m_pParent;	// Reference

public:
			E_VR	GetEVR()								{ return this->m_TAG.GetEVR(); }
			CTAG&	GetTAG()								{ return this->m_TAG; }
			Uint16	GetGNumber()							{ return this->m_TAG.GetGNumber(); }
			Uint16	GetENumber()							{ return this->m_TAG.GetENumber(); }
			MRET	SetGNumber(Uint16 nGNumber)				{ this->m_TAG.SetGNumber(nGNumber); return ME_OK; }
			MRET	SetENumber(Uint16 nENumber)				{ this->m_TAG.SetENumber(nENumber); return ME_OK; }

public:
	virtual E_VR	GetLabel() = 0;
	virtual Uint32	GetVM() = 0;
	virtual Uint32	GetLength()								{ return this->m_nLength; }
	virtual MRET	SetLength(Uint32 nLength)				{ this->m_nLength = nLength; return ME_OK; }

	virtual MRET	BuiltHeader(COstream* pIOstream, CTransferSyntax* pTS);

	virtual MRET	GetValueLengthETS	(Uint32& nLength,		E_TS eTS);
	virtual MRET	CalculateLengthETS	(Uint32& nLength,		E_TS eTS);
	virtual MRET	BuiltETS			(COstream* pIOstream,	E_TS eTS);
	virtual MRET	ParseETS			(CIstream* pIOstream,	E_TS eTS);

	virtual MRET	GetValueLength		(Uint32& nLength,		CTransferSyntax* pTS) = 0;
	virtual MRET	CalculateLength		(Uint32& nLength,		CTransferSyntax* pTS) = 0;
	virtual MRET	Built				(COstream* pIOstream,	CTransferSyntax* pTS) = 0;
	virtual MRET	Parse				(CIstream* pIOstream,	CTransferSyntax* pTS) = 0;

public:
	virtual CElement*	FindElement(CTIndex& TIndex)							{ return NULL; }
	virtual MRET	Search(CTIndex& TIndex, COBList<CDCMObject>& list)			{ return ME_OK; }

	virtual	Uint32	FindVM	 (CTIndex& TIndex);

	virtual	Uint32	FindSQ	 (CTIndex& TIndex, CElementSQ*& pElementSQ);

	virtual	Uint32	FindValue(CTIndex& TIndex, CString& strValue, Uint32 nPos = 0);

	virtual	Uint32	FindValue(CTIndex& TIndex, LPSTR&	Value);
	virtual	Uint32	FindValue(CTIndex& TIndex, Uint16*&	Value);

	virtual	Uint32	FindValue(CTIndex& TIndex, Uint16&	Value, Uint32 nPos = 0);
	virtual	Uint32	FindValue(CTIndex& TIndex, Sint16&	Value, Uint32 nPos = 0);
	virtual	Uint32	FindValue(CTIndex& TIndex, Uint32&	Value, Uint32 nPos = 0);
	virtual	Uint32	FindValue(CTIndex& TIndex, Sint32&	Value, Uint32 nPos = 0);
	virtual	Uint32	FindValue(CTIndex& TIndex, double&	Value, Uint32 nPos = 0);

public:
	CDCMObject(CTAG& TAG);
	CDCMObject(CTAG* pObject);
	CDCMObject(CDCMObject* pObject);
	virtual ~CDCMObject();
};


class CElement : public CDCMObject  
{
protected:
	LPBYTE			m_lpValue;
	BOOL			m_bLittleEndian;

public:
	virtual MRET	SetLength(Uint32 nLength);
	virtual Uint32	GetUnitLength()							{ return this->m_TAG.GetVR().GetUnitLength(); }
	virtual LPBYTE	GetValue(BOOL bLittleEndian = CTools::IsLittleMachine());

protected:
	virtual	MRET	SetValue(LPVOID lpvValue, Uint32 nLength);
	virtual	MRET	SetValue(LPVOID lpvValue, Uint32 nLength, Uint32 nPos);
	virtual	MRET	SetBlankValue(Uint32 nLength);

public:
	virtual MRET	GetValueLength	(Uint32& nLength,		CTransferSyntax* pTS)	{ nLength = this->m_nLength; return ME_OK; }
	virtual MRET	CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET	Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET	Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
			MRET	GetValue(Uint16*		Value);
			MRET	GetValue(Sint16*		Value);
			MRET	GetValue(Uint32*		Value);
			MRET	GetValue(Sint32*		Value);
			MRET	GetValue(Float32*		Value);
			MRET	GetValue(Float64*		Value);
			MRET	GetValue(CString*		Value);

			MRET	GetValue(UINT16_ARRAY*	Value);
			MRET	GetValue(SINT16_ARRAY*	Value);
			MRET	GetValue(UINT32_ARRAY*	Value);
			MRET	GetValue(SINT32_ARRAY*	Value);
			MRET	GetValue(FLOAT32_ARRAY*	Value);
			MRET	GetValue(FLOAT64_ARRAY*	Value);
			MRET	GetValue(STRING_ARRAY*	Value);

			MRET	SetValue(Uint16*		Value);
			MRET	SetValue(Sint16*		Value);
			MRET	SetValue(Uint32*		Value);
			MRET	SetValue(Sint32*		Value);
			MRET	SetValue(Float32*		Value);
			MRET	SetValue(Float64*		Value);
			MRET	SetValue(CString*		Value);

			MRET	SetValue(UINT16_ARRAY*	Value);
			MRET	SetValue(SINT16_ARRAY*	Value);
			MRET	SetValue(UINT32_ARRAY*	Value);
			MRET	SetValue(SINT32_ARRAY*	Value);
			MRET	SetValue(FLOAT32_ARRAY*	Value);
			MRET	SetValue(FLOAT64_ARRAY*	Value);
			MRET	SetValue(STRING_ARRAY*	Value);

public:
	virtual MRET	GetValueSTR		(CString& strValue);
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

	virtual MRET	GetValueSTR		(LPSTR&		Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

	virtual MRET	GetValueUint8A	(Uint8*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueSint16A	(Sint16*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueUint16A	(Uint16*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueSint32A	(Sint32*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueUint32A	(Uint32*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueFloat32A(Float32*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueFloat64A(Float64*&	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

	virtual MRET	GetValueTIndex	(CTIndex&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueUint8	(Uint8&		Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueSint16	(Sint16&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueUint16	(Uint16&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueSint32	(Sint32&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueUint32	(Uint32&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueFloat32	(Float32&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	GetValueFloat64	(Float64&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

	virtual MRET	SetValueSTR		(LPCTSTR	Value)					{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

	virtual MRET	SetValueUint8A	(Uint8*		Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueSint16A	(Sint16*	Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueUint16A	(Uint16*	Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueSint32A	(Sint32*	Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueUint32A	(Uint32*	Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueFloat32A(Float32*	Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueFloat64A(Float64*	Value,	Uint32 nSize)	{ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

	virtual MRET	SetValueTIndex	(CTIndex&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueUint8	(Uint8&		Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueSint16	(Sint16&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueUint16	(Uint16&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueSint32	(Sint32&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueUint32	(Uint32&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueFloat32	(Float32&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }
	virtual MRET	SetValueFloat64	(Float64&	Value,	Uint32 nPos = 0){ LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_FUNCTION); }

public:
	CElement(CTAG* pObject);
	CElement(CElement* pObject);
	virtual ~CElement();
};


class CElementSTR : public CElement  
{
protected:
	Uint32			m_nMaxLength;

protected:
	virtual LPBYTE	GetValue(BOOL bLittleEndian = CTools::IsLittleMachine())	{ return this->m_lpValue; }

public:
	virtual Uint32	GetVM();
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSTR		(CString& strValue);
	virtual MRET	GetValueSTR		(LPSTR&		Value);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);

public:
	CElementSTR(CTAG* pObject);
	CElementSTR(CElementSTR* pObject);
	virtual ~CElementSTR();
};


class CElementAE : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_AE; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementAE(CTAG* pObject);
	CElementAE(CElementAE* pObject);
	virtual ~CElementAE();
};


class CElementAS : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_AS; }

public:
	CElementAS(CTAG* pObject);
	CElementAS(CElementAS* pObject);
	virtual ~CElementAS();
};


class CElementAT : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_AT; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / (2 * sizeof(Uint16))); }
	virtual Uint32	GetUnitLength()	{ return 4; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueTIndex	(CTIndex&	Value,	Uint32 nPos = 0);
	virtual MRET	GetValueUint16A	(Uint16*&	Value);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);						// E.G. "(0008,0020)\(0008,0030)"
	virtual MRET	SetValueUint16A	(Uint16*	Value,	Uint32 nSize);
	virtual MRET	SetValueTIndex	(CTIndex&	Value,	Uint32 nPos = 0);

public:
	CElementAT(CTAG* pObject);
	CElementAT(CElementAT* pObject);
	virtual ~CElementAT();
};


class CElementCS : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_CS; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementCS(CTAG* pObject);
	CElementCS(CElementCS* pObject);
	virtual ~CElementCS();
};


class CElementDA : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_DA; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementDA(CTAG* pObject);
	CElementDA(CElementDA* pObject);
	virtual ~CElementDA();
};


class CElementDS : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_DS; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueFloat64	(Float64&	Value,	Uint32 nPos = 0);

public:
	CElementDS(CTAG* pObject);
	CElementDS(CElementDS* pObject);
	virtual ~CElementDS();
};


class CElementDT : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_DT; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementDT(CTAG* pObject);
	CElementDT(CElementDT* pObject);
	virtual ~CElementDT();
};


class CElementFL : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_FL; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / sizeof(Float32)); }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueFloat32A(Float32*&	Value);
	virtual MRET	GetValueFloat32	(Float32&	Value,	Uint32 nPos = 0);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);						// E.G. "12.3456\1\-123.456\1234.0"
	virtual MRET	SetValueFloat32A(Float32*	Value,	Uint32 nSize);
	virtual MRET	SetValueFloat32	(Float32&	Value,	Uint32 nPos = 0);

public:
	CElementFL(CTAG* pObject);
	CElementFL(CElementFL* pObject);
	virtual ~CElementFL();
};


class CElementFD : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_FD; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / sizeof(Float64)); }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueFloat64A(Float64*&	Value);
	virtual MRET	GetValueFloat64	(Float64&	Value,	Uint32 nPos = 0);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);						// E.G. "12.3456\1\-123.456\1234.0"
	virtual MRET	SetValueFloat64A(Float64*	Value,	Uint32 nSize);
	virtual MRET	SetValueFloat64	(Float64&	Value,	Uint32 nPos = 0);

public:
	CElementFD(CTAG* pObject);
	CElementFD(CElementFD* pObject);
	virtual ~CElementFD();
};


class CElementIS : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_IS; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSint32	(Sint32&	Value,	Uint32 nPos = 0);

public:
	CElementIS(CTAG* pObject);
	CElementIS(CElementIS* pObject);
	virtual ~CElementIS();
};


class CElementLO : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_LO; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementLO(CTAG* pObject);
	CElementLO(CElementLO* pObject);
	virtual ~CElementLO();
};


class CElementLT : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_LT; }
	virtual Uint32	GetVM();
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSTR		(CString& strValue);

public:
	CElementLT(CTAG* pObject);
	CElementLT(CElementLT* pObject);
	virtual ~CElementLT();
};


class CElementOF : public CElementFL  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_OF; }
	virtual Uint32	GetVM()			{ return 1; }

public:
	CElementOF(CTAG* pObject);
	CElementOF(CElementOF* pObject);
	virtual ~CElementOF();
};


class CElementPN : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_PN; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementPN(CTAG* pObject);
	CElementPN(CElementPN* pObject);
	virtual ~CElementPN();
};


class CElementSH : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_SH; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementSH(CTAG* pObject);
	CElementSH(CElementSH* pObject);
	virtual ~CElementSH();
};


class CElementSL : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_SL; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / sizeof(Sint32)); }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSint32A	(Sint32*&	Value);
	virtual MRET	GetValueSint32	(Sint32&	Value,	Uint32 nPos = 0);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);					// E.G. "-333\-22\-1\0\1\22\333"
	virtual MRET	SetValueSint32A	(Sint32*	Value,	Uint32 nSize);
	virtual MRET	SetValueSint32	(Sint32&	Value,	Uint32 nPos = 0);

public:
	CElementSL(CTAG* pObject);
	CElementSL(CElementSL* pObject);
	virtual ~CElementSL();
};


class CElementSS : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_SS; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / sizeof(Sint16)); }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSint16A	(Sint16*&	Value);
	virtual MRET	GetValueSint16	(Sint16&	Value,	Uint32 nPos = 0);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);						// E.G. "-333\-22\-1\0\1\22\333"
	virtual MRET	SetValueSint16A	(Sint16*	Value,	Uint32 nSize);
	virtual MRET	SetValueSint16	(Sint16&	Value,	Uint32 nPos = 0);

public:
	CElementSS(CTAG* pObject);
	CElementSS(CElementSS* pObject);
	virtual ~CElementSS();
};


class CElementST : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_ST; }
	virtual Uint32	GetVM();
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSTR		(CString& strValue);

public:
	CElementST(CTAG* pObject);
	CElementST(CElementST* pObject);
	virtual ~CElementST();
};


class CElementTM : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_TM; }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);

public:
	CElementTM(CTAG* pObject);
	CElementTM(CElementTM* pObject);
	virtual ~CElementTM();
};


class CElementUI : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_UI; }

public:
	CElementUI(CTAG* pObject);
	CElementUI(CElementUI* pObject);
	virtual ~CElementUI();
};


class CElementUL : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_UL; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / sizeof(Uint32)); }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueUint32A	(Uint32*&	Value);
	virtual MRET	GetValueUint32	(Uint32&	Value,	Uint32 nPos = 0);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);					// E.G. "1\22\333\4444\55555\666666\7777777"
	virtual MRET	SetValueUint32A	(Uint32*	Value,	Uint32 nSize);
	virtual MRET	SetValueUint32	(Uint32&	Value,	Uint32 nPos = 0);

public:
	CElementUL(CTAG* pObject);
	CElementUL(CElementUL* pObject);
	virtual ~CElementUL();
};


class CElementUS : public CElement  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_US; }
	virtual Uint32	GetVM()			{ return (this->m_nLength / sizeof(Uint16)); }
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueUint16A	(Uint16*&	Value);
	virtual MRET	GetValueUint16	(Uint16&	Value,	Uint32 nPos = 0);
	virtual MRET	SetValueSTR		(LPCTSTR	Value);						// E.G. "1\22\333\4444\55555"
	virtual MRET	SetValueUint16A	(Uint16*	Value,	Uint32 nSize);
	virtual MRET	SetValueUint16	(Uint16&	Value,	Uint32 nPos = 0);

public:
	CElementUS(CTAG* pObject);
	CElementUS(CElementUS* pObject);
	virtual ~CElementUS();
};


class CElementUT : public CElementSTR  
{
public:
	virtual E_VR	GetLabel()		{ return EVR_UT; }
	virtual Uint32	GetVM();
	virtual MRET	GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET	GetValueSTR		(CString& strValue);

public:
	CElementUT(CTAG* pObject);
	CElementUT(CElementUT* pObject);
	virtual ~CElementUT();
};

#endif // !defined(AFX_ELEMENT_H__0C709014_9B14_48F0_A37F_61B97F945977__INCLUDED_)
