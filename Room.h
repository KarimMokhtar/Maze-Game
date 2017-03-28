#ifndef ROOM_H_
#define ROOM_H_

#include <bits/stdc++.h>

using namespace std;
class Agent;
class Object;
class Key;
class Monster ;

class Room
{
private:
	string Name,Description;
public:
    set<Object*>object;
    map<string,Room *>directions;
    vector<Agent*>occupants;
	Room();
	~Room();
	Room(string pName,string pDescription);
	string getName();
	string getDescription();
	void Link(Room *roomobj , string Direction);
	Room *getLinked(string Direction);
	void printLinked();
	friend ostream &operator <<(ostream &Output,Room *R);
	void Enter(Agent *a);
	void Leave(Agent *a);
	void PrintOccupants();

	void Put(Object *obj);
	void Picked(Object *obj);
	Monster ** getMonsters();

    void linkObj(Object *obj)  ;
    int n;
	void PrintObjects(string type);
	Object *getobject(string objName);
	static int occ_size;
};


#endif
