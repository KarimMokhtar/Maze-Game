#include "Agent.h"
#include <bits/stdc++.h>

Agent::Agent()
{
    Name="None";
    Current_room=NULL;
    Description ="none" ;
    weapon =NULL ;
    health = 100 ;

}
string Agent::getName()
{
    return Name;
}
string Agent::TypeCheck()
{
    return Type;
}
bool Agent::act()
{
    return 0;
}
void Agent::setDescription(string pDescription)
{
    Description=pDescription ;
}
string Agent::getDescription()
{
    return Description;
}

Object * getWeapon ()
{

}
void Agent::setHealth(int h)
{
    health=h;
}
int Agent::getHealth()
{
    return health;
}
Agent::~Agent(){
}
