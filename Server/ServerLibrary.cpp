#include "ServerLibrary.h"

ServerLibrary::ServerLibrary() {

	HTTP_STATUS_CODE.insert(pair<int, string>(100, "Continue"));
	HTTP_STATUS_CODE.insert(pair<int, string>(101, "Switching Protocols"));
	HTTP_STATUS_CODE.insert(pair<int, string>(200, "OK"));
	HTTP_STATUS_CODE.insert(pair<int, string>(201, "Created"));
	HTTP_STATUS_CODE.insert(pair<int, string>(202, "Accepted"));
	HTTP_STATUS_CODE.insert(pair<int, string>(203, "Non-Authoritative Information"));
	HTTP_STATUS_CODE.insert(pair<int, string>(204, "No Content"));
	HTTP_STATUS_CODE.insert(pair<int, string>(205, "Reset Content"));
	HTTP_STATUS_CODE.insert(pair<int, string>(206, "Partial Content"));
	HTTP_STATUS_CODE.insert(pair<int, string>(300, "Multiple Choices"));
	HTTP_STATUS_CODE.insert(pair<int, string>(301, "Moved Permanently"));
	HTTP_STATUS_CODE.insert(pair<int, string>(302, "Found"));
	HTTP_STATUS_CODE.insert(pair<int, string>(303, "See Other"));
	HTTP_STATUS_CODE.insert(pair<int, string>(304, "Not Modified"));
	HTTP_STATUS_CODE.insert(pair<int, string>(305, "Use Proxy"));
	HTTP_STATUS_CODE.insert(pair<int, string>(307, "Temporary Redirect"));
	HTTP_STATUS_CODE.insert(pair<int, string>(400, "Bad Request"));
	HTTP_STATUS_CODE.insert(pair<int, string>(401, "Unauthorized"));
	HTTP_STATUS_CODE.insert(pair<int, string>(402, "Payment Required"));
	HTTP_STATUS_CODE.insert(pair<int, string>(403, "Forbidden"));
	HTTP_STATUS_CODE.insert(pair<int, string>(404, "Not Found"));
	HTTP_STATUS_CODE.insert(pair<int, string>(405, "Method Not Allowed"));
	HTTP_STATUS_CODE.insert(pair<int, string>(406, "Not Acceptable"));
	HTTP_STATUS_CODE.insert(pair<int, string>(407, "Proxy Authentication Required"));
	HTTP_STATUS_CODE.insert(pair<int, string>(408, "Request Time-out"));
	HTTP_STATUS_CODE.insert(pair<int, string>(409, "Conflict"));
	HTTP_STATUS_CODE.insert(pair<int, string>(410, "Gone"));
	HTTP_STATUS_CODE.insert(pair<int, string>(411, "Length Required"));
	HTTP_STATUS_CODE.insert(pair<int, string>(412, "Precondition Failed"));
	HTTP_STATUS_CODE.insert(pair<int, string>(413, "Request Entity Too Large"));
	HTTP_STATUS_CODE.insert(pair<int, string>(414, "Request-URI Too Large"));
	HTTP_STATUS_CODE.insert(pair<int, string>(415, "Unsupported Media Type"));
	HTTP_STATUS_CODE.insert(pair<int, string>(416, "Requested range not satisfiable"));
	HTTP_STATUS_CODE.insert(pair<int, string>(417, "Expectation Failed"));
	HTTP_STATUS_CODE.insert(pair<int, string>(500, "Internal Server Error"));
	HTTP_STATUS_CODE.insert(pair<int, string>(501, "Not Implemented"));
	HTTP_STATUS_CODE.insert(pair<int, string>(502, "Bad Gateway"));
	HTTP_STATUS_CODE.insert(pair<int, string>(503, "Service Unavailable"));
	HTTP_STATUS_CODE.insert(pair<int, string>(504, "Gateway Time-out"));
	HTTP_STATUS_CODE.insert(pair<int, string>(505, "HTTP Version not supported"));
}
