#ifndef ROOM
#define ROOM

#include "Entity.h"


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
	Room(const char* creating_name, const char* creating_des) : Entity(creating_name, creating_des){
		//Assigned to nullptr to simplify the world creation process
		north_exit = nullptr;
		south_exit = nullptr;
		weast_exit = nullptr;
		east_exit = nullptr;
		down_exit = nullptr;

		//Assigned to open by default also to simplify world creation
		open_north = true;
		open_south = true;
		open_east = true;
		open_weast = true;
		open_down = true;

		//Assigned to false to simplify world creation
		door_north = false;
		door_south = false;
		door_east = false;
		door_weast = false;
		door_down = false;
	};
	~Room(){};

	void Set_north_exit(Room* exit);
	void Set_south_exit(Room* exit);
	void Set_weast_exit(Room* exit);
	void Set_east_exit(Room* exit);
	void Set_down_exit(Room* exit);

	void Set_north_door(bool state);
	void Set_south_door(bool state);
	void Set_weast_door(bool state);
	void Set_east_door(bool state);
	void Set_down_door(bool state);
};

#endif // !ROOM