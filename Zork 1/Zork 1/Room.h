#ifndef ROOM
#define ROOM

#include "Exit.h"
#include <string>

using namespace std;


class Room
{
public:
	string name;
	string description;
	Room* north_exit;
	Room* south_exit;
	Room* weast_exit;
	Room* east_exit;

	Room();
    ~Room();

private:

};

#endif // !ROOM