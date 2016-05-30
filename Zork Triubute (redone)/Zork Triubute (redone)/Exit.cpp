#include "Exit.h"

Exit::Exit(const char* name, const char* des, EntityType id, Direction dir, Room* src, Room* destination) : Entity(name, des, id), dir(dir), src(src), destination(destination){
};
