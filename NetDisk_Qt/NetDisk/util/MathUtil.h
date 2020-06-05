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
	// �ж� a ���� b true
	static bool et(double a, double b);

	// �ж� a С�� b true
	static bool lt(double a, double b);

	// �ж� a ���� b true
	static bool gt(double a, double b);

	// �ж� a <= b true
	static bool el(double a, double b);

	// �ж� a >= b true
	static bool eg(double a, double b);

	/// ֻ�ܽ���int���Ͳ���
	/// count ��������
	/// ...   ���double���Ͳ���
	/// �п�  ���double�д��� 0 ����true �����ڷ���false
	static bool isZero(int count...);

	// ��� a �� b ֮���ֵ 
	// ��a �� bС��0 �򷵻�0 
	// ��a ���� b �򷵻�0 
	// (a,b)
	static double nextDouble(double a, double b);

	// ��� a �� b ֮���ֵ 
	// ��a �� bС��0 �򷵻�0 
	// ��a ���� b �򷵻�0 
	static int random(int a, int b);

	// ��� a �� b ֮���ֵ 
	// ��a �� bС��0 �򷵻�0 
	// ��a ���� b �򷵻�0 
	static double random(double a, double b);

	// ��ȡָ��С��λ����С����
	// digit = 2 ���� 0.01
	// digit = 0 ���� 1
	// digit = -2 ���� 1
	static double digit(int digit);

	// ��ȡΨһID
	static long long getUniqueId();

	// ʮ�������ַ���תʮ������ֵ��
	static bool toDec(const string& hexStr, unsigned long long &n);

	//�ֽ���תΪ�洢��ʽ
	static long long storageScoreToBytes(long long nStorageScore);

	static string byteToSize(long long nBytes);
};



#endif
