#include "stdafx.h"
#include "CBase64Algo.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CMimeAlgo::CMimeAlgo()
{

}

CMimeAlgo::~CMimeAlgo()
{

}



//-------------------------------------------------------------
//interface

void CMimeAlgo::Encode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen )
{

	//
	// xxxxxxyy xxxxxxzz xxxxxxpp
	// to 
	// 0xxxxxx1 0xxxxxx1 0xxxxxx1 0yyzzpp1
	//



	outBufLen = (inSrcLen / 3 * 4) + (inSrcLen % 3) + (inSrcLen % 3 ? 1 : 0);
	*outBuf = new unsigned char [outBufLen + 1];//another byte for '\0'
	(*outBuf)[outBufLen] = '\0';//only for easy to use, len not include this byte


	unsigned char * p = *outBuf;//use as cursor
	unsigned char c;//use as worker unit

	for(int i=0; i<inSrcLen; i++ )
	{
		c = inSrcBuf[i] & ~ MakeBitSectionByOrder07(6, 7);
		c = c >> 1;
		* ( p ++ ) = ClearHeadAndSetTail(c);

		if( i % 3 == 2 )
		{
			c = inSrcBuf[i-2] & MakeBitSectionByOrder07(6, 7);
			c = c << 2;
			c |= inSrcBuf[i-1] & MakeBitSectionByOrder07(6, 7);
			c = c << 2;
			c |= inSrcBuf[i] & MakeBitSectionByOrder07(6, 7);
			c = c << 1;
			* ( p ++ ) = ClearHeadAndSetTail(c);
		}
		else if( i == (inSrcLen -1) )
		{
			if( i % 3 == 0 )
			{
				c = inSrcBuf[i] & MakeBitSectionByOrder07(6, 7);
				c = c << 5;
				* ( p ++ ) = ClearHeadAndSetTail(c);
			}
			else if( i % 3 == 1 )
			{
				c = inSrcBuf[i-1] & MakeBitSectionByOrder07(6, 7);
				c = c << 2;
				c = inSrcBuf[i] & MakeBitSectionByOrder07(6, 7);
				c = c << 3;
				* ( p ++ ) = ClearHeadAndSetTail(c);
			}
			else if( i % 3 == 2 )
			{
				; // note here do nothing, the if( i % 3 == 2 ) had done it
			}
		}
	}//for

	ASSERT(outBufLen == (p - *outBuf));
}

void CMimeAlgo::Decode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen )
{
	//
	// 0xxxxxx1 0xxxxxx1 0xxxxxx1 0yyzzpp1
	// to 
	// xxxxxxyy xxxxxxzz xxxxxxpp
	//

	
	outBufLen = (inSrcLen / 4 * 3) + (inSrcLen % 4) - (inSrcLen % 4 ? 1 : 0);
	*outBuf = new unsigned char [outBufLen + 1];//another byte for '\0'
	(*outBuf)[outBufLen] = '\0';//only for easy to use, len not include this byte


	unsigned char * p = *outBuf;//use as cursor
	unsigned char c;

	for(int i=0; i<inSrcLen; i++ )
	{
		if( i % 4 == 3 )
		{
			c = inSrcBuf[i] & MakeBitSectionByOrder07(1, 2);
			c = c >> 5;
			* (p - 3) |= c;

			c |= inSrcBuf[i] & MakeBitSectionByOrder07(3, 4);
			c = c >> 3;
			* (p - 2) |= c;

			c |= inSrcBuf[i] & MakeBitSectionByOrder07(5, 6);
			c = c >> 1;
			* (p - 1) |= c;
		}
		else
		{
			if( i != (inSrcLen -1) )
			{
				c = inSrcBuf[i];
				c = c << 1;
				* ( p ++ ) = c;
			}
			else
			{
				if( i % 4 == 0 )
				{
					; // not imposible // because inBuf is encoded before by EncodeEvery3ByteTo4Byte()
				}
				else if( i % 4 == 1 )
				{
					c = inSrcBuf[i] & MakeBitSectionByOrder07(1, 2);
					c = c >> 5;
					* (p - 1) |= c;
				}
				else if( i % 4 == 2 )
				{
					c = inSrcBuf[i] & MakeBitSectionByOrder07(1, 2);
					c = c >> 5;
					* (p - 2) |= c;

					c |= inSrcBuf[i] & MakeBitSectionByOrder07(3, 4);
					c = c >> 3;
					* (p - 1) |= c;
				}
				else if( i % 4 == 3 )
				{
					; // note here do nothing, the if( i % 4 == 3 ) had done it
				}
			}

		}//if
	}//for

	ASSERT(outBufLen == (p - *outBuf));
}



//-------------------------------------------------------------
//basic helper

inline bool CMimeAlgo::TestBitByOrder07(unsigned char inChar, int inWhich)
{
	if( (inChar & MakeBitByOrder07(inWhich)) == 0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}

inline unsigned char CMimeAlgo::MakeBitByOrder07(int inWhich)
{
	return 1U << (7-inWhich) ;
}

inline unsigned char CMimeAlgo::MakeBitSectionByOrder07(int inFrom, int inTo)
{
	unsigned char c = 0x00;
	for(int k = inFrom; k <= inTo; k++)
	{
		SetBitByOrder07(c, k);
	}
	return c;
}

inline unsigned char CMimeAlgo::SetBitByOrder07(unsigned char & inoutChar, int inWhich)
{
	inoutChar |= MakeBitByOrder07(inWhich);
	return inoutChar;
}

inline unsigned char CMimeAlgo::ClearBitByOrder07(unsigned char & inoutChar, int inWhich)
{
	inoutChar &= ~ MakeBitByOrder07(inWhich);
	return inoutChar;
}

inline unsigned char CMimeAlgo::ClearHeadAndSetTail( unsigned char & inoutChar )
{
	ClearBitByOrder07(inoutChar, 0);
	SetBitByOrder07(inoutChar, 7);
	//now inoutChar is like 0xxx xxx1
	return inoutChar;
}


//-------------------------------------------------------------
//con de

CBase64Algo::CBase64Algo()
{
	unsigned char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+#";
	for( int i = 0; i < 64; i ++ )
	{
		mArr[i] = arr[i]; //init xxxxxx to char Struct
		mMap.SetAt( arr[i], i ); // init char to xxxxxx Struct
	}
}

CBase64Algo::~CBase64Algo()
{

}

//-------------------------------------------------------------
//overrided

void CBase64Algo::Encode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen )
{
	outBufLen = (inSrcLen / 3 * 4) + (inSrcLen % 3 ? 4 : 0) + 6;
	*outBuf = new unsigned char [outBufLen];//another byte for '\0'
	(*outBuf)[outBufLen] = '\0';//only for easy to use, len not include this byte

	unsigned char * p = *outBuf;//use as cursor
	memcpy(p,"LZMINE",6);
	p+=6;

	for(int i=0; i < inSrcLen / 3; i++ )
	{
		EncodeEvery3Byte(p, inSrcBuf + i * 3);
		p = p + 4;
	}
	//here, i had ++

	if(inSrcLen % 3)
	{
		EncodeEvery3Byte(p, inSrcBuf + i * 3, inSrcLen % 3);
	}
}

void CBase64Algo::Encode( sstring &outBuf, unsigned char * inSrcBuf, int inSrcLen )
{
	LONG outBufLen = (inSrcLen / 3 * 4) + (inSrcLen % 3 ? 4 : 0) + 6;
	outBuf.resize(outBufLen);
//	BYTE * out = new unsigned char [outBufLen];//another byte for '\0'
//	out[outBufLen] = '\0';//only for easy to use, len not include this byte

	unsigned char * p = (BYTE*)&outBuf[0];//use as cursor
	memcpy(p,"LZMINE",6);
	p+=6;

	for(int i=0; i < inSrcLen / 3; i++ )
	{
		EncodeEvery3Byte(p, inSrcBuf + i * 3);
		p = p + 4;
	}
	//here, i had ++

	if(inSrcLen % 3)
	{
		EncodeEvery3Byte(p, inSrcBuf + i * 3, inSrcLen % 3);
	}
//	outBuf.copy((char *)out,strlen((char*)out));
//	outBuf = (char*)out;
//	outBuf.resize();
//	delete out;	
}

void CBase64Algo:: Decode( unsigned char ** outBuf, int & outBufLen, unsigned char * inSrcBuf, int inSrcLen )
{	
	inSrcLen -=6;
	inSrcBuf +=6;
	ASSERT(inSrcLen % 4 == 0);

	outBufLen = (inSrcLen / 4 * 3);//this len now may be bigger, becuase '=' is not ture code
	*outBuf = new unsigned char [outBufLen + 1];//another byte for '\0'
	::memset(*outBuf, '\0', outBufLen + 1);//only for easy to use, len not include this byte //not to decode '=' so fill '\0'
	
	unsigned char * p = *outBuf;//use as cursor
	unsigned char * pi = inSrcBuf ;//use as cursor

	for(int i=0; i < inSrcLen / 4; i++ )
	{
		DecodeEvery4Byte(p, pi + i * 4);
		p = p + 3;
	}

	i = 0;
	for(int k=inSrcLen-1; pi[k]=='='; k--)
	{
		i++;
	}
	outBufLen = outBufLen - i;
}


//-------------------------------------------------------------
//encode helper

inline void CBase64Algo::EncodeEvery3Byte(unsigned char * outBuf, const unsigned char * const inBuf, int inRest /*= 0*/)
{
	ASSERT(inRest >= 0);
	ASSERT(inRest <= 2);


	if(! inRest)
	{
		for(int i = 0; i < 4; i ++)
		{
			* ( outBuf ++ ) = mArr[ Get6Bits( inBuf, i ) ];
		}
	}
	else
	{
		::memset(outBuf, '=', 4);

		unsigned char cccc[4];
		::memset(cccc, 0x00, 4);
		::memcpy(cccc, inBuf, inRest);

		outBuf[0] = mArr[ Get6Bits( cccc, 0 ) ];
		outBuf[1] = mArr[ Get6Bits( cccc, 1 ) ];
		if( inRest == 2 )
		{
			outBuf[2] = mArr[ Get6Bits( cccc, 2 ) ];
		}
	}
}

inline unsigned char CBase64Algo::Get6Bits(const unsigned char * const inBase, int inOffset)
{
	ASSERT(inOffset >= 0);
	ASSERT(inOffset <= 3);

	unsigned char c = 0x00;

	if( inOffset==0 )
	{
		c = inBase[0] & MakeBitSectionByOrder07(0, 5);
		c = c >> 2;
	}
	else if( inOffset==1 )
	{
		c = ( inBase[0] & MakeBitSectionByOrder07(6, 7) ) << 6;
		c |= ( inBase[1] & MakeBitSectionByOrder07(0, 3) ) >> 2;;
		c = c >> 2;
	}
	else if( inOffset==2 )
	{
		c = ( inBase[1] & MakeBitSectionByOrder07(4, 7) ) << 4;;
		c |= ( inBase[2] & MakeBitSectionByOrder07(0, 1) ) >> 4;;
		c = c >> 2;
	}
	else if( inOffset==3 )
	{
		c = inBase[2] & MakeBitSectionByOrder07(2, 7);
		//c = c >> 2;
	}

	return c;
}


//-------------------------------------------------------------
//decode helper

inline void CBase64Algo::DecodeEvery4Byte(unsigned char * outBuf, const unsigned char * const inBuf)
{
	unsigned char b6;
	for(int i = 0; i < 4; i ++)
	{
		if( ! mMap.Lookup( inBuf[i], b6 ) )
		{
			b6 = 0x00;
		}
		Set6Bits( outBuf, i , b6);
	}
}

void CBase64Algo::Set6Bits(unsigned char * outBuf, int inOffset, unsigned char in6Bits)
{
	ASSERT(inOffset >= 0);
	ASSERT(inOffset <= 3);

	if( inOffset==0 )
	{
		in6Bits = in6Bits << 2;
		outBuf[0] |= in6Bits; //1. all inToHere is memset 0x00 //2.  |= make Set6Bits(2) then Set6Bits(1) is also ok
	}
	else if( inOffset==1 )
	{
		in6Bits = in6Bits << 2;
		outBuf[0] |= ( in6Bits & MakeBitSectionByOrder07(0, 1) ) >> 6;
		outBuf[1] |= ( in6Bits & MakeBitSectionByOrder07(2, 5) ) << 2;
	}
	else if( inOffset==2 )
	{
		in6Bits = in6Bits << 2;
		outBuf[1] |= ( in6Bits & MakeBitSectionByOrder07(0, 3) ) >> 4;
		outBuf[2] |= ( in6Bits & MakeBitSectionByOrder07(4, 5) ) << 4;
	}
	else if( inOffset==3 )
	{
		//in6Bits = in6Bits << 2;
		outBuf[2] |= in6Bits;
	}
}

//-------------------------------------------------------------
