#include "SQLiteDatabase.h"

/**
 * Open sqlite3 database file or create if one not exist.
 *
 * @param db_name SQLiteDatabase file name.
 */
SQLiteDatabase::SQLiteDatabase(const char* db_name){

	if (sqlite3_open(db_name, &(this->db)) != SQLITE_OK) {
		this->Error("SQL", sqlite3_errmsg(db));
	}
	else {
		this->Init();
	}
}

/**
 * Close sqlite3 database file.
 */
SQLiteDatabase::~SQLiteDatabase(){

	sqlite3_close(this->db);
}

/**
 * Print error message on screen.
 *
 * @param type message type.
 * @param err_msg message body.
 */
void SQLiteDatabase::Error(const char* type, const char* err_msg) {

	cout << type << ": " << err_msg << endl;
}

/**
 * Initialize columns in database.
 */
void SQLiteDatabase::Init() {

	const char* colDomains ="id INTEGER PRIMARY KEY AUTOINCREMENT," \
							"domain TEXT NOT NULL";
	this->CreateTable("domains", colDomains);

	const char* colUsers =	"id INTEGER PRIMARY KEY AUTOINCREMENT," \
							"name TEXT NOT NULL," \
							"surname TEXT NOT NULL," \
							"salary REAL NOT NULL";
	this->CreateTable("users", colUsers);
}

/**
* Create table in database if it not exists.
*
* @param table new table name.
* @param columns list of new columns.
*/
void SQLiteDatabase::CreateTable(const char* table, const char* columns) {

	string sql = (string)"CREATE TABLE IF NOT EXISTS "
		+ table
		+ '(' + columns + ')';

	this->Execute(sql.c_str());
}

/**
 * Send query to database and, if it possibly, return result.
 *
 * @param sql sql query, contains one or more instructions.
 * @return query status true|false.
 */
bool SQLiteDatabase::Execute(const char* sql) {

	if (sqlite3_exec(this->db, sql, 0, 0, &(this->err)) != SQLITE_OK) {
		this->Error("SQL", err);
		sqlite3_free(this->err);
		return false;
	}

	return true;
}

/**
 * Insert values in database.
 *
 * @param table that contains current columns.
 * @param columns for values.
 * @param values data, that'll be added to database.
 * @return insert status true|false.
 */
bool SQLiteDatabase::Insert(const char* table, const char* columns, const char* values) {

	string sql =	(string)"INSERT INTO "
					+ table
					+ '(' + columns + ')'
					+ " VALUES"
					+ '(' + values + ')';

	return this->Execute(sql.c_str());
}

/**
 * Select all values from table.
 *
 * @param table type of table.
 */
void SQLiteDatabase::Select(const char* table) {

	string sql =	(string)"SELECT * "
					+ " FROM "
					+ table;

	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, nullptr);

	char short_command = this->GetShortCommand(table);

	switch (short_command) {
		case 'd': {
			this->SelectDomains(stmt);
			list<Domains>::iterator it;
			break;
		}
		case 'u': {
			this->SelectUsers(stmt);
			break;
		}
		default: {
			this->Error("SQL", "Table not found");
		}
	}
}

void SQLiteDatabase::SelectDomains(sqlite3_stmt *stmt) {

	int stat = sqlite3_step(stmt);
	stringstream buffer;

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

void SQLiteDatabase::SelectUsers(sqlite3_stmt *stmt) {

	int stat = sqlite3_step(stmt);
	stringstream buffer;

	if (stat == SQLITE_ROW) {

		for (; sqlite3_column_text(stmt, 0); sqlite3_step(stmt)) {

			Users user;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 0);
			buffer >> user.id;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 1);
			buffer >> user.name;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 2);
			buffer >> user.surname;

			buffer.clear();
			buffer << sqlite3_column_text(stmt, 3);
			buffer >> user.salary;

			this->users.push_back(user);
		}

		sqlite3_finalize(stmt);
	}
}