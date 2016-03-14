//Zork Tribute game
//Author: Joan Pareja Piñol 
//Github: https://github.com/Yulna/Zork-Tribute

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"
#include "Room.h"

using namespace std;

int main(){
	bool game_on = true;
	enum Rooms_names{Park_Start=0, Crush_house, Kid_house, Shop, Gross_guy_house, Dark_street, Nrw_street, Amus_park, Toilet, Library };
	string comand;
	World new_world;

	new_world.player->current_room = new_world.room+Park_Start;
	
	while (game_on==true){

		getline(std::cin, comand);

		if (comand == "look"||comand=="l"){
			cout << new_world.player->current_room->name << endl;
			cout << new_world.player->current_room->description << endl;
		};

		if (comand == "help" || comand == "h"){
			cout << ("Use the following comands:\nDirection: north/south/east/weast (n/s/e/w)\nCurrent place data: look (l)\n") << endl;
		}

		if (comand == "north" || comand == "n"){
			new_world.move_north();
		}
		if (comand == "south" || comand == "s"){
			new_world.move_south();
		}
		if (comand == "weast" || comand == "w"){
			new_world.move_weast();
		}
		if (comand == "east" || comand == "e"){
			new_world.move_east();
		}
		
		if (comand == "quit" || comand == "q")
			game_on = false;
	};
	



	return 0;
}