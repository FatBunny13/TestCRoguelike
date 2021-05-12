#include "libtcod.hpp"
#include "header1.h"
#include <iostream>

using namespace N;


struct action N::handle_keys(action foo,char key,TCOD_keycode_t vk) {
	if (vk == TCODK_KP8 or vk == TCODK_UP) {
		std::cout << "Hello World!\n";
		foo.coordinates[0] = 0;
		foo.coordinates[1] = -1;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP2 or vk == TCODK_DOWN) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = 0;
		foo.coordinates[1] = 1;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP4 or vk == TCODK_LEFT) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = -1;
		foo.coordinates[1] = 0;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP6 or vk == TCODK_RIGHT) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = 1;
		foo.coordinates[1] = 0;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP3) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = 1;
		foo.coordinates[1] = 1;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP1) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = -1;
		foo.coordinates[1] = 1;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP9) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = 1;
		foo.coordinates[1] = -1;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_KP7) {
		std::cout << "Hey there!\n";
		foo.coordinates[0] = -1;
		foo.coordinates[1] = -1;
		foo.action_performed = "move";
		return foo;
	}
	else if (vk == TCODK_ESCAPE) {
		std::cout << "Hey there!\n";
		foo.action_performed = "escape";
		return foo;
	}
	else {
		foo.coordinates[1] = 0;
		foo.action_performed = "";
		return foo;
	}
	}