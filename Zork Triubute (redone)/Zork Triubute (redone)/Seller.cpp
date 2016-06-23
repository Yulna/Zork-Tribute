#include <stdlib.h>

#include "World.h"
#include "Seller.h"
#include "Item.h"
#include "Exit.h"

Seller::Seller(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins, CreatureType type) : Creature(name, des, id, startRoom, life, coins, type){
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

	case SHOWINV:
		ShowInventory();
		state = NEUTRAL;
		return UPDATECONTINUE;
		break;


	}
	
	return UPDATECONTINUE;
}


void Seller::Talk(){
	state = TALK;
}

void Seller::ShowInventory(){
	//system("cls");
	printf("I have this in stock:\n");
	for (int i = 0; i < NewWorld->entities.size(); i++){
		if (NewWorld->entities[i]->id == ITEM && ((Item*)NewWorld->entities[i])->actual_place == this){
			printf("  %s\n", NewWorld->entities[i]->name.get_str());

		}

	}
}