#ifndef WORLD
#define WORLD
#include "Room.h"
#include "Player.h"
#include "Globals.h"


class World
{
public:
	Room* room = nullptr;
	Player* player = nullptr;

public:
	World();
	~World();
	void Create_world() const;

	//Print the current room on the game
	void print_room() const;

	//movement prototypes
	void move(direction dir);
	
	//Open prototypes
	void open_exit(direction dir);

	//Close prototypes
	void close_exit(direction dir);

};

#endif // !WORLD
