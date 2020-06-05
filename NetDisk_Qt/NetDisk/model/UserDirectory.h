#pragma once
#ifndef UserDirectory_H
#define UserDirectory_H
#include "stdafx.h"
#include "JsonRPC.h"
#include "Json.h"

class UserDirectory;
class UserDirectories
{
public:
	UserDirectories();
	~UserDirectories();
public:
	UserDirectories* parse(Json::Value value);
	bool isEmpty();
	map<string, UserDirectory> m_dirs;
};

class UserDirectory
{
public:
	UserDirectory();
	~UserDirectory();
public:
	UserDirectory* parse(Json::Value value);
	bool isEmpty();
public:
	string pendingStatus;
	string id;
	string name;
	string fullPath;
	long long timestamp;
	int sortNo;
	int hideFlag;
	int deleteFlag;
};

class DirectoryUpdateInfo
{
public:
	DirectoryUpdateInfo();
	~DirectoryUpdateInfo();
public:
	DirectoryUpdateInfo* parse(Json::Value value);
	bool isEmpty();
public:
	string pendingStatus;
	string id;
};


#endif // !UserDirectory_H

