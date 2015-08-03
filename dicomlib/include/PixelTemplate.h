// PixelTemplate.h: interface for the CPixelTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIXELTEMPLATE_H__A4504693_9086_4113_9E2C_3662FB78EEB3__INCLUDED_)
#define AFX_PIXELTEMPLATE_H__A4504693_9086_4113_9E2C_3662FB78EEB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template<class T>
class CPixelTemplate  
{
public:
	virtual inline BOOL	UintXX();
	virtual inline E_PR	GetEPR();
};

template<> inline BOOL CPixelTemplate<Uint8 >::UintXX()	{ return TRUE; }
template<> inline BOOL CPixelTemplate<Uint16>::UintXX()	{ return TRUE; }
template<> inline BOOL CPixelTemplate<Uint32>::UintXX()	{ return TRUE; }
template<> inline BOOL CPixelTemplate<Sint8 >::UintXX()	{ return FALSE; }
template<> inline BOOL CPixelTemplate<Sint16>::UintXX()	{ return FALSE; }
template<> inline BOOL CPixelTemplate<Sint32>::UintXX()	{ return FALSE; }

template<> inline E_PR CPixelTemplate<Uint8 >::GetEPR()	{ return EPR_Uint08; }
template<> inline E_PR CPixelTemplate<Uint16>::GetEPR()	{ return EPR_Uint16; }
template<> inline E_PR CPixelTemplate<Uint32>::GetEPR()	{ return EPR_Uint32; }
template<> inline E_PR CPixelTemplate<Sint8 >::GetEPR()	{ return EPR_Sint08; }
template<> inline E_PR CPixelTemplate<Sint16>::GetEPR()	{ return EPR_Sint16; }
template<> inline E_PR CPixelTemplate<Sint32>::GetEPR()	{ return EPR_Sint32; }

#endif // !defined(AFX_PIXELTEMPLATE_H__A4504693_9086_4113_9E2C_3662FB78EEB3__INCLUDED_)
