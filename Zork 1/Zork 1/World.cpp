#include "World.h"


World::World(){
	room = new Room[10];
	player = new Player;
	Create_world();

};
World::~World(){
	delete[] room;
}

void World::Create_world(){
	
	enum Rooms_names{wall=0, Park_Start, Crush_house, Kid_house, Shop, Gross_guy_house, Dark_street, Nrw_street, Amus_park, Toilet, Library};
	
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