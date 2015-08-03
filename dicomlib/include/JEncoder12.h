// JEncoder12.h: interface for the CJEncoder12 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JENCODER12_H__79538746_B982_479F_A801_4D833B44F3D0__INCLUDED_)
#define AFX_JENCODER12_H__79538746_B982_479F_A801_4D833B44F3D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JEncoder.h"

extern "C"
{
	struct jpeg_compress_struct;
}

class CJEncoder12 : public CJEncoder  
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
	CJEncoder12(E_TS eTS, E_PI ePhotometric, Uint16 nSamplesPerPixel, Uint16 nRows, Uint16 nColumns, Uint16 nQuality);
	virtual ~CJEncoder12();
};

#endif // !defined(AFX_JENCODER12_H__79538746_B982_479F_A801_4D833B44F3D0__INCLUDED_)
