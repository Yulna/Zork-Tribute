#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Joan Pareja
//https://github.com/JoanPareja/Programacio-II.git

int main() {
	int i = 0;
	char option;
	house *room=(house*)malloc((sizeof(house))*5);
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
			printf("\n%s\n", ((room + i)->north));
			i = ((room + i)->rc_north);
			break;

		case 's':
			printf("\n%s\n", ((room + i)->south));
			i = ((room + i)->rc_south);
			break;

		case 'e':
			printf("\n%s\n", ((room + i)->east));
			i = ((room + i)->rc_east);
			break;

		case 'w':
			printf("\n%s\n", ((room + i)->west));
			i = ((room + i)->rc_west);
			break;

		case 'l':
			printf("\n%s\n", ((room + i)->name));
			break;

		default:
			printf("\nUse only the following keys: n/s/e/w/q\n");
			break;
		}
	} while (option != 'q');
	
	system("pause");
	return 0;
}