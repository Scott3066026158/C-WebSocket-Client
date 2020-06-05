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

// ׷������ �ɹ�����true ʧ�ܷ���false
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

// ׷������ �ɹ�����true ʧ�ܷ���false
bool FileUtil::append(const wchar_t* filePath, const wchar_t* content)
{
	string path = StringUtil::wstrToStr(filePath);
	string appendContent = StringUtil::wstrToStr(content);
	return append(path.c_str(), appendContent.c_str());
}

// д���ļ�
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

// д���ļ�-���ַ�
bool FileUtil::Write(const wchar_t* filePath, const wchar_t* content)
{
	string sFile, sContent;
	string path = StringUtil::wstrToStr(filePath);
	string writeContent = StringUtil::wstrToStr(content);
	return Write(path.c_str(), writeContent.c_str());
}

// �ļ��Ƿ����
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

// �ļ��Ƿ����
bool FileUtil::isFile(const wchar_t* filePath)
{
	string path = StringUtil::wstrToStr(filePath);
	return isFile(path.c_str());
}

// ��ȡ�ļ���С
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

// ��ȡ�ļ���С
int FileUtil::getFileSize(const wchar_t* filePath)
{
	string path = StringUtil::wstrToStr(filePath);
	return getFileSize(path.c_str());
}

// ��ȡ�����ļ�����
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

// ��ȡ�����ļ�����-���ַ�
bool FileUtil::read(const wchar_t* filePath, String& content)
{
	string path = StringUtil::wstrToStr(filePath);
	string fileContent;
	bool readFlag = read(path.c_str(), fileContent);
	if (!readFlag) return readFlag;
	content = StringUtil::strToWStr(fileContent);
	return readFlag;
}

// �ж�Ŀ¼�Ƿ����
bool FileUtil::isDir(const char *dirPath)
{
	if ((_access(dirPath, 0)) != -1)
	{
		return true;
	}
	return false;
}

// �ж�Ŀ¼�Ƿ����
bool FileUtil::isDir(const wchar_t* dirPath)
{
	string dir = StringUtil::wstrToStr(dirPath);
	return isDir(dir.c_str());
}

//���ж�ȡ
void FileUtil::ReadTxtLine(string file)
{
	ifstream ifs;
	ifs.open(file);   			//���ļ����������ļ���������������Ѿ����������ʧ��
	assert(ifs.is_open());   	//��ʧ��,�����������Ϣ,����ֹ��������

	string s;
	while (getline(ifs, s))		//�зָ���������ʾָ�������簴�շֺŷָ�getline(infile,s,';')
	{
		cout << s << endl;
	}
	ifs.close();             	//�ر��ļ������� 
}

//���ַ���ȡ
void FileUtil::ReadTxtChar(string file)
{
	ifstream ifs;
	ifs.open(file.data());  	//���ļ����������ļ��������� 
	assert(ifs.is_open());   	//��ʧ��,�����������Ϣ,����ֹ�������� 

	char c;
	ifs >> std::noskipws;		//���skipws��ʶ�������Կհ׷���Tab���ո񡢻س��ͻ��У�
	while (!ifs.eof())
	{
		ifs >> c;
		cout << c << endl;

	}
	ifs.close();         	//�ر��ļ������� 
}

//����׷��
void FileUtil::WriteLineToTxt(string file, string line)
{
	ofstream ofs(file, ios::out | ios::app);	//�����׷�ӷ�ʽ���ļ����������򴴽�
	assert(ofs.is_open());   				//��ʧ��,�����������Ϣ,����ֹ��������
	ofs << line << endl;						//д��һ��
	ofs.close();
}

//���ַ�׷��
void FileUtil::WriteCharToTxt(string file, char c)
{
	ofstream ofs(file, ios::out | ios::app);	//�����׷�ӷ�ʽ���ļ����������򴴽�
	assert(ofs.is_open());   				//��ʧ��,�����������Ϣ,����ֹ��������
	ofs << c;									//д��һ���ַ�
	ofs.close();
}

//ƫ��ָ���ֽ�д��
void FileUtil::WriteToTxtOffset(string file, int offset, string content)
{
	ofstream ofs(file, ios::out | ios::in);			//�Բ���շ�ʽ���ļ����������򴴽���ע�⣺��Ҫʹ��ios::appģʽ�򿪣���Ϊһ��д�ں��棬seekpҲ��Ч
	assert(ofs.is_open());   						//��ʧ��,�����������Ϣ,����ֹ��������
	ofs.seekp(offset, ios::beg);					//������ʼλ��ƫ��
	ofs << content;									//д������
	ofs.close();
}