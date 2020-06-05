#pragma once
#ifndef KeyStore_H
#define KeyStore_H
#include "stdafx.h"
#include "Json.h"
/*
* 密钥库
*/
class KeyStore
{
public:
	KeyStore();
	~KeyStore();
public:
	KeyStore* parse(Json::Value value);
	bool isEmpty();
public:
	// 地址
	string address;
	// 加密信息
	Crypto* crypto;
	// 派生秘钥加密
	string kdf;
	// 派生秘钥参数
	KDFParams* kdfParams;
	// mac
	string mac;
};

class Crypto
{
public:
	// 加密算法
	string cipher;
	// secretKey
	string cipherText;
	// 加密算法参数
	string cipherParams;
};

class KDFParams
{
public:
	int dkLen;
	int n;
	int p;
	int r;
	string salt;
};
#endif // !KeyPair_H
