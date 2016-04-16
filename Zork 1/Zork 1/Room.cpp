#include "Room.h"

Room::Room(){
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


// Room exit setting methods
void Room::Set_north_exit(Room* exit){
	north_exit = exit;
};
void Room::Set_south_exit(Room* exit){
	south_exit = exit;
};
void Room::Set_weast_exit(Room* exit){
	weast_exit = exit;
};
void Room::Set_east_exit(Room* exit){
	east_exit = exit;
};
void Room::Set_down_exit(Room* exit){
	down_exit = exit;
};

//Door enabling methods
void Room::Set_north_door(bool state){
	door_north = true;
	open_north = state;
};
void Room::Set_south_door(bool state){
	door_south = true;
	open_south = state;
};
void Room::Set_weast_door(bool state){
	door_weast = true;
	open_weast = state;
};
void Room::Set_east_door(bool state){
	door_east = true;
	open_east = state;
};
void Room::Set_down_door(bool state){
	door_down = true;
	open_east = state;
};


