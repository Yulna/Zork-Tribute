#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum EntityType
{
	CREATURE,
	EXIT,
	ROOM,
	ITEM,
	PLAYER,
	NPC
};

enum CreatureType
{
	PC,
	KID,
	SELLER,
	PEDESTRIAN

};


enum UpdateState
{
	UPDATECONTINUE,
	UPDATEERROR,
	UPDATESTOP
};

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEAST,
	DOWN
};

enum ExitState{
	NOTHING,
	CLOSE,
	OPEN
};


typedef unsigned int uint;

#define DELAY 2000
#define COMMANDBUFFER 50
#define MAX_INVENTORY 3




#endif // !__GLOBALS_H__
