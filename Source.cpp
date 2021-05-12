#include "libtcod.hpp"
#include "header1.h"
#include "entity.h"
#include <iostream>
#include <map>

using namespace N;

int main() {
	const int screen_width = 80;
	const int screen_height = 50;
	action process_keys;
	TCODConsole::initRoot(screen_width, screen_height, "libtcod C++ test", false);
	int player_x = 40;
	int player_y = 40;
	while (!TCODConsole::isWindowClosed()) {
		TCOD_key_t key;
		TCOD_mouse_t mouse;
		Actor::Actor player(player_x,player_y,"@", TCODColor::white);
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
		TCODConsole::root->clear();
		TCODConsole::flush();
		TCOD_event_t ev = TCODSystem::waitForEvent(TCOD_EVENT_ANY, &key, &mouse, true);
		process_keys = N::handle_keys(process_keys,key.c,key.vk);
		if (process_keys.action_performed == "move") {
			player_x += process_keys.coordinates[0];
			player_y += process_keys.coordinates[1];
			std::cout << player_y;
		}
		else if (process_keys.action_performed == "escape") {
			break;

		}

	}
	return 0;
}