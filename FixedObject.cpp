#include "FixedObject.h"
#include "Object.h"
#include <bits/stdc++.h>
#include "Key.h"
using namespace std;

FixedObject::FixedObject()
{
   Name="None";
   Type="None";
   key = "None";

   Open=0;
   treasureReached =NULL ;
}

FixedObject::FixedObject(string pName,string pType,string pkey)
{
    Name=pName;
    Type=pType;
    key=pkey;

    Open=0;
    treasureReached = NULL ;
}

bool FixedObject::act()
{
    return false;
}

bool FixedObject::Check()
{
    if(Open==1)return 1;
    else return 0;
}

void FixedObject :: setTreasue (Object *Obj)
{
    treasureReached = Obj ;
}

Object* FixedObject :: getTreasure ()
{
    return treasureReached ;
}

bool FixedObject::act(Object **O)
{
    if(this->Check()==true)
    {
        cout<<"it aleardy opened"<<endl;
        return 0;
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            if(O[i]!=NULL){
                if(O[i]->getName()==key)
               {
                   Open =1 ;
                   cout<<"You opened it"<<endl;
                   if(treasureReached!=NULL)
                   {
                       cout << "\n\t\tyou get the treasure" << endl ;
                        return 1 ;
                   }
                   else
                    cout<<"\n\t\tthere is nothing"<<endl;
                   return 0;
               }
            }
        }
    }
    cout<<"\n\t\tyou can't open it!!"<<endl;
    return 0;
}
FixedObject::~FixedObject(){
    delete treasureReached;
}
