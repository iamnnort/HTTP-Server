#pragma once
#include "Manager.h"
#include "Support.h"
#include "dbPages.h"
#include "dbDomains.h"
#include "dbUsers.h";
#include "Client.h"


class FileManager : public Manager
{
	string server_response_body;
public:
	FileManager() {};
	~FileManager() {};
	void MakeResponseBody(Client*);
	string GetResponseBody();
};

