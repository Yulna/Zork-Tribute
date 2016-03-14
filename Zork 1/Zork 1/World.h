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

	//movement prototypes
	void move_north();
	void move_south();
	void move_weast();
	void move_east();
	void move_down();

	//Open-close prototypes
	void open_north_exit();
	void open_south_exit();
	void open_weast_exit();
	void open_east_exit();
	void open_down_exit();
};

#endif // !WORLD
