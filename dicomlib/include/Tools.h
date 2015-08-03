// Tools.h: interface for the CTools class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLS_H__47BB79B2_5E35_45FD_AC3B_717106B922DA__INCLUDED_)
#define AFX_TOOLS_H__47BB79B2_5E35_45FD_AC3B_717106B922DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	DCM_ACCEPTABLE_AS_FILE		_T("Abstract.ini")

class CTools  
{
public:
	static	LPBYTE		Alloc(Uint32 nLength);

public:
	static	BOOL		IsLittleMachine();
	static	BOOL		CheckLocalMachine();

public:
	static	MRET		BuiltTAG(COstream* pIOstream, CTAG* pTAG, CTransferSyntax* pTS);

public:
	static	Uint32		STRGetVM(LPCTSTR lpValue);
	static	LPSTR		STRGetFirstValue(LPCTSTR& lpValue);

public:
	static	MRET		Swap(Uint16* pValue);
	static	MRET		Swap(Uint32* pValue);
	static	Uint16		SwapShort(Uint16 nValue);
	static	MRET		Swap2Bytes(LPBYTE lpValue);
	static	MRET		Swap4Bytes(LPBYTE lpValue);
	static	MRET		SwapNBytes(LPVOID lpvValue, Uint32 nBytesLength, Uint32 nUnitLength);
	static	MRET		Swap(BOOL bNewLittle, BOOL bOldLittle, LPVOID lpvValue, Uint32 nBytesLength, Uint32 nUnitLength);
	static	E_PI		GetEPI(LPCTSTR lpPhotometric);
	static	LPCTSTR		GetPhotometric(E_PI ePhotometric);
	static	MRET		BuiltAcceptableAS();

public:
	static	LPCTSTR		FormatDA(CString& strDate);
	static	LPCTSTR		FormatTM(CString& strTime);
	static	LPCTSTR		FormatDateTime(CString& strDateTime, LPCTSTR lpDate, LPCTSTR lpTime);
	static	LPCTSTR		FormatDateTime(CString& strDateTime, LPCTSTR lpDateTime);

	static	LPCTSTR		GetEnglishName(CString& strEnglishName, LPCTSTR lpDicomName);
	static	LPCTSTR		GetChineseName(CString& strChineseName, LPCTSTR lpDicomName);

public:
	CTools();
	virtual ~CTools();
};


class CCounter  
{
protected:
	Uint32					m_nCounter;

public:
	void					AddRef()	{ ++m_nCounter; }
	void					Release()	{ if (--m_nCounter == 0) delete this; }

public:
	CCounter()				{ m_nCounter = 1; }
	virtual ~CCounter()		{}
};


class CFileStorage  
{
public:
	CString			m_strFileStorage;
	Uint32			m_nRefuseSpace;

public:
	MRET			SetFileStorage(LPCTSTR lpFileStorage, Uint32 nRefuseSpace);

public:
	CFileStorage();
	virtual ~CFileStorage();
};


class CAcceptableAS  
{
public:
	CString					m_strAS;
	STRING_ARRAY			m_aAcceptableTS;

public:
	CAcceptableAS()			{}
	virtual ~CAcceptableAS(){}
};


#ifdef  __cplusplus
extern "C" {
#endif

extern void * DogData;
extern short int DogAddr;
extern short int DogBytes;
extern unsigned long NewPassword;
extern unsigned long DogPassword;
extern unsigned long DogResult;
extern unsigned char DogCascade;

extern unsigned long DogCheck(void);
extern unsigned long DogConvert(void);
extern unsigned long WriteDog(void);
extern unsigned long ReadDog(void);
extern unsigned long GetCurrentNo(void);
extern unsigned long DisableShare(void);
extern unsigned long SetPassword(void);
extern unsigned long SetDogCascade(void);

#ifdef  __cplusplus
}
#endif


class CSoftSafe  
{
public:
	Uint32			m_nSerialNo;
	Uint32			m_nPass;
	Uint8			m_nCascade;
	UINT32_ARRAY	m_AcceptableSerialNo;

public:
	static	MRET	SetSerialNo(Uint32 nSerialNo);

public:
	static	MRET	CheckSoftSafe();
	static	MRET	GetCurrentNo(Uint32& nCurrentNo);
	static	MRET	GetValue(Uint32 nAddress, LPVOID lpvBuffer, Uint32 nLength);
	static	MRET	SetValue(Uint32 nAddress, LPVOID lpvBuffer, Uint32 nLength);
	static	MRET	Convert	(Uint32& nResult, LPVOID lpvBuffer, Uint32 nLength);

public:
	CSoftSafe();
	virtual ~CSoftSafe();
};

#endif // !defined(AFX_TOOLS_H__47BB79B2_5E35_45FD_AC3B_717106B922DA__INCLUDED_)
