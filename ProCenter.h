#pragma once
#include <list>
#include "Client.h"
using namespace std;

class ProCenter {
private:

	list<Client*> _client_list;
	
public:
	ProCenter();
	void AddClient(Client &client);
	bool Accept(Credit credit,Client client);
};