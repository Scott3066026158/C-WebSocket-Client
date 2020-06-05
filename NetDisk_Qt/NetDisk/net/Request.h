#ifndef __REQUEST_H__
#define __REQUEST_H__
#pragma once
#include "stdafx.h"
#include "GaiaURL.h"
#include "UserDirectory.h"
#include "JsonRPC.h"
#include <memory>
#include "JsonRPCNet.h"
#include "UserFile.h"
class Request
{
public:
	Request();
	virtual ~Request();
private:
	// http请求对象
	JsonRPCNet* net;
public:
	// 获取客户端版本
	bool getClientVersion(string& version);
	// 获取文件目录
	bool getFileDirectories(const string& addr, UserDirectories& fileDirs);
	// 获取帐户存储点
	bool getStorageBalance(const string& addr, unsigned long long& storage);
	// 获取用户文件列表
	bool getFiles(const string& addr, UserFiles& storage);
	// 获取用户文件的总大小单位(字节)
	bool getTotalFileLength(const string& addr, unsigned long long& size);
	// 返回指定目录下的列表
	bool getDirectoryFiles(const string& addr, const string& directoryId, UserFiles& files);
	// 创建文件夹或更新文件夹
	bool sendFileDirectory(const string& addr, const CurrentFileSummary& directoryInfo, DirectoryUpdateInfo& updateInfo);
	// 获取文件夹状态
	bool getFileDirectoryState(const string& addr, const string& directoryId, DirectoryUpdateInfo& updateInfo);
	// 获取默克尔树根
	bool getMerkleTreeRoot(vector<string>& params);

private:
	// 解析Json数据
	template<class _Ty> bool parse(const string& jsonStr, _Ty& result);
	// 解析Json数据
	bool parse(const string& jsonStr, Json::Value& result);
	// 解析Json数据
	bool parse(const string& jsonStr, string& result);
};

#endif // !__REQUEST_H__

