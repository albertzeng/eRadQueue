// MPixel.h: interface for the CMPixel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MPIXEL_H__911B0777_485D_433C_A5FD_7E801F97F993__INCLUDED_)
#define AFX_MPIXEL_H__911B0777_485D_433C_A5FD_7E801F97F993__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMPixel  
{
protected:
	Uint16	m_nBits;
	Uint32	m_nFrames;
	Uint16	m_nRows;
	Uint16	m_nColumns;

protected:
	Uint32	m_nFrame;
	double	m_dblAbsMinimum;
	double	m_dblAbsMaximum;

public:
	virtual Uint16	GetBits()		{ return this->m_nBits; }
	virtual Uint32	GetFrames()		{ return this->m_nFrames; }
	virtual Uint16	GetRows()		{ return this->m_nRows; }
	virtual Uint16	GetColumns()	{ return this->m_nColumns; }

	virtual	Uint32	GetFrame()		{ return this->m_nFrame; }
	virtual double	GetAbsMinimum()	{ return this->m_dblAbsMinimum; }
	virtual double	GetAbsMaximum()	{ return this->m_dblAbsMaximum; }
	virtual double	GetAbsMaxRange(){ return this->m_dblAbsMaximum - this->m_dblAbsMinimum + 1.0; }

	virtual	BOOL	UintXX()		{ return (this->GetAbsMinimum() >= 0); }
	virtual Uint32	GetFrameSize()	{ return (this->m_nRows * (Uint32) this->m_nColumns); }
	virtual Uint32	GetPixelCount()	{ return (this->m_nFrames * this->GetFrameSize()); }

public:
	virtual Uint16	GetPlanes()		= 0;
	virtual E_PR	GetEPR()		= 0;
	virtual LPVOID	GetValue()		= 0;
	virtual LPVOID	GetPlane(Uint16 nPlane) = 0;
	virtual MRET	GetFrame(LPVOID& lpvBuffer, Uint32 nFrame, BOOL bPlane = FALSE) = 0;

public:
	virtual MRET	CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL);

public:
	CMPixel();
	virtual ~CMPixel();
};


class CMMoPixel : public CMPixel  
{
public:
	virtual Uint16	GetPlanes()		{ return 1; }

public:
	CMMoPixel();
	virtual ~CMMoPixel();
};


class CMCoPixel : public CMPixel  
{
public:
	virtual Uint16	GetPlanes()		{ return 3; }

public:
	CMCoPixel();
	virtual ~CMCoPixel();
};

#endif // !defined(AFX_MPIXEL_H__911B0777_485D_433C_A5FD_7E801F97F993__INCLUDED_)
