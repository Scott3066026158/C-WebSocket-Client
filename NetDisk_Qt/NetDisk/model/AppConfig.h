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
	// ���ַ��������ɶ�������
    AppConfig* parse(string configFileContent);
	// �����������Ƿ���ڿ�
	bool isEmpty();
};

#endif // !AppConfig_H
