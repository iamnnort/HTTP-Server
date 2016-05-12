#pragma once
#include "ServerLibrary.h"
#include <ctime>

class Client : public ServerLibrary
{
	string listen_name;
	string site_name;
	string file_addr;
	string access_type;
	int access_status;
public:
	Client() {};
	~Client() {};
	string GetListenName();
	string GetFileDir();
	string GetSiteName();
	void SetAccessStatus(int);
	void MakeClientName(string);
	void MakeRequestedPath(string);
	void MakeRequestedSite(string);
	void MakeRequestedFile(string);
	void MakeClientAccessType(string);
	void MakeClientInfo(string);
	void PrintClientInfo();
	string MakeLogContent();
};

