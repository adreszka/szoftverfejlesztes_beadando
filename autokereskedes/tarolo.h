#ifndef TAROLO_H
#define TAROLO_H

#include <list>
#include <iostream>

#include "auto.h"
#include "regisztraltfelhasznalo.h"

using namespace std;

class Tarolo
{
    list<Auto> autok;
    RegisztraltFelhasznalo felhasznalo;
    Tarolo()=default;
    Tarolo(const Tarolo& other)=default;
public:
    static Tarolo& getObjektum();
    void hozzaAd(const Auto& a);
    void kiirTeszt();
    list<Auto> getAutok() const;
    RegisztraltFelhasznalo getFelhasznalo() const;
    void setFelhasznalo(const RegisztraltFelhasznalo &newFelhasznalo);
};

#endif // TAROLO_H
