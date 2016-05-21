#include "Manager.h"

string Manager::GetResponse() {

	return this->server_response;
}

void Manager::MakeResponse(int status, string response_body) {

	stringstream response;
	response << "HTTP/" << HTTP_VER << SPACE << status << SPACE 
		<< HTTP_STATUS_CODE[status] << NL
		<< "Server: " << SERVER_NAME << NL
		<< "Version: HTTP/" << HTTP_VER << NL
		<< "Content-Type: " << CONTENT_TYPE 
		<< "; charset=" << CHARSET << NL
		<< "Content-Length: " << response_body.length() << NL
		<< NL
		<< response_body;

	this->server_response = response.str();
}

bool Manager::MakeLog(string type, string content) {

	Logger logger(type);
	logger.logWrite(content);

	return true;
}

