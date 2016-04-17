#ifndef PLAYER
#define PLAYER

#include "Room.h"
#include "Item.h"

class Player : public Entity
{
public:
	Room* current_room;
	int max_inv;


public:
	Player();
	~Player();

};

#endif // !PLAYER