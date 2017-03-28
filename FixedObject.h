#ifndef FIXEDOBJECT_H
#define FIXEDOBJECT_H

#include "treasure.h"
#include "Object.h"
#include "Key.h"
#include <bits/stdc++.h>
using namespace std;

class FixedObject : public Object
{
    public:
        FixedObject();
        ~FixedObject();
        FixedObject(string pName,string pType,string pkey);
        void Link(Object *obj);
        bool Check();
        bool act();
        bool act(Object **obj);
        void setTreasue (Object *Obj) ;
        Object *getTreasure () ;
        string key;
    private:
        Object *treasureReached ;
        bool Open;
};

#endif // FIXEDOBJECT_H
