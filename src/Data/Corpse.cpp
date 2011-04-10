#include "Data/Corpse.h"

using namespace data;
using namespace std;

/* initialize static variables */
map<const string, const Corpse*> Corpse::_corpses;

/* protected constructors */
Corpse::Corpse(const string& name, int cost, int weight, int material, unsigned long long properties, int nutrition, int time, int effects, int confer_probability) : Food(name, cost, weight, material, properties, nutrition, time, effects), _confer_probability(confer_probability) {
}

/* destructor */
Corpse::~Corpse() {
}

/* public static methods */
void Corpse::init() {
	Monster::init();
	create("abbot", 400, EAT_EFFECT_HUMAN | EAT_EFFECT_HALLUCINOGENIC, 0);
	create("acid blob", 10, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_ACIDIC, 0);
	create("acolyte", 400, EAT_EFFECT_HUMAN, 0);
	create("aligned priest", 400, EAT_EFFECT_HUMAN, 0);
	create("ape", 500, 0, 0);
	create("apprentice", 400, EAT_EFFECT_HUMAN, 0);
	create("Arch Priest", 400, EAT_EFFECT_HUMAN, 0);
	create("archeologist", 400, EAT_EFFECT_HUMAN, 0);
	create("attendant", 400, EAT_EFFECT_HUMAN, 0);
	create("baby black dragon", 500, 0, 0);
	create("baby blue dragon", 500, 0, 0);
	create("baby crocodile", 200, 0, 0);
	create("baby gray dragon", 500, 0, 0);
	create("baby green dragon", 500, EAT_EFFECT_POISONOUS, 0);
	create("baby long worm", 250, 0, 0);
	create("baby orange dragon", 500, 0, 0);
	create("baby purple worm", 250, 0, 0);
	create("baby red dragon", 500, 0, 0);
	create("baby silver dragon", 500, 0, 0);
	create("baby white dragon", 500, 0, 0);
	create("baby yellow dragon", 500, EAT_EFFECT_ACIDIC, 0);
	create("baluchitherium", 800, 0, 0);
	create("barbarian", 400, EAT_EFFECT_HUMAN, 0);
	create("bat", 20, EAT_EFFECT_STUN, 0);
	create("black dragon", 1500, 0, 100);
	create("black naga", 400, EAT_EFFECT_ACIDIC, 53);
	create("black naga hatchling", 100, EAT_EFFECT_ACIDIC, 20);
	create("black pudding", 250, EAT_EFFECT_ACIDIC, 22);
	create("black unicorn", 300, 0, 27);
	create("blue dragon", 1500, 0, 100);
	create("blue jelly", 20, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN, 13);
	create("brown mold", 30, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN, 3);
	create("brown pudding", 250, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_ACIDIC, 11);
	create("bugbear", 250, 0, 0);
	create("captain", 400, EAT_EFFECT_HUMAN, 0);
	create("carnivorous ape", 550, 0, 0);
	create("cave spider", 50, 0, 7);
	create("caveman", 400, EAT_EFFECT_HUMAN, 0);
	create("cavewoman", 400, EAT_EFFECT_HUMAN, 0);
	create("centipede", 50, 0, 13);
	create("chameleon", 100, EAT_EFFECT_POLYMORPH, 0);
	create("chickatrice", 10, EAT_EFFECT_PETRIFY, 27);
	create("chieftain", 400, EAT_EFFECT_HUMAN, 0);
	create("Chromatic Dragon", 1700, EAT_EFFECT_POISONOUS, 17);
	create("cobra", 100, EAT_EFFECT_POISONOUS, 40);
	create("cockatrice", 30, EAT_EFFECT_PETRIFY, 33);
	create("coyote", 250, 0, 0);
	create("crocodile", 400, 0, 0);
	create("Croesus", 400, EAT_EFFECT_HUMAN, 0);
	create("Cyclops", 700, EAT_EFFECT_STRENGTH, 0);
	create("Death", 1, EAT_EFFECT_DIE, 0);
	create("dingo", 200, 0, 0);
	create("disenchanter", 200, 0, 0);
	create("dog", 200, EAT_EFFECT_AGGRAVATE, 0);
	create("doppelganger", 400, EAT_EFFECT_HUMAN | EAT_EFFECT_POLYMORPH, 0);
	create("dwarf", 300, EAT_EFFECT_DWARF, 0);
	create("dwarf king", 300, EAT_EFFECT_DWARF, 0);
	create("dwarf lord", 300, EAT_EFFECT_DWARF, 0);
	create("electric eel", 250, 0, 47);
	create("elf", 350, EAT_EFFECT_ELF, 67);
	create("elf-lord", 350, EAT_EFFECT_ELF, 53);
	create("Elvenking", 350, EAT_EFFECT_ELF, 60);
	create("ettin", 500, 0, 0);
	create("Famine", 1, EAT_EFFECT_DIE, 0);
	create("fire ant", 10, 0, 20);
	create("fire giant", 750, EAT_EFFECT_STRENGTH, 30);
	create("flesh golem", 600, 0, 12);
	create("floating eye", 10, EAT_EFFECT_ESP, 100);
	create("forest centaur", 600, 0, 0);
	create("fox", 250, 0, 0);
	create("frost giant", 750, EAT_EFFECT_STRENGTH, 33);
	create("gargoyle", 200, 0, 0);
	create("garter snake", 60, 0, 0);
	create("gecko", 20, 0, 0);
	create("gelatinous cube", 150, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_ACIDIC, 10);
	create("giant", 750, EAT_EFFECT_STRENGTH, 0);
	create("giant ant", 10, 0, 0);
	create("giant bat", 30, EAT_EFFECT_STUN, 0);
	create("giant beetle", 10, EAT_EFFECT_POISONOUS, 33);
	create("giant eel", 250, 0, 0);
	create("giant mimic", 500, EAT_EFFECT_MIMIC, 0);
	create("giant rat", 30, 0, 0);
	create("giant spider", 100, EAT_EFFECT_POISONOUS, 33);
	create("glass piercer", 300, 0, 0);
	create("gnome", 100, EAT_EFFECT_GNOME, 0);
	create("gnome king", 150, EAT_EFFECT_GNOME, 0);
	create("gnome lord", 120, EAT_EFFECT_GNOME, 0);
	create("gnomish wizard", 120, EAT_EFFECT_GNOME, 0);
	create("goblin", 100, 0, 0);
	create("golden naga", 400, 0, 67);
	create("golden naga hatchling", 100, 0, 20);
	create("Grand Master", 400, EAT_EFFECT_HUMAN, 0);
	create("gray dragon", 1500, 0, 0);
	create("gray ooze", 250, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_ACIDIC, 7);
	create("gray unicorn", 300, 0, 27);
	create("green dragon", 1500, EAT_EFFECT_POISONOUS, 100);
	create("green mold", 30, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_ACIDIC, 0);
	create("green slime", 150, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_SLIME | EAT_EFFECT_POISONOUS | EAT_EFFECT_ACIDIC, 0);
	create("Green-elf", 350, EAT_EFFECT_ELF, 33);
	create("gremlin", 20, EAT_EFFECT_POISONOUS, 33);
	create("Grey-elf", 350, EAT_EFFECT_ELF, 40);
	create("guard", 400, EAT_EFFECT_HUMAN, 0);
	create("guardian naga", 400, EAT_EFFECT_POISONOUS, 80);
	create("guardian naga hatchling", 100, 0, 20);
	create("guide", 400, EAT_EFFECT_HUMAN, 0);
	create("healer", 400, EAT_EFFECT_HUMAN, 0);
	create("hell hound", 300, 0, 80);
	create("hell hound pup", 200, 0, 47);
	create("high priest", 400, EAT_EFFECT_HUMAN, 0);
	create("hill giant", 700, EAT_EFFECT_STRENGTH, 0);
	create("hill orc", 200, 0, 0);
	create("Hippocrates", 400, EAT_EFFECT_HUMAN, 0);
	create("hobbit", 200, 0, 0);
	create("hobgoblin", 200, 0, 0);
	create("homunculus", 100, EAT_EFFECT_POISONOUS, 7);
	create("horse", 300, 0, 0);
	create("housecat", 200, EAT_EFFECT_AGGRAVATE, 0);
	create("human", 400, EAT_EFFECT_HUMAN, 0);
	create("hunter", 400, EAT_EFFECT_HUMAN, 0);
	create("ice troll", 300, 0, 60);
	create("iguana", 30, 0, 0);
	create("imp", 10, 0, 0);
	create("iron piercer", 300, 0, 0);
	create("Ixoth", 1600, 0, 100);
	create("jabberwock", 600, 0, 0);
	create("jackal", 250, 0, 0);
	create("jaguar", 300, 0, 0);
	create("jellyfish", 20, EAT_EFFECT_POISONOUS, 20);
	create("Keystone Kop", 200, EAT_EFFECT_HUMAN, 0);
	create("killer bee", 5, EAT_EFFECT_POISONOUS, 30);
	create("King Arthur", 400, EAT_EFFECT_HUMAN, 0);
	create("kitten", 150, EAT_EFFECT_AGGRAVATE, 0);
	create("knight", 400, EAT_EFFECT_HUMAN, 0);
	create("kobold", 100, EAT_EFFECT_POISONOUS, 0);
	create("kobold lord", 200, EAT_EFFECT_POISONOUS, 0);
	create("kobold shaman", 150, EAT_EFFECT_POISONOUS, 0);
	create("Kop Kaptain", 200, EAT_EFFECT_HUMAN, 0);
	create("Kop Lieutenant", 200, EAT_EFFECT_HUMAN, 0);
	create("Kop Sergeant", 200, EAT_EFFECT_HUMAN, 0);
	create("kraken", 1000, 0, 0);
	create("large cat", 250, EAT_EFFECT_AGGRAVATE, 0);
	create("large dog", 250, EAT_EFFECT_AGGRAVATE, 0);
	create("large kobold", 150, EAT_EFFECT_POISONOUS, 0);
	create("large mimic", 400, EAT_EFFECT_MIMIC, 0);
	create("leocrotta", 500, 0, 0);
	create("leprechaun", 30, 0, 50);
	create("lichen", 200, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_NEVER_ROT, 0);
	create("lieutenant", 400, EAT_EFFECT_HUMAN, 0);
	create("little dog", 150, EAT_EFFECT_AGGRAVATE, 0);
	create("lizard", 40, EAT_EFFECT_CURE_STONING | EAT_EFFECT_REDUCE_STUNNING | EAT_EFFECT_REDUCE_CONFUSION | EAT_EFFECT_NEVER_ROT, 0);
	create("long worm", 500, 0, 0);
	create("Lord Carnarvon", 400, EAT_EFFECT_HUMAN, 0);
	create("Lord Sato", 400, EAT_EFFECT_HUMAN, 0);
	create("Lord Surtur", 850, EAT_EFFECT_STRENGTH, 50);
	create("lurker above", 350, 0, 0);
	create("lynx", 300, 0, 0);
	create("Master Assassin", 400, EAT_EFFECT_HUMAN, 0);
	create("Master Kaen", 400, EAT_EFFECT_HUMAN, 100);
	create("master mind flayer", 400, 0, 50);
	create("Master of Thieves", 400, EAT_EFFECT_HUMAN, 0);
	create("mastodon", 800, 0, 0);
	create("Medusa", 400, EAT_EFFECT_PETRIFY | EAT_EFFECT_POISONOUS, 100);
	create("mind flayer", 400, 0, 50);
	create("minotaur", 700, 0, 0);
	create("monk", 400, EAT_EFFECT_HUMAN, 0);
	create("monkey", 50, 0, 0);
	create("Mordor orc", 200, 0, 0);
	create("mountain centaur", 500, 0, 0);
	create("mountain nymph", 300, 0, 30);
	create("mumak", 500, 0, 0);
	create("neanderthal", 400, EAT_EFFECT_HUMAN, 0);
	create("Neferet the Green", 400, EAT_EFFECT_HUMAN, 0);
	create("newt", 20, 0, 67);
	create("ninja", 400, EAT_EFFECT_HUMAN, 0);
	create("Norn", 400, EAT_EFFECT_HUMAN, 0);
	create("nurse", 400, EAT_EFFECT_HUMAN | EAT_EFFECT_HEAL, 73);
	create("ochre jelly", 20, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_ACIDIC, 0);
	create("ogre", 500, 0, 0);
	create("ogre king", 750, 0, 0);
	create("ogre lord", 700, 0, 0);
	create("Olog-hai", 400, 0, 0);
	create("Oracle", 400, EAT_EFFECT_HUMAN, 0);
	create("orange dragon", 1500, 0, 100);
	create("orc", 150, 0, 0);
	create("orc shaman", 300, 0, 0);
	create("orc-captain", 350, 0, 0);
	create("Orion", 400, EAT_EFFECT_HUMAN, 0);
	create("owlbear", 700, 0, 0);
	create("page", 400, EAT_EFFECT_HUMAN, 0);
	create("panther", 300, 0, 0);
	create("Pelias", 400, EAT_EFFECT_HUMAN, 0);
	create("Pestilence", 1, EAT_EFFECT_DIE, 0);
	create("piranha", 30, 0, 0);
	create("pit viper", 60, EAT_EFFECT_POISONOUS, 40);
	create("plains centaur", 500, 0, 0);
	create("pony", 250, 0, 0);
	create("priest", 400, EAT_EFFECT_HUMAN, 0);
	create("priestess", 400, EAT_EFFECT_HUMAN, 0);
	create("prisoner", 400, EAT_EFFECT_HUMAN, 0);
	create("purple worm", 700, 0, 0);
	create("pyrolisk", 30, 0, 20);
	create("python", 100, 0, 0);
	create("quantum mechanic", 20, EAT_EFFECT_POISONOUS | EAT_EFFECT_SPEED_TOGGLE, 0);
	create("quasit", 200, 0, 20);
	create("queen bee", 5, EAT_EFFECT_POISONOUS, 60);
	create("quivering blob", 100, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN, 33);
	create("rabid rat", 5, EAT_EFFECT_POISONOUS, 0);
	create("ranger", 400, EAT_EFFECT_HUMAN, 0);
	create("raven", 20, 0, 0);
	create("red dragon", 1500, 0, 100);
	create("red mold", 30, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN, 3);
	create("red naga", 400, 0, 20);
	create("red naga hatchling", 100, 0, 10);
	create("rock mole", 30, 0, 0);
	create("rock piercer", 200, 0, 0);
	create("rock troll", 300, 0, 0);
	create("rogue", 400, EAT_EFFECT_HUMAN, 0);
	create("roshi", 400, EAT_EFFECT_HUMAN, 0);
	create("rothe", 100, 0, 0);
	create("rust monster", 250, 0, 0);
	create("salamander", 400, EAT_EFFECT_POISONOUS, 53);
	create("samurai", 400, EAT_EFFECT_HUMAN, 0);
	create("sasquatch", 750, 0, 0);
	create("scorpion", 100, EAT_EFFECT_POISONOUS, 50);
	create("Scorpius", 350, EAT_EFFECT_POISONOUS, 100);
	create("sergeant", 400, EAT_EFFECT_HUMAN, 0);
	create("sewer rat", 12, 0, 0);
	create("Shaman Karnov", 400, EAT_EFFECT_HUMAN, 0);
	create("shark", 350, 0, 0);
	create("shopkeeper", 400, EAT_EFFECT_HUMAN, 0);
	create("shrieker", 100, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN, 20);
	create("silver dragon", 1500, 0, 0);
	create("small mimic", 200, EAT_EFFECT_MIMIC, 0);
	create("snake", 80, EAT_EFFECT_POISONOUS, 27);
	create("snow ant", 10, 0, 20);
	create("soldier", 400, EAT_EFFECT_HUMAN, 0);
	create("soldier ant", 5, EAT_EFFECT_POISONOUS, 20);
	create("spotted jelly", 20, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_ACIDIC, 0);
	create("stalker", 400, EAT_EFFECT_STUN | EAT_EFFECT_INVISIBILITY, 0);
	create("stone giant", 750, EAT_EFFECT_STRENGTH, 0);
	create("storm giant", 750, EAT_EFFECT_STRENGTH, 50);
	create("student", 400, EAT_EFFECT_HUMAN, 0);
	create("tengu", 200, 0, 17);
	create("thug", 400, EAT_EFFECT_HUMAN, 0);
	create("tiger", 300, 0, 0);
	create("titan", 900, 0, 0);
	create("titanothere", 650, 0, 0);
	create("tourist", 400, EAT_EFFECT_HUMAN, 0);
	create("trapper", 350, 0, 0);
	create("troll", 350, 0, 0);
	create("Twoflower", 400, EAT_EFFECT_HUMAN, 0);
	create("umber hulk", 500, 0, 0);
	create("Uruk-hai", 300, 0, 0);
	create("valkyrie", 400, EAT_EFFECT_HUMAN, 0);
	create("vampire bat", 20, EAT_EFFECT_POISONOUS, 0);
	create("violet fungus", 100, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_HALLUCINOGENIC, 20);
	create("warg", 350, 0, 0);
	create("warhorse", 350, 0, 0);
	create("warrior", 400, EAT_EFFECT_HUMAN, 0);
	create("watch captain", 400, EAT_EFFECT_HUMAN, 0);
	create("watchman", 400, EAT_EFFECT_HUMAN, 0);
	create("water moccasin", 80, EAT_EFFECT_POISONOUS, 27);
	create("water nymph", 300, 0, 30);
	create("water troll", 350, 0, 0);
	create("werejackal", 400, EAT_EFFECT_HUMAN | EAT_EFFECT_POISONOUS | EAT_EFFECT_LYCANTHROPY, 0);
	create("wererat", 400, EAT_EFFECT_HUMAN | EAT_EFFECT_POISONOUS | EAT_EFFECT_LYCANTHROPY, 0);
	create("werewolf", 400, EAT_EFFECT_HUMAN | EAT_EFFECT_POISONOUS | EAT_EFFECT_LYCANTHROPY, 0);
	create("white dragon", 1500, 0, 100);
	create("white unicorn", 300, 0, 27);
	create("winged gargoyle", 300, 0, 0);
	create("winter wolf", 300, 0, 47);
	create("winter wolf cub", 200, 0, 33);
	create("wizard", 400, EAT_EFFECT_HUMAN, 0);
	create("Wizard of Yendor", 400, EAT_EFFECT_HUMAN, 25);
	create("wolf", 250, 0, 0);
	create("wood nymph", 300, 0, 30);
	create("woodchuck", 30, 0, 0);
	create("Woodland-elf", 350, EAT_EFFECT_ELF, 27);
	create("wraith", 0, EAT_EFFECT_GAIN_LEVEL, 0);
	create("wumpus", 500, 0, 0);
	create("xan", 300, EAT_EFFECT_POISONOUS, 47);
	create("xorn", 700, 0, 0);
	create("yellow dragon", 1500, EAT_EFFECT_ACIDIC, 0);
	create("yellow mold", 30, EAT_EFFECT_VEGETARIAN | EAT_EFFECT_VEGAN | EAT_EFFECT_POISONOUS | EAT_EFFECT_HALLUCINOGENIC, 7);
	create("yeti", 700, 0, 33);
	create("zruty", 600, 0, 0);
}

const map<const string, const Corpse*>& Corpse::corpses() {
	return _corpses;
}

/* public methods */
int Corpse::conferProbability() const {
	return _confer_probability;
}

/* protected static methods */
void Corpse::addToMap(const string& name, const Corpse* corpse) {
	_corpses[name] = corpse;
	Food::addToMap(name, corpse);
}

/* private static methods */
void Corpse::create(const string& name, int nutrition, int effects, int confer_probability) {
	const Monster* monster = Monster::monster(name);
	if (monster == NULL || monster->name().size() <= 0)
		return;
	string corpse_name = monster->name();
	string partly_eaten_name = monster->name();
	if (monster->name()[0] >= 'A' && monster->name()[0] <= 'Z' && (monster->genoFlags() & G_GENO) != 0) {
		/* unique monster that can't be genocided.
		 * unique corpse name */
		if (monster->name()[monster->name().size() - 1] == 's') {
			corpse_name.append("' corpse");
			partly_eaten_name.append("' partly eaten corpse");
		} else {
			corpse_name.append("'s corpse");
			partly_eaten_name.append("'s partly eaten corpse");
		}
	} else {
		corpse_name.append(" corpse");
		partly_eaten_name.insert(0, "partly eaten ");
		partly_eaten_name.append(" corpse");
	}
	int material = ((effects & EAT_EFFECT_VEGETARIAN) == 0) ? MATERIAL_FLESH : MATERIAL_VEGGY;
	addToMap(corpse_name, new Corpse(corpse_name, 5, monster->weight(), material, monster->resistancesConferred(), nutrition, monster->weight() / 64 + 3, effects, confer_probability));
	addToMap(partly_eaten_name, new Corpse(partly_eaten_name, 0, monster->weight() / 2, material, monster->resistancesConferred(), nutrition / 2, (monster->weight() / 64 + 3) / 2, effects, confer_probability));
}
