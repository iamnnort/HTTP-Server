#include "Clients.h"

Clients::Clients() {
}

Clients::~Clients() {
}

void Clients::SelectUsers() {

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

void Clients::PrintUsers() {

	

}
