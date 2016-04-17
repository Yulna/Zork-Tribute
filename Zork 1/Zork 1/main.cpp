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
//	String comand;
	World new_world;
	bool game_on = true;
//	Vector<String*> command_token;
	new_world.player->max_inv = 0;

	//Set the player current room to the starting room
	new_world.player->current_room = new_world.rooms[0];


	//print the name of the game and the starting room
	printf ("                          ***THE SACRED PANTIES***\n");

	new_world.print_room();

	
	new_world.Game_loop();
	


	return 0;
}