#pragma once
#ifndef JsonRPCNet_H
#define JsonRPCNet_H

#include "stdafx.h"
#include "GaiaURL.h"
#include <memory>
class JsonRPCNet
{
public:
	JsonRPCNet();
	~JsonRPCNet();
public:
	// 发送数据
	bool send(const string& data, string& result);
private:
	unique_ptr<GaiaURL> m_httpClientPtr;
	// 域名
	string m_domainUrl;
};

#endif // !JsonRPCNet_H
