#pragma once
#ifndef _FileUtil_H_
#define _FileUtil_H_

class FileUtil
{
public:
	FileUtil();
	~FileUtil();
public:		//Create
	// ����Ŀ¼ �ɹ�����true ʧ�ܷ���false
	static bool createDir(const char* dir);
	// ����Ŀ¼ �ɹ�����true ʧ�ܷ���false
	static bool createDir(const wchar_t* dir);

public:		//Update
	// ׷������ �ɹ�����true ʧ�ܷ���false
	static bool append(const char* filePath, const char* content);
	// ׷������ �ɹ�����true ʧ�ܷ���false
	static bool append(const wchar_t* filePath, const wchar_t* content);
	// д���ļ�
	static bool Write(const char* filePath, const char* content);
	// д���ļ�-���ַ�
	static bool Write(const wchar_t* filePath, const wchar_t* content);

public:		// Query
	// �ж�ָ��·���Ƿ����
	static bool isDir(const char *dirPath);
	// �ж�Ŀ¼�Ƿ����
	static bool isDir(const wchar_t* dirPath);
	// �ļ��Ƿ����
	static bool isFile(const char* filePath);
	// �ļ��Ƿ����
	static bool isFile(const wchar_t* filePath);

	// ��ȡ�ļ���С
	static int getFileSize(const char* filePath);
	// ��ȡ�ļ���С
	static int getFileSize(const wchar_t* filePath);

	// ��ȡ�����ļ�����
	static bool read(const char* filePath, string& content);
	// ��ȡ�����ļ�����-���ַ�
	static bool read(const wchar_t* filePath, String& content);
public:
	//���ж�ȡ
	static void ReadTxtLine(string file);
	//���ַ���ȡ
	static void ReadTxtChar(string file);
	//����׷��
	static void WriteLineToTxt(string file, string line);
	//���ַ�׷��
	static void WriteCharToTxt(string file, char c);
	//ƫ��ָ���ֽ�д��
	static void WriteToTxtOffset(string file, int offset, string content);
};

#endif
