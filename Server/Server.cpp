#include "Server.h"

#ifdef _MSC_VER
DWORD WINAPI CheckExit(LPVOID lpParam) {

	HANDLE hExit = CreateEvent(NULL, TRUE, FALSE, EXIT_EVENT);
	WaitForSingleObject(hExit, INFINITE);
	exit_status = true;

	return 0;
}
#endif

int main() {

	Support support;

#ifdef _MSC_VER

	DWORD dwCheckExit, dwCheckExitParam = 1;
	HANDLE hcheckExit;
	hcheckExit = CreateThread(NULL, 0, CheckExit,
		&dwCheckExitParam, 0, &dwCheckExit);
	if (!hcheckExit) {
		support.SystemError("CreateThread hcheckExit failed");
	}

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(si);
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(pi));

	/*if (!CreateProcess(NULL, "ComManager", NULL ,NULL, TRUE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		support.SystemError("CreateProcess failed");
	}*/

	WSAData wsa;
	WORD Version = MAKEWORD(2, 1);
	WSAStartup(Version, &wsa);

	if (WSAStartup(Version, &wsa) != 0) {
		support.SystemError("Winsock is not been initialized");
	}

	SOCKET Listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKET Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (Listen == SOCKET_ERROR || Connect == SOCKET_ERROR) {
		support.SystemError("Listen or Connect socket is not been created");
	}

	SOCKADDR_IN Server;

	Server.sin_family = AF_INET;
	Server.sin_port = htons(SERVER_PORT);
	Server.sin_addr.s_addr = INADDR_ANY;

	if (bind(Listen, (SOCKADDR*)&Server, sizeof(Server)) == SOCKET_ERROR) {
		support.SystemError("Listen socket is not been binded");
	}

	listen(Listen, SOMAXCONN);

#else

	struct sockaddr_in server;
	int Listen, Connect;

	Listen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (Listen == -1) {
		support.SystemError("Socket is not been initialized");
		exit(EXIT_FAILURE);
	}

	memset(&server, 0, sizeof(server));

	server.sin_family = PF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(Listen, (struct sockaddr*) &server, sizeof(server)) == -1) {
		support.SystemError("Socket is not been binded");
		close(Listen);
		exit(EXIT_FAILURE);
	}

	if (listen(Listen, 10) == -1) {
		support.SystemError("Socket is not been listened");
		close(Listen);
		exit(EXIT_FAILURE);
	}

#endif
	
	char message[BUF_SIZE];

	cout << SERVER_NAME << " is running..." << endl;
	cout << "Waiting clients..." << endl;

	while (true) {

#ifdef _MSC_VER
		if (Connect = accept(Listen, NULL, NULL)) {
#else
		Connect = accept(Listen, 0, 0);
		if (Connect >= 0) {
#endif		
#ifdef _MSC_VER
			ZeroMemory(message, sizeof(message));
#else
			memset(&message, 0, sizeof(message));
#endif	
			if (recv(Connect, message, sizeof(message), 0) != NULL) {

				FileManager manager;
				Client client;
				//cout << message << endl;
				//get client info
				client.MakeClientInfo(message);
				//find requested file in public folder
				manager.MakeResponseBody(&client);
				//make response
				manager.MakeResponse(GOOD, manager.GetResponseBody());
				//get response
				string response = manager.GetResponse();
				//send response to client
#ifdef _MSC_VER
				send(Connect, response.c_str(),
					response.length(), 0);
#else
				send(Connect, response.c_str(),
					response.length(), 0);
#endif
				client.PrintClientInfo();
				//complite log file
				string content = client.MakeLogContent();
				manager.MakeLog("access", content);
#ifdef __linux__
				shutdown(Connect, SHUT_RDWR);
				close(Connect);
#endif
			}
		}
	
		if (exit_status) {
			break;
		}
	}

#ifdef _MSC_VER

	ZeroMemory(message, sizeof(message));
	closesocket(Connect);
	closesocket(Listen);
	WSACleanup();
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(hcheckExit);

#else

	memset(&message, 0, sizeof(message));
	shutdown(Connect, SHUT_RDWR);
	close(Connect);
	shutdown(Listen, SHUT_RDWR);
	close(Listen);

#endif
	
	return 0;
}

