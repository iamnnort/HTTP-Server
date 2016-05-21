#include "dbPages.h"

dbPages::dbPages(){
}

dbPages::~dbPages(){
}

void dbPages::SelectPages(const string _where) {

	sqlite3_stmt *stmt = this->Select("private_page", _where);

	int stat = sqlite3_step(stmt);
	stringstream buffer;
	this->pages.clear();

	if (stat == SQLITE_ROW) {

		for (; sqlite3_column_text(stmt, 0); sqlite3_step(stmt)) {

			PrivatePage page;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 0);
			buffer >> page.id;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 1);
			buffer >> page.domain_id;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 2);
			buffer >> page.page;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 3);
			buffer >> page.access_level;

			this->pages.push_back(page);
		}

		sqlite3_finalize(stmt);
	}
}

bool dbPages::AddPage(const string page, const int assecc_level, const int domain_id) {

	if ((!page.length()) || !assecc_level || !domain_id) {
		return false;
	}

	stringstream ss;
	ss << "'";
	ss << page;
	ss << "', ";
	ss << assecc_level;
	ss << ", ";
	ss << domain_id;
	string values = ss.str();

	return this->Insert("private_page", "page, access_level, domain_id", values.c_str());
}

bool dbPages::RemovePage(const string page, const int domain_id) {

	if (!page.length()) {
		return false;
	}

	stringstream ss;
	ss << "DELETE FROM private_page WHERE ";
	ss << "page = '" << page << "' AND domain_id = " << domain_id;
	string sql = ss.str();

	return this->Execute(sql.c_str());
}

bool dbPages::CheckPage(const string page) {

	cout << "Page: " << page << endl;
	
	return true;
}
