#ifndef __WORLD_H__
#define __WORLD_H__

#include "Globals.h"
#include "Vector.h"
#include "Entity.h"
#include "Room.h"
#include "Creature.h"



class World
{
public:
	
	Vector<Entity*> entities;

public:
	World();
	~World();

	bool Game_on();

};




#endif // !__WORLD_H__
