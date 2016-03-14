#include "World.h"
#include <iostream>
#define NUM_ROOMS 10
#define CRT_SECURE_NO_WARNINGS

World::World(){
	room = new Room[NUM_ROOMS];
	player = new Player;
	Create_world();

};
World::~World(){
	delete[] room;
	delete player;
}

//Giving values and data to the difernt rooms
void World::Create_world(){
	
	enum Rooms_names{Park_Start=0, Crush_house, Kid_house, Shop, Gross_guy_house, Dark_street, Nrw_street, Amus_park, Toilet, Library};
	
	//Park data
	strcpy_s(((room + Park_Start)->name), "PARK");
	strcpy_s(((room + Park_Start)->description), "THE STARTING POINT");
	(room + Park_Start)->north_exit = (room + Kid_house);
	(room + Park_Start)->down_exit = (room + Kid_house);
	(room + Park_Start)->open_down = false;

	
	//Kid house data
	strcpy_s(((room + Kid_house)->name), "KIDDO");
	strcpy_s(((room + Kid_house)->description ),"MOVED TO NORTH");
	(room + Kid_house)->south_exit = (room + Park_Start);

}

//Movement functions
void World::move_north(){
	if (player->current_room->north_exit == nullptr)
		cout << ("There is nothing in that direction") << endl;
	else if (player->current_room->open_north){
		player->current_room = player->current_room->north_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
	else
		cout << ("The exit is closed") << endl;
}
void World::move_south(){
	if (player->current_room->south_exit == nullptr)
		cout << ("There is nothing in that direction") << endl;
	else if (player->current_room->open_south){
		player->current_room = player->current_room->south_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
	else
		cout << ("The exit is closed") << endl;
}
void World::move_weast(){
	if (player->current_room->weast_exit == nullptr)
		cout << ("There is nothing in that direction") << endl;
	else if (player->current_room->open_weast){
		player->current_room = player->current_room->weast_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
	else
		cout << ("The exit is closed") << endl;
}
void World::move_east(){
	if (player->current_room->east_exit == nullptr)
		cout << ("There is nothing in that direction") << endl;
	else if (player->current_room->open_east){
		player->current_room = player->current_room->east_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
	else
		cout << ("The exit is closed") << endl;
}
void World::move_down(){
	if (player->current_room->down_exit == nullptr)
		cout << ("There is nothing in that direction") << endl;
	else if (player->current_room->open_down){
		player->current_room = player->current_room->down_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
	else
		cout << ("The exit is closed") << endl;
}

//Open-door functions
void World::open_north_exit(){

	if (player->current_room->open_north)					//Avoid opening unexisting doors
		cout << ("There is nothing to open here") << endl;
	else{
		player->current_room->open_north = true;
		cout << ("The north exit is opened") << endl;
	}
}
void World::open_south_exit(){
	if (player->current_room->open_south)
		cout << ("There is nothing to open here") << endl;
	else{
		player->current_room->open_south = true;
		cout << ("The south exit is opened") << endl;
	}
}
void World::open_weast_exit(){
	if (player->current_room->open_weast)
		cout << ("There is nothing to open here") << endl;
	else{
		player->current_room->open_weast = true;
		cout << ("The weast exit is opened") << endl;
	}
}
void World::open_east_exit(){
	if (player->current_room->open_east)
		cout << ("There is nothing to open here") << endl;
	else{
		player->current_room->open_east = true;
		cout << ("The east exit is opened") << endl;
	}
}
void World::open_down_exit(){
	if (player->current_room->open_down)
		cout << ("There is nothing to open here") << endl;
	else{
		player->current_room->open_down = true;
		cout << ("The down exit is opened") << endl;
	}
}