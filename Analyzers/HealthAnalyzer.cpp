#include "HealthAnalyzer.h"

/* constructors */
HealthAnalyzer::HealthAnalyzer(Saiph *saiph) {
	this->saiph = saiph;
}

/* methods */
void HealthAnalyzer::finish() {
	/* figure out if we're in danger of dying */
	/* illness */
	if (saiph->world->player.status.ill) {
		/* find out the best way to cure this
		 * spell, potion, unihorn, pray
		 *
		 * pray for now */
		saiph->setNextCommand(HA_PRAY, 100);
	}
	/* food */
	if (saiph->world->player.status.hunger == FAINTING) {
		saiph->setNextCommand(HA_PRAY, 100);
	} else if (saiph->world->player.status.hunger == WEAK) {
		/* eat food, or pray */
		//saiph->setNextCommand(HA_PRAY, 90);
	} else if (saiph->world->player.status.hunger == HUNGRY) {
		/* eat food */
	}
	/* hp */
	int hp = saiph->world->player.status.hitpoints;
	int hp_max = saiph->world->player.status.hitpoints_max;
	if (hp < 6 || hp * 7 <= hp_max) {
		/* almost dead, find an urgent way to heal up.
		 * spell, potion, (elbereth?), pray
		 *
		 * pray for now */
		saiph->setNextCommand(HA_PRAY, 100);
	} else if (hp * 2 < hp_max) {
		/* health is going low.
		 * elbereth, run, potion, lots of options
		 *
		 * elbereth for now */
		saiph->setNextCommand(HA_ENGRAVE_ELBERETH, 90);
	}
}