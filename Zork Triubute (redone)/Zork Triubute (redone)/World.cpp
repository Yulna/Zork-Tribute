#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <Windows.h>

#include "World.h"
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Creature.h"
#include "Item.h"
#include "NPC.h"
#include "Seller.h"




World::World(){
	currentTime = 0;
	initialTime = 0;

	//Rooms
	Room* parkStart = new Room("Room 1", "the park gonna be", ROOM);
	Room* Room2 = new Room("Room 2", "secon room", ROOM);
	Room* Room3 = new Room("Room 3", "3 room", ROOM);


	entities.pushback(parkStart);
	entities.pushback(Room2);
	entities.pushback(Room3);


	//Exits
	Exit* north = new Exit("north", "north exit", EXIT, NORTH, parkStart, Room2);
	Exit* south = new Exit("south", "south exit", EXIT, SOUTH, Room2, parkStart);
	Exit* down = new Exit("down", "down exit", EXIT, DOWN, Room2, Room3, true, CLOSE);
	entities.pushback(north);
	entities.pushback(south);
	entities.pushback(down);

	//Creatures
	player = new Player("Yulna", "The pervert", PLAYER, parkStart, 50, 78);
	Npc* test = new Npc("Creature1", "a creature", NPC, Room2, 10, 20);
	Seller* shopguy = new Seller("Seller", "Sells things", NPC, parkStart, 10, 20);
	entities.pushback(test);
	entities.pushback(player);
	entities.pushback(shopguy);


	//Items
	Item* panties = new Item("Panties", "Weapon for Panty", ITEM, Room2);
	Item* Stockings = new Item("Stockings", "Weapon for stockings", ITEM, parkStart);
	Item* Bag = new Item("Bag", "Put stuff in it", ITEM, Room3);
	Bag->Setcontainer(true);
	entities.pushback(panties);
	entities.pushback(Stockings);
	entities.pushback(Bag);
	
}

World::~World(){
	for (int i = 0; i < entities.size(); i++){
		delete entities[i];
	}
	entities.clean();
}


bool World::Game_on(){
	UpdateState game_update;

	
	
	currentTime = GetTickCount();
	if (currentTime > (initialTime + DELAY)){

		//Entities Update-------------------------------------------------
		for (int i = 0; i < entities.size(); i++){
			game_update = entities[i]->Update();

			if (game_update == UPDATESTOP)
				return false;

			if (game_update == UPDATEERROR){
				printf("\nThe game has to close due to an error.");
				getchar();
				return false;
			}
		}
		initialTime = currentTime;
	}


	if (_kbhit()){

		if (commandPos < (COMMANDBUFFER - 2)){
			command[commandPos] = _getch();

			//Erasing functionality
			if (command[commandPos] == '\b' && commandPos>0){
				commandPos--;
				command[commandPos] = '\0';
			}
			else{
				command[commandPos + 1] = '\0';
				commandPos++;
			}
			
			//Cleaning screen and showing the current command
			system("cls");
			printf("%s\n", command);

			//Reseting the command and sending it when pressing Enter
			if (command[commandPos - 1] == '\r'){
				printf("Your command is: %s\n", command);
				command[commandPos-1] = '\0';
				commandPos = 0;
				if(!ReadCommand(command))
					return false;
				
			}

		}
		
		else{
			command[COMMANDBUFFER - 1] = '\0';
			printf("Your command is: %s\n", command);
			command[commandPos - 1] = '\0';
			commandPos = 0;
			if (!ReadCommand(command))
				return false;
		}
	}



	return true;
}


bool World::ReadCommand(char* str){
	String command(str);
	Vector<String> command_token;

	if (command.lenght() >= 1){
		command.tokenize(command_token);

		if (command_token[0] == "help" || command_token[0] == "h"){
			printf("I'm helping.");
		}

		else if (command_token[0] == "look" || command_token[0] == "l"){
			player->IntenseLook();
		}

		//Movement --------
		else if (command_token[0] == "north" || command_token[0] == "n" || (command_token[0] == "go" && command_token[1] == "north") || (command_token[0] == "go" && command_token[1] == "n")) {
			if (player->move(NORTH)==OPEN)
				player->Look();
			else if (player->move(NORTH) == CLOSE){
				printf("The exit is closed.");
			}
			else
				printf("There's nothing in that direction.");
		}
		else if (command_token[0] == "south" || command_token[0] == "s" || (command_token[0] == "go" && command_token[1] == "south") || (command_token[0] == "go" && command_token[1] == "s")) {
			if (player->move(SOUTH) == OPEN)
				player->Look();
			else if (player->move(SOUTH) == CLOSE){
				printf("The exit is closed.");
			}
			else
				printf("There's nothing in that direction.");
		}
		else if (command_token[0] == "east" || command_token[0] == "e" || (command_token[0] == "go" && command_token[1] == "east") || (command_token[0] == "go" && command_token[1] == "e")) {
			if (player->move(EAST) == OPEN)
				player->Look();
			else if (player->move(EAST) == CLOSE){
				printf("The exit is closed.");
			}
			else
				printf("There's nothing in that direction.");
		}
		else if (command_token[0] == "weast" || command_token[0] == "w" || (command_token[0] == "go" && command_token[1] == "weast") || (command_token[0] == "go" && command_token[1] == "w")) {
			if (player->move(WEAST) == OPEN)
				player->Look();
			else if (player->move(WEAST) == CLOSE){
				printf("The exit is closed.");
			}
			else
				printf("There's nothing in that direction.");
		}
		else if (command_token[0] == "down" || command_token[0] == "d" || (command_token[0] == "go" && command_token[1] == "down") || (command_token[0] == "go" && command_token[1] == "d")) {
			if (player->move(DOWN) == OPEN)
				player->Look();
			else if (player->move(DOWN) == CLOSE){
				printf("The exit is closed.");
			}
			else
				printf("There's nothing in that direction.");
		}


		//opening exits
		else if (command_token[0] == "open" || command_token[0] == "o"){
			if (command_token[1] == "north" || command_token[1] == "n"){
				player->open(NORTH);
			}
			else if (command_token[1] == "south" || command_token[1] == "s"){
				player->open(SOUTH);
			}
			else if (command_token[1] == "weast" || command_token[1] == "w"){
				player->open(WEAST);
			}
			else if (command_token[1] == "east" || command_token[1] == "e"){
				player->open(EAST);
			}
			else if (command_token[1] == "down" || command_token[1] == "d"){
				player->open(DOWN);
			}
			
			else{
				printf("You must say a direction(north/south/east/weast). \nUse \"h\" or \"help\" to see all available commands\n");
			}
		}


		//closing exits
		else if (command_token[0] == "close" || command_token[0] == "c"){
			if (command_token[1] == "north" || command_token[1] == "n"){
				player->close(NORTH);
			}
			else if (command_token[1] == "south" || command_token[1] == "s"){
				player->close(SOUTH);
			}
			else if (command_token[1] == "weast" || command_token[1] == "w"){
				player->close(WEAST);
			}
			else if (command_token[1] == "east" || command_token[1] == "e"){
				player->close(EAST);
			}
			else if (command_token[1] == "down" || command_token[1] == "d"){
				player->close(DOWN);
			}
			else if (command_token[0] == "close"){
				printf("You must say a direction(north/south/east/weast. \nUse \"h\" or \"help\" to see all available commands\n");
			}
		}

		//Show inventory
		else if (command_token[0] == "inventory" || command_token[0] == "inv" || command_token[0] == "i"){
			printf("You have this items in your inventory:\n");
			for (int i = 0; i < entities.size(); i++)
			{
				if (((Item*)NewWorld->entities[i])->actual_place == player && ((Item*)NewWorld->entities[i])->equiped == false){
					printf("   %s:", ((Item*)NewWorld->entities[i])->name);
					printf(" %s\n", ((Item*)NewWorld->entities[i])->description);
				}
			}

			for (int i = 0; i < entities.size(); i++)
			{
				if (((Item*)NewWorld->entities[i])->actual_place == player && ((Item*)NewWorld->entities[i])->equiped == true)
					printf("You have  %s equiped\n", ((Item*)NewWorld->entities[i])->name);
			}
		}



		//Pick items
		else if (command_token[0] == "pick"){

			if (player->used_inv < MAX_INVENTORY){
				for (int i = 0; i < entities.size(); i++){
					if (entities[i]->id == ITEM && entities[i]->name == command_token[1]){
						if (((Item*)NewWorld->entities[i])->actual_place == player->currentRoom){
							((Item*)NewWorld->entities[i])->actual_place = player;
							printf("You put the %s into your inventory", entities[i]->name.get_str());
							player->used_inv++;
						}
						else
							printf("There isn't such item in this room.");
					}
				}
			}
			else
				printf("Your inventory is full.");
		}


		//Drop items
		else if (command_token[0] == "drop"){
			for (int i = 0; i < entities.size(); i++){
				if (entities[i]->id == ITEM && ((Item*)NewWorld->entities[i])->name == command_token[1]){
					if (((Item*)NewWorld->entities[i])->actual_place == player && ((Item*)NewWorld->entities[i])->equiped == false){
						((Item*)NewWorld->entities[i])->actual_place = player->currentRoom;
						printf("You droped the %s.", ((Item*)NewWorld->entities[i])->name);
						player->used_inv--;
					}
					else
						printf("You don't have that item in your inventory");
				}
			}
		}


		//Equip item
		else if (command_token[0] == "equip"){
			if (player->item_equiped != true){
				for (int i = 0; i < entities.size(); i++){
					if (entities[i]->id == ITEM && entities[i]->name == command_token[1]){
						if (((Item*)NewWorld->entities[i])->actual_place == player){
							if (((Item*)NewWorld->entities[i])->equiped == false){
								((Item*)NewWorld->entities[i])->equiped = true;
								player->item_equiped = true;
								printf("You equiped the %s.", ((Item*)NewWorld->entities[i])->name.get_str());
								player->used_inv--;
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
				printf("You already have an item equipped");
		}


		//Unequip items
		else if (command_token[0] == "unequip"){
			if (player->item_equiped == true && player->used_inv < MAX_INVENTORY){
				for (int i = 0; i < entities.size(); i++){
					if (entities[i]->id == ITEM && entities[i]->name == command_token[1]){
						if (((Item*)NewWorld->entities[i])->actual_place == player){
							if (((Item*)NewWorld->entities[i])->equiped == true){
								((Item*)NewWorld->entities[i])->equiped = false;
								player->item_equiped = false;
								printf("You unequiped the %s.", ((Item*)NewWorld->entities[i])->name.get_str());
								player->used_inv++;
							}
							else
								printf("You don't have this item equipped.");
						}
						else
							printf("You don't have that item in your inventory.");
					}
				}
			}
			else
				printf("You can't do that.");
		}

		//Put item into item
		else if (command_token[0] == "put"&&command_token[2] == "into"){
			int i, j;
			bool success = false;
			for (i = 0; i < entities.size(); i++){
				if (entities[i]->id == ITEM && ((Item*)NewWorld->entities[i])->container&&command_token[3] == ((Item*)NewWorld->entities[i])->name && ((Item*)NewWorld->entities[i])->actual_place == player){
					for (j = 0; j < entities.size(); j++){
						if (entities[i]->id == ITEM &&entities[j]->name == command_token[1] && ((Item*)NewWorld->entities[j])->actual_place == player){
							((Item*)NewWorld->entities[j])->actual_place = entities[i];
							printf("You put %s", entities[j]->name);
							printf(" into %s.", entities[i]->name);
							player->used_inv--;
							success = true;
						}
					}
				}
			}
			if (success == false)
				printf("You can't do that.");
		}


		//Get item from
		else if (command_token[0] == "get"&&command_token[2] == "from"){
			int i, j;
			bool success = false;
			if (player->used_inv < MAX_INVENTORY){
				for (i = 0; i < entities.size(); i++){
					if (entities[i]->id == ITEM && ((Item*)NewWorld->entities[i])->container&&command_token[3] == ((Item*)NewWorld->entities[i])->name && ((Item*)NewWorld->entities[i])->actual_place == player){
						for (j = 0; j < entities.size(); j++){
							if (entities[i]->id == ITEM && ((Item*)NewWorld->entities[j])->name == command_token[1] && ((Item*)NewWorld->entities[j])->actual_place == entities[i]){
								((Item*)NewWorld->entities[j])->actual_place = player;
								printf("You got %s", entities[j]->name);
								printf(" from %s.", entities[i]->name);
								player->used_inv++;
								success = true;
							}
						}
					}
				}
			}
			if (success == false)
				printf("You can't do that.");
		}


		//Show stats
		else if (command_token[0] == "stats"){
			printf("Yulna's stats:\n");
			player->ShowStats();
		}


		//"Talk"--> Show description and clues about the game
		else if (command_token[0] == "talk"){
			bool success = false;
			for (int i = 0; i < entities.size(); i++){
				if (entities[i]->id == NPC && entities[i]->name == command_token[1]){
					system("cls");
					((Npc*)entities[i])->Talk();
					success = true;
				}
			}
			if (!success){
				printf("You can't do that.");
			}
		}


		//End game
		else if (command_token[0] == "quit" || command_token[0] == "q"){
			return false;
		}

		//Error input message
		else
			printf("Invalid comand. Use \"h\" or \"help\" to see all available commands\n");
	}

	return true;
}