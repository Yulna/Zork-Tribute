#ifndef __ITEM_H__
#define __ITEM_H__

#include "Vector.h"
#include "Entity.h"
#include "Globals.h"

class Item : public Entity{
public:
	Entity* actual_place;

	bool container = false;
	bool equiped = false;

public:
	Item(const char* name, const char* des, EntityType id, Entity* place);
	~Item();

	void Setcontainer(bool state);

};

#endif // !__ITEM_H__