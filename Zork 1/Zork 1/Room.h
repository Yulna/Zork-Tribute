#ifndef ROOM
#define ROOM

#include <string>

using namespace std;


class Room
{
public:
	char name[35];
	char description[500];

	Room* north_exit;
	Room* south_exit;
	Room* weast_exit;
	Room* east_exit;
	Room* down_exit;
	bool open_north;
	bool open_south;
	bool open_east;
	bool open_weast;
	bool open_down;


	Room();
    ~Room();

private:

};

#endif // !ROOM