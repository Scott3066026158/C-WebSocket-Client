#include "stdafx.h"
#include "MathUtil.h"
#include<random>

MathUtil::MathUtil()
{
}


MathUtil::~MathUtil()
{
}

bool MathUtil::et(double a, double b)
{
	return fabs(a - b) < MIN_NUM ? true : false;
}

// 判断 a 小于 b true
bool MathUtil::lt(double a, double b)
{
	if (et(a, b)) return false;
	return a - b < MIN_NUM ? true : false;
}

// 判断 a 大于 b true
bool MathUtil::gt(double a, double b)
{
	if (et(a, b)) return false;
	return a - b > MIN_NUM ? true : false;
}

// 判断 a <= b true
bool MathUtil::el(double a, double b)
{
	return lt(a, b) || et(a, b);
}

// 判断 a >= b true
bool MathUtil::eg(double a, double b)
{
	return gt(a, b) || et(a, b);
}

/// count 参数数量
/// ...   多个String类型参数
/// 判空  多个String中存在""返回true 不存在返回false
bool MathUtil::isZero(int count...)
{
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++)
	{
		int arg = va_arg(ap, int);
		if (et(arg, 0))
		{
			va_end(ap);
			return true;
		}
	}
	va_end(ap);
	return false;
}

// 随机 a 与 b 之间的值 
// 若a 或 b小于0 则返回0 
// 若a 大于 b 则返回0 
// (a,b)
double MathUtil::nextDouble(double a, double b)
{
	bool f1 = gt(a, b);
	bool f2 = lt(a, 0);
	bool f3 = lt(b, 0);
	if (f1 || f2 || f3)
	{
		return 0;
	}
	int ranA = a * MAX_NUM;
	int ranB = b * MAX_NUM;
	int result = random(ranA + 1, ranB - 1);
	return result / MAX_NUM;
}

// 随机 a 与 b 之间的值 
// 若a 或 b小于0 则返回0 
// 若a 大于 b 则返回0
// [a,b]
int MathUtil::random(int a, int b)
{ 
	int c;
	if (gt(a,b) || a < 0 || b < 0)
	{
		c = 0;
	}
	else 
	{
		default_random_engine random(time(NULL));
		uniform_int_distribution<int> u(a, b);
		c = u(random);
	}
	return c;
}

// 随机 a 与 b 之间的值 
// 若a 或 b小于0 则返回0 
// 若a 大于 b 则返回0 
// [a,b]
double MathUtil::random(double a, double b) 
{ 
	double c;
	if (gt(a, b) || a < 0 || b < 0)
	{
		c = 0;
	}
	else
	{
		default_random_engine random(time(0));
		uniform_real_distribution<double> u(a, std::nextafter(b, DBL_MAX));
		c = u(random);
	}
	return c;
}

// 获取指定小数位的最小精度
// digit = 2 返回 0.01
// digit = 0 返回 1
// digit = -2 返回 1
double MathUtil::digit(int digit)
{
	double pre = 1;
	if (digit <= 0)
	{
		pre = 1;
	}
	else 
	{
		for (int i = 0; i < digit; i++) 
		{
			pre = pre / 10;
		}
	}
	return pre;
}


// 获取唯一ID
long long MathUtil::getUniqueId()
{
	return 0;
}

// 十六进制字符串转十进制数值型
bool MathUtil::toDec(const string& hexStr, unsigned long long &n)
{
	if (hexStr.empty()) return false;
	char* pc = new char[hexStr.length()];
	if (pc == 0) return false;
	memset(pc, 0, hexStr.length());
	hexStr.copy(pc, 2);
	string strTmp(pc);
	int cpyCount = 0;
	memset(pc, 0, hexStr.length());
	if (strTmp.compare("0x") == 0 || strTmp.compare("0X") == 0)
	{
		if (hexStr.length() > 18)  return false;
		cpyCount = hexStr.copy(pc, hexStr.size() - 2, 2);
	}
	else {

		if (hexStr.length() > 16)  return false;
		cpyCount = hexStr.copy(pc, hexStr.size());
	}
	n = 0;
	char *ptmp = pc;
	for (int i = 0; i < cpyCount; i++)
	{
		if (*pc >= '0' && *pc <= '9') {
			n += (*pc - '0')*static_cast<int>(pow(16, cpyCount - i - 1));
		}
		else if (*pc >= 'A' && *pc <= 'F') {
			n += (*pc - 'A' + 10)*static_cast<int>(pow(16, cpyCount - i - 1));

		}
		else if (*pc >= 'a' && *pc <= 'f') {
			n += (*pc - 'a' + 10)*static_cast<int>(pow(16, cpyCount - i - 1));
		}
		else {
			return -1;//含有非法字符
		}
		pc++;
	}
	pc = ptmp;
	delete[]pc;
	pc = NULL;
	return true;
}


long long MathUtil::storageScoreToBytes(long long nStorageScore)
{

	return nStorageScore * 125;//todo
}

string MathUtil::byteToSize(long long nBytes)
{
	if (nBytes == 0)
	{
		return "0 B";
	}
	int k = 1024; // or 1000
	string sizes[9] = { "B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
	int i = floor(log(nBytes) / log(k));
	double value = nBytes / (pow(k, i) * 1.0);
	wchar_t buf[128] = { 0 };
	CStr::GetValueByDigit(value, 2, buf);
	string sz = "";
	CStr::wstringTostring(sz, (String)buf);
	return sz + " " + sizes[i];

}