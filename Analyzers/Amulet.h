#ifndef AMULET_H
#define AMULET_H

#include <string>
#include <vector>
#include "Analyzer.h"

namespace event {
	class Event;
}
class Command;

namespace analyzer {
	class Amulet : public Analyzer {
	public:
		Amulet();

		void onEvent(event::Event *const event);
		void parseMessages(const std::string &messages, const Command &best_command);

	private:
		Saiph *saiph;

		void wearAmulet();
	};
}
#endif
