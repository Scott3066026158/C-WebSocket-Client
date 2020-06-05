#include "stdafx.h"
#include "KeyPair.h"
#include "StringUtil.h"

KeyPair::KeyPair()
{

}

KeyPair::~KeyPair()
{

}

KeyPair* KeyPair::parse(Json::Value value)
{
	if (value.isMember(privateKey) && value[privateKey].isString())
	{
		this->privateKey = value[privateKey].asString();
	}
	if (value.isMember(publicKey) && value[publicKey].isString())
	{
		this->privateKey = value[publicKey].asString();
	}
	if (value.isMember(address) && value[address].isString())
	{
		this->privateKey = value[address].asString();
	}
	return this;
}

bool KeyPair::isEmpty()
{
	return StringUtil::isEmpty(3, this->privateKey, this->publicKey, this->address);
}