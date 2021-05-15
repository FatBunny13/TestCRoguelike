#include "libtcod.hpp"
#include "map.h"

#include <time.h>
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
	tiles = new Tile[width*height];
	setWall(30, 22);
	setWall(50, 22);
}

Map::~Map() {
	delete[] tiles;
}

bool Map::isWall(int x, int y) const {
	return !tiles[x + y * width].canWalk;
}

bool Map::inMap(int x, int y) const {
	if (y < 3)
		return true;
	else if (x < 3)
		return true;
	else if (y > 95)
		return true;
	else if (x > 120)
		return true;
	else
		return false;
}

void Map::setWall(int x, int y) {
	tiles[x + y * width].canWalk = false;
}

void Map::dig(int x1, int y1) {
	const int tiles_count = 2600;
	int tiles_made = 0;
	int fourDirections;
	srand(time(NULL));
	fourDirections = rand() % 5;
	while (tiles_made < tiles_count) {
		fourDirections = rand() % 5;
		if (isWall(x1, y1)) {
			tiles[x1 + y1 * width].canWalk = true;
			tiles_made += 1;
		}
		switch (fourDirections) {
			case 0:
				x1 += 1;
				break;
			case 1:
				x1 -= 1;
				break;
			case 2:
				y1 += 1;
				break;
			case 3:
				y1 -= 1;
				break;

		}
		if (inMap(x1, y1)) {
			std::cout << "hey";
			x1 = 62;
			y1 = 50;
		}
	}
}

void Map::render() const {
	static const TCODColor darkWall(0, 0, 100);
	static const TCODColor darkGround(50, 50, 150);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			TCODConsole::root->setCharBackground(x, y,
				isWall(x, y) ? darkWall : darkGround);
		}
	}
}