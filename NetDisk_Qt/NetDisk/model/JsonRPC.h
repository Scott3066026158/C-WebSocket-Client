
#pragma once
#ifndef JSON_RPC_H
#define JSON_RPC_H

#include "stdafx.h"
#include "Json.h"
// JsonRPC请求结构
class JsonRPCRequest
{
public:
	JsonRPCRequest();
	~JsonRPCRequest();
public:
	Json::Value toJson();
	string toJsonStr();
public:
	// JsonRPC Version
	string jsonrpc;
	// 调用过程标识
	string method;
	// 请求参数
	vector<string> params;
	vector<string> arrayParams;
	// 请求id
	long long id;
};


class JsonRPC
{
public:
	JsonRPC();
	~JsonRPC();
public:
	JsonRPC* parse();
	bool isEmpty();
public:
	// 版本
	string jsonrpc;
	// id
	int id;
};
#endif //!JSON_RPC_H