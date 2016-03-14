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
			cout << ("Comands accepted:\nDirection: north/south/east/weast (n/s/e/w)\nCurrent place data: look (l)\n") << endl;
		}

		//movement inputs
		if (strcmp(comand, "north") == 0 || strcmp(comand, "n") == 0 || strcmp(comand, "go north") == 0) {
			new_world.move_north();
		}
		if (strcmp(comand, "south") == 0 || strcmp(comand, "s") == 0 || strcmp(comand, "go south") == 0){
			new_world.move_south();
		}
		if (strcmp(comand, "weast") == 0 || strcmp(comand, "w") == 0 || strcmp(comand, "go weast") == 0){
			new_world.move_weast();
		}
		if (strcmp(comand, "east") == 0 || strcmp(comand, "e") == 0 || strcmp(comand, "go east") == 0){
			new_world.move_east();
		}
		if (strcmp(comand, "down") == 0 || strcmp(comand, "d") == 0 || strcmp(comand, "go down") == 0){
			new_world.move_down();
		}

		//Open doors input
		if (strcmp(comand, "open north") == 0 || strcmp(comand, "o n") == 0 ){
			new_world.open_north_exit();
		}
		if (strcmp(comand, "open south") == 0 || strcmp(comand, "o s") == 0){
			new_world.open_south_exit();
		}
		if (strcmp(comand, "open weast") == 0 || strcmp(comand, "o w") == 0){
			new_world.open_weast_exit();
		}
		if (strcmp(comand, "open east") == 0 || strcmp(comand, "o e") == 0){
			new_world.open_east_exit();
		}
		if (strcmp(comand, "open down") == 0 || strcmp(comand, "o d") == 0){
			new_world.open_down_exit();
		}
			
		
		if (strcmp(comand, "quit") == 0 || strcmp(comand, "q") == 0)
			game_on = false;
	};
	



	return 0;
}