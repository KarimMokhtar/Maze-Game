#ifndef PROPS_H
#define PROPS_H
#include "Object.h"

using namespace std;


class props : public Object
{
    public:
        props();
        ~props();
        props (string pName , string pType) ;
        bool act () ;
        bool act (Object **obj) ;

    protected:
    private:
};

#endif // PROPS_H
