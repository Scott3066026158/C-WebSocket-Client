#pragma once
#ifndef KeyPair_H
#define KeyPair_H
#include "stdafx.h"
#include "Json.h"
/*
 * ��Կ��
 */
class KeyPair
{
public:
	KeyPair();
	~KeyPair();
public:
	KeyPair* parse(Json::Value value);
	bool isEmpty();
public:
	// ˽Կ
	string privateKey;
	// ��Կ
	string publicKey;
	// ��ַ
	string address;
};
#endif // !KeyPair_H
