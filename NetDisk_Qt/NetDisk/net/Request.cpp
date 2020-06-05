#include "stdafx.h"
#include "Request.h"
#include "DataCenter.h"
#include "JsonRPC.h"
#include "Json.h"
#include "MathUtil.h"
Request::Request()
{
	// http�������
	this->net = DataCenter::getJsonRPCNet();
}

Request::~Request()
{
}

// ��ȡ�ͻ��˰汾
bool Request::getClientVersion(string& version)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "clientVersion";
	string result;
	if (net->send(p->toJsonStr(), result)) return false;
	return parse(result, version);
}

// ��ȡ�û��ļ���
bool Request::getFileDirectories(const string& addr, UserDirectories& fileDirs)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "getFileDirectories";
	p->params.push_back(addr);
	string result;
	if (this->net->send(p->toJsonStr(), result) == false) return false;
	return parse<UserDirectories>(result, fileDirs);
}

// ��ȡ�ʻ��洢��
bool Request::getStorageBalance(const string& addr, unsigned long long& storage)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "getStorageBalance";
	p->params.push_back(addr);
	string jsonStr;
	if (net->send(p->toJsonStr(), jsonStr) == false) return false;
	string result;
	if (parse(jsonStr, result) == false) return false;
	return MathUtil::toDec(result, storage);
}

// ��ȡ�û��ļ��б�
bool Request::getFiles(const string& addr, UserFiles& storage)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "getFiles";
	p->params.push_back(addr);
	string result;
	if (net->send(p->toJsonStr(), result) == false) return false;
	return parse<UserFiles>(result, storage);
}

// ��ȡ�û��ļ����ܴ�С��λ(�ֽ�)
bool Request::getTotalFileLength(const string& addr, unsigned long long& storage)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "getTotalFileLength";
	p->params.push_back(addr);
	string jsonStr;
	if (net->send(p->toJsonStr(), jsonStr) == false) return false;
	string result;
	if (parse(jsonStr, result) == false) return false;
	return MathUtil::toDec(result, storage);
}

// ����ָ��Ŀ¼�µ��б�
bool Request::getDirectoryFiles(const string& addr, const string& directoryId, UserFiles& files)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "getDirectoryFiles";
	p->params.push_back(addr);
	p->params.push_back(directoryId);
	string result;
	if (net->send(p->toJsonStr(), result) == false) return false;
	return parse(result, files);
}

// �����ļ��л�����ļ���
bool Request::sendFileDirectory(const string& addr, const CurrentFileSummary& directoryInfo, DirectoryUpdateInfo& updateInfo)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "sendFileDirectory";
	p->params.push_back(addr);
	p->params.push_back(directoryInfo.toJsonStr());
	string result;
	if (net->send(p->toJsonStr(), result) == false) return false;
	return parse<DirectoryUpdateInfo>(result, updateInfo);
}

// ��ȡ�ļ���״̬
bool Request::getFileDirectoryState(const string& addr, const string& directoryId, DirectoryUpdateInfo& updateInfo)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "sendFileDirectory";
	p->params.push_back(addr);
	p->params.push_back(directoryId);
	string result;
	if (net->send(p->toJsonStr(), result) == false) return false;
	return parse<DirectoryUpdateInfo>(result, updateInfo);
}

// ��ȡĬ�˶�����
bool Request::getMerkleTreeRoot(vector<string>& params)
{
	unique_ptr<JsonRPCRequest> p(new JsonRPCRequest);
	p->method = "sendFileDirectory";
	p->arrayParams = params;
	string result;
	if (net->send(p->toJsonStr(), result) == false) return false;
	return false;
}

// ����Json����
bool Request::parse(const string& jsonStr, Json::Value& result)
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(jsonStr, root) == false) return false;
	JsonRPC jsonRpc;
	if (root.isMember("jsonrpc") == false || root["jsonrpc"].isString() == false) return false;
	if (root.isMember("id") == false || root["id"].isInt64() == false) return false;
	if (root.isMember("result") == false) return false;
	jsonRpc.id = root["id"].asInt64();
	jsonRpc.jsonrpc = root["jsonrpc"].asString();
	result = root["result"];
	return true;
}

// ����Json����
bool Request::parse(const string& jsonStr, string& result)
{
	Json::Value value;
	if (parse(jsonStr, value) == false) return false;
	result = value.asString();
	return true;
}

// ����Json����
template<class _Ty> bool Request::parse(const string& jsonStr, _Ty& result)
{
	Json::Value value;
	if (parse(jsonStr, value) == false) return false;
	_Ty* result_ptr = result.parse(value);
	return result_ptr->isEmpty();
}