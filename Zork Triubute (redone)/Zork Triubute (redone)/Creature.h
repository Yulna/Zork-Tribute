#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "Entity.h"
#include "Globals.h"
#include "Room.h"

class Creature : public Entity
{
public:

	int life;
	uint coins;
	Room* currentRoom;

public:
	Creature(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins);
	~Creature();

	UpdateState Update();

};



#endif // !__CREATURE_H__
