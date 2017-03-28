#include <bits/stdc++.h>
#include "Room.h"
#include "Agent.h"
#include "Object.h"
#include "Key.h"
#include "Chest.h"
#include "Monster.h"
using namespace std;

Room::Room()
{
	Name="None";
	Description="None";
	directions["north"]=directions["south"]=directions["west"]=directions["east"]=NULL;

}
Room::Room(string pName,string pDescription)
{
	Name=pName;
    Description=pDescription;
    directions["north"]=directions["south"]=directions["west"]=directions["east"]=NULL;
}


string Room::getName() //  fun to get the name of the room
{
		return Name;
}

string Room::getDescription() // fun to get the description of the room
{
		return Description;
}



void Room::Link(Room *roomobj,string Direction) // function that help us to link to room together
{
    directions[Direction]=roomobj;
    if(Direction == "north")roomobj->directions["south"]=this;
    if(Direction == "south")roomobj->directions["north"]=this;
    if(Direction == "east")roomobj->directions["west"]=this;
    if(Direction == "west")roomobj->directions["east"]=this;
}

Room *Room::getLinked(string Direction) // fun to go to the room in  x direction
{
		return directions[Direction];
}
void Room::printLinked()
{
	if(directions["north"]!=NULL)
    {
        cout << "north -> " << directions["north"]->getName() <<endl;
    }
    if(directions["south"]!=NULL)
    {
        cout << "south -> " << directions["south"]->getName()<< endl;
    }
    if(directions["east"]!=NULL)
    {
        cout << "east -> " << directions["east"]->getName() <<endl;
    }
    if(directions["west"]!=NULL)
    {
        cout << "west -> " << directions["west"]->getName() << endl;
    }
}
ostream &operator <<(ostream &Output,Room *roomObj)
{
		Output<<"\n\t\tYour are in The "<<roomObj->getName()<<". "<<roomObj->getDescription()<<endl;
		return Output;
}
void Room::Enter(Agent *a)
{
	occupants.push_back(a);
}
void Room::Leave(Agent *a)
{
	for(int i=0; i<occupants.size(); i++)
    {
        if(occupants[i]==a)
        {
            occupants.erase(occupants.begin()+i);
            break;
        }

    }
}
void Room::PrintOccupants()
{
	if(occupants.size() == 0)
    {
        cout<<"\n\t\tYou see no other creatures here\n\t\t"<<endl;
        return;
    }
    cout<<"\n\t\tYou see in front of you : \n\t\t"<<endl<<endl;;
    for(int i=0; i<occupants.size(); ++i)
    {
        if(occupants[i]!=NULL)
        {
            if(occupants[i]->TypeCheck()=="Monster")
                cout<<"\n\t\t-A Monster called "<<occupants[i]->getName()<<" ("<<occupants[i]->getDescription()<<")"<<endl<<endl;
            else
                cout<<"\n\t\t-Your Friend "<<occupants[i]->getName()<<endl<<endl;
        }
    }
}

void Room::Put(Object *obj)

{

    object.insert(obj);
}



void Room::Picked(Object *obj)
{
    object.erase(obj);
}

void Room::PrintObjects(string type)
{
    set<Object *>::iterator it=object.begin();
    for(; it != object.end() ; ++it)
    {
        if((*it)!=NULL&&(*it)->getType()=="Prop"&&type=="Prop")
        {
            cout<<(*it)->getName()<<" ";
        }
        else if((*it)!=NULL&&(*it)->getType()=="Fixed"&&type=="Fixed")
        {
            cout<<(*it)->getName()<<" ";
        }
    }

    cout<<endl;
}

Object *Room::getobject(string Name)
{
    set<Object *>::iterator it=object.begin();
    for(; it != object.end() ; ++it)
    {
        if((*it)!=NULL)
        {
            if((*it)->getName()==Name)
            {
                return (*it);
            }
        }
    }
    return NULL;

}

Room::~Room(){
}


