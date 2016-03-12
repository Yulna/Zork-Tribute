#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <string.h>
#include <stdio.h>


void create_map(house *room) {
	int i;
	
	enum housemap{dining_room=0, kitchen, pantry, bedroom, bathroom, wall};

	i = dining_room; 
	strcpy(((room+i)->name), "Dining room");
	
	(room + i)->rc_north = kitchen;
	(room + i)->rc_south = bedroom;
	(room + i)->rc_east = bathroom;
	(room + i)->rc_west = dining_room;


	i = kitchen; 
	strcpy(((room + i)->name), "Kitchen");
	(room + i)->rc_north = kitchen;
	(room + i)->rc_south = dining_room;
	(room + i)->rc_east = pantry;
	(room + i)->rc_west = kitchen;


	i = pantry; 
	strcpy(((room + i)->name), "Pantry");
	(room + i)->rc_north = pantry;
	(room + i)->rc_south = pantry;
	(room + i)->rc_east = pantry;
	(room + i)->rc_west = kitchen;


	i = bedroom; 
	strcpy(((room + i)->name), "Bedroom");
	(room + i)->rc_north = dining_room;
	(room + i)->rc_south = bedroom;
	(room + i)->rc_east = bedroom;
	(room + i)->rc_west = bedroom;


	i = bathroom; 
	strcpy(((room + i)->name), "Bathroom");
	(room + i)->rc_north = wall;
	(room + i)->rc_south = wall;
	(room + i)->rc_east = dining_room;
	(room + i)->rc_west = wall;
}