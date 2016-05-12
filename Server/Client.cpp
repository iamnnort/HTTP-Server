#include "Client.h"

string Client::GetListenName() {

	return this->listen_name;
}

string Client::GetFileDir() {

	string file_dir = RSLS + this->site_name + this->file_addr;
	return file_dir;
}

string Client::GetSiteName() {

	return this->site_name;
}

void Client::SetAccessStatus(int status) {

	this->access_status = status;
}

void Client::MakeClientName(string message) {

	size_t left_border = message.find(USER_AGENT) + strlen(USER_AGENT) + 1;
	size_t right_border = message.find(NL, left_border);
	this->listen_name = message.substr(
		left_border,
		right_border - left_border);
}

void Client::MakeRequestedPath(string message) {

	size_t left_border = message.find(GET) + strlen(GET) + 1;
	size_t right_border = message.find(SPACE, left_border);
	string file_path = message.substr(
		left_border,
		right_border - left_border);

	this->MakeRequestedSite(file_path);
	this->MakeRequestedFile(file_path);
}

void Client::MakeRequestedSite(string file_path) {

	// delete first right slash
	file_path = file_path.substr(1, file_path.length() - 1);
	// search second right slash position
	size_t right_border = file_path.find(RSLS);
	// cutting site name
	this->site_name = file_path.substr(0, right_border);
}

void Client::MakeRequestedFile(string file_path) {

	// delete first right slash
	file_path = file_path.substr(1, file_path.length() - 1);
	// search start of the file path name
	size_t left_border = file_path.find(RSLS);
	// cutting file address
	this->file_addr = file_path.substr(left_border);
	// request consist of alone site name
	if (this->file_addr == RSLS) {
		this->file_addr += INDEX_HTML;
	}
}

void Client::MakeClientAccessType(string message) {

	size_t left_border = message.find(GET);
	size_t http_border = message.find(HTTP);
	size_t right_border = message.find(NL, http_border);
	this->access_type = message.substr(
		left_border,
		right_border - left_border);
}

void Client::MakeClientInfo(string message) {

	this->MakeClientName(message);
	this->MakeRequestedPath(message);
	this->MakeClientAccessType(message);
}

void Client::PrintClientInfo() {

	cout << "# Client:" << endl
		<< "## Client name: "
		<< this->listen_name << endl
		<< "## Requested site: "
		<< this->site_name << endl
		<< "## Requested page: "
		<< this->file_addr << endl;
}

string Client::MakeLogContent() {

	stringstream ss;
#ifdef _MSC_VER
	struct tm newtime;
	__time64_t long_time;
	_time64(&long_time);
	_localtime64_s(&newtime, &long_time);

	ss << '['
		<< newtime.tm_mday
		<< RSLS
		<< newtime.tm_mon + 1
		<< RSLS
		<< newtime.tm_year + 1900
		<< SPACE
		<< newtime.tm_hour
		<< COLON
		<< newtime.tm_min
		<< COLON
		<< newtime.tm_sec
		<< ']'
		<< SPACE;
#else

#endif
	ss << QUOTE
		<< this->access_type
		<< QUOTE
		<< SPACE
		<< this->access_status
		<< SPACE
		<< DASH
		<< SPACE
		<< QUOTE
		<< this->site_name
		<< QUOTE
		<< SPACE
		<< QUOTE
		<< this->listen_name
		<< QUOTE;

	string content;

	getline(ss, content);

	return content;
}