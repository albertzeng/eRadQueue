// JEncoder.h: interface for the CJEncoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JENCODER_H__CF3622D5_EC16_4D7F_B81C_A83C642144B9__INCLUDED_)
#define AFX_JENCODER_H__CF3622D5_EC16_4D7F_B81C_A83C642144B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	JPEG_ENCODER_BLOCKSIZE	0x4000

class CJEncoder  
{
public:
	virtual MRET	FrameEncode(LPVOID lpvUncompressed, Uint8*& lpCompressed, Uint32& nLength) = 0;

public:
	CJEncoder();
	virtual ~CJEncoder();
};

#endif // !defined(AFX_JENCODER_H__CF3622D5_EC16_4D7F_B81C_A83C642144B9__INCLUDED_)
