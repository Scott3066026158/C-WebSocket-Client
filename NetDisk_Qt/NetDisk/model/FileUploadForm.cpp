#include "stdafx.h"
#include "FileUploadForm.h"


FileUploadForm::FileUploadForm()
{
}

FileUploadForm::~FileUploadForm()
{
}

FileUploadForm* FileUploadForm::parse(Json::Value value)
{
	return this;
}

bool FileUploadForm::isEmpty()
{
	return false;
}

Json::Value FileUploadForm::toJson()
{
	Json::Value value;
	if (this->r.empty()) value["r"] = this->r;
	if (this->s.empty()) value["s"] = this->s;
	if (this->v.empty()) value["v"] = this->v;
	value["fileName"] = this->fileName;
	value["fileHash"] = this->fileHash;
	value["sliceRootHash"] = this->sliceRootHash;
	value["sliceCount"] = this->sliceCount;
	value["backupCount"] = this->backupCount;
	value["sizePerSlice"] = this->sizePerSlice;
	value["cccPerSlice"] = this->cccPerSlice;
	value["expireTimestamp"] = this->expireTimestamp;
	if (this->fileSliceHashes.size() > 0)
	{
		Json::Value params;
		for (auto& fileHash : this->fileSliceHashes)
		{
			params.append(fileHash);
		}
		value["fileSliceHashes"] = params;
	}
	return value;
}

string FileUploadForm::toJsonStr()
{
	return toJson().toStyledString();
}