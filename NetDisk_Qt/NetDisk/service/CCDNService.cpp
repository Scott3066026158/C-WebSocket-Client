#include "stdafx.h"
#include "CCDNService.h"
#include "crypto\\sha2.c"
#include "StringUtil.h"
#include "cryptlib.h"
#include "keccak.h"

using namespace CryptoPP;

CCDNService::CCDNService()
{
	m_request.reset(new Request);
}

CCDNService::~CCDNService()
{
}

bool CCDNService::login(const string& priKey)
{
	this->m_userAddr = getUserAddr(priKey);
	if (this->m_userAddr.empty()) return false;
	unsigned long long storageSize = 0;
	bool isSucc = m_request->getStorageBalance(this->m_userAddr, storageSize);
	if (isSucc == false) return false;
	this->m_storageBalance = storageSize;
	if (this->m_storageBalance == 0) return false;
	return true;
}

// 用户获取存储积分
bool CCDNService::getStorageBalance(unsigned long long &size)
{
	size = this->m_storageBalance;
	return true;
}

// 获取用户地址
bool CCDNService::getUserAddr(string& addr)
{
	if (this->m_userAddr.empty() == false)
	{
		addr = this->m_userAddr;
		return true;
	}
	addr = this->getUserAddr(m_userPriKey);
	if (addr.empty())
		return false;
	this->m_userAddr = addr;
	return true;
}

// 获取用户根目录下所有文件和文件夹
bool CCDNService::getRootFilesAndDirectories(UserFiles& files, UserDirectories& directories)
{
	return getFilesAndDirectories("/", files, directories);
}

// 获取指定目录下的文件和文件夹
bool CCDNService::getFilesAndDirectories(const string& path, UserFiles& files, UserDirectories& directories)
{
	// 获取用户所有文件夹
	if (this->m_request->getFileDirectories(this->m_userAddr, directories) == false) return false;

	// 获取指定文件夹id
	map<string, UserDirectory>::iterator dirIter = directories.m_dirs.find(path);
	if (dirIter == directories.m_dirs.end()) return false;
	string rootId = dirIter->second.id;
	// 获取指定目录文件列表
	if (m_request->getDirectoryFiles(this->m_userAddr, rootId, files) == false) return false;
	// 过滤所有文件文件夹
	if (this->directoriesFilter(path, directories) == false) return false;
	return true;
}

// 获取用户的全部图片文件
bool CCDNService::getUserPhotos(UserFiles& files)
{
	return false;
}

// 获取用户的全部视频文件
bool CCDNService::getUserVideos(UserFiles& files)
{
	return false;
}
// 获取用户的全部文档文件
bool CCDNService::getUserDocuments(UserFiles& files)
{
	return false;
}

// 获取用户文件总大小
bool CCDNService::getTotalFileLength(unsigned long long& size)
{
	return this->m_request->getTotalFileLength(this->m_userAddr, size);
}

// 获取用户文件夹
bool CCDNService::getFileDirectories(UserDirectories& fileDirs)
{
	return this->m_request->getFileDirectories(this->m_userAddr, fileDirs);
}

string* byteToHexStr(unsigned char byte_arr[], int arr_len)
{
	string*  hexstr = new string();
	for (int i = 0; i<arr_len; i++)
	{
		char hex1;
		char hex2;
		int value = byte_arr[i]; //直接将unsigned char赋值给整型的值，系统会正动强制转换
		int v1 = value / 16;
		int v2 = value % 16;

		//将商转成字母
		if (v1 >= 0 && v1 <= 9)
			hex1 = (char)(48 + v1);
		else
			hex1 = (char)(55 + v1);

		//将余数转成字母
		if (v2 >= 0 && v2 <= 9)
			hex2 = (char)(48 + v2);
		else
			hex2 = (char)(55 + v2);

		//将字母连接成串
		*hexstr = *hexstr + hex1 + hex2;
	}
	return hexstr;
}

//计算文件hash
vector<string> CCDNService::getFileHash(string& fileName, int sliceNum)
{
	FILE *file = 0;
	vector<string> ret;
	fopen_s(&file, fileName.c_str(), "rb");
	if (!file)
	{
		return ret;
	}
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	const int READ_BUFF_SIZE = 100 * 1024 * 1024;
	std::string digest;

	if (sliceNum == 1)
	{
		long readedSize = 0;
		size_t stRead = 0;
		size_t toreadlen = 0;
		Keccak_256 hash;
		while (1)
		{
			toreadlen = size - readedSize;
			size_t readLength = (toreadlen > READ_BUFF_SIZE) ? READ_BUFF_SIZE : toreadlen;
			unsigned char* buf = new unsigned char[readLength + 1];
			memset(buf, 0, readLength + 1);
			stRead = fread(buf, sizeof(unsigned char), readLength, file);
			readedSize = (long)(readedSize + stRead);
			hash.Update((unsigned char*)buf, readLength);
			if (readedSize >= size)
			{
				digest.resize(hash.DigestSize());
				hash.Final((unsigned char*)&digest[0]);
				string* ss = byteToHexStr((unsigned char*)digest.c_str(), 32);
				ret.push_back(*ss);
				fclose(file);
				break;
			}
			delete[]buf;
			buf = 0;
		}
	}
	else if (sliceNum > 1)
	{
		long itemSize = size / sliceNum;
		for (int i = 0; i < sliceNum; i++)
		{
			if (i == sliceNum - 1)
			{
				itemSize = size - itemSize * (sliceNum - 1);
			}
			long readedSize = 0;
			size_t stRead = 0;
			size_t toreadlen = 0;
			Keccak_256 hash;
			while (1)
			{
				toreadlen = itemSize - readedSize;
				size_t readLength = (toreadlen > READ_BUFF_SIZE) ? READ_BUFF_SIZE : toreadlen;
				unsigned char* buf = new unsigned char[readLength + 1];
				memset(buf, 0, readLength + 1);
				stRead = fread(buf, sizeof(unsigned char), readLength, file);
				readedSize = (long)(readedSize + stRead);
				hash.Update((unsigned char*)buf, readLength);
				if (readedSize >= itemSize)
				{
					digest.resize(hash.DigestSize());
					hash.Final((unsigned char*)&digest[0]);
					string* ss = byteToHexStr((unsigned char*)digest.c_str(), 32);
					ret.push_back(*ss);
					break;
				}
				delete[]buf;
				buf = 0;
			}
		}

		fclose(file);
	}

	return ret;
}

//计算文件分片hash
bool CCDNService::getFileSliceHashes(string& file, int sliceNum)
{
	return false;
}

// 获取用户文件
bool CCDNService::getFiles(UserFiles& files)
{
	return this->m_request->getFiles(this->m_userAddr, files);
}

string CCDNService::getUserAddr(const string& prikey)
{
	char ethAddrStr[43] = { 0 };
	string str = prikey;
	if (str.find("0x") == 0)
	{
		str = str.substr(2, str.size() - 2);
	}
	etherPriKeyToAddress(str.c_str(), ethAddrStr);
	return ethAddrStr;
}

// 过滤非指定目录下文件夹
bool CCDNService::directoriesFilter(const string& path, UserDirectories& directories)
{
	unique_ptr<UserDirectories> dirs(new UserDirectories);
	for (auto &direcInfo : directories.m_dirs)
	{
		if (StringUtil::startWith(direcInfo.second.fullPath, path) == false) return false;
		int srcCount = StringUtil::count(direcInfo.second.fullPath.c_str(), '/');
		int destCount = StringUtil::count(path.c_str(), '/');
		if (srcCount == destCount + 1)
			dirs->m_dirs[direcInfo.second.fullPath] = direcInfo.second;
	}
	directories.m_dirs = dirs->m_dirs;
	return true;
}