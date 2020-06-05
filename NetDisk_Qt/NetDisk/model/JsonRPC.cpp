#include "stdafx.h"
#include "JsonRPC.h"
#include "MathUtil.h"
JsonRPCRequest::JsonRPCRequest()
{
	this->id = MathUtil::getUniqueId();
	this->jsonrpc = "2.0";
}

JsonRPCRequest::~JsonRPCRequest()
{
}

Json::Value JsonRPCRequest::toJson()
{
	Json::Value value;
	value["jsonrpc"] = this->jsonrpc;
	value["id"] = this->id;
	value["method"] = this->method;

	Json::Value params;
	if (this->params.size() > 0)
	{
		for each(string param in this->params)
		{
			params.append(param);
		}
	}
	if (this->arrayParams.size() > 0)
	{
		Json::Value arrayParams;
		for each(string param in this->arrayParams)
		{
			arrayParams.append(param);
		}
		params.append(arrayParams);
	}
	value["params"] = params;
	return value;
}

string JsonRPCRequest::toJsonStr()
{
	string str = this->toJson().toStyledString();
	return str;
}

JsonRPC::JsonRPC()
{
	this->id = 0;
}

JsonRPC::~JsonRPC()
{
}

JsonRPC* JsonRPC::parse()
{
	return this;
}

bool JsonRPC::isEmpty()
{
	return false;
}