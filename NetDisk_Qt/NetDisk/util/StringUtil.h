#ifndef _StringUtil_H_
#define _StringUtil_H_

#include "stdafx.h"
class StringUtil
{
public:
	/// count ��������
	/// ...   ���WString���Ͳ���
	/// �п�  ���WString�д���""����true �����ڷ���false
	static bool isEmptyWStr(int count...);

	/// count ��������
	/// ...   ���String���Ͳ���
	/// �п�  ���String�д���""����true �����ڷ���false
	static bool isEmpty(int count...);
	/// count ��������
	/// ...   ���String���Ͳ���
	/// �п�  ���String�д���""����true �����ڷ���false
	static bool isZero(int count...);

	// ת��Ϊխ�ַ���
	static string wstrToStr(const String& src);

	// ת��Ϊ���ַ���
	static String strToWStr(const string& src);

	// �ַ�����ȱȽ�
	static bool cmpIgnoreCase(string str1, string str2);

	// ��ĸȫ��תСд
	static string toLower(const char* src);

	// ��ĸȫ��ת��д
	static string toUpper(const char* src);

	// ��ĸȫ��תСд
	static string toLower(const string& src);

	// ��ĸȫ��ת��д
	static string toUpper(const string& src);

	//�ж��ַ���Ϊ��ֵ
	static bool isNum(int count...);

	//�ַ���ȥ�ո�
	static void trim(string& str);
	static void trim(String& str);

	//����ת��
	static string GbkToUtf8(const char* src_str);
	//����ת��
	static string Utf8ToGbk(const char* src_str);

	// ͳ��ĳ���ַ����ֵĴ���
	static int count(const char* src, const char c);

	//���ĳ���ַ����Ƿ���ָ���ַ�����ʼ
	static bool startWith(const string& src, const string& dest);
	//doubleתString
	static String  GetValueByDigit(double value, int digit);
	static string GetValueByDigit2(double value, int digit);

	static vector<String> Split(const String& str, const String& pattern);
};
#endif