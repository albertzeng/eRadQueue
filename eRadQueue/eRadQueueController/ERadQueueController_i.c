/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Mar 10 14:34:53 2014
 */
/* Compiler settings for D:\MyCode\eRadQueue\eRadQueue\eRadQueueController\eRadQueueController.odl:
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

const IID LIBID_ERadQueueController = {0xF2192893,0x7FA6,0x44FE,{0x95,0xE9,0x5C,0x05,0xC4,0xA6,0xC3,0xA4}};


const IID DIID_IERadQueueController = {0xEC77BB09,0x1E78,0x4244,{0xA2,0x74,0xF6,0xD9,0x77,0x20,0x85,0xDC}};


const CLSID CLSID_ERadQueueController = {0x24FCB792,0x8383,0x4EB6,{0x92,0x05,0xA4,0xEC,0xDF,0xF5,0xD8,0xFA}};


#ifdef __cplusplus
}
#endif

