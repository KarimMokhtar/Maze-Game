#include "Object.h"
#include "Key.h"
#include <bits/stdc++.h>

using namespace std;

Key::Key()
{
    Name="None";
    Type="None";
}
Key::Key(string pName,string pType)
{
    Name=pName;
    Type=pType;
}
bool Key::act()
{
    return false;
}
bool Key::act(Object *O)
{
    return false;
}
