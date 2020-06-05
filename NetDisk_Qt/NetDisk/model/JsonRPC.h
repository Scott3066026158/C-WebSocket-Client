
#pragma once
#ifndef JSON_RPC_H
#define JSON_RPC_H

#include "stdafx.h"
#include "Json.h"
// JsonRPC����ṹ
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
	// ���ù��̱�ʶ
	string method;
	// �������
	vector<string> params;
	vector<string> arrayParams;
	// ����id
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
	// �汾
	string jsonrpc;
	// id
	int id;
};
#endif //!JSON_RPC_H