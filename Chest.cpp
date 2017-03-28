#include "Chest.h"
#include "Object.h"
#include <bits/stdc++.h>
#include "Key.h"
using namespace std;

Chest::Chest()
{
   Name="None";
   Type="None";
   K=NULL;
   Open=0;
}
Chest::Chest(string s,string t)
{
    Name=s;
    Type=t;
    K=NULL;
    Open=0;
}

void Chest::Link(Key *k)
{
    K=k;
}
bool Chest::act()
{
    return false;
}
bool Chest::Check()
{
    if(Open==1)return 1;
    else return 0;
}
bool Chest::act(Object *O)
{
    if(this->Check()==true){return 1;}
    else if(O!=NULL)
    {
        if(O==K){Open=1;return 1;}
        else return 0;
    }
    return 0;
}
