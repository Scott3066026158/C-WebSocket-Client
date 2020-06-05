#pragma once
#ifndef _MathUtil_H_
#define _MathUtil_H_

#include "stdafx.h"
#include <math.h>

static const double MIN_NUM = 1e-10;
static const double MAX_NUM = 1e+6;

class MathUtil
{
public:
	MathUtil();
	~MathUtil();
public:
public:
	// 判断 a 等于 b true
	static bool et(double a, double b);

	// 判断 a 小于 b true
	static bool lt(double a, double b);

	// 判断 a 大于 b true
	static bool gt(double a, double b);

	// 判断 a <= b true
	static bool el(double a, double b);

	// 判断 a >= b true
	static bool eg(double a, double b);

	/// 只能接受int类型参数
	/// count 参数数量
	/// ...   多个double类型参数
	/// 判空  多个double中存在 0 返回true 不存在返回false
	static bool isZero(int count...);

	// 随机 a 与 b 之间的值 
	// 若a 或 b小于0 则返回0 
	// 若a 大于 b 则返回0 
	// (a,b)
	static double nextDouble(double a, double b);

	// 随机 a 与 b 之间的值 
	// 若a 或 b小于0 则返回0 
	// 若a 大于 b 则返回0 
	static int random(int a, int b);

	// 随机 a 与 b 之间的值 
	// 若a 或 b小于0 则返回0 
	// 若a 大于 b 则返回0 
	static double random(double a, double b);

	// 获取指定小数位的最小精度
	// digit = 2 返回 0.01
	// digit = 0 返回 1
	// digit = -2 返回 1
	static double digit(int digit);

	// 获取唯一ID
	static long long getUniqueId();

	// 十六进制字符串转十进制数值型
	static bool toDec(const string& hexStr, unsigned long long &n);

	//字节数转为存储格式
	static long long storageScoreToBytes(long long nStorageScore);

	static string byteToSize(long long nBytes);
};



#endif
