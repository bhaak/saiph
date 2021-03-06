#ifndef ANALYZER_EXPLORE_H
#define ANALYZER_EXPLORE_H

#include <map>
#include <string>
#include "Coordinate.h"
#include "Point.h"
#include "Analyzers/Analyzer.h"

/* search interval */
#define EXPLORE_SEARCH_INTERVAL 16
/* priorities */
#define PRIORITY_EXPLORE_ROGUE 100
#define PRIORITY_EXPLORE_STAIRS_UP 90
#define PRIORITY_EXPLORE_LEVEL 80
#define PRIORITY_EXPLORE_STAIRS_DOWN 70
#define PRIORITY_EXPLORE_MAGIC_PORTAL 70

class Tile;

namespace analyzer {

	class Explore : public Analyzer {
	public:
		Explore();

		void analyze();

	private:
		std::map<int, int> _explore_levels;

		void explorePoint(Point p, Tile* best_tile, int* best_type);
	};
}
#endif
