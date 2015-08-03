// XmlParse.cpp: implementation of the CXmlParse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XmlParse.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXmlParse::CXmlParse()
{
	CoInitialize(NULL);

	this->m_pDocument = NULL;
}

CXmlParse::~CXmlParse()
{
	if (this->m_pDocument != NULL) this->m_pDocument->Release();

	CoUninitialize();
}

MRET CXmlParse::Open()
{
	if (this->m_pDocument != NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	HRESULT hr = CoCreateInstance(__uuidof(DOMDocument30),
								  NULL,
								  CLSCTX_INPROC_SERVER,
								  __uuidof(IXMLDOMDocument),
								  (void**)&this->m_pDocument);
	
	if (!FAILED(hr))
		hr = this->m_pDocument->put_async(VARIANT_FALSE);
	if (!FAILED(hr))
		hr = this->m_pDocument->put_validateOnParse(VARIANT_FALSE);
	if (!FAILED(hr))
		hr = this->m_pDocument->put_resolveExternals(VARIANT_FALSE);
	if (!FAILED(hr))
		hr = this->m_pDocument->put_preserveWhiteSpace(VARIANT_TRUE);
	
	if (FAILED(hr))
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}
	
	return ME_OK;
}

MRET CXmlParse::AddPINode()
{
	if (this->m_pDocument == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	BSTR bstr = ::SysAllocString(L"xml");
	BSTR bstrPI = ::SysAllocString(L"version='1.0'");
	IXMLDOMProcessingInstruction* PI = NULL;
	HRESULT hr = this->m_pDocument->createProcessingInstruction(bstr, bstrPI, &PI);

	if (bstr) SysFreeString(bstr);
	if (bstrPI) SysFreeString(bstrPI);
	bstr = NULL;
	bstrPI = NULL;

	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	IXMLDOMNode* pNode = NULL;
	hr = this->m_pDocument->appendChild(PI, &pNode);

	if (PI != NULL) PI->Release();

	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	if (pNode != NULL) pNode->Release();

	return ME_OK;
}

MRET CXmlParse::LoadXml()
{
	MRET rc = this->Open();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	rc = this->AddPINode();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	return ME_OK;
}

MRET CXmlParse::LoadXml(CString strXml)
{
	MRET rc = this->Open();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	BSTR bstr = strXml.AllocSysString();
	VARIANT_BOOL vStatus = VARIANT_TRUE;
	HRESULT hr = this->m_pDocument->loadXML(bstr, &vStatus);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (FAILED(hr) || vStatus != VARIANT_TRUE)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	return ME_OK;
}

MRET CXmlParse::SaveXml(CString& strXml)
{
	if (this->m_pDocument == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	BSTR bstr = NULL;
	HRESULT hr = this->m_pDocument->get_xml(&bstr);

	strXml = bstr;

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	return ME_OK;
}

MRET CXmlParse::LoadFile(CString strFile)
{
	MRET rc = this->Open();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	VARIANT_BOOL vStatus = VARIANT_TRUE;
	HRESULT hr = this->m_pDocument->load(COleVariant(strFile), &vStatus);	
	if (FAILED(hr) || vStatus != VARIANT_TRUE) 
	{	
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	return ME_OK;
}

MRET CXmlParse::SaveFile(CString strFile)
{
	if (this->m_pDocument == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	HRESULT hr = this->m_pDocument->save(COleVariant(strFile));
	if (FAILED(hr)) 
	{	
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	return ME_OK;
}

MRET CXmlParse::GetFirstChildNode(IXMLDOMNode* pParent, IXMLDOMNode** ppNode)
{
	if (this->m_pDocument == NULL || ppNode == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	*ppNode = NULL;

	IXMLDOMElement* pElement = NULL;
	HRESULT hr = this->m_pDocument->get_documentElement(&pElement);
	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	IXMLDOMNode* pNode = NULL;
	if (pParent != NULL)
		hr = pParent->get_firstChild(&pNode);
	else
		hr = pElement->get_firstChild(&pNode);

	if (pElement) pElement->Release();

	if (FAILED(hr))
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	*ppNode = pNode;

	return ME_OK;
}

MRET CXmlParse::GetNextSiblingNode(IXMLDOMNode* pNode, IXMLDOMNode** ppNode)
{
	if (pNode == NULL || ppNode == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	*ppNode = NULL;

	IXMLDOMNode* pSibling = NULL;
	HRESULT hr = pNode->get_nextSibling(&pSibling);
	if (FAILED(hr))
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	*ppNode = pSibling;

	return ME_OK;
}

MRET CXmlParse::GetNodes(CString strNode, IXMLDOMNodeList** ppNodes)
{
	if (this->m_pDocument == NULL || ppNodes == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	*ppNodes = NULL;

	IXMLDOMNodeList* pNodes = NULL;

	CString strBuffer;
	strBuffer.Format(_T("//%s/*"), strNode);
	BSTR bstr = strBuffer.AllocSysString();
	HRESULT hr = this->m_pDocument->selectNodes(bstr, &pNodes);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		if (pNodes) pNodes->Release();
		LOG_RET_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);
	}

	*ppNodes = pNodes;

	return ME_OK;
}

MRET CXmlParse::GetSingleNode(IXMLDOMNode* pParent, CString strNode, IXMLDOMNode** ppNode)
{
	if (this->m_pDocument == NULL || ppNode == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	*ppNode = NULL;

	IXMLDOMNode* pNode = NULL;
	if (pParent == NULL)
	{
		CString strBuffer;
		strBuffer.Format(_T("//%s"), strNode);
		BSTR bstr = strBuffer.AllocSysString();
		HRESULT hr = this->m_pDocument->selectSingleNode(bstr, &pNode);

		if (bstr) SysFreeString(bstr);
		bstr = NULL;

		if (hr != S_OK)
		{
			if (pNode) pNode->Release();
			LOG_RET_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);
		}
	}
	else
	{
		CString strBuffer;
		strBuffer.Format(_T("//%s"), strNode);
		BSTR bstr = strBuffer.AllocSysString();
		HRESULT hr = pParent->selectSingleNode(bstr, &pNode);

		if (bstr) SysFreeString(bstr);
		bstr = NULL;

		if (hr != S_OK)
		{
			if (pNode) pNode->Release();
			LOG_RET_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);
		}
	}

	*ppNode = pNode;

	return ME_OK;
}

MRET CXmlParse::GetNodeName(IXMLDOMNode* pNode, CString& strName)
{
	if (this->m_pDocument == NULL || pNode == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	strName.Empty();

	BSTR bstr = NULL;

	HRESULT hr = pNode->get_nodeName(&bstr);

	strName = bstr;
	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	return ME_OK;
}

MRET CXmlParse::GetNodeValue(IXMLDOMNode* pNode, CString& strValue)
{
	if (this->m_pDocument == NULL || pNode == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	strValue.Empty();

	CString strBuffer;

	IXMLDOMNode* pChild = NULL;
	MRET rc = this->GetFirstChildNode(pNode, &pChild);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	if (pChild != NULL)
	{
		CString strName;
		BSTR bstr = NULL;

		HRESULT hr = pChild->get_nodeTypeString(&bstr);

		strName = bstr;
		if (bstr) SysFreeString(bstr);
		bstr = NULL;

		if (hr != S_OK)
		{
			if (pChild) pChild->Release();

			LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
		}

		if (strName.Compare(_T("text")) != 0)
		{
			if (pChild) pChild->Release();

			LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, strName);
		}

		hr = pChild->get_text(&bstr);

		if (pChild) pChild->Release();

		strBuffer = bstr;
		if (bstr) SysFreeString(bstr);
		bstr = NULL;

		this->Decode(strBuffer, strValue);

		if (FAILED(hr))
		{
			LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
		}
	}

	return ME_OK;
}

MRET CXmlParse::AddSpace(IXMLDOMNode* pParent, CString strSpace)
{
	if (this->m_pDocument == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
	}

	if (pParent == NULL) pParent = this->m_pDocument;

	BSTR bstr = strSpace.AllocSysString();
	IXMLDOMText* pSpace = NULL;
	HRESULT hr = this->m_pDocument->createTextNode(bstr, &pSpace);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	IXMLDOMNode* pNode = NULL;
	hr = pParent->appendChild(pSpace, &pNode);

	if (pSpace != NULL) pSpace->Release();

	if (hr != S_OK)
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr);
	}

	if (pNode != NULL) pNode->Release();

	return ME_OK;
}

IXMLDOMNode* CXmlParse::AddNode(IXMLDOMNode* pParent, CString strNode, CString strValue)
{
	if (this->m_pDocument == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);

		return NULL;
	}

	if (pParent == NULL) pParent = this->m_pDocument;

	BSTR bstr = strNode.AllocSysString();
	IXMLDOMElement* pElement = NULL;
	HRESULT hr = this->m_pDocument->createElement(bstr, &pElement);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		return NULL;
	}

	bstr = SysAllocString(L"value");
	IXMLDOMAttribute* pValue = NULL;
	hr = this->m_pDocument->createAttribute(bstr, &pValue);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		if (pElement != NULL) pElement->Release();
		return NULL;
	}

	bstr = strValue.AllocSysString();
	VARIANT VAR;
	VariantInit(&VAR);
	V_BSTR(&VAR) = SysAllocString(bstr);
	V_VT(&VAR) = VT_BSTR;
	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	hr = pValue->put_value(VAR);

	VariantClear(&VAR);

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		if (pValue) pValue->Release();
		if (pElement != NULL) pElement->Release();
		return NULL;
	}

	IXMLDOMAttribute* pValue1 = NULL;
	hr = pElement->setAttributeNode(pValue, &pValue1);

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		if (pValue) pValue->Release();
		if (pElement != NULL) pElement->Release();
		return NULL;
	}

	if (pValue1) pValue1->Release();
	if (pValue) pValue->Release();

	IXMLDOMNode* pNode = NULL;
	hr = pParent->appendChild(pElement, &pNode);

	if (pElement != NULL) pElement->Release();

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		return NULL;
	}

	return pNode;
}

IXMLDOMNode* CXmlParse::AddNode(IXMLDOMNode* pParent, CString strNode, UINT nValue)
{
	CString strValue;
	strValue.Format(_T("%d"), nValue);

	return this->AddNode(pParent, strNode, strValue);
}

IXMLDOMNode* CXmlParse::AddNode(IXMLDOMNode* pParent, CString strNode, LONG nValue)
{
	CString strValue;
	strValue.Format(_T("%d"), nValue);

	return this->AddNode(pParent, strNode, strValue);
}

IXMLDOMNode* CXmlParse::AddNode(IXMLDOMNode* pParent, CString strNode, BOOL bValue)
{
	CString strValue;
	strValue.Format(_T("%d"), bValue);

	return this->AddNode(pParent, strNode, strValue);
}

IXMLDOMNode* CXmlParse::AddNode(IXMLDOMNode* pParent, CString strNode, double dblValue)
{
	CString strValue;
	strValue.Format(_T("%f"), dblValue);

	return this->AddNode(pParent, strNode, strValue);
}

BOOL CXmlParse::GetValue(IXMLDOMNode* pParent, CString strNode, CString& strValue)
{
	if (pParent == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);

		return FALSE;
	}

	BSTR bstr = strNode.AllocSysString();
	IXMLDOMNode* pSubNode = NULL;
	HRESULT hr = pParent->selectSingleNode(bstr, &pSubNode);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		return FALSE;
	}

	IXMLDOMNamedNodeMap* pAttributes = NULL;
	hr = pSubNode->get_attributes(&pAttributes);

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		if (pSubNode != NULL) pSubNode->Release();
		return FALSE;
	}

	bstr = SysAllocString(L"value");
	IXMLDOMNode* pAttribute = NULL;
	hr = pAttributes->getNamedItem(bstr, &pAttribute);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		if (pAttributes != NULL) pAttributes->Release();
		if (pSubNode != NULL) pSubNode->Release();
		return FALSE;
	}

	VARIANT VAR;
	VariantInit(&VAR);
	hr = pAttribute->get_nodeValue(&VAR);

	if (pAttribute != NULL) pAttribute->Release();
	if (pAttributes != NULL) pAttributes->Release();
	if (pSubNode != NULL) pSubNode->Release();

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		VariantClear(&VAR);
		return FALSE;
	}

	strValue = VAR.bstrVal;
	VariantClear(&VAR);

	return TRUE;
}

BOOL CXmlParse::GetValue(IXMLDOMNode* pParent, CString strNode, UINT& nValue)
{
	CString strValue;
	if (this->GetValue(pParent, strNode, strValue))
	{
		strValue.TrimLeft();
		strValue.TrimRight();
		if (!strValue.IsEmpty())
		{
			nValue = atoi(strValue);

			return TRUE;
		}
	}

	return FALSE;
}

BOOL CXmlParse::GetValue(IXMLDOMNode* pParent, CString strNode, LONG& nValue)
{
	CString strValue;
	if (this->GetValue(pParent, strNode, strValue))
	{
		strValue.TrimLeft();
		strValue.TrimRight();
		if (!strValue.IsEmpty())
		{
			nValue = atoi(strValue);

			return TRUE;
		}
	}

	return FALSE;
}

BOOL CXmlParse::GetValue(IXMLDOMNode* pParent, CString strNode, BOOL& bValue)
{
	CString strValue;
	if (this->GetValue(pParent, strNode, strValue))
	{
		strValue.TrimLeft();
		strValue.TrimRight();
		if (!strValue.IsEmpty())
		{
			bValue = atoi(strValue);

			return TRUE;
		}
	}

	return FALSE;
}

BOOL CXmlParse::GetValue(IXMLDOMNode* pParent, CString strNode, double& dblValue)
{
	CString strValue;
	if (this->GetValue(pParent, strNode, strValue))
	{
		strValue.TrimLeft();
		strValue.TrimRight();
		if (!strValue.IsEmpty())
		{
			dblValue = atof(strValue);

			return TRUE;
		}
	}

	return FALSE;
}

IXMLDOMNode* CXmlParse::SetNode(IXMLDOMNode* pParent, CString strNode, CString strValue)
{
	if (this->m_pDocument == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);

		return NULL;
	}

	if (pParent == NULL) pParent = this->m_pDocument;

	BSTR bstr = strNode.AllocSysString();
	IXMLDOMElement* pElement = NULL;
	HRESULT hr = this->m_pDocument->createElement(bstr, &pElement);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		return NULL;
	}

	bstr = strValue.AllocSysString();
	hr = pElement->put_text(bstr);

	if (bstr) SysFreeString(bstr);
	bstr = NULL;

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		if (pElement != NULL) pElement->Release();
		return NULL;
	}

	IXMLDOMNode* pNode = NULL;
	hr = pParent->appendChild(pElement, &pNode);

	if (pElement != NULL) pElement->Release();

	if (hr != S_OK)
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, hr, strNode);

		return NULL;
	}

	return pNode;
}

#ifdef USE_LZMINE_DECODE

#include "ModuleLZMINE.h"

static CModuleLZMINE _ModuleLZMINE;

#endif

BOOL CXmlParse::Decode(CString& strInput, CString& strOutput)
{
	strOutput = strInput;

#ifdef USE_LZMINE_DECODE

	_ModuleLZMINE.Decode(&strInput, strOutput);

#endif

	return TRUE;
}
