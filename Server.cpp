// Server
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <cstring>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>

using namespace std;

int main() {

	cout << "Server:" << endl;

	char message[MAX_PATH];

	WSAData wsa;
	WORD Version = MAKEWORD(2, 1);

	WSAStartup(Version, &wsa);

	if (WSAStartup(Version, &wsa) != 0) {
		cout << "WSA library startup error." << endl;
	}
	else {
		cout << "WSA library startup complite" << endl;
	}

	SOCKET Listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKET Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (Listen == SOCKET_ERROR || Connect == SOCKET_ERROR) {
		cout << "Socket error. Can not create socket." << endl;
	}
	else {
		cout << "Socket create comlite." << endl;
	}

	SOCKADDR_IN Server;

	Server.sin_family = AF_INET;
	Server.sin_port = htons(1337);
	Server.sin_addr.s_addr = INADDR_ANY;

	if (bind(Listen, (SOCKADDR*)&Server, sizeof(Server)) == SOCKET_ERROR) {
		cout << "Can not bind socket." << endl;
	}
	else {
		cout << "Socket bind complite." << endl;
	}

	listen(Listen, SOMAXCONN);

	while (true) {

		if (Connect = accept(Listen, NULL, NULL)) {
			cout << "Client complite connected." << endl;
			recv(Connect, message, sizeof(message), 0);
			send(Connect, "Message from server: You complite connect to server", MAX_PATH, 0);
			break;
		}

		Sleep(100);

	}

	cout << message << endl;

	ZeroMemory(message, sizeof(message));

	closesocket(Listen);
	closesocket(Connect);
	WSACleanup();

	system("pause");
	return 0;
}