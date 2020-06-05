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
	// 用户的存储积分
	long long storageSize;
	// 用户的登录状态
	bool isLogin;
public:
	// 检查用户设置是否存在空
	bool hasEmpty();
};
#endif
