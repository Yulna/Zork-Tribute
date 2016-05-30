#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <Windows.h>

#include "World.h"



World::World(){
	currentTime = 0;
	initialTime = 0;
	
	Room* parkStart = new Room("Room 1", "the park gonna be", ROOM);


	entities.pushback(parkStart);



	//Creatures
	Creature* test = new Creature("Creature 1", "a creature", CREATURE);
	entities.pushback(test);

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
			printf("String: %s\n", command);

			//Reseting the command and sending it when pressing Enter
			if (command[commandPos - 1] == '\r'){
				printf("Your command is: %s\n", command);
				ReadCommand(command);
				command[commandPos] = '\0';
				commandPos = 0;
			}

		}
		
		else{
			command[COMMANDBUFFER - 1] = '\0';
			printf("Your command is: %s\n", command);
			ReadCommand(command);
			command[commandPos] = '\0';
			commandPos = 0;
		}
	}



	return true;
}


void World::ReadCommand(char* str){


}