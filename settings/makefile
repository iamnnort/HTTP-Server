CPP = g++

CFLAGS = -c -Wall -pedantic -std=gnu++0x

CFLAGS1 = -c -fno-access-control  -fcheck-new -ffriend-injection -fno-elide-constructors -fno-enforce-eh-specs -ffor-scope  -fno-for-scope  -fno-gnu-keywords -fno-implicit-templates -fno-implicit-inline-templates -fno-implement-inlines  -fms-extensions -fno-nonansi-builtins  -fnothrow-opt  -fno-operator-names -fno-optional-diags  -fpermissive -fno-pretty-templates -fno-rtti -fno-threadsafe-statics  -fuse-cxa-atexit -fvisibility-inlines-hidden -fvisibility-ms-compat -fext-numeric-literals -Wabi-tag  -Wconversion-null  -Wctor-dtor-privacy -Wdelete-non-virtual-dtor -Wliteral-suffix -Wnarrowing -Wnoexcept -Wnon-virtual-dtor  -Wreorder -Weffc++  -Wstrict-null-sentinel -Wno-non-template-friend  -Wold-style-cast -Woverloaded-virtual  -Wno-pmf-conversions -Wsign-promo

ELFLAGS = -lpthread -ldl

cRWFS = Server.o Client.o ServerLibrary.o Support.o

all: SQLiteDatabase.o Logger.o FileManager.o Manager.o Server.o Client.o ServerLibrary.o Support.o sqlite3.o dbDomains.o dbPages.o dbRangs.o dbUsers.o TablesLib.o
	g++ SQLiteDatabase.o Logger.o FileManager.o Manager.o Server.o Client.o ServerLibrary.o Support.o sqlite3.o dbDomains.o dbPages.o dbRangs.o dbUsers.o TablesLib.o -o SServer $(ELFLAGS)

server: 
	gcc SQLiteDatabase.o Logger.o FileManager.o Manager.o Server.o Client.o ServerLibrary.o Support.o sqlite3.o dbDomains.o dbPages.o dbRangs.o dbUsers.o TablesLib.o -o SServer $(ELFLAGS)

Server.o: ../Server/Server.cpp
	$(CPP) $(CFLAGS) ../Server/Server.cpp ../Server/Server.h

Client.o: ../Server/Client.cpp
	$(CPP) $(CFLAGS) ../Server/Client.cpp ../Server/Client.h

dbDomains.o: ../Server/dbDomains.cpp
	$(CPP) $(CFLAGS) ../Server/dbDomains.cpp ../Server/dbDomains.h

dbPages.o: ../Server/dbPages.cpp
	$(CPP) $(CFLAGS) ../Server/dbPages.cpp ../Server/dbPages.h

dbRangs.o: ../Server/dbRangs.cpp
	$(CPP) $(CFLAGS) ../Server/dbRangs.cpp ../Server/dbRangs.h

dbUsers.o: ../Server/dbUsers.cpp
	$(CPP) $(CFLAGS) ../Server/dbUsers.cpp ../Server/dbUsers.h

FileManager.o: ../Server/FileManager.cpp
	$(CPP) $(CFLAGS) ../Server/FileManager.cpp ../Server/FileManager.h

Manager.o: ../Server/Manager.cpp
	$(CPP) $(CFLAGS) ../Server/Manager.cpp ../Server/Manager.h

Logger.o: ../Server/Logger.cpp
	$(CPP) $(CFLAGS) ../Server/Logger.cpp ../Server/Logger.h

ServerLibrary.o: ../Server/ServerLibrary.cpp
	$(CPP) $(CFLAGS) ../Server/ServerLibrary.cpp ../Server/ServerLibrary.h

sqlite3.o: ../Server/lib/sqlite3.c
	gcc $(CFLAGS) ../Server/lib/sqlite3.c

SQLiteDatabase.o: ../Server/SQLiteDatabase.cpp
	$(CPP) $(CFLAGS) ../Server/SQLiteDatabase.cpp ../Server/SQLiteDatabase.h

Support.o: ../Server/Support.cpp
	$(CPP) $(CFLAGS) ../Server/Support.cpp ../Server/Support.h

TablesLib.o: ../Server/TablesLib.cpp
	$(CPP) $(CFLAGS) ../Server/TablesLib.cpp ../Server/TablesLib.h

clear:
	rm -rf *.o 