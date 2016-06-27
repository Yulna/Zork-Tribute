#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <Windows.h>

#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Creature.h"
#include "Item.h"
#include "NPC.h"
#include "Seller.h"




World::World(){
	currentTime = 0;
	initialTime = 0;

	//Rooms
	Room* parkStart = new Room("Room 1", "the park gonna be", ROOM);
	Room* Room2 = new Room("Room 2", "secon room", ROOM);
	Room* Room3 = new Room("Room 3", "3 room", ROOM);


	entities.pushback(parkStart);
	entities.pushback(Room2);
	entities.pushback(Room3);


	//Exits
	Exit* north = new Exit("north", "north exit", EXIT, NORTH, parkStart, Room2);
	Exit* south = new Exit("south", "south exit", EXIT, SOUTH, Room2, parkStart);
	Exit* down = new Exit("down", "down exit", EXIT, DOWN, Room2, Room3, true, CLOSE);
	entities.pushback(north);
	entities.pushback(south);
	entities.pushback(down);

	//Creatures
	player = new Player("Yulna", "The pervert", PLAYER, parkStart, 50, 78);
	Npc* test = new Npc("Creature1", "a creature", NPC, Room2, 10, 20);
	Seller* shopguy = new Seller("Seller", "Sells things", NPC, parkStart, 10, 20);
	entities.pushback(test);
	entities.pushback(player);
	entities.pushback(shopguy);



	
}

World::~World(){
	for (int i = 0; i < entities.size(); i++){
		delete entities[i];
	}
	entities.clean();
}


bool World::Game_on(){
	UpdateState game_update;

	
	
	currentTime = GetTickCount();
	if (currentTime > (initialTime + DELAY)){

		//Entities Update-------------------------------------------------
		for (int i = 0; i < entities.size(); i++){
			game_update = entities[i]->Update();

			if (game_update == UPDATESTOP)
				return false;

			if (game_update == UPDATEERROR){
				printf("\nThe game has to close due to an error.");
				getchar();
				return false;
			}
		}
		initialTime = currentTime;
	}


	if (_kbhit()){

		if (commandPos < (COMMANDBUFFER - 2)){
			command[commandPos] = _getch();

			//Erasing functionality
			if (command[commandPos] == '\b' && commandPos>0){
				commandPos--;
				command[commandPos] = '\0';
			}
			else{
				command[commandPos + 1] = '\0';
				commandPos++;
			}
			
			//Cleaning screen and showing the current command
			system("cls");
			printf("%s\n", command);

			//Reseting the command and sending it when pressing Enter
			if (command[commandPos - 1] == '\r'){
				printf("Your command is: %s\n", command);
				command[commandPos-1] = '\0';
				commandPos = 0;
				if(!ReadCommand(command))
					return false;
				
			}

		}
		
		else{
			command[COMMANDBUFFER - 1] = '\0';
			printf("Your command is: %s\n", command);
			command[commandPos - 1] = '\0';
			commandPos = 0;
			if (!ReadCommand(command))
				return false;
		}
	}



	return true;
}


bool World::ReadCommand(char* str){
	String command(str);
	Vector<String> command_token;

	if (command.lenght() >= 1){
		command.tokenize(command_token);

		if (command_token[0] == "help" || command_token[0] == "h"){
			printf("I'm helping.");
		}

		else if (command_token[0] == "look" || command_token[0] == "l"){
			player->IntenseLook();
		}

		//Movement --------
		else if (command_token[0] == "north" || command_token[0] == "n" || (command_token[0] == "go" && command_token[1] == "north") || (command_token[0] == "go" && command_token[1] == "n")) {
			player->move(NORTH);
		}

		else if (command_token[0] == "south" || command_token[0] == "s" || (command_token[0] == "go" && command_token[1] == "south") || (command_token[0] == "go" && command_token[1] == "s")) {
			player->move(SOUTH);			
		}

		else if (command_token[0] == "east" || command_token[0] == "e" || (command_token[0] == "go" && command_token[1] == "east") || (command_token[0] == "go" && command_token[1] == "e")) {
			player->move(EAST);
		}
		else if (command_token[0] == "weast" || command_token[0] == "w" || (command_token[0] == "go" && command_token[1] == "weast") || (command_token[0] == "go" && command_token[1] == "w")) {
			player->move(WEAST);
			
		}
		else if (command_token[0] == "down" || command_token[0] == "d" || (command_token[0] == "go" && command_token[1] == "down") || (command_token[0] == "go" && command_token[1] == "d")) {
			player->move(DOWN);			
		}


		//opening exits
		else if (command_token[0] == "open" || command_token[0] == "o"){
			if (command_token[1] == "north" || command_token[1] == "n"){
				player->open(NORTH);
			}
			else if (command_token[1] == "south" || command_token[1] == "s"){
				player->open(SOUTH);
			}
			else if (command_token[1] == "weast" || command_token[1] == "w"){
				player->open(WEAST);
			}
			else if (command_token[1] == "east" || command_token[1] == "e"){
				player->open(EAST);
			}
			else if (command_token[1] == "down" || command_token[1] == "d"){
				player->open(DOWN);
			}
			
			else{
				printf("You must say a direction(north/south/east/weast). \nUse \"h\" or \"help\" to see all available commands\n");
			}
		}


		//closing exits
		else if (command_token[0] == "close" || command_token[0] == "c"){
			if (command_token[1] == "north" || command_token[1] == "n"){
				player->close(NORTH);
			}
			else if (command_token[1] == "south" || command_token[1] == "s"){
				player->close(SOUTH);
			}
			else if (command_token[1] == "weast" || command_token[1] == "w"){
				player->close(WEAST);
			}
			else if (command_token[1] == "east" || command_token[1] == "e"){
				player->close(EAST);
			}
			else if (command_token[1] == "down" || command_token[1] == "d"){
				player->close(DOWN);
			}
			else if (command_token[0] == "close"){
				printf("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available commands\n");
			}
		}

		









		//Show stats
		else if (command_token[0] == "stats"){
			printf("Yulna's stats:\n");
			player->ShowStats();
		}


		

		//End game
		else if (command_token[0] == "quit" || command_token[0] == "q"){
			return false;
		}

		//Error input message
		else
			printf("Invalid comand. Use \"h\" or \"help\" to see all available commands\n");
	}

	return true;
}