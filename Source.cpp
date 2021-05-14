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
	const int screen_width = 80;
	const int screen_height = 50;
	SDL_Event event;
	action process_keys;
	TCODConsole::initRoot(screen_width, screen_height, "The Arena of Bluddoom", false);
	int player_x = 40;
	int player_y = 25;
	std::vector<Actor *> actors;
	Actor *player;
	Map *map;
	player = new Actor(player_x, player_y, '@', TCODColor::white);
	actors.push_back(player);
	map = new Map(80, 50);
	while (!TCODConsole::isWindowClosed()) {
		TCOD_key_t key;
		TCOD_mouse_t mouse;
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
		TCODConsole::root->clear();
		TCOD_event_t ev = TCODSystem::waitForEvent(TCOD_EVENT_ANY, &key, &mouse, true);
		map->render();
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					std::cout << "ewfy555w";
					process_keys.coordinates[0] = 0;
					process_keys.coordinates[1] = -1;
					process_keys.action_performed = "move";
					break;
				case SDLK_DOWN:
					std::cout << "kjhg";
					process_keys.coordinates[0] = 0;
					process_keys.coordinates[1] = 1;
					process_keys.action_performed = "move";
					break;
				case SDLK_LEFT:
					std::cout << "3r3r";
					process_keys.coordinates[0] = -1;
					process_keys.coordinates[1] = 0;
					process_keys.action_performed = "move";
					break;
				case SDLK_RIGHT:
					std::cout << "eew222";
					process_keys.coordinates[0] = 1;
					process_keys.coordinates[1] = 0;
					process_keys.action_performed = "move";
					break;
				default:
					std::cout << "fewefefwewefw";
					process_keys.coordinates[0] = 0;
					process_keys.coordinates[1] = 0;
					process_keys.action_performed = "";
					break;
				}
			break;
			}
		}
		if (process_keys.action_performed == "move") {
			cout << process_keys.action_performed;
			if (!map->isWall(player->x + process_keys.coordinates[0], player->y + process_keys.coordinates[0])) {
				player->x += process_keys.coordinates[0];
				player->y += process_keys.coordinates[1];
				process_keys.action_performed = "why";
				cout << process_keys.action_performed;
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