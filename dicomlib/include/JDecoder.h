// JDecoder.h: interface for the CJDecoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDECODER_H__6AD67683_EE5C_4C94_A876_D08303DF8F40__INCLUDED_)
#define AFX_JDECODER_H__6AD67683_EE5C_4C94_A876_D08303DF8F40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CJDecoder  
{
public:
	virtual MRET	FrameStart() = 0;
	virtual MRET	FrameDecode(Uint8* lpCompressed, Uint32 nCompressed, Uint8* lpUncompressed, Uint32 nUncompressed) = 0;

public:
	CJDecoder();
	virtual ~CJDecoder();
};

#endif // !defined(AFX_JDECODER_H__6AD67683_EE5C_4C94_A876_D08303DF8F40__INCLUDED_)
