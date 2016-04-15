#include "World.h"
#include "Globals.h"
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

	Room* Park_Startp;
	
	//Park data

	rooms.pushback(Park_Startp = new Room("PARK", "park description"));

	//	room.pushback(new Room("\nPARK", "A simple kids park, the perfect home for a homless person like you. \nYou see a library to the south, and regular house at the north."));
	(room + Park_Start)->name = "\nPARK";
	(room + Park_Start)->description = "A simple kids park, the perfect home for a homless person like you. \nYou see a library to the south, and regular house at the north.";
	(room + Park_Start)->north_exit = (room + Kid_house);
	(room + Park_Start)->south_exit = (room + Library);
	
	//Kid house data
	(room + Kid_house)->name = "\nANNOYING KID HOUSE";
	(room + Kid_house)->description  ="The place where that kid that never lets you take a nap lives. \nYou see a shop at the north and you're beatiful home (the park) at the south.";
	(room + Kid_house)->north_exit = (room + Shop);
	(room + Kid_house)->south_exit = (room + Park_Start);
	
	//Shop data
	(room + Shop)->name = "\nREGULAR SHOP";
	(room + Shop)->description = "A simple, regular, normal shop even the salesman is plain. \nAt least you can still buy some groceries, or steal them. \nYou see a normal house to south and a house with a strange aura to east.";
	(room + Shop)->south_exit = (room + Kid_house);
	(room + Shop)->east_exit = (room + Gross_guy_house);

	//Cross-dressing guy house data
	(room + Gross_guy_house)->name = "\nGROSS CROSS-DRESSING GUY HOUSE";
	(room + Gross_guy_house)->description = "An overly decored house with a beatiful and sparkling garden.\nFor some reason can decide if the decoratoins give a femenine or masculine look.To south there is a scary and dark street, contrary to the east exit where you \ncan see a beatiful amusment park.";
	(room + Gross_guy_house)->south_exit = (room + Dark_street);
	(room + Gross_guy_house)->weast_exit = (room + Shop);
	(room + Gross_guy_house)->east_exit = (room + Amus_park);

	//Dark street data
	(room + Dark_street)->name = "\nDARK STREET";
	(room + Dark_street)->description = "The meeting place of all the gangs an delinquents of the town.\nIt will be better to go back an not disturb them too much.\nYou can go back at the werid house to north, there also seems to be a closed \nexit to south.";
	(room + Dark_street)->north_exit = (room + Gross_guy_house);
	(room + Dark_street)->south_exit = (room + Nrw_street);
	(room + Dark_street)->door_south = true;
	(room + Dark_street)->open_south = false;

	//Narrow street data
	(room + Nrw_street)->name = "\nNARROW STREET";
	(room + Nrw_street)->description = "You didn't even know that this street was in your town.\nIt's filled with empty bottles there's even one drunken man laying down on the floor, for some reason most of the bottles are piled up at the east side. It may be becasue the magnetic field of earth?\nThe only way out is going back at the dark street to north.";
	(room + Nrw_street)->north_exit = (room + Dark_street);
	(room + Nrw_street)->east_exit = (room + Crush_house);
	(room + Nrw_street)->door_north = true;
	(room + Nrw_street)->open_north = false;
	(room + Nrw_street)->door_east = true;
	(room + Nrw_street)->open_east = false;

	//Crush house data
	(room + Crush_house)->name = "\nCRUSH HOUSE";
	(room + Crush_house)->description = "Your personal sanctuary, you've dreamed so many times of coming here but never \nmustered enough courage to do it.\nAll but an oddly placed bush at the weast seems like heaven to you.\nThe only way out is at north to the amusment park.";
	(room + Crush_house)->north_exit = (room + Amus_park);
	(room + Crush_house)->weast_exit = (room + Nrw_street);
	(room + Crush_house)->door_weast = true;
	(room + Crush_house)->open_weast = false;

	//Amusement park data 
	(room + Amus_park)->name = "\nAMUSMENT PARK";
	(room + Amus_park)->description = "The average amusment park, full with young lovely-dovey couples. \nYou can sense a heavnly feeling coming from the south exit, at east you can findthe toilets if you need to use them.";
	(room + Amus_park)->south_exit = (room + Crush_house);
	(room + Amus_park)->weast_exit = (room + Gross_guy_house);
	(room + Amus_park)->east_exit = (room + Toilet);

	//Toilets data 
	(room + Toilet)->name = "\nPUBLIC TOILETS";
	(room + Toilet)->description = "The stinky toilets from the park, one fo them is oddly out of place.\nYou can only go back to the park at weast.";
	(room + Toilet)->weast_exit = (room + Amus_park);
	(room + Toilet)->down_exit = (room + Library);
	(room + Toilet)->door_down = true;
	(room + Toilet)->open_down = false;

	//Library data
	(room + Library)->name = "\nLIBRARY";
	(room + Library)->description = "An amaizingly quiet place, all filed with books and a few workaholics with piles of papers in their desks.\nYou can see a creppy guy sitting next to a broken tile or at least it seems so.\nThe only exits leads to the kids park at north.";
	(room + Library)->north_exit = (room + Park_Start);
	(room + Library)->down_exit = (room + Toilet);
	(room + Library)->door_down = true;
	(room + Library)->open_down = false;
	
}


//print the current room on the game
void World::print_room()const{
	player->current_room->name.print_str();
	player->current_room->description.print_str();
}


//Movement methods
void World::move(direction dir){

	if (dir == NORTH){
		if (player->current_room->north_exit == nullptr)
			printf ("There is nothing in that direction\n");
		else if (player->current_room->open_north){
			player->current_room = player->current_room->north_exit;
			print_room();
		}
		else
			printf ("The exit is closed\n");
	}

	if (dir == SOUTH){
		if (player->current_room->south_exit == nullptr)
			printf ("There is nothing in that direction\n");
		else if (player->current_room->open_south){
			player->current_room = player->current_room->south_exit;
			print_room();
		}
		else
			printf ("The exit is closed\n");
	}

	if (dir == WEAST){
		if (player->current_room->weast_exit == nullptr)
			printf ("There is nothing in that direction\n");
		else if (player->current_room->open_weast){
			player->current_room = player->current_room->weast_exit;
			print_room();
		}
		else
			printf ("The exit is closed\n");
	}

	if (dir == EAST){
		if (player->current_room->east_exit == nullptr)
			printf ("There is nothing in that direction\n");
		else if (player->current_room->open_east){
			player->current_room = player->current_room->east_exit;
			print_room();
		}
		else
			printf ("The exit is closed\n");
	}

	if (dir == DOWN){
		if (player->current_room->down_exit == nullptr)
			printf ("There is nothing in that direction\n");
		else if (player->current_room->open_down){
			player->current_room = player->current_room->down_exit;
			print_room();
		}
		else
			printf ("The exit is closed\n");
	}
}


//Open-door methods
void World::open_exit(direction dir){
	if (dir == NORTH){
		if (player->current_room->door_north){
			if (player->current_room->open_north)
				printf ("The door is already opened\n");
			else{
				player->current_room->open_north = true;
				//Change the state of the room door connected to the door you just opened.
				//To do it it goes to the next room you will be if you pass trought the door and then opens the door form where you would come. This code is repeated in all opening/closing-door methods.
				player->current_room->north_exit->open_south = true;
				printf ("The north exit is opened\n");
			}
		}
		else
			printf ("There is nothing to open to north\n");
	}

	if (dir == SOUTH){
		if (player->current_room->door_south){
			if (player->current_room->open_south)
				printf ("The door is already opened\n");
			else{
				player->current_room->open_south = true;
				player->current_room->south_exit->open_north = true;
				printf ("The south exit is opened\n");
			}
		}
		else
			printf ("There is nothing to open to south\n");
	}

	if (dir == WEAST){
		if (player->current_room->door_weast){
			if (player->current_room->open_weast)
				printf ("The door is already opened\n");
			else{
				player->current_room->open_weast = true;
				player->current_room->weast_exit->open_east = true;
				printf ("The weast exit is opened\n");
			}
		}
		else
			printf ("There is nothing to open to weast\n");
	}

	if (dir == EAST){
		if (player->current_room->door_east){
			if (player->current_room->open_east)
				printf ("The door is already opened\n");
			else{
				player->current_room->open_east = true;
				player->current_room->east_exit->open_weast = true;
				printf ("The east exit is opened\n");
			}
		}
		else
			printf ("There is nothing to open to east\n");
	}

	if (dir == DOWN){
		if (player->current_room->door_down){
			if (player->current_room->open_down)
				printf ("The door is already opened\n");
			else{
				player->current_room->open_down = true;
				player->current_room->down_exit->open_down = true;
				printf ("The down exit is opened\n");
			}
		}
		else
			printf ("There is nothing to open below\n");
	}
}


//Close-door methods
//Same as the open methods but returning a false value
void World::close_exit(direction dir){
	if (dir == NORTH){
		if (player->current_room->door_north){
			if (player->current_room->open_north == false)
				printf ("The door is already closed\n");
			else{
				player->current_room->open_north = false;
				player->current_room->north_exit->open_south = false;
				printf ("The north exit is closed\n");
			}
		}
		else
			printf ("There is nothing to close to north\n");
	}
	if (dir == SOUTH){
		if (player->current_room->door_south){
			if (player->current_room->open_south == false)
				printf ("The door is already closed\n");
			else{
				player->current_room->open_south = false;
				player->current_room->south_exit->open_north = false;
				printf ("The south exit is closed\n");
			}
		}
		else
			printf ("There is nothing to close to south\n");
	}

	if (dir == WEAST){
		if (player->current_room->door_weast){
			if (player->current_room->open_weast == false)
				printf ("The door is already closed\n");
			else{
				player->current_room->open_weast = false;
				player->current_room->weast_exit->open_east = false;
				printf ("The weast exit is closed\n");
			}
		}
		else
			printf ("There is nothing to close to weast\n");
	}

	if (dir == EAST){
		if (player->current_room->door_east){
			if (player->current_room->open_east == false)
				printf ("The door is already closed\n");
			else{
				player->current_room->open_east = false;
				player->current_room->east_exit->open_weast = false;
				printf ("The east exit is closed\n");
			}
		}
		else
			printf ("There is nothing to close to east\n");
	}

	if (dir == DOWN){
		if (player->current_room->door_down){
			if (player->current_room->open_down == false)
				printf ("The door is already closed\n");
			else{
				player->current_room->open_down = false;
				player->current_room->down_exit->open_down = false;
				printf ("The down exit is closed\n");
			}
		}
		else
			printf ("There is nothing to close below\n");
	}
}