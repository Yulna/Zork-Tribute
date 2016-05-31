#include "World.h"
#include "Seller.h"
#include "Exit.h"

Seller::Seller(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins) : Creature(name, des, id, startRoom, life, coins){
	state = NEUTRAL;
};

UpdateState Seller::Update(){

	switch (state){
	
	case NEUTRAL:
		return UPDATECONTINUE;
		break;

	case TALK:
		printf("I will sell you gud stuff");
		state = NEUTRAL;
		return UPDATECONTINUE;
		break;

	case BUY:
		return UPDATECONTINUE;
		break;

	case SELL:
		return UPDATECONTINUE;
		break;

	case CONVINCED:
		return UPDATECONTINUE;
		break;


	}
	
	return UPDATECONTINUE;
}


void Seller::Talk(){
	state = TALK;
}