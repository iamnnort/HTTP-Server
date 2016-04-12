#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#define NL "\r\n"
#define SPACE " "

#define ROOT_DIR "../public"
#define GET "GET"
#define HTTP "HTTP/"
#define HTTP_VER "1.1"
#define CONTENT_TYPE "text/html"
#define CHARSET "utf-8"

#define GOOD 200
#define NOT_FOUND 404

using namespace std;

class ServerLibrary
{
protected: 
	map<int, string> HTTP_STATUS_CODE;
public:
	ServerLibrary();
	~ServerLibrary() {};
};

