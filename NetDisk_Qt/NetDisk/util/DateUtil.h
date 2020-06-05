#pragma once
#ifndef _DateUtil_H_
#define _DateUtil_H_

#include <stdio.h>    
#include <time.h>
#include <windows.h>
#include <iostream>

class DateUtil
{
public:
	DateUtil();
	~DateUtil();
public:
	// ��ȡ��ǰʱ���
	static long long currentTimeMillis()
	{
		time_t t;
		time(&t);
		return  t * 1000;
	}

	//��ȡ��ǰϵͳʱ��(��ʽ�����)
	static string getDate()
	{
		time_t now;
		int unixTime = (int)time(&now);
		time_t tick = (time_t)unixTime;

		struct tm tm;
		char s[100];
		tm = *localtime(&tick);
		strftime(s, sizeof(s), "%Y-%m-%d", &tm);
		string time = s;
		return time;
	}
	//��ȡ��ǰϵͳʱ��(��ʽ�����)
	static string getSystemTime() 
	{
		time_t now;
		int unixTime = (int)time(&now);
		time_t tick = (time_t)unixTime;

		struct tm tm;
		char s[100];
		tm = *localtime(&tick);
		strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
		string time = s;
		return time;
	}

	//��ʽ��ʱ��������أ�
	static string getSystemTime(long long stampTime)
	{
		
		time_t tick = (time_t)stampTime/1000;

		struct tm tm;
		tm = *localtime(&tick);

		char s[100];
		strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
		string time = s;
		return time;
	}

	//����ת����unixʱ���(�ַ���:2017-5-12 11:13:37)
	static int64_t strTime2unix(const string& date)
	{
		struct tm tm;
		memset(&tm, 0, sizeof(tm));

		sscanf(date.c_str(), "%d-%d-%d %d:%d:%d",
			&tm.tm_year, &tm.tm_mon, &tm.tm_mday,
			&tm.tm_hour, &tm.tm_min, &tm.tm_sec);

		tm.tm_year -= 1900;
		tm.tm_mon--;

		return mktime(&tm);
	}
};

#endif
