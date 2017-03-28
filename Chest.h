#ifndef CHEST_H
#define CHEST_H

#include "Object.h"
#include "Key.h"
#include <bits/stdc++.h>
using namespace std;

class Chest : public Object
{
    public:
        Chest();
        Chest(string s,string t);
        void Link(Key *k);
        void getinvt(Object *o);
        bool Check();
        bool act();
        bool act(Object *O);
    private:
        Key *K;bool Open;
};

#endif
