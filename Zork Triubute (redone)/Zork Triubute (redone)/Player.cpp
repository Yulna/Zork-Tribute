#include "World.h"
#include "Player.h"
#include "Exit.h"


Player::Player(const char* name, const char* des, EntityType id, Room* startRoom) : Creature(name, des, id), currentRoom(startRoom){
	Yandere = false;
	Tsundere = false;
	Kuudere = false;
	Dendere = false;
};

void Player::Look(){
	printf("%s\n%s", currentRoom->name.get_str(), currentRoom->description.get_str());
}

ExitState Player::move(Direction dir){

	for (int i = 0; i < NewWorld->entities.size(); i++)
	{
		if (NewWorld->entities[i]->id == EXIT && ((Exit*)NewWorld->entities[i])->src == currentRoom && ((Exit*)NewWorld->entities[i])->dir == dir){
			if (((Exit*)NewWorld->entities[i])->state == OPEN){
				currentRoom = ((Exit*)NewWorld->entities[i])->destination;
				return OPEN;
			}
			else if (((Exit*)NewWorld->entities[i])->state == CLOSE){
				return CLOSE;
			}
		}
	}
	
	return NOTHING;
}

bool Player::open(Direction dir){

	for (int i = 0; i < NewWorld->entities.size(); i++)
	{
		if (NewWorld->entities[i]->id == EXIT && ((Exit*)NewWorld->entities[i])->src == currentRoom && ((Exit*)NewWorld->entities[i])->dir == dir){
			if (((Exit*)NewWorld->entities[i])->door){
				if (((Exit*)NewWorld->entities[i])->state == OPEN){
					printf("The exit is already opened.");
					return false;
				}
				else if (((Exit*)NewWorld->entities[i])->state == CLOSE){
					((Exit*)NewWorld->entities[i])->state = OPEN;
					printf("Exit opened.");
					return true;
				}
			}
		}
	}

	printf("There is nothing to open in that direction.");
	
	return false;
}


bool Player::close(Direction dir){

	for (int i = 0; i < NewWorld->entities.size(); i++)
	{
		if (NewWorld->entities[i]->id == EXIT && ((Exit*)NewWorld->entities[i])->src == currentRoom && ((Exit*)NewWorld->entities[i])->dir == dir){
			if (((Exit*)NewWorld->entities[i])->door){
				if (((Exit*)NewWorld->entities[i])->state == CLOSE){
					printf("The exit is already closed.");
					return false;
				}
				else if (((Exit*)NewWorld->entities[i])->state == OPEN){
					((Exit*)NewWorld->entities[i])->state = CLOSE;
					printf("Exit closed.");
					return true;
				}
			}
		}
	}

	printf("There is nothing to close in that direction.");

	return false;
}

void Player::ShowStats(){
	if (Yandere)
		printf("You feel the Yandere power spreading through your veins.");
	if (Tsundere)
		printf("You feel the Tsundere power spreading through your veins.");
	if (Kuudere)
		printf("You feel the Kuudere power spreading through your veins.");
	if (Dendere)
		printf("You feel the Dendere power spreading through your veins.");

	//When you have nothing
	if (!Yandere && !Tsundere && !Kuudere &&!Dendere)
		printf("You have no special stats.");
}