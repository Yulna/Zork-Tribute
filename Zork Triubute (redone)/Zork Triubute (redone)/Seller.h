#ifndef __SELLER_H__
#define __SELLER_H__

#include "Creature.h"
#include "Room.h"


enum SellerState{
	NEUTRAL,
	TALK,
	BUY,
	SELL,
	CONVINCED

};

class Seller : public Creature
{
public:
	SellerState state;

public:
	Seller(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins);
	~Seller();

	UpdateState Update();

	void Talk();
};

#endif // !__SELLER_H__