#pragma once
#ifndef _UserInfo_H_
#define _UserInfo_H_

#include "stdafx.h"
#include "StringUtil.h"
#include "Json.h"
#include "HMAC_SHA256.h"
class UserInfo
{
public:
	UserInfo();
	~UserInfo();
public:
	// �û��Ĵ洢����
	long long storageSize;
	// �û��ĵ�¼״̬
	bool isLogin;
public:
	// ����û������Ƿ���ڿ�
	bool hasEmpty();
};
#endif
