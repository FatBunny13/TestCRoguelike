#include "libtcod.hpp"
#include "header1.h"
#include "SDL.h"
#include "SDL_events.h"

#include <iostream>

using namespace N;


void N::handle_keys(action &foo, SDL_Event *event) {
	std::cout << "test";
	SDL_PollEvent(event);
	switch (event->type) {
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym)
			{
			case SDLK_UP:
				std::cout << "yo";
				foo.coordinates[0] = 0;
				foo.coordinates[1] = -1;
				foo.action_performed = "move";
				break;
			case SDLK_DOWN:
				std::cout << "yo";
				foo.coordinates[0] = 0;
				foo.coordinates[1] = 1;
				foo.action_performed = "move";
				break;
			case SDLK_LEFT:
				std::cout << "yo";
				foo.coordinates[0] = -1;
				foo.coordinates[1] = 0;
				foo.action_performed = "move";
				break;
			case SDLK_RIGHT:
				std::cout << "eew222";
				foo.coordinates[0] = 1;
				foo.coordinates[1] = 0;
				foo.action_performed = "move";
				break;
			default:
				std::cout << "fewefefwewefw";
				foo.coordinates[0] = 0;
				foo.coordinates[1] = 0;
				foo.action_performed = "";
				break;
			}
		break;
	}
}