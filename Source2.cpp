#include "libtcod.hpp"
#include "header1.h"
#include "SDL.h"
#include "SDL_events.h"

#include <iostream>

using namespace N;


struct action N::handle_keys(action foo, SDL_Event *event) {
	std::cout << "test";
	SDL_PollEvent(event);
		std::cout << "hi";
		switch (event->key.keysym.sym) 
		{
		case SDLK_UP:
			foo.coordinates[0] = 0;
			foo.coordinates[1] = 1;
			foo.action_performed = "move";
			return foo;

		case SDLK_DOWN:
			foo.coordinates[0] = 0;
			foo.coordinates[1] = 1;
			foo.action_performed = "move";
			return foo;

		case SDLK_LEFT:
			foo.coordinates[0] = 0;
			foo.coordinates[1] = 1;
			foo.action_performed = "move";
			return foo;

		case SDLK_RIGHT:
			foo.coordinates[0] = 0;
			foo.coordinates[1] = 1;
			foo.action_performed = "move";
			return foo;

		default:
			foo.coordinates[1] = 0;
			foo.action_performed = "";
			return foo;
		}
}