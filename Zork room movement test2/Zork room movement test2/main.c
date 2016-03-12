#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

//Joan Pareja
//https://github.com/JoanPareja/Programacio-II.git

int main() {
	int i = 0;
	char option;
	enum housemap{ dining_room = 0, kitchen, pantry, bedroom, bathroom, wall };

	house *room = (house*)malloc((sizeof(house)) * 5);
	if (room == 0) {
		printf("Error\n");
		exit(0);
	}
	create_map(room);

	printf("Use the keys (n/s/e/w) for directions, (l) to look at which room you are\nand (q) to quit.\n");

	do{
		
		printf("Where you want to go?");
		fflush(stdin);
		scanf_s("%c", &option);
		switch (option){
		case 'n':
			if (room->rc_north == wall)
				printf("You can't go there\n");
			else{
			i = ((room + i)->rc_north);
			printf("\n%s\n", ((room + i)->name));
			}
			break;

		case 's':
			if (room->rc_south == wall)
				printf("You can't go there\n");			
			else{
				i = ((room + i)->rc_south);
				printf("\n%s\n", ((room + i)->name));		
			}
			break;

		case 'e':
			if (room->rc_east == wall)
				printf("You can't go there\n");
			else {
				i = ((room + i)->rc_east);
				printf("\n%s\n", ((room + i)->name));
			}
			break;

		case 'w':
			if (room->rc_west == wall)
				printf("You can't go there\n");
			else {
				i = ((room + i)->rc_west);
				printf("\n%s\n", ((room + i)->name));
			}
			break;

		case 'l':
			printf("\n%s\n", ((room + i)->name));
			break;

		default:
			printf("\nUse only the following keys: n/s/e/w/l/q\n");
			break;
		}
	} while (option != 'q');

	system("pause");
	return 0;
}