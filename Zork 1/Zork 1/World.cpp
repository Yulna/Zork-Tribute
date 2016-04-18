#include "World.h"


World::World(){
	player = new Player;
	Create_world();

};
World::~World(){
	for (int i = 0; i < rooms.size(); i++){
		delete rooms[i];
	}
	rooms.clean();
	for (int i = 0; i < items.size(); i++){
		delete items[i];
	}
	items.clean();
	delete player;
}

//Giving values and data to the difernt rooms
void World::Create_world(){
	


	Room* Park_Start = new Room("PARK", "A simple kids park, the perfect home for a homless person like you. \nYou see a library to the south, and regular house at the north.");
	Room* Kid_house = new Room("ANNOYING KID HOUSE", "The place where that kid that never lets you take a nap lives. \nYou see a shop at the north and you're beatiful home (the park) at the south.");
	Room* Shop = new Room("\nREGULAR SHOP","A simple, regular, normal shop even the salesman is plain. \nAt least you can still buy some groceries, or steal them. \nYou see a normal house to south and a house with a strange aura to east.");
	Room* Gross_guy_house = new Room("\nGROSS CROSS-DRESSING GUY HOUSE","An overly decored house with a beatiful and sparkling garden.\nFor some reason can decide if the decoratoins give a femenine or masculine look.To south there is a scary and dark street, contrary to the east exit where you \ncan see a beatiful amusment park.");
	Room* Dark_street = new Room("\nDARK STREET", "The meeting place of all the gangs an delinquents of the town.\nIt will be better to go back an not disturb them too much.\nYou can go back at the werid house to north, there also seems to be a closed \nexit to south.");
	Room* Nrw_street = new Room("\nNARROW STREET", "You didn't even know that this street was in your town.\nIt's filled with empty bottles there's even one drunken man laying down on the floor, for some reason most of the bottles are piled up at the east side. It may be becasue the magnetic field of earth?\nThe only way out is going back at the dark street to north.");
	Room* Crush_house = new Room("\nCRUSH HOUSE", "Your personal sanctuary, you've dreamed so many times of coming here but never \nmustered enough courage to do it.\nAll but an oddly placed bush at the weast seems like heaven to you.\nThe only way out is at north to the amusment park.");
	Room* Amus_park = new Room("\nAMUSMENT PARK", "The average amusment park, full with young lovely-dovey couples. \nYou can sense a heavnly feeling coming from the south exit, at east you can findthe toilets if you need to use them.");
	Room* Toilet = new Room("\nPUBLIC TOILETS", "The stinky toilets from the park, one fo them is oddly out of place.\nYou can only go back to the park at weast.");
	Room* Library = new Room("\nLIBRARY", "An amaizingly quiet place, all filed with books and a few workaholics with piles of papers in their desks.\nYou can see a creppy guy sitting next to a broken tile or at least it seems so.\nThe only exits leads to the kids park at north.");


	
	//Park data
	Park_Start->Set_north_exit(Kid_house); //kid_house
	Park_Start->Set_south_exit(Library); //Library
	rooms.pushback(Park_Start);
	
	//Kid house data
	Kid_house->Set_north_exit(Shop); //shop
	Kid_house->Set_south_exit(Park_Start);
	rooms.pushback(Kid_house);
	
	//Shop data
	Shop->Set_south_exit(Kid_house);
	Shop->Set_east_exit(Gross_guy_house);//Gross guy house
	rooms.pushback(Shop);

	
	//Cross-dressing guy house data
	Gross_guy_house->Set_south_exit(Dark_street); //dark street
	Gross_guy_house->Set_weast_exit(Shop);
	Gross_guy_house->Set_east_exit(Amus_park); //Amus park
	rooms.pushback(Gross_guy_house);

	
	//Dark street data
	Dark_street->Set_north_exit(Gross_guy_house);
	Dark_street->Set_south_exit(Nrw_street);	//nrw_street
	Dark_street->Set_south_door(false);				//Send the state of the door false==door closed
	rooms.pushback(Dark_street);
	
	//Narrow street data
	Nrw_street->Set_north_exit(Dark_street);
	Nrw_street->Set_east_exit(Crush_house); //crush
	Nrw_street->Set_north_door(false);
	Nrw_street->Set_east_door(false);
	rooms.pushback(Nrw_street);
	
	//Crush house data
	Crush_house->Set_north_exit(Amus_park); //amus
	Crush_house->Set_weast_exit(Nrw_street);
	Crush_house->Set_weast_door(false);
	rooms.pushback(Crush_house);
	
	//Amusement park data 
	Amus_park->Set_south_exit(Crush_house);
	Amus_park->Set_weast_exit(Gross_guy_house);
	Amus_park->Set_east_exit(Toilet); //toilet
	rooms.pushback(Amus_park);
	
	//Toilets data 
	Toilet->Set_weast_exit(Amus_park);//amus
	Toilet->Set_down_exit(Library); //library
	Toilet->Set_down_door(false);
	rooms.pushback(Toilet);
	
	//Library data
	Library->Set_north_exit(Park_Start);
	Library->Set_down_exit(Toilet);
	Library->Set_down_door(false);
	rooms.pushback(Library);
	


	//Item creation

	Item* Sacred_Panties = new Item("Sacred panties", "Your most valuable possession, it was stolen.");
	Sacred_Panties->set_place(Park_Start);
	items.pushback(Sacred_Panties);
}



//print the current room on the game
void World::print_room()const{
	printf("\n%s\n",player->current_room->name.get_str());
	printf("%s\n",player->current_room->description.get_str());
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


void World::Game_loop(){
		String comand;
		Vector<String> command_token;


		while (game_on){
			printf("\nWhat do you want to do?");

			comand.write_str();

			comand.tokenize(command_token);

			if (comand == "look" || command_token[0] == "l"){
				print_room();
			}


			//Clarified version of the help text.
			/*Comands accepted:
			Direction: north/south/east/weast/down (n/s/e/w/d)
			Direction can also be used by: go "direction"
			Current place data: look (l)
			Open doors: open "direction" where direction is north/south/east/weast/down
			Close doors: close "direction" where direction is north/south/east/weast/down
			End game: quit(q)*/

			else if (command_token[0] == ("help") || command_token[0] == "h"){
				printf("\nComands accepted:\n\nDirection: north/south/east/weast/down (n/s/e/w/d)\nDirection can also be used by: go \"direction\"\nCurrent place data: look (l)\nOpen doors: open \"direction\" where direction is north/south/east/weast/down\nClose doors: close \"direction\" where direction is north/south/east/weast/down\nEnd game: quit(q) \n\n");
			}

			//movement inputs
			else if (command_token[0] == "north" || command_token[0] == "n" || command_token[0] == "go north" || command_token[0] == "go n") {
				move(NORTH);
			}
			else if (command_token[0] == "south" || command_token[0] == "s" || command_token[0] == "go south" || command_token[0] == "go s"){
				move(SOUTH);
			}
			else if (command_token[0] == "weast" || command_token[0] == "w" || command_token[0] == "go weast" || command_token[0] == "go w"){
				move(WEAST);
			}
			else if (command_token[0] == "east" || command_token[0] == "e" || command_token[0] == "go east" || command_token[0] == "go e"){
				move(EAST);
			}
			else if (command_token[0] == "down" || command_token[0] == "d" || command_token[0] == "go down" || command_token[0] == "go d"){
				move(DOWN);
			}
			else if (command_token[0] == "go"){
				printf("You must say a direction (north/south/weast/east).\nUse \"h\" or \"help\" to see all available commands\n");
			}

			//Open doors input
			else if (command_token[0] == "open north" || command_token[0] == "o n" || command_token[0] == "open n"){
				open_exit(NORTH);
			}
			else if (command_token[0] == "open south" || command_token[0] == "o s" || command_token[0] == "open s"){
				open_exit(SOUTH);
			}
			else if (command_token[0] == "open weast" || command_token[0] == "o w" || command_token[0] == "open w"){
				open_exit(WEAST);
			}
			else if (command_token[0] == "open east" || command_token[0] == "o e" || command_token[0] == "open e"){
				open_exit(EAST);
			}
			else if (command_token[0] == "open down" || command_token[0] == "o d" || command_token[0] == "open d"){
				open_exit(DOWN);
			}
			else if (command_token[0] == "open all"){ //open all doors of the room
				open_exit(NORTH);
				open_exit(SOUTH);
				open_exit(WEAST);
				open_exit(EAST);
				open_exit(DOWN);
			}

			else if (command_token[0] == "open"){
				printf("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available commands\n");
			}


			//Closing doors input
			//Only already existing doors can be closed
			else if (command_token[0] == "close north" || command_token[0] == "c n" || command_token[0] == "close n"){
				close_exit(NORTH);
			}
			else if (command_token[0] == "close south" || command_token[0] == "c s" || command_token[0] == "close s"){
				close_exit(SOUTH);
			}
			else if (command_token[0] == "close weast" || command_token[0] == "c w" || command_token[0] == "close w"){
				close_exit(WEAST);
			}
			else if (command_token[0] == "close east" || command_token[0] == "c e" || command_token[0] == "close e"){
				close_exit(EAST);
			}
			else if (command_token[0] == "close down" || command_token[0] == "c d" || command_token[0] == "close d"){
				close_exit(DOWN);
			}
			else if (command_token[0] == "close all"){ //close all doors of the room
				close_exit(NORTH);
				close_exit(SOUTH);
				close_exit(WEAST);
				close_exit(EAST);
				close_exit(DOWN);
			}
			else if (command_token[0] == "close"){
				printf("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available commands\n");
			}



			//picking items
			else if (comand == "pick"){
				printf("\nWhich item?");
				comand.write_str();
				if (player->max_inv < MAX_INVETORY){
					for (int i = 0; i < items.size(); i++){
						if (items[i]->name == comand.get_str()){
							if (items[i]->actual_place == player->current_room){
								items[i]->actual_place = player;
								printf("You put the %s into your inventory", items[i]->name);
								player->max_inv++;
							}
							else
								printf("There isn't such item in this room.");
						}
					}
				}
				else
					printf("Your inventory is full.");
			}


			//drop items
			else if (comand == "drop"){
				printf("Which item?");
				comand.write_str();
				for (int i = 0; i < items.size(); i++){
					if (items[i]->name == comand.get_str()){
						if (items[i]->actual_place == player&&items[i]->equiped == false){
							items[i]->actual_place = player->current_room;
							printf("You droped the %s.", items[i]->name);
							player->max_inv--;
						}
						else
							printf("You don't have that item in your inventory");
					}
				}
			}

			//Show inventory
			else if (comand == "inventory" || comand == "inv" || comand == "i"){
				printf("You have this items in your inventory:\n");
				for (int i = 0; i < items.size(); i++)
				{
					if (items[i]->actual_place == player&&items[i]->equiped == false)
						printf("   %s\n", items[i]->name);
				}
			}

			//equip item
			else if (comand == "equip"){
				if (player->item_equiped != true){
					printf("Which item?");
					comand.write_str();
					for (int i = 0; i < items.size(); i++){
						if (items[i]->name == comand.get_str()){
							if (items[i]->actual_place == player){
								if (items[i]->equiped == false){
									items[i]->equiped = true;
									printf("You equiped the %s.", items[i]->name);
									player->max_inv--;
								}
								else
									printf("You already have equipped it.");
							}
							else
								printf("You don't have that item in your inventory.");
						}
					}
				}
				else
					printf("You already have an item esuipped");
			}


			//unequip item
			else if (comand == "unequip"){
				if (player->item_equiped == true){
					printf("Which item?");
					comand.write_str();
					for (int i = 0; i < items.size(); i++){
						if (items[i]->name == comand.get_str()){
							if (items[i]->actual_place == player){
								if (items[i]->equiped == true){
									items[i]->equiped = false;
									printf("You unequiped the %s.", items[i]->name);
									player->max_inv--;
								}
								else
									printf("You don't have this item euipped.");
							}
							else
								printf("You don't have that item in your inventory.");
						}
					}
				}
				else
					printf("You don't have anything equipped to unequip.");
			}


			//stats
			else if (comand == "stats"){
				printf("Yulna's stats:\n");
				if (player->state == Yandere || player->state == All_dere)
					printf("\nYou feel the Yandere power spreading through your veins.");
				if (player->state == Tsundere || player->state == All_dere)
					printf("\nYou feel the Tsundere power spreading through your veins.");
				if (player->state == Kuudere || player->state == All_dere)
					printf("\nYou feel the Kuudere power spreading through your veins.");
				if (player->state == Dendere || player->state == All_dere)
					printf("\nYou feel the Dendere power spreading through your veins.");
			}
			

						

			//Quitting the game
			else if (comand == "quit" || comand == "q")
				game_on = false;
			
			//Error input mesage
			else
				printf("Invalid comand. Use \"h\" or \"help\" to see all available commands\n");


			//Changing player stats depending on items equiped
			for (int i = 0; i < items.size(); i++){
				if (items[i]->name == "Sacred panties"&& items[i]->equiped == true)
					player->state = All_dere;
					
				//Yandere -> Pice of sandwich
				//Tsundere -> Used tissue
				//Dendere ->Crush diary
				//Kudere -> Pile of books
			
			}

			command_token.clean();
	}	//while end
};
