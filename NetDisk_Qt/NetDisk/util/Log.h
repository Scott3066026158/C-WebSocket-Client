#ifndef _Log_H_
#define _Log_H_

#include "stdafx.h"
#include "Lock.h"

// ��־�ṹ
class Log
{
public:
	// ·��
	string path;
	// ����
	string content;
};

// ��־���
class Logger
{
public:
	Logger();
	~Logger();
public:
	// ��ʼ����Ҫ����־�ļ�
	void initLogFile();
	// д��־
	void debug(const string& path, const string& content);
	// д��־
	void info(const string& path, const string& content);
	// д��־
	void warning(const string& path, const string& content);
	// д��־
	void error(const string& path, const string& content);
private:
	// д��־
	void write(const string& logLevel, const string& path, const string& content);
	// ��־�ļ���
	string logDir;
	// ��ǰ��־�ļ���·��
	string currentLogDir;
	// �ڶ���0��ʱ���
	long long secondTimestamp;
	// ��־������
	Lock logsLock;
	// ��־����
	vector<Log> logs;
	// �����߳�
	static DWORD WINAPI logWorker(LPVOID lpParam);
};

#endif // ! _Log_H_
