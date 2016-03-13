#ifndef WORLD
#define WORLD
#include "Room.h"
#include "Player.h"

class World
{
public:
	Room* room = nullptr;
	Player* player = nullptr;

public:
	World();
	~World();
	void Create_world();
};

#endif // !WORLD
