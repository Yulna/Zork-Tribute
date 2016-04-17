#ifndef __Entity_H__
#define __Entity_H__

#include "My_String.h"

class Entity
{
public:
	String name;
	String description;

	//Make the list of other entitys it contains
	//Vector to other entities

public:
	Entity(){};
	Entity(const char* name, const char* des) : name(name), description(des)
	{};
	~Entity(){};

};

#endif // !__Entity_H__