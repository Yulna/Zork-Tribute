#ifndef __WORLD_H__
#define __WORLD_H__

#include "Globals.h"
#include "Vector.h"
#include "Entity.h"
#include "Room.h"
#include "Creature.h"
#include "My_String.h"



class World
{
public:
	
	Vector<Entity*> entities;
	uint currentTime;
	uint initialTime;
	char command[COMMANDBUFFER];
	uint commandPos;


public:
	World();
	~World();

	bool Game_on();

	void ReadCommand(char* str);
	
};




#endif // !__WORLD_H__
