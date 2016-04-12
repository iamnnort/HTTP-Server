#pragma once
#include "Manager.h"
#include "Support.h"


class FileManager : public Manager
{
	string server_response_body;
public:
	FileManager() {};
	~FileManager() {};
	int MakeResponseBody(string);
	string GetResponseBody();
};

