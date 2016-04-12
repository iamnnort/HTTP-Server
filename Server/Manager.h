#pragma once
#include "ServerLibrary.h"

class Manager: public ServerLibrary
{
	string filedir;
	string server_response;

public:
	Manager();
	~Manager();
	string GetFileDir();
	string GetResponse();
	void GetRequestedFile(string message);
	void MakeResponse(int, string);
};

