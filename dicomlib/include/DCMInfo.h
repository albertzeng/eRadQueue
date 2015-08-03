// DCMInfo.h: interface for the CDCMInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCMINFO_H__C17C9FA3_C493_49E4_9E22_32B7417DD68E__INCLUDED_)
#define AFX_DCMINFO_H__C17C9FA3_C493_49E4_9E22_32B7417DD68E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageFile;
class CDCMBasic;
class CDCMPatients;
class CDCMStudies;
class CDCMSeries;
class CDCMImages;

class CDCMInfo : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CDCMInfo)

public:
	CString				m_strFileSetID;				// File-set ID
	CString				m_strDescriptorFileID;		// File-set Descriptor File ID
	CString				m_strDescriptorCharacter;	// Specific Character Set of File-set Descriptor File
	Uint32				m_nFirstPosition;			// Position of the First Directory Record of the Root Directory Entity
	Uint32				m_nLastPosition;			// Position of the Last Directory Record of the Root Directory Entity
	Uint16				m_nConsistency;				// File-set Consistency Flag

public:
	CObFileHeader		m_obFileHeader;
	COBList<CDCMPatients>*m_pPatientsList;

public:
	LONG				m_nPatientsCount;
	LONG				m_nSeriesCount;
	LONG				m_nStudiesCount;
	LONG				m_nImagesCount;

private:
	CString				m_strDir;
	LONG				m_nFileNameIndex;

public:
	MRET				SetDir(LPCTSTR lpDir);
	LPCTSTR				GetNewFileName(CString& strFileName, CObImage* pObImage);
	LPCTSTR				GetNewFileName(CString& strFileName, CString& strStudyDate, CString& strAccessionNumber);

public:
	CDCMImages*			FindImage(CImageFile* pImageFile);
	MRET				AddImageFile(CImageFile* pImageFile);

public:
	MRET				SetMask();
	MRET				Load(LPCTSTR lpFileName);
	MRET				Built();

private:
	MRET				CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);
	MRET				Built			(COstreamFile* pIOstreamFile, CTransferSyntax* pTS);
	MRET				Parse			(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
	CDCMInfo();
	virtual ~CDCMInfo();
};


class CDCMBasic : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CDCMBasic)

public:
	Uint32				m_nNextPosition;				// Position of the Next Directory Record
	Uint16				m_nInUse;						// Record In-use Flag
	Uint32				m_nFirstPosition;				// Position of Referenced Lower-Level Directory Entity
	CString				m_strRecordType;				// Directory Record Type
	CString				m_strRecordUID;					// Private Record UID
	CString				m_strFileID;					// Referenced File ID
	Uint32				m_nMRDRPosition;				// MRDR Directory Record Position
	CString				m_strSOPClassUID;				// Referenced SOP Class UID in File
	CString				m_strSOPInstUID;				// Referenced SOP Instance UID in File
	CString				m_strTransferSyntax;			// Referenced Transfer Syntax UID in File
	Uint32				m_nReferenceNumber;				// Number of References

public:
	Uint32				m_nLength;

public:
	virtual E_DIRECTORY_RECORD	GetLevel()					{ return EDR_UNKNOWN; }
	virtual MRET		SetMask();

public:
	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);
	virtual MRET		Built			(COstreamFile* pIOstreamFile, CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
			MRET		ParseMRDR(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
	CDCMBasic();
	virtual ~CDCMBasic();
};


class CDCMPatients : public CDCMBasic  
{
	DECLARE_MEMBER_TABLE(CDCMPatients)

public:
	CString				m_strPatientsName;			// Patient's Name
	CString				m_strPatientsID;			// Patient ID
	CString				m_strPatientsDOB;			// Patient's Birth Date
	CString				m_strPatientsSex;			// Patient's Sex

public:
	CDCMInfo*			m_pParent;
	COBList<CDCMStudies>*m_pStudiesList;

public:
	LONG				m_nPatientsIndex;
	LONG				m_nPatientsStudies;
	LONG				m_nPatientsSeries;
	LONG				m_nPatientsImages;

public:
	virtual E_DIRECTORY_RECORD	GetLevel()					{ return EDR_PATIENT; }
	virtual MRET		SetMask();

public:
	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);
	virtual MRET		Built			(COstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
	CDCMPatients();
	virtual ~CDCMPatients();
};


class CDCMStudies : public CDCMBasic  
{
	DECLARE_MEMBER_TABLE(CDCMStudies)

public:
	CString				m_strStudiesInstUID;		// Study Instance UID
	CString				m_strStudiesDate;			// Study Date
	CString				m_strStudiesTime;			// Study Time
	CString				m_strAccessionNumber;		// Accession Number
	CString				m_strStudiesDescription;	// Study Description
	CString				m_strStudiesID;				// Study ID

public:
	CDCMPatients*		m_pParent;
	COBList<CDCMSeries>*m_pSeriesList;

public:
	LONG				m_nStudiesIndex;
	LONG				m_nStudiesSeries;
	LONG				m_nStudiesImages;

public:
	virtual E_DIRECTORY_RECORD	GetLevel()					{ return EDR_STUDY; }
	virtual MRET		SetMask();

public:
	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);
	virtual MRET		Built			(COstreamFile* pIOstreamFile, CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
	CDCMStudies();
	virtual ~CDCMStudies();
};


class CDCMSeries : public CDCMBasic  
{
	DECLARE_MEMBER_TABLE(CDCMSeries)

public:
	CString				m_strSeriesInstUID;			// Series Instance UID
	CString				m_strSeriesNumber;			// Series Number
	CString				m_strSeriesDate;			// Series Date
	CString				m_strSeriesTime;			// Series Time
	CString				m_strSeriesModality;		// Modality
	CString				m_strSeriesBodyPart;		// Body Part Examined
	CString				m_strSeriesFrameUID;		// Frame of Reference UID

public:
	CDCMStudies*		m_pParent;
	COBList<CDCMImages>*m_pImagesList;

public:
	LONG				m_nSeriesIndex;
	LONG				m_nSeriesImages;

public:
	virtual E_DIRECTORY_RECORD	GetLevel()					{ return EDR_SERIES; }
	virtual MRET		SetMask();

public:
	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);
	virtual MRET		Built			(COstreamFile* pIOstreamFile, CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
	CDCMSeries();
	virtual ~CDCMSeries();
};


class CDCMImages : public CDCMBasic  
{
	DECLARE_MEMBER_TABLE(CDCMImages)

public:
	CString				m_strImagesNumber;			// Instance Number
	CString				m_strImagesPhotometric;		// Photometric Interpretation
	Uint16				m_nImagesRows;				// Rows
	Uint16				m_nImagesColumns;			// Columns
	Uint16				m_nBitsAllocated;			// Bits Allocated
	Uint16				m_nBitsStored;				// Bits Stored
	CString				m_strImagePosition;			// Image Position (Patient)
	CString				m_strImageOrientation;		// Image Orientation (Patient)
	CString				m_strPixelSpacing;			// Pixel Spacing
	CString				m_strImagerPixelSpacing;	// Imager Pixel Spacing

public:
	CString				m_strSourceAETitle;

public:
	CDCMSeries*			m_pParent;

public:
	LONG				m_nImagesIndex;
	Uint32				m_nFileSize;
	CString				m_strFileName;
	CString				m_strOldFileName;
	CString				m_strUnarchiveFileName;
	CImageFile*			m_pImageFile;

public:
	virtual E_DIRECTORY_RECORD	GetLevel()					{ return EDR_IMAGE; }
	virtual MRET		SetMask();

public:
	virtual MRET		CalculateLength	(Uint32& nLength, CTransferSyntax* pTS);
	virtual MRET		Built			(COstreamFile* pIOstreamFile, CTransferSyntax* pTS);
	virtual MRET		Parse			(CIstreamFile* pIOstreamFile, CTransferSyntax* pTS);

public:
	CDCMImages();
	virtual ~CDCMImages();
};

#endif // !defined(AFX_DCMINFO_H__C17C9FA3_C493_49E4_9E22_32B7417DD68E__INCLUDED_)
