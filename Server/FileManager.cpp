#include "FileManager.h"

string FileManager::GetResponseBody() {

	return this->server_response_body;
}

int FileManager::MakeResponseBody(string filename) {

	Support support;

	filename = ROOT_DIR + filename;
	ifstream ifs(filename.c_str(), ifstream::in);
	if (!ifs) {
		support.getStatus(404);
		return 404;
	}

	string sub_str;

	while (getline(ifs, sub_str)) {
		server_response_body += sub_str + NL;
	}

	ifs.close();

	support.getStatus(200);
	return 200;
}


