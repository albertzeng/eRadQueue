// RADImage.h: interface for the CRADImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RADIMAGE_H__12C05CAF_B325_4F43_8F2F_F9320CBBDB39__INCLUDED_)
#define AFX_RADIMAGE_H__12C05CAF_B325_4F43_8F2F_F9320CBBDB39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWinLvl  
{
private:
	double	m_win, m_midwin, m_minwin, m_maxwin, m_defwin;
	double	m_lvl, m_midlvl, m_minlvl, m_maxlvl, m_deflvl;

public:
	double	GetWin() { return m_win; }
	double	GetLvl() { return m_lvl; }
	void	UseDefWinLvl() { m_win = m_defwin; m_lvl = m_deflvl; }
	void	UseMidWinLvl() { m_win = m_midwin; m_lvl = m_midlvl; }
	void	GetMinMaxWin(double& min, double& max) { min = m_minwin; max = m_maxwin; }
	void	GetMinMaxLvl(double& min, double& max) { min = m_minlvl; max = m_maxlvl; }
	void	SetMinMaxWin(double  min, double  max) { m_minwin = min; m_maxwin = max; }
	void	SetMinMaxLvl(double  min, double  max) { m_minlvl = min; m_maxlvl = max; }
	void	SetMidWinLvl(double  win, double  lvl) { m_midwin = win; m_midlvl = lvl; }
	void	SetDefWinLvl(double  win, double  lvl) { m_defwin = win; m_deflvl = lvl; }

	void SetWinLvl(double win, double lvl)
	{
		m_win = (win < m_minwin) ? m_minwin : (win > m_maxwin) ? m_maxwin : win;
		m_lvl = (lvl < m_minlvl) ? m_minlvl : (lvl > m_maxlvl) ? m_maxlvl : lvl;
	}

public:
	CWinLvl() { m_win = m_minwin = m_maxwin = m_defwin = m_lvl = m_minlvl = m_maxlvl = m_deflvl = 0.0; }
	virtual ~CWinLvl() {}
};

class CRADImage  
{
public:
	CImageFile*		m_pImageFile;

protected:
	Uint32			m_nFrames;					/// (0028,0008) Number of Frames
	Uint16			m_nRows;					/// (0028,0010) Rows
	Uint16			m_nColumns;					/// (0028,0011) Columns
	Uint16			m_nBitsAllocated;			/// (0028,0100) Bits Allocated
	Uint16			m_nBitsStored;				/// (0028,0101) Bits Stored
	Uint16			m_nHighBit;					/// (0028,0102) High Bit

protected:
	CIPixel*		m_pIPixel;
	CMPixel*		m_pMPixel;
	COPixel*		m_pOPixel;
	BOOL			m_bSignedEPR;
	Uint16			m_nBitsPerSample;

protected:
	CWinLvl			m_WinLvl;
	Uint32			m_nWinLvlCount;
	CLUTTable*		m_pVTable;
	Uint32			m_nVTableCount;
	CLUTTable*		m_pPTable;
	E_PLUT_SHAPE	m_ePShape;

public:
	static	MRET	CreateImage(CRADImage*& pRADImage, CImageFile* pImageFile, Uint32 nFrame = 0);
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);
	virtual	MRET	RemoveOPixel();

protected:
	virtual MRET	RemoveIPixel();
	virtual MRET	RemoveMPixel();
	virtual MRET	ReadParameter();
	virtual MRET	ReadPixel(Uint32 nFrame, Uint16 nSamplesPerPixel, double dblCellsPerPixel);
	virtual	MRET	GetPixel(LPVOID& lpvBuffer, Uint16 nBits, Uint32 nFrame, BOOL nPlane, BOOL bNegative);

public:
	virtual Uint32	GetFrames()					{ return this->m_nFrames; }
	virtual Uint16	GetRows()					{ return this->m_nRows; }
	virtual Uint16	GetCols()					{ return this->m_nColumns; }
	virtual Uint16	GetBits(Uint16 nBits = 0)	{ return ((nBits < 1) || (nBits > MAX_BITS)) ? this->m_nBitsPerSample : nBits; }
	virtual	CMPixel*GetMPixel()					{ return this->m_pMPixel; }

public:
	virtual E_PI	GetMEPI() = 0;
	virtual MRET	GetValue(LPVOID& lpvBuffer, Uint16 nBits, Uint32 nFrame = 0, BOOL bPlane = FALSE);

public:
	CWinLvl*		GetWinLvl();
	MRET			UseDefWinLvl();
	Uint32			GetWinLvlCount();
	MRET			GetWinLvl(double& dblWin, double& dblLvl);
	MRET			SetWinLvl(Uint32 nPos = 0);
	MRET			SetWinLvl(double dblWin, double dblLvl);
	Uint32			GetVTableCount();
	MRET			SetVTable(Uint32 nPos);
	MRET			SetVTable(CElement* pValue, CElement* pDescriptor, CElement* pExplanation = NULL);
	E_PLUT_SHAPE	GetPLUTShape();
	MRET			SetPLUTShape(E_PLUT_SHAPE ePShape);
	MRET			SetPTable(CElement* pValue, CElement* pDescriptor, CElement* pExplanation = NULL);

public:
	CRADImage();
	virtual ~CRADImage();
};

#endif // !defined(AFX_RADIMAGE_H__12C05CAF_B325_4F43_8F2F_F9320CBBDB39__INCLUDED_)
