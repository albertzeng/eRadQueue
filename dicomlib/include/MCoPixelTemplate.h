// MCoPixelTemplate.h: interface for the CMCoPixelTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCOPIXELTEMPLATE_H__6B17AB4A_2964_4743_8554_573EE4ED4A83__INCLUDED_)
#define AFX_MCOPIXELTEMPLATE_H__6B17AB4A_2964_4743_8554_573EE4ED4A83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MPixel.h"
#include "PixelTemplate.h"

class CLUTTable;

template<class T>
class CMCoPixelTemplate : public CMCoPixel, public CPixelTemplate<T>  
{
protected:
	inline Uint8	ToUintXX(Uint8  nValue, Uint8  nOffValue)	{ return nValue; }
	inline Uint16	ToUintXX(Uint16 nValue, Uint16 nOffValue)	{ return nValue; }
	inline Uint32	ToUintXX(Uint32 nValue, Uint32 nOffValue)	{ return nValue; }
	inline Uint8	ToUintXX(Sint8  nValue, Sint8  nOffValue)	{ return (Uint8 ) ((Sint32) nValue + (Sint32) nOffValue + 1); }
	inline Uint16	ToUintXX(Sint16 nValue, Sint16 nOffValue)	{ return (Uint16) ((Sint32) nValue + (Sint32) nOffValue + 1); }

public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL)
	{
		MRET rc = CMCoPixel::CreatePixel(pImageFile, pIPixel);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		this->m_nBits = *((Uint16*) lpvParameter);
		this->m_dblAbsMinimum = 0;
		this->m_dblAbsMaximum = MAX_VALUE0(this->m_nBits);

		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		for (Uint32 i = 0; i < 3; i++) this->m_lpValue[i] = (T*) CTools::Alloc(nSize * sizeof(T));

		return ME_OK;
	}

	virtual MRET GetFrame(LPVOID& lpvBuffer, Uint32 nFrame, BOOL bPlane = FALSE)
	{
		if (this->m_nFrame != (Uint32) (-1))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_BADPARAMETER);
		}

		T* lpBuffer = new T[this->GetFrameSize() * 3];
		if (bPlane)
		{
			for (Uint32 i = 0; i < 3; i++)
				MEMCPY(this->m_lpValue[i] + nFrame * this->GetFrameSize(), lpBuffer + i * this->GetFrameSize(), this->GetFrameSize() * sizeof(T));
		}
		else
		{
			register T* lpTarget = lpBuffer;
			register T* lpPlane0 = this->m_lpValue[0] + nFrame * this->GetFrameSize();
			register T* lpPlane1 = this->m_lpValue[1] + nFrame * this->GetFrameSize();
			register T* lpPlane2 = this->m_lpValue[2] + nFrame * this->GetFrameSize();
			for (Uint32 i = this->GetFrameSize(); i != 0; i--)
			{
				*(lpTarget++) = *lpPlane0++;
				*(lpTarget++) = *lpPlane1++;
				*(lpTarget++) = *lpPlane2++;
			}
		}

		lpvBuffer = lpBuffer;

		return ME_OK;
	}

protected:
	T*	m_lpValue[3];

public:
	virtual E_PR	GetEPR()				{ return CPixelTemplate<T>::GetEPR(); }
	virtual LPVOID	GetValue()				{ return this->m_lpValue; }
	virtual LPVOID	GetPlane(Uint16 nPlane)	{ return (this->m_lpValue == NULL || nPlane >= this->GetPlanes()) ? NULL : this->m_lpValue[nPlane]; };

public:
	CMCoPixelTemplate()
	{
		this->m_lpValue[0] = NULL;
		this->m_lpValue[1] = NULL;
		this->m_lpValue[2] = NULL;
	}

	virtual ~CMCoPixelTemplate()
	{
		delete this->m_lpValue[0];
		delete this->m_lpValue[1];
		delete this->m_lpValue[2];
	}
};


template<class T1, class T2, class T3>
class CMCoPALPixelTemplate : public CMCoPixelTemplate<T3>  
{
public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL)
	{
		CLUTTable** pPalette = (CLUTTable**) lpvParameter;

		Uint16 nBits = 0;
		for (Uint32 i = 0; i < 3; i++)
		{
			if (pPalette[i]->GetBits() > nBits)
				nBits = pPalette[i]->GetBits();
		}

		MRET rc = CMCoPixelTemplate<T3>::CreatePixel(pImageFile, pIPixel, &nBits);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		rc = this->ReadPixel(pIPixel, pPalette);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

private:
	MRET ReadPixel(CIPixel* pIPixel, CLUTTable** pPalette)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		register T2 nValue = 0;
		register Uint32 i = 0;
		register Uint32 k = 0;
		register T1* lpSource = (T1*) pIPixel->GetValue();

		for (i = 0; i < nSize; i++)
		{
			nValue = (T2) *(lpSource++);
			for (k = 0; k < 3; k++)
			{
				if		(nValue <= pPalette[k]->GetFst(nValue))
					this->m_lpValue[k][i] = (T3) pPalette[k]->GetFstValue();
				else if (nValue >= pPalette[k]->GetLst(nValue))
					this->m_lpValue[k][i] = (T3) pPalette[k]->GetLstValue();
				else
					this->m_lpValue[k][i] = (T3) pPalette[k]->GetValue(nValue);
			}
		}

		return ME_OK;
	}

public:
	CMCoPALPixelTemplate() {}
	virtual ~CMCoPALPixelTemplate() {}
};


template<class T1, class T2>
class CMCoRGBPixelTemplate : public CMCoPixelTemplate<T2>  
{
public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL)
	{
		MRET rc = CMCoPixelTemplate<T2>::CreatePixel(pImageFile, pIPixel, lpvParameter);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		rc = this->ReadPixel(pIPixel, this->m_nBits);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

private:
	MRET ReadPixel(CIPixel* pIPixel, Uint16 nBits)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		T1 nOffValue = (T1) MAX_VALUE0(nBits - 1);

		register Uint32 i = 0;
		register Uint32 k = 0;
		register T1* lpSource = (T1*) pIPixel->GetValue();

		if (pIPixel->GetPlane())
		{
			for (i = 0; i < nSize; i += this->GetFrameSize())
				for (k = 0; k < 3; k++, i -= this->GetFrameSize())
					for (register Uint32 I = this->GetFrameSize(); I != 0; I--)
						this->m_lpValue[k][i++] = this->ToUintXX(*(lpSource++), nOffValue);
		}
		else
		{
			CPixelTemplate<T1> EPR;
			if (EPR.UintXX())
			{
				for (i = 0; i < nSize; i++)
					for (k = 0; k < 3; k++)
						this->m_lpValue[k][i] = *(lpSource++);
			}
			else
			{
				for (i = 0; i < nSize; i++)
					for (k = 0; k < 3; k++)
						this->m_lpValue[k][i] = this->ToUintXX(*(lpSource++), nOffValue);
			}
		}

		return ME_OK;
	}

public:
	CMCoRGBPixelTemplate() {}
	virtual ~CMCoRGBPixelTemplate() {}
};


template<class T1, class T2>
class CMCoYBRPixelTemplate : public CMCoPixelTemplate<T2>  
{
public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL)
	{
		MRET rc = CMCoPixelTemplate<T2>::CreatePixel(pImageFile, pIPixel, lpvParameter);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		rc = this->ReadPixel(pIPixel, this->m_nBits);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

private:
	MRET ReadPixel(CIPixel* pIPixel, Uint16 nBits)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		T2 nMaxValue = (T2) MAX_VALUE0(nBits);
		T1 nOffValue = (T1) MAX_VALUE0(nBits - 1);

		register T2* lpR = this->m_lpValue[0];
		register T2* lpG = this->m_lpValue[1];
		register T2* lpB = this->m_lpValue[2];

		CPixelTemplate<T1> EPR;
		if (nBits == 8 && EPR.UintXX())
		{
			Sint16 CR2R[256];
			Sint16 CB2G[256];
			Sint16 CR2G[256];
			Sint16 CB2B[256];
			double dblRConst = 0.7010 * (double) nMaxValue;
			double dblGConst = 0.5291 * (double) nMaxValue;
			double dblBConst = 0.8859 * (double) nMaxValue;
			for (register Uint32 k = 0; k < 256; k++)
			{
				CR2R[k] = (Sint16) (1.4020 * k - dblRConst);
				CB2G[k] = (Sint16) (0.3441 * k);
				CR2G[k] = (Sint16) (0.7141 * k - dblGConst);
				CB2B[k] = (Sint16) (1.7720 * k - dblBConst);
			}

			register Sint32 R = 0;
			register Sint32 G = 0;
			register Sint32 B = 0;
			if (pIPixel->GetPlane())
			{
				register T1* lpY  = (T1*) pIPixel->GetValue();
				register T1* lpCB = lpY  + this->GetFrameSize();
				register T1* lpCR = lpCB + this->GetFrameSize();
				for (register Uint32 i = nSize; i != 0; lpY += 2 * this->GetFrameSize(), lpCB += 2 * this->GetFrameSize(), lpCR += 2 * this->GetFrameSize())
				{
					for (k = this->GetFrameSize(); k != 0; k--, i--, lpY++, lpCB++, lpCR++)
					{
						R = (Sint32) *lpY						 + (Sint32) CR2R[*lpCR];
						G = (Sint32) *lpY - (Sint32) CB2G[*lpCB] - (Sint32) CR2G[*lpCR];
						B = (Sint32) *lpY + (Sint32) CB2B[*lpCB];
						*(lpR++) = (R < 0) ? 0 : (R > (Sint32) nMaxValue) ? nMaxValue : (T2) R;
						*(lpG++) = (G < 0) ? 0 : (G > (Sint32) nMaxValue) ? nMaxValue : (T2) G;
						*(lpB++) = (B < 0) ? 0 : (B > (Sint32) nMaxValue) ? nMaxValue : (T2) B;
					}
				}
			}
			else
			{
				register T1 Y  = 0;
				register T1 CB = 0;
				register T1 CR = 0;
				register T1* lpSource = (T1*) pIPixel->GetValue();
				for (register Uint32 i = nSize; i != 0; i--)
				{
					Y  = *(lpSource++);
					CB = *(lpSource++);
					CR = *(lpSource++);
					R  = (Sint32) Y						+ (Sint32) CR2R[CR];
					G  = (Sint32) Y - (Sint32) CB2G[CB] - (Sint32) CR2G[CR];
					B  = (Sint32) Y + (Sint32) CB2B[CB];
					*(lpR++) = (R < 0) ? 0 : (R > (Sint32) nMaxValue) ? nMaxValue : (T2) R;
					*(lpG++) = (G < 0) ? 0 : (G > (Sint32) nMaxValue) ? nMaxValue : (T2) G;
					*(lpB++) = (B < 0) ? 0 : (B > (Sint32) nMaxValue) ? nMaxValue : (T2) B;
				}
			}
		}
		else
		{
			if (pIPixel->GetPlane())
			{
				register Uint32 k = 0;
				register T1* lpY  = (T1*) pIPixel->GetValue();
				register T1* lpCB = lpY + this->GetFrameSize();
				register T1* lpCR = lpCB + this->GetFrameSize();
				for (register Uint32 i = nSize; i != 0; lpY += 2 * this->GetFrameSize(), lpCB += 2 * this->GetFrameSize(), lpCR += 2 * this->GetFrameSize())
					for (k = this->GetFrameSize(); k != 0; k--, i--)
						this->Calculate(lpR++, lpG++, lpB++, this->ToUintXX(*(lpY++), nOffValue), this->ToUintXX(*(lpCB++), nOffValue), this->ToUintXX(*(lpCR++), nOffValue), nMaxValue);
			}
			else
			{
				register T2 Y  = 0;
				register T2 CB = 0;
				register T2 CR = 0;
				register T1* lpSource = (T1*) pIPixel->GetValue();
				for (register Uint32 i = nSize; i != 0; i--)
				{
					Y  = this->ToUintXX(*(lpSource++), nOffValue);
					CB = this->ToUintXX(*(lpSource++), nOffValue);
					CR = this->ToUintXX(*(lpSource++), nOffValue);

					this->Calculate(lpR++, lpG++, lpB++, Y, CB, CR, nMaxValue);
				}
			}
		}

		return ME_OK;
	}

	inline void Calculate(T2* lpR, T2* lpG, T2* lpB, const T2 Y, const T2 CB, const T2 CR, const T2 nMax)
	{
		double dblR = (double) Y			   + 1.4020 * CR - 0.7010 * nMax;
		double dblG = (double) Y - 0.3441 * CB - 0.7141 * CR + 0.5291 * nMax;
		double dblB = (double) Y + 1.7720 * CB				 - 0.8859 * nMax;
		*lpR = (dblR < .0) ? 0 : ((dblR > (double) nMax) ? nMax : (T2) dblR);
		*lpG = (dblG < .0) ? 0 : ((dblG > (double) nMax) ? nMax : (T2) dblG);
		*lpB = (dblB < .0) ? 0 : ((dblB > (double) nMax) ? nMax : (T2) dblB);
	}

public:
	CMCoYBRPixelTemplate() {}
	virtual ~CMCoYBRPixelTemplate() {}
};


template<class T1, class T2>
class CMCoYBR422PixelTemplate : public CMCoPixelTemplate<T2>  
{
public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL)
	{
		MRET rc = CMCoPixelTemplate<T2>::CreatePixel(pImageFile, pIPixel, lpvParameter);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		if (pIPixel->GetPlane())
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		rc = this->ReadPixel(pIPixel, this->m_nBits);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

private:
 	MRET ReadPixel(CIPixel* pIPixel, Uint16 nBits)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		T2 nMaxValue = (T2) MAX_VALUE0(nBits);
		T1 nOffValue = (T1) MAX_VALUE0(nBits - 1);

		register T2 Y1 = 0;
		register T2 Y2 = 0;
		register T2 CB = 0;
		register T2 CR = 0;

		register T2* lpR = this->m_lpValue[0];
		register T2* lpG = this->m_lpValue[1];
		register T2* lpB = this->m_lpValue[2];
		register T1* lpSource = (T1*) pIPixel->GetValue();
		for (register Uint32 i = (nSize / 2); i != 0; i--)
		{
			Y1 = this->ToUintXX(*(lpSource++), nOffValue);
			Y2 = this->ToUintXX(*(lpSource++), nOffValue);
			CB = this->ToUintXX(*(lpSource++), nOffValue);
			CR = this->ToUintXX(*(lpSource++), nOffValue);
			this->Calculate(lpR++, lpG++, lpB++, Y1, CB, CR, nMaxValue);
			this->Calculate(lpR++, lpG++, lpB++, Y2, CB, CR, nMaxValue);
		}

		return ME_OK;
	}

	inline void Calculate(T2* lpR, T2* lpG, T2* lpB, const T2 Y, const T2 CB, const T2 CR, const T2 nMax)
	{
		double dblR = (double) Y			   + 1.4020 * CR - 0.7010 * nMax;
		double dblG = (double) Y - 0.3441 * CB - 0.7141 * CR + 0.5291 * nMax;
		double dblB = (double) Y + 1.7720 * CB				 - 0.8859 * nMax;
		*lpR = (dblR < .0) ? 0 : ((dblR > (double) nMax) ? nMax : (T2) dblR);
		*lpG = (dblG < .0) ? 0 : ((dblG > (double) nMax) ? nMax : (T2) dblG);
		*lpB = (dblB < .0) ? 0 : ((dblB > (double) nMax) ? nMax : (T2) dblB);
	}

public:
	CMCoYBR422PixelTemplate() {}
	virtual ~CMCoYBR422PixelTemplate() {}
};


template<class T1, class T2>
class CMCoYBRPart422PixelTemplate : public CMCoPixelTemplate<T2>  
{
public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter = NULL)
	{
		MRET rc = CMCoPixelTemplate<T2>::CreatePixel(pImageFile, pIPixel, lpvParameter);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		if (pIPixel->GetPlane())
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		rc = this->ReadPixel(pIPixel, this->m_nBits);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

private:
	MRET ReadPixel(CIPixel* pIPixel, Uint16 nBits)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		T2 nMaxValue = (T2) MAX_VALUE0(nBits);
		T1 nOffValue = (T1) MAX_VALUE0(nBits - 1);

		register T2 Y1 = 0;
		register T2 Y2 = 0;
		register T2 CB = 0;
		register T2 CR = 0;

		register T2* lpR = this->m_lpValue[0];
		register T2* lpG = this->m_lpValue[1];
		register T2* lpB = this->m_lpValue[2];
		register T1* lpSource = (T1*) pIPixel->GetValue();
		for (register Uint32 i = (nSize / 2); i != 0; i--)
		{
			Y1 = this->ToUintXX(*(lpSource++), nOffValue);
			Y2 = this->ToUintXX(*(lpSource++), nOffValue);
			CB = this->ToUintXX(*(lpSource++), nOffValue);
			CR = this->ToUintXX(*(lpSource++), nOffValue);
			this->Calculate(lpR++, lpG++, lpB++, Y1, CB, CR, nMaxValue);
			this->Calculate(lpR++, lpG++, lpB++, Y2, CB, CR, nMaxValue);
		}

		return ME_OK;
	}

	inline void Calculate(T2* lpR, T2* lpG, T2* lpB, const T2 Y, const T2 CB, const T2 CR, const T2 nMax)
	{
		double dblR = 1.1631 * Y			   + 1.5969 * CR - 0.8713 * nMax;
		double dblG = 1.1631 * Y - 0.3913 * CB - 0.8121 * CR + 0.5290 * nMax;
		double dblB = 1.1631 * Y + 2.0177 * CB				 - 1.0820 * nMax;
		*lpR = (dblR < .0) ? 0 : ((dblR > (double) nMax) ? nMax : (T2) dblR);
		*lpG = (dblG < .0) ? 0 : ((dblG > (double) nMax) ? nMax : (T2) dblG);
		*lpB = (dblB < .0) ? 0 : ((dblB > (double) nMax) ? nMax : (T2) dblB);
	}

public:
	CMCoYBRPart422PixelTemplate() {}
	virtual ~CMCoYBRPart422PixelTemplate() {}
};

#endif // !defined(AFX_MCOPIXELTEMPLATE_H__6B17AB4A_2964_4743_8554_573EE4ED4A83__INCLUDED_)
