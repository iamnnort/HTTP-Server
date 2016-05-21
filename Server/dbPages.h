#pragma once
#include "SQLiteDatabase.h"

class dbPages : public SQLiteDatabase
{
public:
	dbPages();
	~dbPages();
	void SelectPages(const string = "");
	bool AddPage(const string, const int, const int);
	bool RemovePage(const string, const int);
	bool CheckPage(const string);
};

