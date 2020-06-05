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
	// http�������
	JsonRPCNet* net;
public:
	// ��ȡ�ͻ��˰汾
	bool getClientVersion(string& version);
	// ��ȡ�ļ�Ŀ¼
	bool getFileDirectories(const string& addr, UserDirectories& fileDirs);
	// ��ȡ�ʻ��洢��
	bool getStorageBalance(const string& addr, unsigned long long& storage);
	// ��ȡ�û��ļ��б�
	bool getFiles(const string& addr, UserFiles& storage);
	// ��ȡ�û��ļ����ܴ�С��λ(�ֽ�)
	bool getTotalFileLength(const string& addr, unsigned long long& size);
	// ����ָ��Ŀ¼�µ��б�
	bool getDirectoryFiles(const string& addr, const string& directoryId, UserFiles& files);
	// �����ļ��л�����ļ���
	bool sendFileDirectory(const string& addr, const CurrentFileSummary& directoryInfo, DirectoryUpdateInfo& updateInfo);
	// ��ȡ�ļ���״̬
	bool getFileDirectoryState(const string& addr, const string& directoryId, DirectoryUpdateInfo& updateInfo);
	// ��ȡĬ�˶�����
	bool getMerkleTreeRoot(vector<string>& params);

private:
	// ����Json����
	template<class _Ty> bool parse(const string& jsonStr, _Ty& result);
	// ����Json����
	bool parse(const string& jsonStr, Json::Value& result);
	// ����Json����
	bool parse(const string& jsonStr, string& result);
};

#endif // !__REQUEST_H__

