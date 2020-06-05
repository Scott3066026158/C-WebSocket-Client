#include "stdafx.h"
#include "UserDirectory.h"
#include "StringUtil.h"

UserDirectories::UserDirectories()
{
}

UserDirectories::~UserDirectories()
{
}

UserDirectories* UserDirectories::parse(Json::Value value)
{
	int dirs = value.size();
	for (int i = 0; i < dirs; i++)
	{
		UserDirectory dir;
		Json::Value dicInfo = value[i];
		if (dir.parse(dicInfo)->isEmpty() == false)
		{
			continue;
		}
		this->m_dirs[dir.fullPath] = dir;
	}
	return this;
}

bool UserDirectories::isEmpty()
{
	if (m_dirs.size() == 0) return false;
	return true;
}

UserDirectory::UserDirectory()
{
	this->sortNo = 0;
	this->hideFlag = 0;
	this->deleteFlag = 0;
	this->timestamp = 0;
}

UserDirectory::~UserDirectory()
{
}

UserDirectory* UserDirectory::parse(Json::Value value)
{
	if (value.isMember("pendingStatus") && value["pendingStatus"].isString())
		this->pendingStatus = value["pendingStatus"].asString();
	if (value.isMember("id") && value["id"].isString())
		this->id = value["id"].asString();
	if (value.isMember("name") && value["name"].isString())
		this->name = value["name"].asString();
	if (value.isMember("fullPath") && value["fullPath"].isString())
		this->fullPath = value["fullPath"].asString();
	if (value.isMember("timestamp") && value["timestamp"].isInt64())
		this->timestamp = value["timestamp"].asInt64();
	if (value.isMember("sortNo") && value["sortNo"].isInt())
		this->sortNo = value["sortNo"].asInt();
	if (value.isMember("hideFlag") && value["hideFlag"].isInt())
		this->hideFlag = value["hideFlag"].asInt();
	if (value.isMember("deleteFlag") && value["deleteFlag"].isInt())
		this->deleteFlag = value["deleteFlag"].asInt();
	return this;
}

bool UserDirectory::isEmpty()
{
	if (StringUtil::isEmpty(4, this->pendingStatus, this->id, this->name, this->fullPath)) return false;
	return true;
}

DirectoryUpdateInfo::DirectoryUpdateInfo()
{
}

DirectoryUpdateInfo::~DirectoryUpdateInfo()
{
}

DirectoryUpdateInfo* DirectoryUpdateInfo::parse(Json::Value value)
{
	if (value.isMember("pendingStatus") && value["pendingStatus"].isString())
		this->pendingStatus = value["pendingStatus"].asString();
	if (value.isMember("id") && value["id"].isString())
		this->id = value["id"].asString();
	return this;
}

bool DirectoryUpdateInfo::isEmpty()
{
	if (StringUtil::isEmpty(2, this->pendingStatus, this->id)) return false;
	return true;
}