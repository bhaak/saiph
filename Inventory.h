#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <set>
#include <string>
#include "Globals.h"
#include "Item.h"
#include "Events/ChangedInventoryItems.h"

class Inventory {
public:
	static std::map<unsigned char, Item>& items();
	static const bool& updated();
	static const bool& updated(const bool& updated);
	static void analyze();
	static void parseMessages(const std::string& messages);
	static const unsigned char& itemInSlot(const int& slot);
	static void addItem(const unsigned char& key, const Item& item);
	static void removeItem(const unsigned char& key, const Item& item);

private:
	static bool _updated;
	static std::map<unsigned char, Item> _items;
	static unsigned char _slots[SLOTS];
	static event::ChangedInventoryItems _changed;
	static std::set<unsigned char> _lost;

	static void setSlot(const unsigned char& key, const Item& item);
};
#endif
