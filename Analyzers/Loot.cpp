#include "Loot.h"

/* constructors */
Loot::Loot(Saiph *saiph) {
	this->saiph = saiph;
	vector<unsigned char> symbols;
	symbols.push_back(WEAPON);
	symbols.push_back(ARMOR);
	symbols.push_back(RING);
	symbols.push_back(AMULET);
	symbols.push_back(TOOL);
	symbols.push_back(FOOD);
	symbols.push_back(POTION);
	symbols.push_back(SCROLL);
	symbols.push_back(SPELLBOOK);
	symbols.push_back(WAND);
	symbols.push_back(GOLD);
	symbols.push_back(GEM);
	symbols.push_back(STATUE);
	/* skipping boulder as that's a special item */
	symbols.push_back(IRON_BALL);
	symbols.push_back(CHAINS);
	symbols.push_back(VENOM);
	saiph->registerSymbols(this, symbols);
}

/* methods */
int Loot::parseMessages(string *messages) {
	return 0;
	if (messages->find(LO_THINGS_HERE, 0) != string::npos) {
		/* multiple items here */
		action = LO_LOOT;
		return 100;
	} else if (messages->find(LO_YOU_SEE, 0) != string::npos) {
		/* single item here */
		action = LO_LOOT;
		return 100;
	} else if (messages->find(LO_PICK_UP, 0) != string::npos) {
		/* pick up menu */
		action = LO_SELECT_ALL;
		return 100;
	} else if (messages->find(LO_LITTLE_LIFTING, 0) != string::npos) {
		action = LO_NO_LOOT;
		return 100;
	} else if (messages->find(LO_EXTREME_LIFTING, 0) != string::npos) {
		action = LO_NO_LOOT;
		return 100;
	} else if (messages->find(LO_MUCH_LIFTING, 0) != string::npos) {
		action = LO_NO_LOOT;
		return 100;
	}
	return 0;
}

void Loot::analyze(int row, int col, unsigned char symbol) {
	return;
}

int Loot::finish() {
	return 0;
}

void Loot::command(string *command) {
	switch (action) {
		case LO_LOOT:
			command->push_back(',');
			break;

		case LO_SELECT_ALL:
			command->push_back(',');
			command->push_back(' ');
			break;

		case LO_NO_LOOT:
			command->push_back(NO);
			break;

		default:
			cerr << "Loot don't know what to do" << endl;
			exit(1);
			break;
	}
}