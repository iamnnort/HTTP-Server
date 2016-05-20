#pragma once
#include "SQLiteDatabase.h"

class dbDomains : public SQLiteDatabase
{
public:
	dbDomains();
	~dbDomains();
	void SelectDomains();
	bool AddDomain(string);
	bool RemoveDomain(const string);
};

