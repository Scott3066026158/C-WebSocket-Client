#pragma once
#ifndef FileUploadForm_H
#define FileUploadForm_H

#include "stdafx.h"
#include "Json.h"
// JsonRPC«Î«ÛΩ·ππ
class FileUploadForm
{
public:
	FileUploadForm();
	~FileUploadForm();
public:
	FileUploadForm* parse(Json::Value value);
	bool isEmpty();
	Json::Value toJson();
	string toJsonStr();
public:
	string fileName;
	string 	fileHash;
	string sliceRootHash;
	int sliceCount;
	int backupCount;
	int sizePerSlice;
	int cccPerSlice;
	unsigned long long expireTimestamp;
	string r;
	string s;
	string v;
	vector<string> fileSliceHashes;
};


#endif //!JSON_RPC_H