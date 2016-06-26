#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Creature.h"
#include "Room.h"



class Player : public Creature
{
public:


	//States, are in bool because you can have more than once active at time
	bool Yandere;
	bool Tsundere;
	bool Kuudere;
	bool Dendere;

public:
	Player(const char* name, const char* des, EntityType id, Room* startRoom, int life, uint coins);
	~Player();

	void Look();
	void IntenseLook();
	ExitState move(Direction dir);
	bool open(Direction dir);
	bool close(Direction dir);
	void ShowStats();

	

};


#endif // !__PLAYER_H__
