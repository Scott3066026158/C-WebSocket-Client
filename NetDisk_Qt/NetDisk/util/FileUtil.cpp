#include "stdafx.h"
#include "FileUtil.h"
#include "StringUtil.h"
#include <direct.h>
FileUtil::FileUtil()
{
}


FileUtil::~FileUtil()
{
}

bool FileUtil::createDir(const char *dirPath)
{
	if (_mkdir(dirPath)) return false;
	return true;
}

bool FileUtil::createDir(const wchar_t* dirPath)
{
	string sDir = StringUtil::wstrToStr(dirPath);
	return createDir(sDir.c_str());
}

// 追加内容 成功返回true 失败返回false
bool FileUtil::append(const char* filePath, const char* content)
{
	ofstream fs(filePath, ios::app);
	if (fs)
	{
		fs << content;
		fs.close();
		return true;
	}
	return false;
}

// 追加内容 成功返回true 失败返回false
bool FileUtil::append(const wchar_t* filePath, const wchar_t* content)
{
	string path = StringUtil::wstrToStr(filePath);
	string appendContent = StringUtil::wstrToStr(content);
	return append(path.c_str(), appendContent.c_str());
}

// 写入文件
bool FileUtil::Write(const char* filePath, const char* content)
{
	ofstream fs(filePath, ios::out);
	if (fs)
	{
		fs << content;
		fs.close();
		return true;
	}
	return false;
}

// 写入文件-宽字符
bool FileUtil::Write(const wchar_t* filePath, const wchar_t* content)
{
	string sFile, sContent;
	string path = StringUtil::wstrToStr(filePath);
	string writeContent = StringUtil::wstrToStr(content);
	return Write(path.c_str(), writeContent.c_str());
}

// 文件是否存在
bool FileUtil::isFile(const char* filePath)
{
	ifstream fs(filePath, ios::in);
	if (fs)
	{
		fs.close();
		return true;
	}
	return false;
}

// 文件是否存在
bool FileUtil::isFile(const wchar_t* filePath)
{
	string path = StringUtil::wstrToStr(filePath);
	return isFile(path.c_str());
}

// 获取文件大小
int FileUtil::getFileSize(const char* filePath)
{
	FILE* fp = 0;
	int fileLen = 0;
	fp = fopen(filePath, "rb");
	if (!fp)
	{
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	fileLen = ftell(fp);
	fclose(fp);
	return fileLen;
}

// 获取文件大小
int FileUtil::getFileSize(const wchar_t* filePath)
{
	string path = StringUtil::wstrToStr(filePath);
	return getFileSize(path.c_str());
}

// 读取整个文件内容
bool FileUtil::read(const char* filePath, string& content)
{
	if (!FileUtil::isFile(filePath)) return false;

	int fileLength = FileUtil::getFileSize(filePath);
	char *szContent = new char[fileLength + 1];
	memset(szContent, '\0', fileLength + 1);
	ifstream fs(filePath, ios::in);
	if (fs)
	{
		if (fileLength > 0)
		{
			while (!fs.eof())
			{
				fs.read(szContent, fileLength);
			}
		}
		fs.close();
	}
	content = szContent;
	delete[] szContent;
	szContent = 0;
	return true;
}

// 读取整个文件内容-宽字符
bool FileUtil::read(const wchar_t* filePath, String& content)
{
	string path = StringUtil::wstrToStr(filePath);
	string fileContent;
	bool readFlag = read(path.c_str(), fileContent);
	if (!readFlag) return readFlag;
	content = StringUtil::strToWStr(fileContent);
	return readFlag;
}

// 判断目录是否存在
bool FileUtil::isDir(const char *dirPath)
{
	if ((_access(dirPath, 0)) != -1)
	{
		return true;
	}
	return false;
}

// 判断目录是否存在
bool FileUtil::isDir(const wchar_t* dirPath)
{
	string dir = StringUtil::wstrToStr(dirPath);
	return isDir(dir.c_str());
}

//逐行读取
void FileUtil::ReadTxtLine(string file)
{
	ifstream ifs;
	ifs.open(file);   			//将文件流对象与文件关联起来，如果已经关联则调用失败
	assert(ifs.is_open());   	//若失败,则输出错误消息,并终止程序运行

	string s;
	while (getline(ifs, s))		//行分隔符可以显示指定，比如按照分号分隔getline(infile,s,';')
	{
		cout << s << endl;
	}
	ifs.close();             	//关闭文件输入流 
}

//逐字符读取
void FileUtil::ReadTxtChar(string file)
{
	ifstream ifs;
	ifs.open(file.data());  	//将文件流对象与文件连接起来 
	assert(ifs.is_open());   	//若失败,则输出错误消息,并终止程序运行 

	char c;
	ifs >> std::noskipws;		//清除skipws标识，不忽略空白符（Tab、空格、回车和换行）
	while (!ifs.eof())
	{
		ifs >> c;
		cout << c << endl;

	}
	ifs.close();         	//关闭文件输入流 
}

//逐行追加
void FileUtil::WriteLineToTxt(string file, string line)
{
	ofstream ofs(file, ios::out | ios::app);	//以输出追加方式打开文件，不存在则创建
	assert(ofs.is_open());   				//若失败,则输出错误消息,并终止程序运行
	ofs << line << endl;						//写入一行
	ofs.close();
}

//逐字符追加
void FileUtil::WriteCharToTxt(string file, char c)
{
	ofstream ofs(file, ios::out | ios::app);	//以输出追加方式打开文件，不存在则创建
	assert(ofs.is_open());   				//若失败,则输出错误消息,并终止程序运行
	ofs << c;									//写入一个字符
	ofs.close();
}

//偏移指定字节写入
void FileUtil::WriteToTxtOffset(string file, int offset, string content)
{
	ofstream ofs(file, ios::out | ios::in);			//以不清空方式打开文件，不存在则创建。注意：不要使用ios::app模式打开，因为一定写在后面，seekp也无效
	assert(ofs.is_open());   						//若失败,则输出错误消息,并终止程序运行
	ofs.seekp(offset, ios::beg);					//从流开始位置偏移
	ofs << content;									//写入内容
	ofs.close();
}