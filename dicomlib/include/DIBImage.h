// DIBImage.h: interface for the CDIBImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIBIMAGE_H__90D70035_FA98_484D_A726_7BCDF8469699__INCLUDED_)
#define AFX_DIBIMAGE_H__90D70035_FA98_484D_A726_7BCDF8469699__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum E_IMAGE_ORIENTATION
{
	E_IMAGE_ORIENTATION_ABCD,		// 正常位置，四角按顺时针分别标记为ABCD
	E_IMAGE_ORIENTATION_DABC,
	E_IMAGE_ORIENTATION_CDAB,
	E_IMAGE_ORIENTATION_BCDA,
	E_IMAGE_ORIENTATION_DCBA,
	E_IMAGE_ORIENTATION_CBAD,
	E_IMAGE_ORIENTATION_BADC,
	E_IMAGE_ORIENTATION_ADCB
};

class CDIBImage  
{
public:
	CString				m_strFileName;

protected:
	DWORD				m_dwDIBSize;
	LPBYTE				m_lpDIB;
	LPBITMAPINFO		m_lpBMI;
	LPBITMAPINFOHEADER	m_lpBMIHeader;
	LPBYTE				m_lpBits;

public:
	virtual MRET		CreateImage(CRADImage* pRADImage, Uint32 nFrame = 0, BOOL bInverse = FALSE);
	virtual	MRET		LoadDIBImage(CDIBImage* pDIBImage, CRect* pRect = NULL);
	virtual	MRET		LoadDIBImage(CDIBImage* pDIBImage, CSize* pSize);
	virtual	MRET		LoadDIBImage(CDIBImage* pDIBImage, E_IMAGE_ORIENTATION eOrientation);
	virtual MRET		LoadDIBImage(LPBYTE lpValue, Uint32 nSize);
	virtual	MRET		LoadDIBFile(LPCTSTR lpDIBFile);
	virtual MRET		SaveDIBFile(HANDLE hFile);
	virtual MRET		SaveDIBFile(LPCTSTR lpDIBFile, DWORD dwCreationFlags = CREATE_NEW);

public:
	DWORD				GetDIBSize()			{ return this->m_dwDIBSize; }
	LPBYTE				GetDIB()				{ return this->m_lpDIB; }
	LPBITMAPINFO		GetBMI()				{ return this->m_lpBMI; }
	LPBITMAPINFOHEADER	GetBMIHeader()			{ return this->m_lpBMIHeader; }
	LPBYTE				GetBits()				{ return this->m_lpBits; }
	LONG				GetCols()				{ return this->m_lpBMIHeader->biWidth; }
	LONG				GetRows()				{ return this->m_lpBMIHeader->biHeight; }

public:
	CDIBImage();
	virtual ~CDIBImage();
};

#endif // !defined(AFX_DIBIMAGE_H__90D70035_FA98_484D_A726_7BCDF8469699__INCLUDED_)
