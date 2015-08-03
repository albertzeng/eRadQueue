// OPixel.h: interface for the COPixel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPIXEL_H__20F37286_8F6E_47E6_B27F_6659D1D074F0__INCLUDED_)
#define AFX_OPIXEL_H__20F37286_8F6E_47E6_B27F_6659D1D074F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLUTTable;

class COPixel  
{
protected:
	Uint16	m_nRows;
	Uint16	m_nColumns;

public:
	virtual MRET	CreatePixel(CMPixel* pMPixel, CLUTTable* pVTable, CLUTTable* pPTable, double dblWin, double dblLvl, Uint32 nLValue, Uint32 nHValue, Uint32 nFrame, BOOL bPlane = FALSE);

public:
	virtual	Uint16	GetRows()		{ return this->m_nRows; }
	virtual	Uint16	GetColumns()	{ return this->m_nColumns; }
	virtual	Uint32	GetFrameSize()	{ return this->m_nRows * (Uint32) this->m_nColumns; }

public:
	virtual Uint16	GetPlanes()		= 0;
	virtual E_PR	GetEPR()		= 0;
	virtual Uint32	GetPixelSize()	= 0;
	virtual LPVOID	GetValue()		= 0;
	virtual LPVOID	RemoveValue()	= 0;
	virtual LPVOID	GetPlane(Uint16 nPlane) = 0;

public:
	COPixel();
	virtual ~COPixel();
};

#endif // !defined(AFX_OPIXEL_H__20F37286_8F6E_47E6_B27F_6659D1D074F0__INCLUDED_)
