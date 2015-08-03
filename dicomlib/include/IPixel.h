// IPixel.h: interface for the CIPixel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPIXEL_H__B93253D0_B9EF_489E_86DC_F9ECA78C5A77__INCLUDED_)
#define AFX_IPIXEL_H__B93253D0_B9EF_489E_86DC_F9ECA78C5A77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIPixel  
{
protected:
	Uint16	m_nBits;
	Uint32	m_nFrames;
	Uint16	m_nRows;
	Uint16	m_nColumns;
	Uint16	m_nSamples;
	Uint16	m_nPlane;

protected:
	Uint32	m_nFrame;
	double	m_dblAbsMinimum;
	double	m_dblAbsMaximum;
	double	m_dblCellsPerPixel;

public:
	inline Uint16	GetBits()		{ return this->m_nBits; }
	inline Uint32	GetFrames()		{ return this->m_nFrames; }
	inline Uint16	GetRows()		{ return this->m_nRows; }
	inline Uint16	GetColumns()	{ return this->m_nColumns; }
	inline Uint16	GetSamples()	{ return this->m_nSamples; }
	inline Uint16	GetPlane()		{ return this->m_nPlane; }

	inline Uint32	GetFrame()		{ return this->m_nFrame; }
	inline double	GetAbsMinimum()	{ return this->m_dblAbsMinimum; }
	inline double	GetAbsMaximum()	{ return this->m_dblAbsMaximum; }
	inline double	GetAbsMaxRange(){ return this->m_dblAbsMaximum - this->m_dblAbsMinimum + 1.0; }

	inline Uint32	GetPixelCount()	{ return (this->m_nFrames * (Uint32) this->m_nRows * (Uint32) this->m_nColumns); }
	inline Uint32	GetCellsCount()	{ return (Uint32) (this->GetPixelCount() * this->m_dblCellsPerPixel); }
	inline Uint32	GetFrameCells()	{ return (Uint32) ((Uint32) this->m_nRows * (Uint32) this->m_nColumns * this->m_dblCellsPerPixel); }

public:
	virtual E_PR	GetEPR()		= 0;
	virtual LPVOID	GetValue()		= 0;
	virtual LPVOID	RemoveValue()	= 0;

public:
	virtual MRET	CreatePixel(CImageFile* pImageFile, Uint32 nFrame, Uint16 nSamplesPerPixel, double dblCellsPerPixel);

public:
	CIPixel();
	virtual ~CIPixel();
};

#endif // !defined(AFX_IPIXEL_H__B93253D0_B9EF_489E_86DC_F9ECA78C5A77__INCLUDED_)
