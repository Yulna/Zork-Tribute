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
	strcpy_s(((room + Park_Start)->name), "Park");
	strcpy_s(((room + Park_Start)->description), "A simple kids park, the perfect home for a homless person like you. \nYou see a library to the south, and regular house at the north.");
	(room + Park_Start)->north_exit = (room + Kid_house);
	(room + Park_Start)->south_exit = (room + Library);
	
	//Kid house data
	strcpy_s(((room + Kid_house)->name), "Annoying kid house");
	strcpy_s(((room + Kid_house)->description ),"The place where that kid that never lets you take a nap lives. \nYou see a shop at the north and you're beatiful home (the park) at the south.");
	(room + Kid_house)->north_exit = (room + Shop);
	(room + Kid_house)->south_exit = (room + Park_Start);
	
	//Shop data
	strcpy_s(((room + Shop)->name), "Regular Shop");
	strcpy_s(((room + Shop)->description), "A simple, regular, normal shop even the salesman is plain. \nAt least you can still buy some groceries, or steal them. \nYou see a normal hause to the south and a house with a strange aura to the east.");
	(room + Shop)->south_exit = (room + Kid_house);
	(room + Shop)->east_exit = (room + Gross_guy_house);

	//Cross-dressing guy house data
	strcpy_s(((room + Gross_guy_house)->name), "Gross cross-dressing guy house");
	strcpy_s(((room + Gross_guy_house)->description), "");
	(room + Gross_guy_house)->south_exit = (room + Dark_street);
	(room + Gross_guy_house)->weast_exit = (room + Shop);
	(room + Gross_guy_house)->east_exit = (room + Amus_park);

	//Dark street data
	strcpy_s(((room + Dark_street)->name), "Dark street");
	strcpy_s(((room + Dark_street)->description), "");
	(room + Dark_street)->north_exit = (room + Gross_guy_house);
	(room + Dark_street)->south_exit = (room + Nrw_street);
	(room + Dark_street)->open_south = false;

	//Narrow street data
	strcpy_s(((room + Nrw_street)->name), "Narrow street");
	strcpy_s(((room + Nrw_street)->description), "");
	(room + Nrw_street)->north_exit = (room + Dark_street);
	(room + Nrw_street)->east_exit = (room + Crush_house);
	(room + Nrw_street)->open_east = false;

	//Crush house data
	strcpy_s(((room + Crush_house)->name), "Crush house");
	strcpy_s(((room + Crush_house)->description), "Your personal sanctuary, ");
	(room + Crush_house)->north_exit = (room + Amus_park);
	(room + Crush_house)->weast_exit = (room + Nrw_street);

	//Amusement park data 
	strcpy_s(((room + Amus_park)->name), "Amusment park");
	strcpy_s(((room + Amus_park)->description), "The average amusment park, full with young lovely-dovey couples. ");
	(room + Amus_park)->south_exit = (room + Crush_house);
	(room + Amus_park)->weast_exit = (room + Gross_guy_house);
	(room + Amus_park)->east_exit = (room + Toilet);

	//Toilets data
	strcpy_s(((room + Toilet)->name), "Public toilets");
	strcpy_s(((room + Toilet)->description), "");
	(room + Toilet)->weast_exit = (room + Amus_park);
	(room + Toilet)->down_exit = (room + Library);
	(room + Toilet)->open_down = false;

	//Library data
	strcpy_s(((room + Library)->name), "Library");
	strcpy_s(((room + Library)->description), "");
	(room + Library)->north_exit = (room + Park_Start);
	(room + Library)->down_exit = (room + Toilet);
	(room + Library)->open_down = false;
}

//Movement methods
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

//Open-door methods
void World::open_north_exit(){

	if (player->current_room->open_north)					//Avoid opening unexisting doors
		cout << ("There is nothing to open at north") << endl;
	else{
		player->current_room->open_north = true;
		cout << ("The north exit is opened") << endl;
	}
}
void World::open_south_exit(){
	if (player->current_room->open_south)
		cout << ("There is nothing to open at south") << endl;
	else{
		player->current_room->open_south = true;
		cout << ("The south exit is opened") << endl;
	}
}
void World::open_weast_exit(){
	if (player->current_room->open_weast)
		cout << ("There is nothing to open at weast") << endl;
	else{
		player->current_room->open_weast = true;
		cout << ("The weast exit is opened") << endl;
	}
}
void World::open_east_exit(){
	if (player->current_room->open_east)
		cout << ("There is nothing to open at east") << endl;
	else{
		player->current_room->open_east = true;
		cout << ("The east exit is opened") << endl;
	}
}
void World::open_down_exit(){
	if (player->current_room->open_down)
		cout << ("There is nothing to open below") << endl;
	else{
		player->current_room->open_down = true;
		cout << ("The down exit is opened") << endl;
	}
}


//Close-door methods
//Same as the open methods but returning a false value
void World::close_north_exit(){
	if (player->current_room->open_north)					//Avoid opening unexisting doors
		cout << ("There is nothing to close at north.") << endl;
	else{
		player->current_room->open_north = false;
		cout << ("The north exit is closed.") << endl;
	}
}
void World::close_south_exit(){
	if (player->current_room->open_south)
		cout << ("There is nothing to close at south.") << endl;
	else{
		player->current_room->open_south = false;
		cout << ("The south exit is closed.") << endl;
	}
}
void World::close_weast_exit(){
	if (player->current_room->open_weast)
		cout << ("There is nothing to close at weast.") << endl;
	else{
		player->current_room->open_weast = false;
		cout << ("The weast exit is closed.") << endl;
	}
}
void World::close_east_exit(){
	if (player->current_room->open_east)
		cout << ("There is nothing to close at east.") << endl;
	else{
		player->current_room->open_east = false;
		cout << ("The east exit is closed.") << endl;
	}
}
void World::close_down_exit(){
	if (player->current_room->open_down)
		cout << ("There is nothing to close below.") << endl;
	else{
		player->current_room->open_down = false;
		cout << ("The down exit is closed.") << endl;
	}
}