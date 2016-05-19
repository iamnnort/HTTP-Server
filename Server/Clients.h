#pragma once
#include "SQLiteDatabase.h"

class Clients : public SQLiteDatabase
{
public:
	Clients();
	~Clients();
	void SelectUsers();
	void PrintUsers();
};

