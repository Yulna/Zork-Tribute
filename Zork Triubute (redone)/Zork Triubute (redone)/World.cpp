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




World::World(){
	currentTime = 0;
	initialTime = 0;

	//Rooms
	Room* parkStart = new Room("Room 1", "the park gonna be", ROOM);
	Room* Room2 = new Room("Room 2", "secon room", ROOM);


	entities.pushback(parkStart);
	entities.pushback(Room2);


	//Exits
	Exit* north = new Exit("north", "north exit", EXIT, NORTH, parkStart, Room2);
	entities.pushback(north);

	//Creatures
	player = new Player("Yulna", "The pervert", PLAYER, parkStart);
	Creature* test = new Creature("Creature 1", "a creature", NPC);
	entities.pushback(test);
	entities.pushback(player);

	
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
			printf("I'm helping");
		}

		else if (command_token[0] == "look" || command_token[0] == "l"){
			player->Look();
		}

		//Movement --------
		else if (command_token[0] == "north" || command_token[0] == "n" || (command_token[0] == "go" && command_token[1] == "north") || (command_token[0] == "go" && command_token[1] == "n")) {
			if (player->move(NORTH))
				player->Look();
			else
				printf("There's a wall in that direction");
		}
		else if (command_token[0] == "south" || command_token[0] == "s" || (command_token[0] == "go" && command_token[1] == "south") || (command_token[0] == "go" && command_token[1] == "s")) {
			if (player->move(SOUTH))
				player->Look();
			else
				printf("There's a wall in that direction");
		}
		else if (command_token[0] == "east" || command_token[0] == "e" || (command_token[0] == "go" && command_token[1] == "east") || (command_token[0] == "go" && command_token[1] == "e")) {
			if (player->move(EAST))
				player->Look();
			else
				printf("There's a wall in that direction");
		}
		else if (command_token[0] == "weast" || command_token[0] == "w" || (command_token[0] == "go" && command_token[1] == "weast") || (command_token[0] == "go" && command_token[1] == "w")) {
			if (player->move(WEAST))
				player->Look();
			else
				printf("There's a wall in that direction");
		}
		else if (command_token[0] == "down" || command_token[0] == "d" || (command_token[0] == "go" && command_token[1] == "down") || (command_token[0] == "go" && command_token[1] == "d")) {
			if (player->move(DOWN))
				player->Look();
			else
				printf("There's a wall in that direction");
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