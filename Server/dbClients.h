#pragma once
#include "SQLiteDatabase.h"

class dbClients : public SQLiteDatabase
{
public:
	dbClients();
	~dbClients();
	void SelectUsers();
	bool AddUser(const string, string);
	bool RemoveUser(const string);
};

