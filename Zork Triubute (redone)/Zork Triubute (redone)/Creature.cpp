#include "Creature.h"

Creature::Creature(const char* name, const char* des, EntityType id) : Entity(name, des, id){
};


UpdateState Creature::Update(){

	if (id != PLAYER){
		printf("Hi");
	}
	
	return UPDATECONTINUE;
}