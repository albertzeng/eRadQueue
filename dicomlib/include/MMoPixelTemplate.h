// MMoPixelTemplate.h: interface for the CMMoPixelTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MMOPIXELTEMPLATE_H__9C3A80C4_4249_4EC4_BF03_F4BBF9ADE700__INCLUDED_)
#define AFX_MMOPIXELTEMPLATE_H__9C3A80C4_4249_4EC4_BF03_F4BBF9ADE700__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MPixel.h"
#include "PixelTemplate.h"

class CLUTModalities;

template<class T1, class T2, class T3>
class CMMoPixelTemplate : public CMMoPixel, public CPixelTemplate<T3>  
{
private:
	MRET UseLUTTable(CIPixel* pIPixel, CLUTModalities* pModalities)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		T1* lpValue = (T1*) pIPixel->GetValue();
		if (BITS(T1) > LUT_MAX_BITS)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		CLUTTable* pLUT = pModalities->GetLUTTable();
		if (pLUT != NULL)
		{
			this->m_lpValue = new T3[nSize];
			register T2 nValue = 0;
			T2 nFst = pLUT->GetFst(nValue);
			T2 nLst = pLUT->GetLst(nValue);
			T3 nFstValue = (T3) pLUT->GetFstValue();
			T3 nLstValue = (T3) pLUT->GetLstValue();
			register T1* lpSource = lpValue;
			register T3* lpTarget = this->m_lpValue;
			register Uint32 i = 0;
			Uint32 nCount = (Uint32) pIPixel->GetAbsMaxRange();
			if (nSize > 3 * nCount)
			{
				T3* lpBuffer = (T3*) CTools::Alloc(nCount * sizeof(T3));
				T3* lpTable = lpBuffer;
				T2 nAbsMinimum = (T2) pIPixel->GetAbsMinimum();
				for (i = 0; i < nCount; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if (nValue <= nFst)
						*(lpTable++) = nFstValue;
					else if (nValue >= nLst)
						*(lpTable++) = nLstValue;
					else
						*(lpTable++) = (T3) pLUT->GetValue(nValue);
				}
				lpTable = lpBuffer - (T2) nAbsMinimum;
				for (i = nSize; i != 0; i--)
					*(lpTarget++) = *(lpTable + *(lpSource++));
				delete lpBuffer;
			}
			else
			{
				for (i = nSize; i != 0; i--)
				{
					nValue = (T2) *(lpSource++);
					if (nValue <= nFst)
						*(lpTarget++) = nFstValue;
					else if (nValue >= nLst)
						*(lpTarget++) = nLstValue;
					else
						*(lpTarget++) = (T3) pLUT->GetValue(nValue);
				}
			}
		}

		return ME_OK;
	}

	MRET UseRescale(CIPixel* pIPixel, double dblSlope = 1.0, double dblIntercept = 0.0)
	{
		Uint32 nSize = (this->m_nFrame != (Uint32) (-1)) ? this->GetFrameSize() : this->GetPixelCount();

		T1* lpValue = (T1*) pIPixel->GetValue();

		BOOL bUseInput = (sizeof(T1) == sizeof(T3));
		if (bUseInput)
			this->m_lpValue = (T3*) pIPixel->RemoveValue();
		else
			this->m_lpValue = (T3*) CTools::Alloc(nSize * sizeof(T3));

		register Uint32 i = 0;
		register T3* lpTarget = this->m_lpValue;
		if ((dblSlope == 1.0) && (dblIntercept == 0.0))
		{
			if (!bUseInput)
			{
				register T1* lpSource = lpValue;
				for (i = nSize; i != 0; i--)
					*(lpTarget++) = (T3) *(lpSource++);
			}
		}
		else
		{
			register T1* lpSource = lpValue;
			Uint32 nCount = (Uint32) pIPixel->GetAbsMaxRange();
			if (nSize > 3 * nCount)
			{
				T3* lpBuffer = (T3*) CTools::Alloc(nCount * sizeof(T3));
				T3* lpTable = lpBuffer;
				double dblAbsMinimum = pIPixel->GetAbsMinimum();
				if (dblSlope == 1.0)
				{
					for (i = 0; i < nCount; i++)
						*(lpTable++) = (T3) (i + dblAbsMinimum + dblIntercept);
				}
				else if (dblIntercept == 0.0)
				{
					for (i = 0; i < nCount; i++)
						*(lpTable++) = (T3) ((i + dblAbsMinimum) * dblSlope);
				}
				else
				{
					for (i = 0; i < nCount; i++)
						*(lpTable++) = (T3) ((i + dblAbsMinimum) * dblSlope + dblIntercept);
				}

				lpTable = lpBuffer - (T2) dblAbsMinimum;
				for (i = nSize; i != 0; i--)
					*(lpTarget++) = *(lpTable + (*(lpSource++)));

				delete lpBuffer;
			}
			else
			{
				if (dblSlope == 1.0)
				{
					for (i = nSize; i != 0; i--)
						*(lpTarget++) = (T3) (*(lpSource++) + dblIntercept);
				}
				else if (dblIntercept == 0.0)
				{
					for (i = nSize; i != 0; i--)
						*(lpTarget++) = (T3) (*(lpSource++) * dblSlope);
				}
				else
				{
					for (i = nSize; i != 0; i--)
						*(lpTarget++) = (T3) (*(lpSource++) * dblSlope + dblIntercept);
				}
			}
		}

		return ME_OK;
	}

public:
	virtual MRET CreatePixel(CImageFile* pImageFile, CIPixel* pIPixel, LPVOID lpvParameter)
	{
		MRET rc = CMMoPixel::CreatePixel(pImageFile, pIPixel, lpvParameter);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		CLUTModalities* pModalities = (CLUTModalities*) lpvParameter;
		if (pModalities != NULL && (pModalities->UseLUTTable() || pModalities->UseRescale()))
		{
			this->m_nBits			= pModalities->GetBits();
			this->m_dblAbsMinimum	= pModalities->GetAbsMinimum();
			this->m_dblAbsMaximum	= pModalities->GetAbsMaximum();

			if ((pModalities != NULL) && pModalities->UseLUTTable())
				rc = this->UseLUTTable(pIPixel, pModalities);
			else
				rc = this->UseRescale(pIPixel, pModalities->GetRescaleSlope(), pModalities->GetRescaleIntercept());
		}
		else
			rc = this->UseRescale(pIPixel);

		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

	virtual MRET GetFrame(LPVOID& lpvBuffer, Uint32 nFrame, BOOL bPlane = FALSE)
	{
		if (this->m_nFrame != (Uint32) (-1))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_BADPARAMETER);
		}

		lpvBuffer = new T3[this->GetFrameSize()];
		MEMCPY(this->m_lpValue + nFrame * this->GetFrameSize(), lpvBuffer, this->GetFrameSize() * sizeof(T3));

		return ME_OK;
	}

protected:
	T3*		m_lpValue;

public:
	virtual E_PR	GetEPR()				{ return CPixelTemplate<T3>::GetEPR(); }
	virtual LPVOID	GetValue()				{ return this->m_lpValue; }
	virtual LPVOID	GetPlane(Uint16 nPlane)	{ return this->m_lpValue; }

public:
	CMMoPixelTemplate()						{ this->m_lpValue = NULL; }
	virtual ~CMMoPixelTemplate()			{ delete this->m_lpValue; }
};

#endif // !defined(AFX_MMOPIXELTEMPLATE_H__9C3A80C4_4249_4EC4_BF03_F4BBF9ADE700__INCLUDED_)
