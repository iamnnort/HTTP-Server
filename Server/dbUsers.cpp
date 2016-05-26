#include "dbUsers.h"

dbUsers::dbUsers() {
}

dbUsers::~dbUsers() {
}

void dbUsers::SelectUsers(const string _where) {

	sqlite3_stmt *stmt = this->Select("users", _where);

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

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 3);
			buffer >> user.rang_id;

			this->users.push_back(user);
		}

		sqlite3_finalize(stmt);
	}
}

bool dbUsers::AddUser(const string login, string password, int rang_id) {

	if ((!login.length()) || (!password.length())) {
		return false;
	}

	password = this->MD5(password);

	stringstream ss;
	ss << "'";
	ss << login;
	ss << "', '";
	ss << password;
	ss << "', ";
	ss << rang_id;
	string values = ss.str();

	return this->Insert("users", "login, password, rang_id", values.c_str());
}

bool dbUsers::RemoveUser(const string login) {

	if (!login.length()) {
		return false;
	}

	return this->Delete("users", "login", login.c_str());
}

bool dbUsers::AddUserRights(const string login, const string domain, const string page) {

	if (!login.length() || !page.length()) {
		return false;
	}

	string _where = "login = '" + login + "'";
	this->SelectUsers(_where);
	list<Users> users = this->GetUsers();
	list<Users>::iterator itu = users.begin();

	if (users.size() != 1) {
		cout << "Unknown user." << endl;
		return false;
	}

	_where.clear();
	stringstream ss;
	ss << "domain_id = ";
	ss << "(SELECT id FROM domains WHERE domain = '";
	ss << domain << "' LIMIT 1)";
	ss << "AND page = '";
	ss << page << "'";
	_where = ss.str();

	dbPages pg;
	pg.SelectPages(_where);
	list<PrivatePage> pages = pg.GetPages();
	list<PrivatePage>::iterator itp = pages.begin();

	stringstream sstream;
	sstream << itu->id;
	sstream << ", ";
	sstream << itp->id;
	string values = sstream.str();
	
	if (pages.size() != 1) {
		cout << "Unknown domain or private page." << endl;
		return false;
	}

	return this->Insert("access", "user_id, page_id", values.c_str());
}

bool dbUsers::CheckUserRights(const string login, const string password, const int rang_id, const int page_id) {

	stringstream ss;
	ss << "login = '";
	ss << login;
	ss << "' AND password = '";
	ss << this->MD5(password);
	ss << "' AND (rang_id = ";
	ss << rang_id;
	ss << " OR id IN (SELECT user_id FROM access WHERE page_id = ";
	ss << page_id;
	ss << ") )";
	string _where = ss.str();
	this->SelectUsers(_where);
	list<Users> users = this->GetUsers();
	
	if (users.size() == 1) {
		return true;
	}

	return false;
}