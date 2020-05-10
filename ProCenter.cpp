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