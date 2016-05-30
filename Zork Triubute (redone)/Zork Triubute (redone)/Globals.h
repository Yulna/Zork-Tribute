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

#endif // !__GLOBALS_H__
