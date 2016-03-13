//Zork Tribute game
//Author: Joan Pareja Piñol
//Github: https://github.com/Yulna/Zork-Tribute


#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"

using namespace std;

int main(){
	bool game_on = true;
	enum Rooms_names{ wall = 0, Park_Start, Crush_house, Kid_house, Shop, Gross_guy_house, Dark_street, Nrw_street, Amus_park, Toilet, Library };
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

		}

		if (comand == "north" || comand == "n"){
			if (new_world.player->current_room == new_world.player->current_room->north_exit)
				cout << ("There is nothing in that direction") << endl;
			else{
				new_world.player->current_room = new_world.player->current_room->north_exit;
				cout << new_world.player->current_room->name << endl;
				cout << new_world.player->current_room->description << endl;
			}
		}

		if (comand == "south" || comand == "s"){
			if (new_world.player->current_room == new_world.player->current_room->south_exit)
				cout << ("There is nothing in that direction") << endl;
			else{
				new_world.player->current_room = new_world.player->current_room->south_exit;
				cout << new_world.player->current_room->name << endl;
				cout << new_world.player->current_room->description << endl;
			}
		}


		
		
		if (comand == "quit" || comand == "q")
			game_on = false;
	};

	return 0;
}