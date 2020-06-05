#pragma once
#ifndef _JsonString_H_
#define _JsonString_H_

#include "stdafx.h"

template<class T>
class JsonString
{
public:
	// 结果码
	string code;
	// 返回信息
	string message;
	// 返回的数据
	T data;
};

// 状态码
enum ErrorCode
{
	// 请求成功
	successful,
	// json数据解析失败
	parse_json_error = 55555,
	// 指定json数据不存在
	jsonkey_no_exist

};

string ctos(ErrorCode code);
#endif // !_JsonString_H_
