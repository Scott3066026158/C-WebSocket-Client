#include "AppConfig.h"


AppConfig::AppConfig()
{
}

AppConfig::~AppConfig()
{
}

// 将字符串解析成对象属性
AppConfig* AppConfig::parse(string configFileContent)
{
	return this;
}

// 检测对象属性是否存在空
bool AppConfig::isEmpty()
{
	return false;
}
