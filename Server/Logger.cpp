#include "Logger.h"

Logger::Logger(string file_name = ""){

	if (file_name == "access") {
		this->log_file = ACCESS_LOG;
	}
	else if (file_name == "error") {
		this->log_file = ERROR_LOG;
	}
}

bool Logger::logWrite(string content) {

	ofstream ofs(this->log_file.c_str(), ofstream::app);
	if (!ofs) {
		perror("Write content to log");
		return false;
	}

	ofs << content << endl;

	ofs.close();

	return true;
}
