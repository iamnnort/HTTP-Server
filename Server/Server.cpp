#include "Server.h"

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

			FileManager manager;

			cout << "Client complite connected." << endl;

			//cut data from socket
			recv(Connect, message, sizeof(message), NULL);
			//get requested file name
			manager.GetRequestedFile(message);
			//find requested file in public folder
			if (manager.MakeResponseBody(manager.GetFileDir()) == GOOD) {

				//make response
				manager.MakeResponse(GOOD, manager.GetResponseBody());
				//get response
				string response = manager.GetResponse();
				//send response to client
				send(Connect, response.c_str(),
					response.length(), 0);
			}
		}

		Sleep(100);

	}

	ZeroMemory(message, sizeof(message));

	closesocket(Listen);
	closesocket(Connect);
	WSACleanup();

	system("pause");
	return 0;
}

