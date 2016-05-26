#include "FileManager.h"

string FileManager::GetResponseBody() {

	return this->server_response_body;
}

int FileManager::MakeResponseBody(Client *client) {

	this->server_response_body.clear();
	string domain = client->GetSiteName();
	string filename = client->GetFileAddr();
	string filedir = client->GetFileDir();

	stringstream ss;
	ss << "domain = ";
	ss << "'";
	ss << domain;
	ss << "' LIMIT 1";
	string sql = ss.str();

	dbDomains dom;
	dom.SelectDomains(sql);
	list<Domains> domains = dom.GetDomains();
	list<Domains>::iterator it;

	bool private_page = false;
	bool check_user = false;
	
	if (domains.size() == 1) {
		it = domains.begin();
		if (it->id) {
			stringstream ss;
			ss << "domain_id = ";
			ss << it->id;
			string sql = ss.str();

			dbPages pg;
			pg.SelectPages(sql);
			list<PrivatePage> pages = pg.GetPages();
			list<PrivatePage>::iterator it;

			if (pages.size()) {
				for (it = pages.begin(); it != pages.end(); it++) {
					int index = filename.find(it->page);
					cout << it->page << endl;
					if(index >= 0 && index <= filename.length()) {
						dbUsers users;
						bool user_right = users.CheckUserRights(
							client->GetUserLogin(),
							client->GetUserPassword(),
							it->rang_id,
							it->id);
						if (!user_right) {
							private_page = true;
						}
					}
					
				}
			}
		}
	}

	Support support;

	if (private_page) {
		client->SetAccessStatus(401);
		filedir = AUTH_FILE;
	}
	else {
		filedir = ROOT_DIR + filedir;
		client->SetAccessStatus(200);
	}

	ifstream ifs(filedir.c_str(), ifstream::in);
	if (!ifs) {
		client->SetAccessStatus(404);
		return client->GetAccessStatus();
	}

	string sub_str;

	while (getline(ifs, sub_str)) {
		this->server_response_body += sub_str + NL;
	}

	ifs.close();

	return client->GetAccessStatus();
}


