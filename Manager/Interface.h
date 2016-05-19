#pragma once
#include "../Server/Clients.h"

#define LINE_SIZE 30
#define BORDER 2

class Interface
{
public:
	Interface() {};
	~Interface() {};
	string getSeparators(const int, const char);
	string GetMenuItem(const int, const char*, const char);
	string GetMenuItem(const vector<string>, const char);
	void GetMainMenu();
	void GetUsersMenu();
	void GetDomainsMenu();
	void GetPrivatePagesMenu();
	int GetSelectedItem();
	void PrintUsers(list<Users>);
};
