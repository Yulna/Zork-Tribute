//Zork Tribute game
//Author: Joan Pareja Piñol 
//Github: https://github.com/Yulna/Zork-Tribute

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"

#include "MemLeaks.h"

using namespace std;

int main(){
	ReportMemoryLeaks();
	bool game_on = true;
	//enum Rooms_names{Park_Start=0, Crush_house, Kid_house, Shop, Gross_guy_house, Dark_street, Nrw_street, Amus_park, Toilet, Library };
	char comand[15];
	World new_world;

	new_world.player->current_room = new_world.room;
	

	while (game_on==true){


		gets_s(comand);

		if (comand == "look"||comand=="l"){
			cout << new_world.player->current_room->name << endl;
			cout << new_world.player->current_room->description << endl;
		};

		if (strcmp(comand, "help")==0 || strcmp(comand, "h")==0){
			cout << ("Use the following comands:\nDirection: north/south/east/weast (n/s/e/w)\nCurrent place data: look (l)\n") << endl;
		}

		if (strcmp(comand, "north") || strcmp(comand, "n") || strcmp(comand, "go north")){
			new_world.move_north();
		}
		if (strcmp(comand, "south") || strcmp(comand, "s") || strcmp(comand, "go south")){
			new_world.move_south();
		}
		if (strcmp(comand, "weast") || strcmp(comand, "w") || strcmp(comand, "go weast")){
			new_world.move_weast();
		}
		if (strcmp(comand, "east") || strcmp(comand, "east") || strcmp(comand, "go east")){
			new_world.move_east();
		}

		if (comand == "open" || comand == "o")
			new_world.open_room();
		
		if (comand == "quit" || comand == "q")
			game_on = false;
	};
	



	return 0;
}