#include "World.h"
#include "Player.h"
#include "Exit.h"


Player::Player(const char* name, const char* des, EntityType id, Room* startRoom) : Creature(name, des, id), currentRoom(startRoom){
};

void Player::Look(){
	printf("%s\n%s", currentRoom->name.get_str(), currentRoom->description.get_str());
}

bool Player::move(Direction dir){

	for (int i = 0; i < NewWorld->entities.size(); i++)
	{
		if (NewWorld->entities[i]->id == EXIT && ((Exit*)NewWorld->entities[i])->src == currentRoom && ((Exit*)NewWorld->entities[i])->dir == dir){
			currentRoom = ((Exit*)NewWorld->entities[i])->destination;
			return true;
		}
	}
	
	return false;
	}