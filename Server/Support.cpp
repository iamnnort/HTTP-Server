#include "Support.h"

void Support::getStatus(int number) {

	cout << "## " << STATUS 
		<< " [" << number << "] - "
		<< HTTP_STATUS_CODE[number] << endl;
}

void Support::SystemError(string e_str) {

	cout << "Error: " << e_str;
}