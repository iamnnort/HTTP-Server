#include "ComManager.h"

int main(int argc, char *argv[]) {

#ifdef _MSC_VER
	HANDLE hExit = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, TRUE, EXIT_EVENT);
#endif

	Interface interf;
	interf.GetMainMenu();
#ifdef _MSC_VER
	WaitForSingleObject(hExit, INFINITE);
#endif

	return 0;
}