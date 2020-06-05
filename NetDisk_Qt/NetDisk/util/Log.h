#ifndef _Log_H_
#define _Log_H_

#include "stdafx.h"
#include "Lock.h"

// 日志结构
class Log
{
public:
	// 路径
	string path;
	// 内容
	string content;
};

// 日志组件
class Logger
{
public:
	Logger();
	~Logger();
public:
	// 初始化需要的日志文件
	void initLogFile();
	// 写日志
	void debug(const string& path, const string& content);
	// 写日志
	void info(const string& path, const string& content);
	// 写日志
	void warning(const string& path, const string& content);
	// 写日志
	void error(const string& path, const string& content);
private:
	// 写日志
	void write(const string& logLevel, const string& path, const string& content);
	// 日志文件夹
	string logDir;
	// 当前日志文件夹路径
	string currentLogDir;
	// 第二天0点时间戳
	long long secondTimestamp;
	// 日志容器锁
	Lock logsLock;
	// 日志容器
	vector<Log> logs;
	// 工作线程
	static DWORD WINAPI logWorker(LPVOID lpParam);
};

#endif // ! _Log_H_
