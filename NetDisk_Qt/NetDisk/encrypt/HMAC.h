/* ----------------------------------------------------------
文件名称：HMAC_MD5_API.h

作者：秦建辉

MSN：splashcn@msn.com

当前版本：V1.1

历史版本：
V1.1	2010年05月08日
增加输出BASE64编码字符串接口。

V1.0	2010年04月15日
完成正式版本。

功能描述：
MD5和HMAC-MD5加密

接口函数：
MD5_Hash
HMAC_MD5_Hash
MD5_BASE64
HMAC_MD5_BASE64
------------------------------------------------------------ */
#pragma once
#ifndef _HMAC_H_
#define _HMAC_H_

#include <windows.h>
//-------------------导出函数-------------
#ifdef __cplusplus
extern "C" {
#endif

	/*
	功能：计算输入数据的MD5哈希值
	入口参数：
	inputBuffer：输入数据
	inputCount：输入数据长度（字节数）
	outputBuffer：输入数据的哈希值
	返回值：
	哈希值的有效长度（字节数）
	*/
	INT MD5_Hash(const BYTE* inputBuffer, UINT inputCount, BYTE* outputBuffer);

	/*
	功能：计算输入数据的HMAC-MD5哈希值
	入口参数：
	inputBuffer：输入数据
	inputCount：输入数据长度（字节数）
	userKey：用户密钥
	UserKeyLen：用户密钥长度
	outputBuffer：输入数据的哈希值
	返回值：
	哈希值的有效长度（字节数）
	*/
	string HMAC_MD5_Hash(const BYTE* inputBuffer, UINT inputCount, const BYTE* userKey, UINT UserKeyLen);


#ifdef __cplusplus
}
#endif
#endif