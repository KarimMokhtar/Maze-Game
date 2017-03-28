#ifndef OBJECT_H
#define OBJECT_H

#include <bits/stdc++.h>
#include <Object.h>
using namespace std;

class Object
{
    public:
        Object();
        virtual~Object()=0;
        virtual bool act() = 0;
        virtual bool act(Object **O)=0;
        Object(string name,string type);
        void setName(string pName);
        string getName();
        string getType();
        void setType(string pName);

    protected:
        string Name,Type;
};

#endif
