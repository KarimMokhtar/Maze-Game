#ifndef MONSTER_H_
#define MONSTER_H_

#include <bits/stdc++.h>
#include "Agent.h"
#include "Room.h"
#include "Object.h"
#include "props.h"
class Monster : public Agent
{
public:
	Monster();
	~Monster();
	Monster(string Name, Room *Starting_room, Object *obj);
	bool act();
	void setWeapon (Object *obj) ;
    int BFS(Room *curRoom);
	Object * getWeapon () ;
private:


};

#endif
