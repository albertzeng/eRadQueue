#ifndef _H_CBase64Algo_
#define _H_CBase64Algo_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <vector>
typedef	std::string sstring;
#include <afxtempl.h>
#pragma warning (disable : 4244)
class CMimeAlgo
{
//con de
public:
	CMimeAlgo();
	~CMimeAlgo();

//interface
public:
	virtual void Encode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen );
	virtual void Decode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen );


//implement
protected:
	bool TestBitByOrder07(unsigned char inChar, int inWhich);
	unsigned char MakeBitByOrder07(int inWhich);
	unsigned char MakeBitSectionByOrder07(int inFrom, int inTo);
	unsigned char SetBitByOrder07(unsigned char & inoutChar, int inWhich);
	unsigned char ClearBitByOrder07(unsigned char & inoutChar, int inWhich);
	unsigned char ClearHeadAndSetTail( unsigned char & inoutChar );
};


class CBase64Algo : public CMimeAlgo
{
//con de
public:
	CBase64Algo();
	~CBase64Algo();


//overrided
public:
	virtual void Encode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen );
	virtual void Decode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen );
	void Encode( sstring &outBuf, unsigned char * inSrcBuf, int inSrcLen );

//implement
protected:
	unsigned char mArr[64]; //to help find char from xxxxxx
	CMap<unsigned char, unsigned char, unsigned char, unsigned char> mMap; //to help find xxxxxx from char

	void EncodeEvery3Byte(unsigned char * outBuf, const unsigned char * const inBuf, int inRest = 0);
	unsigned char Get6Bits(const unsigned char * const inBase, int inOffset);

	void DecodeEvery4Byte(unsigned char * outBuf, const unsigned char * const inBuf);
	void Set6Bits(unsigned char * outBuf, int inOffset, unsigned char in6Bits);
};

#endif
