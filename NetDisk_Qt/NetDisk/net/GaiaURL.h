#ifndef _GAIAURL_H_
#define _GAIAURL_H_
#include "stdafx.h"

class GaiaURL
{
public:

	GaiaURL();
	~GaiaURL();
	string Get(string url, string apikey);
	string Post(string url, string content, int length, string apikey);
	string Delete(string url, string apikey);
	string GetSign();
	void Start(int port);

};

#endif