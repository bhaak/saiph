#include "Remove.h"
#include "../Inventory.h"
#include "../World.h"

using namespace action;
using namespace std;

const int Remove::id = Action::createID();

Remove::Remove(unsigned char key, int priority) : remove(REMOVE, priority), remove_key(string(1, key), PRIORITY_CONTINUE_ACTION) {
}

const Command &Remove::getCommand() {
	switch (sequence) {
	case 0:
		return remove;
		
	case 1:
		/* also mark the inventory dirty when we do this */
		Inventory::updated = false;
		return remove_key;

	default:
		return Action::noop;
	}
}

void Remove::updateAction(const string &messages) {
	if (World::question && messages.find(MESSAGE_WHAT_TO_REMOVE) != string::npos)
		sequence = 1;
	else if (sequence == 1)
		sequence = 2;
}