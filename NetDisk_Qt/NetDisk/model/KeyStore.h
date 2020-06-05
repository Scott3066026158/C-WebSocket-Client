#pragma once
#ifndef KeyStore_H
#define KeyStore_H
#include "stdafx.h"
#include "Json.h"
/*
* ��Կ��
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
	// ��ַ
	string address;
	// ������Ϣ
	Crypto* crypto;
	// ������Կ����
	string kdf;
	// ������Կ����
	KDFParams* kdfParams;
	// mac
	string mac;
};

class Crypto
{
public:
	// �����㷨
	string cipher;
	// secretKey
	string cipherText;
	// �����㷨����
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
