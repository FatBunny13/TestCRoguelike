#include "libtcod.hpp"
#include "header1.h"
#include "entity.h"
#include "map.h"
#include "SDL.h"
#include "SDL_events.h"

#include <iostream>
#include <list>

using namespace N;
using namespace std;

int wmain() {
	const int screen_width = 130;
	const int screen_height = 105;
	SDL_Event event;
	action process_keys;
	TCODConsole::initRoot(screen_width, screen_height, "The Arena of Bluddoom", false);
	std::vector<Actor *> actors;
	Actor *player;
	Map *map;
	map = new Map(125, 100);
	map->dig(62,50);
	int player_x = 62;
	int player_y = 50;
	player = new Actor(player_x, player_y, '@', TCODColor::white);
	actors.push_back(player);
	while (!TCODConsole::isWindowClosed()) {
		TCODConsole::root->clear();
		map->render();
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					process_keys.coordinates[0] = 0;
					process_keys.coordinates[1] = -1;
					process_keys.action_performed = "move";
					break;
				case SDLK_DOWN:
					process_keys.coordinates[0] = 0;
					process_keys.coordinates[1] = 1;
					process_keys.action_performed = "move";
					break;
				case SDLK_LEFT:
					process_keys.coordinates[0] = -1;
					process_keys.coordinates[1] = 0;
					process_keys.action_performed = "move";
					break;
				case SDLK_RIGHT:
					process_keys.coordinates[0] = 1;
					process_keys.coordinates[1] = 0;
					process_keys.action_performed = "move";
					break;
				default:
					process_keys.coordinates[0] = 0;
					process_keys.coordinates[1] = 0;
					process_keys.action_performed = "";
					break;
				}
			break;
			}
		}
		if (process_keys.action_performed == "move") {
			cout << player->x << endl;
			cout << player->y << endl;
			if (!map->isWall(player->x + process_keys.coordinates[0], player->y + process_keys.coordinates[1])) { //lolol ive been working on this for 2 days and just realized i put process_keys.coordinates [0] instead of [1]
				player->x += process_keys.coordinates[0];
				player->y += process_keys.coordinates[1];
				process_keys.action_performed = "why";
				cout << player->x << endl;
				cout << player->y << endl;
			}
		}
		else if (process_keys.action_performed == "escape") {
			break;

		}
		for (size_t i = 0; i < actors.size(); i++) { //note, it's very important to put this loop BEFORE you process the movement of an npc
			actors[i]->render();
			TCODConsole::flush();
		}

	}
	return 0;
}