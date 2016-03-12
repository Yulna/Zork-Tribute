#include "World.h"

World::World(){
	rooms = new Room[10];
};

World::~World(){
	delete[] rooms;
}