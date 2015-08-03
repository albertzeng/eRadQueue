// Overls.h: interface for the COverls class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OVERLS_H__83013559_C20A_482F_9DC8_0ED55291F6D2__INCLUDED_)
#define AFX_OVERLS_H__83013559_C20A_482F_9DC8_0ED55291F6D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	OVERL_MAX_COUNT			16
#define	OVERL_FIRST_GNUMBER		0x6000

class COverlPlane  
{
protected:
	Uint16			m_nGNumber;
	Uint32			m_nFrames;			// (60xx,0015) Number of Frames in Overlay
	Uint16			m_nFrameStart;		// (60xx,0051) Image Frame Origin
	E_OVERL_MODE	m_eMode;			// (60xx,0040) Overlay Type
	E_OVERL_MODE	m_eDefaultMode;		// (60xx,0040) Overlay Type

	Uint16			m_nRows;			// (60xx,0010) Overlay Rows
	Uint16			m_nColumns;			// (60xx,0011) Overlay Columns
	Sint16			m_nLTRow;			// (60xx,0050) Overlay Origin
	Sint16			m_nLTColumn;		// (60xx,0050) Overlay Origin

	Uint16			m_nBitsAllocated;	// (60xx,0100) Overlay Bits Allocated
	Uint16			m_nBitPosition;		// (60xx,0102) Overlay Bit Position

	CString			m_strLabel;			// (60xx,1500) Overlay Label
	CString			m_strDescriptor;	// (60xx,0022) Overlay Description

	BOOL			m_bVisible;
	BOOL			m_bValueEmbedded;

	double			m_dblFore;
	double			m_dblThreshold;

	Uint16*			m_lpValue;			// Reference

private:
	Uint32			m_nBits;
	Uint32			m_nStartBits;
	Uint16*			m_lpPtr;
	Uint16*			m_lpStartPtr;

public:
	MRET			InitOverlPlane(CImageFile* pImageFile, Uint16 nGNumber, Uint16 nBitsAllocated);

public:
	MRET			CreatePlaneValue(LPVOID& lpvValue, Uint32& nSize, Uint16& nRows, Uint16& nColumns, Uint32& nFrames);

	Uint16			GetGNumber()				{ return this->m_nGNumber; }
	Uint32			GetFrames()					{ return this->m_nFrames; }
	E_OVERL_MODE	GetMode()					{ return this->m_eMode; }
	Uint16			GetRows()					{ return this->m_nRows; }
	Uint16			GetColumns()				{ return this->m_nColumns; }
	Sint16			GetLTRow()					{ return this->m_nLTRow; }
	Sint16			GetLTColumn()				{ return this->m_nLTColumn; }
	Sint16			GetRBRow()					{ return this->m_nLTRow + this->m_nRows; }
	Sint16			GetRBColumn()				{ return this->m_nLTColumn + this->m_nColumns; }
	double			GetFore()					{ return this->m_dblFore; }
	double			GetThreshold()				{ return this->m_dblThreshold; }
	LPCTSTR			GetLabel()					{ return this->m_strLabel; }
	LPCTSTR			GetDescriptor()				{ return this->m_strDescriptor; }
	BOOL			IsVisible()					{ return this->m_bVisible; }
	BOOL			IsValueEmbedded()			{ return this->m_bValueEmbedded; }
	BOOL			Hide()						{ return this->m_bVisible = FALSE; }
	BOOL			Show()						{ return this->m_bVisible = TRUE; }
	BOOL			Show(double dblFore, double dblThreshold, E_OVERL_MODE eMode);

public:
	BOOL Reset(Uint32 nFrame)
	{
		if ((this->m_lpValue == NULL) || (nFrame < this->m_nFrameStart) || (nFrame >= this->m_nFrameStart + this->m_nFrames))
			return FALSE;

		Uint32 nBits = nFrame * (Uint32) this->m_nRows * (Uint32) this->m_nColumns * (Uint32) this->m_nBitsAllocated;
		this->m_nStartBits = this->m_nBits = (Uint32) this->m_nBitPosition + nBits;
		this->m_lpStartPtr = this->m_lpPtr = this->m_lpValue + (nBits >> 4);

		return TRUE;;
	}

	BOOL SetStart(Uint16 nRow, Uint16 nColumn)
	{
		Uint32 nOffset = (Uint32) (nRow - this->m_nLTRow) * (Uint32) this->m_nColumns + (Uint32) (nColumn - this->m_nLTColumn);
		if (this->m_nBitsAllocated == 16)
			this->m_lpPtr = this->m_lpStartPtr + nOffset;
		else
			this->m_nBits = this->m_nStartBits + nOffset * (Uint32) this->m_nBitsAllocated;

		return TRUE;
	}

	BOOL GetNextBit()
	{
		BOOL bResult = FALSE;
		if (this->m_nBitsAllocated == 16)
			bResult = (((*this->m_lpPtr++) & (1 << this->m_nBitPosition)) != 0);
		else
		{
			this->m_lpPtr = this->m_lpStartPtr + (this->m_nBits >> 4);
			bResult = (((*this->m_lpPtr) & (1 << (this->m_nBits & 0xF))) != 0);
			this->m_nBits += this->m_nBitsAllocated;
		}

		return bResult;
	}

public:
	COverlPlane();
	virtual ~COverlPlane();
};


class COverls : public CCounter  
{
protected:
	Uint16			m_nPlaneCount;
	Sint16			m_nLTRow;
	Sint16			m_nLTColumn;
	Sint16			m_nRBRow;
	Sint16			m_nRBColumn;
	COverlPlane**	m_pPlanes;

public:
	MRET			CreateOverls(CImageFile* pImageFile = NULL, Uint16 nBitsAllocated = 0);

public:
	BOOL			HideAllPlanes();
	BOOL			ShowAllPlanes();
	BOOL			ShowAllPlanes(double dblFore, double dblThreshold, E_OVERL_MODE eMode);
	BOOL			HasValueEmbedded();

	Uint16			GetPlaneCount()				{ return (this->m_nPlaneCount); }
	Sint16			GetLTRow()					{ return (this->m_nLTRow); }
	Sint16			GetLTColumn()				{ return (this->m_nLTColumn); }
	Sint16			GetRBRow()					{ return (this->m_nRBRow); }
	Sint16			GetRBColumn()				{ return (this->m_nRBColumn); }
	COverlPlane*	GetPlane(Uint16 nPlane)		{ return (!this->HasPlane(nPlane)) ? NULL		: this->m_pPlanes[nPlane]; }
	Uint16			GetGNumber(Uint16 nPlane)	{ return (!this->HasPlane(nPlane)) ? 0			: this->m_pPlanes[nPlane]->GetGNumber(); }
	E_OVERL_MODE	GetMode(Uint16 nPlane)		{ return (!this->HasPlane(nPlane)) ? EOM_DEFAULT: this->m_pPlanes[nPlane]->GetMode(); }
	LPCTSTR			GetLabel(Uint16 nPlane)		{ return (!this->HasPlane(nPlane)) ? NULL		: this->m_pPlanes[nPlane]->GetLabel(); }
	LPCTSTR			GetDescriptor(Uint16 nPlane){ return (!this->HasPlane(nPlane)) ? NULL		: this->m_pPlanes[nPlane]->GetDescriptor(); }
	BOOL			IsVisible(Uint16 nPlane)	{ return (!this->HasPlane(nPlane)) ? FALSE		: this->m_pPlanes[nPlane]->IsVisible(); }
	BOOL			HidePlane(Uint16 nPlane)	{ return (!this->HasPlane(nPlane)) ? FALSE		: this->m_pPlanes[nPlane]->Hide(); }
	BOOL			ShowPlane(Uint16 nPlane)	{ return (!this->HasPlane(nPlane)) ? FALSE		: this->m_pPlanes[nPlane]->Show(); }
	BOOL			ShowPlane(Uint16 nPlane, double dblFore, double dblThreshold, E_OVERL_MODE eMode)
												{ return (!this->HasPlane(nPlane)) ? FALSE		: this->m_pPlanes[nPlane]->Show(dblFore, dblThreshold, eMode); }

private:
	BOOL			IsGNumber(Uint16 nGNumber)	{ return ((nGNumber >= this->ToGNumber(0)) && (nGNumber < this->ToGNumber(OVERL_MAX_COUNT)) && !(nGNumber & 1)); }
	Uint16			ToGNumber(Uint16 nPNumber)	{ return (OVERL_FIRST_GNUMBER + 2 * nPNumber); }

public:
	BOOL HasPlane(Uint16& nPlane)
	{
		if (this->IsGNumber(nPlane)) nPlane = (nPlane - OVERL_FIRST_GNUMBER) >> 1;

		if ((nPlane < OVERL_MAX_COUNT) && (this->m_pPlanes != NULL) && (this->m_pPlanes[nPlane]) != NULL)
			return TRUE;

		return FALSE;
	}

public:
	COverls();
	virtual ~COverls();
};

#endif // !defined(AFX_OVERLS_H__83013559_C20A_482F_9DC8_0ED55291F6D2__INCLUDED_)
