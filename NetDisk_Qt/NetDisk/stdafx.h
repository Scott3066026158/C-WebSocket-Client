// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <deque>
#include <Shlobj.h>
#include <ShellAPI.h>
#include <objbase.h>
#include <zmouse.h>
#include <regex>
#include <memory>
#pragma warning(disable:4311)//�ӡ�LPVOID������int����ָ��ض�
#pragma warning(disable:4312)

#pragma warning(disable:4067)//�����Ƿ�
#pragma warning(disable:4996)
#pragma warning(disable:4244)//double ת int
#pragma warning(disable:4018)//�з���/�޷��Ų�ƥ��
#pragma warning(disable:4482)//ʹ���˷Ǳ�׼��չ
#pragma warning(disable:4267)//size_t ת int



#include <comdef.h>

#include <stdio.h>
#include <tchar.h>

#pragma comment(lib, "libcrypto.lib")
#pragma comment(lib, "libssl")
#pragma comment(lib, "cryptlib.lib")

using namespace std;

#define SECURITY_WIN32
#define SECURITY_KERNEL

#define WM_LOCKWINDOW WM_USER + 1000
