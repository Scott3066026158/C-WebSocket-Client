#pragma once
#ifndef _FileUtil_H_
#define _FileUtil_H_

class FileUtil
{
public:
	FileUtil();
	~FileUtil();
public:		//Create
	// 创建目录 成功返回true 失败返回false
	static bool createDir(const char* dir);
	// 创建目录 成功返回true 失败返回false
	static bool createDir(const wchar_t* dir);

public:		//Update
	// 追加内容 成功返回true 失败返回false
	static bool append(const char* filePath, const char* content);
	// 追加内容 成功返回true 失败返回false
	static bool append(const wchar_t* filePath, const wchar_t* content);
	// 写入文件
	static bool Write(const char* filePath, const char* content);
	// 写入文件-宽字符
	static bool Write(const wchar_t* filePath, const wchar_t* content);

public:		// Query
	// 判断指定路径是否存在
	static bool isDir(const char *dirPath);
	// 判断目录是否存在
	static bool isDir(const wchar_t* dirPath);
	// 文件是否存在
	static bool isFile(const char* filePath);
	// 文件是否存在
	static bool isFile(const wchar_t* filePath);

	// 获取文件大小
	static int getFileSize(const char* filePath);
	// 获取文件大小
	static int getFileSize(const wchar_t* filePath);

	// 读取整个文件内容
	static bool read(const char* filePath, string& content);
	// 读取整个文件内容-宽字符
	static bool read(const wchar_t* filePath, String& content);
public:
	//逐行读取
	static void ReadTxtLine(string file);
	//逐字符读取
	static void ReadTxtChar(string file);
	//逐行追加
	static void WriteLineToTxt(string file, string line);
	//逐字符追加
	static void WriteCharToTxt(string file, char c);
	//偏移指定字节写入
	static void WriteToTxtOffset(string file, int offset, string content);
};

#endif
