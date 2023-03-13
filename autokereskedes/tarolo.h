#ifndef TAROLO_H
#define TAROLO_H

#include <list>
#include <iostream>

#include "auto.h"

using namespace std;

class Tarolo
{
    list<Auto> autok;
    Tarolo()=default;
    Tarolo(const Tarolo& other)=default;
public:
    static Tarolo& getObjektum();
    void hozzaAd(const Auto& a);
    //void kiirTeszt();
};

#endif // TAROLO_H
