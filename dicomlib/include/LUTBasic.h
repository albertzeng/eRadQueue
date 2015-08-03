// LUTBasic.h: interface for the CLUTBasic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LUTBASIC_H__711E92D7_94E8_47C7_9487_FCF63A29BEDB__INCLUDED_)
#define AFX_LUTBASIC_H__711E92D7_94E8_47C7_9487_FCF63A29BEDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLUTBasic  
{
protected:
	Uint32	m_nEntries;
	Uint16	m_nFst;			// FIRST Value
	Uint16	m_nBits;
	Uint16	m_nMinValue;
	Uint16	m_nMaxValue;
	Uint16*	m_lpValue;

public:
	inline Uint32	GetEntries()			{ return this->m_nEntries; }
	inline Uint16	GetBits()				{ return this->m_nBits; }
	inline Uint32	GetFst(Uint32 = 0)		{ return this->m_nFst; }
	inline Uint32	GetLst(Uint32 = 0)		{ return this->m_nFst + this->m_nEntries - 1; }
	inline Sint32	GetFst(Sint32)			{ return ((Sint16) this->m_nFst); }
	inline Sint32	GetLst(Sint32)			{ return ((Sint16) this->m_nFst) + this->m_nEntries - 1; }

	inline Uint16	GetFstValue()			{ return this->m_lpValue[0]; }
	inline Uint16	GetLstValue()			{ return this->m_lpValue[this->m_nEntries - 1]; }
	inline Uint16	GetMinValue()			{ return this->m_nMinValue; }
	inline Uint16	GetMaxValue()			{ return this->m_nMaxValue; }
	inline Uint32	GetAbsMaxRange()		{ return MAX_VALUE1(this->m_nBits); }
	inline Uint16	GetValue(Uint16 nPos)	{ return this->m_lpValue[nPos]; }
	inline Uint16	GetValue(Uint32 nPos)	{ return this->m_lpValue[nPos - this->m_nFst]; }
	inline Uint16	GetValue(Sint32 nPos)	{ return this->m_lpValue[nPos - (Sint16) this->m_nFst]; }

	inline Uint16*	GetValue()				{ return this->m_lpValue; }

public:
	CLUTBasic();
	virtual ~CLUTBasic();
};


class CLUTTable : public CLUTBasic  
{
protected:
	MRET	CheckValue();

public:
	MRET	CreateTable(Uint16* lpValue, Uint32 nEntries, Uint16 nBits, Uint16 nFst = 0);
	MRET	CreateTable(CElement* pValue, CElement* pDescriptor, CElement* pExplanation = NULL);
	MRET	CreateTable(CImageFile* pImageFile, CTIndex& idxValue, CTIndex& idxDescriptor, CTIndex& idxExplanation);
	MRET	CreateTable(CImageFile* pImageFile, CTIndex& idxSQ, CTIndex& idxValue, CTIndex& idxDescriptor, CTIndex& idxExplanation, Uint32 nPos = 0);

public:
	CLUTTable();
	virtual ~CLUTTable();
};

#endif // !defined(AFX_LUTBASIC_H__711E92D7_94E8_47C7_9487_FCF63A29BEDB__INCLUDED_)
