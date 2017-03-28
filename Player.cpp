#include "Player.h"
#include "Room.h"
#include "Agent.h"
#include <bits/stdc++.h>
#include "Key.h"
#include "Object.h"
#include "FixedObject.h"
#include<windows.h>
using namespace std;

Player::Player()
{
    Name="None";
    Current_room=NULL;
    Type="None";
    Obj[0]=NULL;
    Obj[1]=NULL;
    Obj[2]=NULL;
    Obj[3]=NULL;
    Obj[4]=NULL;
    weapon = NULL ;
}

Player::Player(string name, Room *Starting_room)
{
    Name=name;
    Type="Player";
    Current_room=Starting_room;
    Current_room->Enter(this);
    Obj[0]=NULL;
    Obj[1]=NULL;
    Obj[2]=NULL;
    Obj[3]=NULL;
    Obj[4]=NULL;

    weapon = NULL ;
}

void Player::Pick(Object *o) // allow  the player to pick an object from the room
{
    for(int i=0; i<5; i++)
    {
        if(Obj[i]==NULL)
        {
            Obj[i]=o;
            break;
        }

    }
}

Object *Player::Drop(string name) // fun that allow the player to drop one of the objects that he is carrying
{
    Object *temp=NULL;
    for(int i=0; i<5; i++)
    {
        if(Obj[i]!=NULL)
        {
            if(Obj[i]->getName()==name)
            {
                temp=Obj[i];
                delete Obj[i];
                Obj[i]=NULL;
                break;
            }
        }
    }
    if(temp==NULL)
    {
        cout<<"\n\t\tThere is nothing to drop"<<endl;
        return NULL;
    }
    else
    {
        cout<<"\n\t\tyou have dropped object"<<endl;
        return temp;
    }
}

void Player::printobjecct() // fun that print the objects which are holden
{
    for(int i=0; i<5; i++)
    {
        if(Obj[i]!=NULL)
        {
            cout<<Obj[i]->getName()<<" ";
        }
    }
    cout<<endl;
}

bool Player::Choose() // allow player to write a command whether pick drop or open
{
    string choice;

    Object *temp;
    cout << "\n\t\tthis room contains that you can pick:\n\n\t\t";
    Current_room->PrintObjects("Prop");
    cout << "\n\t\tthis room contains that you can open:\n\n\t\t";
    Current_room->PrintObjects("Fixed");
    cout << "\n\t\tThe objects and the weapons that you have is/are:\n\n\t\t";
    this->printobjecct();
    while(true)
    {
        for(int i=0;i<5;i++){
        if(Obj[i]!=NULL&&Obj[i]->getName()=="healing")
        {
            if(this->health+20>100)this->health=100;
            else this->health+=20 ;
            Current_room->object.insert(Obj[i]);
            Obj[i]=NULL;
        }
        }
        cout<<"\n\t\tDo you want Choose command (\"yes\") if no write (\"no\") \n\t\t"<< endl ;
        cout << "\n\t\t" ;
        cin>>choice;

        if(choice=="Yes"||choice=="yes"||choice=="YES")
        {

            cout<<"\n\t\tChoose One Command of the Following"<<endl;
            cout<<"\n\t\tpick\t\t"<<"drop\t\t"<<"open"<<endl;
            cout << "\n\t\t" ;
            cin>>choice;
            if(choice=="Pick"||choice=="pick"||choice=="PICK")
            {
                cout<<"\n\t\tChoose one of the following Objects\n\t\t ";
                Current_room->PrintObjects("Prop");
                cout << "\t\t";
                cin>>choice;
                int c=0;
                for(int i=0;i<5;i++)
                {
                    if(Obj[i]!=NULL)
                    {
                        c++;
                    }
                }
                if(c==5)
                {
                        cout<<"\n\t\tyou can't pick more objects"<<endl;

                }
                else{
                if(Current_room->getobject(choice)!=NULL)
                {
                    c=0;
                    cout<<"\n\t\tThis Object is "<<Current_room->getobject(choice)->getName()<<endl;
                    temp=Current_room->getobject(choice);
                    this->Pick(temp);
                    Current_room->Picked(temp);
                    cout<<"\n\t\tYou picked object"<<endl;
                }
                else
                {
                    cout<<"\n\t\t404 Not found :D"<<endl;
                    Choose() ;
                    return false ;
                }
                }
            }
            else if(choice=="Drop"||choice=="drop"||choice=="DROP")
            {
                cout<<"\n\t\tChoose one of the objects to drop \n\t\t";
                this->printobjecct();
                cout << "\t\t";
                cin>>choice;
                Current_room->Put(this->Drop(choice));
                continue;
            }
            else if(choice=="Open"||choice=="open"||choice=="OPEN")
            {
                cout<<"\n\t\tChoose static object of the following object to open\n\t\t";
                cin>>choice;
                if(Current_room->getobject(choice)!=NULL)
                {
                    if(Current_room->getobject(choice)->act(Obj)==1)
                    {
                        cout << "\t\tyou have won the game\n\t\t" << endl ;
                        Sleep(5000);
                        exit(10) ;


                    }
                }
                else
                {
                    cout<<"\n\t\t404 Not found :D\n\t\t"<<endl;
                }
            }
            else
            {
                cout<<"\n\t\tWrong Command\n\t\t"<<endl;
            }
        }
        else break;
    }
}

bool Player::act()
{
    string Direction;
    cout<<this->Name<<", it is your turn. your health is :"<<this->health<<endl;
    cout<<Current_room<<endl;
    Current_room->Leave(this);
    Current_room->PrintOccupants();
    Current_room->Enter(this);
    for (int i=0 ; i< Current_room->occupants.size() ; i++)
    {
        bool die = 0 ,check=0;
        if(Current_room->occupants[i]!=NULL&&Current_room->occupants[i]->TypeCheck()=="Monster")
        {
            check=1;
            cout <<"\n\t\tyou are now fighting with a monster :" << Current_room->occupants[i]->getName() ;
            for (int i = 0 ;i < 8 ; ++i){
                cout << '.';
                Sleep(500);
            }
            for(int j = 0 ; j < 5 ; ++j)
            {

                if(Obj[j]!=NULL&&Current_room->occupants[i]->getWeapon()!=NULL&&(Obj[j]->getName() == "sword"|| Obj[j]->getName()=="blade" || Obj[j]->getName()=="degger"||Obj[j]->getName()=="bow"))
                {
                    int n=rand()%50;
                    cout << "\n\t\tyour health reduced by : " << n <<"\n\t\tyou killed :"<<Current_room->occupants[i]->getName()<<"\n\n\t\t";
                    Current_room->occupants[i]->setHealth(0);
                    Current_room->Leave(Current_room->occupants[i]);
                    this ->setHealth(max(this ->getHealth()-n,1));
                    die=1;
                    break;
                }
            }
        }
        if(!die&&check || this ->getHealth() <= 0){
            for(int i = 0 ; i < 5 ; ++i){
                if(Obj[i] != NULL){
                    Current_room->object.insert(Obj[i]);
                    Obj[i]=NULL;
                }
            }
            Current_room->Leave(this);
            return cout << "\n\t\tyou health is ZERO, you died \n", !die&&check;
        }
    }
    this->Choose();
    cout<<"\n\t\tThere is an exit to ....."<<endl<<endl;
    if(Current_room->getLinked("north")!=NULL)
    {
        cout<<"\n\t\tnorth - > "<<Current_room->getLinked("north")->getName()<<endl;
    }
    if(Current_room->getLinked("south")!=NULL)
    {
        cout<<"\n\t\tsouth - > "<<Current_room->getLinked("south")->getName()<<endl;
    }
    if(Current_room->getLinked("east")!=NULL)
    {
        cout<<"\n\t\teast - > "<<Current_room->getLinked("east")->getName()<<endl;
    }
    if(Current_room->getLinked("west")!=NULL)
    {
        cout<<"\n\t\twest - > "<<Current_room->getLinked("west")->getName()<<endl;
    }

    cout<<endl;
    cout<<"\n\t\tWhich exit? (or 'Quit') : \n\t\t";
    cin>>Direction;
    cout<<endl;
    if(Direction=="Quit"||Direction=="quit"||Direction=="QUIT")
    {
        Current_room->Leave(this);
        return 1;
    }
    else if(Current_room->getLinked(Direction)==NULL)
    {
        cout << "\n\t\tyou entered empty(wrong) room " << endl ;
        Sleep(1000);
        system("cls");
        this->act();
    }
    else
    {
        Current_room->Leave(this);
        Current_room=Current_room->getLinked(Direction);
        cout<<"\n\t\tYou are moving.......";
        for(int i = 0 ; i < 8 ; ++i){
                cout <<'.';
                Sleep(500);
            }
        Current_room->Enter(this);
    }

    return 0;
}

props * Player :: getWeapon()
{
    return NULL ;
}
Player::~Player(){
    for(int i = 0 ; i < 5 ; ++i)if(Obj[i]!=NULL)delete Obj[i],Obj[i]=NULL;
    //cout << "player"<<endl;
}
