#include "Item.h"

Item::Item(const char* name, const char* des, EntityType id, Entity* place) : Entity(name, des, id), actual_place(place){};

Item::~Item(){};

void Item::Setcontainer(bool state){
	container = state;
}