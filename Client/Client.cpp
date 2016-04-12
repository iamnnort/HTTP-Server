// Client
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <cstring>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>

using namespace std;

int main() {

	cout << "Client: " << endl;

	char message[MAX_PATH];

	char ip[15];
	u_short port;

	cout << "IP: ";
	cin >> ip;	
		
	cout << "Port: ";
	cin >> port;
	cout << endl;

	WSAData wsa;
	WORD Version = MAKEWORD(2, 1);

	WSAStartup(Version, &wsa);

	if (WSAStartup(Version, &wsa) != 0) {
		cout << "WSA library startup error." << endl;
	}
	else {
		cout << "WSA library startup complite" << endl;
	}

	SOCKET Connect = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (Connect == SOCKET_ERROR) {
		cout << "Socket error. Can not create socket." << endl;
	}
	else {
		cout << "Socket create comlite." << endl;
	}

	SOCKADDR_IN Client;

	Client.sin_family = AF_INET;
	Client.sin_port = htons(port);
	Client.sin_addr.s_addr = inet_addr(ip);

	while (true) {

		if (connect(Connect, (SOCKADDR*)&Client, sizeof(Client))) {
			cout << "Complite connect to server." << endl;
			send(Connect, "Message from client: You complite connect to Client.", MAX_PATH, 0);
			recv(Connect, message, sizeof(message), 0);
			break;
		}

		Sleep(100);

	}

	cout << message << endl;

	ZeroMemory(message, sizeof(message));

	closesocket(Connect);
	WSACleanup();

	system("pause");
	return 0;
}