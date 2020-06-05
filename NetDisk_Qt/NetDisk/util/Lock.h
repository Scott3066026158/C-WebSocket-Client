#pragma once
#ifndef _Lock_H_
#define _Lock_H_

class Lock
{
public:
	Lock();
	Lock(const char *name);
	virtual ~Lock();
private:
	CRITICAL_SECTION m_cs;
	char m_name[100];
public:
	void lock();
	void lock(const char* name);
	void unLock();
	void unLock(const char* name);
	void setName(const char* name);
};

#endif