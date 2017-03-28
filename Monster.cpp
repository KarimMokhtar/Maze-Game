#include "Monster.h"
#include "Room.h"
#include "Agent.h"
#include <bits/stdc++.h>
#include "Object.h"
#include "props.h"
using namespace std;

Monster::Monster()
{
   Name="None";
   Type="Monster";
   Current_room=NULL;
   weapon= NULL ;
   weapon ->setName("sword");

}
Monster::Monster(string name, Room *Starting_room,Object *obj)
{
	Name=name;
	Type="Monster";
	Current_room=Starting_room;
	Current_room->Enter(this);
	obj ->setName("sword");
	weapon= obj ;
}
void Monster :: setWeapon (Object *obj)
{
    weapon = obj ;
}
Object* Monster ::getWeapon ()
{
    return weapon ;
}
bool Monster::act()
{
    string Direction;
    int east=1e9,west=1e9,south=1e9,north=1e9;
    cout<<endl;
    if (this->health == 0)return false;
    for(int i = 0 ; i < Current_room->occupants.size(); ++i){
        if(Current_room->occupants[i]->TypeCheck()!="Monster")return 0;
    }
    if(Current_room->directions["east"]!=NULL)east=BFS(Current_room);
    if(Current_room->directions["west"]!=NULL)west=BFS(Current_room);
    if(Current_room->directions["south"]!=NULL)south=BFS(Current_room);
    if(Current_room->directions["north"]!=NULL)north=BFS(Current_room);
    if(east <= west && east <= south && east <= north){
        Current_room->Leave(this);
        Current_room = Current_room->directions["east"];
        Current_room->Enter(this);
    }
    if(east >= west && west <= south && west <= north){
        Current_room->Leave(this);
        Current_room = Current_room->directions["west"];
        Current_room->Enter(this);
    }
    if(south <= west && east >= south && south <= north){
        Current_room->Leave(this);
        Current_room = Current_room->directions["south"];
        Current_room->Enter(this);
    }
    if(north <= west && north <= south && east >= north){
        Current_room->Leave(this);
        Current_room = Current_room->directions["north"];
        Current_room->Enter(this);
    }
    return 0;
}

int Monster ::BFS(Room *the_current_room){
    queue<Room *>q;// just to make sure that all the current children of the graph in the same level
    q.push(the_current_room); // our first parent :"D
    Room *visited_array[1000] = {};//just to avoid infinite cycle and the most important part :"D
    memset(visited_array,NULL,sizeof visited_array); // to initialize all the visited_array by NULL
    int result = 0 ;// the number of rooms between the monster and the nearest player
    while(q.size()){
        int currentLevel=q.size(); // b bsata the number of rooms till now
        while(currentLevel--){
            Room *r=q.front(); // search about it on google :"D
            q.pop(); // the same as this |^|
            for(int i = 0 ; i < r->occupants.size(); ++i){
                if(r->occupants[i]->TypeCheck()!="Monster")return result;
                /*this two loop check if the children of the current level
                 * no no sorry it's check if the room have a player or not ^-^ */
            }
            if(visited_array[r->n]!=NULL)continue;// to avoid the infinite cycle as we mentioned before
            visited_array[r->n]=the_current_room; // if we come to that room for the first time so visit it or mark it :"D
            /*the next 4 lines just for put the next level*/
            if(r->directions["east"]!=NULL)q.push(r->directions["east"]);
            if(r->directions["west"]!=NULL)q.push(r->directions["west"]);
            if(r->directions["south"]!=NULL)q.push(r->directions["south"]);
            if(r->directions["north"]!=NULL)q.push(r->directions["north"]);
        }
        result++; // if we finished that level so we increase our distance by 1;
    }
    return 1e9; // if we don't find any players retrun a big value
}
Monster::~Monster(){
}
