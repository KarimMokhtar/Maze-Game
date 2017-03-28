#ifndef PLAYER_H_
#define PLAYER_H_

#include <bits/stdc++.h>
#include "Agent.h"
#include "room.h"
#include "Key.h"
#include "Object.h"
#include "FixedObject.h"

class Player : public Agent
{
public:
	Player();
	~Player();
	Player(string Pname, Room *Starting_room);

    void Pick(Object *obj);

    void printobjecct();
    bool Choose();
    Object *Drop(string name);
	bool act();
	props * getWeapon () ;
private:
    Object *Obj[5];
};

#endif
/*لو فى موونستر و لاعب فى نفس الاوضه هنقص من هلس الاعب 20 ولو الاعب معاه السلاح الى بيصد الوحش خلاص
هنستخدم getoccuoants ()-> room ;
getprop -> monster

healing 20 on ground
healing 50 in box*/

