#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <string.h>
#include <stdio.h>


void create_map(house *room) {
	int i;
	
	enum housemap{dining_room=0, kitchen, pantry, bedroom, bathroom	};

	i = dining_room; 
	strcpy(((room+i)->name), "Dining room");
	strcpy(((room + i)->north), "Kitchen");
	(room + i)->rc_north = kitchen;
	strcpy(((room + i)->south), "Bedroom");
	(room + i)->rc_south = bedroom;
	strcpy(((room + i)->east), "Bathroom");
	(room + i)->rc_east = bathroom;
	strcpy(((room + i)->west), "You can't go there.");
	(room + i)->rc_west = dining_room;


	i = kitchen; 
	strcpy(((room + i)->name), "Kitchen");
	strcpy(((room + i)->north), "You can't go there.");
	(room + i)->rc_north = kitchen;
	strcpy(((room + i)->south), "Dining room");
	(room + i)->rc_south = dining_room;
	strcpy(((room + i)->east), "Pantry");
	(room + i)->rc_east = pantry;
	strcpy(((room + i)->west), "You can't go there.");
	(room + i)->rc_west = kitchen;


	i = pantry; 
	strcpy(((room + i)->name), "Pantry");
	strcpy(((room + i)->north), "You can't go there.");
	(room + i)->rc_north = pantry;
	strcpy(((room + i)->south), "You can't go there.");
	(room + i)->rc_south = pantry;
	strcpy(((room + i)->east), "You can't go there.");
	(room + i)->rc_east = pantry;
	strcpy(((room + i)->west), "Kitchen");
	(room + i)->rc_west = kitchen;


	i = bedroom; 
	strcpy(((room + i)->name), "Bedroom");
	strcpy(((room + i)->north), "Dining room");
	(room + i)->rc_north = dining_room;
	strcpy(((room + i)->south), "You can't go there.");
	(room + i)->rc_south = bedroom;
	strcpy(((room + i)->east), "You can't go there.");
	(room + i)->rc_east = bedroom;
	strcpy(((room + i)->west), "You can't go there.");
	(room + i)->rc_west = bedroom;


	i = bathroom; 
	strcpy(((room + i)->name), "Bathroom");
	strcpy(((room + i)->north), "You can't go there.");
	(room + i)->rc_north = bathroom;
	strcpy(((room + i)->south), "You can't go there.");
	(room + i)->rc_south = bathroom;
	strcpy(((room + i)->east), "Dining room");
	(room + i)->rc_east = dining_room;
	strcpy(((room + i)->west), "You can't go there.");
	(room + i)->rc_west = bathroom;
}