#pragma once
#ifndef AppConfig_H
#define AppConfig_H

#include "stdafx.h"

class AppConfig
{
public:
	AppConfig();
	~AppConfig();
public:
	// 将字符串解析成对象属性
    AppConfig* parse(string configFileContent);
	// 检测对象属性是否存在空
	bool isEmpty();
};

#endif // !AppConfig_H
