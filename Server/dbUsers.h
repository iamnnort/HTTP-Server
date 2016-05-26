#pragma once
#include "SQLiteDatabase.h"
#include "dbPages.h"

class dbUsers : public SQLiteDatabase
{
public:
	dbUsers();
	~dbUsers();
	void SelectUsers(const string = "");
	bool AddUser(const string, string, int);
	bool AddUserRights(const string, const string, const string);
	bool RemoveUser(const string);
	bool CheckUserRights(const string, const string, const int, const int);
};

