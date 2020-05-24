#include "ProCenter.h"
ProCenter::ProCenter() {

}
void ProCenter::AddClient(Client &client) {

	_client_list.push_back(&client);
}

bool ProCenter::Accept(Credit credit, Client client) {
	if (credit.PayMent() * 6 <= client.GetCount()) {
		return true;
	}
	else
		return false;
}

Client* ProCenter::SearchClient(string count) {
	Client* client = 0;

	for (int i = 0; i < _client_list.size(); i++) {

		client = _client_list[i];

		string curr_count = client->Count();

		if (curr_count == count) {
			return client;
		}
	}

	return client;
}