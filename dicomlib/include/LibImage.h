// LibImage.h: interface for the CLibImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIBIMAGE_H__FAC8A6A3_5DEC_4805_8AB1_0321670FCD1C__INCLUDED_)
#define AFX_LIBIMAGE_H__FAC8A6A3_5DEC_4805_8AB1_0321670FCD1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "dicomlib.h"

#define	LUT_MIN_BITS			8
#define	LUT_MAX_BITS			16
#define	LUT_MAX_ENTRIES			0x10000

#define	MAX_BITS				16
#define	BITS(T)					(sizeof(T) << 3)
#define	MAX_VALUE0(nBits)		((((Uint32) 1) << ((Uint16) nBits)) - 1)
#define	MAX_VALUE1(nBits)		((((Uint32) 1) << ((Uint16) nBits)))


enum E_PR								/// Pixel Representation (0028,0103)
{
	EPR_UNKNOWN,
	EPR_Sint08, EPR_MinSigned	= EPR_Sint08,
	EPR_Uint08, EPR_MinUnsigned	= EPR_Uint08,
	EPR_Sint16,
	EPR_Uint16,
	EPR_Sint32, EPR_MaxSigned	= EPR_Sint32,
	EPR_Uint32, EPR_MaxUnsigned	= EPR_Uint32,
};

enum E_OVERL_MODE						/// (60xx,0040) Overlay Type
{
	EOM_DEFAULT,
	EOM_Replace,
	EOM_Graphics = EOM_Replace,
	EOM_ThresholdReplace,
	EOM_Complement,
	EOM_ROI,
	EOM_BMPShutter
};

#define	DCM_OVERLAY_TYPE_Graphics	"G"
#define	DCM_OVERLAY_TYPE_ROI		"R"

enum E_PLUT_SHAPE					/// (2050,0020) Presentation LUT Shape
{
	EPS_DEFAULT,
	EPS_LINOD,
	EPS_INVERSE,
	EPS_IDENTITY
};

#define	DCM_PLUT_SHAPE_LINOD		"LIN OD"
#define	DCM_PLUT_SHAPE_INVERSE		"INVERSE"
#define	DCM_PLUT_SHAPE_IDENTITY		"IDENTITY"


class CLibImage  
{
public:
	static Uint16	ToBits(Uint32 nValue);
	static E_PR		GetEPR(double dblMinValue, double dblMaxValue);

public:
	CLibImage();
	virtual ~CLibImage();
};


#include "IPixel.h"
#include "IPixelTemplate.h"
#include "MPixel.h"
#include "MMoPixelTemplate.h"
#include "MCoPixelTemplate.h"
#include "OPixel.h"
#include "OPixelTemplate.h"

#include "LUTBasic.h"
#include "LUTModalities.h"
#include "Overls.h"

#include "RADImage.h"
#include "MoImage.h"
#include "CoImage.h"
#include "DIBImage.h"

#endif // !defined(AFX_LIBIMAGE_H__FAC8A6A3_5DEC_4805_8AB1_0321670FCD1C__INCLUDED_)
