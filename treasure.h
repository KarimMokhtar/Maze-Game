#ifndef TREASURE_H
#define TREASURE_H
#include <bits/stdc++.h>
#include "Key.h"
#include "Object.h"

using namespace std;

class treasure : public Object
{
    public:
        treasure () ;
        ~treasure () ;
        treasure(string pName,string pType,string pDescription);

        bool act();
        bool act(Object **obj);
    protected:
    private:
        string description ;
};

#endif // TREASURE_H
