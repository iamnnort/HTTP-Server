#pragma once
#include "../Server/dbUsers.h"
#include "../Server/dbDomains.h"
#include "../Server/dbPages.h"
#include "../Server/dbRangs.h"

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
	void GetRangsMenu();
	int GetSelectedItem();
	void PrintUsers();
	bool AddUser();
	bool AddUniqueRights();
	bool RemoveUser();
	void PrintDomains();
	bool AddDomain();
	bool RemoveDomain();
	void PrintPages();
	bool AddPage();
	bool RemovePage();
	void PrintRangs();
};

