// RLEEncoder.h: interface for the CRLEEncoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RLEENCODER_H__520521CF_9BE2_457D_8779_9227FF628B89__INCLUDED_)
#define AFX_RLEENCODER_H__520521CF_9BE2_457D_8779_9227FF628B89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	RLE_ENCODER_BLOCKSIZE	0x4000

class CRLEEncoder  
{
public:
	inline void Add(Uint8 nValue)
	{
		if ((int) nValue == this->m_nRLEPrevious)
			this->m_nRLERepeatCount++;
		else
		{
			switch (this->m_nRLERepeatCount)
			{
			case 0:
				break;

            case 2:
				this->m_lpRLEBuffer[this->m_nRLEIndex++] = (Uint8) this->m_nRLEPrevious;
			case 1:
				this->m_lpRLEBuffer[this->m_nRLEIndex++] = (Uint8) this->m_nRLEPrevious;
				break;

			default:
				if (this->m_nRLEIndex > 1)
				{
					this->m_lpRLEBuffer[0] = (Uint8) (this->m_nRLEIndex - 2);
					this->Move(this->m_nRLEIndex);
				}

				this->m_lpRLEBuffer[1] = (Uint8) this->m_nRLEPrevious;
				for (; this->m_nRLERepeatCount > 0; this->m_nRLERepeatCount -= 128)
				{
					this->m_lpRLEBuffer[0] = (this->m_nRLERepeatCount > 128) ? 0x81 : (Uint8) (257 - this->m_nRLERepeatCount);
					this->Move(2);
				}

				this->m_lpRLEBuffer[0] = 0;
				this->m_nRLEIndex = 1;
				break;
			}

			if (this->m_nRLEIndex > 129)
			{
				this->m_lpRLEBuffer[0] = 127;
				this->Move(129);
				this->m_nRLEIndex -= 128;
				if (this->m_nRLEIndex > 1) this->m_lpRLEBuffer[1] = this->m_lpRLEBuffer[129];
				if (this->m_nRLEIndex > 2) this->m_lpRLEBuffer[2] = this->m_lpRLEBuffer[130];
			}

			this->m_nRLEPrevious = nValue;
			this->m_nRLERepeatCount = 1;
		}
    }

	inline void Add(Uint8* lpBuffer, Uint32 nLength)
	{
		if (lpBuffer != NULL)
			while (nLength-- > 0)
				this->Add(*lpBuffer++);
	}

	inline void Flush()
	{
		if (this->m_nRLERepeatCount < 2)
		{
			for (; this->m_nRLERepeatCount > 0; this->m_nRLERepeatCount--)
				this->m_lpRLEBuffer[this->m_nRLEIndex++] = (Uint8) this->m_nRLEPrevious;
		}

		if (this->m_nRLEIndex > 129)
		{
			this->m_lpRLEBuffer[0] = 127;
			this->Move(129);
			this->m_nRLEIndex -= 128;
			if (this->m_nRLEIndex > 1) this->m_lpRLEBuffer[1] = this->m_lpRLEBuffer[129];
			if (this->m_nRLEIndex > 2) this->m_lpRLEBuffer[2] = this->m_lpRLEBuffer[130];
		}

		if (this->m_nRLEIndex > 1)
		{
			this->m_lpRLEBuffer[0] = (Uint8) (this->m_nRLEIndex - 2);
			this->Move(this->m_nRLEIndex);
		}

		if (this->m_nRLERepeatCount >= 2)
		{
			this->m_lpRLEBuffer[1] = (Uint8) this->m_nRLEPrevious;
			for (; this->m_nRLERepeatCount > 0; this->m_nRLERepeatCount -= 128)
			{
				this->m_lpRLEBuffer[0] = (this->m_nRLERepeatCount > 128) ? 0x81 : (Uint8) (257 - this->m_nRLERepeatCount);
				this->Move(2);
			}
		}

		this->m_lpRLEBuffer[0] = 0;
		this->m_nRLEPrevious = -1;
		this->m_nRLERepeatCount = 0;
		this->m_nRLEIndex = 1;
    }

	inline Uint32 GetSize()
	{
		Uint32 nLength = this->m_pOutputList->GetSize() * RLE_ENCODER_BLOCKSIZE + this->m_nOffset;

		if (nLength & 1) nLength++;

		return nLength;
	}

	inline void Write(LPVOID lpBuffer)
	{
		Uint8* lpTarget = (Uint8*) lpBuffer;
		for (Uint8* lpCurrent = this->m_pOutputList->GetHead(); lpCurrent != NULL; lpCurrent = this->m_pOutputList->GetNext())
		{
			MEMCPY(lpTarget, lpCurrent, RLE_ENCODER_BLOCKSIZE);
			lpTarget += RLE_ENCODER_BLOCKSIZE;
		}

		if (this->m_nOffset > 0)
		{
			MEMCPY(lpTarget, this->m_lpOutput, this->m_nOffset);
			lpTarget += this->m_nOffset;
		}

		if ((this->m_pOutputList->GetSize() * RLE_ENCODER_BLOCKSIZE + this->m_nOffset) & 1)
			*lpTarget = 0;
	}

private:
	inline void Move(Uint32 nLength)
	{
		Uint32 i = 0;
		while (i < nLength)
		{
			if (this->m_nOffset == RLE_ENCODER_BLOCKSIZE)
			{
				this->m_pOutputList->AddTail(this->m_lpOutput);

				this->m_lpOutput = CTools::Alloc(RLE_ENCODER_BLOCKSIZE);
				this->m_nOffset = 0;
			}

			this->m_lpOutput[this->m_nOffset++] = this->m_lpRLEBuffer[i++];
		}
	}

	COBList<Uint8>*	m_pOutputList;
	Uint8*			m_lpOutput;
	Uint32			m_nOffset;
	Uint8*			m_lpRLEBuffer;
	Uint32			m_nRLEIndex;
	int				m_nRLEPrevious;
	int				m_nRLERepeatCount;

public:
	CRLEEncoder()
	{
		this->m_pOutputList		= new COBList<Uint8>;
		this->m_lpOutput		= CTools::Alloc(RLE_ENCODER_BLOCKSIZE);
		this->m_nOffset			= 0;
		this->m_lpRLEBuffer		= CTools::Alloc(132);
		this->m_nRLEIndex		= 1;
		this->m_nRLEPrevious	= -1;
		this->m_nRLERepeatCount	= 0;
	}

	virtual ~CRLEEncoder()
	{
		delete this->m_pOutputList;
		delete this->m_lpOutput;
		delete this->m_lpRLEBuffer;
	}
};

#endif // !defined(AFX_RLEENCODER_H__520521CF_9BE2_457D_8779_9227FF628B89__INCLUDED_)
