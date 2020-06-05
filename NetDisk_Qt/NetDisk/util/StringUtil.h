#ifndef _StringUtil_H_
#define _StringUtil_H_

#include "stdafx.h"
class StringUtil
{
public:
	/// count 参数数量
	/// ...   多个WString类型参数
	/// 判空  多个WString中存在""返回true 不存在返回false
	static bool isEmptyWStr(int count...);

	/// count 参数数量
	/// ...   多个String类型参数
	/// 判空  多个String中存在""返回true 不存在返回false
	static bool isEmpty(int count...);
	/// count 参数数量
	/// ...   多个String类型参数
	/// 判空  多个String中存在""返回true 不存在返回false
	static bool isZero(int count...);

	// 转化为窄字符串
	static string wstrToStr(const String& src);

	// 转化为宽字符串
	static String strToWStr(const string& src);

	// 字符串相等比较
	static bool cmpIgnoreCase(string str1, string str2);

	// 字母全部转小写
	static string toLower(const char* src);

	// 字母全部转大写
	static string toUpper(const char* src);

	// 字母全部转小写
	static string toLower(const string& src);

	// 字母全部转大写
	static string toUpper(const string& src);

	//判断字符串为数值
	static bool isNum(int count...);

	//字符串去空格
	static void trim(string& str);
	static void trim(String& str);

	//编码转换
	static string GbkToUtf8(const char* src_str);
	//编码转换
	static string Utf8ToGbk(const char* src_str);

	// 统计某个字符出现的次数
	static int count(const char* src, const char c);

	//检查某个字符串是否以指定字符串开始
	static bool startWith(const string& src, const string& dest);
	//double转String
	static String  GetValueByDigit(double value, int digit);
	static string GetValueByDigit2(double value, int digit);

	static vector<String> Split(const String& str, const String& pattern);
};
#endif