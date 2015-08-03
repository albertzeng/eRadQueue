// LUTModalities.h: interface for the CLUTModalities class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LUTMODALITIES_H__0EC127BC_9FC7_4289_A91E_81B0D1BC4DD8__INCLUDED_)
#define AFX_LUTMODALITIES_H__0EC127BC_9FC7_4289_A91E_81B0D1BC4DD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLUTModalities  
{
protected:
	Uint16		m_nBits;
	E_PR		m_eRepresentation;

	BOOL		m_bLUTTable;
	CLUTTable*	m_pLUTTable;

	BOOL		m_bRescale;
	double		m_dblRescaleSlope;
	double		m_dblRescaleIntercept;

	double		m_dblAbsMinimum;
	double		m_dblAbsMaximum;

protected:
	MRET		CheckValue(CIPixel* pIPixel);

public:
	MRET		CreateModalities(CImageFile* pImageFile, CIPixel* pIPixel);
	MRET		CreateModalities(CImageFile* pImageFile, CIPixel* pIPixel, double dblSlope, double dblIntercept);
	MRET		CreateModalities(CImageFile* pImageFile, CIPixel* pIPixel, CElement* pValue, CElement* pDescriptor, CElement* pExplanation = NULL);

public:
	inline Uint16		GetBits()				{ return this->m_nBits; }
	inline E_PR			GetEPR()				{ return this->m_eRepresentation; }
	inline BOOL			UseLUTTable()			{ return this->m_bLUTTable; }
	inline CLUTTable*	GetLUTTable()			{ return this->m_pLUTTable; }
	inline BOOL			UseRescale()			{ return this->m_bRescale; }
	inline double		GetRescaleSlope()		{ return this->m_dblRescaleSlope; }
	inline double		GetRescaleIntercept()	{ return this->m_dblRescaleIntercept; }
	inline double		GetAbsMinimum()			{ return this->m_dblAbsMinimum; }
	inline double		GetAbsMaximum()			{ return this->m_dblAbsMaximum; }

public:
	CLUTModalities();
	virtual ~CLUTModalities();
};

#endif // !defined(AFX_LUTMODALITIES_H__0EC127BC_9FC7_4289_A91E_81B0D1BC4DD8__INCLUDED_)
