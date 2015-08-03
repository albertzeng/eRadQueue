// JDecoder08.h: interface for the CJDecoder08 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDECODER08_H__543F07A1_53FF_4B33_BFB6_993F771DA415__INCLUDED_)
#define AFX_JDECODER08_H__543F07A1_53FF_4B33_BFB6_993F771DA415__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JDecoder.h"

extern "C"
{
	struct jpeg_decompress_struct;
}

class CJDecoder08 : public CJDecoder  
{
private:
	jpeg_decompress_struct* cinfo;
	Uint32 suspension;
	LPVOID jsampBuffer;

private:
	virtual MRET	clean();

public:
	virtual MRET	FrameStart();
	virtual MRET	FrameDecode(Uint8* lpCompressed, Uint32 nCompressed, Uint8* lpUncompressed, Uint32 nUncompressed);

public:
	CJDecoder08();
	virtual ~CJDecoder08();
};

#endif // !defined(AFX_JDECODER08_H__543F07A1_53FF_4B33_BFB6_993F771DA415__INCLUDED_)
