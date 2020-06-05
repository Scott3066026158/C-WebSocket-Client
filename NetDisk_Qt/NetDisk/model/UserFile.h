#pragma once

#ifndef UserFile_H
#define UserFile_H

#include "stdafx.h"
#include "JsonRPC.h"
#include <memory>
class UserFile;

class UserFiles
{
public:
	UserFiles();
	~UserFiles();
public:
	UserFiles* parse(Json::Value value);
	bool isEmpty();
	map<string, UserFile> m_files;
};

class CurrentFileSummary
{
public:
	CurrentFileSummary();
	~CurrentFileSummary();
public:
	CurrentFileSummary* parse(Json::Value value);
	bool isEmpty();
	Json::Value toJson() const;
	string toJsonStr() const;
public:
	string fileName;
	long long fileLength;
	string fileHash;
	string sliceRootHash;
	string fileType;
	int	encryptionType;
	string fileDirectortyId;
	string keyWords;
	string remark;
	string password;
	int	version;
	long long timestamp;
};

class UserFile
{
public:
	UserFile();
	~UserFile();
public:
	UserFile* parse(Json::Value value);
	bool isEmpty();
public:
	CurrentFileSummary currFile;
};


#endif;