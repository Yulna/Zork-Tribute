#ifndef __WORLD_H__
#define __WORLD_H__

#include "Globals.h"
#include "Vector.h"
#include "My_String.h"
#include "Entity.h"
#include "Player.h"



class World
{
public:
	Player* player;
	Vector<Entity*> entities;
	uint currentTime;
	uint initialTime;
	char command[COMMANDBUFFER];
	uint commandPos;


public:
	World();
	~World();

	bool Game_on();

	bool ReadCommand(char* str);
	
};

extern World* NewWorld;
#endif // !__WORLD_H__
