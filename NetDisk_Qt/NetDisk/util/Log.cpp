#include "stdafx.h"
#include "Log.h"
#include "FileUtil.h"
#include "DateUtil.h"
#include "DataCenter.h"
#include "DateUtil.h"
Logger::Logger()
{
	long long currentTime = DateUtil::currentTimeMillis();
	int dayDate = 60 * 60 * 24 * 1000;
	this->logDir = DataCenter::GetAppPath() + "\\log";
	if (!FileUtil::isDir(this->logDir.c_str()))
	{
		FileUtil::createDir((this->logDir).c_str());
	}
	this->currentLogDir = this->logDir + "\\" + DateUtil::getDate();
	if (!FileUtil::isDir(this->currentLogDir.c_str()))
	{
		FileUtil::createDir(this->currentLogDir.c_str());
	}
	//����0ʱʱ���
	long long todayZeroDate = currentTime - (currentTime + 8 * 60 * 60 * 1000) % dayDate;
	//�ڶ���0ʱʱ���
	this->secondTimestamp = todayZeroDate + dayDate;
	HANDLE hThread = ::CreateThread(0, 0, logWorker, this, 0, 0);
	::CloseHandle(hThread);
}

Logger::~Logger()
{
}

// ��ʼ����Ҫ����־�ļ�
void Logger::initLogFile()
{
}

// д��־
void Logger::debug(const string& path, const string& content)
{
	write("debug", path, content);
}

// д��־
void Logger::info(const string& path, const string& content)
{
	write("info", path, content);
}

// д��־
void Logger::warning(const string& path, const string& content)
{
	write("warning", path, content);
}

// д��־
void Logger::error(const string& path, const string& content)
{
	write("error", path, content);
}

// д��־
void Logger::write(const string& logLevel, const string& path, const string& content)
{
	int tid = GetCurrentThreadId();
	string time = DateUtil::getSystemTime();
	Log log;
	log.path = path + ".log";
	log.content = "[(" + logLevel + ")Tid:" + to_string(tid) + "" + ",time:" + time + "]" + content + "\n";
	logsLock.lock();
	this->logs.push_back(log);
	logsLock.unLock();
}

// �����߳�
DWORD WINAPI Logger::logWorker(LPVOID lpParam)
{
	Logger* log = (Logger*)lpParam;
	while (true)
	{
		log->logsLock.lock();
		vector<Log> clogs = log->logs;
		log->logs.clear();
		log->logsLock.unLock();
		if (clogs.size() == 0)
		{
			::Sleep(100);
			continue;
		}
		int dayDate = 60 * 60 * 24 * 1000;
		long long currentTime = DateUtil::currentTimeMillis();
		//����ʱ��С�ڵڶ���0ʱ
		if (currentTime > log->secondTimestamp)
		{
			log->secondTimestamp += dayDate;
			log->currentLogDir = log->logDir + "\\" + DateUtil::getDate();
			if (!FileUtil::isDir(log->currentLogDir.c_str()))
			{
				FileUtil::createDir(log->currentLogDir.c_str());
			}
		}
		for (vector<Log>::const_iterator logIter = clogs.cbegin(); logIter != clogs.cend(); logIter++)
		{
			string filePath = log->currentLogDir + "\\" + (*logIter).path;
			FileUtil::append(filePath.c_str(), (*logIter).content.c_str());
		}
	}
}