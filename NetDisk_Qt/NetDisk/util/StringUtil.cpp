#include "stdafx.h"
#include "StringUtil.h"
/// count ��������
/// ... ���WString���Ͳ���
/// �п� ���WString�д���""����true �����ڷ���false
bool StringUtil::isEmptyWStr(int count...)
{
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++)
	{
		String arg = va_arg(ap, String);
		if (arg.empty())
		{
			va_end(ap);
			return true;
		}
	}
	va_end(ap);
	return false;
}

/// count ��������
/// ... ���String���Ͳ���
/// �п� ���String�д���""����true �����ڷ���false
bool StringUtil::isEmpty(int count...)
{
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++)
	{
		string arg = va_arg(ap, string);
		if (arg.empty())
		{
			va_end(ap);
			return true;
		}
	}
	va_end(ap);
	return false;
}

// ת��Ϊխ�ַ���
string StringUtil::wstrToStr(const String& src)
{
	int iTextLen = WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, 0, 0, 0, 0);
	char *pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1));
	::WideCharToMultiByte(CP_ACP, 0, src.c_str(), -1, pElementText, iTextLen, 0, 0);
	string dest = pElementText;
	delete[] pElementText;
	return dest;
}

// ת��Ϊ���ַ���
String StringUtil::strToWStr(const string& src)
{
	int  unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, 0, 0);
	wchar_t *pUnicode = new  wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, src.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);
	String dest = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return dest;
}

// �ַ�����ȱȽ�
bool StringUtil::cmpIgnoreCase(string str1, string str2)
{
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	if (str1 == str2) {
		return true;
	}
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	return str1 == str2;
}

// �ַ���ȫ��תСд
string StringUtil::toLower(const char* src)
{
	int len = strlen(src);
	char* dest = new char[len + 1]{ 0 };
	for (int i = 0; i < len && src[i] != '\0'; i++) {
		if (src[i] >= 'A' && src[i] <= 'Z') {
			dest[i] = tolower(src[i]);
		}
	}
	string destStr = dest;
	delete[] dest;
	return destStr;
}

// �ַ���ȫ��ת��д
string StringUtil::toUpper(const char* src)
{
	int len = strlen(src);
	char* dest = new char[len + 1]{ 0 };
	for (int i = 0; i < len && src[i] != '\0'; i++) {
		if (src[i] >= 'A' && src[i] <= 'Z') {
			dest[i] = ::toupper(src[i]);
		}
	}
	string destStr = dest;
	delete[] dest;
	return destStr;
}

// �ַ���ȫ��תСд
string StringUtil::toLower(const string& src)
{
	string dest = src;
	transform(dest.begin(), dest.end(), dest.begin(), ::tolower);
	return dest;
}

// �ַ���ȫ��ת��д
string StringUtil::toUpper(const string& src)
{
	string dest = src;
	transform(dest.begin(), dest.end(), dest.begin(), ::toupper);
	return dest;
}

string StringUtil::GetValueByDigit2(double value, int digit)
{
	String str = GetValueByDigit(value, digit);
	return wstrToStr(str);
}

//doubleתString
String StringUtil::GetValueByDigit(double value, int digit)
{
	wchar_t str[1024] = { 0 };
	if (!_isnan(value))
	{
		if (digit == 0)
		{
			double newValue = round(value);
			if (abs(value - newValue) < 1)
			{
				value = newValue;
			}
		}
		switch (digit)
		{
		case 0:
			_stprintf_s(str, 99, L"%d", (int)value);
			break;
		case 1:
			_stprintf_s(str, 99, L"%.1f", value);
			break;
		case 2:
			_stprintf_s(str, 99, L"%.2f", value);
			break;
		case 3:
			_stprintf_s(str, 99, L"%.3f", value);
			break;
		case 4:
			_stprintf_s(str, 99, L"%.4f", value);
			break;
		case 5:
			_stprintf_s(str, 99, L"%.5f", value);
			break;
		case 6:
			_stprintf_s(str, 99, L"%.6f", value);
			break;
		case 7:
			_stprintf_s(str, 99, L"%.7f", value);
			break;
		case 8:
			_stprintf_s(str, 99, L"%.8f", value);
			break;
		case 9:
			_stprintf_s(str, 99, L"%.9f", value);
			break;
		default:
			_stprintf_s(str, 99, L"%f", value);
		}
	}
	return str;
}

// �ж��ַ���Ϊ��ֵ
bool StringUtil::isNum(int count...)
{
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++)
	{
		String arg = va_arg(ap, String);
		//Ϊ�շ���false
		if (arg.empty())
		{
			va_end(ap);
			return false;
		}
		for (int i = 0; i < arg.size(); i++)
		{
			int tmp = (int)arg[i];
			if ((tmp < 48 || tmp > 57) && tmp != 46)
			{
				va_end(ap);
				return false;
			}
		}
	}
	va_end(ap);
	return true;
}

//�ַ���ȥ�ո�
void StringUtil::trim(string& str)
{
	if (!str.empty()) 
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(0, str.find_last_not_of(" ") + 1);
	}
}

void StringUtil::trim(String& str)
{
	string convertStr = wstrToStr(str);
	trim(convertStr);
}

string StringUtil::GbkToUtf8(const char *src_str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, src_str, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, src_str, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	string strTemp = str;
	if (wstr) delete[] wstr;
	if (str) delete[] str;
	return strTemp;
}

string StringUtil::Utf8ToGbk(const char *src_str)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}

// ͳ��ĳ���ַ����ֵĴ���
int StringUtil::count(const char* src, const char c)
{
	int count = 0;
	while (*src)
		if (*src++ == c) count++;
	return count;
}

//���ĳ���ַ����Ƿ���ָ���ַ�����ʼ
bool StringUtil::startWith(const string& src, const string& dest)
{
	int size = dest.length() + 1;
	char* destPtr = new char[size];
	if (destPtr == 0) return false;
	memset(destPtr, 0, size);
	src.copy(destPtr, size - 1);
	if (dest.compare(destPtr) == 0) return true;
	return false;
}

vector<String> StringUtil::Split(const String& str, const String& pattern)
{
	int pos = -1;
	vector<String> result;
	String newStr = str;
	newStr += pattern;
	int size = (int)str.size();
	for (int i = 0; i < size; i++)
	{
		pos = (int)newStr.find(pattern, i);
		if ((int)pos <= size)
		{
			String s = newStr.substr(i, pos - i);
			result.push_back(s);
			i = pos + (int)pattern.size() - 1;
		}
	}
	return result;
}