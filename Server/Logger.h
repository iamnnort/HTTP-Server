#pragma once
#include "ServerLibrary.h"

#define ACCESS_LOG "../settings/logs/access.log"
#define ERROR_LOG "../settings/logs/error.log"

class Logger : public ServerLibrary
{
	string log_file;
public:
	Logger(string);
	~Logger() {};
	bool logWrite(string);
};

