#include "stdafx.h"
#include "UserFile.h"
#include "StringUtil.h"
#include "MathUtil.h"

UserFiles::UserFiles()
{
}

UserFiles::~UserFiles()
{
}

UserFiles* UserFiles::parse(Json::Value value)
{
	int dirs = value.size();
	for (int i = 0; i < dirs; i++)
	{
		UserFile file;
		Json::Value dicInfo = value[i];
		if (file.parse(dicInfo)->isEmpty() == false)
			continue;
		this->m_files[file.currFile.fileHash] = file;
	}
	return this;
}

bool UserFiles::isEmpty()
{
	if (this->m_files.size() == 0) return false;
	return true;
}

UserFile::UserFile()
{
}

UserFile::~UserFile()
{
}

UserFile* UserFile::parse(Json::Value value)
{
	Json::Value fileValue = value["currentFileSummary"];
	currFile.parse(fileValue);
	return this;
}

bool UserFile::isEmpty()
{
	return currFile.isEmpty();
}

CurrentFileSummary::CurrentFileSummary()
{
	this->fileLength = 0;
	this->encryptionType = 0;
	this->version = 0;
	this->timestamp = 0;
}

CurrentFileSummary::~CurrentFileSummary()
{
}

CurrentFileSummary* CurrentFileSummary::parse(Json::Value value)
{
	if (value.isMember("fileName") && value["fileName"].isString())
		this->fileName = value["fileName"].asString();
	if (value.isMember("fileLength") && value["fileLength"].isInt64())
		this->fileLength = value["fileLength"].asInt64();
	if (value.isMember("fileHash") && value["fileHash"].isString())
		this->fileHash = value["fileHash"].asString();
	if (value.isMember("sliceRootHash") && value["sliceRootHash"].isString())
		this->sliceRootHash = value["sliceRootHash"].asString();
	if (value.isMember("fileType") && value["fileType"].isString())
		this->fileType = value["fileType"].asString();
	if (value.isMember("encryptionType") && value["encryptionType"].isInt())
		this->encryptionType = value["encryptionType"].asInt();
	if (value.isMember("fileDirectortyId") && value["fileDirectortyId"].isString())
		this->fileDirectortyId = value["fileDirectortyId"].asString();
	if (value.isMember("keyWords") && value["keyWords"].isString())
		this->keyWords = value["keyWords"].asString();
	if (value.isMember("remark") && value["remark"].isString())
		this->remark = value["remark"].asString();
	if (value.isMember("password") && value["password"].isString())
		this->remark = value["password"].asString();
	if (value.isMember("version") && value["version"].isInt())
		this->version = value["version"].asInt();
	if (value.isMember("timestamp") && value["timestamp"].isInt())
		this->timestamp = value["timestamp"].asInt();
	return this;
}

bool CurrentFileSummary::isEmpty()
{
	//if (StringUtil::isEmpty(8, this->fileName, this->fileHash, this->sliceRootHash, this->fileType, this->fileDirectortyId, this->keyWords,
		//this->remark, this->password)) return false;
	//if (MathUtil::isZero(4, this->fileLength, this->encryptionType, this->version, this->timestamp)) return false;
	if (StringUtil::isEmpty(5, this->fileName, this->fileHash, this->sliceRootHash, this->fileType, this->fileDirectortyId)) return false;
	if (this->fileLength == 0 || this->encryptionType == 0) return false;
	return true;
}

Json::Value CurrentFileSummary::toJson() const
{
	Json::Value value;
	value["fileName"] = this->fileName;
	value["fileLength"] = this->fileLength;
	value["fileHash"] = this->fileHash;
	value["sliceRootHash"] = this->sliceRootHash;
	value["fileType"] = this->fileType;
	value["encryptionType"] = this->encryptionType;
	value["keyWords"] = this->keyWords;
	value["remark"] = this->remark;
	value["password"] = this->password;
	value["version"] = this->version;
	value["timestamp"] = this->timestamp;
	return value;
}

string CurrentFileSummary::toJsonStr() const
{
	Json::Value value = this->toJson();
	return value.toStyledString();
}