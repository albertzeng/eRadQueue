/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Mar 13 16:35:28 2014
 */
/* Compiler settings for D:\MyCode\eRadQueue\eRadQueue\eRadQueueCall\eRadQueueCall.odl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_ERadQueueCall = {0x2189BAA1,0x7DD1,0x4B46,{0xBF,0x3F,0x27,0x93,0xA9,0x42,0x8C,0x0F}};


#ifdef __cplusplus
}
#endif

