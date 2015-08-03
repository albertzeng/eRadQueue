// JDecoder12.h: interface for the CJDecoder12 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDECODER12_H__EB921039_9B44_44B2_AEEC_BBE03FD38FDE__INCLUDED_)
#define AFX_JDECODER12_H__EB921039_9B44_44B2_AEEC_BBE03FD38FDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JDecoder.h"

extern "C"
{
	struct jpeg_decompress_struct;
}

class CJDecoder12 : public CJDecoder  
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
	CJDecoder12();
	virtual ~CJDecoder12();
};

#endif // !defined(AFX_JDECODER12_H__EB921039_9B44_44B2_AEEC_BBE03FD38FDE__INCLUDED_)
