#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "Entity.h"
#include "Globals.h"

class Creature : public Entity
{
public:



public:
	Creature(const char* name, const char* des, EntityType id);
	~Creature();

	UpdateState Update();

};



#endif // !__CREATURE_H__
