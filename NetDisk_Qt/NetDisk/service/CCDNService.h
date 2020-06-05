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
	// ��¼
	bool login(const string& priKey);
	// �û���ȡ�洢����
	bool getStorageBalance(unsigned long long& size);
	// ��ȡ�û���ַ
	bool getUserAddr(string& addr);
	// ��ȡ�û���Ŀ¼�������ļ����ļ���
	bool getRootFilesAndDirectories(UserFiles& files, UserDirectories& directories);
	// ��ȡָ��Ŀ¼�µ��ļ����ļ���
	bool getFilesAndDirectories(const string& path, UserFiles& files, UserDirectories& directories);
	// ��ȡ�û���ȫ��ͼƬ�ļ�
	bool getUserPhotos(UserFiles& files);
	// ��ȡ�û���ȫ����Ƶ�ļ�
	bool getUserVideos(UserFiles& files);
	// ��ȡ�û���ȫ���ĵ��ļ�
	bool getUserDocuments(UserFiles& files);
	// ��ȡ�û��ļ��ܴ�С
	bool getTotalFileLength(unsigned long long& size);
	// ��ȡ�û��ļ���
	bool getFileDirectories(UserDirectories& fileDirs);
	// ��ȡ�û��ļ�
	bool getFiles(UserFiles& files);
	//�����ļ�hash
	vector<string> getFileHash(string& fileName, int sliceNum);
	//�����ļ���Ƭhash
	bool getFileSliceHashes(string& file, int sliceNum);

private:
	// ��ȡ�û���ַ
	string getUserAddr(const string& prikey);
	// ���˷Ǹ�Ŀ¼���ļ���
	bool directoriesFilter(const string& path, UserDirectories& directories);
private:
	unique_ptr<Request> m_request;
	// �û���ǰ��¼��ַ
	string m_userAddr;
	// �û���ǰ��¼˽Կ
	string m_userPriKey;
	// �û���ǰ�洢����
	unsigned long long m_storageBalance;
	// �û���ǰ��ʹ�ô�С
	unsigned long long m_totalFileLength;
};
#endif // !CCDNService_H
