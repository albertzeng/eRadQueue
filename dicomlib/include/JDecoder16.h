// JDecoder16.h: interface for the CJDecoder16 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDECODER16_H__AF520CA8_107E_4AAB_862C_2D725BFEB405__INCLUDED_)
#define AFX_JDECODER16_H__AF520CA8_107E_4AAB_862C_2D725BFEB405__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JDecoder.h"

extern "C"
{
	struct jpeg_decompress_struct;
}

class CJDecoder16 : public CJDecoder  
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
	CJDecoder16();
	virtual ~CJDecoder16();
};

#endif // !defined(AFX_JDECODER16_H__AF520CA8_107E_4AAB_862C_2D725BFEB405__INCLUDED_)
