// MoImage.h: interface for the CMoImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOIMAGE_H__D5787C58_870C_4A18_A741_56C491163915__INCLUDED_)
#define AFX_MOIMAGE_H__D5787C58_870C_4A18_A741_56C491163915__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RADImage.h"

class CMoImage : public CRADImage  
{
protected:
	MRET				CreateMPixel(CLUTModalities* pModalities);

public:
	virtual	MRET		CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);
//	virtual MRET		CreateImage(CImageFile* pImageFile, double dblSlope, double dblIntercept);
//	virtual MRET		CreateImage(CImageFile* pImageFile, CElement* pLutValue, CElement* pDescriptor, CElement* pExplanation);

public:
	CMoImage();
	virtual ~CMoImage();
};


class CMo1Image : public CMoImage  
{
public:
	virtual	MRET		CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);

public:
	virtual E_PI		GetMEPI()		{ return EPI_MONOCHROME1; }
	virtual MRET		GetValue(LPVOID& lpvBuffer, Uint16 nBits, Uint32 nFrame = 0, BOOL bPlane = FALSE);

public:
	CMo1Image();
	virtual ~CMo1Image();
};


class CMo2Image : public CMoImage  
{
public:
	virtual	MRET		CreateImage(CImageFile* pImageFile, Uint32 nFrame = 0, Uint16 nSamplesPerPixel = 1, double dblCellsPerPixel = 1.0);
//	virtual MRET		CreateImage(CImageFile* pImageFile, double dblSlope, double dblIntercept);
//	virtual MRET		CreateImage(CImageFile* pImageFile, CElement* pLutValue, CElement* pDescriptor, CElement* pExplanation);

public:
	virtual E_PI		GetMEPI()		{ return EPI_MONOCHROME2; }
	virtual MRET		GetValue(LPVOID& lpvBuffer, Uint16 nBits, Uint32 nFrame = 0, BOOL bPlane = FALSE);

public:
	CMo2Image();
	virtual ~CMo2Image();
};

#endif // !defined(AFX_MOIMAGE_H__D5787C58_870C_4A18_A741_56C491163915__INCLUDED_)
