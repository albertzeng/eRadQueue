// AttributeTable.h: interface for the CAttributeTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ATTRIBUTETABLE_H__6069BAD6_4C7A_40BB_9A83_B6E71966721F__INCLUDED_)
#define AFX_ATTRIBUTETABLE_H__6069BAD6_4C7A_40BB_9A83_B6E71966721F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	DCM_VariableVM					-1
#define	DCM_AttributeTable_HASH_SIZE	2047

class CAttrHashedTable;

enum E_RANGE_RESTRICTION
{
	ERR_Unspecified,
	ERR_ODD,
	ERR_EVEN
};

class CAttrProperties : public CTIndex  
{
private:
	CTIndex					m_RangeAttribute;
	CAttributeVR			m_VR;
	LPCTSTR					m_lpName;
	int						m_nMinVM;
	int						m_nMaxVM;
	LPCTSTR					m_lpStandardVersion;
	E_RANGE_RESTRICTION		m_eGRestriction;
	E_RANGE_RESTRICTION		m_eERestriction;
	LPCTSTR					m_lpPrivateCreator;

public:
	CAttributeVR			GetVR()					{ return m_VR; }
	E_VR					GetEVR()				{ return m_VR.GetEVR(); }
	LPCTSTR					GetStandardVersion()	{ return m_lpStandardVersion; }
	LPCTSTR					GetName()				{ return m_lpName; }
	LPCTSTR					GetPrivateCreator()		{ return m_lpPrivateCreator; }
	BOOL					PrivateCreatorEquivalent(LPCTSTR lpCreator)				{ return TRUE; }	// ((m_lpPrivateCreator == NULL && lpCreator == NULL) || (m_lpPrivateCreator && lpCreator && (strcmp(m_lpPrivateCreator, lpCreator) == 0))); }
	BOOL					PrivateCreatorEquivalent(CAttrProperties& Properties)	{ return TRUE; }	// PrivateCreatorEquivalent(Properties.m_lpPrivateCreator); }
	int						GetMinVM()				{ return m_nMinVM; }
	int						GetMaxVM()				{ return m_nMaxVM; }
	BOOL					IsFixedSingleVM()		{ return (m_nMinVM != DCM_VariableVM && m_nMinVM == m_nMaxVM); }
	BOOL					IsFixedRangeVM()		{ return (m_nMinVM != DCM_VariableVM && m_nMaxVM != DCM_VariableVM); }
	BOOL					IsVariableRangeVM()		{ return (m_nMinVM != DCM_VariableVM && m_nMaxVM == DCM_VariableVM); }
	Uint16					GetGRange()				{ return m_RangeAttribute.GetGNumber(); }
	Uint16					GetERange()				{ return m_RangeAttribute.GetENumber(); }
	CTIndex					GetAttribute()			{ return *this; }
	BOOL					IsRepeat()				{ return (IsGRepeat() || IsERepeat()); }
	BOOL					IsGRepeat()				{ return (GetGNumber() != GetGRange()); }
	BOOL					IsERepeat()				{ return (GetENumber() != GetERange()); }
	E_RANGE_RESTRICTION		GetGRestriction()		{ return m_eGRestriction; }
	E_RANGE_RESTRICTION		GetERestriction()		{ return m_eERestriction; }
	BOOL					SetGRestriction(E_RANGE_RESTRICTION eGRestriction)		{ m_eGRestriction = eGRestriction; return TRUE; }
	BOOL					SetERestriction(E_RANGE_RESTRICTION eERestriction)		{ m_eERestriction = eERestriction; return TRUE; }
	BOOL					Contains(LPCTSTR lpName){ return !strcmp(m_lpName, lpName); }

	BOOL Contains(CTIndex& TIndex, LPCTSTR lpCreator)
	{
		if		((GetGRestriction() == ERR_EVEN) && ((TIndex.GetGNumber()) & 1))
			return FALSE;
		else if ((GetGRestriction() == ERR_ODD) && !((TIndex.GetGNumber()) & 1))
			return FALSE;
		else if ((GetERestriction() == ERR_EVEN) && ((TIndex.GetENumber()) & 1))
			return FALSE;
		else if ((GetERestriction() == ERR_ODD) && !((TIndex.GetENumber()) & 1))
			return FALSE;
		else if (!PrivateCreatorEquivalent(lpCreator))
			return FALSE;
		else
			return (TIndex.GetGNumber() >= GetGNumber() && TIndex.GetGNumber() <= GetGRange() && TIndex.GetENumber() >= GetENumber() && TIndex.GetENumber() <= GetERange());
	}

	BOOL Subset(CAttrProperties& Properties)
	{
		return (GetGNumber() >= Properties.GetGNumber() && GetGRange() <= Properties.GetGRange() && GetENumber() >= Properties.GetENumber() && GetERange() <= Properties.GetERange() && PrivateCreatorEquivalent(Properties.m_lpPrivateCreator));
	}

	BOOL SetEQ(CAttrProperties& Properties)
	{
		return (GetGNumber() == Properties.GetGNumber() && GetGRange() == Properties.GetGRange() && GetENumber() == Properties.GetENumber() && GetERange() == Properties.GetERange() && GetGRestriction() == Properties.GetGRestriction() && GetERestriction() == Properties.GetERestriction() && PrivateCreatorEquivalent(Properties.m_lpPrivateCreator));
	}

public:
	CAttrProperties(Uint16 nGNumber, Uint16 nENumber, CAttributeVR VR, LPCTSTR lpName, int nMinVM, int nMaxVM, LPCTSTR lpVersion, LPCTSTR lpCreator);
	CAttrProperties(Uint16 nGNumber, Uint16 nENumber, Uint16 nGRange, Uint16 nERange, CAttributeVR VR, LPCTSTR lpName, int nMinVM, int nMaxVM, LPCTSTR lpVersion, LPCTSTR lpCreator);
	CAttrProperties(CAttrProperties& Properties);
	CAttrProperties();
	virtual ~CAttrProperties();
};


#define CAttrListIter	STListIter(CAttrProperties*)


class CAttrList : public STList<CAttrProperties*>  
{
public:
	CAttrProperties*		InsertAndReplace(CAttrProperties* pObject);
	CAttrProperties*		FindItem(CTIndex& TIndex, LPCTSTR lpCreator);

public:
	CAttrList();
	virtual ~CAttrList();
};

class CAttrHashedTableIter
{
private:
	CAttrHashedTable*		m_pTable;
	int						m_nIndex;
	BOOL					m_bValid;
	CAttrListIter			m_ListIter;

private:
	BOOL					Initialize(CAttrHashedTable* pObject, BOOL bAtEnd = FALSE);
	BOOL					StepUp();

public:
	CAttrHashedTableIter& operator =(CAttrHashedTableIter& iter)
	{
		m_pTable = iter.m_pTable;
		m_nIndex = iter.m_nIndex; 
		m_bValid = iter.m_bValid;
		m_ListIter = iter.m_ListIter;
		return *this;
	}

	BOOL operator ==(CAttrHashedTableIter& iter)
	{
		return (m_nIndex == iter.m_nIndex) && (m_ListIter == iter.m_ListIter);
	}

	BOOL operator !=(CAttrHashedTableIter& iter)
	{
		return (m_nIndex != iter.m_nIndex) || (m_ListIter != iter.m_ListIter);
	}

	CAttrProperties* operator *()
	{
		return (*m_ListIter);
	}

	CAttrHashedTableIter& operator ++()
	{
		StepUp();
		return *this;
	}

	CAttrHashedTableIter operator ++(int)
	{
		CAttrHashedTableIter iter(*this);
		StepUp();
		return iter;
	}

public:
	CAttrHashedTableIter(CAttrHashedTable* pObject, BOOL bAtEnd = FALSE)
	{
		m_pTable = NULL;
		m_nIndex = 0;
		m_bValid = FALSE;

		Initialize(pObject, bAtEnd);
	}

	CAttrHashedTableIter(CAttrHashedTableIter& iter)
	{
		m_pTable = iter.m_pTable;
		m_nIndex = iter.m_nIndex;
		m_bValid = iter.m_bValid;
		m_ListIter = iter.m_ListIter;
	}

	CAttrHashedTableIter();
	virtual ~CAttrHashedTableIter();
};


class CAttrHashedTable  
{
friend class CAttrHashedTableIter;

private:
	CAttrList**				m_ppAttributeList;
	int						m_nLength;
	int						m_nLowestBucket;
	int						m_nHighestBucket;
	int						m_nCount;

private:
	BOOL					Initialize(int nLength);
	int						Hashed(CTIndex* pObject);

	CAttrProperties* InsertInList(CAttrList& list, CAttrProperties* pObject)
	{
		return list.InsertAndReplace(pObject);
	}

	CAttrProperties* FindInList(CAttrList& list, CTIndex& TIndex, LPCTSTR lpCreator)
	{
		return list.FindItem(TIndex, lpCreator);
	}

	CAttrProperties* RemoveInList(CAttrList& list, CTIndex& TIndex, LPCTSTR lpCreator)
	{
		CAttrProperties* pItem = FindInList(list, TIndex, lpCreator);
		list.remove(pItem);
		return pItem;
	}

public:
	int						GetSize()	{ return m_nCount; }
	BOOL					Put(CAttrProperties* pObject);
	CAttrProperties*		Get(CTIndex& TIndex, LPCTSTR lpCreator);
	BOOL					Del(CTIndex& TIndex, LPCTSTR lpCreator);

	CAttrHashedTableIter	Begin()		{ CAttrHashedTableIter iter(this);			return iter; }
	CAttrHashedTableIter	End()		{ CAttrHashedTableIter iter(this, TRUE);	return iter; }

public:
	CAttrHashedTable(int nLength)
	{
		m_ppAttributeList = NULL;
		m_nLength = nLength;
		m_nLowestBucket = 0;
		m_nHighestBucket = 0;
		m_nCount = 0;

		Initialize(nLength);
	}

	CAttrHashedTable();
	virtual ~CAttrHashedTable();
};


class CAttributeTable  
{
public:
	struct CSingleAttribute
	{
		Uint16				nGNumber;
		Uint16				nENumber;
		Uint16				nGRange;
		Uint16				nERange;
		E_VR				eVR;
		LPCTSTR				lpName;
		int					nMinVM;
		int					nMaxVM;
		LPCTSTR				lpStandardVersion;
		E_RANGE_RESTRICTION	eGRestriction;
		E_RANGE_RESTRICTION	eERestriction;
		LPCTSTR				lpPrivateCreator;
	};

private:
	CAttrHashedTable		m_HashedTable;
	CAttrList				m_RepeatList;
	int						m_nSkeletonCount;
	BOOL					m_bLoaded;

private:
	CAttrProperties*		MakeSkeletonItem(Uint16 nGNumber, Uint16 nENumber, Uint16 nGRange, Uint16 nERange, E_VR eVR, LPCTSTR lpName, int nMixVM, int nMaxVM, LPCTSTR lpVersion, E_RANGE_RESTRICTION eGRestriction, E_RANGE_RESTRICTION eERestriction, LPCTSTR lpCreator);
	BOOL					LoadSkeletonTable();
	BOOL					LoadAttributeTable();

public:
	int						GetSkeletonNumber()		{ return m_nSkeletonCount; }
	int						GetNormalNumber()		{ return m_HashedTable.GetSize(); }
	int						GetRepeatNumber()		{ return m_RepeatList.size(); }
	int						GetNumber()				{ return GetNormalNumber() + GetRepeatNumber() - m_nSkeletonCount; }
	BOOL					AddItem(CAttrProperties* pItem);
	BOOL					DeleteItem(CAttrProperties& Properties);

	CAttrHashedTableIter	NormalBegin()			{ return m_HashedTable.Begin(); }
	CAttrHashedTableIter	NormalEnd()				{ return m_HashedTable.End(); }
	CAttrListIter			RepeatBegin()			{ return m_RepeatList.begin(); }
	CAttrListIter			RepeatEnd()				{ return m_RepeatList.end(); }

public:
	static BOOL				IsLoaded();
	static CAttrProperties*	FindItem(CTIndex& TIndex, LPCTSTR lpCreator);
	static CAttrProperties*	FindItem(LPCTSTR lpName);
	static CAttrProperties*	FindItem(CAttrProperties& Properties);

public:
	CAttributeTable();
	virtual ~CAttributeTable();
};

#endif // !defined(AFX_ATTRIBUTETABLE_H__6069BAD6_4C7A_40BB_9A83_B6E71966721F__INCLUDED_)
