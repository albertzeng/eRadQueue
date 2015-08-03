// IPixelTemplate.h: interface for the CIPixelTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPIXELTEMPLATE_H__677FD934_4BAB_40E1_9821_67EE39A1A733__INCLUDED_)
#define AFX_IPIXELTEMPLATE_H__677FD934_4BAB_40E1_9821_67EE39A1A733__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPixel.h"
#include "PixelTemplate.h"

template<class T1, class T2>
class CIPixelTemplate : public CIPixel, public CPixelTemplate<T2>  
{
private:
	inline Uint8	ToSintXX(Uint8  nValue, Uint8  SBit, Uint8  nMask)	{ return (nValue); }
	inline Uint16	ToSintXX(Uint16 nValue, Uint16 SBit, Uint16 nMask)	{ return (nValue); }
	inline Uint32	ToSintXX(Uint32 nValue, Uint32 SBit, Uint32 nMask)	{ return (nValue); }
	inline Sint8	ToSintXX(Sint8  nValue, Sint8  SBit, Sint8  nMask)	{ return (nValue & SBit) ? (nValue | nMask) : nValue; }
	inline Sint16	ToSintXX(Sint16 nValue, Sint16 SBit, Sint16 nMask)	{ return (nValue & SBit) ? (nValue | nMask) : nValue; }
	inline Sint32	ToSintXX(Sint32 nValue, Sint32 SBit, Sint32 nMask)	{ return (nValue & SBit) ? (nValue | nMask) : nValue; }
	inline MRET		GetPixelValue(CElement* pElement, Uint8*&  pValue)	{ return pElement->GetValueUint8A (pValue); }
	inline MRET		GetPixelValue(CElement* pElement, Uint16*& pValue)	{ return pElement->GetValueUint16A(pValue); }
	inline MRET		GetFrameValue(CElement* pElement, Uint32& nFrame, Uint8*&  pValue)	{ return ((CPixelElement*) pElement)->GetFrameUint08A(nFrame, pValue); }
	inline MRET		GetFrameValue(CElement* pElement, Uint32& nFrame, Uint16*& pValue)	{ return ((CPixelElement*) pElement)->GetFrameUint16A(nFrame, pValue); }

private:
	virtual MRET ReadPixel(CElement* pElement, Uint16 nBitsAllocated, Uint16 nBitsStored, Uint16 nHighBit)
	{
		Uint32 nCells = this->GetCellsCount();
		Uint32 nCancelCells = 0;
		T1* lpValue = NULL;
		register T1* lpSource = NULL;

		CPixelElement* pPixelElement = (CPixelElement*) pElement;
		if (pPixelElement->HaveDecoded())
		{
			if ((nCells * nBitsAllocated + 7) / 8 > pElement->GetLength())
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_BADDATA);
			}

			if (this->m_nFrame != (Uint32) (-1))
			{
				nCells = this->GetFrameCells();
				nCancelCells = this->GetFrameCells() * this->m_nFrame;
			}

			MRET rc = this->GetPixelValue(pElement, lpSource);
			if (rc != ME_OK)
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}
		}
		else
		{
			if (this->m_nFrame == (Uint32) (-1))
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
			}

			Uint32 nFrame = this->m_nFrame;
			MRET rc = this->GetFrameValue(pElement, nFrame, lpSource);
			if (rc != ME_OK)
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}

			if (nFrame == (Uint32) (-1))
			{
				delete lpSource;
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
			}

			nCells = this->GetFrameCells();
			lpValue = lpSource;
		}

		register LONG i = 0;

		const Uint16 nT1Bits = BITS(T1);
		const Uint16 nT2Bits = BITS(T2);

		T2 nSign = 1 << (nBitsStored - 1);
		Uint16 nOffsetBits = nHighBit + 1 - nBitsStored;
		T1 nMask = 0;
		for (i = 0; i < nBitsStored; i++) nMask |= (T1) (1 << i);
		T2 nSignMask = 0;
		for (i = nBitsStored; i < nT2Bits; i++) nSignMask |= (T2) (1 << i);

		this->m_lpValue = (T2*) CTools::Alloc((nCells + 16) * sizeof(T2));
		register T2* lpTarget = this->m_lpValue;

		if (nT1Bits == nBitsAllocated)
		{															// Case 1: Equal to 8/16 Bits
			lpSource += nCancelCells;

			if (nBitsStored == nBitsAllocated)
				for (i = nCells; i > 0; i--)
					*(lpTarget++) = (T2) *(lpSource++);
			else
			{
				if (nOffsetBits == 0)
					for (i = nCells; i > 0; i--)
						*(lpTarget++) = this->ToSintXX( (T2) (*(lpSource++) & nMask), nSign, nSignMask);
				else
					for (i = nCells; i > 0; i--)
						*(lpTarget++) = this->ToSintXX( (T2) ((*(lpSource++) >> nOffsetBits) & nMask), nSign, nSignMask);
			}
		}
		else if ((nT1Bits > nBitsAllocated) && (nT1Bits % nBitsAllocated == 0))
		{															// Case 2: Divisor of 8/16 Bits
			const Uint16 nTimes = nT1Bits / nBitsAllocated;

			lpSource += nCancelCells / nTimes;
			Uint32 nCancel = nCancelCells % nTimes;

			register Uint16 k = 0;
			register T1 nValue = 0;
			if ((nBitsStored == nBitsAllocated) && (nBitsStored == nT2Bits))
			{
				if (nTimes == 2)
				{
					if (nCancel > 0) *(lpTarget++) = (T2) (*(lpSource++) >> nBitsAllocated);

					for (i = nCells - nCancel; i > 0; i -= 2)
					{
						*(lpTarget++) = (T2) (*lpSource & nMask);
						*(lpTarget++) = (T2) (*(lpSource++) >> nBitsAllocated);
					}
				}
				else
				{
					if (nCancel > 0)
						for (k = nTimes, nValue = *(lpSource++); k != 0; k--, nValue >>= nBitsAllocated)
							if (k <= nTimes - nCancel)
								*(lpTarget++) = (T2) (nValue & nMask);

					for (i = nCells - nCancel; i > 0; i -= nTimes)
						for (k = nTimes, nValue = *(lpSource++); k != 0; k--, nValue >>= nBitsAllocated)
							*(lpTarget++) = (T2) (nValue & nMask);
				}
			}
			else
			{
				if (nCancel > 0)
					for (k = nTimes, nValue = *(lpSource++) >> nOffsetBits; k != 0; k--, nValue >>= nBitsAllocated)
						if (k <= nTimes - nCancel)
							*(lpTarget++) = this->ToSintXX( (T2) (nValue & nMask), nSign, nSignMask);

				for (i = nCells - nCancel; i > 0; i -= nTimes)
					for (k = nTimes, nValue = *(lpSource++) >> nOffsetBits; k != 0; k--, nValue >>= nBitsAllocated)
						*(lpTarget++) = this->ToSintXX( (T2) (nValue & nMask), nSign, nSignMask);
			}
		}
		else if ((nT1Bits < nBitsAllocated) && (nBitsAllocated % nT1Bits == 0) && (nBitsStored == nBitsAllocated))
		{															// Case 3: Multiplicant of 8/16 Bits
			const Uint16 nTimes = nBitsAllocated / nT1Bits;

			lpSource += nCancelCells * nTimes;

			register Uint16 k = 0;
			register T2 nValue = 0;
			for (i = nCells; i > 0; i--, lpSource += nTimes)
			{
				for (k = nTimes, nValue = 0; k > 0; k--)
					nValue = (nValue << nT1Bits) + *(lpSource + k - 1);
				*(lpTarget++) = nValue;
			}
		}
		else
		{															// Case 4: 
			register T2 nValue = 0;
			register Uint16 nBits = 0;
			register Uint32 nSkipBits = nHighBit + 1 - nBitsStored;

			nSkipBits += nCancelCells * nBitsAllocated;

			T1 nBitsMask[nT1Bits];
			for (nBitsMask[0] = 1, i = 1; i < nT1Bits; i++) nBitsMask[i] = (nBitsMask[i - 1] << 1) | 1;

			const Uint32 nGapBits = nBitsAllocated - nBitsStored;

			i = 0;
			while (i < nCells)
			{
				if (nSkipBits < nT1Bits)
				{
					if (nSkipBits + nBitsStored - nBits <= nT1Bits)
					{
						nValue |= ( ((T2) ((*lpSource >> nSkipBits) & nBitsMask[nBitsStored - nBits - 1])) << nBits );
						*(lpTarget++) = this->ToSintXX(nValue, nSign, nSignMask);
						i++;

						nSkipBits += nBitsStored - nBits + nGapBits;
						nBits = 0;
						nValue = 0;
					}
					else
					{
						nValue |= ( ((T2) ((*lpSource >> nSkipBits) & nBitsMask[nT1Bits - nSkipBits - 1])) << nBits );
						nBits += nT1Bits - nSkipBits;
						lpSource++;
						nSkipBits = 0;
					}
				}
				else
				{
					lpSource += (nSkipBits / nT1Bits);
					nSkipBits = (nSkipBits % nT1Bits);
				}
			}
		}

		delete lpValue;

		return ME_OK;
	}

public:
	virtual MRET CreatePixel(CImageFile* pImageFile, Uint32 nFrame, Uint16 nSamplesPerPixel, double dblCellsPerPixel)
	{
		MRET rc = CIPixel::CreatePixel(pImageFile, nFrame, nSamplesPerPixel, dblCellsPerPixel);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		if (this->UintXX())
		{
			this->m_dblAbsMinimum = +0.0;
			this->m_dblAbsMaximum = +(double) MAX_VALUE0(this->m_nBits);
		}
		else
		{
			this->m_dblAbsMinimum = -(double) MAX_VALUE1(this->m_nBits - 1);
			this->m_dblAbsMaximum = +(double) MAX_VALUE0(this->m_nBits - 1);
		}

		CElement* pElement = pImageFile->GetFileDataSet()->FindElement(DCM_PixelData);
		if (pElement == NULL)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_BADDATA);
		}

		rc = this->ReadPixel(pElement, pImageFile->GetBitsAllocated(), pImageFile->GetBitsStored(), pImageFile->GetHighBit());
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

protected:
	T2*	m_lpValue;

public:
	virtual E_PR	GetEPR()		{ return CPixelTemplate<T2>::GetEPR(); }
	virtual LPVOID	GetValue()		{ return this->m_lpValue; }
	virtual LPVOID	RemoveValue()	{ LPVOID lpvValue = this->m_lpValue; this->m_lpValue = NULL; return lpvValue; }

public:
	CIPixelTemplate()				{ this->m_lpValue = NULL; }
	virtual ~CIPixelTemplate()		{ delete this->m_lpValue; }
};

#endif // !defined(AFX_IPIXELTEMPLATE_H__677FD934_4BAB_40E1_9821_67EE39A1A733__INCLUDED_)
