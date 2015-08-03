// UID.h: interface for the CUID class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UID_H__10286869_FDB7_4207_B113_894139ABFE91__INCLUDED_)
#define AFX_UID_H__10286869_FDB7_4207_B113_894139ABFE91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	DCMUID_Verification								"1.2.840.10008.1.1"
#define	DCMUID_MediaStorageDirectory					"1.2.840.10008.1.3.10"
#define	DCMUID_BasicStudyContentNotification			"1.2.840.10008.1.9"
#define	DCMUID_StorageCommitmentPushModel				"1.2.840.10008.1.20.1"
#define	DCMUID_StorageCommitmentPushModelSOPInstance	"1.2.840.10008.1.20.1.1"
#define	DCMUID_DICOMControlledTerminologyCodingScheme	"1.2.840.10008.2.16.4"
#define	DCMUID_DICOMApplicationContextName				"1.2.840.10008.3.1.1.1"

#define	DCMUID_ImplicitVR								"1.2.840.10008.1.2"
#define	DCMUID_ExplicitVR								"1.2.840.10008.1.2.1"
#define	DCMUID_DeflatedExplicitVR						"1.2.840.10008.1.2.1.99"
#define	DCMUID_ExplicitVRBigEndian						"1.2.840.10008.1.2.2"
#define	DCMUID_JPEGBaseline50							"1.2.840.10008.1.2.4.50"
#define	DCMUID_JPEGExtended51							"1.2.840.10008.1.2.4.51"
#define	DCMUID_JPEGLossless57							"1.2.840.10008.1.2.4.57"
#define	DCMUID_JPEGLossless70							"1.2.840.10008.1.2.4.70"
#define	DCMUID_JPEGLSLossless80							"1.2.840.10008.1.2.4.80"
#define	DCMUID_JPEGLSLossy81							"1.2.840.10008.1.2.4.81"
#define	DCMUID_JPEG2000Lossless							"1.2.840.10008.1.2.4.90"
#define	DCMUID_JPEG2000									"1.2.840.10008.1.2.4.91"
#define	DCMUID_RLELossless								"1.2.840.10008.1.2.5"

#define	DCMUID_DetachedPatient							"1.2.840.10008.3.1.2.1.1"
#define	DCMUID_DetachedPatientMeta						"1.2.840.10008.3.1.2.1.4"
#define	DCMUID_DetachedVisit							"1.2.840.10008.3.1.2.2.1"
#define	DCMUID_DetachedStudy							"1.2.840.10008.3.1.2.3.1"
#define	DCMUID_StudyComponent							"1.2.840.10008.3.1.2.3.2"
#define	DCMUID_MPPS										"1.2.840.10008.3.1.2.3.3"
#define	DCMUID_MPPS_Retrieve							"1.2.840.10008.3.1.2.3.4"
#define	DCMUID_MPPS_Notification						"1.2.840.10008.3.1.2.3.5"
#define	DCMUID_DetachedResults							"1.2.840.10008.3.1.2.5.1"
#define	DCMUID_DetachedResultsMeta						"1.2.840.10008.3.1.2.5.4"
#define	DCMUID_DetachedStudyMeta						"1.2.840.10008.3.1.2.5.5"
#define	DCMUID_DetachedInterpretation					"1.2.840.10008.3.1.2.6.1"

#define	DCMUID_BasicFilmSession							"1.2.840.10008.5.1.1.1"
#define	DCMUID_BasicFilmBox								"1.2.840.10008.5.1.1.2"
#define	DCMUID_BasicGrayscaleImageBox					"1.2.840.10008.5.1.1.4"
#define	DCMUID_BasicColorImageBox						"1.2.840.10008.5.1.1.4.1"
#define	DCMUID_ReferencedImageBox_RET					"1.2.840.10008.5.1.1.4.2"
#define	DCMUID_BasicGrayscalePrintMeta					"1.2.840.10008.5.1.1.9"
#define	DCMUID_ReferencedGrayscalePrintMeta_RET			"1.2.840.10008.5.1.1.9.1"
#define	DCMUID_PrintJob									"1.2.840.10008.5.1.1.14"
#define	DCMUID_BasicAnnotationBox						"1.2.840.10008.5.1.1.15"
#define	DCMUID_Printer									"1.2.840.10008.5.1.1.16"
#define	DCMUID_PrinterConfiguration						"1.2.840.10008.5.1.1.16.376"
#define	DCMUID_PrinterSOPInstance						"1.2.840.10008.5.1.1.17"
#define	DCMUID_PrinterConfigurationSOPInstance			"1.2.840.10008.5.1.1.17.376"
#define	DCMUID_BasicColorPrintMeta						"1.2.840.10008.5.1.1.18"
#define	DCMUID_ReferencedColorPrintMeta_RET				"1.2.840.10008.5.1.1.18.1"
#define	DCMUID_VOILUTBox								"1.2.840.10008.5.1.1.22"
#define	DCMUID_PresentationLUT							"1.2.840.10008.5.1.1.23"
#define	DCMUID_ImageOverlayBox_RET						"1.2.840.10008.5.1.1.24"
#define	DCMUID_BasicPrintImageOverlayBox				"1.2.840.10008.5.1.1.24.1"
#define	DCMUID_PrintQueueSOPInstance					"1.2.840.10008.5.1.1.25"
#define	DCMUID_PrintQueue								"1.2.840.10008.5.1.1.26"
#define	DCMUID_StoredPrint								"1.2.840.10008.5.1.1.27"
#define	DCMUID_HardcopyGrayscaleImage					"1.2.840.10008.5.1.1.29"
#define	DCMUID_HardcopyColorImage						"1.2.840.10008.5.1.1.30"
#define	DCMUID_PullPrintRequest							"1.2.840.10008.5.1.1.31"
#define	DCMUID_PullStoredPrintMeta						"1.2.840.10008.5.1.1.32"

#define	DCMUID_ComputedRadiographyImage					"1.2.840.10008.5.1.4.1.1.1"
#define	DCMUID_DigitalXRayImage_PRES					"1.2.840.10008.5.1.4.1.1.1.1"
#define	DCMUID_DigitalXRayImage_PROC					"1.2.840.10008.5.1.4.1.1.1.1.1"
#define	DCMUID_DigitalMammographyXRayImage_PRES			"1.2.840.10008.5.1.4.1.1.1.2"
#define	DCMUID_DigitalMammographyXRayImage_PROC			"1.2.840.10008.5.1.4.1.1.1.2.1"
#define	DCMUID_DigitalIntraOralXRayImage_PRES			"1.2.840.10008.5.1.4.1.1.1.3"
#define	DCMUID_DigitalIntraOralXRayImage_PROC			"1.2.840.10008.5.1.4.1.1.1.3.1"
#define	DCMUID_CTImage									"1.2.840.10008.5.1.4.1.1.2"
#define	DCMUID_Ultrasound_MF_Image_RET					"1.2.840.10008.5.1.4.1.1.3"
#define	DCMUID_Ultrasound_MF_Image						"1.2.840.10008.5.1.4.1.1.3.1"
#define	DCMUID_MRImage									"1.2.840.10008.5.1.4.1.1.4"
#define	DCMUID_EnhancedMRImage							"1.2.840.10008.5.1.4.1.1.4.1"
#define	DCMUID_MRSpectroscopy							"1.2.840.10008.5.1.4.1.1.4.2"
#define	DCMUID_NuclearMedicineImage_RET					"1.2.840.10008.5.1.4.1.1.5"
#define	DCMUID_UltrasoundImage_RET						"1.2.840.10008.5.1.4.1.1.6"
#define	DCMUID_UltrasoundImage							"1.2.840.10008.5.1.4.1.1.6.1"
#define	DCMUID_SC_Image									"1.2.840.10008.5.1.4.1.1.7"
#define	DCMUID_MF_SingleBit_SC_Image					"1.2.840.10008.5.1.4.1.1.7.1"
#define	DCMUID_MF_GrayscaleByte_SC_Image				"1.2.840.10008.5.1.4.1.1.7.2"
#define	DCMUID_MF_GrayscaleWord_SC_Image				"1.2.840.10008.5.1.4.1.1.7.3"
#define	DCMUID_MF_TrueColor_SC_Image					"1.2.840.10008.5.1.4.1.1.7.4"
#define	DCMUID_StandaloneOverlay						"1.2.840.10008.5.1.4.1.1.8"
#define	DCMUID_StandaloneCurve							"1.2.840.10008.5.1.4.1.1.9"
#define	DCMUID_12LeadECGWaveform						"1.2.840.10008.5.1.4.1.1.9.1.1"
#define	DCMUID_GeneralECGWaveform						"1.2.840.10008.5.1.4.1.1.9.1.2"
#define	DCMUID_AmbulatoryECGWaveform					"1.2.840.10008.5.1.4.1.1.9.1.3"
#define	DCMUID_HemodynamicWaveform						"1.2.840.10008.5.1.4.1.1.9.2.1"
#define	DCMUID_CardiacElectrophysiologyWaveform			"1.2.840.10008.5.1.4.1.1.9.3.1"
#define	DCMUID_BasicVoiceAudioWaveform					"1.2.840.10008.5.1.4.1.1.9.4.1"
#define	DCMUID_StandaloneModalityLUT					"1.2.840.10008.5.1.4.1.1.10"
#define	DCMUID_StandaloneVOILUT							"1.2.840.10008.5.1.4.1.1.11"
#define	DCMUID_GrayscaleSoftcopyPresentationState		"1.2.840.10008.5.1.4.1.1.11.1"
#define	DCMUID_XRayAngiographicImage					"1.2.840.10008.5.1.4.1.1.12.1"
#define	DCMUID_XRayRadiofluoroscopicImage				"1.2.840.10008.5.1.4.1.1.12.2"
#define	DCMUID_XRayAngiographicBiPlaneImage_RET			"1.2.840.10008.5.1.4.1.1.12.3"
#define	DCMUID_NuclearMedicineImage						"1.2.840.10008.5.1.4.1.1.20"
#define	DCMUID_RawData									"1.2.840.10008.5.1.4.1.1.66"
#define	DCMUID_VLImage_RET								"1.2.840.10008.5.1.4.1.1.77.1"
#define	DCMUID_VLEndoscopicImage						"1.2.840.10008.5.1.4.1.1.77.1.1"
#define	DCMUID_VLMicroscopicImage						"1.2.840.10008.5.1.4.1.1.77.1.2"
#define	DCMUID_VLSlideCoordinatesMicroscopicImage		"1.2.840.10008.5.1.4.1.1.77.1.3"
#define	DCMUID_VLPhotographicImage						"1.2.840.10008.5.1.4.1.1.77.1.4"
#define	DCMUID_VL_MF_Image_RET							"1.2.840.10008.5.1.4.1.1.77.2"
#define	DCMUID_BasicTextSR								"1.2.840.10008.5.1.4.1.1.88.11"
#define	DCMUID_EnhancedSR								"1.2.840.10008.5.1.4.1.1.88.22"
#define	DCMUID_ComprehensiveSR							"1.2.840.10008.5.1.4.1.1.88.33"
#define	DCMUID_MammographyCADSR							"1.2.840.10008.5.1.4.1.1.88.50"
#define	DCMUID_KeyObjectSelectionDocument				"1.2.840.10008.5.1.4.1.1.88.59"
#define	DCMUID_ChestCADSR								"1.2.840.10008.5.1.4.1.1.88.65"
#define	DCMUID_PositronEmissionTomographyImage			"1.2.840.10008.5.1.4.1.1.128"
#define	DCMUID_StandalonePETCurve						"1.2.840.10008.5.1.4.1.1.129"
#define	DCMUID_RTImage									"1.2.840.10008.5.1.4.1.1.481.1"
#define	DCMUID_RTDose									"1.2.840.10008.5.1.4.1.1.481.2"
#define	DCMUID_RTStructureSet							"1.2.840.10008.5.1.4.1.1.481.3"
#define	DCMUID_RTBeamsTreatmentRecord					"1.2.840.10008.5.1.4.1.1.481.4"
#define	DCMUID_RTPlan									"1.2.840.10008.5.1.4.1.1.481.5"
#define	DCMUID_RTBrachyTreatmentRecord					"1.2.840.10008.5.1.4.1.1.481.6"
#define	DCMUID_RTTreatmentSummaryRecord					"1.2.840.10008.5.1.4.1.1.481.7"

#define	DCMUID_PR_QR_FIND								"1.2.840.10008.5.1.4.1.2.1.1"
#define	DCMUID_PR_QR_MOVE								"1.2.840.10008.5.1.4.1.2.1.2"
#define	DCMUID_PR_QR_GET								"1.2.840.10008.5.1.4.1.2.1.3"
#define	DCMUID_SR_QR_FIND								"1.2.840.10008.5.1.4.1.2.2.1"
#define	DCMUID_SR_QR_MOVE								"1.2.840.10008.5.1.4.1.2.2.2"
#define	DCMUID_SR_QR_GET								"1.2.840.10008.5.1.4.1.2.2.3"
#define	DCMUID_PS_QR_FIND								"1.2.840.10008.5.1.4.1.2.3.1"
#define	DCMUID_PS_QR_MOVE								"1.2.840.10008.5.1.4.1.2.3.2"
#define	DCMUID_PS_QR_GET								"1.2.840.10008.5.1.4.1.2.3.3"
#define	DCMUID_MWL_FIND									"1.2.840.10008.5.1.4.31"
#define	DCMUID_GPWL_FIND								"1.2.840.10008.5.1.4.32.1"
#define	DCMUID_GSPS										"1.2.840.10008.5.1.4.32.2"
#define	DCMUID_GPPS										"1.2.840.10008.5.1.4.32.3"
#define	DCMUID_GPWL_META								"1.2.840.10008.5.1.4.32"


class CUID  
{
public:
	struct CSingleUID
	{
		LPCTSTR			lpUID;
		LPCTSTR			lpName;
	};

public:
	static LPCTSTR		FindName(LPCTSTR lpUID);
	static BOOL			IsImageSOPClassUID(LPCTSTR lpUID);
	static BOOL			IsStorageSOPClassUID(LPCTSTR lpUID);

public:
	CUID();
	virtual ~CUID();
};


class CTransferSyntax  
{
public:
	struct CSingleTS
	{
		E_TS			eTS;
		LPCTSTR			lpUID;
		BOOL			bLittleEndian;
		BOOL			bImplicitVR;
		BOOL			bEncapsulated;
		e_streamCompression	estreamCompression;
	};

private:
	E_TS				m_eTS;
	LPCTSTR				m_lpUID;
	BOOL				m_bLittleEndian;
	BOOL				m_bImplicitVR;
	BOOL				m_bEncapsulated;
	e_streamCompression	m_estreamCompression;

public:
	CTransferSyntax& operator =(E_TS eTS);
	CTransferSyntax& operator =(CTransferSyntax& TS);

	E_TS				GetETS()			{ return m_eTS; }
	LPCTSTR				GetUID()			{ return m_lpUID; }
	LPCTSTR				GetName();
	BOOL				IsLittleEndian()	{ return m_bLittleEndian; }
	BOOL				IsImplicitVR()		{ return m_bImplicitVR; }
	BOOL				IsEncapsulated()	{ return m_bEncapsulated; }
	e_streamCompression	GetESC()			{ return m_estreamCompression; }

	Uint32				GetElementHeaderSize(E_VR eVR);

public:
	CTransferSyntax(E_TS eTS);
	CTransferSyntax(LPCTSTR lpUID);
	CTransferSyntax(CTransferSyntax& TS);
	CTransferSyntax();
	virtual ~CTransferSyntax();
};

#endif // !defined(AFX_UID_H__10286869_FDB7_4207_B113_894139ABFE91__INCLUDED_)
