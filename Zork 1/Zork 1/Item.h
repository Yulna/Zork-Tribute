#ifndef __ITEM_H__
#define __ITEM_H__

#include "Vector.h"
#include "Entity.h"

class Item : public Entity{
public:
	Entity* actual_place;
	bool container = false;
	bool equiped = false;

public:
	Item(const char* name, const char* des, Entity* place) : Entity(name, des){
		actual_place = place;
	};
	
};

#endif // !__ITEM_H__
