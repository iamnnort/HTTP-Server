#include "dbDomains.h"

dbDomains::dbDomains(){
}

dbDomains::~dbDomains(){
}

void dbDomains::SelectDomains(const string _where) {

	sqlite3_stmt *stmt = this->Select("domains", _where);

	int stat = sqlite3_step(stmt);
	stringstream buffer;
	this->domains.clear();

	if (stat == SQLITE_ROW) {

		for (; sqlite3_column_text(stmt, 0); sqlite3_step(stmt)) {

			Domains domain;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 0);
			buffer >> domain.id;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 1);
			buffer >> domain.domain;

			this->domains.push_back(domain);
		}

		sqlite3_finalize(stmt);
	}
}

bool dbDomains::AddDomain(string domain) {

	if (!domain.length()) {
		return false;
	}

	stringstream ss;
	ss << "'";
	ss << domain;
	ss << "'";
	domain = ss.str();
	
	return this->Insert("domains", "domain", domain.c_str());
}

bool dbDomains::RemoveDomain(const string domain) {

	if (!domain.length()) {
		return false;
	}

	return this->Delete("domains", "domain", domain.c_str());
}
