#ifndef __NPC_H__
#define __NPC_H__

#include "Creature.h"
#include "Room.h"

class Npc : public Creature
{
public:


public:
	Npc(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins);
	~Npc();

	void Talk();
};

#endif // !__NPC_H__
