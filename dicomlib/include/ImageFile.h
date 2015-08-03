// ImageFile.h: interface for the CImageFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEFILE_H__3D7720C9_2CAD_4440_BF90_87FBF5420A92__INCLUDED_)
#define AFX_IMAGEFILE_H__3D7720C9_2CAD_4440_BF90_87FBF5420A92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageFile  
{
public:
	BOOL			m_bLoaded;
	BOOL			m_bChanged;
	LONG			m_nReferenceCount;

public:
	Uint32			m_nFileSize;
	CString			m_strFileName;
	CString			m_strOldFileName;

public:
	CDCMPatients*	m_pPatients;
	CDCMStudies*	m_pStudies;
	CDCMSeries*		m_pSeries;
	CDCMImages*		m_pImages;
	LONG			m_nPatientIndex;
	LONG			m_nStudiesIndex;
	LONG			m_nSeriesIndex;
	LONG			m_nImagesIndex;

public:
	CObFileHeader	m_obFileHeader;
	CObImage		m_obImage;

private:
	CFileDataSet*	m_pFileDataSet;
	E_TS			m_eTS;
	E_PI			m_ePhotometric;
	CString			m_strSOPInstUID;
	CString			m_strSOPClassUID;

private:
	Uint16			m_nSamplesPerPixel;			/// (0028,0002) Samples Per Pixel
	Uint16			m_nPlanarConfiguration;		/// (0028,0006) Planar Configuration
	Uint32			m_nFrames;					/// (0028,0008) Number of Frames
	Uint16			m_nRows;					/// (0028,0010) Rows
	Uint16			m_nColumns;					/// (0028,0011) Columns
	Uint16			m_nBitsAllocated;			/// (0028,0100) Bits Allocated
	Uint16			m_nBitsStored;				/// (0028,0101) Bits Stored
	Uint16			m_nHighBit;					/// (0028,0102) High Bit
	Uint16			m_nPixelRepresentation;		/// (0028,0103) Pixel Representation

public:
	E_TS			GetETS()					{ return this->m_eTS; }
	CFileDataSet*	GetFileDataSet()			{ return this->m_pFileDataSet; }
	E_PI			GetEPI()					{ return this->m_ePhotometric; }
	CString&		GetSOPInstUID()				{ return this->m_strSOPInstUID; }
	CString&		GetSOPClassUID()			{ return this->m_strSOPClassUID; }

public:
	Uint16			GetSamplesPerPixel()		{ return this->m_nSamplesPerPixel; }
	Uint16			GetPlanarConfiguration()	{ return this->m_nPlanarConfiguration; }
	Uint32			GetFrames()					{ return this->m_nFrames; }
	Uint16			GetRows()					{ return this->m_nRows; }
	Uint16			GetColumns()				{ return this->m_nColumns; }
	Uint16			GetBitsAllocated()			{ return this->m_nBitsAllocated; }
	Uint16			GetBitsStored()				{ return this->m_nBitsStored; }
	Uint16			GetHighBit()				{ return this->m_nHighBit; }
	Uint16			GetPixelRepresentation()	{ return this->m_nPixelRepresentation; }

public:
	MRET			Load(CIstream* pIOstream, CTransferSyntax* pTS);
	MRET			Load();
	MRET			Load(LPCTSTR lpFileName);

public:
	MRET			LoadDIBFile(LPBITMAPINFO lpBMI, LPBYTE lpBits, CRect* lpROI = NULL);
	MRET			LoadDIBFile(LPCTSTR lpDIBFile, CRect* lpROI = NULL);
	MRET			LoadAVIFile(LPCTSTR lpAviFile, E_ENCAPSULATED_TS eEncapsulatedTS = EETS_NONE, Uint32 nFrameSpace = 0, LPVOID lpvParameter = NULL);

private:
	MRET			Save(HANDLE hFile);

public:
	MRET			Save(LPCTSTR lpFileName);
	MRET			Save(LPCTSTR lpFileName, E_TS eTS, LPVOID lpvParameter = NULL);
	MRET			Save(LPCTSTR lpFileName, E_ENCAPSULATED_TS eEncapsulatedTS, LPVOID lpvParameter = NULL);
	MRET			SaveAT(LPCTSTR lpFileStorage);
	MRET			SaveAT(LPCTSTR lpFileStorage, E_TS eTS, LPVOID lpvParameter = NULL);
	MRET			SaveAT(LPCTSTR lpFileStorage, E_ENCAPSULATED_TS eEncapsulatedTS, LPVOID lpvParameter = NULL);

private:
	MRET			GetTransferableTS(STRING_ARRAY& pTransferableTS);

public:
	MRET			Send(CService* pService, CObCommand* pRequestCommand);

public:
	MRET			LoadAttribute();

private:
	MRET			AdjustOverls();
	MRET			AdjustPixelValue();

public:
	MRET			Decode(BOOL bJustIconImage = FALSE);
	MRET			DecodeFrame(E_PI& ePhotometric);

private:
	MRET			Encode(E_TS eTS, LPVOID lpvParameter = NULL);
	MRET			Encode(E_ENCAPSULATED_TS eEncapsulatedTS, LPVOID lpvParameter = NULL);

private:
	MRET			RLEDecode(CPixelElement* pPixelElement);
	MRET			RLEEncode();

public:
	static Uint8	JDecodeBits(LPBYTE lpValue, Uint32 nLength);

private:
	MRET			JDecode(CPixelElement* pPixelElement);
	MRET			JEncode(E_TS eTS, Uint16 nQualities = 90);
	MRET			JEncodeMoImage(E_TS eTS, Uint16 nQualities, Uint32& nCompressedSize);
	MRET			JEncodeCoImage(E_TS eTS, Uint16 nQualities, Uint32& nCompressedSize);

private:
	MRET			CreatePlanarConfiguration(Uint8 *lpValue, Uint16 nRows, Uint16 nColumns, BOOL bPlanarConfiguration);
	MRET			CreatePlanarConfiguration(Uint16 *lpValue, Uint16 nRows, Uint16 nColumns, BOOL bPlanarConfiguration);

public:
	CImageFile(LPCTSTR lpFileName = NULL);
	virtual ~CImageFile();
};

#endif // !defined(AFX_IMAGEFILE_H__3D7720C9_2CAD_4440_BF90_87FBF5420A92__INCLUDED_)
