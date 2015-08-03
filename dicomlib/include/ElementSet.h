// ElementSet.h: interface for the CElementSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMENTSET_H__57D08BB3_50F4_4896_8D65_1C916D0B0AA5__INCLUDED_)
#define AFX_ELEMENTSET_H__57D08BB3_50F4_4896_8D65_1C916D0B0AA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CElementSet : public CDCMObject  
{
friend class CObBasic;

protected:
	COBList<CElement>*	m_pElementList;

protected:
			CElement*	CreateElement(CElement* pObject);
			CElement*	CreateElement(CTAG* pObject, Uint32 nLength = 0);
			MRET		CreateElement(CElement*& pElement, CTAG* pObject, Uint32 nLength = 0);
			MRET		PutBlankElement(CTIndex& TIndex, BOOL bReplace = TRUE);
			MRET		ParseHeader(CIstream* pIOstream, CTransferSyntax* pTS, CTAG& TAG, Uint32& nLength);
			MRET		ParseSubElement(CIstream* pIOstream, CTransferSyntax* pTS, CTAG* pObject, Uint32 nLength);

public:
			MRET		PutElement(CElement* pElement, BOOL bReplace = FALSE, BOOL bOrderCheck = FALSE);

public:
	virtual E_VR		GetLabel()		{ return EVR_ITEM; }
	virtual Uint32		GetVM()			{ return 1; }

	virtual MRET		GetValueLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	virtual CElement*	FindElement(CTIndex& TIndex);
	virtual MRET		Search(CTIndex& TIndex, COBList<CDCMObject>& list);
			CElement*	Remove(CTIndex& TIndex);
			BOOL		Has(CTIndex& TIndex);
			BOOL		HasValue(CTIndex& TIndex);
	COBList<CElement>*	GetElementList(){ return m_pElementList; }

public:
			BOOL		GetValueSTR		(CTIndex& TIndex, CString& strValue, Uint32 nPos);
			BOOL		GetValueSTR		(CTIndex& TIndex, CString& strValue);

			BOOL		GetValueSTR		(CTIndex& TIndex, LPSTR&	Value);

			BOOL		GetValueUint8A	(CTIndex& TIndex, Uint8*&	Value,	Uint32* pCount = NULL);
			BOOL		GetValueUint16A	(CTIndex& TIndex, Uint16*&	Value,	Uint32* pCount = NULL);
			BOOL		GetValueSint16A	(CTIndex& TIndex, Sint16*&	Value,	Uint32* pCount = NULL);
			BOOL		GetValueUint32A	(CTIndex& TIndex, Uint32*&	Value,	Uint32* pCount = NULL);
			BOOL		GetValueSint32A	(CTIndex& TIndex, Sint32*&	Value,	Uint32* pCount = NULL);
			BOOL		GetValueFloat32A(CTIndex& TIndex, Float32*&	Value,	Uint32* pCount = NULL);
			BOOL		GetValueFloat64A(CTIndex& TIndex, Float64*&	Value,	Uint32* pCount = NULL);

			BOOL		GetValueUint8	(CTIndex& TIndex, Uint8&	Value,	Uint32 nPos = 0);
			BOOL		GetValueUint16	(CTIndex& TIndex, Uint16&	Value,	Uint32 nPos = 0);
			BOOL		GetValueSint16	(CTIndex& TIndex, Sint16&	Value,	Uint32 nPos = 0);
			BOOL		GetValueUint32	(CTIndex& TIndex, Uint32&	Value,	Uint32 nPos = 0);
			BOOL		GetValueSint32	(CTIndex& TIndex, Sint32&	Value,	Uint32 nPos = 0);
			BOOL		GetValueFloat32	(CTIndex& TIndex, Float32&	Value,	Uint32 nPos = 0);
			BOOL		GetValueFloat64	(CTIndex& TIndex, Float64&	Value,	Uint32 nPos = 0);

public:
			MRET		SetValueSTR		(CTIndex& TIndex, LPCTSTR	Value, BOOL bReplace = TRUE);

			MRET		SetValueUint8A	(CTIndex& TIndex, Uint8*	Value, Uint32 nCount, BOOL bReplace = TRUE);
			MRET		SetValueUint16A	(CTIndex& TIndex, Uint16*	Value, Uint32 nCount, BOOL bReplace = TRUE);
			MRET		SetValueSint16A	(CTIndex& TIndex, Sint16*	Value, Uint32 nCount, BOOL bReplace = TRUE);

			MRET		SetValueUint16	(CTIndex& TIndex, Uint16	Value, Uint32 nPos = 0, BOOL bReplace = TRUE);
			MRET		SetValueSint16	(CTIndex& TIndex, Sint16	Value, Uint32 nPos = 0, BOOL bReplace = TRUE);
			MRET		SetValueUint32	(CTIndex& TIndex, Uint32	Value, Uint32 nPos = 0, BOOL bReplace = TRUE);
			MRET		SetValueSint32	(CTIndex& TIndex, Sint32	Value, Uint32 nPos = 0, BOOL bReplace = TRUE);
			MRET		SetValueFloat32	(CTIndex& TIndex, Float32	Value, Uint32 nPos = 0, BOOL bReplace = TRUE);
			MRET		SetValueFloat64	(CTIndex& TIndex, Float64	Value, Uint32 nPos = 0, BOOL bReplace = TRUE);

public:
	CElementSet();
	CElementSet(CTAG* pObject);
	CElementSet(CElementSet* pObject);
	virtual ~CElementSet();
};


class CFileMetaInfo : public CElementSet  
{
private:
	LPBYTE				m_lpFilePreamble;

private:
			BOOL		NextInclude(CIstream* pIOstream, CTransferSyntax* pTS);

public:
	virtual E_VR		GetLabel()		{ return EVR_FILE_META; }

	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	CFileMetaInfo();
	CFileMetaInfo(CFileMetaInfo* pObject);
	virtual ~CFileMetaInfo();
};


class CFileDataSet : public CElementSet  
{
public:
	virtual E_VR		GetLabel()		{ return EVR_FILE_DATA; }

	virtual MRET		Built			(COstream* pIOstream, CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream, CTransferSyntax* pTS);

public:
	CFileDataSet();
	CFileDataSet(CFileDataSet* pObject);
	virtual ~CFileDataSet();
};


class CFileDICOMDIR : public CElementSet  
{
private:
			BOOL		NextInclude(CIstream* pIOstream, CTransferSyntax* pTS);

public:
	virtual E_VR		GetLabel()		{ return EVR_FILE_DICOMDIR; }

	virtual MRET		Parse			(CIstream* pIOstream, CTransferSyntax* pTS);

public:
	CFileDICOMDIR();
	CFileDICOMDIR(CFileDICOMDIR* pObject);
	virtual ~CFileDICOMDIR();
};


class CElementSQ : public CElement  
{
friend class CObBasic;

protected:
	COBList<CElementSet>*m_pElementSetList;

public:
			Uint32		GetSize()		{ return this->m_pElementSetList->GetSize(); }
			MRET		PutElementSet(CElementSet* pElementSet);
			CElementSet*GetElementSet(Uint32 nNumber);
			MRET		ParseHeader(CIstream* pIOstream, CTransferSyntax* pTS, CTAG& TAG, Uint32& nLength);

public:
	virtual E_VR		GetLabel()		{ return EVR_SQ; }
	virtual Uint32		GetVM()			{ return 1; }

	virtual MRET		GetValueLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	virtual MRET		Search(CTIndex& TIndex, COBList<CDCMObject>& list);

public:
	CElementSQ(CTAG* pObject);
	CElementSQ(CElementSQ* pObject);
	virtual ~CElementSQ();
};


class CElementOX : public CElement  
{
public:
	virtual E_VR		GetLabel()		{ return this->m_TAG.GetEVR(); }
	virtual Uint32		GetVM()			{ return 1; }

	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);

	virtual MRET		GetValueSTR		(CString& strValue, Uint32 nPos);
	virtual MRET		GetValueSTR		(CString& strValue);
	virtual MRET		GetValueUint8A	(Uint8*&	Value);
	virtual MRET		GetValueUint16A	(Uint16*&	Value);
	virtual MRET		GetValueUint8	(Uint8&		Value,	Uint32 nPos = 0);
	virtual MRET		GetValueUint16	(Uint16&	Value,	Uint32 nPos = 0);
	virtual MRET		SetValueUint8A	(Uint8*		Value,	Uint32 nSize);
	virtual MRET		SetValueUint16A	(Uint16*	Value,	Uint32 nSize);

public:
	CElementOX(CTAG* pObject);
	CElementOX(CElementOX* pObject);
	virtual ~CElementOX();
};


class CElementChangeOX : public CElementOX  
{
public:
	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	virtual MRET		GetValueUint8A		(Uint8*&	Value);
	virtual MRET		GetValueUint16A		(Uint16*&	Value);
	virtual MRET		SetValueUint8A		(Uint8*		Value,	Uint32 nSize);
	virtual MRET		SetValueUint16A		(Uint16*	Value,	Uint32 nSize);
	virtual MRET		CreateValueUint8A	(Uint8*&	Value,	Uint32 nSize);
	virtual MRET		CreateValueUint16A	(Uint16*&	Value,	Uint32 nSize);

public:
	CElementChangeOX(CTAG* pObject);
	CElementChangeOX(CElementChangeOX* pObject);
	virtual ~CElementChangeOX();
};


class CPixelFragment : public CElementOX  
{
public:
			MRET		BuiltOffsetTable(STList<Uint32>* pLengthList);

public:
	virtual E_VR		GetLabel()		{ return EVR_PIXEL_FRAGMENT; }

	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);

	virtual MRET		BuiltHeader(COstream* pIOstream, CTransferSyntax* pTS);

	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	CPixelFragment(CTAG* pObject);
	CPixelFragment(CPixelFragment* pObject);
	virtual ~CPixelFragment();
};


class CPixelFrame : public CElement  
{
friend class CImageFile;
friend class CPixelElement;

protected:
	COBList<CPixelFragment>*m_pFragmentList;

public:
			MRET		PutFragment(CPixelFragment* pFragment);

public:
	virtual E_VR		GetLabel()		{ return EVR_PIXEL_FRAME; }
	virtual Uint32		GetVM()			{ return 1; }

	virtual MRET		GetValueLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS)	{ return ME_ERR_FUNCTION; }

public:
	CPixelFrame();
	CPixelFrame(CPixelFrame* pObject);
	virtual ~CPixelFrame();
};


class CPixelSQ : public CElement  
{
friend class CImageFile;
friend class CPixelElement;

protected:
	E_TS				m_eTS;
	COBList<CPixelFrame>*m_pFrameList;

public:
			E_TS		GetETS()		{ return m_eTS; }
			MRET		PutFrame(CPixelFrame* pFrame);
			MRET		PutFrame(LPBYTE lpValue, Uint32 nLength);
			MRET		ParseHeader(CIstream* pIOstream, CTransferSyntax* pTS, CTAG& TAG, Uint32& nLength);

public:
	virtual E_VR		GetLabel()		{ return EVR_PIXEL_SQ; }
	virtual Uint32		GetVM()			{ return 1; }

	virtual MRET		GetValueLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	CPixelSQ(CTAG* pObject);
	CPixelSQ(CPixelSQ* pObject);
	virtual ~CPixelSQ();
};


class CPixelElement : public CElementChangeOX  
{
friend class CImageFile;

protected:
			CPixelSQ*	m_pPixelSQ;
			BOOL		m_bHaveDecoded;

public:
	virtual E_VR		GetLabel()		{ return EVR_PIXEL_ELEMENT; }
	virtual	BOOL		HaveDecoded()	{ return this->m_bHaveDecoded; }
	virtual	MRET		DecodeFrame(LPVOID& lpvValue, Uint32 nFrame);
	virtual MRET		GetFrameUint08A(Uint32& nFrame, Uint8*& Value);
	virtual MRET		GetFrameUint16A(Uint32& nFrame, Uint16*& Value);

public:
	virtual MRET		GetValueLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		CalculateLength	(Uint32& nLength,		CTransferSyntax* pTS);
	virtual MRET		Built			(COstream* pIOstream,	CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstream* pIOstream,	CTransferSyntax* pTS);

public:
	CPixelElement(CTAG* pObject);
	CPixelElement(CPixelElement* pObject);
	virtual ~CPixelElement();
};

#endif // !defined(AFX_ELEMENTSET_H__57D08BB3_50F4_4896_8D65_1C916D0B0AA5__INCLUDED_)
