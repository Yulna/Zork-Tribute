#ifndef PLAYER
#define PLAYER

#include "Room.h"

class Player
{
public:
	Room* current_room;
	Room* previous_room;

public:
	Player();
	~Player();

};

#endif // !PLAYER