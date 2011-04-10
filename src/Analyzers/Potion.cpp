#include "Analyzers/Potion.h"

#include "Debug.h"
#include "Request.h"
#include "Saiph.h"
#include "World.h"

using namespace analyzer;
using namespace std;

/* constructors/destructor */
Potion::Potion(Saiph* saiph) : Analyzer("Potion"), saiph(saiph), command2("") {
	appearance.push_back("black");
	appearance.push_back("brilliant blue");
	appearance.push_back("brown");
	appearance.push_back("bubbly");
	appearance.push_back("clear");
	appearance.push_back("cloudy");
	appearance.push_back("cyan");
	appearance.push_back("effervescent");
	appearance.push_back("emerald");
	appearance.push_back("dark");
	appearance.push_back("dark green");
	appearance.push_back("fizzy");
	appearance.push_back("golden");
	appearance.push_back("magenta");
	appearance.push_back("milky");
	appearance.push_back("murky");
	appearance.push_back("orange");
	appearance.push_back("pink");
	appearance.push_back("puce");
	appearance.push_back("purple-red");
	appearance.push_back("ruby");
	appearance.push_back("sky blue");
	appearance.push_back("smoky");
	appearance.push_back("swirly");
	appearance.push_back("white");
	appearance.push_back("yellow");
	appearance.push_back("muddy");
	appearance.push_back("sparkling");
	appearance.push_back("luminescent");
	appearance.push_back("icy");
	appearance.push_back("squishy");
	appearance.push_back("greasy");
	appearance.push_back("slimy");
	appearance.push_back("soapy");
	appearance.push_back("ochre");
	appearance.push_back("steamy");
	appearance.push_back("gooey");
	appearance.push_back("silver");
}

/* methods */
void Potion::analyze() {
	if (saiph->world->player.experience > 10 && priority < PRIORITY_POTION_QUAFF_GAIN_LEVEL) {
		/* see if we got a potion of gain level and quaff it */
		for (map<unsigned char, Item>::iterator i = saiph->inventory.begin(); i != saiph->inventory.end(); ++i) {
			if (i->second.name != "potion of gain level")
				continue;
			/* cool, we do */
			command = QUAFF;
			priority = PRIORITY_POTION_QUAFF_GAIN_LEVEL;
			command2 = i->first;
		}
	}
}

void Potion::parseMessages(const string& messages) {
	if (command2 != "" && messages.find(MESSAGE_WHAT_TO_DRINK, 0) != string::npos) {
		/* quaff the potion */
		command = command2;
		priority = PRIORITY_CONTINUE_ACTION;
		command2.clear();
		/* mark inventory as dirty */
		req.request = REQUEST_DIRTY_INVENTORY;
		saiph->request(req);
	} else if (saiph->world->question && messages.find(MESSAGE_DRINK_FROM_FOUNTAIN, 0) != string::npos) {
		/* drink from fountain? no, let's not */
		command = NO;
		priority = PRIORITY_CONTINUE_ACTION;
	} else if (saiph->world->question) {
		string::size_type stop = messages.rfind(POTION_CALL_END);
		Debug::info(saiph->last_turn) << POTION_DEBUG_NAME << "Potion checking for question about naming potion" << endl;
		if (stop == string::npos)
			return;
		Debug::info(saiph->last_turn) << POTION_DEBUG_NAME << "Found ' potion:  '" << endl;
		string::size_type start = messages.rfind(POTION_CALL_POTION1, stop);
		if (start == string::npos) {
			start = messages.rfind(POTION_CALL_POTION2, stop);
			if (start != string::npos)
				start += sizeof (POTION_CALL_POTION2) - 1;
		} else {
			start += sizeof (POTION_CALL_POTION1) - 1;
		}
		if (start == string::npos)
			return;
		string name = messages.substr(start, stop - start);
		Debug::notice(saiph->last_turn) << POTION_DEBUG_NAME << "Asking for name for a " << name << " potion" << endl;
		for (vector<string>::iterator a = appearance.begin(); a != appearance.end(); ++a) {
			if (name != *a)
				continue;
			/* recognized the potion */
			command = "hello :)\n";
			priority = PRIORITY_CONTINUE_ACTION;
		}
	}
}

bool Potion::request(const Request& request) {
	if (request.request == REQUEST_QUAFF_HEALING) {
		for (map<unsigned char, Item>::iterator i = saiph->inventory.begin(); i != saiph->inventory.end(); ++i) {
			if (i->second.name != "potion of healing" && i->second.name != "potion of extra healing" && i->second.name != "potion of full healing")
				continue;
			/* just pick the first healing potion for now */
			command = QUAFF;
			priority = request.priority;
			command2 = i->first;
			return true;
		}
	}
	return false;
}
