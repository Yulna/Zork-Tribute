#include "World.h"
#include "Globals.h"
#include <iostream>

#define CRT_SECURE_NO_WARNINGS

World::World(){
	player = new Player;
	Create_world();

};
World::~World(){
	delete player;
}

//Giving values and data to the difernt rooms
void World::Create_world(){
	


	Room* Park_Start = new Room("\nPARK", "A simple kids park, the perfect home for a homless person like you. \nYou see a library to the south, and regular house at the north.");
	Room* Kid_house = new Room("\nANNOYING KID HOUSE", "The place where that kid that never lets you take a nap lives. \nYou see a shop at the north and you're beatiful home (the park) at the south.");
	Room* Shop = new Room("\nREGULAR SHOP","A simple, regular, normal shop even the salesman is plain. \nAt least you can still buy some groceries, or steal them. \nYou see a normal house to south and a house with a strange aura to east.");
	Room* Gross_guy_house = new Room("\nGROSS CROSS-DRESSING GUY HOUSE","An overly decored house with a beatiful and sparkling garden.\nFor some reason can decide if the decoratoins give a femenine or masculine look.To south there is a scary and dark street, contrary to the east exit where you \ncan see a beatiful amusment park.");
	Room* Dark_street = new Room("\nDARK STREET", "The meeting place of all the gangs an delinquents of the town.\nIt will be better to go back an not disturb them too much.\nYou can go back at the werid house to north, there also seems to be a closed \nexit to south.");
	Room* Nrw_street = new Room("\nNARROW STREET", "You didn't even know that this street was in your town.\nIt's filled with empty bottles there's even one drunken man laying down on the floor, for some reason most of the bottles are piled up at the east side. It may be becasue the magnetic field of earth?\nThe only way out is going back at the dark street to north.");
	Room* Crush_house = new Room("\nCRUSH HOUSE", "Your personal sanctuary, you've dreamed so many times of coming here but never \nmustered enough courage to do it.\nAll but an oddly placed bush at the weast seems like heaven to you.\nThe only way out is at north to the amusment park.");
	Room* Amus_park = new Room("\nAMUSMENT PARK", "The average amusment park, full with young lovely-dovey couples. \nYou can sense a heavnly feeling coming from the south exit, at east you can findthe toilets if you need to use them.");
	Room* Toilet = new Room("\nPUBLIC TOILETS", "The stinky toilets from the park, one fo them is oddly out of place.\nYou can only go back to the park at weast.");
	Room* Library = new Room("\nLIBRARY", "An amaizingly quiet place, all filed with books and a few workaholics with piles of papers in their desks.\nYou can see a creppy guy sitting next to a broken tile or at least it seems so.\nThe only exits leads to the kids park at north.");


	
	//Park data
	Park_Start->Set_north_exit(Kid_house);
	Park_Start->Set_south_exit(Library);
	rooms.pushback(Park_Start);

	//Kid house data
	Kid_house->Set_north_exit(Shop);
	Kid_house->Set_south_exit(Park_Start);
	rooms.pushback(Kid_house);
	
	//Shop data
	Shop->Set_south_exit(Kid_house);
	Shop->Set_east_exit(Gross_guy_house);
	rooms.pushback(Shop);

	//Cross-dressing guy house data
	Gross_guy_house->Set_south_exit(Dark_street);
	Gross_guy_house->Set_weast_exit(Shop);
	Gross_guy_house->Set_east_exit(Amus_park);
	rooms.pushback(Gross_guy_house);

	//Dark street data
	Dark_street->Set_north_exit(Gross_guy_house);
	Dark_street->Set_south_exit(Nrw_street);
	Dark_street->Set_south_door(false);				//Send the state of the door false==door closed
	rooms.pushback(Dark_street);

	//Narrow street data
	Nrw_street->Set_north_exit(Dark_street);
	Nrw_street->Set_east_exit(Crush_house);
	Nrw_street->Set_north_door(false);
	Nrw_street->Set_east_door(false);
	rooms.pushback(Nrw_street);

	//Crush house data
	Crush_house->Set_north_exit(Amus_park);
	Crush_house->Set_weast_exit(Nrw_street);
	Crush_house->Set_weast_door(false);
	rooms.pushback(Crush_house);
	
	//Amusement park data 
	Amus_park->Set_south_exit(Crush_house);
	Amus_park->Set_weast_exit(Gross_guy_house);
	Amus_park->Set_east_exit(Toilet);
	rooms.pushback(Crush_house);

	//Toilets data 
	Toilet->Set_weast_exit(Amus_park);
	Toilet->Set_down_exit(Library);
	Toilet->Set_down_door(false);
	rooms.pushback(Toilet);

	//Library data
	Library->Set_north_exit(Park_Start);
	Library->Set_down_exit(Toilet);
	Library->Set_down_door(false);
	rooms.pushback(Library);
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