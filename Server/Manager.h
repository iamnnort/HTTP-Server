#pragma once
#include "ServerLibrary.h"
#include "Logger.h"

class Manager: public ServerLibrary
{
	string server_response;

public:
	Manager() {};
	~Manager() {};
	string GetResponse();
	void MakeResponse(int, string);
	bool MakeLog(string, string);
};

