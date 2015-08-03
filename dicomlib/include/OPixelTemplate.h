// OPixelTemplate.h: interface for the COPixelTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPIXELTEMPLATE_H__821854DA_B124_402D_B4BE_4DC6094525AD__INCLUDED_)
#define AFX_OPIXELTEMPLATE_H__821854DA_B124_402D_B4BE_4DC6094525AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OPixel.h"
#include "PixelTemplate.h"

template<class T1, class T2, class T3>
class COPixelTemplate : public COPixel, public CPixelTemplate<T3>  
{
private:
	MRET UseVTable(CMPixel* pMPixel, Uint32 nFrame, CLUTTable* pVTable, CLUTTable* pPTable, CLUTTable* pOTable, T3 nLValue, T3 nHValue)
	{
		double dblOutRange = (double) nHValue - (double) nLValue + (nHValue > nLValue) ? (+1.0) : (-1.0);

		register Uint32 i = 0;
		register T2 nValue = 0;
		T2 nFst = pVTable->GetFst(nValue);
		T2 nLst = pVTable->GetLst(nValue);

		T2 nAbsMinimum = (T2) pMPixel->GetAbsMinimum();
		Uint32 nAbsMaxRange = (Uint32) pMPixel->GetAbsMaxRange();

		T3* lpTable = (T3*) CTools::Alloc(nAbsMaxRange * sizeof(T3));

		register T3* lpTable0 = lpTable;
		if (pPTable != NULL)
		{
			double dblSlope1 = (double) (pPTable->GetEntries()) / (double) (pVTable->GetAbsMaxRange());
			Uint32 nFstValue = (Uint32) (pVTable->GetFstValue() * dblSlope1);
			Uint32 nLstValue = (Uint32) (pVTable->GetLstValue() * dblSlope1);

			register Uint32 nValue2 = 0;
			if (pOTable != NULL && nLValue > nHValue)
			{
				Uint16 nMaxValue = (Uint16) (pPTable->GetAbsMaxRange() - 1);
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if		(nValue <= nFst)	nValue2 = nFstValue;
					else if	(nValue >= nLst)	nValue2 = nLstValue;
					else						nValue2 = (Uint32) (pVTable->GetValue(nValue) * dblSlope1);
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) (nMaxValue - pPTable->GetValue(nValue2)));
				}
			}
			else if (pOTable != NULL)
			{
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if		(nValue <= nFst)	nValue2 = nFstValue;
					else if	(nValue >= nLst)	nValue2 = nLstValue;
					else						nValue2 = (Uint32) (pVTable->GetValue(nValue) * dblSlope1);
					*(lpTable0++) = (T3) pOTable->GetValue(pPTable->GetValue(nValue2));
				}
			}
			else
			{
				double dblSlope2 = dblOutRange / pPTable->GetAbsMaxRange();
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if		(nValue <= nFst)	nValue2 = nFstValue;
					else if	(nValue >= nLst)	nValue2 = nLstValue;
					else						nValue2 = (Uint32) (pVTable->GetValue(nValue) * dblSlope1);
					*(lpTable0++) = (T3) (nLValue + pPTable->GetValue(nValue2) * dblSlope2);
				}
			}
		}	/// (pPTable != NULL)
		else
		{
			if (pOTable != NULL && nLValue > nHValue)
			{
				Uint16 nMaxValue = (Uint16) (pVTable->GetAbsMaxRange() - 1);
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if		(nValue < nFst)	nValue = nFst;
					else if	(nValue > nLst)	nValue = nLst;
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) (nMaxValue - pVTable->GetValue(nValue)));
				}
			}
			else if (pOTable != NULL)
			{
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if		(nValue < nFst)	nValue = nFst;
					else if	(nValue > nLst)	nValue = nLst;
					*(lpTable0++) = (T3) pOTable->GetValue(pVTable->GetValue(nValue));
				}
			}
			else
			{
				double dblSlope = dblOutRange / pVTable->GetAbsMaxRange();
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (T2) i + nAbsMinimum;
					if		(nValue <= nFst) nValue = nFst;
					else if	(nValue >= nLst) nValue = nLst;
					*(lpTable0++) = (T3) (nLValue + pVTable->GetValue(nValue) * dblSlope);
				}
			}
		}	/// (pPTable != NULL)

		register T3* lpTarget = this->m_lpValue;

		lpTable0 = lpTable - nAbsMinimum;
		if (this->m_nPlanes == 1 || this->m_bPlane)
		{
			for (Uint32 k = 0; k < this->m_nPlanes; k++)
			{
				Uint32 nCancel = (pMPixel->GetFrame() != (Uint32) (-1)) ? 0 : nFrame * this->GetFrameSize();
				register T1* lpSource = ((T1*) pMPixel->GetPlane(k)) + nCancel;
				for (i = this->GetFrameSize(); i != 0; i--)
					*(lpTarget++) = *(lpTable0 + (*lpSource++));
			}
		}
		else
		{
			Uint32 nCancel = (pMPixel->GetFrame() != (Uint32) (-1)) ? 0 : nFrame * this->GetFrameSize();
			register T1* lpPlane0 = ((T1*) pMPixel->GetPlane(0)) + nCancel;
			register T1* lpPlane1 = ((T1*) pMPixel->GetPlane(1)) + nCancel;
			register T1* lpPlane2 = ((T1*) pMPixel->GetPlane(2)) + nCancel;
			for (i = this->GetFrameSize(); i != 0; i--)
			{
				*(lpTarget++) = *(lpTable0 + (*lpPlane0++));
				*(lpTarget++) = *(lpTable0 + (*lpPlane1++));
				*(lpTarget++) = *(lpTable0 + (*lpPlane2++));
			}
		}

		delete lpTable;

		return ME_OK;
	}

	MRET UseWinLvl(CMPixel* pMPixel, Uint32 nFrame, CLUTTable* pPTable, CLUTTable* pOTable, T3 nLValue, T3 nHValue)
	{
		double dblOutRange = (double) nHValue - (double) nLValue + (nHValue > nLValue) ? (+1.0) : (-1.0);

		register Uint32 i = 0;
		register Uint32 nValue = 0;
		Uint32 nAbsMaxRange = (Uint32) pMPixel->GetAbsMaxRange();

		T3* lpTable = (T3*) CTools::Alloc(nAbsMaxRange * sizeof(T3));

		register T3* lpTable0 = lpTable;
		if (pPTable != NULL)
		{
			double dblSlope1 = pPTable->GetEntries() / pMPixel->GetAbsMaxRange();
			if (pOTable != NULL && nLValue > nHValue)
			{
				Uint16 nMaxValue = (Uint16) (pPTable->GetAbsMaxRange() - 1);
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (Uint32) (i * dblSlope1);
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) (nMaxValue - pPTable->GetValue(nValue)));
				}
			}
			else if (pOTable != NULL)
			{
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (Uint32) (i * dblSlope1);
					*(lpTable0++) = (T3) pOTable->GetValue(pPTable->GetValue(nValue));
				}
			}
			else
			{
				double dblSlope2 = dblOutRange / pPTable->GetAbsMaxRange();
				for (i = 0; i < nAbsMaxRange; i++)
				{
					nValue = (Uint32) (i * dblSlope1);
					*(lpTable0++) = (T3) (nLValue + pPTable->GetValue(nValue) * dblSlope2);
				}
			}
		}	/// (pPTable != NULL)
		else
		{
			register double dblSlope = dblOutRange / (pMPixel->GetAbsMaxRange());
			if (pOTable != NULL && nLValue > nHValue)
				for (i = nAbsMaxRange - 1; i >= 0; i--)
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) i);
			else if (pOTable != NULL)
				for (i = 0; i < nAbsMaxRange; i++)
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) i);
			else
				for (i = 0; i < nAbsMaxRange; i++)
					*(lpTable0++) = (T3) (nLValue + i * dblSlope);
		}	/// (pPTable != NULL)

		register T3* lpTarget = this->m_lpValue;

		lpTable0 = lpTable - (T2) pMPixel->GetAbsMinimum();
		if (this->m_nPlanes == 1 || this->m_bPlane)
		{
			for (Uint32 k = 0; k < this->m_nPlanes; k++)
			{
				Uint32 nCancel = (pMPixel->GetFrame() != (Uint32) (-1)) ? 0 : nFrame * this->GetFrameSize();
				register T1* lpSource = ((T1*) pMPixel->GetPlane(k)) + nCancel;
				for (i = this->GetFrameSize(); i != 0; i--)
					*(lpTarget++) = *(lpTable0 + (*lpSource++));
			}
		}
		else
		{
			Uint32 nCancel = (pMPixel->GetFrame() != (Uint32) (-1)) ? 0 : nFrame * this->GetFrameSize();
			register T1* lpPlane0 = ((T1*) pMPixel->GetPlane(0)) + nCancel;
			register T1* lpPlane1 = ((T1*) pMPixel->GetPlane(1)) + nCancel;
			register T1* lpPlane2 = ((T1*) pMPixel->GetPlane(2)) + nCancel;
			for (i = this->GetFrameSize(); i != 0; i--)
			{
				*(lpTarget++) = *(lpTable0 + (*lpPlane0++));
				*(lpTarget++) = *(lpTable0 + (*lpPlane1++));
				*(lpTarget++) = *(lpTable0 + (*lpPlane2++));
			}
		}

		delete lpTable;

		return ME_OK;
	}

	MRET UseWinLvl(CMPixel* pMPixel, Uint32 nFrame, CLUTTable* pPTable, CLUTTable* pOTable, double dblWin, double dblLvl, T3 nLValue, T3 nHValue)
	{
		double dblOutRange = (double) nHValue - (double) nLValue + (nHValue > nLValue) ? (+1.0) : (-1.0);

		register Uint32 i = 0;
		register Uint32 nValue = 0;
		register double dblValue = 0;
		double dblLBorder = dblLvl - 0.5 - (dblWin - 1.0) / 2;
		double dblHBorder = dblLvl - 0.5 + (dblWin - 1.0) / 2;

		double dblAbsMinimum = pMPixel->GetAbsMinimum();
		Uint32 nAbsMaxRange = (Uint32) pMPixel->GetAbsMaxRange();

		T3* lpTable = (T3*) CTools::Alloc(nAbsMaxRange * sizeof(T3));

		register T3* lpTable0 = lpTable;
		if (pPTable != NULL)
		{
			Uint32 nMaximum = pPTable->GetEntries() - 1;
			double dblSlope = pPTable->GetEntries() / dblWin;
			if (pOTable != NULL && nLValue > nHValue)
			{
				Uint16 nMaxValue = (Uint16) (pPTable->GetAbsMaxRange() - 1);
				for (i = 0; i < nAbsMaxRange; i++)
				{
					dblValue = i + dblAbsMinimum;
					if		(dblValue <= dblLBorder)	nValue = 0;
					else if	(dblValue >  dblHBorder)	nValue = nMaximum;
					else								nValue = (Uint32) ((dblValue - dblLBorder) * dblSlope);
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) (nMaxValue - pPTable->GetValue(nValue)));
				}
			}
			else if (pOTable != NULL)
			{
				for (i = 0; i < nAbsMaxRange; i++)
				{
					dblValue = i + dblAbsMinimum;
					if		(dblValue <= dblLBorder)	nValue = 0;
					else if	(dblValue >  dblHBorder)	nValue = nMaximum;
					else								nValue = (Uint32) ((dblValue - dblLBorder) * dblSlope);
					*(lpTable0++) = (T3) pOTable->GetValue(pPTable->GetValue(nValue));
				}
			}
			else
			{
				double dblSlope1 = dblOutRange / pPTable->GetAbsMaxRange();
				for (i = 0; i < nAbsMaxRange; i++)
				{
					dblValue = i + dblAbsMinimum;
					if		(dblValue <= dblLBorder)	nValue = 0;
					else if (dblValue >  dblHBorder)	nValue = nMaximum;
					else								nValue = (Uint32) ((dblValue - dblLBorder) * dblSlope);
					*(lpTable0++) = (T3) (nLValue + pPTable->GetValue(nValue) * dblSlope1);
				}
			}
		}	/// (pPTable != NULL)
		else
		{
			if (pOTable != NULL && nLValue > nHValue)
			{
				Uint16 nMaxValue = (Uint16) (pOTable->GetAbsMaxRange() - 1);

				Uint32 nMValue2 = pOTable->GetEntries() - 1;
				double dblSlope = pOTable->GetEntries() / dblWin;
				for (i = 0; i < nAbsMaxRange; i++)
				{
					dblValue = i + dblAbsMinimum;
					if		(dblValue <= dblLBorder)	nValue = 0;
					else if	(dblValue >  dblHBorder)	nValue = nMValue2;
					else								nValue = (Uint32) ((dblValue - dblLBorder) * dblSlope);
					*(lpTable0++) = (T3) pOTable->GetValue((Uint16) (nMaxValue - nValue));
				}
			}
			else if (pOTable != NULL)
			{
				Uint32 nMValue2 = pOTable->GetEntries() - 1;
				double dblSlope = pOTable->GetEntries() / dblWin;
				for (i = 0; i < nAbsMaxRange; i++)
				{
					dblValue = i + dblAbsMinimum;
					if		(dblValue <= dblLBorder)	nValue = 0;
					else if	(dblValue >  dblHBorder)	nValue = nMValue2;
					else								nValue = (Uint32) ((dblValue - dblLBorder) * dblSlope);
					*(lpTable0++) = (T3) pOTable->GetValue(nValue);
				}
			}
			else
			{
				double dblSlope = (dblWin <= 1) ? 0 : ((double) nHValue - (double) nLValue) / (dblWin - 1.0);
				double dblConst = (dblWin <= 1) ? 0 : nHValue - ((dblLvl - 0.5) / (dblWin - 1.0) + 0.5) * ((double) nHValue - (double) nLValue);
				for (i = 0; i < nAbsMaxRange; i++)
				{
					dblValue = i + dblAbsMinimum;
					if		(dblValue <= dblLBorder)	*(lpTable0++) = nLValue;
					else if	(dblValue >  dblHBorder)	*(lpTable0++) = nHValue;
					else								*(lpTable0++) = (T3) (dblConst + dblValue * dblSlope);
				}
			}
		}	/// (pPTable != NULL)

		register T3* lpTarget = this->m_lpValue;

		lpTable0 = lpTable - (T2) dblAbsMinimum;
		if (this->m_nPlanes == 1 || this->m_bPlane)
		{
			for (Uint32 k = 0; k < this->m_nPlanes; k++)
			{
				Uint32 nCancel = (pMPixel->GetFrame() != (Uint32) (-1)) ? 0 : nFrame * this->GetFrameSize();
				register T1* lpSource = ((T1*) pMPixel->GetPlane(k)) + nCancel;
				for (i = this->GetFrameSize(); i != 0; i--)
					*(lpTarget++) = *(lpTable0 + (*lpSource++));
			}
		}
		else
		{
			Uint32 nCancel = (pMPixel->GetFrame() != (Uint32) (-1)) ? 0 : nFrame * this->GetFrameSize();
			register T1* lpPlane0 = ((T1*) pMPixel->GetPlane(0)) + nCancel;
			register T1* lpPlane1 = ((T1*) pMPixel->GetPlane(1)) + nCancel;
			register T1* lpPlane2 = ((T1*) pMPixel->GetPlane(2)) + nCancel;
			for (i = this->GetFrameSize(); i != 0; i--)
			{
				*(lpTarget++) = *(lpTable0 + (*lpPlane0++));
				*(lpTarget++) = *(lpTable0 + (*lpPlane1++));
				*(lpTarget++) = *(lpTable0 + (*lpPlane2++));
			}
		}

		delete lpTable;

		return ME_OK;
	}

public:
	virtual MRET CreatePixel(CMPixel* pMPixel, CLUTTable* pVTable, CLUTTable* pPTable, double dblWin, double dblLvl, Uint32 nLValue, Uint32 nHValue, Uint32 nFrame, BOOL bPlane = FALSE)
	{
		MRET rc = COPixel::CreatePixel(pMPixel, pVTable, pPTable, dblWin, dblLvl, nLValue, nHValue, nFrame, bPlane);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		this->m_bPlane	= bPlane;
		this->m_nPlanes = pMPixel->GetPlanes();
		this->m_lpValue = (T3*) CTools::Alloc(this->GetFrameSize() * sizeof(T3) * this->m_nPlanes);

		if (this->m_nPlanes != 1 && this->m_nPlanes != 3)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		}

		if (pVTable != NULL)
			rc = this->UseVTable(pMPixel, nFrame, pVTable, pPTable, NULL, (T3) nLValue, (T3) nHValue);
		else if (dblWin < 1)
			rc = this->UseWinLvl(pMPixel, nFrame, pPTable, NULL, (T3) nLValue, (T3) nHValue);
		else
			rc = this->UseWinLvl(pMPixel, nFrame, pPTable, NULL, dblWin, dblLvl, (T3) nLValue, (T3) nHValue);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}

		return ME_OK;
	}

protected:
	T3*		m_lpValue;
	BOOL	m_bPlane;
	Uint16	m_nPlanes;

public:
	virtual Uint16	GetPlanes()		{ return this->m_nPlanes; }
	virtual E_PR	GetEPR()		{ return CPixelTemplate<T3>::GetEPR(); }
	virtual Uint32	GetPixelSize()	{ return sizeof(T3); }
	virtual LPVOID	GetValue()		{ return this->m_lpValue; }
	virtual LPVOID	RemoveValue()	{ LPVOID lpvValue = this->m_lpValue; this->m_lpValue = NULL; return lpvValue; }
	virtual LPVOID	GetPlane(Uint16 nPlane)
	{
		if (this->m_lpValue == NULL || nPlane >= this->GetPlanes())
			return NULL;
		
		if (!this->m_bPlane)
			return this->m_lpValue + nPlane;
		else
			return this->m_lpValue + nPlane * this->GetFrameSize();
	}

public:
	COPixelTemplate()				{ this->m_nPlanes = 0; this->m_bPlane = FALSE; this->m_lpValue = NULL; }
	virtual ~COPixelTemplate()		{ delete this->m_lpValue; }
};

#endif // !defined(AFX_OPIXELTEMPLATE_H__821854DA_B124_402D_B4BE_4DC6094525AD__INCLUDED_)
