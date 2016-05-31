#include "World.h"
#include "NPC.h"
#include "Exit.h"

Npc::Npc(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins) : Creature(name, des, id, startRoom, life, coins){
};



UpdateState Npc::Update(){

	return UPDATECONTINUE;
}