#include "World.h"
#include <iostream>


World::World(){
	room = new Room[10];
	player = new Player;
	Create_world();

};
World::~World(){
	delete[] room;
}

void World::Create_world(){
	
	enum Rooms_names{Park_Start=0, Crush_house, Kid_house, Shop, Gross_guy_house, Dark_street, Nrw_street, Amus_park, Toilet, Library};
	
	//Park data
	(room + Park_Start)->name = "PARK";
	(room + Park_Start)->description = "THE STARTING POINT";
	(room + Park_Start)->north_exit = (room + Kid_house);
	(room + Park_Start)->south_exit = (room + Park_Start);
	(room + Park_Start)->weast_exit = (room + Park_Start);
	(room + Park_Start)->east_exit = (room + Park_Start);
	

	//Kid house data
	(room + Kid_house)->name = "KIDDO";
	(room + Kid_house)->description = "MOVED TO NORTH";
	(room + Kid_house)->north_exit = (room + Kid_house);
	(room + Kid_house)->south_exit = (room + Park_Start);
	(room + Kid_house)->weast_exit = (room + Kid_house);
	(room + Kid_house)->east_exit = (room + Kid_house);
}


void World::move_north(){
	if (player->current_room == player->current_room->north_exit)
		cout << ("There is nothing in that direction") << endl;
	else{
		player->current_room = player->current_room->north_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
}
void World::move_south(){
	if (player->current_room == player->current_room->south_exit)
		cout << ("There is nothing in that direction") << endl;
	else{
		player->current_room = player->current_room->south_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
}
void World::move_weast(){
	if (player->current_room == player->current_room->weast_exit)
		cout << ("There is nothing in that direction") << endl;
	else{
		player->current_room = player->current_room->weast_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
}
void World::move_east(){
	if (player->current_room == player->current_room->east_exit)
		cout << ("There is nothing in that direction") << endl;
	else{
		player->current_room = player->current_room->east_exit;
		cout << player->current_room->name << endl;
		cout << player->current_room->description << endl;
	}
}
