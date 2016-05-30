#include "Exit.h"

//No door contructor (Always opened)
Exit::Exit(const char* name, const char* des, EntityType id, Direction dir, Room* src, Room* destination) : Entity(name, des, id), dir(dir), src(src), destination(destination){
	state = OPEN;
};

//Doors constructor
Exit::Exit(const char* name, const char* des, EntityType id, Direction dir, Room* src, Room* destination, bool door, ExitState state) : Entity(name, des, id), dir(dir), src(src), destination(destination), door(door), state(state){
};
