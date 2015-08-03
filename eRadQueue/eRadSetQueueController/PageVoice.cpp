// PageVoice.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageVoice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageVoice property page

IMPLEMENT_DYNCREATE(CPageVoice, CPropertyPage)

CPageVoice::CPageVoice() : CPropertyPage(CPageVoice::IDD)
{
	//{{AFX_DATA_INIT(CPageVoice)
	m_bVoiceEnable = FALSE;
	m_strVoiceFormat = _T("");
	m_nVoiceRepeat = 0;
	m_nVoiceInterval = 0;
	m_bpromptVoiceEnable = FALSE;
	m_bUseKdfx = FALSE;
	m_strSeriesId = _T("");
	//}}AFX_DATA_INIT

	this->m_pController = NULL;
}

CPageVoice::~CPageVoice()
{
}

void CPageVoice::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageVoice)
	DDX_Check(pDX, IDC_CHECK_VOICE_ENABLE, m_bVoiceEnable);
	DDX_Text(pDX, IDC_EDIT_VOICE_FORMAT, m_strVoiceFormat);
	DDX_Text(pDX, IDC_EDIT_VOICE_REPEAT, m_nVoiceRepeat);
	DDV_MinMaxUInt(pDX, m_nVoiceRepeat, 0, 10);
	DDX_Text(pDX, IDC_EDIT_VOICE_INTERVAL, m_nVoiceInterval);
	DDV_MinMaxUInt(pDX, m_nVoiceInterval, 0, 100);
	DDX_Check(pDX, IDC_CHECK_PROMPTVOICE_ENABLE, m_bpromptVoiceEnable);
	DDX_Check(pDX, IDC_CHECK_BUSEKDFX, m_bUseKdfx);
	DDX_Text(pDX, IDC_EDIT_SERIESID, m_strSeriesId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageVoice, CPropertyPage)
	//{{AFX_MSG_MAP(CPageVoice)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageVoice message handlers

BOOL CPageVoice::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
