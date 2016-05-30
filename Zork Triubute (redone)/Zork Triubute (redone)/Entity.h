#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "My_String.h"
#include "Globals.h"



class Entity
{
public:
	EntityType id;
	String name;
	String description;


public:
	Entity();
	Entity(const char* name, const char* des, EntityType id);
	~Entity();

	virtual UpdateState Update(){ return UpdateState::UPDATECONTINUE; }

};




#endif // !__ENTITY_H__
