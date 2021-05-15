#pragma once

struct Tile {
	bool canWalk; // can we walk through this tile?
	Tile() : canWalk(false) {}
};

class Map {
public:
	int width, height;

	Map(int width, int height);
	~Map();
	bool isWall(int x, int y) const;
	void render() const;
	void dig(int x1, int y1);
	bool inMap(int x, int y) const;
protected:
	Tile *tiles;

	void setWall(int x, int y);
};