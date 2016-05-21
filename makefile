all:
	g++ Server/Server.h Server/Server.cpp Server/Client.h Server/Client.cpp Server/Logger.h Server/Logger.cpp Server/ServerLibrary.h Server/ServerLibrary.cpp Server/Manager.cpp Server/Manager.h Server/FileManager.cpp Server/FileManager.h Server/Support.cpp Server/Support.h -o debug/Server.exe

s:
	./Debug/Server.exe