#ifndef WORLD
#define WORLD
#include "Room.h"
#include "Player.h"
#include "Globals.h"
#include "Vector.h"


class World
{
public:
	
	Vector<Room*> rooms;
	Player* player = nullptr;
	bool game_on = true;

public:
	World();
	~World();
	void Create_world();

	void Game_loop();

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
