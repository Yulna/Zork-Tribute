#include "Room.h"


Room::Room(){

	//Assigned to nullptr ti simplify the world creation process
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
	door_north=false;
	door_south=false;
	door_east=false;
	door_weast=false;
	door_down=false;
};
Room::~Room(){};