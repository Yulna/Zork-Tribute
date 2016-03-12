#ifndef WORLD
#define WORLD
#include "Room.h"

class World
{
public:
	Room* rooms = nullptr;

public:
	World();
	~World();
};

#endif // !WORLD
