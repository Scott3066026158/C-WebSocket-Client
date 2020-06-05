#pragma once
#ifndef CCDNService_H
#define CCDNService_H

#include "stdafx.h"
#include "Request.h"
#include <memory>
#include "crypto\\etherkeys.h"
class CCDNService
{
public:
	CCDNService();
	~CCDNService();

public:
	// 登录
	bool login(const string& priKey);
	// 用户获取存储积分
	bool getStorageBalance(unsigned long long& size);
	// 获取用户地址
	bool getUserAddr(string& addr);
	// 获取用户根目录下所有文件和文件夹
	bool getRootFilesAndDirectories(UserFiles& files, UserDirectories& directories);
	// 获取指定目录下的文件和文件夹
	bool getFilesAndDirectories(const string& path, UserFiles& files, UserDirectories& directories);
	// 获取用户的全部图片文件
	bool getUserPhotos(UserFiles& files);
	// 获取用户的全部视频文件
	bool getUserVideos(UserFiles& files);
	// 获取用户的全部文档文件
	bool getUserDocuments(UserFiles& files);
	// 获取用户文件总大小
	bool getTotalFileLength(unsigned long long& size);
	// 获取用户文件夹
	bool getFileDirectories(UserDirectories& fileDirs);
	// 获取用户文件
	bool getFiles(UserFiles& files);
	//计算文件hash
	vector<string> getFileHash(string& fileName, int sliceNum);
	//计算文件分片hash
	bool getFileSliceHashes(string& file, int sliceNum);

private:
	// 获取用户地址
	string getUserAddr(const string& prikey);
	// 过滤非根目录下文件夹
	bool directoriesFilter(const string& path, UserDirectories& directories);
private:
	unique_ptr<Request> m_request;
	// 用户当前登录地址
	string m_userAddr;
	// 用户当前登录私钥
	string m_userPriKey;
	// 用户当前存储积分
	unsigned long long m_storageBalance;
	// 用户当前已使用大小
	unsigned long long m_totalFileLength;
};
#endif // !CCDNService_H
