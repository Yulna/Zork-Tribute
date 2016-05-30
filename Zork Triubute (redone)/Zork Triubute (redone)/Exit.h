#ifndef __EXIT_H__
#define __EXIT_H__

#include "Entity.h"
#include "Room.h"
#include "Globals.h"

class Exit : public Entity
{
public:
	Direction dir;
	Room* src;
	Room* destination;
	bool door;
	ExitState state;

public:
	Exit(const char* name, const char* des, EntityType id, Direction dir, Room* src, Room* destination);
	Exit(const char* name, const char* des, EntityType id, Direction dir, Room* src, Room* destination,bool door, ExitState state);
	~Exit();
};

#endif // !__EXIT_H__
