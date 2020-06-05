#include "stdafx.h"
#include "HMAC_SHA256.h"
SHA_INT_TYPE SHA1_K(SHA_INT_TYPE t) {
	if (t <= 19)return 0x5a827999;
	else if (t <= 39)return 0x6ed9eba1;
	else if (t <= 59)return 0x8f1bbcdc;
	else if (t <= 79)return 0xca62c1d6;
	return 0;
}

SHA_INT_TYPE SHA1_f(SHA_INT_TYPE t, SHA_INT_TYPE B, SHA_INT_TYPE C, SHA_INT_TYPE D) {
	if (t <= 19)return (B&C) | (~B&D);
	else if (t <= 39)return B^C^D;
	else if (t <= 59)return (B&C) | (B&D) | (C&D);
	else if (t <= 79)return B^C^D;
	return 0;
}

SHA_INT_TYPE SHA1_rotl(SHA_INT_TYPE r, SHA_INT_TYPE x) {
	SHA_INT_TYPE rot = r % 32;
	return (x >> (32 - rot)) | (x << rot);
}

void HMAC_SHA1_Copy(unsigned char *copy, SHA1_DATA *shd) {
	SHA_INT_TYPE Value[5];
	for (int i = 0; i<5; i++)Value[i] = SHA_Reverse(shd->Value[i]);
	memcpy(copy, Value, 20);
}

SHA_INT_TYPE SHA256_rotr(SHA_INT_TYPE r, SHA_INT_TYPE x) {
	SHA_INT_TYPE rot = r % 32;
	return (x >> rot) | (x << (32 - rot));
}

SHA_INT_TYPE SHA256_sigma0(SHA_INT_TYPE x) {
	return SHA256_rotr(7, x) ^ SHA256_rotr(18, x) ^ (x >> 3);
}

SHA_INT_TYPE SHA256_sigma1(SHA_INT_TYPE x) {
	return SHA256_rotr(17, x) ^ SHA256_rotr(19, x) ^ (x >> 10);
}

SHA_INT_TYPE SHA256_sum0(SHA_INT_TYPE x) {
	return SHA256_rotr(2, x) ^ SHA256_rotr(13, x) ^ SHA256_rotr(22, x);
}

SHA_INT_TYPE SHA256_sum1(SHA_INT_TYPE x) {
	return SHA256_rotr(6, x) ^ SHA256_rotr(11, x) ^ SHA256_rotr(25, x);
}

SHA_INT_TYPE SHA256_ch(SHA_INT_TYPE x, SHA_INT_TYPE y, SHA_INT_TYPE z) {
	return (x & y) ^ (~x & z);
}

SHA_INT_TYPE SHA256_maj(SHA_INT_TYPE x, SHA_INT_TYPE y, SHA_INT_TYPE z) {
	return (x&y) ^ (x&z) ^ (y&z);
}

void SHA_Reverse_INT64(unsigned char *data, unsigned __int64 write) {
	unsigned char cdata[8];
	memcpy(cdata, &write, sizeof(__int64));
	for (int i = 0; i <= 7; i++)*(data + i) = cdata[7 - i];
}

SHA_INT_TYPE SHA_Reverse(SHA_INT_TYPE d) {
	unsigned char b_data[4], a_data[4];
	SHA_INT_TYPE ret;
	memcpy(b_data, &d, sizeof(__int32));
	for (int i = 0; i<4; i++)a_data[i] = b_data[3 - i];
	memcpy(&ret, a_data, sizeof(a_data));
	return ret;
}

void HMAC_SHA256_Copy(unsigned char *copy, SHA256_DATA *shd) {
	SHA_INT_TYPE Value[8];
	for (int i = 0; i<8; i++)Value[i] = SHA_Reverse(shd->Value[i]);
	memcpy(copy, Value, 32);
}

void SHA1_HashBlock(SHA_INT_TYPE *SHA1_H_Data, const unsigned char *data) {
	SHA_INT_TYPE SIT[80];
	SHA_INT_TYPE SIT_d[16];//512ビット、64バイト
	SHA_INT_TYPE a, b, c, d, e;
	for (int i = 0, j = 0; i<16; i++, j += 4)SIT_d[i] = ((*(data + j + 3) & 0xFF) << 24) | ((*(data + j + 2) & 0xFF) << 16) | ((*(data + j + 1) & 0xFF) << 8) | ((*(data + j) & 0xFF));
	for (int i = 0; i<16; i++)SIT[i] = SHA_Reverse(SIT_d[i]);
	for (int t = 16; t <= 79; t++)SIT[t] = SHA1_rotl(1, SIT[t - 3] ^ SIT[t - 8] ^ SIT[t - 14] ^ SIT[t - 16]);
	a = *SHA1_H_Data;
	b = *(SHA1_H_Data + 1);
	c = *(SHA1_H_Data + 2);
	d = *(SHA1_H_Data + 3);
	e = *(SHA1_H_Data + 4);
	for (int t = 0; t <= 79; t++) {
		SHA_INT_TYPE tmp;
		tmp = SHA1_rotl(5, a) + SHA1_f(t, b, c, d) + e + SIT[t] + SHA1_K(t);
		e = d;
		d = c;
		c = SHA1_rotl(30, b);
		b = a;
		a = tmp;
	}
	*SHA1_H_Data += a;
	*(SHA1_H_Data + 1) += b;
	*(SHA1_H_Data + 2) += c;
	*(SHA1_H_Data + 3) += d;
	*(SHA1_H_Data + 4) += e;
}

bool SHA1(SHA1_DATA *sha1d, const char *data, SHA_INT_TYPE size) {
	SHA_INT_TYPE s, h[5], ns;
	int cnt = 0;
	unsigned __int64 s64;
	unsigned char d[64];
	if (!sha1d)return false;
	s = (size) ? size : strlen(data);
	memcpy(h, SHA1_H_Val, sizeof(SHA1_H_Val));

	for (SHA_INT_TYPE i = s, j = 0; i >= 64; i -= 64, j += 64)SHA1_HashBlock(h, (const unsigned char*)(data + j));

	ns = s % 64;

	memset(d, 0, 64);

	memcpy(d, data + (s - ns), ns);

	d[ns] = 0x80;

	if (ns >= 56) {
		SHA1_HashBlock(h, d);
		memset(d, 0, 56);
	}

	s64 = s * 8;

	SHA_Reverse_INT64(&d[56], s64);

	SHA1_HashBlock(h, d);
	memcpy(sha1d->Value, h, sizeof(h));
	sprintf(sha1d->Val_String, "%08X %08X %08X %08X %08X", h[0], h[1], h[2], h[3], h[4]);
	return true;
}

bool HMAC_SHA1(SHA1_DATA *sha1d, const char *b_target, const char *b_key, SHA_INT_TYPE tsize) {
	unsigned char key[65], ipad[64], opad[64];
	unsigned char *tk, tk2[20], tk3[84];
	SHA_INT_TYPE tks;
	SHA1_DATA SD, ret;
	memset(&SD, 0, sizeof(SHA1_DATA));
	memset(key, 0, 65);
	memset(ipad, 0x36, 64);
	memset(opad, 0x5c, 64);
	if (!sha1d)return false;
	if (strlen(b_key) > 64) {
		SHA1(&SD, b_key, 0);
		HMAC_SHA1_Copy(key, &SD);
	}
	else {
		memcpy(key, (unsigned char*)b_key, strlen(b_key));
	}
	memset(&SD, 0, sizeof(SHA1_DATA));
	for (int i = 0; i<64; i++) {
		ipad[i] = key[i] ^ ipad[i];
		opad[i] = key[i] ^ opad[i];
	}
	tks = (tsize) ? tsize : strlen(b_target) + 64;
	tk = (unsigned char *)malloc(tks);
	if (!tk)return false;
	memset(tk, 0, tks);
	memcpy(tk, ipad, 64);
	memcpy(tk + 64, (unsigned char*)b_target, (tsize) ? tsize : strlen(b_target));
	SHA1(&SD, (char *)tk, tks);
	HMAC_SHA1_Copy(tk2, &SD);
	memcpy(tk3, opad, 64);
	memcpy(tk3 + 64, tk2, 20);
	SHA1(&ret, (char *)tk3, 84);
	memcpy(sha1d, &ret, sizeof(SHA1_DATA));
	free(tk);
	return true;
}

void SHA256_HashBlock(SHA_INT_TYPE *SHA256_H_Data, const unsigned char *data) {
	SHA_INT_TYPE SIT[64];
	SHA_INT_TYPE SIT_d[16];
	SHA_INT_TYPE a, b, c, d, e, f, g, h;
	for (int i = 0, j = 0; i<16; i++, j += 4)SIT_d[i] = ((*(data + j + 3) & 0xFF) << 24) | ((*(data + j + 2) & 0xFF) << 16) | ((*(data + j + 1) & 0xFF) << 8) | ((*(data + j) & 0xFF));
	for (int i = 0; i<16; i++)SIT[i] = SHA_Reverse(SIT_d[i]);
	for (int t = 16; t <= 63; t++)	SIT[t] = SHA256_sigma1(SIT[t - 2]) + SIT[t - 7] + SHA256_sigma0(SIT[t - 15]) + SIT[t - 16];
	a = *SHA256_H_Data;
	b = *(SHA256_H_Data + 1);
	c = *(SHA256_H_Data + 2);
	d = *(SHA256_H_Data + 3);
	e = *(SHA256_H_Data + 4);
	f = *(SHA256_H_Data + 5);
	g = *(SHA256_H_Data + 6);
	h = *(SHA256_H_Data + 7);
	for (int t = 0; t <= 63; t++) {
		SHA_INT_TYPE tmp[2];
		tmp[0] = h + SHA256_sum1(e) + SHA256_ch(e, f, g) + SHA256_K_Val[t] + SIT[t];
		tmp[1] = SHA256_sum0(a) + SHA256_maj(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + tmp[0];
		d = c;
		c = b;
		b = a;
		a = tmp[0] + tmp[1];
	}
	*SHA256_H_Data += a;
	*(SHA256_H_Data + 1) += b;
	*(SHA256_H_Data + 2) += c;
	*(SHA256_H_Data + 3) += d;
	*(SHA256_H_Data + 4) += e;
	*(SHA256_H_Data + 5) += f;
	*(SHA256_H_Data + 6) += g;
	*(SHA256_H_Data + 7) += h;
}

bool SHA256(SHA256_DATA *sha256d, const char *data, SHA_INT_TYPE size) {
	SHA_INT_TYPE s, h[8], ns;
	int cnt = 0;
	unsigned __int64 s64;
	unsigned char d[64];
	if (!sha256d)return false;
	s = (size) ? size : strlen(data);
	memcpy(h, SHA256_H_Val, sizeof(SHA256_H_Val));

	for (SHA_INT_TYPE i = s, j = 0; i >= 64; i -= 64, j += 64)SHA256_HashBlock(h, (const unsigned char*)(data + j));

	ns = s % 64;

	memset(d, 0, 64);

	memcpy(d, data + (s - ns), ns);

	d[ns] = 0x80;

	if (ns >= 56) {
		SHA256_HashBlock(h, d);

		memset(d, 0, 56);
	}

	s64 = s * 8;

	SHA_Reverse_INT64(&d[56], s64);

	SHA256_HashBlock(h, d);

	memcpy(sha256d->Value, h, sizeof(h));
	sprintf(sha256d->Val_String, "%08x%08x%08x%08x%08x%08x%08x%08x", h[0], h[1], h[2], h[3], h[4], h[5], h[6], h[7]);
	return true;
}

bool HMAC_SHA256(SHA256_DATA *sha256d, const char *b_target, const char *b_key, SHA_INT_TYPE tsize) {
	unsigned char key[65], ipad[64], opad[64];
	unsigned char *tk, tk2[32], tk3[96];
	SHA_INT_TYPE tks;
	SHA256_DATA SD, ret;
	memset(&SD, 0, sizeof(SHA256_DATA));
	memset(key, 0, 65);
	memset(ipad, 0x36, 64);
	memset(opad, 0x5c, 64);
	if (!sha256d)return false;
	if (strlen(b_key) > 64) {
		SHA256(&SD, b_key, 0);
		HMAC_SHA256_Copy(key, &SD);
	}
	else {
		memcpy(key, (unsigned char*)b_key, strlen(b_key));
	}
	memset(&SD, 0, sizeof(SHA256_DATA));
	for (int i = 0; i<64; i++) {
		ipad[i] = key[i] ^ ipad[i];
		opad[i] = key[i] ^ opad[i];
	}
	tks = (tsize) ? tsize : strlen(b_target) + 64;
	tk = (unsigned char *)malloc(tks);
	if (!tk)return false;
	memset(tk, 0, tks);
	memcpy(tk, ipad, 64);
	memcpy(tk + 64, (unsigned char*)b_target, (tsize) ? tsize : strlen(b_target));
	SHA256(&SD, (char *)tk, tks);
	HMAC_SHA256_Copy(tk2, &SD);
	memcpy(tk3, opad, 64);
	memcpy(tk3 + 64, tk2, 32);
	SHA256(&ret, (char *)tk3, 96);
	memcpy(sha256d, &ret, sizeof(SHA256_DATA));
	free(tk);
	return true;
}

string HMAC_SHA256(const char* data, const char* key)
{
	SHA256_DATA SD256;
	HMAC_SHA256(&SD256, data, key, 0);
	string result = SD256.Val_String;
	return result;
}
