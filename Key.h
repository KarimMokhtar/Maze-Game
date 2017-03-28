#ifndef KEY_H
#define KEY_H
#include "Object.h"
#include <bits/stdc++.h>

using namespace std;

class Key : public Object
{
    public:
        Key();
        Key(string pName,string pType);
        bool act();
        bool act(Object *O);
};

#endif
