#ifndef TAROLO_H
#define TAROLO_H

#include "auto.h"
#include <list>

using namespace std;

class Tarolo
{
    list<Auto> autok;
    Tarolo()=default;
    Tarolo(const Tarolo& other)=default;
public:
    static Tarolo& getObjektum();
};

#endif // TAROLO_H
