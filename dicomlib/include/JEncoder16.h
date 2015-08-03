// JEncoder16.h: interface for the CJEncoder16 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JENCODER16_H__EE011224_54C4_4623_995C_3328004ACC74__INCLUDED_)
#define AFX_JENCODER16_H__EE011224_54C4_4623_995C_3328004ACC74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JEncoder.h"

extern "C"
{
	struct jpeg_compress_struct;
}

class CJEncoder16 : public CJEncoder  
{
private:
	E_TS			m_eTS;
	E_PI			m_ePhotometric;
	Uint16			m_nSamplesPerPixel;
	Uint16			m_nRows;
	Uint16			m_nColumns;
	Uint16			m_nQuality;

private:
	Uint32			m_nLength;
	COBList<Uint8>*	m_pOutputList;

private:
	virtual MRET	clean();

public:
	virtual MRET	FrameEncode(LPVOID lpvUncompressed, Uint8*& lpCompressed, Uint32& nLength);
	virtual MRET	StartOutput(jpeg_compress_struct* cinfo);
	virtual MRET	ClearOutput(jpeg_compress_struct* cinfo);
	virtual MRET	CloseOutput(jpeg_compress_struct* cinfo);

public:
	CJEncoder16(E_TS eTS, E_PI ePhotometric, Uint16 nSamplesPerPixel, Uint16 nRows, Uint16 nColumns, Uint16 nQuality);
	virtual ~CJEncoder16();
};

#endif // !defined(AFX_JENCODER16_H__EE011224_54C4_4623_995C_3328004ACC74__INCLUDED_)
