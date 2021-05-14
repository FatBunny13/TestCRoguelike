#pragma once
#include "libtcod.hpp"
#include "SDL.h"
#include "SDL_events.h"

#include <vector> // #include directive
#include <string>

using namespace std;

namespace N {

			struct action {
			int coordinates[2] = {0,0};
			string action_performed;
		};


		struct action handle_keys(action, SDL_Event*);

}