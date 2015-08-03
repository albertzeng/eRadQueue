// XmlParse.h: interface for the CXmlParse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLPARSE_H__1AED8601_40C2_48C4_8681_763FA7F35588__INCLUDED_)
#define AFX_XMLPARSE_H__1AED8601_40C2_48C4_8681_763FA7F35588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

#include <MSXML2.H>

#define XML_EXCHANGE_START(XMLSTRING)								\
	CString strNode;												\
	BSTR bstr = NULL;												\
	HRESULT hr = S_OK;												\
	IXMLDOMNode* pRoot = NULL;										\
	IXMLDOMNode* pNode = NULL;										\
	IXMLDOMNodeList* pNodes = NULL;									\
	CXmlParse XmlParse;												\
	if (!bSave) {													\
		MRET rc = XmlParse.LoadXml(XMLSTRING);						\
		if (rc != ME_OK) {											\
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, XMLSTRING);	\
		}															\
	}																\
	else {															\
		MRET rc = XmlParse.LoadXml();								\
		if (rc != ME_OK) {											\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
		pRoot = XmlParse.AddNode(NULL, _T("ROOT"), _T(""));			\
		if (pRoot == NULL) {										\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);		\
		}															\
	}																\


#define XML_EXCHANGE_CLOSE(XMLSTRING)								\
	if (bSave) {													\
		XmlParse.AddSpace(pRoot, _T("\n"));							\
		if (pRoot != NULL) pRoot->Release();						\
		MRET rc = XmlParse.SaveXml(XMLSTRING);						\
		if (rc != ME_OK) {											\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
	}																\


#define XML_FILE_EXCHANGE_START(XMLFILE)							\
	CString strNode;												\
	BSTR bstr = NULL;												\
	HRESULT hr = S_OK;												\
	IXMLDOMNode* pRoot = NULL;										\
	IXMLDOMNode* pNode = NULL;										\
	IXMLDOMNodeList* pNodes = NULL;									\
	CXmlParse XmlParse;												\
	if (!bSave) {													\
		MRET rc = XmlParse.LoadFile(XMLFILE);						\
		if (rc != ME_OK) {											\
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, XMLFILE);		\
		}															\
	}																\
	else {															\
		MRET rc = XmlParse.LoadXml();								\
		if (rc != ME_OK) {											\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
		pRoot = XmlParse.AddNode(NULL, _T("ROOT"), _T(""));			\
		if (pRoot == NULL) {										\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);		\
		}															\
	}																\


#define XML_FILE_EXCHANGE_CLOSE(XMLFILE)							\
	if (bSave) {													\
		XmlParse.AddSpace(pRoot, _T("\n"));							\
		if (pRoot != NULL) pRoot->Release();						\
		MRET rc = XmlParse.SaveFile(XMLFILE);						\
		if (rc != ME_OK) {											\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);					\
		}															\
	}																\


#define XML_EXCHANGE_VALUE(NAME, MEMBER, DEFAULT)					\
	if (!bSave) {													\
		if (!pXmlParse->GetValue(pNode, NAME, MEMBER)) MEMBER = DEFAULT;	\
	}																\
	else {															\
		if (lpSpace != NULL) pXmlParse->AddSpace(pNode, lpSpace);	\
		IXMLDOMNode* pSubNode = pXmlParse->AddNode(pNode, NAME, MEMBER);	\
		if (pSubNode == NULL)										\
			return FALSE;											\
		if (pSubNode != NULL) pSubNode->Release();					\
	}																\


#define XML_EXCHANGE_KEY(NAME, MEMBER)								\
	if (!bSave) {													\
		MRET rc = XmlParse.GetSingleNode(NULL, NAME, &pNode);		\
		if (rc != ME_OK) {											\
			LOG_ERROR(LL_ERROR | LD_FILE, rc);						\
		}															\
		if (pNode == NULL)											\
			MEMBER->ExchangeXML(NULL, NULL, bSave);					\
		else														\
			MEMBER->ExchangeXML(&XmlParse, pNode, bSave);			\
		if (pNode != NULL) pNode->Release();						\
	}																\
	else {															\
		XmlParse.AddSpace(pRoot, _T("\n  "));						\
		pNode = XmlParse.AddNode(pRoot, NAME, _T(""));				\
		if (pNode == NULL) {										\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);		\
		}															\
		else {														\
			MEMBER->ExchangeXML(&XmlParse, pNode, bSave, _T("\n    "));	\
			XmlParse.AddSpace(pNode, _T("\n  "));					\
		}															\
		if (pNode != NULL) pNode->Release();						\
	}																\


#define XML_EXCHANGE_KEY_GROUP(NAME, TYPE, MEMBER)					\
	if (!bSave) {													\
		MRET rc = XmlParse.GetNodes(NAME, &pNodes);					\
		if (rc != ME_OK) {											\
			LOG_ERROR(LL_ERROR | LD_FILE, rc);						\
		}															\
		if (pNodes != NULL) {										\
			LONG nSize = 0;											\
			pNodes->get_length(&nSize);								\
			for (LONG i = 0; i < nSize; i++) {						\
				hr = pNodes->get_item(i, &pNode);					\
				if (pNode != NULL) {								\
					TYPE* IT = new TYPE;							\
					IT->ExchangeXML(&XmlParse, pNode, bSave);		\
					(MEMBER)->AddTail(IT);							\
					pNode->Release();								\
				}													\
			}														\
			pNodes->Release();										\
		}															\
	}																\
	else {															\
		pNode = NULL;												\
		TYPE* IT = NULL;											\
		XmlParse.AddSpace(pRoot, _T("\n  "));						\
		IXMLDOMNode* pLst = XmlParse.AddNode(pRoot, NAME, _T(""));	\
		if (pLst != NULL) {											\
			OBPOS POS = NULL;										\
			for (IT = (MEMBER)->GetHead(POS); IT != NULL; IT = (MEMBER)->GetNext(POS)) {	\
				XmlParse.AddSpace(pLst, _T("\n    "));				\
				pNode = XmlParse.AddNode(pLst, _T("SubNode"), _T(""));	\
				if (pNode == NULL || !IT->ExchangeXML(&XmlParse, pNode, bSave, _T("\n      ")))	\
					break;											\
				XmlParse.AddSpace(pNode, _T("\n    "));				\
				if (pNode != NULL) pNode->Release();				\
				pNode = NULL;										\
			}														\
			XmlParse.AddSpace(pLst, _T("\n  "));					\
		}															\
		if (pLst == NULL || IT != NULL) {							\
			if (pNode != NULL) pNode->Release();					\
			if (pLst != NULL) pLst->Release();						\
			if (pRoot != NULL) pRoot->Release();					\
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);		\
		}															\
		if (pLst != NULL) pLst->Release();							\
	}																\


class CXmlParse  
{
protected:
	IXMLDOMDocument*	m_pDocument;

private:
	MRET				Open();
	MRET				AddPINode();

public:
	MRET				LoadXml();
	MRET				LoadXml(CString strXml);
	MRET				SaveXml(CString& strXml);
	MRET				LoadFile(CString strFile);
	MRET				SaveFile(CString strFile);

public:
	MRET				GetFirstChildNode(IXMLDOMNode* pParent, IXMLDOMNode** ppNode);
	MRET				GetNextSiblingNode(IXMLDOMNode* pNode, IXMLDOMNode** ppNode);
	MRET				GetNodes(CString strNode, IXMLDOMNodeList** ppNodes);
	MRET				GetSingleNode(IXMLDOMNode* pParent, CString strNode, IXMLDOMNode** ppNode);
	MRET				GetNodeName(IXMLDOMNode* pNode, CString& strName);
	MRET				GetNodeValue(IXMLDOMNode* pNode, CString& strValue);

public:
	MRET				AddSpace(IXMLDOMNode* pParent, CString strSpace);

public:	// 格式：<XXXX value="XXXX"/>
	IXMLDOMNode*		AddNode	(IXMLDOMNode* pParent, CString strNode, CString strValue);
	IXMLDOMNode*		AddNode	(IXMLDOMNode* pParent, CString strNode, UINT nValue);
	IXMLDOMNode*		AddNode	(IXMLDOMNode* pParent, CString strNode, LONG nValue);
	IXMLDOMNode*		AddNode	(IXMLDOMNode* pParent, CString strNode, BOOL bValue);
	IXMLDOMNode*		AddNode	(IXMLDOMNode* pParent, CString strNode, double dblValue);

public:	// 格式：<XXXX value="XXXX"/>
	BOOL				GetValue(IXMLDOMNode* pParent, CString strNode, CString& strValue);
	BOOL				GetValue(IXMLDOMNode* pParent, CString strNode, UINT& nValue);
	BOOL				GetValue(IXMLDOMNode* pParent, CString strNode, LONG& nValue);
	BOOL				GetValue(IXMLDOMNode* pParent, CString strNode, BOOL& bValue);
	BOOL				GetValue(IXMLDOMNode* pParent, CString strNode, double& dblValue);

public:	// 格式：<XXXX>XXXX</XXXX>
	IXMLDOMNode*		SetNode	(IXMLDOMNode* pParent, CString strNode, CString strValue);

public:
	BOOL				Decode(CString& strIn, CString& strOut);

public:
	CXmlParse();
	virtual ~CXmlParse();
};

#endif // !defined(AFX_XMLPARSE_H__1AED8601_40C2_48C4_8681_763FA7F35588__INCLUDED_)
