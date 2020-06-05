// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
// Windows 头文件:
#include <windows.h>

// C 运行时头文件
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
#pragma warning(disable:4311)//从“LPVOID”到“int”的指针截断
#pragma warning(disable:4312)

#pragma warning(disable:4067)//意外标记符
#pragma warning(disable:4996)
#pragma warning(disable:4244)//double 转 int
#pragma warning(disable:4018)//有符号/无符号不匹配
#pragma warning(disable:4482)//使用了非标准扩展
#pragma warning(disable:4267)//size_t 转 int



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
