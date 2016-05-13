#pragma once

#include "TablesLib.h"

#define DB_NAME "../settings/lib/database.sqlite3"

class SQLiteDatabase: public TablesLib
{
	/*
	 * @var db database descriptor
	 */
	sqlite3 *db = nullptr;
	/*
	 * @var err database error message
	 */
	char *err = nullptr;

public:
	SQLiteDatabase(const char* = DB_NAME);
	~SQLiteDatabase();
	void Error(const char*, const char*);
	void Init();
	void CreateTable(const char*, const char*);
	bool Execute(const char*);
	bool Insert(const char*, const char*, const char*);
	void Select(const char*);
	void SelectDomains(sqlite3_stmt*);
	void SelectUsers(sqlite3_stmt*);
};

