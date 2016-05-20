#include "TablesLib.h"

TablesLib::TablesLib() {

	TableNames table;
	table.full_title = "domains";
	table.short_title = 'd';
	table_names.push_back(table);

	table.full_title = "users";
	table.short_title = 'u';
	table_names.push_back(table);
}

TablesLib::~TablesLib() {

	this->domains.clear();
	this->users.clear();
}

list<Domains> TablesLib::GetDomains(){
	
	return this->domains;
}
list<Users> TablesLib::GetUsers() {

	return this->users;
}

/*
 * Transformation long command to short for using in switch operator.
 *
 * @param long_command long command
 * @return char new short command or 'z' - 'zero'
 */
char TablesLib::GetShortCommand(const char *long_command) {

	char short_command = 'z';
	list<TableNames>::iterator it;
	for (it = this->table_names.begin(); it != this->table_names.end(); it++) {
		if (!strcmp(long_command, it->full_title)) {
			short_command = it->short_title;
			break;
		}
	}

	return short_command;
}

string TablesLib::MD5(string source) {

	source = "a156" + source + "qwd12" + "belars" + source + "e42rv" + "dsa14fd" + source;
	source = source.substr(1, 6) + source.substr(3, 2) + source.substr(6, 9);
	source = source.insert(5, source);
	source = source.substr(2, 13) + source.substr(15, 5);

	return source;
}