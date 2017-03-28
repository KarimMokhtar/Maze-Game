#include "props.h"
#include "Object.h"

using namespace std;


props::props()
{
    Name  = "" ;
    Type = "Prop" ;
}

props :: props (string pName , string pType)
{
    Name = pName ;
    Type = pType ;
}

bool props :: act ()
{
    return false ;
}

bool props :: act(Object **obj)
{
    return false ;
}
props::~props(){
}
