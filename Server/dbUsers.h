#pragma once
#include "SQLiteDatabase.h"

class dbUsers : public SQLiteDatabase
{
public:
	dbUsers();
	~dbUsers();
	void SelectUsers();
	bool AddUser(const string, string);
	bool RemoveUser(const string);
};

