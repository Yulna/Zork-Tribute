#ifndef ROOM
#define ROOM

#include "Exit.h"
#include <string>

using namespace std;


class Room
{
public:
	string name="HABITACIO GUAI";
	string description;
	Exit* room_exits;


	//Room();
	//~Room();

private:

};

#endif // !ROOM