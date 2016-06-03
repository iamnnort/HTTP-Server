#pragma once

#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <time.h>

#define SERVER_NAME "NPWEB"
#define SERVER_PORT 1337
#define BUF_SIZE 1024

#define NL "\r\n"
#define SPACE " "
#define RSLS "/"
#define QUOTE '"'
#define DASH "-"
#define COLON ":"

#define ROOT_DIR "../public"
#define INDEX_HTML "index.html"
#define AUTH_FILE "../private/auth.html"
#define NOT_FOUND_FILE "../private/404.html"
#define COM_MANAGER_PATH "./ComManager"
#define LOGIN "login"
#define PASSWORD "password"
#define REFERER "Referer"
#define QUSTION_MARK "?"
#define GET "GET"
#define HTTP "HTTP/"
#define HTTP_VER "1.1"
#define CONTENT_TYPE "text/html"
#define CHARSET "utf-8"
#define USER_AGENT "User-Agent:"
#define ACCEPT "Accept:"

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

