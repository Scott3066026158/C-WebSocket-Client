/* ----------------------------------------------------------
�ļ����ƣ�HMAC_MD5_API.h

���ߣ��ؽ���

MSN��splashcn@msn.com

��ǰ�汾��V1.1

��ʷ�汾��
V1.1	2010��05��08��
�������BASE64�����ַ����ӿڡ�

V1.0	2010��04��15��
�����ʽ�汾��

����������
MD5��HMAC-MD5����

�ӿں�����
MD5_Hash
HMAC_MD5_Hash
MD5_BASE64
HMAC_MD5_BASE64
------------------------------------------------------------ */
#pragma once
#ifndef _HMAC_H_
#define _HMAC_H_

#include <windows.h>
//-------------------��������-------------
#ifdef __cplusplus
extern "C" {
#endif

	/*
	���ܣ������������ݵ�MD5��ϣֵ
	��ڲ�����
	inputBuffer����������
	inputCount���������ݳ��ȣ��ֽ�����
	outputBuffer���������ݵĹ�ϣֵ
	����ֵ��
	��ϣֵ����Ч���ȣ��ֽ�����
	*/
	INT MD5_Hash(const BYTE* inputBuffer, UINT inputCount, BYTE* outputBuffer);

	/*
	���ܣ������������ݵ�HMAC-MD5��ϣֵ
	��ڲ�����
	inputBuffer����������
	inputCount���������ݳ��ȣ��ֽ�����
	userKey���û���Կ
	UserKeyLen���û���Կ����
	outputBuffer���������ݵĹ�ϣֵ
	����ֵ��
	��ϣֵ����Ч���ȣ��ֽ�����
	*/
	string HMAC_MD5_Hash(const BYTE* inputBuffer, UINT inputCount, const BYTE* userKey, UINT UserKeyLen);


#ifdef __cplusplus
}
#endif
#endif