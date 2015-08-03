// RLEDecoder.h: interface for the CRLEDecoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RLEDECODER_H__A7F36081_7090_4C8B_A9AA_9C0F674671F4__INCLUDED_)
#define AFX_RLEDECODER_H__A7F36081_7090_4C8B_A9AA_9C0F674671F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRLEDecoder  
{
public:
	inline MRET FrameDecode(LPVOID lpvCompressed, Uint32 nCompressed)
	{
		if (nCompressed > 0)
		{
			if (lpvCompressed == NULL)
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
			}

			Uint8 nValue = 0;
			Uint8 nLength = 0;

			Uint8* lpValue = (Uint8*) lpvCompressed;

			if (this->m_nSuspendInfo > 128)
			{
				nLength = (Uint8) (257 - this->m_nSuspendInfo);

				this->m_nSuspendInfo = 128;

				nValue = *lpValue++;
				nCompressed--;

				MRET rc = this->Replicate(nValue, nLength);
				if (rc != ME_OK)
				{
					LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
				}
			}
			else if (this->m_nSuspendInfo < 128)
			{
				nLength = (Uint8) ((this->m_nSuspendInfo & 0x7f) + 1);

				this->m_nSuspendInfo = 128;
				if (nCompressed < nLength)
				{
					this->m_nSuspendInfo = (Uint8) (nLength - nCompressed - 1);
					nLength = (Uint8) nCompressed;
				}

				MRET rc = this->Literal(lpValue, nLength);
				if (rc != ME_OK)
				{
					LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
				}

				lpValue += nLength;
				nCompressed -= nLength;
			}

			while (nCompressed > 0)
			{
				nValue = *lpValue++;
				nCompressed--;

				if (nValue & 0x80)
				{
					if (nCompressed > 0)
					{
						nLength = (Uint8) (257 - nValue);
						nValue = *lpValue++;
						nCompressed--;
						MRET rc = this->Replicate(nValue, nLength);
						if (rc != ME_OK)
						{
							LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
						}
					}
					else
					{
						this->m_nSuspendInfo = nValue;
					}
				}
				else
				{
					nLength = (Uint8) ((nValue & 0x7f) + 1);
					if (nCompressed < nLength)
					{
						this->m_nSuspendInfo = (Uint8) (nLength - nCompressed - 1);
						nLength = (Uint8) nCompressed;
					}

					MRET rc = this->Literal(lpValue, nLength);
					if (rc != ME_OK)
					{
						LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
					}

					lpValue += nLength;
					nCompressed -= nLength;
				}
			}
		}

		return ME_OK;
	}

private:
	inline MRET Replicate(Uint8 nValue, Uint8 nLength)
	{
		if (this->m_nOffset + nLength > this->m_nLength)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		while (nLength--) this->m_lpOutput[this->m_nOffset++] = nValue;

		return ME_OK;
	}

	inline MRET Literal(Uint8* lpValue, Uint8 nLength)
	{
		if (this->m_nOffset + nLength > this->m_nLength)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		while (nLength--) this->m_lpOutput[m_nOffset++] = *lpValue++;

		return ME_OK;
	}

private:
	Uint32			m_nLength;
	Uint8*			m_lpOutput;
	Uint32			m_nOffset;
	Uint8			m_nSuspendInfo;

public:
	inline Uint32	GetSize()	{ return this->m_nOffset; }
	inline LPVOID	GetValue()	{ return this->m_lpOutput; }
	inline BOOL		Clear()		{ this->m_nOffset = 0; this->m_nSuspendInfo = 128; return TRUE; }
	inline BOOL		Suspended()	{ return (this->m_nSuspendInfo != 128); }

public:
	CRLEDecoder(Uint32 nLength)
	{
		this->m_nLength			= nLength;
		this->m_lpOutput		= CTools::Alloc(nLength);
		this->m_nOffset			= 0;
		this->m_nSuspendInfo	= 128;
	}

	virtual ~CRLEDecoder() { delete this->m_lpOutput; }
};

#endif // !defined(AFX_RLEDECODER_H__A7F36081_7090_4C8B_A9AA_9C0F674671F4__INCLUDED_)
