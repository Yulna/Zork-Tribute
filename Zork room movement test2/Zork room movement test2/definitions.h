#ifndef _ROOMS
#define _ROOMS

typedef struct{
	char name[30];
	int rc_north;
	int rc_east;
	int rc_south;
	int rc_west;
}house;

//void create_map(house *room);

#endif // !_ROOMS