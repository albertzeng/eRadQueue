// IOstream.h: interface for the CIOstream class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IOSTREAM_H__AC558E5C_F52F_478E_B1B4_3751A9E1806C__INCLUDED_)
#define AFX_IOSTREAM_H__AC558E5C_F52F_478E_B1B4_3751A9E1806C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


///////////////////////////////////////////////////////////////////////////////
extern "C"
{
#include "zlib.h"
}

#if MAX_MEM_LEVEL >= 8
#define	DEF_MEM_LEVEL	8
#else
#define	DEF_MEM_LEVEL	MAX_MEM_LEVEL
#endif
///////////////////////////////////////////////////////////////////////////////


#define	IOSTREAM_READ(pIOstream, lpvBuffer, nLength)				\
	{																\
		MRET rc = (pIOstream)->Read((LPVOID) (lpvBuffer), nLength);	\
		if (rc != ME_OK)											\
		{															\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
	}																\


#define	IOSTREAM_SKIP(pIOstream, nLength)							\
	{																\
		MRET rc = (pIOstream)->Skip(nLength);						\
		if (rc != ME_OK)											\
		{															\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
	}																\


#define	IOSTREAM_WRITE(pIOstream, lpvBuffer, nLength)				\
	{																\
		MRET rc = (pIOstream)->Write((LPVOID) (lpvBuffer), nLength);\
		if (rc != ME_OK)											\
		{															\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
	}																\


class CIProducer;
class CIFilter;
class CIFilterZlib;
class COConsumer;
class COFilter;
class COFilterZlib;
class CPDUPDataTF;
class CService;

class CIstream  
{
private:
	CIProducer*			m_pProducer;		// Reference
	CIFilter*			m_pCompressionFilter;
	Uint32				m_nLength;
	Uint32				m_nMark;

public:
	virtual BOOL		EOS();
	virtual Uint32		Available();
	virtual MRET		Read(LPVOID lpvBuffer, Uint32 nLength);
	virtual MRET		Skip(Uint32 nLength);
	virtual Uint32		Mark();
	virtual MRET		Back();
	virtual	MRET		Seek(Uint32 nLength);

public:
	virtual Uint32		GetLength()			{ return this->m_nLength; }
	virtual MRET		InstallCompressionFilter(e_streamCompression estreamCompression);

protected:
	virtual	CIProducer*	CurrentProducer()	{ return this->m_pProducer; }

public:
	CIstream(CIProducer* pProducer);
	CIstream();
	virtual ~CIstream();
};


class CIProducer  
{
public:
	virtual BOOL		EOS() = 0;
	virtual Uint32		Available() = 0;
	virtual MRET		Read(LPVOID lpvBuffer, Uint32 nLength, Uint32& nReadLength) = 0;
	virtual MRET		Skip(Uint32 nLength) = 0;
	virtual MRET		Back(Uint32 nLength) = 0;

public:
	CIProducer() {}
	virtual ~CIProducer() {}
};


class CIFilter : public CIProducer  
{
public:
	virtual MRET		Append(CIProducer* pProducer) = 0;

public:
	CIFilter() {}
	virtual ~CIFilter() {}
};


class CIProducerBuffer : public CIProducer  
{
private:
	BOOL				m_bEOS;
	LPBYTE				m_lpBuffer;
	Uint32				m_nBufferSize;
	Uint32				m_nBufferBack;
	LPBYTE				m_lpBackup;
	Uint32				m_nBackupCount;
	Uint32				m_nBackupBack;

public:
	virtual BOOL		EOS()				{ return (this->m_bEOS && (this->Available() == 0)); }
	virtual Uint32		Available()			{ return (this->m_nBackupCount + this->m_nBufferSize - this->m_nBufferBack); }
	virtual MRET		Read(LPVOID lpvBuffer, Uint32 nLength, Uint32& nReadLength);
	virtual MRET		Skip(Uint32 nLength);
	virtual MRET		Back(Uint32 nLength);

public:
	virtual BOOL		SetEOS();
	virtual MRET		ReleaseBuffer();
	virtual MRET		SetBuffer(LPVOID lpvBuffer, Uint32 nLength);

public:
	CIProducerBuffer();
	virtual ~CIProducerBuffer();
};


class CIstreamBuffer : public CIstream  
{
private:
	CIProducerBuffer	m_ProducerBuffer;

public:
	virtual BOOL		SetEOS()			{ return this->m_ProducerBuffer.SetEOS(); }
	virtual MRET		ReleaseBuffer()		{ return this->m_ProducerBuffer.ReleaseBuffer(); }
	virtual MRET		SetBuffer(LPVOID lpvBuffer, Uint32 nLength);

public:
	CIstreamBuffer();
	virtual ~CIstreamBuffer();
};


class CIProducerFile : public CIProducer  
{
private:
	HANDLE				m_hFile;
	HANDLE				m_hMapFile;
	LPBYTE				m_lpFile;
	Uint32				m_nFileSize;
	Uint32				m_nCurrent;

public:
			MRET		Initialize(LPCTSTR lpFileName);
			MRET		GetRemains(LPVOID& lpvBuffer, Uint32& nLength);

public:
	virtual BOOL		EOS()				{ return (this->m_nFileSize == this->m_nCurrent); }
	virtual Uint32		Available()			{ return (this->m_nFileSize - this->m_nCurrent); }
	virtual MRET		Read(LPVOID lpvBuffer, Uint32 nLength, Uint32& nReadLength);
	virtual MRET		Skip(Uint32 nLength);
	virtual MRET		Back(Uint32 nLength);

public:
	CIProducerFile();
	virtual ~CIProducerFile();
};


class CIstreamFile : public CIstream  
{
private:
	CString				m_strFileName;
	CIProducerFile		m_ProducerFile;

public:
	virtual	MRET		Initialize(LPCTSTR lpFileName, Uint32 nOffset = 0);
			MRET		GetRemains(LPVOID& lpvBuffer, Uint32& nLength);

public:
	CIstreamFile();
	virtual ~CIstreamFile();
};


#pragma pack(1)

class CIProducerNetwork : public CIProducer  
{
private:
	struct CPrePDV {
		Uint32		Len;
		BYTE		ContextID;
		BYTE		ControlHeader;
	};

	FILE*				m_fileTrack;	// Track the communication
	CPDUPDataTF*		m_pPDataTF;		// Reference
	CService*			m_pService;		// Reference
	Uint32				m_nReceiveLength;
	BOOL				m_bEOS;
	LPBYTE				m_lpBuffer;
	Uint32				m_nBufferSize;
	Uint32				m_nBufferBack;
	LPBYTE				m_lpBackup;
	Uint32				m_nBackupCount;
	Uint32				m_nBackupBack;

public:
			MRET		Initialize(CPDUPDataTF* pPDataTF, CService* pService = NULL);

public:
	virtual BOOL		EOS()				{ return (this->m_bEOS && (this->Available() == 0)); }
	virtual Uint32		Available()			{ return (this->m_nBackupCount + this->m_nBufferSize - this->m_nBufferBack); }
	virtual MRET		Read(LPVOID lpvBuffer, Uint32 nLength, Uint32& nReadLength);
	virtual MRET		Skip(Uint32 nLength);
	virtual MRET		Back(Uint32 nLength);

private:
			MRET		Receive();

public:
	CIProducerNetwork();
	virtual ~CIProducerNetwork();
};

#pragma pack()


class CIstreamNetwork : public CIstream  
{
private:
	CIProducerNetwork	m_ProducerNetwork;

public:
			MRET		Initialize(CPDUPDataTF* pPDataTF, CService* pService = NULL);

public:
	CIstreamNetwork();
	virtual ~CIstreamNetwork();
};


class CIFilterZlib : public CIFilter  
{
private:
	z_streamp			m_pZlibStream;
	CIProducer*			m_pProcuder;
	BOOL				m_bEOS;
	BOOL				m_bPadded;
	LPBYTE				m_lpInput;
	Uint32				m_nInputStart;
	Uint32				m_nInputCount;
	LPBYTE				m_lpOutput;
	Uint32				m_nOutputStart;
	Uint32				m_nOutputCount;
	Uint32				m_nOutputBack;

public:
			MRET		Initialize();

public:
	virtual BOOL		EOS()				{ return (this->m_bEOS && this->m_nOutputCount == 0); }
	virtual Uint32		Available()			{ return this->m_nOutputCount; }
	virtual MRET		Read(LPVOID lpvBuffer, Uint32 nLength, Uint32& nReadLength);
	virtual MRET		Skip(Uint32 nLength);
	virtual MRET		Back(Uint32 nLength);
	virtual MRET		Append(CIProducer* pProducer);

private:
			MRET		Decode(LPBYTE lpBuffer, Uint32 nLength, Uint32& nDecodeLength);
			MRET		FillInputBuffer(Uint32& nInputLength);
			MRET		FillOutputBuffer();

public:
	CIFilterZlib();
	virtual ~CIFilterZlib();
};


class COstream  
{
private:
	COConsumer*			m_pConsumer;
	COFilter*			m_pCompressionFilter;
	Uint32				m_nLength;

public:
	virtual MRET		Flush();
	virtual BOOL		IsFlushed();
	virtual Uint32		Available();
	virtual	MRET		Write(LPVOID lpvBuffer, Uint32 nLength);

public:
	virtual Uint32		GetLength()			{ return this->m_nLength; }
	virtual MRET		InstallCompressionFilter(e_streamCompression estreamCompression);

public:
	COstream(COConsumer* pConsumer);
	COstream();
	virtual ~COstream();
};


class COConsumer  
{
public:
	virtual	MRET		Flush() = 0;
	virtual BOOL		IsFlushed() = 0;
	virtual Uint32		Available() = 0;
	virtual MRET		Write(LPVOID lpvBuffer, Uint32 nLength) = 0;

public:
	COConsumer() {}
	virtual ~COConsumer() {}
};


class COFilter : public COConsumer  
{
public:
	virtual	MRET		Append(COConsumer* pConsumer) = 0;

public:
	COFilter() {}
	virtual ~COFilter() {}
};


class COConsumerBuffer : public COConsumer  
{
private:
	LPBYTE				m_lpBuffer;
	Uint32				m_nBufferSize;
	Uint32				m_nBufferFilled;

public:
	virtual MRET		FlushBuffer(LPVOID& lpvBuffer, Uint32& nLength);

public:
	virtual	MRET		Flush()				{ return ME_OK; }
	virtual BOOL		IsFlushed()			{ return (this->m_nBufferFilled == 0); }
	virtual Uint32		Available()			{ return (this->m_nBufferSize - this->m_nBufferFilled); }
	virtual MRET		Write(LPVOID lpvBuffer, Uint32 nLength);

public:
	COConsumerBuffer(Uint32 nLength);
	virtual ~COConsumerBuffer();
};


class COstreamBuffer : public COstream  
{
private:
	COConsumerBuffer	m_ConsumerBuffer;

public:
	virtual MRET		FlushBuffer(LPVOID& lpvBuffer, Uint32& nLength);

public:
	COstreamBuffer(Uint32 nLength);
	virtual ~COstreamBuffer();
};


class COConsumerFile : public COConsumer  
{
private:
	HANDLE				m_hFile;
	LPBYTE				m_lpBuffer;
	Uint32				m_nBufferSize;
	Uint32				m_nBufferFilled;

public:
	virtual MRET		SetFile(HANDLE hFile);

public:
	virtual	MRET		Flush();
	virtual BOOL		IsFlushed()			{ return (this->m_nBufferFilled == 0); }
	virtual Uint32		Available()			{ return (Uint32) -1; }
	virtual MRET		Write(LPVOID lpvBuffer, Uint32 nLength);

public:
	COConsumerFile();
	virtual ~COConsumerFile();
};


class COstreamFile : public COstream  
{
private:
	COConsumerFile		m_ConsumerFile;

public:
	virtual MRET		SetFile(HANDLE hFile)	{ return this->m_ConsumerFile.SetFile(hFile); }

public:
	COstreamFile();
	virtual ~COstreamFile();
};


class COFilterZlib : public COFilter  
{
private:
	z_streamp			m_pZlibStream;
	COConsumer*			m_pConsumer;
	BOOL				m_bFlushed;
	LPBYTE				m_lpInput;
	Uint32				m_nInputStart;
	Uint32				m_nInputCount;
	LPBYTE				m_lpOutput;
	Uint32				m_nOutputStart;
	Uint32				m_nOutputCount;

public:
			MRET		Initialize(LONG nLevel = Z_DEFAULT_COMPRESSION);

public:
	virtual	MRET		Flush();
	virtual BOOL		IsFlushed();
	virtual Uint32		Available();
	virtual MRET		Write(LPVOID lpvBuffer, Uint32 nLength);
	virtual	MRET		Append(COConsumer* pConsumer);

private:
			MRET		Encode(LPBYTE lpBuffer, Uint32 nLength, BOOL bFinalize, Uint32& nEncodeLength);
			MRET		EncodeInputBuffer(BOOL bFinalize);
			MRET		FlushOutputBuffer();

public:
	COFilterZlib();
	virtual ~COFilterZlib();
};

#endif // !defined(AFX_IOSTREAM_H__AC558E5C_F52F_478E_B1B4_3751A9E1806C__INCLUDED_)
