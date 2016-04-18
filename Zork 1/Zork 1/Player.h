#ifndef PLAYER
#define PLAYER

#include "Room.h"
#include "Item.h"
#include "Globals.h"

class Player : public Entity
{
public:
	Room* current_room;
	int max_inv;
	bool item_equiped = false;
	Dere_states state = No_dere;


public:
	Player();
	~Player();

};

#endif // !PLAYER