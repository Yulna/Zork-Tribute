#include <stdio.h>

#include "Globals.h"
#include "World.h"



World::World(){
	
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



	return true;
}