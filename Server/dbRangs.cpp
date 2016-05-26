#include "dbRangs.h"

dbRangs::dbRangs(){
}

dbRangs::~dbRangs(){
}

void dbRangs::SelectRangs() {

	sqlite3_stmt *stmt = this->Select("rangs");

	int stat = sqlite3_step(stmt);
	stringstream buffer;
	this->rangs.clear();

	if (stat == SQLITE_ROW) {

		for (; sqlite3_column_text(stmt, 0); sqlite3_step(stmt)) {

			Rangs rang;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 0);
			buffer >> rang.id;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 1);
			buffer >> rang.rang;

			this->rangs.push_back(rang);
		}

		sqlite3_finalize(stmt);
	}
}
