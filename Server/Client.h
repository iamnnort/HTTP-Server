#pragma once
#include "ServerLibrary.h"
#include "Support.h"
#include <ctime>

class Client : public ServerLibrary
{
	string listen_name;
	string site_name;
	string file_addr;
	string access_type;
	int access_status;
	string login;
	string password;
public:
	Client() {};
	~Client() {};
	string GetListenName();
	string GetFileDir();
	string GetSiteName();
	string GetFileAddr();
	string GetUserLogin();
	string GetUserPassword();
	int GetAccessStatus();
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

