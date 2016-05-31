#include "Creature.h"

Creature::Creature(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins) : Entity(name, des, id), currentRoom(startRoom), life(life), coins(coins), type(PC){
};

Creature::Creature(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins, CreatureType type) : Entity(name, des, id), currentRoom(startRoom), life(life), coins(coins), type(type){
};


void Creature::Talk(){

	printf("%s\n", description.get_str());
}

UpdateState Creature::Update(){

	return UPDATECONTINUE;
}