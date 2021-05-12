#pragma once
#include "libtcod.hpp"
#include <vector> // #include directive
#include <string>

using namespace std;

namespace N {

			struct action {
			int coordinates[2] = {0,0};
			string action_performed;
		};


		struct action handle_keys(action,char,TCOD_keycode_t);

}