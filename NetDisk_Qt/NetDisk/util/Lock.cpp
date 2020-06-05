#include "stdafx.h"
#include "Lock.h"

Lock::Lock()
{
	memset(m_name, 0, 100);
	::InitializeCriticalSection(&m_cs);
}

Lock::Lock(const char* name)
{
	strcpy_s(m_name, name);
	::InitializeCriticalSection(&m_cs);
}

Lock::~Lock()
{
	::DeleteCriticalSection(&m_cs);
}

void Lock::lock()
{
	::EnterCriticalSection(&m_cs);
}

void Lock::lock(const char* name)
{
	::EnterCriticalSection(&m_cs);
}

void Lock::setName(const char* name)
{
	strcpy_s(m_name, name);
}

void Lock::unLock()
{
	::LeaveCriticalSection(&m_cs);
}

void Lock::unLock(const char* funcName)
{
	::LeaveCriticalSection(&m_cs);
}
