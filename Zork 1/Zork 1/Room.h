#ifndef ROOM
#define ROOM

#include <string>
#include "Entity.h"

using namespace std;


class Room : public Entity 
{
public:
	
	//room exits
	Room* north_exit;
	Room* south_exit;
	Room* weast_exit;
	Room* east_exit;
	Room* down_exit;

	//door states
	bool open_north;
	bool open_south;
	bool open_east;
	bool open_weast;
	bool open_down;

	//Define if there is or not a door in a determined diretion
	bool door_north;
	bool door_south;
	bool door_east;
	bool door_weast;
	bool door_down;


public:
	Room();
    ~Room();

};

#endif // !ROOM