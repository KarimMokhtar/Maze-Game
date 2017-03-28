#ifndef AGENT_H_
#define AGENT_H_

#include <bits/stdc++.h>
#include "Room.h"
#include "Object.h"
#include "Props.h"

using namespace std;

class Agent
{
public:
	Agent();
    virtual~Agent()=0;
	string getName();
	void setDescription(string pDescription);
    string getDescription();
	string TypeCheck();
	virtual bool act() = 0;
    virtual Object *getWeapon () = 0 ;
    void setHealth(int h);
    int getHealth();
protected :
	Room *Current_room;
	Object *weapon;
	string Name,Type,Description;
    int health;
};

#endif
