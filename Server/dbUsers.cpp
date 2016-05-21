#include "dbUsers.h"

dbUsers::dbUsers() {
}

dbUsers::~dbUsers() {
}

void dbUsers::SelectUsers() {

	sqlite3_stmt *stmt = this->Select("users");

	int stat = sqlite3_step(stmt);
	stringstream buffer;
	this->users.clear();

	if (stat == SQLITE_ROW) {

		for (; sqlite3_column_text(stmt, 0); sqlite3_step(stmt)) {

			Users user;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 0);
			buffer >> user.id;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 1);
			buffer >> user.login;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 2);
			buffer >> user.password;

			this->users.push_back(user);
		}

		sqlite3_finalize(stmt);
	}
}

bool dbUsers::AddUser(const string login, string password) {

	if ((!login.length()) || (!password.length())) {
		return false;
	}

	password = this->MD5(password);

	stringstream ss;
	ss << "'";
	ss << login;
	ss << "', '";
	ss << password;
	ss << "'";
	string values = ss.str();

	return this->Insert("users", "login, password", values.c_str());
}

bool dbUsers::RemoveUser(const string login) {

	if (!login.length()) {
		return false;
	}

	return this->Delete("users", "login", login.c_str());
}