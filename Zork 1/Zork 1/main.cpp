//Zork Tribute game
//Author: Joan Pareja Piñol 
//Github: https://github.com/Yulna/Zork-Tribute

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "World.h"
#include "Globals.h"
#include "My_String.h"

#include "MemLeaks.h"


int main(){
	ReportMemoryLeaks();
	bool game_on = true;
	String comand;
	World new_world;
	Vector<String*> command_token;

	//Set the player current room to the starting room
	new_world.player->current_room = new_world.rooms[0];


	//print the name of the game and the starting room
	printf ("                          ***THE SACRED PANTIES***\n");

	new_world.print_room();

	while (game_on==true){
		
		printf ("\nWhat do you want to do?");

		comand.write_str();


		if (comand=="look" || comand == "l" ){
			new_world.print_room();
		}
		

		//Clarified version of the help text.
		/*Comands accepted:
		Direction: north/south/east/weast/down (n/s/e/w/d)
		Direction can also be used by: go "direction"
		Current place data: look (l)
		Open doors: open "direction" where direction is north/south/east/weast/down
		Close doors: close "direction" where direction is north/south/east/weast/down
		End game: quit(q)*/
		
		else if (comand == "help" || comand == "h"){
			printf ("Comands accepted:\n\nDirection: north/south/east/weast/down (n/s/e/w/d)\nDirection can also be used by: go \"direction\"\nCurrent place data: look (l)\nOpen doors: open \"direction\" where direction is north/south/east/weast/down\nClose doors: close \"direction\" where direction is north/south/east/weast/down\nEnd game: quit(q) \n\n");
		}
		
		//movement inputs
		else if (comand == "north" || comand == "n" || comand == "go north" || comand == "go n") {
			new_world.move(NORTH);
		}
		else if (comand == "south" || comand == "s" || comand == "go south" || comand == "go s"){
			new_world.move(SOUTH);
		}
		else if (comand == "weast" || comand == "w" || comand == "go weast" || comand == "go w"){
			new_world.move(WEAST);
		}
		else if (comand == "east" || comand == "e" || comand == "go east" || comand == "go e"){
			new_world.move(EAST);
		}
		else if (comand == "down" || comand == "d" || comand == "go down" || comand == "go d" ){
			new_world.move(DOWN);
		}
		else if (comand == "go"){
			printf ("You must say a direction (north/south/weast/east).\nUse \"h\" or \"help\" to see all available comands\n");
		}

		//Open doors input
		else if (comand == "open north" || comand == "o n" || comand == "open n"){
			new_world.open_exit(NORTH);
		}
		else if (comand == "open south" || comand == "o s" || comand == "open s"){
			new_world.open_exit(SOUTH);
		}
		else if (comand == "open weast" || comand == "o w" || comand == "open w"){
			new_world.open_exit(WEAST);
		}
		else if (comand == "open east"  || comand == "o e" || comand == "open e"){
			new_world.open_exit(EAST);
		}
		else if (comand == "open down" || comand == "o d" || comand == "open d"){
			new_world.open_exit(DOWN);
		}
		else if (comand == "open all"){ //open all doors of the room
			new_world.open_exit(NORTH);
			new_world.open_exit(SOUTH);
			new_world.open_exit(WEAST);
			new_world.open_exit(EAST);
			new_world.open_exit(DOWN);
		}

		else if (comand == "open"){
			printf ("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available comands\n");
		}


		//Closing doors input
		//Only already existing doors can be closed
		else if (comand == "close north" || comand == "c n" || comand == "close n"){
			new_world.close_exit(NORTH);
		}
		else if (comand == "close south" || comand == "c s" || comand == "close s"){
			new_world.close_exit(SOUTH);
		}
		else if (comand == "close weast" || comand == "c w" || comand == "close w"){
			new_world.close_exit(WEAST);
		}
		else if (comand == "close east" || comand == "c e" || comand == "close e"){
			new_world.close_exit(EAST);
		}
		else if (comand == "close down" || comand == "c d"|| comand == "close d"){
			new_world.close_exit(DOWN);
		}
		else if (comand == "close all"){ //close all doors of the room
			new_world.close_exit(NORTH);
			new_world.close_exit(SOUTH);
			new_world.close_exit(WEAST);
			new_world.close_exit(EAST);
			new_world.close_exit(DOWN);
		}
		else if (comand== "close"){
			printf ("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available comands\n");
		}
		
	
		else if (comand =="quit" ||  comand=="q")
			game_on = false;

		//Error input mesage
		else
			printf ("Invalid comand. Use \"h\" or \"help\" to see all available comands\n");
	};
	



	return 0;
}