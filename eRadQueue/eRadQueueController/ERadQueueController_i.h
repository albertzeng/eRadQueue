/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Mar 10 14:34:53 2014
 */
/* Compiler settings for D:\MyCode\eRadQueue\eRadQueue\eRadQueueController\eRadQueueController.odl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __ERadQueueController_i_h__
#define __ERadQueueController_i_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IERadQueueController_FWD_DEFINED__
#define __IERadQueueController_FWD_DEFINED__
typedef interface IERadQueueController IERadQueueController;
#endif 	/* __IERadQueueController_FWD_DEFINED__ */


#ifndef __ERadQueueController_FWD_DEFINED__
#define __ERadQueueController_FWD_DEFINED__

#ifdef __cplusplus
typedef class ERadQueueController ERadQueueController;
#else
typedef struct ERadQueueController ERadQueueController;
#endif /* __cplusplus */

#endif 	/* __ERadQueueController_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __ERadQueueController_LIBRARY_DEFINED__
#define __ERadQueueController_LIBRARY_DEFINED__

/* library ERadQueueController */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ERadQueueController;

#ifndef __IERadQueueController_DISPINTERFACE_DEFINED__
#define __IERadQueueController_DISPINTERFACE_DEFINED__

/* dispinterface IERadQueueController */
/* [uuid] */ 


EXTERN_C const IID DIID_IERadQueueController;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EC77BB09-1E78-4244-A274-F6D9772085DC")
    IERadQueueController : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IERadQueueControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IERadQueueController __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IERadQueueController __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IERadQueueController __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IERadQueueController __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IERadQueueController __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IERadQueueController __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IERadQueueController __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IERadQueueControllerVtbl;

    interface IERadQueueController
    {
        CONST_VTBL struct IERadQueueControllerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IERadQueueController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IERadQueueController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IERadQueueController_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IERadQueueController_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IERadQueueController_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IERadQueueController_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IERadQueueController_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IERadQueueController_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ERadQueueController;

#ifdef __cplusplus

class DECLSPEC_UUID("24FCB792-8383-4EB6-9205-A4ECDFF5D8FA")
ERadQueueController;
#endif
#endif /* __ERadQueueController_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
