#ifndef __ROOM_H__
#define __ROOM_H__

#include "Entity.h"

class Room : public Entity
{


public:
	Room(const char* name, const char* des, EntityType id);
	~Room();

};



#endif // !__ROOM_H__
