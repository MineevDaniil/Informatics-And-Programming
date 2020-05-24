#pragma once
#include <vector>
#include "Client.h"
using namespace std;

class ProCenter {
private:

	vector<Client*> _client_list;
	
public:
	ProCenter();
	void AddClient(Client &client);
	bool Accept(Credit credit,Client client);
	Client* SearchClient(string count);
};