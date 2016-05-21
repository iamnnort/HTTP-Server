#pragma once
#include "Manager.h"
#include "Support.h"
#include "dbPages.h"
#include "dbDomains.h"
#include "Client.h"


class FileManager : public Manager
{
	string server_response_body;
public:
	FileManager() {};
	~FileManager() {};
	int MakeResponseBody(Client);
	string GetResponseBody();
};

