#include "treasure.h"
#include <bits/stdc++.h>
#include "Object.h"
#include "Key.h"
using namespace std;
treasure::treasure()
{
    Type = "treasure" ;
    Name = "none" ;
    description = "none" ;
}

treasure::treasure(string pName,string pType,string pDescription)
{
    Name = pName ;
    Type = pType ;
    description = pDescription ;
}

bool treasure :: act()
{
    return 0 ;
}
bool treasure :: act (Object **a)
{
    return 0 ;
}
treasure ::~treasure () {

}
