#include "stdafx.h"
#include "JsonRPCNet.h"
#include "DataCenter.h"
#include "FileUtil.h"
JsonRPCNet::JsonRPCNet()
{
	m_httpClientPtr.reset(new GaiaURL);
	// ����
	m_domainUrl = "http://ss.gaiafintech.com:5542/ccdn";
}

JsonRPCNet::~JsonRPCNet()
{
}

// ��������
bool JsonRPCNet::send(const string& data, string& result)
{
	result = m_httpClientPtr->Post(m_domainUrl, data, data.size(), "");
	if (result.empty()) return false;
	result = StringUtil::Utf8ToGbk(result.c_str());
	return true;
}