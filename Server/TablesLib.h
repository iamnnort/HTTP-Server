#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "lib/sqlite3.h"

using namespace std;

struct TableNames {
	const char* full_title;
	char short_title;
};

struct Domains {
	int id;
	string domain;
};

struct Users {
	int id;
	string name;
	string surname;
	double salary;
};

class TablesLib {

protected:
	list<TableNames> table_names;
	list<Domains> domains;
	list<Users> users;
	
public:
	TablesLib();
	~TablesLib();
	list<Domains> GetDomains();
	list<Users> GetUsers();
	char TablesLib::GetShortCommand(const char*);
};

