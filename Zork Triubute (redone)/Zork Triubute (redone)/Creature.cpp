#include "Creature.h"

Creature::Creature(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins) : Entity(name, des, id), currentRoom(startRoom), life(life), coins(coins){
};


UpdateState Creature::Update(){

	if (id != PLAYER){
		printf("Hi");
	}
	
	return UPDATECONTINUE;
}