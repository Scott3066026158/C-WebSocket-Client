#pragma once
#ifndef KeyPair_H
#define KeyPair_H
#include "stdafx.h"
#include "Json.h"
/*
 * √‹‘ø∂‘
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
	// ÀΩ‘ø
	string privateKey;
	// π´‘ø
	string publicKey;
	// µÿ÷∑
	string address;
};
#endif // !KeyPair_H
