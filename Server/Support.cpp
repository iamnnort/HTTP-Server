#include "Support.h"

void Support::getStatus(int number) {

	cout << STATUS << " [" << number << "] - ";
	cout << HTTP_STATUS_CODE[number] << endl;
}
