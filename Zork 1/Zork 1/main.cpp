//Zork Tribute game
//Author: Joan Pareja Piñol 
//Github: https://github.com/Yulna/Zork-Tribute

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include "World.h"
#include "Globals.h"

#include "MemLeaks.h"

using namespace std;

int main(){
	ReportMemoryLeaks();
	bool game_on = true;
	char comand[15];
	World new_world;

	//Set the player current room to the starting room
	new_world.player->current_room = new_world.room;
	
	//print the name of the game and the starting room
	cout << ("                          ***THE SACRED PANTIES***\n") << endl;
	new_world.print_room();

	while (game_on==true){
		
		cout << ("\nWhat do you want to do?") << endl;

		gets_s(comand);

		if (strcmp(comand, "look") == 0 || strcmp(comand, "l") == 0){
			cout << new_world.player->current_room->name << endl;
			cout << new_world.player->current_room->description << endl;
		}

		//Clarified version of the help text.
		/*Comands accepted:
		Direction: north/south/east/weast/down (n/s/e/w/d)
		Direction can also be used by: go "direction"
		Current place data: look (l)
		Open doors: open "direction" where direction is north/south/east/weast/down
		Close doors: close "direction" where direction is north/south/east/weast/down
		End game: quit(q)*/
		else if (strcmp(comand, "help")==0 || strcmp(comand, "h")==0){
			cout << ("Comands accepted:\n\nDirection: north/south/east/weast/down (n/s/e/w/d)\nDirection can also be used by: go \"direction\"\nCurrent place data: look (l)\nOpen doors: open \"direction\" where direction is north/south/east/weast/down\nClose doors: close \"direction\" where direction is north/south/east/weast/down\nEnd game: quit(q) \n") << endl;
		}

		//movement inputs
		else if (strcmp(comand, "north") == 0 || strcmp(comand, "n") == 0 || strcmp(comand, "go north") == 0 || strcmp(comand, "go n") == 0) {
			new_world.move(NORTH);
		}
		else if (strcmp(comand, "south") == 0 || strcmp(comand, "s") == 0 || strcmp(comand, "go south") == 0 || strcmp(comand, "go s") == 0){
			new_world.move(SOUTH);
		}
		else if (strcmp(comand, "weast") == 0 || strcmp(comand, "w") == 0 || strcmp(comand, "go weast") == 0 || strcmp(comand, "go w") == 0){
			new_world.move(WEAST);
		}
		else if (strcmp(comand, "east") == 0 || strcmp(comand, "e") == 0 || strcmp(comand, "go east") == 0 || strcmp(comand, "go e") == 0){
			new_world.move(EAST);
		}
		else if (strcmp(comand, "down") == 0 || strcmp(comand, "d") == 0 || strcmp(comand, "go down") == 0 || strcmp(comand, "go d") == 0){
			new_world.move(DOWN);
		}
		else if (strcmp(comand, "go")==0){
			cout << ("You must say a direction (north/south/weast/east).\nUse \"h\" or \"help\" to see all available comands") << endl;
		}

		//Open doors input
		else if (strcmp(comand, "open north") == 0 || strcmp(comand, "o n") == 0 || strcmp(comand, "open n") == 0){
			new_world.open_exit(NORTH);
		}
		else if (strcmp(comand, "open south") == 0 || strcmp(comand, "o s") == 0 || strcmp(comand, "open s") == 0){
			new_world.open_exit(SOUTH);
		}
		else if (strcmp(comand, "open weast") == 0 || strcmp(comand, "o w") == 0 || strcmp(comand, "open w") == 0){
			new_world.open_exit(WEAST);
		}
		else if (strcmp(comand, "open east") == 0 || strcmp(comand, "o e") == 0 || strcmp(comand, "open e") == 0){
			new_world.open_exit(EAST);
		}
		else if (strcmp(comand, "open down") == 0 || strcmp(comand, "o d" ) == 0|| strcmp(comand, "open d") == 0){
			new_world.open_exit(DOWN);
		}
		else if (strcmp(comand, "open all")==0){ //open all doors of the room
			new_world.open_exit(NORTH);
			new_world.open_exit(SOUTH);
			new_world.open_exit(WEAST);
			new_world.open_exit(EAST);
			new_world.open_exit(DOWN);
		}

		else if (strcmp(comand, "open") == 0){
			cout << ("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available comands") << endl;
		}


		//Closing doors input
		//Only already existing doors can be closed
		else if (strcmp(comand, "close north") == 0 || strcmp(comand, "c n") == 0 || strcmp(comand, "close n") == 0){
			new_world.close_exit(NORTH);
		}
		else if (strcmp(comand, "close south") == 0 || strcmp(comand, "c s") == 0 || strcmp(comand, "close s") == 0){
			new_world.close_exit(SOUTH);
		}
		else if (strcmp(comand, "close weast") == 0 || strcmp(comand, "c w") == 0 || strcmp(comand, "close w") == 0){
			new_world.close_exit(WEAST);
		}
		else if (strcmp(comand, "close east") == 0 || strcmp(comand, "c e") == 0 || strcmp(comand, "close e") == 0){
			new_world.close_exit(EAST);
		}
		else if (strcmp(comand, "close down") == 0 || strcmp(comand, "c d") == 0 || strcmp(comand, "close d") == 0){
			new_world.close_exit(DOWN);
		}
		else if (strcmp(comand, "close all") == 0){ //close all doors of the room
			new_world.close_exit(NORTH);
			new_world.close_exit(SOUTH);
			new_world.close_exit(WEAST);
			new_world.close_exit(EAST);
			new_world.close_exit(DOWN);
		}
		else if (strcmp(comand, "close") == 0){
			cout << ("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available comands") << endl;
		}
	
		else if (strcmp(comand, "quit") == 0 || strcmp(comand, "q") == 0)
			game_on = false;

		//Error input mesage
		else
			cout << ("Invalid comand. Use \"h\" or \"help\" to see all available comands") << endl;
	};
	



	return 0;
}