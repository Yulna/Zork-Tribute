#ifndef WORLD
#define WORLD

#include "Globals.h"
#include "Vector.h"


class Room;
class Item;
class Player;

class World
{
public:
	
	Vector<Room*> rooms;
	Vector<Item*> items;
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
