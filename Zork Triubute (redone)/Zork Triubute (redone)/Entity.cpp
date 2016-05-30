
#include "Entity.h"

Entity::Entity(){}

Entity::Entity(const char* name, const char* des, EntityType id) : name(name), description(des), id(id) {};

Entity::~Entity(){};
