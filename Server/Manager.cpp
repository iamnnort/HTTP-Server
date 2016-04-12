#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
}

string Manager::GetFileDir() {

	return this->filedir;
}

string Manager::GetResponse() {

	return this->server_response;
}

void Manager::GetRequestedFile(string message) {

	size_t left_border = message.find(GET) + strlen(GET) + 1;
	size_t right_border = message.find(HTTP) - 1;
	this->filedir = message.substr(
		left_border,
		right_border - left_border);
}

void Manager::MakeResponse(int status, string response_body) {

	stringstream response;

	response << "HTTP/" << HTTP_VER << SPACE << status << SPACE 
		<< HTTP_STATUS_CODE[status] << NL
		<< "Version: HTTP/" << HTTP_VER << NL
		<< "Content-Type: " << CONTENT_TYPE 
		<< "; charset=" << CHARSET << NL
		<< "Content-Length: " << response_body.length() << NL
		<< NL
		<< response_body;

	this->server_response = response.str();
}

