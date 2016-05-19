#include "Interface.h"

string Interface::getSeparators(const int count, const char sep) {

	string sleshe="";

	for (int i = 0; i < count; i++) {
		sleshe += sep;
	}

	return sleshe;
}

string Interface::GetMenuItem(const int size, const char* value, const char sep='|') {

	string menu_item = "";
	stringstream ss;

	int space_offset=0;
	if (!((strlen(value) % 2 != 0) && (size % 2 != 0))) {
		space_offset = 1;
	}

	int space_size;
	space_size = (LINE_SIZE * size - BORDER * 2 - size - 1 + space_offset  - strlen(value)) / 2;

	ss << this->getSeparators(LINE_SIZE * size - size - 1 + space_offset, sep) << endl;
	ss << this->getSeparators(BORDER, sep);
	ss << this->getSeparators(space_size, ' ');
	if ((strlen(value) % 2 != 0)) {
		ss << " ";
	}
	ss << value;
	ss << this->getSeparators(space_size, ' ');
	ss << this->getSeparators(BORDER, sep) << endl;
	ss << this->getSeparators(LINE_SIZE * size - size - 1 + space_offset, sep) << endl;

	menu_item = ss.str();

	return menu_item;
}

string Interface::GetMenuItem(const vector<string> value, const char sep = '|') {

	string menu_item = "";
	stringstream ss;
	int space_size;

	ss << getSeparators(LINE_SIZE * value.size() - BORDER * (value.size() -1), sep) << endl;

	ss << this->getSeparators(BORDER, sep);
	for (int i = 0; i < value.size(); i++) {
		space_size = (LINE_SIZE - BORDER * 2 - value[i].length()) / 2;
		ss << this->getSeparators(space_size, ' ');
		if (value[i].length() % 2 != 0) {
			ss << " ";
		}
		ss << value[i];
		ss << this->getSeparators(space_size, ' ');
		ss << this->getSeparators(BORDER, sep);
	}
	ss << endl;

	ss << getSeparators(LINE_SIZE * value.size() - BORDER * (value.size() - 1), sep) << endl;

	menu_item = ss.str();

	return menu_item;
}

void Interface::GetMainMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Main menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Users");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Domains");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Pages");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Shut down");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			this->GetUsersMenu();
			break;
		}
		case 2: {
			this->GetDomainsMenu();
			break;
		}
		case 3: {
			this->GetPrivatePagesMenu();
			break;
		}
		case 4: {
			break;
		}
		default: {
			this->GetMainMenu();
		}
	}
}

void Interface::GetUsersMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Users menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Add user");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Remove user");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Show users");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Back");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			Clients cli;
			cli.SelectUsers();
			PrintUsers(cli.GetUsers());
			system("pause");
			this->GetUsersMenu();
			break;
		}
		case 4: {
			this->GetMainMenu();
			break;
		}
		default: {
			this->GetUsersMenu();
		}
	}
}

void Interface::GetDomainsMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Domains menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Add user");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Remove domain");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Show domain");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Back");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			this->GetMainMenu();
			break;
		}
		default: {
			this->GetDomainsMenu();
		}
	}
}

void Interface::GetPrivatePagesMenu() {

	system("cls");
	vector<string> item;

	cout << this->GetMenuItem(2, "Private pages menu") << endl;

	item.clear();
	item.push_back("1");
	item.push_back("Add user");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("2");
	item.push_back("Remove private page");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("3");
	item.push_back("Show private page");
	cout << this->GetMenuItem(item) << endl;

	item.clear();
	item.push_back("4");
	item.push_back("Back");
	cout << this->GetMenuItem(item) << endl;

	switch (GetSelectedItem()) {
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			this->GetMainMenu();
			break;
		}
		default: {
			this->GetPrivatePagesMenu();
		}
	}
}

int Interface::GetSelectedItem() {

	int n;

	cout << "Number: ";
	cin >> n;

	return n;
}

void Interface::PrintUsers(list<Users> users) {

	system("cls");

	vector<string> columns;
	columns.push_back("id");
	columns.push_back("login");
	columns.push_back("password");

	cout << this->GetMenuItem(3, "Users") << endl;
	cout << this->GetMenuItem(columns) << endl;

	list<Users>::iterator it;

	for (it = users.begin(); it != users.end(); it++) {

		columns.clear();
		stringstream ss;
		ss << it->id;
		string id;
		ss >> id;
		columns.push_back(id);
		columns.push_back(it->login);
		columns.push_back(it->password);

		cout << this->GetMenuItem(columns) << endl;
	}

}


