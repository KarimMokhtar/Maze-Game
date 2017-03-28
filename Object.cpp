#include "Object.h"
#include <bits/stdc++.h>

using namespace std;

Object::Object()
{
  Name="None";
  Type="None";
}
Object::Object(string name,string type)
{
    Name=name;
    Type=type;
}
void Object::setName(string pName)
{
    Name=pName;
}
string Object::getName()
{
    return Name;
}
void Object::setType(string pName)
{
    Type=pName;
}
string Object::getType()
{
    return Type;
}
bool Object::act()
{
    return 0;
}
bool Object::act(Object **O)
{
    return 0;
}
Object::~Object(){

}
