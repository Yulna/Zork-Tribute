#ifndef _ROOMS
#define _ROOMS

typedef struct{
	char name[30];
	char north[30];
	int rc_north;
	char east[30];
	int rc_east;
	char south[30];
	int rc_south;
	char west[30];
	int rc_west;
}house;

void create_map(house *room);

#endif // !_ROOMS




