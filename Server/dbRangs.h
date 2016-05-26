#pragma once
#include "SQLiteDatabase.h"

class dbRangs : public SQLiteDatabase
{
public:
	dbRangs();
	~dbRangs();
	void SelectRangs();
};

