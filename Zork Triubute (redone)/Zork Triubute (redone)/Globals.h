#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum EntityType
{
	CREATURE,
	EXIT,
	ROOM,
	ITEM
};


enum UpdateState
{
	UPDATECONTINUE,
	UPDATEERROR,
	UPDATESTOP
};

typedef unsigned int uint;

#define DELAY 2000
#define COMMANDBUFFER 50





#endif // !__GLOBALS_H__
