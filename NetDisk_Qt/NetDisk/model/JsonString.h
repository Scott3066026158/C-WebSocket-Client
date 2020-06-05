#pragma once
#ifndef _JsonString_H_
#define _JsonString_H_

#include "stdafx.h"

template<class T>
class JsonString
{
public:
	// �����
	string code;
	// ������Ϣ
	string message;
	// ���ص�����
	T data;
};

// ״̬��
enum ErrorCode
{
	// ����ɹ�
	successful,
	// json���ݽ���ʧ��
	parse_json_error = 55555,
	// ָ��json���ݲ�����
	jsonkey_no_exist

};

string ctos(ErrorCode code);
#endif // !_JsonString_H_
