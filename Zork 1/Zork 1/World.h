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
	void move_north();
	void move_south();
	void move_weast();
	void move_east();
	void open_room();
};

#endif // !WORLD
