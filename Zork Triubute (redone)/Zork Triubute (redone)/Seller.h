#ifndef __SELLER_H__
#define __SELLER_H__

#include "Creature.h"
#include "Room.h"
#include "Globals.h"


enum SellerState{
	NEUTRAL,
	TALK,
	BUY,
	SELL,
	CONVINCED,
	SHOWINV

};

class Seller : public Creature
{
public:
	SellerState state;

public:
	Seller(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins, CreatureType type);
	~Seller();

	UpdateState Update();

	void Talk();
	void ShowInventory();
};

#endif // !__SELLER_H__