// CoImage.h: interface for the CCoImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COIMAGE_H__16CABB11_D49F_46A9_B0DA_A889E21ABF06__INCLUDED_)
#define AFX_COIMAGE_H__16CABB11_D49F_46A9_B0DA_A889E21ABF06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RADImage.h"

class CCoImage : public CRADImage  
{
public:
	virtual E_PI	GetMEPI()			{ return EPI_RGB; }
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	CCoImage();
	virtual ~CCoImage();
};


class CCoPALImage : public CCoImage  
{
private:
	CLUTTable*		m_pPalette[3];

public:
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	CCoPALImage();
	virtual ~CCoPALImage();
};


class CCoRGBImage : public CCoImage  
{
public:
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	CCoRGBImage();
	virtual ~CCoRGBImage();
};


class CCoYBRImage : public CCoImage  
{
public:
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	CCoYBRImage();
	virtual ~CCoYBRImage();
};


class CCoYBR422Image : public CCoImage  
{
public:
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	CCoYBR422Image();
	virtual ~CCoYBR422Image();
};


class CCoYBRPart422Image : public CCoImage  
{
public:
	virtual	MRET	CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	CCoYBRPart422Image();
	virtual ~CCoYBRPart422Image();
};

#endif // !defined(AFX_COIMAGE_H__16CABB11_D49F_46A9_B0DA_A889E21ABF06__INCLUDED_)
